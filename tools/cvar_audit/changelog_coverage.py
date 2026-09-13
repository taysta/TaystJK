#!/usr/bin/env python3
"""Report which reference entries the hand-written CHANGELOG still misses.

`CHANGELOG.md` lives on the source branch and is maintained by hand, so it falls
behind the cvars and commands the fork actually adds.  This measures the gap per
origin bucket and ratchets it, so it can shrink but not grow.

The source branch is read through `git show`; nothing here writes to it.

Names are matched as whole words, case-insensitively.  That distinction matters:
`cg_killfeed` must not be counted as covered because `cg_killfeedX` happens to
appear, so the boundary check rejects a neighbouring word character on either
side.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path
from typing import Any

RATCHET = Path("tools/cvar_audit/changelog-coverage-ratchet.json")


def changelog_text(ref: str, path: str) -> str:
    result = subprocess.run(
        ["git", "show", f"{ref}:{path}"], check=False, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    if result.returncode:
        raise SystemExit(f"cannot read {path} from {ref}: {result.stderr.strip()}")
    return result.stdout


def mentions(text: str, name: str) -> bool:
    """True when `name` appears as a whole word.

    A cvar name contains underscores, which are word characters, so a longer
    name never satisfies the boundary for a shorter one it contains.
    """
    pattern = re.compile(
        r"(?<![0-9A-Za-z_])" + re.escape(name) + r"(?![0-9A-Za-z_])", re.IGNORECASE
    )
    return bool(pattern.search(text))


def coverage(entries: list[dict[str, Any]], text: str) -> dict[str, dict[str, Any]]:
    buckets: dict[str, dict[str, list[str]]] = defaultdict(lambda: {"present": [], "absent": []})
    for entry in entries:
        source = (entry.get("origin") or {}).get("source") or "unknown"
        key = "present" if mentions(text, entry["name"]) else "absent"
        buckets[source][key].append(entry["name"])
    return {
        source: {
            "total": len(value["present"]) + len(value["absent"]),
            "present": sorted(value["present"]),
            "absent": sorted(value["absent"]),
        }
        for source, value in sorted(buckets.items())
    }


def render(report: dict[str, dict[str, Any]]) -> str:
    lines = ["Changelog coverage by origin", ""]
    lines.append(f"{'origin':12s} {'entries':>8s} {'covered':>8s} {'missing':>8s}")
    for source, value in report.items():
        lines.append(
            f"{source:12s} {value['total']:8d} {len(value['present']):8d} {len(value['absent']):8d}"
        )
    total = sum(value["total"] for value in report.values())
    missing = sum(len(value["absent"]) for value in report.values())
    lines.extend(["", f"{total} entries, {total - missing} covered, {missing} missing"])
    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--ref", default="origin/master", help="branch holding CHANGELOG.md")
    parser.add_argument("--changelog", default="CHANGELOG.md")
    parser.add_argument("--cvars", default="_data/cvars.json", type=Path)
    parser.add_argument("--commands", default="_data/commands.json", type=Path)
    parser.add_argument("--json", type=Path, help="write the machine-readable report here")
    parser.add_argument("--ratchet", default=RATCHET, type=Path)
    parser.add_argument(
        "--update-ratchet", action="store_true",
        help="record the current gaps as the new ceiling, after they legitimately shrank",
    )
    args = parser.parse_args()

    entries = json.loads(args.cvars.read_text()) + json.loads(args.commands.read_text())
    report = coverage(entries, changelog_text(args.ref, args.changelog))
    print(render(report))

    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n")

    if not args.ratchet.exists():
        raise SystemExit(f"\nmissing ratchet file {args.ratchet}")
    ratchet = json.loads(args.ratchet.read_text())
    ceilings: dict[str, int] = ratchet.get("buckets", {})
    actual = {source: len(value["absent"]) for source, value in report.items()}

    if args.update_ratchet:
        ratchet["buckets"] = {source: actual.get(source, 0) for source in ceilings}
        args.ratchet.write_text(json.dumps(ratchet, indent=2, sort_keys=True) + "\n")
        print(f"\nratchet updated: {ratchet['buckets']}")
        return

    failures = [
        f"  {source}: {actual.get(source, 0)} missing, ceiling is {ceiling}"
        for source, ceiling in sorted(ceilings.items())
        if actual.get(source, 0) > ceiling
    ]
    if failures:
        print("\nchangelog coverage got worse:", file=sys.stderr)
        print("\n".join(failures), file=sys.stderr)
        raise SystemExit(
            "\nDocument the new entries in CHANGELOG.md on the source branch, or, if the "
            "increase is expected, rerun with --update-ratchet and commit the result."
        )
    shrunk = [
        f"  {source}: {actual.get(source, 0)} missing, ceiling is {ceiling}"
        for source, ceiling in sorted(ceilings.items())
        if actual.get(source, 0) < ceiling
    ]
    if shrunk:
        print("\nthe gap shrank; rerun with --update-ratchet to lock it in:")
        print("\n".join(shrunk))
    print("\nchangelog coverage is within its ratchet")


if __name__ == "__main__":
    main()
