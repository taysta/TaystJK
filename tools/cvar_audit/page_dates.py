#!/usr/bin/env python3
"""Record when each page was last changed, from git.

GitHub Pages cannot run a plugin, so the date has to be worked out here and committed.
It is the author date of the most recent commit touching the file.

The limitation worth knowing: a page edited after this last ran shows the previous date
until it is run again. That is a lag of one commit, which does not change whether a reader
can trust the page's age. The "History" link beside the date is always exact, so precision
is available where it matters.

    python3 tools/cvar_audit/page_dates.py
"""

from __future__ import annotations

import json
import subprocess
import sys
from pathlib import Path

OUTPUT = Path("_data/page_updated.json")
SKIP_DIRS = {"tools"}
SKIP_NAMES = {"CLAUDE.md", "CONVENTIONS.md", "README.md"}


def git(*args: str) -> str:
    return subprocess.run(["git", *args], capture_output=True, text=True, check=True).stdout.strip()


def tracked_pages() -> list[Path]:
    pages = []
    for name in git("ls-files", "*.md").split("\n"):
        if not name:
            continue
        path = Path(name)
        if path.parts[0].startswith(".") or path.parts[0] in SKIP_DIRS:
            continue
        if path.name in SKIP_NAMES:
            continue
        # The generated entry pages carry the reference's own source commit instead.
        if path.parts[:2] in (("reference", "cvars"), ("reference", "commands")):
            continue
        pages.append(path)
    return sorted(pages)


def main() -> int:
    dates = {}
    for path in tracked_pages():
        stamp = git("log", "-1", "--format=%as", "--", str(path))
        if stamp:
            dates[path.as_posix()] = stamp

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(dates, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(f"recorded last-changed dates for {len(dates)} pages")
    return 0


if __name__ == "__main__":
    sys.exit(main())
