#!/usr/bin/env python3
"""Regression coverage for snapshot reuse and reference presentation."""

import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from build_reference import (
    bit_option_index, calling_handler, engine_managed_basis, menu_mirror_index,
    registration_baselines,
)
from check_generated import fragment_errors, page_anchor_ids
from generate_docs import (
    bit_table, detail_page, emoji_page, engine_managed_notice, mirror_row, whats_new_rows,
    whats_new_page,
)
from provenance import (
    RESOLVER_VERSION,
    extract_ref,
    reusable_provenance,
    reusable_provenance_entry,
)
from validate import baseline_totals, validate_baselines


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

    def test_resolver_upgrade_refreshes_only_shared_japro_game_entries(self):
        report = {"meta": {
            "extractor_version": 7, "provenance_schema_version": 6,
            "resolver_version": 36,
        }}
        self.assertTrue(reusable_provenance(report))
        old_entry = {
            "source": "eternaljk",
            "method": "shared-earliest-commit-lineage-order",
            "upstream_presence": ["eternaljk", "japro"],
        }
        self.assertFalse(reusable_provenance_entry(
            old_entry, [{"module": "game"}], 36,
        ))
        self.assertTrue(reusable_provenance_entry(
            old_entry, [{"module": "cgame"}], 36,
        ))
        group_credit_entry = {
            "source": "eternaljk",
            "method": "squash-feature-group-explicit-credit",
            "upstream_presence": ["eternaljk", "japro"],
        }
        self.assertTrue(reusable_provenance({"meta": {
            "extractor_version": 7, "provenance_schema_version": 6,
            "resolver_version": 37,
        }}))
        self.assertFalse(reusable_provenance_entry(
            group_credit_entry, [{"module": "game"}], 37,
        ))
        self.assertFalse(reusable_provenance_entry(
            {"source": "taystjk"},
            [{"name": "g_fixSaberMoveData", "module": "game"}],
            39,
        ))

    def test_baselines_use_presence_and_are_not_cumulative(self):
        inventories = {"eternaljk": {"cg_camerafps"}, "openjk": {"removed_upstream"}, "basejka": set()}
        self.assertEqual(registration_baselines("cg_cameraFPS", inventories), ["openjk", "basejka"])
        self.assertEqual(registration_baselines("removed_upstream", inventories), ["eternaljk", "basejka"])

    def test_baseline_totals_are_reviewed_separately_from_membership(self):
        entries = [
            {"name": "one", "baselines": ["eternaljk", "openjk"]},
            {"name": "two", "baselines": ["basejka"]},
        ]
        totals = {"eternaljk": 1, "openjk": 1, "basejka": 1}
        self.assertEqual(baseline_totals(entries), totals)
        self.assertEqual(validate_baselines(entries, totals), [])
        self.assertIn(
            "baseline total for openjk: expected 0, found 1",
            validate_baselines(entries, {**totals, "openjk": 0})[0],
        )

    def test_engine_state_is_separated_from_a_settable_cvar(self):
        registered = [{"kind": "Cvar_Get"}]
        self.assertEqual(engine_managed_basis([], registered), [])
        self.assertEqual(engine_managed_basis(["CVAR_ARCHIVE"], registered), [])
        self.assertEqual(
            engine_managed_basis(["CVAR_INTERNAL", "CVAR_ROM"], registered),
            ["CVAR_ROM", "CVAR_INTERNAL"],
        )
        # ui_tribesMode's shape: written by the UI, never registered anywhere.
        self.assertEqual(
            engine_managed_basis([], [{"kind": "implicit Cvar_Set"}, {"kind": "implicit Cvar_Set"}]),
            ["implicit-write"],
        )
        # One real registration is enough to keep it a setting players own.
        self.assertEqual(
            engine_managed_basis([], [{"kind": "XCVAR_DEF"}, {"kind": "implicit Cvar_Set"}]),
            [],
        )

    def test_menu_mirror_pairs_a_staging_copy_with_its_setting(self):
        mirrors = menu_mirror_index([("codemp/ui/ui_main.c", """
void UI_UpdateVideoSetup ( void ) {
	trap->Cvar_Set ( "r_picmip", UI_Cvar_VariableString ( "ui_r_picmip" ) );
}
void UI_GetVideoSetup ( void ) {
	trap->Cvar_Set ( "ui_r_picmip", UI_Cvar_VariableString ( "r_picmip" ) );
	// trap->Cvar_Set ( "g_redTeam", UI_Cvar_VariableString ( "ui_teamName" ) );
}
""")])
        self.assertEqual(sorted(mirrors), ["ui_r_picmip"])
        mirror = mirrors["ui_r_picmip"]
        self.assertEqual(mirror["target"], "r_picmip")
        # Both directions are recorded, and a commented-out pair is not a pair.
        self.assertEqual(mirror["apply"]["line"], 3)
        self.assertEqual(mirror["read"]["line"], 6)
        self.assertNotIn("ui_teamname", mirrors)
        self.assertEqual(engine_managed_basis([], [{"kind": "Cvar_Get"}], mirror), ["menu-mirror"])

    def test_mirror_row_links_only_a_target_that_has_a_page(self):
        entry = {"menu_mirror": {"target": "r_picmip", "apply": {"url": "u", "path": "p", "line": 1}, "read": None}}
        row = mirror_row(entry, {"r_picmip": "r_picmip"})
        self.assertIn("/TaystJK/reference/cvars/r_picmip-", row)
        self.assertIn("written through", row)
        self.assertNotIn("read back", row)
        # A target the source writes but never registers is named, not linked.
        unlinked = mirror_row(entry, {})
        self.assertNotIn("[`r_picmip`](", unlinked)
        self.assertIn("`r_picmip`", unlinked)

    BIT_SOURCE = """
static bitInfo_T strafeTweaks[] = {
	{"Original style"},
	{"Sound"}
};
static const int MAX_STRAFEHELPER_TWEAKS = ARRAY_LEN( strafeTweaks );
void CG_StrafeHelper_f( void ) {
	trap->Cvar_Set("cg_strafeHelper", va("%i", (1 << index) ^ cg_strafeHelper.integer));
	CG_Print(strafeTweaks[index].string);
}
static bitInfo_T adminOptions[] = {
	{"Kick"}
};
void Svcmd_ToggleAdmin_f( void ) {
	trap->Cvar_Set( "g_juniorAdminLevel", va( "%i", value ) );
	trap->Cvar_Set( "g_fullAdminLevel", va( "%i", value ) );
	trap->Print( "%s", adminOptions[index].string );
}
"""

    def test_bit_tables_pair_with_every_cvar_their_handler_sets(self):
        index = bit_option_index([("codemp/cgame/cg_consolecmds.c", self.BIT_SOURCE)])
        self.assertEqual(
            sorted(index), ["cg_strafehelper", "g_fulladminlevel", "g_junioradminlevel"],
        )
        options = index["cg_strafehelper"]["options"]
        # Bit order is the array position, and the value is that bit alone.
        self.assertEqual(
            options, [{"bit": 0, "value": "1", "meaning": "Original style"},
                      {"bit": 1, "value": "2", "meaning": "Sound"}],
        )
        self.assertEqual(index["cg_strafehelper"]["handler"], "CG_StrafeHelper_f")
        # One table drives both admin levels, so neither is dropped.
        self.assertEqual(index["g_fulladminlevel"]["options"], [{"bit": 0, "value": "1", "meaning": "Kick"}])

    def test_a_handler_is_bounded_by_its_own_body(self):
        # The last table in a file must not absorb every function after it.
        source = self.BIT_SOURCE + """
void CG_Unrelated_f( void ) {
	trap->Cvar_Set("cg_somethingElse", "1");
}
"""
        index = bit_option_index([("codemp/cgame/cg_consolecmds.c", source)])
        self.assertNotIn("cg_somethingelse", index)

    def test_commented_out_table_is_not_a_bit_table(self):
        source = "/*" + self.BIT_SOURCE + "*/\n"
        self.assertEqual(bit_option_index([("codemp/game/g_svcmds.c", source)]), {})

    def test_dispatcher_resolves_to_the_registered_handler(self):
        source = """
void CG_Cosmetics_JaPRO( void ) {
	trap->Cvar_Set("cp_cosmetics", "1");
}
void CG_Cosmetics_f( void ) {
	CG_Cosmetics_JaPRO();
}
"""
        files = [("codemp/cgame/cg_consolecmds.c", source)]
        self.assertEqual(calling_handler(files, "CG_Cosmetics_JaPRO"), "CG_Cosmetics_f")
        self.assertIsNone(calling_handler(files, "CG_Missing_f"))

    def test_bit_table_keeps_a_traced_read_beside_the_label(self):
        entry = {
            "source_commit": "a" * 40,
            "values": [{"value": "2", "meaning": "ignored", "evidence": {"path": "cg.h", "line": 63}}],
            "bits": {
                "commands": ["strafeHelper", "sh"],
                "options": [{"bit": 0, "value": "1", "meaning": "Original style"},
                            {"bit": 1, "value": "2", "meaning": "Sound"}],
                "evidence": {"path": "cg_consolecmds.c", "line": 1108, "url": "u"},
            },
        }
        rendered = "\n".join(bit_table(entry))
        self.assertIn("strafeHelper", rendered)
        self.assertIn("strafeHelper`](/TaystJK/reference/commands/strafehelper-", rendered)
        self.assertIn(" or [`sh`](/TaystJK/reference/commands/sh-", rendered)
        self.assertIn("see the command pages for syntax", rendered)
        self.assertNotIn("followed by the bit number", rendered)
        self.assertIn("| 1 | `2` | Sound | [cg.h:63](", rendered)
        self.assertIn("| 0 | `1` | Original style | — |", rendered)
        self.assertEqual(bit_table({"bits": None}), [])

    def test_engine_managed_notice_names_each_basis(self):
        notice = engine_managed_notice({"engine_managed_basis": ["CVAR_ROM", "implicit-write"]})
        self.assertIn("CVAR_ROM", notice)
        self.assertIn("Cvar_Set", notice)
        self.assertIsNone(engine_managed_notice({"engine_managed_basis": []}))
        self.assertIsNone(engine_managed_notice({}))
        mirrored = engine_managed_notice(
            {"engine_managed_basis": ["menu-mirror"],
             "menu_mirror": {"target": "r_picmip", "apply": None, "read": None}},
            {"r_picmip": "r_picmip"},
        )
        self.assertIn("staging copy", mirrored)
        self.assertIn("/TaystJK/reference/cvars/r_picmip-", mirrored)

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


    def test_anchor_ids_follow_kramdown_gfm(self):
        ids = page_anchor_ids(
            "# Install TaystJK\n"
            "## When to use `vm_legacy`\n"
            "### Install TaystJK\n"
            "```sh\n# not a heading\n```\n"
            "## Positioning: the `.cosmetic` file\n"
            '<section id="platform-panel-windows">\n'
        )
        self.assertEqual(ids, {
            "install-taystjk", "install-taystjk-1", "when-to-use-vm_legacy",
            "positioning-the-cosmetic-file", "platform-panel-windows",
        })

    def test_broken_same_page_anchor_is_reported(self):
        with tempfile.TemporaryDirectory() as directory:
            page = Path(directory) / "page.md"
            text = "## Real heading\n\nSee [here](#real-heading) and [there](#missing).\n"
            page.write_text(text)
            self.assertEqual(fragment_errors(page, text, {}), [f"broken anchor in {page}: #missing"])

    def test_detail_page_lists_only_other_registering_modules(self):
        refs = json.loads(Path("_data/reference-meta.json").read_text())["upstream_commits"]
        cvars = json.loads(Path("_data/cvars.json").read_text())
        single = next(e for e in cvars if e.get("modules") == [e["module"]])
        self.assertNotIn("Also registered in", detail_page(single, refs))
        shared = next(e for e in cvars if len(set(e.get("modules", []))) > 1)
        row = next(line for line in detail_page(shared, refs).splitlines() if line.startswith("| Also registered in"))
        self.assertNotIn(f"`{shared['module']}`", row)

if __name__ == "__main__":
    unittest.main()
