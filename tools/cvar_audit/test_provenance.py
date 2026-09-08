#!/usr/bin/env python3
"""Regression tests for provenance direction and chronology."""

from __future__ import annotations

import unittest
from unittest.mock import patch

from provenance import attribute_change, select_dated_origin


def event(timestamp: int, sha: str) -> dict[str, object]:
    return {"timestamp": timestamp, "sha": sha}


class DatedOriginTests(unittest.TestCase):
    def test_later_newjk_import_does_not_claim_rend2_origin(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "rend2": event(100, "rend2"),
            "taystjk": event(200, "taystjk"),
            "newjk": event(300, "newjk"),
        })
        self.assertEqual(source, "rend2")
        self.assertEqual(confidence, "high")
        self.assertEqual(method, "earliest-dated-project-introduction")

    def test_later_vulkan_port_does_not_claim_taystjk_origin(self) -> None:
        source, _, _, _ = select_dated_origin({
            "taystjk": event(100, "taystjk"),
            "vulkan": event(200, "vulkan"),
        })
        self.assertEqual(source, "taystjk")

    def test_shared_taystjk_commit_is_not_claimed_by_synced_vulkan(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "taystjk": event(100, "shared"),
            "vulkan": event(100, "shared"),
        })
        self.assertEqual(source, "taystjk")
        self.assertEqual(confidence, "medium")
        self.assertEqual(method, "shared-earliest-commit-lineage-order")

    def test_direction_is_not_hardcoded_to_one_project_pair(self) -> None:
        source, _, _, _ = select_dated_origin({
            "jk2mv": event(100, "jk2mv"),
            "japro": event(200, "japro"),
            "taystjk": event(300, "taystjk"),
        })
        self.assertEqual(source, "jk2mv")

    def test_shared_commit_uses_lineage_tie_break_only_after_date(self) -> None:
        source, confidence, method, tied = select_dated_origin({
            "eternaljk": event(100, "same"),
            "vulkan": event(100, "same"),
            "taystjk": event(200, "later"),
        })
        self.assertEqual(source, "eternaljk")
        self.assertEqual(confidence, "medium")
        self.assertEqual(method, "shared-earliest-commit-lineage-order")
        self.assertEqual(tied, ["eternaljk", "vulkan"])


class ChangeAttributionTests(unittest.TestCase):
    def change(self) -> dict[str, object]:
        return {
            "sha": "a" * 40,
            "timestamp": 200,
            "subject": "Adjust the setting",
            "categories": ["registration"],
            "paths": ["codemp/example.cpp"],
        }

    @patch("provenance.pr_for_commit", return_value=None)
    @patch("provenance.commit_body", return_value="Import adjustment from jaPRO")
    def test_explicit_change_credit_wins_over_containment(
        self, _body: object, _pr: object,
    ) -> None:
        change = self.change()
        result = attribute_change(change, [], {
            "taystjk": {change["sha"]},
            "japro": {change["sha"]},
        })
        self.assertEqual(result["source"], "japro")
        self.assertEqual(result["repository"], "japro")
        self.assertEqual(result["method"], "explicit-change-credit")
        self.assertEqual(result["confidence"], "high")

    @patch("provenance.pr_for_commit", return_value=None)
    @patch("provenance.commit_body", return_value="")
    def test_shared_taystjk_change_is_not_claimed_by_vulkan_copy(
        self, _body: object, _pr: object,
    ) -> None:
        change = self.change()
        result = attribute_change(change, [], {
            "taystjk": {change["sha"]},
            "vulkan": {change["sha"]},
        })
        self.assertEqual(result["source"], "taystjk")
        self.assertEqual(result["confidence"], "medium")
        self.assertEqual(result["method"], "shared-change-commit-lineage-order")


if __name__ == "__main__":
    unittest.main()
