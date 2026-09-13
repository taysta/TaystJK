#!/usr/bin/env python3
"""Check that Liquid block tags balance in the templates this site hand-writes.

There is no local Jekyll, so the real build is the first place a template error would
surface -- and it surfaces as a failed deploy, not a failed test. This catches the class
of mistake that actually happens when editing these files by hand: an unclosed for, if or
comment. It does not evaluate Liquid, so it proves nothing about the output.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

PAIRED = {
    "for": "endfor",
    "if": "endif",
    "unless": "endunless",
    "case": "endcase",
    "comment": "endcomment",
    "raw": "endraw",
    "capture": "endcapture",
    "tablerow": "endtablerow",
}
CLOSERS = {v: k for k, v in PAIRED.items()}
# Tags that live inside a block rather than opening one.
INNER = {"else", "elsif", "when", "break", "continue", "increment", "decrement"}

TAG = re.compile(r"\{%-?\s*(\w+)")


def check(path):
    text = path.read_text(encoding="utf-8")
    stack = []
    errors = []

    for match in TAG.finditer(text):
        name = match.group(1)
        line = text.count("\n", 0, match.start()) + 1

        if name in PAIRED:
            stack.append((name, line))
        elif name in CLOSERS:
            expected = CLOSERS[name]
            if not stack:
                errors.append(f"{path.relative_to(ROOT)}:{line}: {{% {name} %}} with nothing open")
            elif stack[-1][0] != expected:
                opened, opened_line = stack[-1]
                errors.append(
                    f"{path.relative_to(ROOT)}:{line}: {{% {name} %}} closes {{% {opened} %}} "
                    f"opened at line {opened_line}"
                )
                stack.pop()
            else:
                stack.pop()
        elif name in INNER and not stack:
            errors.append(f"{path.relative_to(ROOT)}:{line}: {{% {name} %}} outside any block")

    for name, line in stack:
        errors.append(f"{path.relative_to(ROOT)}:{line}: {{% {name} %}} is never closed")

    return errors


def main():
    targets = sorted(ROOT.glob("_layouts/*.html"))
    index = ROOT / "search-index.json"
    if index.exists():
        targets.append(index)

    if not targets:
        print("no templates found", file=sys.stderr)
        return 1

    errors = []
    for path in targets:
        errors.extend(check(path))

    if errors:
        for error in errors:
            print(error, file=sys.stderr)
        return 1

    print(f"liquid blocks balance in {len(targets)} templates")
    return 0


if __name__ == "__main__":
    sys.exit(main())
