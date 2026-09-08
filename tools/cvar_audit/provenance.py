#!/usr/bin/env python3
"""Resolve cvar/command provenance across the TaystJK upstream graph.

The resolver is deliberately conservative.  Exact Git history and explicit
credits are evidence; simple similarity is not.  Results and expensive Git
queries are cached under .cvar-audit/cache so interrupted runs can resume.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
from collections import defaultdict
from dataclasses import asdict
from functools import lru_cache
from pathlib import Path
from typing import Any, Iterable

from extract import extract_commands, extract_cvars, source_files


BASEJKA_REF = "14cea1563762076974bee277afadbd5bf234c494"
CURRENT_REF = "origin/master"
EXTRACTOR_VERSION = 6
RESOLVER_VERSION = 17
UPSTREAM_REFS = {
    "openjk": "openjk/master",
    "eternaljk": "eternaljk/master",
    "japro": "japro/main",
    "jk2mv": "jk2mv/master",
    "newjk": "newjk/master",
    "rend2": "somaz/rend2-unified-wip",
    "vulkan": "Sunny/master",
}
ORIGIN_PRIORITY = (
    # Used only for exact-time lineage ties. OpenJK is the root engine line;
    # EternalJK and rend2 predate the TaystJK lines that consume them. TaystJK
    # precedes its current synchronized jaPRO, NewJK, and Vulkan descendants so
    # those heads cannot claim inherited TaystJK commits merely by containing
    # the same SHA. Explicit commit/PR credit can still override this order.
    "openjk", "jk2mv", "eternaljk", "rend2", "taystjk",
    "japro", "newjk", "vulkan",
)
REMOTE_MARKERS = {
    "openjk": ("refs/remotes/openjk/",),
    "eternaljk": ("refs/remotes/eternaljk/",),
    "japro": ("refs/remotes/japro/",),
    "jk2mv": ("refs/remotes/jk2mv/", "refs/remotes/fau/"),
    "newjk": ("refs/remotes/newjk/",),
    "rend2": ("refs/remotes/somaz/",),
    "vulkan": ("refs/remotes/Sunny/",),
    "taystjk": ("refs/remotes/origin/",),
}
SOURCE_PATTERNS = {
    "taystjk": re.compile(r"\btaystjk\b|\btayst\s+jk\b", re.I),
    "japro": re.compile(r"\bja\s*pro\b|\bjapro\b", re.I),
    "jk2mv": re.compile(r"\bjk2mv\b|\bfau\b", re.I),
    "newjk": re.compile(r"\bnewjk\b|\bnewmod\b", re.I),
    "rend2": re.compile(r"\brend2\b|\bsomaz\b", re.I),
    "vulkan": re.compile(r"\bvulkan\b|\bjksunny\b|\bsunny\b", re.I),
    "eternaljk": re.compile(r"\beternaljk\b|\beternal\s+jk\b", re.I),
    "openjk": re.compile(r"\bopenjk\b", re.I),
}


def git(*args: str) -> str:
    result = subprocess.run(
        ["git", *args], check=False, text=True, errors="replace",
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    if result.returncode:
        raise RuntimeError(f"git {' '.join(args)} failed: {result.stderr.strip()}")
    return result.stdout


def write_json(path: Path, value: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n")


def cache_key(prefix: str, value: str) -> str:
    digest = hashlib.sha256(value.encode()).hexdigest()[:20]
    return f"{prefix}-{digest}.json"


def extract_ref(ref: str, kind: str, cache: Path, refresh: bool) -> list[dict[str, Any]]:
    safe = re.sub(r"[^A-Za-z0-9_.-]+", "_", ref)
    path = cache / "extract" / f"{safe}.v{EXTRACTOR_VERSION}.{kind}.json"
    if path.exists() and not refresh:
        return json.loads(path.read_text())
    files = list(source_files(ref, ".", None))
    records = extract_cvars(files) if kind == "cvars" else extract_commands(files)
    rendered = [asdict(record) for record in records]
    write_json(path, rendered)
    return rendered


def grouped(records: Iterable[dict[str, Any]]) -> dict[str, list[dict[str, Any]]]:
    result: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        result[record["name"].casefold()].append(record)
    return dict(result)


def branch_introductions(
    ref: str,
    records: dict[str, list[dict[str, Any]]],
    cache: Path,
    refresh: bool,
    label: str,
) -> dict[str, dict[str, Any]]:
    """Find when each current registration first entered a project's mainline.

    `git branch --contains` cannot establish direction: a later consumer also
    contains the original commit.  A first-parent diff records the integration
    point instead, so ports such as TaystJK -> NewJK receive a later date than
    their source. Exact shared commits remain explicit, reviewable ties because
    Git does not record which remote received an object first.
    """
    if not records:
        return {}
    sha = git("rev-parse", ref).strip()
    coordinates = "\0".join(
        f"{name}:{','.join(sorted({item['path'] for item in registrations}))}"
        for name, registrations in sorted(records.items())
    )
    key = cache_key(f"branch-introductions-v2-{label}-{sha[:12]}", coordinates)
    path = cache / "git" / key
    if path.exists() and not refresh:
        return json.loads(path.read_text())

    names_by_path: dict[str, set[str]] = defaultdict(set)
    display_names: dict[str, str] = {}
    for name, registrations in records.items():
        display_names[name] = registrations[0]["name"]
        usable = [item for item in registrations if not str(item.get("kind", "")).startswith("implicit")]
        for registration in usable or registrations:
            names_by_path[registration["path"]].add(name)

    patterns = {
        source_path: re.compile(
            r"(?<![A-Za-z0-9_])(?:"
            + "|".join(sorted((re.escape(display_names[name]) for name in names), key=len, reverse=True))
            + r")(?![A-Za-z0-9_])",
            re.I,
        )
        for source_path, names in names_by_path.items()
    }
    marker = "@@@TAYSTJK-INTRO@@@%H%x09%ct%x09%s"
    command = [
        "git", "log", ref, "--first-parent", "--reverse", "--root",
        "--diff-merges=first-parent",
        "-p", "--unified=0", "--no-color", f"--format={marker}", "--",
        *sorted(names_by_path),
    ]
    process = subprocess.Popen(
        command, text=True, errors="replace",
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    assert process.stdout is not None
    current: dict[str, Any] | None = None
    current_path: str | None = None
    found: dict[str, dict[str, Any]] = {}
    for raw_line in process.stdout:
        line = raw_line.rstrip("\n")
        if line.startswith("@@@TAYSTJK-INTRO@@@"):
            fields = line.removeprefix("@@@TAYSTJK-INTRO@@@").split("\t", 2)
            current = None
            current_path = None
            if len(fields) == 3:
                current = {
                    "sha": fields[0], "timestamp": int(fields[1]),
                    "subject": fields[2], "ref": ref,
                }
            continue
        if line.startswith("+++ b/"):
            current_path = line[6:]
            continue
        if current is None or current_path not in patterns or not line.startswith("+") or line.startswith("+++"):
            continue
        for match in patterns[current_path].finditer(line[1:]):
            key_name = match.group(0).casefold()
            if key_name in records and key_name not in found:
                found[key_name] = {**current, "path": current_path}

    stderr = process.stderr.read() if process.stderr else ""
    return_code = process.wait()
    if return_code:
        raise RuntimeError(f"dated introduction scan for {ref} failed: {stderr.strip()}")
    write_json(path, found)
    return found


GENERIC_BEHAVIOR_TOKENS = {
    "cmd", "command", "cvar", "cv", "data", "entry", "item", "name",
    "model", "value", "var", "variable",
}


def behavior_tokens(
    records: dict[str, list[dict[str, Any]]],
) -> tuple[dict[str, set[str]], dict[str, set[str]]]:
    """Return cvar-variable and command-handler tokens mapped to entries."""
    variables: dict[str, set[str]] = defaultdict(set)
    handlers: dict[str, set[str]] = defaultdict(set)
    for key, registrations in records.items():
        for registration in registrations:
            variable = registration.get("variable")
            if (
                isinstance(variable, str)
                and re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", variable)
                and len(variable) >= 4
                and variable.casefold() not in GENERIC_BEHAVIOR_TOKENS
            ):
                variables[variable].add(key)
            handler = registration.get("handler")
            if (
                isinstance(handler, str)
                and re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", handler)
                and len(handler) >= 4
                and handler not in {"NULL"}
            ):
                handlers[handler].add(key)
    return dict(variables), dict(handlers)


def branch_change_events(
    ref: str,
    records: dict[str, list[dict[str, Any]]],
    cache: Path,
    refresh: bool,
    label: str,
) -> dict[str, list[dict[str, Any]]]:
    """Trace registration and exact behavior-reference changes on a mainline.

    Registration names are matched in their registration files. Cvar variables
    are matched on changed lines throughout the current source tree. Command
    handlers are additionally matched in diff hunk function context, which
    captures edits inside a handler even when its name is not on the changed
    line. The result is deliberately evidence-shaped: it does not infer a
    behavioral change from a file-level commit that never touches the bound
    variable or handler.
    """
    if not records:
        return {}
    sha = git("rev-parse", ref).strip()
    variables, handlers = behavior_tokens(records)
    coordinates = "\0".join(
        f"{key}:{records[key][0]['name']}:"
        f"{','.join(sorted({item['path'] for item in records[key]}))}:"
        f"{','.join(sorted(token for token, keys in variables.items() if key in keys))}:"
        f"{','.join(sorted(token for token, keys in handlers.items() if key in keys))}"
        for key in sorted(records)
    )
    key = cache_key(f"branch-changes-v2-{label}-{sha[:12]}", coordinates)
    cache_path = cache / "git" / key
    if cache_path.exists() and not refresh:
        return json.loads(cache_path.read_text())

    names_by_path: dict[str, set[str]] = defaultdict(set)
    display_names = {key: registrations[0]["name"] for key, registrations in records.items()}
    for entry_key, registrations in records.items():
        for registration in registrations:
            names_by_path[registration["path"]].add(entry_key)

    variable_keys_by_path: dict[str, dict[str, set[str]]] = defaultdict(lambda: defaultdict(set))
    handler_keys_by_path: dict[str, dict[str, set[str]]] = defaultdict(lambda: defaultdict(set))
    wanted_tokens = set(variables) | set(handlers)
    for source_path, source_text in source_files(ref, ".", None):
        present_tokens = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", source_text)) & wanted_tokens
        for token in present_tokens:
            if token in variables:
                variable_keys_by_path[source_path][token].update(variables[token])
            if token in handlers:
                handler_keys_by_path[source_path][token].update(handlers[token])

    relevant_paths = sorted(
        set(names_by_path) | set(variable_keys_by_path) | set(handler_keys_by_path)
    )
    name_patterns = {
        source_path: re.compile(
            r"(?<![A-Za-z0-9_])(?:"
            + "|".join(sorted(
                (re.escape(display_names[entry_key]) for entry_key in entry_keys),
                key=len, reverse=True,
            ))
            + r")(?![A-Za-z0-9_])",
            re.I,
        )
        for source_path, entry_keys in names_by_path.items()
    }
    name_lookup = {value.casefold(): key for key, value in display_names.items()}
    registration_kinds = {
        entry_key: {str(item.get("kind", "")) for item in registrations}
        for entry_key, registrations in records.items()
    }

    def is_registration_line(entry_key: str, changed_line: str) -> bool:
        name = display_names[entry_key]
        escaped = re.escape(name)
        kinds = registration_kinds[entry_key]
        if "XCVAR_DEF" in kinds and re.search(
            rf"\bXCVAR_DEF\s*\(\s*{escaped}\s*,", changed_line, re.I,
        ):
            return True
        quoted = re.search(rf'"{escaped}"', changed_line, re.I)
        if not quoted:
            return False
        if any("forwarded client command table" == kind for kind in kinds):
            return True
        if any("table" in kind for kind in kinds) and "{" in changed_line:
            return True
        return bool(re.search(
            r"\b(?:trap_)?Cvar_(?:Get|Register)\b|\b(?:Cmd_AddCommand|trap_AddCommand)\b|\btrap->AddCommand\b",
            changed_line,
        ))

    marker = "@@@TAYSTJK-CHANGE@@@%H%x09%ct%x09%an%x09%ae%x09%s"
    command = [
        "git", "log", ref, "--first-parent", "--reverse", "--root",
        "--diff-merges=first-parent", "-p", "--unified=0", "--no-color",
        f"--format={marker}", "--", *relevant_paths,
    ]
    process = subprocess.Popen(
        command, text=True, errors="replace",
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    assert process.stdout is not None
    current: dict[str, Any] | None = None
    current_path: str | None = None
    hunk_handler_keys: set[str] = set()
    found: dict[str, dict[str, dict[str, Any]]] = defaultdict(dict)

    def add_hit(entry_key: str, category: str, sign: str, changed_line: str) -> None:
        assert current is not None and current_path is not None
        event = found[entry_key].setdefault(current["sha"], {
            **current, "categories": set(), "paths": set(),
            "added": [], "removed": [],
        })
        event["categories"].add(category)
        event["paths"].add(current_path)
        bucket = "added" if sign == "+" else "removed"
        normalized = changed_line.strip()
        if normalized and normalized not in event[bucket] and len(event[bucket]) < 8:
            event[bucket].append(normalized[:300])

    for raw_line in process.stdout:
        line = raw_line.rstrip("\n")
        if line.startswith("@@@TAYSTJK-CHANGE@@@"):
            fields = line.removeprefix("@@@TAYSTJK-CHANGE@@@").split("\t", 4)
            current = None
            current_path = None
            hunk_handler_keys = set()
            if len(fields) == 5:
                current = {
                    "sha": fields[0], "timestamp": int(fields[1]),
                    "author": fields[2], "email": fields[3], "subject": fields[4],
                    "ref": ref,
                }
            continue
        diff_match = re.match(r"diff --git a/(.+) b/(.+)$", line)
        if diff_match:
            old_path, new_path = diff_match.groups()
            current_path = new_path if new_path in relevant_paths else old_path
            hunk_handler_keys = set()
            continue
        if line.startswith("@@"):
            hunk_handler_keys = set()
            if current_path in handler_keys_by_path:
                for token, entry_keys in handler_keys_by_path[current_path].items():
                    if re.search(rf"(?<![A-Za-z0-9_]){re.escape(token)}(?![A-Za-z0-9_])", line):
                        hunk_handler_keys.update(entry_keys)
            continue
        if (
            current is None or current_path not in relevant_paths
            or not line.startswith(("+", "-")) or line.startswith(("+++", "---"))
        ):
            continue
        sign, changed_line = line[0], line[1:]
        registration_keys: set[str] = set()
        pattern = name_patterns.get(current_path)
        if pattern:
            registration_keys = {
                name_lookup[match.group(0).casefold()]
                for match in pattern.finditer(changed_line)
                if match.group(0).casefold() in name_lookup
                and is_registration_line(name_lookup[match.group(0).casefold()], changed_line)
            }
            for entry_key in registration_keys:
                add_hit(entry_key, "registration", sign, changed_line)

        identifiers = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", changed_line))
        for token in identifiers:
            for entry_key in variable_keys_by_path.get(current_path, {}).get(token, ()):
                if entry_key not in registration_keys:
                    add_hit(entry_key, "behavior-reference", sign, changed_line)
            for entry_key in handler_keys_by_path.get(current_path, {}).get(token, ()):
                if entry_key not in registration_keys:
                    add_hit(entry_key, "handler", sign, changed_line)
        for entry_key in hunk_handler_keys - registration_keys:
            add_hit(entry_key, "handler", sign, changed_line)

    stderr = process.stderr.read() if process.stderr else ""
    return_code = process.wait()
    if return_code:
        raise RuntimeError(f"change history scan for {ref} failed: {stderr.strip()}")

    rendered: dict[str, list[dict[str, Any]]] = {}
    for entry_key, by_sha in found.items():
        rendered[entry_key] = sorted(
            ({
                **event,
                "categories": sorted(event["categories"]),
                "paths": sorted(event["paths"]),
            } for event in by_sha.values()),
            key=lambda event: (event["timestamp"], event["sha"]),
        )
    write_json(cache_path, rendered)
    return rendered


def select_dated_origin(
    events: dict[str, dict[str, Any]],
) -> tuple[str, str, str, list[str]]:
    """Select an ultimate origin from per-project first-mainline events.

    Dates establish direction. Project order is used only when two projects'
    earliest appearances have the exact same timestamp, most commonly because
    they share a commit through fork ancestry.
    """
    if not events:
        return "unknown", "low", "unresolved", []
    earliest_timestamp = min(event["timestamp"] for event in events.values())
    earliest_sources = {
        source for source, event in events.items()
        if event["timestamp"] == earliest_timestamp
    }
    source = next(
        (candidate for candidate in ORIGIN_PRIORITY if candidate in earliest_sources),
        sorted(earliest_sources)[0],
    )
    ordered_ties = [
        candidate for candidate in ORIGIN_PRIORITY if candidate in earliest_sources
    ]
    ordered_ties.extend(sorted(earliest_sources - set(ordered_ties)))
    if len(earliest_sources) == 1:
        return source, "high", "earliest-dated-project-introduction", ordered_ties
    shared_shas = {events[candidate]["sha"] for candidate in earliest_sources}
    if len(shared_shas) == 1:
        # Git objects have no repository-of-origin field. A shared SHA proves
        # common lineage but cannot by itself prove which remote received it
        # first, so keep the result reviewable unless explicit credit resolves it.
        return source, "medium", "shared-earliest-commit-lineage-order", ordered_ties
    return source, "medium", "tied-earliest-project-introductions", ordered_ties


def load_prs(patterns: list[str]) -> list[dict[str, Any]]:
    prs: list[dict[str, Any]] = []
    for pattern in patterns:
        # Patterns are expanded explicitly to keep this script shell-independent.
        path = Path(pattern)
        candidates = sorted(path.parent.glob(path.name))
        for candidate in candidates:
            value = json.loads(candidate.read_text())
            prs.extend(value if isinstance(value, list) else [value])
    return prs


def pickaxe(name: str, cache: Path, refresh: bool) -> list[dict[str, Any]]:
    key = cache_key("pickaxe", name)
    path = cache / "git" / key
    if path.exists() and not refresh:
        return json.loads(path.read_text())

    format_string = "%H%x09%ct%x09%an%x09%ae%x09%s"
    searches = [f'"{name}"', name]
    lines: list[str] = []
    used = searches[-1]
    for search in searches:
        used = search
        output = git("log", "--all", "--full-history", f"--format={format_string}", f"-S{search}", "--")
        lines = [line for line in output.splitlines() if line.count("\t") >= 4]
        if lines:
            break

    commits: list[dict[str, Any]] = []
    for line in lines:
        sha, timestamp, author, email, subject = line.split("\t", 4)
        refs = git("for-each-ref", "--contains", sha, "--format=%(refname)", "refs/remotes/").splitlines()
        commits.append({
            "sha": sha,
            "timestamp": int(timestamp),
            "author": author,
            "email": email,
            "subject": subject,
            "refs": sorted(refs),
        })
    commits.sort(key=lambda item: (item["timestamp"], item["sha"]))
    write_json(path, {"search": used, "commits": commits})
    return commits


def cached_pickaxe(name: str, cache: Path, refresh: bool) -> list[dict[str, Any]]:
    value = pickaxe(name, cache, refresh)
    if isinstance(value, dict):
        return value["commits"]
    return value


def batch_first_additions(
    records: dict[str, list[dict[str, Any]]], cache: Path, refresh: bool,
) -> dict[str, dict[str, Any]]:
    """Find the first matching addition in each current registration file.

    Walking each relevant file once is orders of magnitude faster than a
    full-tree pickaxe per identifier.  Current-line blame is retained as a
    fallback for registrations whose history moved between files.
    """
    if not records:
        return {}
    normalized = sorted(records)
    coordinates = "\0".join(
        f"{key}:{records[key][0]['path']}:{records[key][0]['line']}" for key in normalized
    )
    key = cache_key("origin-file-history-v2", coordinates)
    path = cache / "git" / key
    if path.exists() and not refresh:
        return json.loads(path.read_text())
    found: dict[str, dict[str, Any]] = {}
    by_path: dict[str, list[tuple[str, int]]] = defaultdict(list)
    for name, registrations in records.items():
        registration = sorted(
            registrations,
            key=lambda item: (str(item["kind"]).startswith("implicit"), item["path"], item["line"]),
        )[0]
        by_path[registration["path"]].append((name, registration["line"]))
    commit_cache: dict[str, dict[str, Any]] = {}
    for source_path, targets in by_path.items():
        marker = "@@@TAYSTJK-COMMIT@@@%H%x09%ct%x09%an%x09%ae%x09%s"
        history = git(
            "log", "--reverse", "--full-history", "-p", "--unified=0",
            f"--format={marker}", CURRENT_REF, "--", source_path,
        )
        pending = {name for name, _line in targets}
        current: dict[str, Any] | None = None
        for history_line in history.splitlines():
            if history_line.startswith("@@@TAYSTJK-COMMIT@@@"):
                fields = history_line.removeprefix("@@@TAYSTJK-COMMIT@@@").split("\t", 4)
                current = None
                if len(fields) == 5:
                    current = {
                        "sha": fields[0], "timestamp": int(fields[1]),
                        "author": fields[2], "email": fields[3], "subject": fields[4],
                        "refs": ["refs/remotes/origin/master"],
                        "evidence_method": "first-addition-in-registration-file-history",
                    }
                continue
            if current is None or not history_line.startswith("+") or history_line.startswith("+++"):
                continue
            folded = history_line.casefold()
            for name in list(pending):
                if re.search(rf"(?<![A-Za-z0-9_]){re.escape(name)}(?![A-Za-z0-9_])", folded):
                    found[name] = dict(current)
                    pending.remove(name)

        if not pending:
            continue
        output = git("blame", "--line-porcelain", CURRENT_REF, "--", source_path)
        line_commits: dict[int, str] = {}
        for line in output.splitlines():
            match = re.match(r"^([0-9a-f]{40})\s+\d+\s+(\d+)(?:\s+\d+)?$", line)
            if match:
                line_commits[int(match.group(2))] = match.group(1)
        for name, line_number in targets:
            if name not in pending:
                continue
            sha = line_commits.get(line_number)
            if not sha:
                continue
            if sha not in commit_cache:
                fields = git("show", "-s", "--format=%H%x09%ct%x09%an%x09%ae%x09%s", sha).strip().split("\t", 4)
                if len(fields) != 5:
                    continue
                commit_cache[sha] = {
                    "sha": fields[0], "timestamp": int(fields[1]),
                    "author": fields[2], "email": fields[3], "subject": fields[4],
                    "refs": ["refs/remotes/origin/master"],
                    "evidence_method": "registration-line-blame",
                }
            found[name] = dict(commit_cache[sha])
    write_json(path, found)
    return found


def sources_for_refs(refs: Iterable[str]) -> list[str]:
    found: list[str] = []
    for source, markers in REMOTE_MARKERS.items():
        if any(any(ref.startswith(marker) for marker in markers) for ref in refs):
            found.append(source)
    return found


def source_context(registrations: list[dict[str, Any]], name: str) -> str:
    chunks: list[str] = []
    seen: set[str] = set()
    for registration in registrations[:4]:
        path = registration["path"]
        if path in seen:
            continue
        seen.add(path)
        try:
            lines = current_source(path).splitlines()
        except RuntimeError:
            continue
        line = registration["line"] - 1
        chunks.extend(lines[max(0, line - 8): min(len(lines), line + 9)])
    return "\n".join(chunks)


@lru_cache(maxsize=None)
def current_source(path: str) -> str:
    return git("show", f"{CURRENT_REF}:{path}")


def credited_sources(text: str) -> list[str]:
    return [source for source, pattern in SOURCE_PATTERNS.items() if pattern.search(text)]


def pr_for_commit(commit: dict[str, Any] | None, prs: list[dict[str, Any]]) -> dict[str, Any] | None:
    if not commit:
        return None
    number_match = re.search(r"\(#(\d+)\)\s*$", commit["subject"])
    if number_match:
        number = int(number_match.group(1))
        return next((pr for pr in prs if pr.get("number") == number), None)
    sha = commit["sha"]
    return next(
        (pr for pr in prs if (pr.get("merge_commit_sha") or "") == sha),
        None,
    )


@lru_cache(maxsize=None)
def commit_body(sha: str | None) -> str:
    return git("show", "-s", "--format=%B", sha).strip() if sha else ""


@lru_cache(maxsize=None)
def commit_timestamp(sha: str) -> int:
    value = git("show", "-s", "--format=%ct", sha).strip()
    return int(value)


@lru_cache(maxsize=None)
def registration_blame_event(path: str, line: int) -> dict[str, Any] | None:
    output = git(
        "blame", "--line-porcelain", f"-L{line},{line}", CURRENT_REF, "--", path,
    )
    first_line = output.splitlines()[0] if output else ""
    match = re.match(r"^\^?([0-9a-f]{40})\s", first_line)
    if not match or set(match.group(1)) == {"0"}:
        return None
    sha = match.group(1)
    fields = git(
        "show", "-s", "--format=%H%x09%ct%x09%an%x09%ae%x09%s", sha,
    ).strip().split("\t", 4)
    if len(fields) != 5:
        return None
    return {
        "sha": fields[0], "timestamp": int(fields[1]),
        "author": fields[2], "email": fields[3], "subject": fields[4],
        "ref": CURRENT_REF, "categories": ["registration"], "paths": [path],
    }


def attribute_change(
    event: dict[str, Any],
    prs: list[dict[str, Any]],
    project_histories: dict[str, set[str]],
) -> dict[str, Any]:
    """Attribute a TaystJK-lineage change using explicit credit and topology."""
    sha = event["sha"]
    pr = pr_for_commit(event, prs)
    pr_text = "\n".join(str(pr.get(field) or "") for field in ("title", "body")) if pr else ""
    evidence_text = "\n".join((event.get("subject", ""), commit_body(sha), pr_text))
    explicit = credited_sources(evidence_text)
    members = [source for source, commits in project_histories.items() if sha in commits]

    if len(explicit) == 1:
        source = explicit[0]
        confidence = "high" if source in members else "medium"
        method = "explicit-change-credit"
    elif members:
        source = next(
            (candidate for candidate in ORIGIN_PRIORITY if candidate in members),
            sorted(members)[0],
        )
        confidence = "high" if len(members) == 1 else "medium"
        method = "single-project-mainline-change" if len(members) == 1 else "shared-change-commit-lineage-order"
    else:
        source, confidence, method = "taystjk", "medium", "taystjk-first-parent-change"

    repository = source if source in members else (
        "taystjk" if "taystjk" in members else (members[0] if members else "taystjk")
    )
    categories = set(event.get("categories", []))
    descriptions: list[str] = []
    if "registration" in categories:
        descriptions.append("registration, default, flags, module, renderer scope, handler, or gating")
    if "behavior-reference" in categories:
        descriptions.append("an exact bound cvar-variable reference")
    if "handler" in categories:
        descriptions.append("the registered command handler")
    change = "Changed " + "; and ".join(descriptions) + "."
    return {
        "source": source,
        "change": change,
        "categories": sorted(categories),
        "commit": sha,
        "timestamp": event["timestamp"],
        "subject": event.get("subject", ""),
        "paths": event.get("paths", []),
        "confidence": confidence,
        "method": method,
        "repository": repository,
        "pr": pr.get("number") if pr else None,
        "pr_url": pr.get("html_url") if pr else None,
    }


def signature(records: list[dict[str, Any]]) -> list[dict[str, Any]]:
    values = {
        (
            record.get("kind"),
            record.get("default"),
            tuple(record.get("flags") or ()),
            record.get("module"),
            record.get("renderer"),
            record.get("handler"),
            tuple(record.get("gating") or ()),
            record.get("condition"),
        )
        for record in records
        if not str(record.get("kind", "")).startswith("implicit")
    }
    return [
        {
            "kind": kind, "default": default, "flags": list(flags),
            "module": module, "renderer": renderer, "handler": handler,
            "gating": list(gating), "condition": condition,
        }
        for kind, default, flags, module, renderer, handler, gating, condition
        in sorted(values, key=lambda value: tuple(str(x) for x in value))
    ]


def resolve_one(
    key: str,
    registrations: list[dict[str, Any]],
    base_names: set[str],
    upstream: dict[str, dict[str, list[dict[str, Any]]]],
    prs: list[dict[str, Any]],
    cache: Path,
    refresh: bool,
    introductions: dict[str, dict[str, dict[str, Any]]],
    change_events: dict[str, list[dict[str, Any]]],
    project_histories: dict[str, set[str]],
    first_additions: dict[str, dict[str, Any]],
    deep_pickaxe: bool,
) -> dict[str, Any]:
    name = registrations[0]["name"]
    present = [source for source, names in upstream.items() if key in names]
    notes: list[str] = []
    method = ""
    first: dict[str, Any] | None = None
    credited_bullet: str | None = None
    ported_via: list[str] = []
    events: dict[str, dict[str, Any]] = {}

    if key in base_names:
        source = "basejka"
        confidence = "high"
        method = "present-in-openjk-initial-source-import"
        first_commit = BASEJKA_REF
        first_ref = BASEJKA_REF
        notes.append("Identifier is present in OpenJK's initial Raven source-import snapshot.")
    else:
        first = introductions.get("taystjk", {}).get(key) or first_additions.get(key)
        if not first and deep_pickaxe:
            commits = cached_pickaxe(name, cache, refresh)
            first = commits[0] if commits else None

        events = {
            source_name: event_map[key]
            for source_name, event_map in introductions.items()
            if key in event_map
        }
        if events:
            source, confidence, method, earliest_sources = select_dated_origin(events)
            if len(earliest_sources) > 1:
                notes.append(
                    "The earliest dated introduction is shared by "
                    + ", ".join(earliest_sources)
                    + f"; fork-lineage order selects {source}."
                )
        else:
            # Keep a conservative head-presence fallback for registrations whose
            # file history cannot be followed through a rename or generated table.
            source = next((candidate for candidate in ORIGIN_PRIORITY if candidate in present), "unknown")
            confidence = "medium" if source != "unknown" else "low"
            method = "upstream-head-presence" if source != "unknown" else "unresolved"

        first_commit = first["sha"] if first else None
        first_ref = first.get("ref") if first else None
        if not first_ref and first and first.get("refs"):
            first_ref = first["refs"][0]

        body = commit_body(first_commit)
        pr = pr_for_commit(first, prs)
        pr_text = "\n".join(str(pr.get(field) or "") for field in ("title", "body")) if pr else ""
        context = source_context(registrations, name)
        body_bullets = [line.lstrip("* -\t") for line in body.splitlines() if re.match(r"\s*[*-]\s+", line)]
        name_bullets = [line for line in body_bullets if name.casefold() in line.casefold()]
        related_bullets = list(name_bullets)
        for bullet in name_bullets:
            prefix = re.match(r"\[([^\]]+)\]", bullet)
            if prefix:
                related_bullets.extend(
                    candidate for candidate in body_bullets
                    if candidate.startswith(prefix.group(0))
                )
        bullet_prefixes = {
            match.group(1)
            for candidate in body_bullets
            if (match := re.match(r"\[([^\]]+)\]", candidate))
        }
        if not related_bullets and body_bullets and len(bullet_prefixes) == 1:
            related_bullets = body_bullets
        targeted_lines = [
            line for line in (body + "\n" + pr_text + "\n" + context).splitlines()
            if name.casefold() in line.casefold()
        ]
        explicit = credited_sources("\n".join(targeted_lines))
        if not explicit and targeted_lines:
            whole_change_credit = credited_sources(body + "\n" + pr_text)
            if len(whole_change_credit) == 1:
                # A conventional two-line message often names the identifier
                # in the subject and puts "originally from ..." in the body.
                explicit = whole_change_credit
        if not explicit:
            explicit = credited_sources("\n".join(related_bullets))
        nearby_explicit = credited_sources(context)
        if not explicit and len(nearby_explicit) == 1:
            explicit = nearby_explicit
        if len(explicit) == 1:
            credited_source = explicit[0]
            direct_credit = any(
                SOURCE_PATTERNS[credited_source].search(line)
                for line in targeted_lines
            )
            credited_event = events.get(credited_source)
            selected_event = events.get(source)
            credit_is_later_hop = bool(
                credited_event and selected_event
                and credited_event["timestamp"] > selected_event["timestamp"]
            )
            if credit_is_later_hop:
                ported_via.append(credited_source)
                notes.append(
                    f"The TaystJK integration evidence credits {credited_source} as an immediate port source, "
                    f"but {source} has an earlier dated introduction and remains the ultimate origin."
                )
            else:
                source = credited_source
                confidence = "high" if direct_credit or len(present) <= 1 else "medium"
                method = "identifier-adjacent-explicit-credit" if direct_credit else "squash-feature-group-explicit-credit"
                notes.append(
                    f"An identifier-adjacent source/commit/PR line explicitly credits {source}."
                    if direct_credit else
                    f"The identifier's single-prefix squash feature group explicitly credits {source}."
                )
            credit_lines = [line for line in related_bullets if SOURCE_PATTERNS[credited_source].search(line)]
            if len(credit_lines) == 1:
                credited_bullet = credit_lines[0]

        if source == "unknown" and first:
            source = "taystjk"
            confidence = "medium"
            method = first.get("evidence_method", "taystjk-registration-history-after-upstream-checks")
            if method == "registration-line-blame":
                notes.append(
                    "The registration line is blamed to a TaystJK commit and all configured upstream heads were checked. "
                    "Line blame may identify a later edit rather than the original introduction."
                )
            else:
                notes.append(
                    "The first exact-name addition in the current registration file is a TaystJK commit; "
                    "all configured upstream heads were also checked."
                )

        if source == "unknown":
            notes.append("No initial-import match, upstream head match, exact-name pickaxe attribution, or identifier-adjacent credit was found.")

    pr = pr_for_commit(first, prs) if first else None
    body = commit_body(first_commit) if first_commit and first_commit != BASEJKA_REF else ""
    bullets = [line.lstrip("* -\t") for line in body.splitlines() if re.match(r"\s*[*-]\s+", line)]
    matching_bullets = [line for line in bullets if name.casefold() in line.casefold()]

    introduction_evidence = [
        {"source": source_name, **event}
        for source_name, event in sorted(
            events.items(),
            key=lambda item: (
                item[1]["timestamp"],
                ORIGIN_PRIORITY.index(item[0]) if item[0] in ORIGIN_PRIORITY else 999,
            ),
        )
    ]
    origin_event = events.get(source)
    downstream = [
        item for item in introduction_evidence
        if origin_event and item["source"] != source and item["timestamp"] > origin_event["timestamp"]
    ]

    origin_records = upstream.get(source, {}).get(key, [])
    if source == "basejka":
        origin_records = upstream.get("basejka", {}).get(key, [])
    elif source == "taystjk":
        origin_records = registrations

    signature_changed = bool(
        origin_records and signature(origin_records) != signature(registrations)
    )
    origin_timestamp = (
        origin_event["timestamp"] if origin_event
        else commit_timestamp(first_commit) if first_commit
        else 0
    )
    origin_sha = origin_event["sha"] if origin_event else first_commit
    tayst_introduction = introductions.get("taystjk", {}).get(key)
    modified_by: list[dict[str, Any]] = []
    saw_registration_change = False
    for raw_change in change_events.get(key, []):
        if raw_change["timestamp"] <= origin_timestamp or raw_change["sha"] == origin_sha:
            continue
        categories = set(raw_change.get("categories", []))
        # The import commit makes the identifier available in TaystJK. It is
        # not itself a behavioral modification, but a changed registration at
        # that point is retained when it differs from the origin snapshot.
        if tayst_introduction and raw_change["sha"] == tayst_introduction["sha"]:
            categories -= {"behavior-reference", "handler"}
            if not signature_changed:
                categories.discard("registration")
        if not categories:
            continue
        modified_by.append(attribute_change(
            {**raw_change, "categories": sorted(categories)},
            prs,
            project_histories,
        ))
        saw_registration_change |= "registration" in categories

    if signature_changed and not saw_registration_change:
        blamed: dict[str, dict[str, Any]] = {}
        for registration in registrations:
            blame_lines = [registration["line"]]
            condition = registration.get("condition")
            if condition:
                condition_tokens = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", condition)) - {"defined", "else"}
                source_lines = current_source(registration["path"]).splitlines()
                for candidate_line in range(
                    registration["line"] - 1,
                    max(0, registration["line"] - 80),
                    -1,
                ):
                    directive = source_lines[candidate_line - 1]
                    if re.match(r"\s*#\s*(?:if|ifdef|ifndef|elif)\b", directive) and (
                        not condition_tokens
                        or condition_tokens & set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", directive))
                    ):
                        blame_lines.append(candidate_line)
                        break
            for blame_line in blame_lines:
                event = registration_blame_event(registration["path"], blame_line)
                if (
                    event and event["timestamp"] > origin_timestamp
                    and event["sha"] != origin_sha
                ):
                    blamed[event["sha"]] = event
        for event in sorted(blamed.values(), key=lambda item: (item["timestamp"], item["sha"])):
            existing = next(
                (item for item in modified_by if item.get("commit") == event["sha"]),
                None,
            )
            if existing:
                existing["categories"] = sorted(set(existing.get("categories", [])) | {"registration"})
                existing["change"] = existing["change"].rstrip(".") + "; the current differing registration line is also blamed here."
                saw_registration_change = True
                continue
            change = attribute_change(event, prs, project_histories)
            change["change"] = "The current differing registration line is blamed to this commit."
            change["method"] = "registration-line-blame+" + change["method"]
            if change["confidence"] == "high":
                change["confidence"] = "medium"
            modified_by.append(change)
            saw_registration_change = True
        if not saw_registration_change:
            modified_by.append({
                "source": "unknown",
                "change": "The current structured registration differs from the origin, but its changing commit was not recoverable through patch history or current-line blame.",
                "categories": ["registration"],
                "commit": None,
                "confidence": "low",
                "method": "unresolved-registration-difference",
                "repository": "taystjk",
            })
            notes.append("The current registration signature differs from the origin snapshot, but the changing commit remains unresolved after patch-history and line-blame checks.")
        else:
            notes.append("Current-line blame identifies the later differing registration after the patch path could not be followed.")
    elif signature_changed:
        notes.append("Dated commit evidence identifies later registration changes relative to the origin snapshot.")

    modified_by.sort(key=lambda item: (
        item.get("timestamp") is None,
        item.get("timestamp", 0),
        item.get("commit") or "",
    ))

    origin_evidence = None
    if origin_records:
        record = sorted(origin_records, key=lambda item: (item["path"], item["line"]))[0]
        evidence_ref = BASEJKA_REF if source == "basejka" else (CURRENT_REF if source == "taystjk" else UPSTREAM_REFS.get(source))
        origin_evidence = {
            "ref": evidence_ref,
            "path": record["path"],
            "line": record["line"],
            "kind": record["kind"],
        }

    return {
        "source": source,
        "confidence": confidence,
        "status": "documented" if confidence == "high" else "needs-review",
        "method": method,
        "first_commit": first_commit,
        "first_ref": first_ref or (UPSTREAM_REFS.get(source) if source in UPSTREAM_REFS else None),
        "pr": pr.get("number") if pr else None,
        "pr_url": pr.get("html_url") if pr else None,
        "squash_bullet": matching_bullets[0] if len(matching_bullets) == 1 else credited_bullet,
        "upstream_presence": present,
        "introduction_evidence": introduction_evidence,
        "origin_introduction": ({"source": source, **origin_event} if origin_event else None),
        "downstream_introductions": downstream,
        "ported_via": ported_via,
        "origin_evidence": origin_evidence,
        "modified_by": modified_by,
        "notes": " ".join(notes),
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cache", default=".cvar-audit/cache")
    parser.add_argument("--output", default=".cvar-audit/provenance.json")
    parser.add_argument("--state", default=".cvar-audit/state.json")
    parser.add_argument("--pr-json", action="append", default=[])
    parser.add_argument("--refresh", action="store_true")
    parser.add_argument("--deep-pickaxe", action="store_true",
                        help="run exact-name history across all remotes for every non-base entry")
    parser.add_argument("--limit", type=int, help="resolve only the first N pending identifiers")
    args = parser.parse_args()

    cache = Path(args.cache)
    prs = load_prs(args.pr_json)
    all_refs = {"basejka": BASEJKA_REF, **UPSTREAM_REFS}
    inventories: dict[str, dict[str, dict[str, list[dict[str, Any]]]]] = {}
    for source, ref in {"current": CURRENT_REF, **all_refs}.items():
        inventories[source] = {}
        for kind in ("cvars", "commands"):
            inventories[source][kind] = grouped(extract_ref(ref, kind, cache, args.refresh))

    previous: dict[str, Any] = {}
    output_path = Path(args.output)
    if output_path.exists() and not args.refresh:
        candidate = json.loads(output_path.read_text())
        if (
            candidate.get("meta", {}).get("extractor_version") == EXTRACTOR_VERSION
            and candidate.get("meta", {}).get("resolver_version") == RESOLVER_VERSION
        ):
            previous = candidate
    result = {"meta": {"current_ref": CURRENT_REF, "basejka_ref": BASEJKA_REF,
                        "extractor_version": EXTRACTOR_VERSION,
                        "resolver_version": RESOLVER_VERSION}, "cvars": {}, "commands": {}}

    non_base_records: dict[str, list[dict[str, Any]]] = {}
    for kind in ("cvars", "commands"):
        base_names = set(inventories["basejka"][kind])
        for key, records in inventories["current"][kind].items():
            if key not in base_names:
                # Trace the TaystJK-side introduction even when the identifier
                # also exists in an upstream head. Independent cherry-picks and
                # squash merges do not share SHAs; their commit bodies/PRs may
                # be the only evidence that distinguishes the credited source.
                non_base_records.setdefault(key, []).extend(records)
    first_additions = batch_first_additions(non_base_records, cache, args.refresh)

    # A current-head match only proves that a project ships an identifier, not
    # that the project created it. Date the first mainline registration in every
    # project so later ports in any direction remain downstream evidence.
    introductions: dict[str, dict[str, dict[str, dict[str, Any]]]] = {
        "cvars": {}, "commands": {},
    }
    project_refs = {"taystjk": CURRENT_REF, **UPSTREAM_REFS}
    project_histories = {
        source: set(git("rev-list", "--first-parent", ref).splitlines())
        for source, ref in project_refs.items()
    }
    for kind in ("cvars", "commands"):
        base_names = set(inventories["basejka"][kind])
        non_base_names = set(inventories["current"][kind]) - base_names
        for source, ref in project_refs.items():
            inventory_source = "current" if source == "taystjk" else source
            records = {
                key: registrations
                for key, registrations in inventories[inventory_source][kind].items()
                if key in non_base_names
            }
            print(f"dating {kind} introductions in {source}...", flush=True)
            introductions[kind][source] = branch_introductions(
                ref, records, cache, args.refresh, f"{source}-{kind}",
            )

    changes: dict[str, dict[str, list[dict[str, Any]]]] = {}
    for kind in ("cvars", "commands"):
        historical_records: dict[str, list[dict[str, Any]]] = {}
        for entry_key, current_records in inventories["current"][kind].items():
            combined = list(current_records)
            for inventory_source in all_refs:
                combined.extend(inventories[inventory_source][kind].get(entry_key, []))
            historical_records[entry_key] = combined
        print(f"tracing {kind} registration and behavior changes in taystjk...", flush=True)
        changes[kind] = branch_change_events(
            CURRENT_REF,
            historical_records,
            cache,
            args.refresh,
            f"taystjk-{kind}",
        )

    processed = 0
    for kind in ("cvars", "commands"):
        result[kind].update(previous.get(kind, {}))
        upstream = {source: inventories[source][kind] for source in all_refs}
        base_names = set(inventories["basejka"][kind])
        for key in sorted(inventories["current"][kind]):
            if key in result[kind] and not args.refresh:
                continue
            if args.limit is not None and processed >= args.limit:
                continue
            result[kind][key] = resolve_one(
                key, inventories["current"][kind][key], base_names,
                upstream, prs, cache, args.refresh, introductions[kind],
                changes[kind], project_histories, first_additions, args.deep_pickaxe,
            )
            processed += 1
            if processed % 25 == 0:
                write_json(output_path, result)
                write_json(Path(args.state), {
                    "processed": processed,
                    "cvars": len(result["cvars"]),
                    "commands": len(result["commands"]),
                })

    write_json(output_path, result)
    write_json(Path(args.state), {
        "processed_this_run": processed,
        "cvars": len(result["cvars"]),
        "commands": len(result["commands"]),
        "complete": (
            len(result["cvars"]) == len(inventories["current"]["cvars"])
            and len(result["commands"]) == len(inventories["current"]["commands"])
        ),
    })
    print(
        f"resolved {len(result['cvars'])} cvars and {len(result['commands'])} commands "
        f"({processed} processed this run)"
    )


if __name__ == "__main__":
    main()
