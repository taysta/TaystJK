#!/usr/bin/env python3
"""Validate checked-in reference data without third-party dependencies."""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any

from generate_docs import load_whats_new_overrides, validate_whats_new_overrides


ORIGINS = {"basejka", "openjk", "eternaljk", "japro", "jk2mv", "newjk", "rend2", "vulkan", "taystjk", "quake3", "unknown"}
CONFIDENCE = {"high", "medium", "low"}
STATUS = {"documented", "needs-review", "unknown", "removed"}
NETWORK = {"client-only", "needs-server-support", "server-authoritative", "feature-flagged"}
DERIVATION = {"documented", "code-trace", "mixed"}
RENDERERS = {"rd-vanilla", "rd-rend2", "rd-vulkan", "rd-dedicated"}
CHANGE_CATEGORIES = {"registration", "behavior-reference", "handler"}
ENGINE_MANAGED_BASIS = {"CVAR_ROM", "CVAR_INTERNAL", "implicit-write", "menu-mirror", "editorial"}
COMMON = {
    "name", "kind", "module", "modules", "renderer", "summary", "description",
    "derivation", "network", "origin", "modified_by", "evidence", "confidence",
    "status", "source_commit", "category", "feature", "xdocs", "menu_entries",
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
        if entry.get("feature") is not None and not isinstance(entry.get("feature"), str):
            errors.append(f"{label}: invalid feature family")
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
        has_dated_or_private_origin = bool(
            origin_introduction
            or "developer-lineage-credit" in str(origin.get("method") or "")
        )
        expected_downstream = {
            (item.get("source"), item.get("sha"))
            for item in introductions
            if item.get("source") != origin.get("source")
        } if has_dated_or_private_origin else set()
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
            for field in (
                "default", "flags", "value_type", "range", "values", "requires_restart",
                "engine_managed", "engine_managed_basis", "menu_mirror", "bits",
            ):
                if field not in entry:
                    errors.append(f"{label}: missing cvar field {field}")
            basis = entry.get("engine_managed_basis", [])
            if not isinstance(basis, list) or set(basis) - ENGINE_MANAGED_BASIS:
                errors.append(f"{label}: invalid engine-managed basis {basis!r}")
            elif bool(basis) != bool(entry.get("engine_managed")):
                errors.append(f"{label}: engine-managed flag does not match its basis")
            mirror = entry.get("menu_mirror")
            if mirror is not None and (
                not mirror.get("target") or not (mirror.get("apply") or mirror.get("read"))
            ):
                errors.append(f"{label}: menu mirror has no target or no evidence")
            if bool(mirror) != ("menu-mirror" in basis if isinstance(basis, list) else False):
                errors.append(f"{label}: menu mirror does not match its engine-managed basis")
            bits = entry.get("bits")
            if bits is not None:
                options = bits.get("options") or []
                if not options or not bits.get("evidence"):
                    errors.append(f"{label}: bit table has no options or no evidence")
                if [option.get("bit") for option in options] != sorted(
                    option.get("bit") for option in options
                ):
                    errors.append(f"{label}: bit options are not in bit order")
                if any(not option.get("meaning") for option in options):
                    errors.append(f"{label}: unnamed bit option")
            for option in entry.get("values", []):
                if not option.get("evidence"):
                    errors.append(f"{label}: option {option.get('value')} has no evidence")
        else:
            for field in ("syntax", "arguments", "gating", "handlers", "configures"):
                if field not in entry:
                    errors.append(f"{label}: missing command field {field}")
    return errors


BASELINES = ("eternaljk", "openjk", "basejka")
BASELINE_TOTALS_PATH = Path("tools/cvar_audit/baseline-totals.json")


def baseline_totals(entries: list[dict[str, Any]]) -> dict[str, int]:
    """Count entries absent from each independently pinned baseline inventory."""
    return {
        name: sum(
            1 for entry in entries
            if isinstance(entry.get("baselines"), list) and name in entry["baselines"]
        )
        for name in BASELINES
    }


def validate_baselines(
    entries: list[dict[str, Any]], expected_totals: dict[str, int],
) -> list[str]:
    """Check independent baseline membership and totals."""
    errors: list[str] = []
    for entry in entries:
        values = entry.get("baselines")
        if not isinstance(values, list) or any(value not in BASELINES for value in values):
            errors.append(f"{entry['name']}: invalid baselines {values!r}")
        elif len(values) != len(set(values)):
            errors.append(f"{entry['name']}: duplicate baselines {values!r}")
    actual_totals = baseline_totals(entries)
    for name in BASELINES:
        total = actual_totals[name]
        expected = expected_totals.get(name)
        if expected is None:
            errors.append(f"baseline totals: missing expected count for {name}")
            continue
        if total != expected:
            errors.append(
                f"baseline total for {name}: expected {expected}, found {total}. "
                "Inventory comparisons changed; confirm the shift is intended, then update "
                f"{BASELINE_TOTALS_PATH} and the documented counts."
            )
    return errors


def validate_bit_pairing(entries: list[dict[str, Any]]) -> list[str]:
    """Each command's configured cvars must name that command back."""
    errors: list[str] = []
    owner = {
        entry["name"]: (entry.get("bits") or {}).get("commands")
        for entry in entries if entry.get("kind") == "cvar"
    }
    for entry in entries:
        for name in entry.get("configures", []):
            if name not in owner:
                errors.append(f"{entry['name']}: configures unknown cvar {name}")
            elif entry["name"] not in (owner[name] or []):
                errors.append(
                    f"{entry['name']}: configures {name}, which names "
                    f"{owner[name]!r} as its commands"
                )
    return errors


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--update-baseline-totals", action="store_true",
        help="record current independent-baseline totals after regenerating the reference",
    )
    args = parser.parse_args()

    errors = validate(Path("_data/cvars.json"), "cvar")
    errors += validate(Path("_data/commands.json"), "command")
    entries = (
        json.loads(Path("_data/cvars.json").read_text())
        + json.loads(Path("_data/commands.json").read_text())
    )
    actual_baseline_totals = baseline_totals(entries)
    if args.update_baseline_totals:
        expected_baseline_totals = actual_baseline_totals
    elif BASELINE_TOTALS_PATH.exists():
        expected_baseline_totals = json.loads(BASELINE_TOTALS_PATH.read_text())
    else:
        expected_baseline_totals = {}
        errors.append(f"missing baseline totals file {BASELINE_TOTALS_PATH}")
    errors += validate_baselines(entries, expected_baseline_totals)
    errors += validate_bit_pairing(entries)
    # Checked here as well as at generation time so CI catches a hand-tuning
    # file that has rotted against renamed entries, without regenerating.
    errors += validate_whats_new_overrides(entries, load_whats_new_overrides())
    if errors:
        raise SystemExit("\n".join(errors))
    if args.update_baseline_totals:
        BASELINE_TOTALS_PATH.write_text(
            json.dumps(actual_baseline_totals, indent=2, sort_keys=True) + "\n"
        )
        print(f"updated {BASELINE_TOTALS_PATH}")
    print("reference data is valid")


if __name__ == "__main__":
    main()
