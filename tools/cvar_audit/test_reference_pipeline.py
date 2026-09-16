#!/usr/bin/env python3
"""Regression coverage for snapshot reuse and reference presentation."""

import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from build_reference import registration_baselines
from generate_docs import emoji_page, whats_new_rows, whats_new_page
from provenance import extract_ref, reusable_provenance, RESOLVER_VERSION


class PipelineTests(unittest.TestCase):
    @patch("provenance.git", return_value="a" * 40)
    @patch("provenance.source_files")
    def test_old_inventory_cache_is_reextracted_and_new_cache_reused(self, files, git):
        files.return_value = [("codemp/client/test.cpp", '''
#define DEFAULT_RENDER_LIBRARY "rd-taystjk"
r = ri.Cvar_Get("cl_renderer", DEFAULT_RENDER_LIBRARY, CVAR_ARCHIVE);
''')]
        with tempfile.TemporaryDirectory() as directory:
            cache = Path(directory)
            (cache / "extract").mkdir()
            old = cache / "extract/origin_master.v6.cvars.json"
            old.write_text(json.dumps([{"name": "cl_renderer", "default": "DEFAULT_RENDER_LIBRARY"}]))
            records = extract_ref("origin/master", "cvars", cache, False)
            self.assertEqual(records[0]["default"], "rd-taystjk")
            self.assertEqual(records[0]["variable"], "r")
            self.assertEqual(json.loads(json.dumps(records)), extract_ref("origin/master", "cvars", cache, False))
            files.assert_called_once_with("a" * 40, ".", None)
            # A moved branch must not return the earlier source inventory.
            git.return_value = "b" * 40
            files.return_value = []
            self.assertEqual(extract_ref("origin/master", "cvars", cache, False), [])

    def test_extraction_upgrade_preserves_resolved_provenance(self):
        self.assertTrue(reusable_provenance({"meta": {
            "extractor_version": 6, "resolver_version": RESOLVER_VERSION,
        }}))
        self.assertTrue(reusable_provenance({"meta": {
            "extractor_version": 7, "provenance_schema_version": 6,
            "resolver_version": RESOLVER_VERSION,
        }}))
        self.assertFalse(reusable_provenance({"meta": {
            "extractor_version": 5, "resolver_version": RESOLVER_VERSION,
        }}))

    def test_baselines_use_presence_and_are_not_cumulative(self):
        inventories = {"eternaljk": {"cg_camerafps"}, "openjk": {"removed_upstream"}, "basejka": set()}
        self.assertEqual(registration_baselines("cg_cameraFPS", inventories), ["openjk", "basejka"])
        self.assertEqual(registration_baselines("removed_upstream", inventories), ["eternaljk", "basejka"])

    @patch("generate_docs.export_emoji_assets", return_value={"#smile.png": "smile.png"})
    @patch("generate_docs.emoji_files", return_value=["#smile.png"])
    def test_emoji_assets_and_attribution_share_snapshot(self, files, export):
        sha = "a" * 40
        page, warnings = emoji_page(sha)
        files.assert_called_once_with(sha)
        export.assert_called_once_with(sha, ["#smile.png"])
        self.assertIn(sha, page)
        self.assertFalse(warnings)

    def test_promoted_rows_precede_unranked_alphabetical_rows(self):
        def entry(name):
            return {"name": name, "kind": "cvar", "category": "HUD", "summary": "Example.",
                    "origin": {"source": "taystjk"}}
        rows = whats_new_rows([entry("alpha"), entry("beta"), entry("gamma")], [], {
            "gamma": {"promote": 1}, "beta": {"promote": 2},
        })
        text = "\n".join(rows)
        self.assertLess(text.index("gamma"), text.index("beta"))
        self.assertLess(text.index("beta"), text.index("alpha"))

    @patch("generate_docs.declared_features", return_value=[])
    @patch("generate_docs.load_whats_new_overrides", return_value={"entries": {}, "features": []})
    def test_rendered_panels_respect_independent_membership(self, overrides, features):
        page, _, _ = whats_new_page([{
            "name": "only_eternaljk_lacks_this", "kind": "cvar", "category": "HUD",
            "summary": "Example.", "origin": {"source": "jk2mv"},
            "source_commit": "a" * 40, "baselines": ["eternaljk"],
        }])
        eternal, rest = page.split('id="baseline-panel-eternaljk"')[1].split('id="baseline-panel-openjk"')
        self.assertIn("only_eternaljk_lacks_this", eternal)
        self.assertNotIn("only_eternaljk_lacks_this", rest)


if __name__ == "__main__":
    unittest.main()
