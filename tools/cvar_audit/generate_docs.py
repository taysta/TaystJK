#!/usr/bin/env python3
"""Generate the GitHub Pages console reference from _data JSON files."""

from __future__ import annotations

import argparse
import hashlib
import html
import json
import re
import subprocess
from collections import Counter
from functools import lru_cache
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Iterable

from build_reference import baseline_for
from provenance import CURRENT_REF


ORIGIN_LABELS = {
    "taystjk": "TaystJK",
    "eternaljk": "EternalJK",
    "japro": "jaPRO",
    "jk2mv": "JK2MV",
    "newjk": "NewJK / NewMod",
    "rend2": "rend2",
    "vulkan": "Vulkan",
    "openjk": "OpenJK",
    "basejka": "Base Jedi Academy",
    "quake3": "Quake III lineage",
    "unknown": "Unknown",
}
ORIGIN_ORDER = (
    "taystjk",
    "eternaljk",
    "japro",
    "newjk",
    "vulkan",
    "rend2",
    "openjk",
    "basejka",
    "jk2mv",
    "quake3",
    "unknown",
)
ORIGIN_REPOS = {
    "taystjk": "taysta/TaystJK",
    "eternaljk": "eternalcodes/EternalJK",
    "japro": "videoP/jaPRO",
    "jk2mv": "mvdevs/jk2mv",
    "newjk": "jkanewmod/NewJK",
    "rend2": "SomaZ/OpenJK",
    "vulkan": "JKSunny/EternalJK",
    "openjk": "JACoders/OpenJK",
    "basejka": "JACoders/OpenJK",
    "quake3": "id-Software/Quake-III-Arena",
}
FLAG_HELP = {
    "CVAR_ARCHIVE": "saved to the user configuration",
    "CVAR_ARCHIVE_ND": "saved to configuration without marking the cvar as user-created",
    "CVAR_LATCH": "latched until the relevant subsystem or map is restarted",
    "CVAR_CHEAT": "requires cheats",
    "CVAR_INIT": "initialization/command-line setting",
    "CVAR_ROM": "read-only after registration",
    "CVAR_USERINFO": "sent in the client's userinfo",
    "CVAR_SERVERINFO": "published in serverinfo",
    "CVAR_SYSTEMINFO": "replicated in systeminfo",
    "CVAR_NORESTART": "preserved across cvar restart",
    "CVAR_PROTECTED": "protected from unsafe remote changes",
    "CVAR_INTERNAL": "internal UI/engine state",
    "CVAR_TEMP": "temporary and not archived",
}
# Why a cvar is engine-managed, in the reader's terms.  Each clause names the
# evidence the pipeline actually matched, so the notice stays checkable.
ENGINE_MANAGED_HELP = {
    "CVAR_ROM": "it is read-only after registration (<code>CVAR_ROM</code>)",
    "CVAR_INTERNAL": "it is internal UI/engine state, hidden from every cvar listing (<code>CVAR_INTERNAL</code>)",
    "implicit-write": (
        "no registration exists — every cited site only writes it with <code>Cvar_Set</code>, "
        "so a value you set is replaced the next time that code runs"
    ),
    "editorial": "it is internal state rather than a setting; see the description above",
}
NETWORK_HELP = {
    "client-only": "Local to the client/UI/renderer.",
    "needs-server-support": "Sent to, or only useful with, a supporting game server.",
    "server-authoritative": "Owned or enforced by the server.",
    "feature-flagged": "Client behavior is negotiated through a server feature flag.",
}


def git(*args: str) -> str:
    result = subprocess.run(["git", *args], text=True, errors="replace", stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return result.stdout.strip() if result.returncode == 0 else ""


def introduction_date(item: dict[str, Any]) -> str:
    return datetime.fromtimestamp(int(item["timestamp"]), timezone.utc).date().isoformat()


def evidence_date(item: dict[str, Any], key: str) -> str:
    timestamp = item.get(key)
    if timestamp is None:
        return "—"
    return datetime.fromtimestamp(int(timestamp), timezone.utc).date().isoformat()


def introduction_commit_link(item: dict[str, Any]) -> str:
    repo = ORIGIN_REPOS.get(item["source"])
    sha = item["sha"]
    if not repo:
        return code(sha[:12])
    return f"[`{sha[:12]}`](https://github.com/{repo}/commit/{sha})"


def change_commit_link(item: dict[str, Any]) -> str:
    sha = item.get("commit")
    if not sha:
        return "—"
    repo = ORIGIN_REPOS.get(item.get("repository", "taystjk"), ORIGIN_REPOS["taystjk"])
    return f"[`{sha[:12]}`](https://github.com/{repo}/commit/{sha})"


def load(path: Path) -> Any:
    return json.loads(path.read_text())


def write(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text.rstrip() + "\n")


def frontmatter(
    title: str,
    nav_order: int | None = None,
    parent: str | None = None,
    nav_exclude: bool = False,
    *,
    wide: bool = False,
    reference_app: bool = False,
    description: str | None = None,
    toc: bool = False,
) -> str:
    lines = ["---", f"title: {json.dumps(title)}", "layout: reference", "generated: true"]
    if nav_order is not None:
        lines.append(f"nav_order: {nav_order}")
    if parent:
        lines.append(f"parent: {json.dumps(parent)}")
    if nav_exclude:
        lines.extend(["nav_exclude: true", "search_exclude: false"])
    if wide:
        lines.append("wide: true")
    if reference_app:
        lines.append("reference_app: true")
    if description:
        lines.append(f"description: {json.dumps(description)}")
    if toc:
        lines.append("toc: true")
    lines.extend(["---", ""])
    return "\n".join(lines)


def code(value: Any) -> str:
    return f"`{str(value).replace('`', '&#96;')}`"


def esc(value: Any) -> str:
    return html.escape(str(value), quote=True)


def slug(name: str) -> str:
    value = name.casefold().replace("+", "plus-").replace("-", "minus-")
    value = re.sub(r"[^a-z0-9_]+", "-", value).strip("-") or "entry"
    # Jekyll does not publish pages whose filename begins with an underscore.
    if value.startswith("_"):
        value = f"entry-{value}"
    return f"{value}-{hashlib.sha1(name.casefold().encode()).hexdigest()[:7]}"


def collection_slug(name: str) -> str:
    return re.sub(r"[^a-z0-9]+", "-", name.casefold()).strip("-")


def detail_url(entry: dict[str, Any]) -> str:
    return f"/TaystJK/reference/{entry['kind']}s/{slug(entry['name'])}/"


@lru_cache(maxsize=1)
def source_snapshot() -> tuple[str | None, str | None]:
    """The commit the checked-in reference was generated from, and its date."""
    meta_path = Path("_data/reference-meta.json")
    if not meta_path.exists():
        return None, None
    meta = load(meta_path)
    return meta.get("source_commit"), meta.get("source_commit_date")


def generated_from(sha: str) -> str:
    """Footer stating which source snapshot a page was generated from."""
    _, date = source_snapshot()
    when = f" on {esc(date[:10])}" if date else ""
    return (
        f'<p class="page-provenance">Generated from source commit '
        f'<a href="https://github.com/taysta/TaystJK/tree/{esc(sha)}"><code>{esc(sha[:12])}</code></a>'
        f"{when}. Anything merged after that is not reflected here.</p>"
    )


# Registrations carry independent inventory comparisons in `baselines`.
# The cumulative buckets below apply only to editorial feature defaults.
BASELINE_PANELS: tuple[tuple[str, str, tuple[str, ...]], ...] = (
    ("eternaljk", "EternalJK", ("eternaljk",)),
    ("openjk", "OpenJK", ("eternaljk", "openjk")),
    ("basejka", "base Jedi Academy", ("eternaljk", "openjk", "basejka")),
)
DEFAULT_BASELINE = "eternaljk"


def resolve_url(url: str) -> Path | None:
    """The file a /TaystJK/ link resolves to, or None when it does not exist."""
    relative = url.removeprefix("/TaystJK/")
    if not relative:
        return Path("index.md")
    if any(part.startswith(("_", ".")) for part in Path(relative).parts):
        return None
    direct = Path(relative)
    if direct.is_file():
        return direct
    if url.endswith("/"):
        page = Path(f"{relative.rstrip('/')}.md")
        if page.is_file():
            return page
        index = Path(relative) / "index.md"
        if index.is_file():
            return index
    return None


WHATS_NEW_OVERRIDES = Path("tools/cvar_audit/whats-new-overrides.json")
ENTRY_OVERRIDE_KEYS = {"hide", "promote", "summary", "group"}
FEATURE_KEYS = {"title", "origin", "group", "summary", "page", "added_on"}
FRONT_MATTER = re.compile(r"\A---\n(.*?)\n---\n", re.S)


def load_whats_new_overrides() -> dict[str, Any]:
    data = load(WHATS_NEW_OVERRIDES) if WHATS_NEW_OVERRIDES.exists() else {}
    return {"entries": data.get("entries", {}), "features": data.get("features", [])}


def validate_whats_new_overrides(
    entries: list[dict[str, Any]], overrides: dict[str, Any],
) -> list[str]:
    """Reject a hand-tuning file that no longer matches the reference data."""
    errors: list[str] = []
    known = {entry["name"].casefold() for entry in entries}
    for name, tuning in sorted(overrides["entries"].items()):
        label = f"whats-new-overrides entries.{name}"
        if name.casefold() not in known:
            errors.append(
                f"{label}: no such cvar or command. It was renamed or removed; "
                "update or delete this override."
            )
        if not isinstance(tuning, dict):
            errors.append(f"{label}: expected an object")
            continue
        for key in sorted(set(tuning) - ENTRY_OVERRIDE_KEYS):
            errors.append(f"{label}: unknown key {key!r}")
        if "hide" in tuning and not isinstance(tuning["hide"], bool):
            errors.append(f"{label}: hide must be true or false")
        if "promote" in tuning and not isinstance(tuning["promote"], int):
            errors.append(f"{label}: promote must be an integer rank")
        for key in ("summary", "group"):
            if key in tuning and not (isinstance(tuning[key], str) and tuning[key].strip()):
                errors.append(f"{label}: {key} must be a non-empty string")
    for index, feature in enumerate(overrides["features"]):
        label = f"whats-new-overrides features[{index}]"
        if not isinstance(feature, dict):
            errors.append(f"{label}: expected an object")
            continue
        for key in sorted(set(feature) - FEATURE_KEYS):
            errors.append(f"{label}: unknown key {key!r}")
        for key in ("title", "origin", "page"):
            if not feature.get(key):
                errors.append(f"{label}: missing {key}")
        origin = feature.get("origin")
        if origin and origin not in ORIGIN_LABELS:
            errors.append(f"{label}: unknown origin {origin!r}")
        elif origin and baseline_for(origin) is None:
            errors.append(
                f"{label}: origin {origin!r} is part of base Jedi Academy, "
                "so the feature is not new against any baseline"
            )
    return errors


def page_front_matter(path: Path) -> dict[str, str]:
    """Parse the flat scalar keys of a page's front matter."""
    match = FRONT_MATTER.match(path.read_text())
    if not match:
        return {}
    fields: dict[str, str] = {}
    for line in match.group(1).splitlines():
        key, separator, value = line.partition(":")
        if separator and not key.startswith((" ", "\t", "#")):
            fields[key.strip()] = value.strip().strip('"').strip("'")
    return fields


def declared_features(root: Path = Path(".")) -> list[dict[str, Any]]:
    """Collect hand-written pages that opt into the what's-new page.

    A page joins by carrying `whats_new: true` with `origin` and `added_on`, as
    described in CONVENTIONS.md, so a feature moves out of the seed list simply
    by being written.
    """
    features: list[dict[str, Any]] = []
    for path in sorted(root.glob("*.md")) + sorted(root.glob("*/*.md")):
        if path.parts[0] in {"reference", "_site", ".migration", ".plan"}:
            continue
        fields = page_front_matter(path)
        if fields.get("whats_new", "").lower() != "true":
            continue
        features.append({
            "title": fields.get("title") or path.stem,
            "origin": fields.get("origin"),
            "group": fields.get("group"),
            "summary": fields.get("description"),
            "added_on": fields.get("added_on"),
            "page": "/TaystJK/" + str(path.with_suffix("")).replace("index", "") + "/",
            "source": str(path),
        })
    return features


EMOJI_SOURCE_DIR = "assets/japro/gfx/emoji"
EMOJI_ASSET_DIR = Path("assets/emoji")
# cg_local.h: MAX_EMOJI_LENGTH 24, MAX_LOADABLE_EMOJIS 256.
MAX_LOADABLE_EMOJIS = 256


def q_strstrip(value: str, strip: str, repl: str) -> str:
    """Port of Q_strstrip in shared/qcommon/q_string.c.

    A stripped character is replaced by the character at the same index in
    `repl`, or dropped when `repl` is shorter than that index.
    """
    out = []
    for char in value:
        index = strip.find(char)
        if index == -1:
            out.append(char)
        elif index < len(repl):
            out.append(repl[index])
    return "".join(out)


def emoji_token(filename: str) -> str:
    """The chat token a shipped emoji file produces.

    Mirrors CG_LoadEmojis in codemp/cgame/cg_main.c: drop the extension, treat
    `!` as "uppercase the next character" (it exists because a pk3 lowercases
    filenames), then substitute the characters a filename cannot contain --
    backtick becomes a colon and tilde becomes `>`.  The filename is not the
    token: 181 of the 186 shipped files differ from it.
    """
    name = filename[:-4] if filename.lower().endswith(".png") else filename
    chars = list(name)
    index = 0
    while index < len(chars):
        if chars[index] == "!" and index + 1 < len(chars):
            chars[index + 1] = chars[index + 1].upper()
            index += 2
        else:
            index += 1
    return q_strstrip("".join(chars), "`~!", ":>")


def emoji_files(ref: str) -> list[str]:
    listing = git("ls-tree", "-r", "--name-only", ref, "--", EMOJI_SOURCE_DIR + "/")
    return sorted(
        line.rsplit("/", 1)[-1] for line in listing.splitlines() if line.lower().endswith(".png")
    )


def export_emoji_assets(ref: str, filenames: list[str]) -> dict[str, str]:
    """Copy the shipped emoji into the site, keyed by a URL-safe name.

    The originals contain `#`, backticks and brackets, which are painful to
    reference in a URL, so each is published under a stable digest of its
    source filename.  Re-exported on every run, so the set cannot drift from
    the source branch without the page changing too.
    """
    EMOJI_ASSET_DIR.mkdir(parents=True, exist_ok=True)
    published: dict[str, str] = {}
    for filename in filenames:
        digest = hashlib.sha1(filename.encode()).hexdigest()[:12]
        target = EMOJI_ASSET_DIR / f"{digest}.png"
        blob = subprocess.run(
            ["git", "show", f"{ref}:{EMOJI_SOURCE_DIR}/{filename}"],
            check=True, stdout=subprocess.PIPE,
        ).stdout
        if not target.exists() or target.read_bytes() != blob:
            target.write_bytes(blob)
        published[filename] = target.name
    for stale in EMOJI_ASSET_DIR.glob("*.png"):
        if stale.name not in published.values():
            stale.unlink()
    return published


def emoji_page(sha: str) -> tuple[str, list[str]]:
    """The shipped chat emoji, with the token that produces each one."""
    filenames = emoji_files(sha)
    published = export_emoji_assets(sha, filenames)
    warnings: list[str] = []
    if len(filenames) > MAX_LOADABLE_EMOJIS:
        warnings.append(
            f"{len(filenames)} emoji files ship, but the client loads at most "
            f"{MAX_LOADABLE_EMOJIS}; the page lists files the client will not load"
        )
    seen: dict[str, str] = {}
    rows = []
    for filename in filenames:
        token = emoji_token(filename)
        if token in seen:
            warnings.append(
                f"emoji token {token!r} is produced by both {seen[token]!r} and {filename!r}"
            )
        seen[token] = filename
        rows.append(
            '<figure class="emoji-tile">'
            f'<img src="{{{{ \'/assets/emoji/{published[filename]}\' | relative_url }}}}"'
            f' alt="" width="32" height="32" loading="lazy">'
            f"<figcaption>{esc(token)}</figcaption></figure>"
        )
    head = frontmatter(
        "Chat emoji",
        9,
        "Features",
        wide=True,
        description=(
            "Every chat emoji TaystJK ships, and the text you type to send each one."
        ),
    ) + f"""
<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Chat emoji

<p class="page-lede">TaystJK ships {len(filenames)} chat emoji. Type the text under an image to send it. They are drawn in the chat box only when <code>cg_chatBoxEmojis</code> is on.</p>

{generated_from(sha)}
</div>

The client builds this list by reading the files in `gfx/emoji`, so a server or a
pk3 you install can add more. `listEmojis` prints what your own client loaded.

<div class="emoji-grid">
{chr(10).join(rows)}
</div>
"""
    return head, warnings


ADDED_ON_ANCHOR = "/TaystJK/features/whats-new/#how-to-tell-what-your-build-has"
# Every claim here is read from source: the printf in CG_ModVersion_f, the
# version cvar in codemp/qcommon/common.cpp, and the git describe/rev-parse
# calls CMakeLists.txt uses to fill GIT_TAG and GIT_HASH.
ADDED_ON_NOTE = """## How to tell what your build has

Availability here is a date, because TaystJK has no release versioning. Releases roll under
a single `latest` tag, so a build identifies itself by when it was compiled.

- `version` prints the engine build and ends with the date it was compiled.
- `modversion` prints the game module's compile date and time, followed by an identifier
  like `latest-6ff04c0ba`.

**Compare the date.** If your build is older than the date on an entry, your build does not
have it.

The rest of that identifier cannot answer "is mine newer". The `latest` in front is the
same string on every release. The hash behind it is not ordered either: two short hashes
cannot be ranked against each other without the repository.

A date marked *needs review* rests on an attribution that could not be proven exactly. The
entry is real; treat the date as approximate.
"""


def added_on_cell(entry: dict[str, Any]) -> str:
    """Short availability marker for a list row."""
    value = entry.get("added_on")
    if not value:
        return ""
    if isinstance(value, str):  # hand-written front matter supplies a plain string
        return f' <span class="meta-chip">{esc(value)}</span>'
    chip = "meta-chip" if value.get("certain") else "status-chip"
    suffix = "" if value.get("certain") else " · needs review"
    return f' <span class="{chip}">{esc(value["date"])}{suffix}</span>'


def added_on_row(entry: dict[str, Any]) -> str | None:
    """The `Added` row for an entry's detail table."""
    value = entry.get("added_on")
    if not isinstance(value, dict):
        return None
    commit = (
        f'[{code(value["short"])}]'
        f'(https://github.com/taysta/TaystJK/commit/{esc(value["commit"])})'
    )
    caveat = (
        "" if value.get("certain")
        else ' <span class="status-chip">needs review</span>'
    )
    return (
        f'| Added | {esc(value["date"])} in {commit}{caveat} '
        f'— [how to compare this against your build]({ADDED_ON_ANCHOR}) |'
    )


def feature_row(feature: dict[str, Any]) -> str:
    """A manually declared, non-cvar addition.

    A destination that does not exist yet is shown as plain text with a marker
    rather than as a link, so the page never ships a reader a 404 while the
    documentation it promises is still unwritten.
    """
    title = esc(feature["title"])
    if feature.get("unresolved"):
        name = f'{title} <span class="meta-chip">page not written yet</span>'
    else:
        name = f"[{title}]({feature['page']})"
    summary = f" — {esc(feature['summary'])}" if feature.get("summary") else ""
    return (
        f"- {name} {badge(feature['origin'])}"
        f"{added_on_cell(feature)} <span class=\"meta-chip\">feature</span>{summary}"
    )


def whats_new_rows(
    entries: list[dict[str, Any]], features: list[dict[str, Any]],
    tuning: dict[str, Any],
) -> list[str]:
    """Rows grouped by topic; promoted entries lead, then alphabetical."""
    grouped: dict[str, list[tuple[float, str, str]]] = {}
    for entry in entries:
        override = tuning.get(entry["name"], {})
        category = override.get("group") or entry["category"]
        summary = override.get("summary") or entry["summary"]
        rank = override.get("promote")
        grouped.setdefault(category, []).append((
            rank if isinstance(rank, int) else float("inf"),
            entry["name"].casefold(),
            f"- [{code(entry['name'])}]({detail_url(entry)}) "
            f"{badge(entry['origin']['source'])}{added_on_cell(entry)} — {esc(summary)}",
        ))
    for feature in features:
        grouped.setdefault(feature.get("group") or "Other", []).append(
            # Hand-written features lead their topic: they are the additions a
            # reader cannot discover from a cvar list.
            (float("-inf"), str(feature["title"]).casefold(), feature_row(feature))
        )
    lines: list[str] = []
    for category in sorted(grouped):
        members = sorted(grouped[category], key=lambda item: (item[0], item[1]))
        lines.extend([f"### {category} ({len(members)})", ""])
        lines.extend(row for _rank, _key, row in members)
        lines.append("")
    return lines


def whats_new_page(entries: list[dict[str, Any]]) -> tuple[str, list[str], list[str]]:
    """The what's-new page: one panel per baseline, all rendered server-side.

    Every panel is in the HTML and the selector only hides the ones not chosen,
    so the page still answers the question with JavaScript unavailable.

    Returns the page plus the names hidden by hand and any warnings, so hiding
    an entry cannot quietly remove it from the record.
    """
    overrides = load_whats_new_overrides()
    tuning = overrides["entries"]
    warnings: list[str] = []

    # A page that declares itself supersedes its seed entry, so a feature needs
    # no cleanup here once it is written.
    declared = declared_features()
    declared_titles = {str(item["title"]).casefold() for item in declared}
    features = declared + [
        feature for feature in overrides["features"]
        if str(feature["title"]).casefold() not in declared_titles
    ]
    for feature in features:
        destination = str(feature.get("page") or "")
        if resolve_url(destination) is None:
            feature["unresolved"] = True
            warnings.append(
                f"what's-new feature {feature['title']!r} points at {destination or '(nothing)'}, "
                "which does not exist yet; listed without a link"
            )

    hidden = sorted(
        entry["name"] for entry in entries
        if tuning.get(entry["name"], {}).get("hide")
    )
    entries = [entry for entry in entries if not tuning.get(entry["name"], {}).get("hide")]

    totals = {
        name: (
            sum(1 for entry in entries if name in entry["baselines"])
            + sum(1 for feature in features if baseline_for(feature["origin"]) in buckets)
        )
        for name, _label, buckets in BASELINE_PANELS
    }
    head = frontmatter(
        "What's new",
        1,
        "Features",
        wide=True,
        description=(
            "Every cvar and console command TaystJK adds, grouped by topic and "
            "filtered by the client you are coming from."
        ),
    ) + f"""
<div class="page-heading" markdown="1">
<p class="eyebrow">Generated from the console reference</p>

# What's new

<p class="page-lede">What TaystJK adds over the client you already know. Pick that client below to compare console entries against its recorded source snapshot, alongside the documented feature additions.</p>

{generated_from(entries[0]["source_commit"])}
</div>

{ADDED_ON_NOTE}

<section class="baseline-guide" data-baseline-guide>
  <div class="baseline-selector-shell platform-selector-shell">
    <p class="platform-selector-label">Coming from</p>
    <div class="baseline-selector platform-selector" role="tablist" aria-label="Baseline client">
"""
    tabs = [
        f'      <button type="button" id="baseline-tab-{name}" role="tab"'
        f' aria-controls="baseline-panel-{name}" aria-selected="false" tabindex="-1"'
        f' data-baseline-choice="{name}">{esc(label)} ({totals[name]:,})</button>'
        for name, label, _buckets in BASELINE_PANELS
    ]
    body = ["    </div>", "  </div>", ""]
    for name, label, buckets in BASELINE_PANELS:
        members = [entry for entry in entries if name in entry["baselines"]]
        panel_features = [
            feature for feature in features if baseline_for(feature["origin"]) in buckets
        ]
        body.extend([
            f'  <section class="baseline-panel platform-panel" id="baseline-panel-{name}"'
            f' role="tabpanel" aria-labelledby="baseline-tab-{name}" tabindex="0"'
            f' data-baseline-panel="{name}" markdown="1">',
            "",
            f"## New since {label} ({len(members) + len(panel_features):,})",
            "",
        ])
        body.extend(whats_new_rows(members, panel_features, tuning))
        # The close tag must start at column 0. Each panel ends with a list, and kramdown
        # reads an indented line after one as continuation content of the final item -- so
        # an indented "</section>" never closes the panel, and the next panel is parsed
        # inside this one. The toggle then has nothing it can show.
        body.extend(["</section>", ""])
    body.append("</section>")
    return head + "\n".join(tabs + body), hidden, warnings


MACRO_KIND_LABELS = {
    "compiler-builtin": "set at build time",
    "enum-constant": "enum constant",
    "unresolved-identifier": "unresolved identifier",
}


def default_cell(entry: dict[str, Any]) -> str:
    """Render a default, showing the macro it came from where there is one."""
    value = entry.get("default")
    if value is None:
        return code("dynamic")
    macro = entry.get("default_macro")
    kind = entry.get("default_macro_kind")
    if kind:
        # Not a literal: the identifier is all the source commits to.
        return f"{code(value)} — {esc(MACRO_KIND_LABELS.get(kind, kind))}"
    if macro and macro != value:
        return f"{code(value)} <span class=\"meta-chip\">from {esc(macro)}</span>"
    return code(value)


def badge(origin: str) -> str:
    return f'<span class="label ref-origin ref-origin-{esc(origin)}">{esc(ORIGIN_LABELS.get(origin, origin))}</span>'


def catalog_app(
    mode: str = "all",
    *,
    preset_key: str | None = None,
    preset_value: str | None = None,
    multi_select: bool = False,
) -> str:
    """Return the progressively enhanced catalog shell.

    The browser receives a compact search index rather than thousands of table
    rows. Detail pages remain static and crawlable.
    """
    catalog_title = {
        "cvar": "Find a cvar",
        "command": "Find a command",
    }.get(mode, "Find a cvar or command")
    attrs = [
        'class="reference-catalog"',
        'id="catalog"',
        'data-reference-app',
        f'data-mode="{esc(mode)}"',
        'data-catalog-url="{{ \'/assets/data/catalog.json\' | relative_url }}"',
    ]
    if preset_key and preset_value:
        attrs.append(f'data-preset-{esc(preset_key)}="{esc(preset_value)}"')
    if multi_select:
        filters = """    <div class="catalog-filters">
      <div class="filter-dropdown" data-filter-dropdown="origin">
        <button class="filter-toggle" type="button" data-filter-toggle="origin" aria-expanded="false"><span>Origin</span><strong data-filter-summary="origin">Any origin</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="origin" hidden>
          <div class="filter-options" data-filter-options="origin"></div>
          <button class="filter-clear" type="button" data-clear-filter="origin">Clear origin</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="module">
        <button class="filter-toggle" type="button" data-filter-toggle="module" aria-expanded="false"><span>Module</span><strong data-filter-summary="module">Any module</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="module" hidden>
          <div class="filter-options" data-filter-options="module"></div>
          <button class="filter-clear" type="button" data-clear-filter="module">Clear module</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="category">
        <button class="filter-toggle" type="button" data-filter-toggle="category" aria-expanded="false"><span>Topic</span><strong data-filter-summary="category">Any topic</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="category" hidden>
          <div class="filter-options" data-filter-options="category"></div>
          <button class="filter-clear" type="button" data-clear-filter="category">Clear topic</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="feature">
        <button class="filter-toggle" type="button" data-filter-toggle="feature" aria-expanded="false"><span>Feature</span><strong data-filter-summary="feature">Any feature</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="feature" hidden>
          <div class="filter-options" data-filter-options="feature"></div>
          <button class="filter-clear" type="button" data-clear-filter="feature">Clear feature</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="renderer">
        <button class="filter-toggle" type="button" data-filter-toggle="renderer" aria-expanded="false"><span>Renderer</span><strong data-filter-summary="renderer">Any renderer</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="renderer" hidden>
          <div class="filter-options" data-filter-options="renderer">
            <label class="filter-checkbox"><input type="checkbox" name="renderer" value="renderer-specific" data-filter="renderer"><span>Renderer-specific only</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="renderer" value="none" data-filter="renderer"><span>Not renderer-specific</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="renderer">Clear renderer</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="status">
        <button class="filter-toggle" type="button" data-filter-toggle="status" aria-expanded="false"><span>Documentation</span><strong data-filter-summary="status">Any status</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="status" hidden>
          <div class="filter-options">
            <label class="filter-checkbox"><input type="checkbox" name="status" value="documented" data-filter="status"><span>Documented</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="status" value="needs-review" data-filter="status"><span>Needs review</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="status">Clear documentation</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="network">
        <button class="filter-toggle" type="button" data-filter-toggle="network" aria-expanded="false"><span>Network scope</span><strong data-filter-summary="network">Any scope</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="network" hidden>
          <div class="filter-options" data-filter-options="network"></div>
          <button class="filter-clear" type="button" data-clear-filter="network">Clear network scope</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="coverage">
        <button class="filter-toggle" type="button" data-filter-toggle="coverage" aria-expanded="false"><span>In game</span><strong data-filter-summary="coverage">Any coverage</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="coverage" hidden>
          <div class="filter-options">
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="xdocs" data-filter="coverage"><span>Has xdocs entry</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="menu" data-filter="coverage"><span>Has menu entry</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="no-xdocs" data-filter="coverage"><span>Missing from xdocs</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="no-menu" data-filter="coverage"><span>Missing from menus</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="coverage">Clear in-game coverage</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="audience" data-cvar-filter>
        <button class="filter-toggle" type="button" data-filter-toggle="audience" aria-expanded="false"><span>Settable</span><strong data-filter-summary="audience">Any cvar</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="audience" hidden>
          <div class="filter-options">
            <label class="filter-checkbox"><input type="checkbox" name="audience" value="settable" data-filter="audience"><span>Player-settable</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="audience" value="engine-managed" data-filter="audience"><span>Engine-managed</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="audience">Clear settable</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="flag" data-cvar-filter>
        <button class="filter-toggle" type="button" data-filter-toggle="flag" aria-expanded="false"><span>Cvar flag</span><strong data-filter-summary="flag">Any flag</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="flag" hidden>
          <div class="filter-options" data-filter-options="flag"></div>
          <button class="filter-clear" type="button" data-clear-filter="flag">Clear cvar flags</button>
        </div>
      </div>
    </div>"""
    else:
        filters = """    <div class="catalog-filters">
      <label><span>Origin</span><select name="origin" data-filter="origin"><option value="">Any origin</option></select></label>
      <label><span>Module</span><select name="module" data-filter="module"><option value="">Any module</option></select></label>
      <label><span>Topic</span><select name="category" data-filter="category"><option value="">Any topic</option></select></label>
      <label><span>Feature</span><select name="feature" data-filter="feature"><option value="">Any feature</option></select></label>
      <label><span>Renderer</span><select name="renderer" data-filter="renderer"><option value="">Any renderer</option><option value="renderer-specific">Renderer-specific only</option><option value="none">Not renderer-specific</option></select></label>
      <label><span>Documentation</span><select name="status" data-filter="status"><option value="">Any status</option><option value="documented">Documented</option><option value="needs-review">Needs review</option></select></label>
      <label><span>Network scope</span><select name="network" data-filter="network"><option value="">Any scope</option></select></label>
      <label><span>In game</span><select name="coverage" data-filter="coverage"><option value="">Any coverage</option><option value="xdocs">Has xdocs entry</option><option value="menu">Has menu entry</option><option value="no-xdocs">Missing from xdocs</option><option value="no-menu">Missing from menus</option></select></label>
      <label data-cvar-filter><span>Settable</span><select name="audience" data-filter="audience"><option value="">Any cvar</option><option value="settable">Player-settable</option><option value="engine-managed">Engine-managed</option></select></label>
      <label data-cvar-filter><span>Cvar flag</span><select name="flag" data-filter="flag"><option value="">Any flag</option></select></label>
    </div>"""
    return f"""
<section {' '.join(attrs)} aria-labelledby="catalog-title">
  <div class="catalog-heading">
    <div>
      <p class="section-kicker">Console index</p>
      <h2 id="catalog-title">{catalog_title}</h2>
    </div>
    <p class="catalog-shortcut"><kbd>/</kbd> to search</p>
  </div>

  <form class="catalog-controls" data-catalog-form role="search">
    <label class="catalog-search">
      <span>Search the reference</span>
      <span class="search-field">
        <svg aria-hidden="true" viewBox="0 0 24 24"><path d="m21 21-4.35-4.35m2.35-5.65a8 8 0 1 1-16 0 8 8 0 0 1 16 0Z"/></svg>
        <input type="search" name="q" data-search autocomplete="off" spellcheck="false" placeholder="Try cg_fov, download, bloom…">
      </span>
    </label>

    <div class="catalog-kind" data-kind-tabs aria-label="Entry type">
      <button type="button" data-kind="all">All</button>
      <button type="button" data-kind="cvar">Cvars</button>
      <button type="button" data-kind="command">Commands</button>
    </div>

{filters}

    <div class="catalog-actions">
      <button type="reset" class="button button-quiet" data-reset>Clear filters</button>
      <label class="catalog-sort"><span>Sort</span><select name="sort" data-sort><option value="origin">Origin</option><option value="relevance">Relevance</option><option value="name">Name</option><option value="category">Topic</option><option value="feature">Feature</option><option value="module">Module</option></select></label>
    </div>
  </form>

  <div class="catalog-status" aria-live="polite">
    <p data-result-count>Loading the reference…</p>
    <p class="active-filters" data-active-filters></p>
  </div>
  <div class="catalog-results" data-results aria-busy="true"></div>
  <div class="catalog-empty" data-empty hidden>
    <h3>No matching entries</h3>
    <p>Try a shorter search or clear one of the filters.</p>
  </div>
  <div class="catalog-more"><button type="button" class="button button-secondary" data-load-more hidden>Show more</button></div>
  <noscript><p class="catalog-noscript">JavaScript is required for the interactive index. You can still browse the <a href="{{{{ '/reference/all/' | relative_url }}}}">static A–Z index</a> or use the generated JSON files.</p></noscript>
</section>
""".strip()


def evidence_link(item: dict[str, Any], label: str | None = None) -> str:
    text = label or f"{item.get('path')}:{item.get('line')}"
    url = item.get("url")
    return f"[{text}]({url})" if url else code(text)


def upstream_evidence_link(origin: dict[str, Any], refs: dict[str, str]) -> str | None:
    item = origin.get("origin_evidence")
    source = origin.get("source")
    repo = ORIGIN_REPOS.get(source)
    if not item or not repo:
        return None
    ref = item.get("ref") or "master"
    sha = refs.get(ref, ref)
    url = f"https://github.com/{repo}/blame/{sha}/{item['path']}#L{item['line']}"
    return f"[{item['path']}:{item['line']}]({url})"


def value_table(entry: dict[str, Any]) -> str:
    values = entry.get("values", [])
    if not values:
        return "No discrete value list is enforced or documented in the inspected source."
    lines = ["| Value | Meaning | Evidence |", "|:--|:--|:--|"]
    for item in values:
        evidence = blamed(item.get("evidence"), entry["source_commit"])
        lines.append(f"| {code(item['value'])} | {item['meaning']} | {evidence_link(evidence) if evidence else '—'} |")
    return "\n".join(lines)


def blamed(evidence: dict[str, Any] | None, sha: str) -> dict[str, Any] | None:
    """Fill in a blame URL for evidence recorded as a bare path and line."""
    if evidence and not evidence.get("url") and evidence.get("path"):
        return dict(evidence, url=source_url(evidence["path"], evidence["line"], sha))
    return evidence


def source_url(path: str, line: int, sha: str) -> str:
    return f"https://github.com/taysta/TaystJK/blame/{sha}/{path}#L{line}"


def mirror_target(entry: dict[str, Any], cvar_names: dict[str, str]) -> tuple[str, str | None]:
    """The staged setting's reference spelling and detail-page URL, if it has one."""
    target = entry["menu_mirror"]["target"]
    canonical = cvar_names.get(target.casefold())
    if not canonical:
        return target, None
    return canonical, detail_url({"kind": "cvar", "name": canonical})


def mirror_clause(entry: dict[str, Any], cvar_names: dict[str, str]) -> str:
    """Name the setting a menu staging copy stands in for."""
    name, url = mirror_target(entry, cvar_names)
    label = f"<code>{esc(name)}</code>"
    if url:
        label = f'<a href="{url}">{label}</a>'
    return (
        f"it is the menu's staging copy of {label}, which the menu writes through when the "
        "change is applied and reads back when it is opened"
    )


def mirror_row(entry: dict[str, Any], cvar_names: dict[str, str]) -> str:
    """The At-a-glance cell pairing a staging copy with its setting and evidence."""
    name, url = mirror_target(entry, cvar_names)
    cell = f"[{code(name)}]({url})" if url else code(name)
    mirror = entry["menu_mirror"]
    links = [
        evidence_link(mirror[key], label)
        for key, label in (("apply", "written through"), ("read", "read back"))
        if mirror.get(key)
    ]
    return f"{cell} — {', '.join(links)}" if links else cell


def command_link(name: str, kind: str = "command") -> str:
    return f"[{code(name)}]({detail_url({'kind': kind, 'name': name})})"


def joined(values: list[str], conjunction: str = "or") -> str:
    if len(values) < 2:
        return "".join(values)
    return f"{', '.join(values[:-1])} {conjunction} {values[-1]}"


def bit_notice(entry: dict[str, Any]) -> str | None:
    """Point a bitmask cvar at the command that owns its bits."""
    commands = (entry.get("bits") or {}).get("commands") or []
    if not commands:
        return None
    names = joined([f"<code>{esc(name)}</code>" for name in commands])
    return (
        f'<p class="ref-notice"><strong>Set with {names}.</strong> '
        "Each bit is a separate option, so the command toggles one of them per use and leaves "
        "the rest alone. Setting a raw value by hand replaces every option at once.</p>"
    )


def bit_table(entry: dict[str, Any]) -> list[str]:
    """The named options behind a bitmask value.

    This replaces the inferred value list, which can only reach the handful of
    bits with a distinctive read site and would otherwise describe the same bit
    twice in two vocabularies.
    """
    bits = entry.get("bits")
    if not bits or not bits["options"]:
        return []
    commands = bits.get("commands") or []
    lead = (
        f"Toggle one with {joined([command_link(name) for name in commands])} "
        "followed by the bit number."
        if commands else "Each bit is one option."
    )
    # Where the pipeline already traced a bit to the code that reads it, keep
    # that evidence beside the source table's own label.
    reads = {str(option.get("value")): option for option in entry.get("values", [])}
    lines = [
        "## Bits", "",
        f"{lead} The value column is that bit on its own — "
        f"{evidence_link(bits['evidence'], 'the labels come from the source table')}.", "",
        "| Bit | Value | Meaning | Read by |", "|:--|:--|:--|:--|",
    ]
    for option in bits["options"]:
        read = blamed((reads.get(option["value"]) or {}).get("evidence"), entry["source_commit"])
        evidence = evidence_link(read) if read else "—"
        lines.append(
            f"| {option['bit']} | {code(option['value'])} | {option['meaning']} | {evidence} |"
        )
    return lines


def engine_managed_notice(entry: dict[str, Any], cvar_names: dict[str, str] | None = None) -> str | None:
    """Return the callout that separates engine state from a real setting."""
    basis = entry.get("engine_managed_basis") or []
    reasons = [ENGINE_MANAGED_HELP[item] for item in basis if item in ENGINE_MANAGED_HELP]
    if entry.get("menu_mirror") and "menu-mirror" in basis:
        reasons.append(mirror_clause(entry, cvar_names or {}))
    if not reasons:
        return None
    return (
        '<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value '
        "itself, so it is not a setting to change by hand: " + "; ".join(reasons) + ".</p>"
    )


def detail_page(entry: dict[str, Any], refs: dict[str, str], cvar_names: dict[str, str] | None = None) -> str:
    origin = entry["origin"]
    lines = [frontmatter(entry["name"], nav_exclude=True), f"# {code(entry['name'])}", "", badge(origin["source"]), ""]
    if entry["status"] != "documented":
        lines.extend([
            '<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>', "",
        ])
    for notice in (engine_managed_notice(entry, cvar_names), bit_notice(entry)):
        if notice:
            lines.extend([notice, ""])
    lines.extend([entry["description"], "", "## At a glance", "", "| Field | Value |", "|:--|:--|"])
    lines.append(f"| Category | {entry['category']} |")
    if entry.get("feature"):
        lines.append(f"| Feature family | {entry['feature']} |")
    lines.extend([
        f"| Module | {code(entry['module'])} |",
        f"| Also registered in | {', '.join(code(value) for value in entry.get('modules', []))} |",
        f"| Renderer | {', '.join(code(value) for value in entry.get('renderer', [])) or 'All / not renderer-specific'} |",
        f"| Network scope | {code(entry['network'])} — {NETWORK_HELP.get(entry['network'], '')} |",
        f"| Derivation | {code(entry['derivation'])} |",
        f"| Confidence | {code(entry['confidence'])} |",
        *( [added_on_row(entry)] if added_on_row(entry) else [] ),
    ])
    xdocs = entry.get("xdocs")
    if xdocs:
        xdocs_item = dict(xdocs, url=source_url(xdocs["path"], xdocs["line"], entry["source_commit"]))
        xdocs_value = "Yes — " + evidence_link(xdocs_item)
    else:
        xdocs_value = "No"
    menus = entry.get("menu_entries", [])
    if menus:
        menu_links = [
            evidence_link(
                dict(item, url=source_url(item["path"], item["line"], entry["source_commit"])),
                f"{Path(item['path']).name}:{item['line']}",
            )
            for item in menus[:3]
        ]
        menu_value = "Yes — " + ", ".join(menu_links)
    else:
        menu_value = "No"
    lines.extend([
        f"| In-game xdocs | {xdocs_value} |",
        f"| In-game menu | {menu_value} |",
    ])
    if entry["kind"] == "cvar":
        lines.extend([
            f"| Default | {default_cell(entry)} |",
            f"| Value type | {code(entry['value_type'])} |",
            f"| Restart | {'Yes; the value is latched.' if entry['requires_restart'] else 'No latch flag is registered.'} |",
            f"| Cheat protected | {'Yes' if entry['cheat_protected'] else 'No'} |",
            f"| Player-settable | {'No — the game writes this value.' if entry.get('engine_managed') else 'Yes'} |",
            *([f"| Staging copy of | {mirror_row(entry, cvar_names or {})} |"] if entry.get("menu_mirror") else []),
            *([f"| Configure with | {joined([command_link(name) for name in entry['bits']['commands']])} |"]
              if (entry.get("bits") or {}).get("commands") else []),
            "",
            *(bit_table(entry) or ["## Values", "", value_table(entry), ""]),
        ])
        if entry.get("range"):
            lines.extend(["## Enforced ranges", ""])
            for item in entry["range"]:
                lines.append(
                    f"- {code(item['min'])} through {code(item['max'])}"
                    f" ({'integer' if item.get('integral') else 'numeric'}; {item.get('kind', 'range check')}"
                    f"{'' if item.get('confidence', 'high') == 'high' else ', not enforced on every path'}) — "
                    f"{evidence_link(dict(item['evidence'], url=source_url(item['evidence']['path'], item['evidence']['line'], entry['source_commit'])))}"
                )
            lines.append("")
        lines.extend(["## Flags", ""])
        if entry.get("flags"):
            lines.extend(f"- {code(flag)} — {FLAG_HELP.get(flag, 'fork/source-defined flag; see registration evidence')}" for flag in entry["flags"])
        else:
            lines.append("No cvar flags are registered at the cited site.")
        defaults = {(item.get("value"), item.get("module"), item.get("renderer"), item.get("condition")) for item in entry.get("defaults", [])}
        if len(defaults) > 1:
            lines.extend(["", "## Registration-specific defaults", "", "| Default | Module | Renderer | Compile condition |", "|:--|:--|:--|:--|"])
            for value, module, renderer, condition in sorted(defaults, key=lambda item: tuple(str(x) for x in item)):
                lines.append(f"| {code(value)} | {code(module)} | {code(renderer or '—')} | {code(condition or 'always')} |")
    else:
        lines.extend([
            f"| Syntax | {code(entry['syntax'])} |",
            f"| Cheat protected | {'Yes' if entry['cheat_protected'] else 'No'} |",
            *([f"| Configures | {', '.join(command_link(name, 'cvar') for name in entry['configures'])} |"]
              if entry.get("configures") else []),
            "", "## Arguments and gating", "",
        ])
        if entry.get("arguments"):
            lines.append("Arguments: " + ", ".join(code(value) for value in entry["arguments"]) + ".")
        else:
            lines.append("No verified argument schema is available beyond the syntax shown above.")
        if entry.get("gating"):
            lines.append("Gating: " + ", ".join(code(value) for value in entry["gating"]) + ".")
    lines.extend(["", "## Provenance", "", f"Origin: {badge(origin['source'])}", ""])
    origin_introduction = origin.get("origin_introduction")
    if origin_introduction:
        authored_key = (
            "content_author_timestamp"
            if origin_introduction.get("content_author_timestamp")
            else "author_timestamp"
        )
        authored = evidence_date(origin_introduction, authored_key)
        proposal = evidence_date(origin_introduction, "pr_created_timestamp")
        chronology = f"content authored {code(authored)}"
        if proposal != "—":
            chronology += f", PR opened {code(proposal)}"
        chronology += f", integrated {code(introduction_date(origin_introduction))}"
        lines.append(
            f"- Ultimate-origin introduction: {introduction_commit_link(origin_introduction)} "
            f"in {badge(origin_introduction['source'])} ({chronology})"
        )
    if origin.get("first_commit"):
        # Except for the Raven baseline (and optional deep-pickaxe mode), the
        # first-addition SHA is from TaystJK's own registration-file history.
        # The separately linked origin_evidence points into the upstream repo.
        repo = "JACoders/OpenJK" if origin["first_commit"] == "14cea1563762076974bee277afadbd5bf234c494" else "taysta/TaystJK"
        if not origin_introduction or origin["first_commit"] != origin_introduction.get("sha"):
            label = "Baseline evidence" if origin["first_commit"] == "14cea1563762076974bee277afadbd5bf234c494" else "TaystJK integration evidence"
            lines.append(f"- {label}: [`{origin['first_commit'][:12]}`](https://github.com/{repo}/commit/{origin['first_commit']})")
    if origin.get("pr_url"):
        lines.append(f"- Origin pull request: [#{origin['pr']}]({origin['pr_url']})")
    if (
        origin.get("integration_pr_url")
        and origin.get("integration_pr_url") != origin.get("pr_url")
    ):
        lines.append(
            f"- TaystJK integration pull request: "
            f"[#{origin['integration_pr']}]({origin['integration_pr_url']})"
        )
    if origin.get("squash_bullet"):
        lines.append(f"- Matching squash bullet: {code(origin['squash_bullet'])}")
    upstream = upstream_evidence_link(origin, refs)
    if upstream:
        lines.append(f"- Upstream registration evidence: {upstream}")
    lines.extend([
        f"- Attribution method: {code(origin.get('method', 'unknown'))}",
        f"- Attribution confidence: {code(origin.get('confidence', 'low'))}",
    ])
    if origin.get("notes"):
        lines.append(f"- Notes: {origin['notes']}")
    introductions = origin.get("introduction_evidence", [])
    if introductions:
        lines.extend([
            "", "### Dated project introductions", "",
            "Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.", "",
            "| Project | Authored | PR opened | Integrated | Commit | Relationship |", "|:--|:--|:--|:--|:--|:--|",
        ])
        for item in introductions:
            if origin_introduction and item["source"] == origin_introduction["source"] and item["sha"] == origin_introduction["sha"]:
                relationship = "Ultimate origin"
            elif origin_introduction and item["sha"] == origin_introduction["sha"]:
                relationship = "Shared integration commit"
            else:
                relationship = "Other project appearance"
            authored_key = "content_author_timestamp" if item.get("content_author_timestamp") else "author_timestamp"
            proposal = evidence_date(item, "pr_created_timestamp")
            if item.get("pr_url") and proposal != "—":
                proposal = f"[{proposal}]({item['pr_url']})"
            lines.append(
                f"| {badge(item['source'])} | {code(evidence_date(item, authored_key))} | "
                f"{proposal} | {code(introduction_date(item))} | "
                f"{introduction_commit_link(item)} | {relationship} |"
            )
    if origin.get("ported_via"):
        lines.extend([
            "", "Immediate port-source credit: "
            + ", ".join(badge(source) for source in origin["ported_via"])
            + ". The earlier dated project remains the ultimate origin.",
        ])
    if entry.get("modified_by"):
        lines.extend([
            "", "### Later changes", "",
            "These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.", "",
            "| Date | Change source | Commit / subject | Evidence | Confidence |", "|:--|:--|:--|:--|:--|",
        ])
        for change in entry["modified_by"]:
            date = code(introduction_date(change)) if change.get("timestamp") else "—"
            subject = str(change.get("subject") or "unresolved").replace("|", "\\|")
            commit = change_commit_link(change)
            if change.get("pr_url"):
                commit += f" · [PR #{change['pr']}]({change['pr_url']})"
            paths = change.get("paths", [])
            path_note = ", ".join(code(path) for path in paths[:3])
            if len(paths) > 3:
                path_note += f" and {len(paths) - 3} more"
            evidence = change["change"] + (f" {path_note}" if path_note else "")
            lines.append(
                f"| {date} | {badge(change['source'])} | {commit}<br>{subject} | "
                f"{evidence} | {code(change.get('confidence', 'unknown'))} |"
            )
    lines.extend(["", "## Evidence", ""])
    for item in entry["evidence"]:
        extra = f" ({item.get('registration_kind')})" if item.get("registration_kind") else ""
        condition = f"; condition {code(item['condition'])}" if item.get("condition") else ""
        lines.append(f"- {item['kind']}: {evidence_link(item)}{extra}{condition}")
    lines.extend(["", generated_from(entry["source_commit"])])
    return "\n".join(lines)


def count_table(entries: list[dict[str, Any]], key) -> str:
    counts = Counter(key(entry) for entry in entries)
    return "\n".join(["| Group | Count |", "|:--|--:|"] + [f"| {label} | {count} |" for label, count in sorted(counts.items())])


def compact_table(entries: list[dict[str, Any]]) -> str:
    if not entries:
        return "None."
    lines = ["| Name | Kind | Module | Summary |", "|:--|:--|:--|:--|"]
    for entry in entries:
        lines.append(f"| [{code(entry['name'])}]({detail_url(entry)}) | {entry['kind']} | {entry['module']} | {entry['summary']} |")
    return "\n".join(lines)


def collection_page(
    title: str,
    intro: str,
    entries: list[dict[str, Any]],
    nav_order: int,
    parent: str,
    *,
    preset_key: str,
    preset_value: str,
    mode: str = "all",
) -> str:
    cvar_count = sum(entry["kind"] == "cvar" for entry in entries)
    command_count = sum(entry["kind"] == "command" for entry in entries)
    breakdown = []
    if cvar_count:
        breakdown.append(f"{cvar_count:,} cvars")
    if command_count:
        breakdown.append(f"{command_count:,} commands")
    lines = [
        frontmatter(
            title,
            nav_order,
            parent,
            wide=True,
            reference_app=True,
            description=f"Browse {', '.join(breakdown)} in the TaystJK console reference.",
        ),
        '<div class="page-heading" markdown="1">',
        '<p class="eyebrow">Filtered collection</p>',
        f"<h1>{esc(title)}</h1>",
        f'<p class="page-lede">{intro} This collection contains {", ".join(breakdown)}.</p>',
        "</div>",
        "",
        catalog_app(mode, preset_key=preset_key, preset_value=preset_value),
        "",
    ]
    return "\n".join(lines)


def compact_catalog_entry(entry: dict[str, Any]) -> dict[str, Any]:
    """Build the public search record without shipping source-evidence payloads."""
    item: dict[str, Any] = {
        "kind": entry["kind"],
        "name": entry["name"],
        "url": detail_url(entry),
        "module": entry["module"],
        "modules": entry.get("modules", [entry["module"]]),
        "renderer": entry.get("renderer", []),
        "summary": entry["summary"],
        "description": entry["description"],
        "network": entry["network"],
        "status": entry["status"],
        "confidence": entry["confidence"],
        "derivation": entry["derivation"],
        "category": entry["category"],
        "feature": entry.get("feature"),
        "xdocs": bool(entry.get("xdocs")),
        "menu": bool(entry.get("menu_entries")),
        "cheat_protected": entry["cheat_protected"],
        "origin": entry["origin"]["source"],
        "origin_confidence": entry["origin"]["confidence"],
    }
    if entry["kind"] == "cvar":
        item.update({
            "default": entry.get("default"),
            "flags": entry.get("flags", []),
            "value_type": entry.get("value_type"),
            "requires_restart": entry.get("requires_restart", False),
            "engine_managed": entry.get("engine_managed", False),
            "values": [
                {"value": option["value"], "meaning": option["meaning"]}
                for option in entry.get("values", [])
            ],
        })
    else:
        item.update({
            "syntax": entry.get("syntax"),
            "arguments": entry.get("arguments", []),
            "gating": entry.get("gating", []),
        })
    return item


def static_index_page(cvars: list[dict[str, Any]], commands: list[dict[str, Any]]) -> str:
    lines = [
        frontmatter(
            "Static A–Z index",
            wide=True,
            description="A no-JavaScript index of every TaystJK cvar and console command.",
        ),
        '<div class="page-heading" markdown="1">',
        '<p class="eyebrow">No-JavaScript directory</p>',
        '<h1>Static A–Z index</h1>',
        '<p class="page-lede">Every detail page in the generated reference, listed alphabetically.</p>',
        '</div>',
    ]
    for title, selected in (("Cvars", cvars), ("Commands", commands)):
        lines.extend(["", f"## {title}", '<div class="static-index-list">'])
        for entry in selected:
            lines.append(f'<a href="{detail_url(entry)}"><code>{esc(entry["name"])}</code></a>')
        lines.append("</div>")
    return "\n".join(lines)


def home_page(cvars: list[dict[str, Any]], commands: list[dict[str, Any]]) -> str:
    entries = cvars + commands
    total_count = len(entries)
    japro_count = sum(1 for entry in entries if entry["origin"]["source"] == "japro")
    return frontmatter(
        "TaystJK — one client for Jedi Academy multiplayer",
        1,
        wide=True,
        toc=True,
        description=(
            "TaystJK is a cross-platform Jedi Academy multiplayer client built for Base JKA, "
            "JA+/JA++, jaPRO, and Lugormod servers, with modern performance and quality-of-life improvements."
        ),
    ) + f"""
<div class="docs-overview">
  <section class="docs-intro" aria-labelledby="page-title">
    <p class="eyebrow">TaystJK documentation</p>
    <h1 id="page-title">One client for Jedi Academy multiplayer</h1>
    <p class="page-lede">Move between the game's major server communities without giving up a modern, responsive client. TaystJK combines mod-aware compatibility with cross-platform performance and practical quality-of-life improvements.</p>
    <nav class="docs-intro-links" aria-label="Project links">
      <a href="{{{{ '/install/' | relative_url }}}}">Installation</a>
      <a href="{{{{ '/overview/' | relative_url }}}}">How this site works</a>
      <a href="https://github.com/taysta/TaystJK/releases/tag/latest">Latest release</a>
      <a href="https://github.com/taysta/TaystJK">Source repository</a>
    </nav>
  </section>

  <nav class="docs-quick-links" aria-labelledby="quick-links-heading">
    <h2 id="quick-links-heading" data-toc-skip>Quick links</h2>
    <a href="{{{{ '/server-hosting/' | relative_url }}}}">
      <strong>Run a server</strong>
      <span>Docker Compose, server.cfg, downloads, and reflists</span>
    </a>
    <a href="{{{{ '/development/' | relative_url }}}}">
      <strong>Work on TaystJK</strong>
      <span>Compilation, debugging, and bundled libraries</span>
    </a>
    <a href="{{{{ '/reference/' | relative_url }}}}">
      <strong>Find a console control</strong>
      <span>{len(cvars):,} cvars and {len(commands):,} commands derived from source</span>
    </a>
  </nav>
</div>

<section class="home-purpose" aria-labelledby="purpose-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Why TaystJK exists</p>
      <h2 id="purpose-heading">Keep the community connected</h2>
    </div>
    <p>Jedi Academy multiplayer is spread across server mods with distinct rules and features. TaystJK is maintained as a dependable everyday client across those communities.</p>
  </div>

  <div class="purpose-principles">
    <article>
      <span>01</span>
      <h3>Compatibility first</h3>
      <p>Detect the server family and adapt prediction, presentation, and client behavior while leaving gameplay authority with the server.</p>
    </article>
    <article>
      <span>02</span>
      <h3>Modern where it matters</h3>
      <p>Maintain fast, stable builds for Windows, Linux, and macOS—including current 64-bit and Apple Silicon systems.</p>
    </article>
    <article>
      <span>03</span>
      <h3>Better to live with</h3>
      <p>Refine the HUD, controls, console, demos, downloads, rendering, and other everyday details without losing the feel of JKA.</p>
    </article>
  </div>

  <p class="project-lineage">TaystJK is a considered assembly of proven work from OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2, the community's Vulkan renderer work, and TaystJK's own contributors. Code brought across project boundaries is ported with permission, credited to its source, and maintained as part of a coherent client rather than a loose collection of patches. <a href="{{{{ '/reference/sources/' | relative_url }}}}">See the source lineage.</a></p>

  <p class="project-lineage"><strong>jaPRO</strong> is the largest single source of what this client can do: {japro_count} of the {total_count:,} entries in the console reference originate there. TaystJK bundles jaPRO's gamecode on both sides &mdash; the client-side <code>cgame</code>, so its HUD and movement tools work on any server, and the server-side <code>jampgame</code>, so a TaystJK server hosts race, Tribes and the admin system with nothing else installed. The code is maintained upstream, so bugs in the rules belong to <a href="https://github.com/videoP/jaPRO">videoP/jaPRO</a>. <a href="{{{{ '/overview/' | relative_url }}}}">What the split means.</a></p>
</section>

<section class="home-compatibility" aria-labelledby="compatibility-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Server compatibility</p>
      <h2 id="compatibility-heading">What each integration covers</h2>
    </div>
    <p>Support is adapted to the information and features each server exposes, so its depth differs by mod.</p>
  </div>

  <div class="compatibility-grid">
    <article class="compatibility-card">
      <div><span class="compatibility-mark">Base</span><h3>Base JKA</h3></div>
      <p>Standard multiplayer with no companion server mod required, augmented by engine fixes, renderer choices, interface controls, and safer networking.</p>
    </article>
    <article class="compatibility-card">
      <div><span class="compatibility-mark">JA+</span><h3>JA+ / JA++</h3></div>
      <p>Server detection and feature-aware handling for the JA+ family: roll variants, flip-kicks, grappling, custom animations, plugin settings, and private-duel isolation.</p>
    </article>
    <article class="compatibility-card">
      <div><span class="compatibility-mark">PRO</span><h3>jaPRO</h3></div>
      <p>The deepest integration: racing and custom movement styles, timing and checkpoint tools, movement analysis, demo workflows, improved prediction, and Tribes mode.</p>
    </article>
    <article class="compatibility-card">
      <div><span class="compatibility-mark">LMD</span><h3>Lugormod</h3></div>
      <p>A dedicated compatibility path for extended jumping and Force Rage, player scaling, Lugormod's custom stat layout, and its command behavior.</p>
    </article>
  </div>

  <p class="compatibility-note"><strong>Client support does not replace the server mod.</strong> The connected server still defines gameplay and determines which mod-specific features are available.</p>
</section>

<section class="home-guides" aria-labelledby="guides-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Guides and reference</p>
      <h2 id="guides-heading">Browse the documentation</h2>
    </div>
    <p>Use the task guides for setup and maintenance, or search the source-derived console reference.</p>
  </div>

  <div class="home-guide-grid">
    <a class="home-guide" href="{{{{ '/install/' | relative_url }}}}">
      <h3>Installation</h3>
      <p>Client setup, game files, clean directory layouts, and first launch.</p>
      <span>Installation guide →</span>
    </a>
    <a class="home-guide" href="{{{{ '/server-hosting/' | relative_url }}}}">
      <h3>Server administration</h3>
      <p>Dedicated server deployment, map rotation, downloads, and PK3 references.</p>
      <span>Server guide →</span>
    </a>
    <a class="home-guide" href="{{{{ '/features/' | relative_url }}}}">
      <h3>Features</h3>
      <p>What this client adds: HUD and movement tools, renderers, cosmetics, and movement styles.</p>
      <span>Browse the features →</span>
    </a>
    <a class="home-guide" href="{{{{ '/development/' | relative_url }}}}">
      <h3>Development</h3>
      <p>Build configuration, platform targets, debugging, and dependency details.</p>
      <span>Development guide →</span>
    </a>
    <a class="home-guide" href="{{{{ '/reference/' | relative_url }}}}">
      <h3>Console reference</h3>
      <p>Search controls by topic, module, origin, and documentation coverage.</p>
      <span>Browse the reference →</span>
    </a>
  </div>
</section>

<section class="home-resources" aria-labelledby="resources-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Project details</p>
      <h2 id="resources-heading">Technical information</h2>
    </div>
  </div>
  <div class="home-resource-list">
    <a href="{{{{ '/development/libraries/' | relative_url }}}}">
      <strong>Bundled libraries</strong>
      <span>Dependency versions and system-library selection rules.</span>
    </a>
    <a href="{{{{ '/reference/sources/' | relative_url }}}}">
      <strong>Source provenance</strong>
      <span>How reference entries and code lineage are determined.</span>
    </a>
    <a href="{{{{ '/troubleshooting/' | relative_url }}}}">
      <strong>Troubleshooting</strong>
      <span>Common problems listed by the symptom you actually see.</span>
    </a>
    <a href="{{{{ '/mod-compatibility/' | relative_url }}}}">
      <strong>Mod compatibility</strong>
      <span>Why a feature works on one server and does nothing on another.</span>
    </a>
    <a href="{{{{ '/ai-disclosure/' | relative_url }}}}">
      <strong>AI disclosure</strong>
      <span>How this documentation was produced and reviewed.</span>
    </a>
  </div>
</section>
"""


def audit_page(
    entries: list[dict[str, Any]], runtime: dict[str, Any] | None,
    hidden_from_whats_new: list[str] | None = None,
) -> str:
    review = [entry for entry in entries if entry["status"] != "documented"]
    ambiguous = [entry for entry in entries if entry["origin"]["confidence"] != "high"]
    modified = [entry for entry in entries if entry.get("modified_by")]
    modification_count = sum(len(entry.get("modified_by", [])) for entry in entries)
    lines = [frontmatter("Audit report", 7, "Console reference", toc=True,
        description="What the reference knows and how confidently: coverage, provenance confidence, and the entries still needing review."), "# Audit report", "",
             "This is the deliberately untidy review queue behind the published reference. `unknown` and `needs-review` are used instead of guesses.", "",
             "## Totals by origin", "", count_table(entries, lambda entry: ORIGIN_LABELS.get(entry["origin"]["source"], entry["origin"]["source"])), "",
             "## Runtime reconciliation", ""]
    if hidden_from_whats_new:
        # Hiding is editorial, never a deletion: the entry keeps its detail page
        # and is listed here so it stays discoverable.
        lines[-1:] = [
            f"## Hidden from the what's-new page ({len(hidden_from_whats_new)})", "",
            "Suppressed by `tools/cvar_audit/whats-new-overrides.json`. Each still has a"
            " detail page and still appears in the reference.", "",
            *(f"- {code(name)}" for name in hidden_from_whats_new), "",
            "## Runtime reconciliation", "",
        ]
    if runtime:
        lines.extend([
            f"Runtime target: {code(runtime['target'])}; build: {code(runtime['build'])}.", "",
            runtime["notes"], "",
            "| Registry | Runtime | Static union | Runtime-only | Expected static-only |", "|:--|--:|--:|--:|--:|",
            f"| Cvars | {runtime['cvars']['runtime_count']} | {runtime['cvars']['static_union_count']} | {len(runtime['cvars']['runtime_only'])} | {len(runtime['cvars']['static_not_in_runtime_target'])} |",
            f"| Commands | {runtime['commands']['runtime_count']} | {runtime['commands']['static_union_count']} | {len(runtime['commands']['runtime_only'])} | {len(runtime['commands']['static_not_in_runtime_target'])} |", "",
            "Runtime-only cvars: " + (", ".join(code(value) for value in runtime["cvars"]["runtime_only"]) or "none") + ".", "",
            "Runtime-only commands: " + (", ".join(code(value) for value in runtime["commands"]["runtime_only"]) or "none") + ".", "",
            "The dump was captured from stdout after loading `mp/ffa3`; stdout does not use the client console scrollback buffer. Cvars and commands were dumped in separate launches so neither list could displace the other.", "",
        ])
    else:
        lines.extend(["No runtime report was supplied to the generator.", ""])
    lines.extend([
        f"## Provenance needing review ({len(ambiguous)})", "", compact_table(ambiguous), "",
        f"## Semantics or options needing review ({len(review)})", "", compact_table(review), "",
        f"## Post-origin change history ({len(modified)} entries; {modification_count} events)", "",
        "These entries have dated post-origin registration or behavior evidence on TaystJK's inherited first-parent history. Each detail page links the exact commit and records whether attribution comes from explicit credit, a unique project mainline, shared lineage, or an unresolved registration difference.", "",
        compact_table(modified), "",
    ])
    return "\n".join(lines)


def sources_page(refs: dict[str, str]) -> str:
    rows = ["| Origin | Repository / snapshot | Role |", "|:--|:--|:--|"]
    details = {
        "basejka": "Raven/id JA source present in OpenJK's initial import",
        "openjk": "post-import OpenJK additions",
        "eternaljk": "public EternalJK additions and explicitly credited private continuation work",
        "japro": "jaPRO gameplay, HUD, movement, and admin work",
        "jk2mv": "selected JK2MV ports",
        "newjk": "NewJK and explicitly credited NewMod ports",
        "rend2": "SomaZ rend2-unified renderer lineage",
        "vulkan": "JKSunny Vulkan renderer lineage",
        "taystjk": "entries first evidenced in TaystJK after upstream checks",
    }
    ref_for = {
        "basejka": "14cea1563762076974bee277afadbd5bf234c494",
        "openjk": "openjk/master", "eternaljk": "eternaljk/master", "japro": "japro/main",
        "jk2mv": "jk2mv/master", "newjk": "newjk/master", "rend2": "somaz/rend2-unified-wip",
        "vulkan": "Sunny/master", "taystjk": "origin/master",
    }
    for source in details:
        repo = ORIGIN_REPOS[source]
        ref = ref_for[source]
        sha = refs.get(ref, ref)
        rows.append(f"| {badge(source)} | [`{repo}@{sha[:12]}`](https://github.com/{repo}/tree/{sha}) | {details[source]} |")
    return frontmatter("Sources and methodology", 6, "Console reference", toc=True,
        description="Which upstream project each entry is attributed to, and the rules the resolver follows to decide.") + """
# Sources and methodology

The reference separates origin from current availability. An entry inherited from Raven remains **Base Jedi Academy** even though OpenJK and every fork ship it. A cvar registered only by `rd-vulkan` is not automatically Vulkan-originated: the resolver checks rend2 and other upstream snapshots first.

""" + "\n".join(rows) + """

## Evidence process

1. The extractor masks comments, follows preprocessor conditions, and recognizes XCVAR macros, legacy VM tables, direct and syscall `Cvar_Get`/`Cvar_Register` calls, dynamic format expansions, command tables, input tables, renderer tables, and server-forwarded command names.
2. The Raven baseline is OpenJK commit `14cea1563762076974bee277afadbd5bf234c494`, the initial JA source dump.
3. For every non-base name, the resolver finds its first registration on the current first-parent line of TaystJK, OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2, and Vulkan. It separately records the exact registration's first author date, the target project's PR creation date, and the mainline integration date. Authorship and submission are considered before merge order, so merging an upstream PR into TaystJK first does not make TaystJK its origin.
4. Equal chronology is resolved only afterward, using explicit cross-project PR links and shared commits as fork-lineage evidence. PR numbers are scoped to their target repository, and a lone available PR date is not compared against candidates whose PR archive was not supplied. Squash bullets, commit bodies, and PR descriptions can identify an immediate port source, while identifier-adjacent developer credit can identify an unpublished project continuation. A later intermediate source cannot displace an earlier authored, submitted, or explicitly credited origin.
5. After origin is established, a separate TaystJK first-parent patch scan records exact registration changes, changed bound cvar-variable references, and edits within registered command-handler hunks. Each change is dated and attributed from explicit commit/PR credit or project-mainline membership; shared change commits remain medium-confidence.
6. Semantics come from source descriptions, `ui_xdocs.h`, jaPRO's checked-in documentation, handler/read sites, masks, comparisons, and range checks. The generator separately records exact xdocs declarations and appearances in shipped `.menu` files.
7. Stable topic rules classify broad areas, while curated feature-family rules keep related controls such as `cg_killfeed…` together. Unproven semantic fields stay in the review queue.
8. The dedicated runtime registry is reconciled separately. One runtime cannot contain client, UI, every platform, and all renderers, so the published inventory is the static union.

NewMod is closed source. Its [published feature documentation](https://jkanewmod.github.io/documentation.html) is useful semantic context, but the resolver attributes NewMod/NewJK only where a commit, PR, or nearby source comment explicitly says so, or where the open NewJK tree supplies direct evidence. A feature-page resemblance alone is not treated as origin proof.

Bucky's later EternalJK continuation was also shared privately. Explicit `Bucky` or `Bucky21659` credit next to an identifier is therefore treated as EternalJK lineage even when the historical label says `jaPRO/Bucky`. The public-introduction table still shows where that code first became available in a published repository; it does not invent an EternalJK commit for unpublished source.

Contributor identity is not treated as permanent project identity. `cg_chatBoxEmojis` is a curated historical exception: Sunny contributed the feature to EternalJK before starting work on Vulkan, so the JKSunny branch name identifies the contributor there rather than Vulkan lineage.

## Confidence

- **High:** initial-import match, a unique earliest authored/submitted project introduction, explicit identifier/feature-group credit consistent with chronology, or curated maintainer-supplied historical attribution.
- **Medium:** shared-commit lineage (a Git object has no repository-of-origin field), tied author/PR/integration dates, or exact upstream-head presence when registration-file history cannot be followed.
- **Low:** no reliable attribution; these remain `unknown`.

The [audit report](/TaystJK/reference/audit/) lists every medium/low attribution, incomplete semantic entry, and ambiguous registration-signature change.
"""


def removed_page(items: list[dict[str, Any]], source_sha: str) -> str:
    lines = [frontmatter("Removed and inactive", 6, "Console reference",
        description="Names the client no longer registers, kept so an old config or guide referring to one can be understood."), "# Removed and inactive names", "",
             "These identifiers are not part of the active static inventory, but remain useful search targets. `inactive` means the apparent registration is commented/disabled in the current tree; `renamed` identifies a verified replacement.", "",
             "| Name | Kind | Status | Replacement | Reason | Evidence |", "|:--|:--|:--|:--|:--|:--|"]
    for item in items:
        evidence = item["evidence"]
        evidence["url"] = source_url(evidence["path"], evidence["line"], source_sha)
        replacement = code(item["replacement"]) if item.get("replacement") else "—"
        lines.append(f"| {code(item['name'])} | {item['kind']} | {item['status']} | {replacement} | {item['summary']} | {evidence_link(evidence)} |")
    lines.extend(["", "This list covers inactive registration candidates found by the current-tree audit plus verified renames. Fully deleted historical names require an additional all-revision extraction and remain a future audit item."])
    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cvars", default="_data/cvars.json", type=Path)
    parser.add_argument("--commands", default="_data/commands.json", type=Path)
    parser.add_argument("--runtime", default=".cvar-audit/runtime-report.json", type=Path)
    args = parser.parse_args()
    cvars = load(args.cvars)
    commands = load(args.commands)
    entries = cvars + commands
    # A staging copy links to the setting it stands in for, under the reference's
    # own spelling; a target the source writes but never registers has no page.
    cvar_names = {entry["name"].casefold(): entry["name"] for entry in cvars}
    refs = load(Path("_data/reference-meta.json"))["upstream_commits"]

    write(Path("index.md"), home_page(cvars, commands))
    emoji, emoji_warnings = emoji_page(cvars[0]["source_commit"])
    write(Path("features/emoji.md"), emoji)
    for warning in emoji_warnings:
        print(f"warning: {warning}")
    whats_new, hidden_from_whats_new, whats_new_warnings = whats_new_page(cvars + commands)
    write(Path("features/whats-new.md"), whats_new)
    for warning in whats_new_warnings:
        print(f"warning: {warning}")
    write(Path("reference.md"), frontmatter(
        "Console reference",
        6,
        wide=True,
        reference_app=True,
        description="Search and filter every cvar and console command available in TaystJK.",
    ) + f"""
<div class="page-heading" markdown="1">
<p class="eyebrow">Complete source-derived inventory</p>

<h1>Console reference</h1>

<p class="page-lede">Search {len(cvars) + len(commands):,} cvars and commands across the client, dedicated server, game, cgame, UI, platform code, and every renderer backend.</p>

{generated_from(cvars[0]["source_commit"])}
</div>

{catalog_app("all", multi_select=True)}

## How to read an entry

The **topic** is a broad area such as HUD & interface or Movement & race. A **feature** is a narrower family of related controls, such as Killfeed, Movement keys, or Speedometer. The **origin** badge identifies where an entry first appeared, not merely every fork that ships it. Later changes to defaults or flags are listed separately. **Renderer scope** says which current backend registers a cvar, while **network scope** distinguishes local controls from server-owned or negotiated behavior.

The **xdocs** and **menu** badges show whether the current name already has an entry in TaystJK's in-game documentation or shipped menu definitions. Each detail page links the matching source line.

An entry marked **needs review** is real and has registration evidence, but one or more behavior, option, or attribution fields could not be proven precisely enough to present as settled fact.

### More ways to browse

- [Browse by origin](/TaystJK/reference/origins/)
- [Browse by module](/TaystJK/reference/modules/)
- [Browse by topic](/TaystJK/reference/categories/)
- [Browse by feature](/TaystJK/reference/features/)
- [Read the sources and methodology](/TaystJK/reference/sources/)
- [See removed and inactive names](/TaystJK/reference/removed/)
- [Open the audit and review queue](/TaystJK/reference/audit/)
- [Use the static A–Z index](/TaystJK/reference/all/) without JavaScript
- Download the machine-readable [catalog JSON](/TaystJK/assets/data/catalog.json), [full cvars JSON](/TaystJK/assets/data/cvars.json), [full commands JSON](/TaystJK/assets/data/commands.json), [metadata](/TaystJK/assets/data/reference-meta.json), or [JSON Schema](/TaystJK/assets/data/schema.json)
""")
    for entry in entries:
        write(Path("reference") / f"{entry['kind']}s" / f"{slug(entry['name'])}.md", detail_page(entry, refs, cvar_names))
    write(Path("reference/all.md"), static_index_page(cvars, commands))

    origin_cards = []
    for source in ORIGIN_ORDER:
        count = sum(entry["origin"]["source"] == source for entry in entries)
        if count:
            origin_cards.append(
                f'<a class="directory-card" href="/TaystJK/reference/origins/{source}/">'
                f'{badge(source)}<strong>{ORIGIN_LABELS[source]}</strong><span>{count:,} entries</span></a>'
            )
    write(Path("reference/origins.md"), frontmatter("By origin", 3, "Console reference", wide=True,
        description="Every cvar and command grouped by the project it first appeared in, from base Jedi Academy through to TaystJK.") + """
<div class="page-heading" markdown="1">
<p class="eyebrow">Provenance</p>

<h1>Browse by origin</h1>

<p class="page-lede">Origin means the earliest source supported by the inspected code, Git history, pull requests, and upstream snapshots—not simply every project that now contains the name.</p>
</div>

<div class="directory-grid">
""" + "\n".join(origin_cards) + "\n</div>")
    for order, source in enumerate(ORIGIN_ORDER, 1):
        selected = [entry for entry in entries if entry["origin"]["source"] == source]
        if selected:
            intro = "Entries whose evidence identifies this project as the original source. Later consumers do not change the origin badge."
            if source == "taystjk":
                intro = "Entries first found in TaystJK after all configured upstream snapshots and explicit port credits were checked. Medium-confidence entries remain in the audit queue."
            write(Path("reference/origins") / f"{source}.md", collection_page(
                ORIGIN_LABELS[source], intro, selected, order, "By origin",
                preset_key="origin", preset_value=source,
            ))

    modules = sorted({entry["module"] for entry in entries})
    module_cards = []
    for module in modules:
        count = sum(entry["module"] == module for entry in entries)
        module_cards.append(
            f'<a class="directory-card" href="/TaystJK/reference/modules/{module}/">'
            f'<span class="directory-code">{esc(module)}</span><strong>{count:,}</strong><span>entries</span></a>'
        )
    write(Path("reference/modules.md"), frontmatter("By module", 4, "Console reference", wide=True,
        description="Every cvar and command grouped by the module that registers it: engine, renderer, game, cgame or UI.") + """
<div class="page-heading" markdown="1">
<p class="eyebrow">Registration context</p>

<h1>Browse by module</h1>

<p class="page-lede">Find controls registered by the engine, game, cgame, UI, or renderer portions of the current TaystJK tree.</p>
</div>

<div class="directory-grid">
""" + "\n".join(module_cards) + "\n</div>")
    for order, module in enumerate(modules, 1):
        selected = [entry for entry in entries if entry["module"] == module]
        write(Path("reference/modules") / f"{module}.md", collection_page(
            module, "Entries whose primary registration or dispatch context is this module.", selected, order, "By module",
            preset_key="module", preset_value=module,
        ))

    categories = sorted({entry["category"] for entry in entries})
    category_cards = []
    for category in categories:
        selected = [entry for entry in entries if entry["category"] == category]
        cvar_count = sum(entry["kind"] == "cvar" for entry in selected)
        command_count = len(selected) - cvar_count
        category_cards.append(
            f'<a class="directory-card" href="/TaystJK/reference/categories/{collection_slug(category)}/">'
            f'<span class="directory-code">{esc(category)}</span><strong>{len(selected):,}</strong>'
            f'<span>{cvar_count:,} cvars · {command_count:,} commands</span></a>'
        )
    write(Path("reference/categories.md"), frontmatter("By topic", 5, "Console reference", wide=True,
        description="Every cvar and command grouped by subject, from audio and HUD through to movement and networking.") + """
<div class="page-heading" markdown="1">
<p class="eyebrow">Broad areas</p>

<h1>Browse by topic</h1>

<p class="page-lede">Browse the complete reference by broad functional area. Narrow control families such as Killfeed and Speedometer are listed separately as features.</p>
</div>

<div class="directory-grid">
""" + "\n".join(category_cards) + "\n</div>")
    for order, category in enumerate(categories, 1):
        selected = [entry for entry in entries if entry["category"] == category]
        write(Path("reference/categories") / f"{collection_slug(category)}.md", collection_page(
            category, "Entries in this broad functional area.", selected, order, "By topic",
            preset_key="category", preset_value=category,
        ))

    features = sorted({entry["feature"] for entry in entries if entry.get("feature")})
    feature_cards = []
    for feature in features:
        selected = [entry for entry in entries if entry.get("feature") == feature]
        cvar_count = sum(entry["kind"] == "cvar" for entry in selected)
        command_count = len(selected) - cvar_count
        topics = sorted({entry["category"] for entry in selected})
        cvar_label = "cvar" if cvar_count == 1 else "cvars"
        command_label = "command" if command_count == 1 else "commands"
        feature_cards.append(
            f'<a class="directory-card" href="/TaystJK/reference/features/{collection_slug(feature)}/">'
            f'<span class="directory-code">{esc(feature)}</span><strong>{len(selected):,}</strong>'
            f'<span>{cvar_count:,} {cvar_label} · {command_count:,} {command_label} · {esc(" / ".join(topics))}</span></a>'
        )
    write(Path("reference/features.md"), frontmatter("By feature", 6, "Console reference", wide=True,
        description="Every cvar and command grouped by the feature it belongs to, for when you know the feature but not the name.") + """
<div class="page-heading" markdown="1">
<p class="eyebrow">Control families</p>

<h1>Browse by feature</h1>

<p class="page-lede">Find cvars and commands that configure the same feature. Families are curated from shared prefixes and behavior rather than inferred from every coincidental name match.</p>
</div>

<div class="directory-grid">
""" + "\n".join(feature_cards) + "\n</div>")
    for order, feature in enumerate(features, 1):
        selected = [entry for entry in entries if entry.get("feature") == feature]
        write(Path("reference/features") / f"{collection_slug(feature)}.md", collection_page(
            feature, "Related controls for this configurable feature.", selected, order, "By feature",
            preset_key="feature", preset_value=feature,
        ))

    runtime = load(args.runtime) if args.runtime.exists() else None
    write(Path("reference/audit.md"), audit_page(entries, runtime, hidden_from_whats_new))
    write(Path("reference/sources.md"), sources_page(refs))
    removed_path = Path("tools/cvar_audit/removed.json")
    write(Path("reference/removed.md"), removed_page(load(removed_path), cvars[0]["source_commit"]))
    Path("assets/data").mkdir(parents=True, exist_ok=True)
    write(Path("assets/data/cvars.json"), json.dumps(cvars, separators=(",", ":")))
    write(Path("assets/data/commands.json"), json.dumps(commands, separators=(",", ":")))
    write(Path("assets/data/reference-meta.json"), json.dumps(load(Path("_data/reference-meta.json")), separators=(",", ":")))
    write(Path("assets/data/schema.json"), json.dumps(load(Path("tools/cvar_audit/schema.json")), separators=(",", ":")))
    write(Path("assets/data/catalog.json"), json.dumps([compact_catalog_entry(entry) for entry in entries], separators=(",", ":")))
    print(f"generated {len(entries)} detail entries and collection pages")


if __name__ == "__main__":
    main()
