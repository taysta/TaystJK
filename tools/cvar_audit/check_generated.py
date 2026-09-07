#!/usr/bin/env python3
"""Validate generated Pages, public data copies, and internal reference links."""

from __future__ import annotations

import json
import re
from pathlib import Path

from generate_docs import compact_catalog_entry, slug


ROOT = Path(".")
LINK = re.compile(r"(?:\]\(|href=[\"'])(/TaystJK/[^)\"'#?]*)")


def resolve_url(url: str) -> Path | None:
    relative = url.removeprefix("/TaystJK/")
    if not relative:
        return ROOT / "index.md"
    if any(part.startswith(("_", ".")) for part in Path(relative).parts):
        return None
    direct = ROOT / relative
    if direct.is_file():
        return direct
    if url.endswith("/"):
        page = ROOT / f"{relative.rstrip('/')}.md"
        if page.is_file():
            return page
        index = ROOT / relative / "index.md"
        if index.is_file():
            return index
    return None


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
    expected_collections = {
        Path("reference/origins") / f"{source}.md"
        for source in {entry["origin"]["source"] for entry in all_entries}
    }
    expected_collections |= {
        Path("reference/modules") / f"{module}.md"
        for module in {entry["module"] for entry in all_entries}
    }
    expected_collections |= {
        Path("reference/renderers") / f"{renderer}.md"
        for renderer in {renderer for entry in datasets["cvar"] for renderer in entry.get("renderer", [])}
    }
    actual_collections = {
        path
        for directory in (Path("reference/origins"), Path("reference/modules"), Path("reference/renderers"))
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

    pages = [Path("index.md"), Path("reference.md"), Path("cvars.md"), Path("commands.md"), *Path("reference").rglob("*.md")]
    for page in pages:
        text = page.read_text()
        if not text.startswith("---\n") or "\n---\n" not in text[4:]:
            errors.append(f"invalid or missing front matter: {page}")
        for match in LINK.finditer(text):
            url = match.group(1)
            if resolve_url(url) is None:
                errors.append(f"broken internal link in {page}: {url}")

    if errors:
        raise SystemExit("\n".join(errors))
    print(f"generated site is internally consistent ({sum(map(len, datasets.values()))} detail pages)")


if __name__ == "__main__":
    main()
