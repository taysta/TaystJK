#!/usr/bin/env python3
"""Validate checked-in reference data without third-party dependencies."""

from __future__ import annotations

import json
from pathlib import Path


ORIGINS = {"basejka", "openjk", "eternaljk", "japro", "jk2mv", "newjk", "rend2", "vulkan", "taystjk", "quake3", "unknown"}
CONFIDENCE = {"high", "medium", "low"}
STATUS = {"documented", "needs-review", "unknown", "removed"}
NETWORK = {"client-only", "needs-server-support", "server-authoritative", "feature-flagged"}
DERIVATION = {"documented", "code-trace", "mixed"}
RENDERERS = {"rd-vanilla", "rd-rend2", "rd-vulkan", "rd-dedicated"}
COMMON = {
    "name", "kind", "module", "modules", "renderer", "summary", "description",
    "derivation", "network", "origin", "modified_by", "evidence", "confidence",
    "status", "source_commit",
}


def validate(path: Path, expected_kind: str) -> list[str]:
    errors: list[str] = []
    entries = json.loads(path.read_text())
    seen: set[str] = set()
    for index, entry in enumerate(entries):
        label = f"{path}:{index}:{entry.get('name', '<unnamed>')}"
        missing = COMMON - set(entry)
        if missing:
            errors.append(f"{label}: missing {sorted(missing)}")
        if entry.get("kind") != expected_kind:
            errors.append(f"{label}: kind is not {expected_kind}")
        key = str(entry.get("name", "")).casefold()
        if not key:
            errors.append(f"{label}: empty name")
        if key in seen:
            errors.append(f"{label}: duplicate case-insensitive name")
        seen.add(key)
        if not entry.get("summary") or not entry.get("description"):
            errors.append(f"{label}: empty prose")
        if entry.get("derivation") not in DERIVATION:
            errors.append(f"{label}: invalid derivation")
        if entry.get("network") not in NETWORK:
            errors.append(f"{label}: invalid network scope")
        if entry.get("confidence") not in CONFIDENCE:
            errors.append(f"{label}: invalid confidence")
        if entry.get("status") not in STATUS:
            errors.append(f"{label}: invalid status")
        if set(entry.get("renderer", [])) - RENDERERS:
            errors.append(f"{label}: invalid renderer")
        if not entry.get("evidence"):
            errors.append(f"{label}: no evidence")
        origin = entry.get("origin", {})
        if origin.get("source") not in ORIGINS:
            errors.append(f"{label}: invalid origin")
        if origin.get("confidence") not in CONFIDENCE or origin.get("status") not in STATUS:
            errors.append(f"{label}: incomplete origin assessment")
        if expected_kind == "cvar":
            for field in ("default", "flags", "value_type", "range", "values", "requires_restart"):
                if field not in entry:
                    errors.append(f"{label}: missing cvar field {field}")
            for option in entry.get("values", []):
                if not option.get("evidence"):
                    errors.append(f"{label}: option {option.get('value')} has no evidence")
        else:
            for field in ("syntax", "arguments", "gating", "handlers"):
                if field not in entry:
                    errors.append(f"{label}: missing command field {field}")
    return errors


def main() -> None:
    errors = validate(Path("_data/cvars.json"), "cvar")
    errors += validate(Path("_data/commands.json"), "command")
    if errors:
        raise SystemExit("\n".join(errors))
    print("reference data is valid")


if __name__ == "__main__":
    main()
