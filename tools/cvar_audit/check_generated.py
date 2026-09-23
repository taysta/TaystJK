#!/usr/bin/env python3
"""Validate generated Pages, public data copies, and internal reference links."""

from __future__ import annotations

import json
import re
import subprocess
from pathlib import Path

from generate_docs import collection_slug, compact_catalog_entry, home_page, reference_stats, resolve_url, slug


ROOT = Path(".")
LINK = re.compile(r"(?:\]\(|href=[\"'])(/TaystJK/[^)\"'#?]*)")
STATS_KEY = re.compile(r"site\.data\.reference_stats((?:\.\w+)+)")


FRAGMENT_LINK = re.compile(r"(?:\]\(|href=[\"'])(/TaystJK/[^)\"'#?]*)?(?:\?[^)\"'#]*)?#([^)\"'\s]+)")
FENCE = re.compile(r"^(```|~~~).*?^\1", re.M | re.S)
ATX_HEADING = re.compile(r"^#{1,6}[ \t]+(.+?)[ \t]*#*[ \t]*$", re.M)
EXPLICIT_ID = re.compile(r"""\bid=["']([^"'{}]+)["']|\{:?\s*#([\w-]+)\s*\}""")
NON_WORD = re.compile(r"[^\w\- \t]")


def page_anchor_ids(text: str) -> set:
    """The ids kramdown gives a page's headings, plus any written out by hand.

    Jekyll parses Markdown as GFM, which derives an id from the heading's raw source: lower
    case, everything but word characters, hyphens and spaces dropped, spaces turned into
    hyphens, and a repeat numbered -1, -2 and so on. Headings inside code fences are not
    headings, so fences are removed first.
    """
    body = FENCE.sub("", text)
    ids = set()
    seen = {}
    for match in ATX_HEADING.finditer(body):
        raw = match.group(1)
        explicit = re.search(r"\{:?\s*#([\w-]+)\s*\}\s*$", raw)
        if explicit:
            ids.add(explicit.group(1))
            continue
        base = NON_WORD.sub("", raw.lower()).replace(" ", "-").replace("\t", "-")
        count = seen.get(base, -1) + 1
        seen[base] = count
        ids.add(base if count == 0 else f"{base}-{count}")
    for match in EXPLICIT_ID.finditer(text):
        ids.add(match.group(1) or match.group(2))
    return ids


def fragment_errors(page: Path, text: str, anchors: dict) -> list:
    """A link to a heading that does not exist lands at the top of the page, silently."""
    errors = []
    for match in FRAGMENT_LINK.finditer(FENCE.sub("", text)):
        url, fragment = match.group(1), match.group(2)
        target = resolve_url(url) if url else page
        if target is None or target.suffix != ".md":
            continue
        if target not in anchors:
            anchors[target] = page_anchor_ids(target.read_text())
        if fragment not in anchors[target]:
            errors.append(f"broken anchor in {page}: {url or ''}#{fragment}")
    return errors


def stats_errors(page: Path, text: str, stats: dict) -> list:
    """A misspelt key renders as nothing, so check every figure a page quotes exists."""
    errors = []
    for match in STATS_KEY.finditer(text):
        value = stats
        for key in match.group(1).strip(".").split("."):
            value = value.get(key) if isinstance(value, dict) else None
        if value is None:
            errors.append(f"unknown reference_stats key in {page}: {match.group(0)}")
    return errors


def stats_claim_errors(stats: dict) -> list:
    """Prose around the generated figures that the figures themselves can falsify."""
    ranked = [origin["id"] for origin in stats.get("origins", [])]
    if ranked[:2] != ["basejka", "japro"]:
        return [
            "index.md and overview.md call jaPRO the largest source after the base game, "
            f"but the origins now rank {ranked[:3]}"
        ]
    return []


def missing_description_errors() -> list:
    """Every published page needs a description.

    It is the only summary the listing cards and the meta tags have, and it is what a
    search result shows under the title. A page without one renders a blank card and
    falls back to the site-wide description everywhere else.

    Tracked files only. An untracked local build tree is not part of the site. Redirect
    stubs are exempt: they carry `layout: none` and are never indexed.
    """
    tracked = subprocess.run(
        ["git", "ls-files", "*.md"], capture_output=True, text=True, check=True
    ).stdout.split()

    skip_dirs = {"tools"}
    skip_names = {"AGENTS.md", "CLAUDE.md", "CONVENTIONS.md", "README.md"}
    errors = []

    for name in sorted(tracked):
        path = Path(name)
        if path.parts[0].startswith(".") or path.parts[0] in skip_dirs:
            continue
        if path.name in skip_names:
            continue
        # Generated entry pages are nav-excluded details, not listed anywhere.
        if path.parts[:2] in (("reference", "cvars"), ("reference", "commands")):
            continue

        text = path.read_text(encoding="utf-8", errors="ignore")
        if not text.startswith("---"):
            continue
        front = text.split("---", 2)[1]
        if re.search(r"^layout:\s*none\s*$", front, re.M):
            continue
        if not re.search(r"^description:", front, re.M):
            errors.append(f"page has no description front matter: {path}")

    return errors


def tab_panel_errors(page, text) -> list:
    """Tab panels must close at column 0 when their content ends with a list.

    Kramdown reads an indented line following a list as continuation content of the final
    item, so an indented "</section>" does not close the panel -- the next panel is parsed
    inside it instead. Every panel after the first then sits inside a hidden one, and the
    toggle appears to do nothing. Panels ending in a paragraph are unaffected, which is why
    this only became visible on the generated what's-new page.
    """
    errors = []
    lines = text.split("\n")
    open_panel = None
    previous = ""

    for number, line in enumerate(lines, start=1):
        if "data-baseline-panel=" in line or "data-platform-panel=" in line:
            open_panel = number
        elif line.strip() == "</section>" and open_panel is not None:
            if line.startswith((" ", "\t")) and previous.lstrip().startswith("- "):
                errors.append(
                    f"{page}:{number}: panel opened at line {open_panel} closes with an "
                    f"indented </section> after a list; kramdown will nest the next panel "
                    f"inside it. Put the close tag at column 0."
                )
            open_panel = None
        if line.strip():
            previous = line

    return errors


def main() -> None:
    errors: list[str] = []
    datasets = {
        "cvar": json.loads(Path("_data/cvars.json").read_text()),
        "command": json.loads(Path("_data/commands.json").read_text()),
    }
    for kind, entries in datasets.items():
        directory = Path("reference") / f"{kind}s"
        expected = {directory / f"{slug(entry['name'])}.md" for entry in entries}
        actual = set(directory.glob("*.md"))
        for path in sorted(expected - actual):
            errors.append(f"missing generated detail page: {path}")
        for path in sorted(actual - expected):
            errors.append(f"stale generated detail page: {path}")

    all_entries = datasets["cvar"] + datasets["command"]
    expected_home = home_page(datasets["cvar"], datasets["command"]).rstrip() + "\n"
    if Path("index.md").read_text() != expected_home:
        errors.append("index.md differs from the generated homepage")

    expected_collections = {
        Path("reference/origins") / f"{source}.md"
        for source in {entry["origin"]["source"] for entry in all_entries}
    }
    expected_collections |= {
        Path("reference/modules") / f"{module}.md"
        for module in {entry["module"] for entry in all_entries}
    }
    expected_collections |= {
        Path("reference/categories") / f"{collection_slug(category)}.md"
        for category in {entry["category"] for entry in all_entries}
    }
    expected_collections |= {
        Path("reference/features") / f"{collection_slug(feature)}.md"
        for feature in {entry.get("feature") for entry in all_entries if entry.get("feature")}
    }
    actual_collections = {
        path
        for directory in (Path("reference/origins"), Path("reference/modules"), Path("reference/categories"), Path("reference/features"))
        for path in directory.glob("*.md")
    }
    for path in sorted(expected_collections - actual_collections):
        errors.append(f"missing generated collection page: {path}")
    for path in sorted(actual_collections - expected_collections):
        errors.append(f"stale generated collection page: {path}")

    if json.loads(Path("assets/data/cvars.json").read_text()) != datasets["cvar"]:
        errors.append("assets/data/cvars.json differs from _data/cvars.json")
    if json.loads(Path("assets/data/commands.json").read_text()) != datasets["command"]:
        errors.append("assets/data/commands.json differs from _data/commands.json")
    catalog = json.loads(Path("assets/data/catalog.json").read_text())
    expected_catalog = [compact_catalog_entry(entry) for entry in datasets["cvar"] + datasets["command"]]
    if catalog != expected_catalog:
        errors.append("assets/data/catalog.json differs from the compact reference records")
    stats_path = Path("_data/reference_stats.json")
    stats = json.loads(stats_path.read_text()) if stats_path.exists() else {}
    if stats != reference_stats(datasets["cvar"], datasets["command"]):
        errors.append("_data/reference_stats.json differs from the reference records")
    errors.extend(stats_claim_errors(stats))

    retired_pages = [Path("cvars.md"), Path("commands.md"), Path("reference/renderers.md"), *Path("reference/renderers").glob("*.md")]
    for page in retired_pages:
        if page.exists():
            errors.append(f"retired standalone catalog page still exists: {page}")

    pages = [
        Path("index.md"), Path("install.md"), *Path("install").rglob("*.md"),
        Path("server-hosting.md"),
        Path("development.md"), *Path("development").rglob("*.md"),
        Path("reference.md"), *Path("reference").rglob("*.md"),
        Path("features.md"), *Path("features").rglob("*.md"),
        Path("overview.md"), Path("glossary.md"),
        Path("troubleshooting.md"), Path("where-to-report.md"),
        Path("devlog.md"), Path("licensing.md"),
        Path("help.md"), Path("ai-disclosure.md"), Path("404.md"),
        *Path("_devlog").glob("*.md"),
    ]
    anchors = {}
    for page in pages:
        text = page.read_text()
        if not text.startswith("---\n") or "\n---\n" not in text[4:]:
            errors.append(f"invalid or missing front matter: {page}")
        for match in LINK.finditer(text):
            url = match.group(1)
            if resolve_url(url) is None:
                errors.append(f"broken internal link in {page}: {url}")
        errors.extend(tab_panel_errors(page, text))
        errors.extend(fragment_errors(page, text, anchors))
        errors.extend(stats_errors(page, text, stats))

    errors.extend(missing_description_errors())

    if errors:
        raise SystemExit("\n".join(errors))
    print(f"generated site is internally consistent ({sum(map(len, datasets.values()))} detail pages)")


if __name__ == "__main__":
    main()
