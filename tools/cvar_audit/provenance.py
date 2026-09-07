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
RESOLVER_VERSION = 10
UPSTREAM_REFS = {
    "openjk": "openjk/master",
    "eternaljk": "eternaljk/master",
    "japro": "japro/master",
    "jk2mv": "jk2mv/master",
    "newjk": "newjk/master",
    "rend2": "somaz/rend2-unified-wip",
    "vulkan": "Sunny/master",
}
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


def signature(records: list[dict[str, Any]]) -> list[dict[str, Any]]:
    values = {
        (
            record.get("default"),
            tuple(record.get("flags") or ()),
            record.get("module"),
            record.get("renderer"),
        )
        for record in records
        if not str(record.get("kind", "")).startswith("implicit")
    }
    return [
        {"default": default, "flags": list(flags), "module": module, "renderer": renderer}
        for default, flags, module, renderer in sorted(values, key=lambda value: tuple(str(x) for x in value))
    ]


def resolve_one(
    key: str,
    registrations: list[dict[str, Any]],
    base_names: set[str],
    upstream: dict[str, dict[str, list[dict[str, Any]]]],
    prs: list[dict[str, Any]],
    cache: Path,
    refresh: bool,
    first_additions: dict[str, dict[str, Any]],
    deep_pickaxe: bool,
) -> dict[str, Any]:
    name = registrations[0]["name"]
    renderers = {record.get("renderer") for record in registrations if record.get("renderer")}
    present = [source for source, names in upstream.items() if key in names]
    notes: list[str] = []
    method = ""
    first: dict[str, Any] | None = None
    credited_bullet: str | None = None

    if key in base_names:
        source = "basejka"
        confidence = "high"
        method = "present-in-openjk-initial-source-import"
        first_commit = BASEJKA_REF
        first_ref = BASEJKA_REF
        notes.append("Identifier is present in OpenJK's initial Raven source-import snapshot.")
    else:
        if deep_pickaxe:
            commits = cached_pickaxe(name, cache, refresh)
            first = commits[0] if commits else None
        else:
            first = first_additions.get(key)
        first_sources = sources_for_refs(first["refs"]) if first else []

        # Renderer lineage takes precedence over the branch name when a cvar is
        # exclusive to one backend.  Many Vulkan cvars were inherited from rend2.
        if renderers == {"rd-rend2"} and "rend2" in present:
            source, confidence, method = "rend2", "high", "renderer-scope-and-upstream-presence"
        elif renderers == {"rd-vulkan"} and "rend2" in present:
            source, confidence, method = "rend2", "high", "vulkan-port-inherited-from-rend2"
        elif renderers == {"rd-vulkan"} and "vulkan" in present:
            source, confidence, method = "vulkan", "high", "vulkan-exclusive-upstream-presence"
        elif "openjk" in present:
            source, confidence, method = "openjk", "high", "post-import-openjk-head-presence"
        elif first_sources and deep_pickaxe:
            priority = ("openjk", "japro", "jk2mv", "newjk", "eternaljk", "rend2", "vulkan", "taystjk")
            source = next(candidate for candidate in priority if candidate in first_sources)
            confidence, method = "high", "earliest-pickaxe-commit"
        else:
            # Independent cherry-picks do not share SHAs.  Head presence is still
            # stronger evidence than an origin-only squash commit.
            priority = ("japro", "jk2mv", "newjk", "eternaljk", "rend2", "vulkan")
            source = next((candidate for candidate in priority if candidate in present), "unknown")
            confidence = (
                "high" if source in {"eternaljk", "rend2", "vulkan"} and len(present) <= 2
                else "medium" if source != "unknown" else "low"
            )
            method = "upstream-head-presence" if source != "unknown" else "unresolved"

        first_commit = first["sha"] if first else None
        first_ref = (first["refs"][0] if first and first["refs"] else None)

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
            source = explicit[0]
            direct_credit = any(name.casefold() in line.casefold() for line in targeted_lines)
            confidence = "high" if direct_credit or len(present) <= 1 else "medium"
            method = "identifier-adjacent-explicit-credit" if direct_credit else "squash-feature-group-explicit-credit"
            notes.append(
                f"An identifier-adjacent source/commit/PR line explicitly credits {source}."
                if direct_credit else
                f"The identifier's single-prefix squash feature group explicitly credits {source}."
            )
            credit_lines = [line for line in related_bullets if SOURCE_PATTERNS[source].search(line)]
            if len(credit_lines) == 1:
                credited_bullet = credit_lines[0]

        if source == "unknown" and first and "taystjk" in first_sources:
            source = "taystjk"
            confidence = "medium"
            method = first.get("evidence_method", "origin-only-pickaxe-after-upstream-checks")
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

    origin_records = upstream.get(source, {}).get(key, [])
    if source == "basejka":
        origin_records = upstream.get("basejka", {}).get(key, [])
    modified_by: list[dict[str, Any]] = []
    if origin_records and signature(origin_records) != signature(registrations):
        modified_by.append({
            "source": "unknown",
            "change": "Registration defaults, flags, modules, or renderer scope differ from the originating snapshot.",
            "commit": None,
            "confidence": "low",
        })
        notes.append("The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.")

    origin_evidence = None
    if origin_records:
        record = sorted(origin_records, key=lambda item: (item["path"], item["line"]))[0]
        evidence_ref = BASEJKA_REF if source == "basejka" else UPSTREAM_REFS.get(source)
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
                upstream, prs, cache, args.refresh, first_additions, args.deep_pickaxe,
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
