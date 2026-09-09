#!/usr/bin/env python3
"""Validate checked-in reference data without third-party dependencies."""

from __future__ import annotations

import json
from pathlib import Path
from typing import Any


ORIGINS = {"basejka", "openjk", "eternaljk", "japro", "jk2mv", "newjk", "rend2", "vulkan", "taystjk", "quake3", "unknown"}
CONFIDENCE = {"high", "medium", "low"}
STATUS = {"documented", "needs-review", "unknown", "removed"}
NETWORK = {"client-only", "needs-server-support", "server-authoritative", "feature-flagged"}
DERIVATION = {"documented", "code-trace", "mixed"}
RENDERERS = {"rd-vanilla", "rd-rend2", "rd-vulkan", "rd-dedicated"}
CHANGE_CATEGORIES = {"registration", "behavior-reference", "handler"}
COMMON = {
    "name", "kind", "module", "modules", "renderer", "summary", "description",
    "derivation", "network", "origin", "modified_by", "evidence", "confidence",
    "status", "source_commit", "category", "xdocs", "menu_entries",
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
        if not entry.get("category"):
            errors.append(f"{label}: empty category")
        if not isinstance(entry.get("menu_entries"), list):
            errors.append(f"{label}: invalid menu-entry evidence")
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
        introductions = origin.get("introduction_evidence", [])
        def introduction_rank(item: dict[str, Any]) -> tuple[int, int, int]:
            integrated = int(item.get("timestamp") or 0)
            authored = int(
                item.get("content_author_timestamp")
                or item.get("author_timestamp")
                or integrated
            )
            proposed = int(item.get("pr_created_timestamp") or integrated)
            return authored, proposed, integrated

        ranks = [introduction_rank(item) for item in introductions]
        if ranks != sorted(ranks):
            errors.append(f"{label}: project introductions are not evidence-chronological")
        introduction_sources = [item.get("source") for item in introductions]
        if len(introduction_sources) != len(set(introduction_sources)):
            errors.append(f"{label}: duplicate project introduction source")
        origin_introduction = origin.get("origin_introduction")
        if origin_introduction:
            if origin_introduction.get("source") != origin.get("source"):
                errors.append(f"{label}: origin introduction does not match attributed source")
        downstream = origin.get("downstream_introductions", [])
        expected_downstream = (
            {
                (item.get("source"), item.get("sha"))
                for item in introductions
                if item.get("source") != origin.get("source")
            }
            if origin_introduction else set()
        )
        actual_downstream = {
            (item.get("source"), item.get("sha")) for item in downstream
        }
        if actual_downstream != expected_downstream:
            errors.append(f"{label}: downstream introductions do not match non-origin projects")
        modifications = entry.get("modified_by", [])
        dated_modifications = [item for item in modifications if item.get("timestamp") is not None]
        modification_timestamps = [item["timestamp"] for item in dated_modifications]
        if modification_timestamps != sorted(modification_timestamps):
            errors.append(f"{label}: later changes are not chronological")
        commits = [item.get("commit") for item in modifications if item.get("commit")]
        if len(commits) != len(set(commits)):
            errors.append(f"{label}: duplicate later-change commit")
        for change in modifications:
            if change.get("source") not in ORIGINS:
                errors.append(f"{label}: invalid later-change source")
            if change.get("confidence") not in CONFIDENCE:
                errors.append(f"{label}: invalid later-change confidence")
            if set(change.get("categories", [])) - CHANGE_CATEGORIES:
                errors.append(f"{label}: invalid later-change category")
            if not change.get("method") or not change.get("change"):
                errors.append(f"{label}: incomplete later-change evidence")
            commit = change.get("commit")
            if commit is not None and (
                not isinstance(commit, str) or len(commit) != 40
                or any(character not in "0123456789abcdef" for character in commit)
            ):
                errors.append(f"{label}: invalid later-change commit")
            if commit and change.get("timestamp") is None:
                errors.append(f"{label}: dated later-change commit has no timestamp")
            if change.get("repository") not in ORIGINS:
                errors.append(f"{label}: invalid later-change repository")
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
