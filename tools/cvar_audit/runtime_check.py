#!/usr/bin/env python3
"""Compare dedicated/client cvarlist and cmdlist output with static data."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path
from typing import Any


def parse_section(path: Path, total_label: str) -> list[str]:
    lines = path.read_text(errors="replace").splitlines()
    ends = [index for index, line in enumerate(lines) if total_label in line]
    if not ends:
        raise ValueError(f"{path} has no '{total_label}' footer")
    end = ends[-1]
    starts = [
        index + 1 for index, line in enumerate(lines[:end])
        if "Cleaned up racetimes" in line or "Common Initialization Complete" in line
    ]
    return lines[(starts[-1] if starts else 0):end]


def parse_cvars(path: Path) -> dict[str, str]:
    names: dict[str, str] = {}
    for line in parse_section(path, "total cvars"):
        match = re.search(r"\^7\s+([^\s=]+)\s+=", line)
        if match:
            names[match.group(1).casefold()] = match.group(1)
    return names


def parse_commands(path: Path) -> dict[str, str]:
    names: dict[str, str] = {}
    for line in parse_section(path, "total commands"):
        match = re.match(r"\s*([^\s^]+)(?:\^2|\s*$)", line)
        if match:
            names[match.group(1).casefold()] = match.group(1)
    return names


def static_names(path: Path) -> dict[str, str]:
    return {entry["name"].casefold(): entry["name"] for entry in json.loads(path.read_text())}


def comparison(runtime: dict[str, str], static: dict[str, str]) -> dict[str, Any]:
    runtime_keys, static_keys = set(runtime), set(static)
    return {
        "runtime_count": len(runtime),
        "static_union_count": len(static),
        "runtime_only": [runtime[key] for key in sorted(runtime_keys - static_keys)],
        "static_not_in_runtime_target": [static[key] for key in sorted(static_keys - runtime_keys)],
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cvars", required=True, type=Path)
    parser.add_argument("--commands", required=True, type=Path)
    parser.add_argument("--static-cvars", default="_data/cvars.json", type=Path)
    parser.add_argument("--static-commands", default="_data/commands.json", type=Path)
    parser.add_argument("--output", default=".cvar-audit/runtime-report.json", type=Path)
    parser.add_argument("--target", default="dedicated-server")
    parser.add_argument("--build", default="unknown")
    args = parser.parse_args()

    report = {
        "target": args.target,
        "build": args.build,
        "notes": (
            "The static inventory is a union of client, dedicated server, game, cgame, UI, "
            "platform-conditional, and renderer registrations. Static-only entries are therefore "
            "expected for a single runtime target."
        ),
        "cvars": comparison(parse_cvars(args.cvars), static_names(args.static_cvars)),
        "commands": comparison(parse_commands(args.commands), static_names(args.static_commands)),
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n")
    print(json.dumps({
        "cvars": {key: value for key, value in report["cvars"].items() if key != "static_not_in_runtime_target"},
        "commands": {key: value for key, value in report["commands"].items() if key != "static_not_in_runtime_target"},
    }, indent=2))


if __name__ == "__main__":
    main()
