#!/usr/bin/env python3
"""Fail when source registrations and checked-in reference data diverge."""

from __future__ import annotations

import argparse
import json
from pathlib import Path

from extract import extract_commands, extract_cvars, source_files


def names(records: list[object]) -> set[str]:
    result: set[str] = set()
    for record in records:
        name = record.name if hasattr(record, "name") else record["name"]  # type: ignore[index]
        result.add(name.casefold())
    return result


def check(kind: str, extracted: set[str], documented: set[str]) -> list[str]:
    errors: list[str] = []
    missing = sorted(extracted - documented)
    stale = sorted(documented - extracted)
    if missing:
        errors.append(f"{kind} missing from data: {', '.join(missing)}")
    if stale:
        errors.append(f"{kind} no longer registered: {', '.join(stale)}")
    return errors


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--ref", default="origin/master")
    parser.add_argument("--cvars", default="_data/cvars.json", type=Path)
    parser.add_argument("--commands", default="_data/commands.json", type=Path)
    args = parser.parse_args()
    files = list(source_files(args.ref, ".", None))
    errors = check("cvars", names(extract_cvars(files)), names(json.loads(args.cvars.read_text())))
    errors += check("commands", names(extract_commands(files)), names(json.loads(args.commands.read_text())))
    if errors:
        raise SystemExit("\n".join(errors))
    print("reference data matches source registrations")


if __name__ == "__main__":
    main()
