#!/usr/bin/env python3
"""Regression tests for provenance direction and chronology."""

from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from provenance import (
    attribute_change,
    credited_sources,
    enrich_introduction_events,
    developer_lineage_sources,
    integration_subject_sources,
    introduction_content_event,
    is_registration_line,
    module_lineage_beats_group_credit,
    pr_for_commit,
    reconcile_explicit_origin_credit,
    resolve_one,
    select_dated_origin,
)


def event(timestamp: int, sha: str, **extra: object) -> dict[str, object]:
    return {"timestamp": timestamp, "sha": sha, **extra}


class DatedOriginTests(unittest.TestCase):
    def test_introduction_line_rejects_variable_declaration(self) -> None:
        kinds = {"Cvar_Get"}
        self.assertFalse(is_registration_line("cl_downloadOverlay", kinds, "cvar_t *cl_downloadOverlay;"))
        self.assertTrue(is_registration_line(
            "cl_downloadOverlay", kinds,
            'cl_downloadOverlay = Cvar_Get("cl_downloadOverlay", "1", CVAR_ARCHIVE);',
        ))

    @patch("provenance.git")
    def test_content_history_uses_first_exact_registration_addition(
        self, git: object,
    ) -> None:
        line_sha = "a" * 40
        first_sha = "b" * 40
        later_sha = "c" * 40
        git.side_effect = [
            f"{line_sha} 1 1 1\nauthor Example\n\tregistration line\n",
            (
                f'@@@CONTENT@@@{later_sha}\t200\t210\tLater\tlater@example.test\tEdit registration\n+"example_cvar"\n'
                f'@@@CONTENT@@@{first_sha}\t100\t110\tFirst\tfirst@example.test\tAdd registration\n+"example_cvar"\n'
            ),
        ]
        introduction_content_event.cache_clear()
        result = introduction_content_event(
            "d" * 40, "code.cpp", 10, '"example_cvar"',
        )
        self.assertEqual(result["content_sha"], first_sha)
        self.assertEqual(result["content_author_timestamp"], 100)
        self.assertEqual(result["line_commit_sha"], line_sha)

    @patch("provenance.git")
    def test_content_history_stops_at_reverted_same_named_setting(self, git: object) -> None:
        current_sha, removed_sha, old_sha = "a" * 40, "b" * 40, "c" * 40
        git.side_effect = [
            f'{current_sha} 1 1 1\n\tcon_height = Cvar_Get("con_height", "0.5", 0);\n',
            (
                f'@@@CONTENT@@@{current_sha}\t300\t300\tNew\tnew@example.test\tAdd console height\n+"con_height"\n'
                f'@@@CONTENT@@@{removed_sha}\t200\t200\tOld\told@example.test\tRevert old setting\n+++ b/console.cpp\n-"con_height"\n'
                f'@@@CONTENT@@@{old_sha}\t100\t100\tOld\told@example.test\tOld setting\n+"con_height"\n'
            ),
            '// the old setting was reverted\n',
        ]
        introduction_content_event.cache_clear()
        result = introduction_content_event(current_sha, "console.cpp", 1, '"con_height"')
        self.assertEqual(result["content_sha"], current_sha)
        self.assertEqual(result["content_author_timestamp"], 300)

    def test_paths_and_default_values_are_not_project_credit(self) -> None:
        for text in (
            'com_unpackLibraries enabled; install dlls to the /EternalJK/ directory.',
            'Set fs_forcegame default to "EternalJK "to retain previous behaviour.',
            'fs_forcegame = Cvar_Get("fs_forcegame", "EternalJK", CVAR_INIT);',
            'fs_forcegame = Cvar_Get("fs_forcegame", "EternalJK", CVAR_INIT); // install /EternalJK/',
            'Install com_unpackLibraries dlls in "C:\\EternalJK\\".',
        ):
            with self.subTest(text=text):
                self.assertEqual(credited_sources(text), [])
        self.assertEqual(credited_sources(
            'fs_forcegame = Cvar_Get("fs_forcegame", "EternalJK", 0); // from jk2mv'
        ), ["jk2mv"])
        self.assertEqual(credited_sources('Port fs_forcegame from jk2mv.'), ["jk2mv"])
        self.assertEqual(credited_sources(
            'cl_idrive = Cvar_Get("cl_idrive", "0", 0, "From jaPRO");'
        ), ["japro"])
        self.assertEqual(credited_sources('Serverside duel isolation (JA+/jaPRO)'), ["japro"])

    @patch("provenance.git")
    def test_command_table_cleanup_does_not_break_content_history(self, git: object) -> None:
        current_sha, first_sha = "a" * 40, "b" * 40
        git.side_effect = [
            f'{current_sha} 1 1 1\n\t{{"fontlist", R_FontList_f}},\n',
            (
                f'@@@CONTENT@@@{current_sha}\t200\t200\tNew\tnew@example.test\tUse command table\n'
                '+++ b/renderer.cpp\n'
                '-Cmd_AddCommand("fontlist", R_FontList_f);\n'
                '-Cmd_RemoveCommand("fontlist");\n'
                '+{"fontlist", R_FontList_f},\n'
                f'@@@CONTENT@@@{"c" * 40}\t150\t150\tMove\tmove@example.test\tMove renderer\n'
                '--- a/old/renderer.cpp\n+++ /dev/null\n-Cmd_AddCommand("fontlist", R_FontList_f);\n'
                f'@@@CONTENT@@@{first_sha}\t100\t100\tFirst\tfirst@example.test\tAdd command\n'
                '+Cmd_AddCommand("fontlist", R_FontList_f);\n'
                '+Cmd_RemoveCommand("fontlist");\n'
            ),
            '{"fontlist", R_FontList_f},\n',
        ]
        introduction_content_event.cache_clear()
        result = introduction_content_event(current_sha, "renderer.cpp", 1, '"fontlist"')
        self.assertEqual(result["content_sha"], first_sha)

    def test_openjk_import_link_keeps_older_jk2mv_origin(self) -> None:
        source, _, _, _ = select_dated_origin({
            "jk2mv": event(100, "jk2mv", content_author_timestamp=100),
            "openjk": event(500, "openjk", content_author_timestamp=200),
            "taystjk": event(300, "tayst", content_author_timestamp=200,
                             linked_upstream_pr_sources=["openjk"]),
        })
        self.assertEqual(source, "jk2mv")

    @patch("provenance.source_context", return_value="")
    @patch("provenance.commit_body", return_value="Merge pull request #52\nFS Features")
    def test_fs_pr_values_do_not_override_origin_and_port_route(
        self, _body: object, _context: object,
    ) -> None:
        # The misleading literals and the upstream link are from TaystJK #52.
        prs = [{
            "number": 52, "merge_commit_sha": "a" * 40,
            "html_url": "https://github.com/taysta/TaystJK/pull/52",
            "_source": "taystjk",
            "body": (
                "Merge @Daggolin's FS featured PR from https://github.com/JACoders/OpenJK/pull/1185\n"
                '- Set fs_forcegame default to "EternalJK "to retain previous behaviour.\n'
                "- With com_unpackLibraries enabled, install dlls to the /EternalJK/ directory."
            ),
        }]
        for name, expected in (("com_unpackLibraries", "openjk"), ("fs_forcegame", "jk2mv")):
            with self.subTest(name=name):
                key = name.casefold()
                registration = {
                    "name": name, "kind": "Cvar_Get", "path": "code.cpp", "line": 1,
                    "module": "engine-shared", "renderer": None,
                }
                introductions = {
                    "taystjk": {key: event(300, "a" * 40, content_author_timestamp=200)},
                    "openjk": {key: event(500, "b" * 40, content_author_timestamp=200)},
                }
                if expected == "jk2mv":
                    introductions["jk2mv"] = {key: event(100, "c" * 40, content_author_timestamp=100)}
                upstream = {
                    source: {key: [registration]}
                    for source in introductions if source != "taystjk"
                }
                result = resolve_one(
                    key, [registration], set(), upstream, prs, Path("."), False,
                    introductions, {}, {}, {}, False,
                )
                self.assertEqual(result["source"], expected)
                self.assertEqual(result["origin_introduction"]["source"], expected)
                self.assertEqual(result["ported_via"], ["openjk"] if expected == "jk2mv" else [])
                self.assertNotIn("explicitly credits eternaljk", result["notes"])

    def test_explicit_newjk_import_does_not_require_public_head_presence(self) -> None:
        subject = "import strSub, ifCvar, delay and waitf from NewJK/NewMod"
        source, confidence, method, _ = select_dated_origin({
            "taystjk": event(200, "shared", content_subject=subject),
            "japro": event(200, "shared", content_subject=subject),
        })
        self.assertEqual((source, confidence, method), (
            "newjk", "high", "introduction-commit-explicit-credit",
        ))

    def test_generic_project_mention_without_import_is_not_missing_origin(self) -> None:
        for subject in (
            "NewJK compatibility adjustment",
            "Mouse repeat https://github.com/JACoders/OpenJK/issues/474",
            "Hibernation inspired by a patch for openjk https://github.com/JACoders/OpenJK/pull/826/files",
        ):
            with self.subTest(subject=subject):
                source, _, _, _ = select_dated_origin({
                    "taystjk": event(200, "shared", content_subject=subject),
                })
                self.assertEqual(source, "taystjk")

    @patch("provenance.source_context", return_value="")
    @patch("provenance.commit_body", return_value="Merge pull request #53 from taysta/daggo-misc")
    def test_daggo_filtergames_upstream_squash_does_not_claim_taystjk_origin(
        self, _body: object, _context: object,
    ) -> None:
        registration = {
            "name": "cl_filterGames", "kind": "Cvar_Get", "path": "client.cpp", "line": 1,
            "module": "engine-client", "renderer": None,
        }
        introductions = {
            "taystjk": {"cl_filtergames": event(200, "a" * 40, content_author_timestamp=100)},
            "openjk": {"cl_filtergames": event(300, "b" * 40, content_author_timestamp=300)},
        }
        result = resolve_one(
            "cl_filtergames", [registration], set(),
            {"openjk": {"cl_filtergames": [registration]}}, [], Path("."), False,
            introductions, {}, {}, {}, False,
        )
        self.assertEqual(result["source"], "openjk")
        self.assertEqual(result["ported_via"], [])
        self.assertIn("Daggolin", result["notes"])
        self.assertEqual(result["origin_introduction"]["source"], "openjk")

    @patch("provenance.source_context", return_value="")
    @patch("provenance.commit_body", return_value="Reconcile game module with the SDK")
    def test_reconciliation_cvars_belong_to_openjk_not_base_or_taystjk(
        self, _body: object, _context: object,
    ) -> None:
        for name in ("g_fixSaberDisarmBonus", "g_fixSaberMoveData"):
            with self.subTest(name=name):
                key = name.casefold()
                registration = {
                    "name": name, "kind": "XCVAR_DEF", "path": "codemp/game/g_xcvar.h",
                    "line": 1, "module": "game", "renderer": None,
                    "handler": None, "gating": [], "condition": None,
                }
                introductions = {
                    "taystjk": {key: event(200, "a" * 40, content_author_timestamp=100)},
                    "openjk": {key: event(300, "b" * 40, content_author_timestamp=100)},
                }
                result = resolve_one(
                    key, [registration], set(),
                    {"openjk": {key: [registration]}}, [], Path("."), False,
                    introductions, {}, {}, {}, False,
                )
                self.assertEqual(result["source"], "openjk")
                self.assertEqual(result["confidence"], "high")
                self.assertEqual(result["method"], "curated-historical-attribution")

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

    def test_shared_game_module_commit_uses_japro_provider_lineage(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "eternaljk": event(100, "shared"),
            "taystjk": event(100, "shared"),
            "japro": event(100, "shared"),
        }, shared_commit_preference="japro")
        self.assertEqual(source, "japro")
        self.assertEqual(confidence, "medium")
        self.assertEqual(method, "shared-earliest-commit-module-lineage")

    def test_game_module_lineage_does_not_override_explicit_credit(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "eternaljk": event(
                100, "shared", content_subject="Import game command from EternalJK",
            ),
            "japro": event(
                100, "shared", content_subject="Import game command from EternalJK",
            ),
        }, shared_commit_preference="japro")
        self.assertEqual(source, "eternaljk")
        self.assertEqual(confidence, "high")
        self.assertEqual(method, "introduction-commit-explicit-credit")

    def test_non_specific_group_credit_does_not_override_module_lineage(self) -> None:
        method = "shared-earliest-commit-module-lineage"
        self.assertTrue(module_lineage_beats_group_credit(method, direct_credit=False))
        self.assertFalse(module_lineage_beats_group_credit(method, direct_credit=True))

    def test_shared_merge_label_does_not_override_game_module_lineage(self) -> None:
        shared = event(
            100, "shared", subject="Merge branch 'master' of EternalJK",
        )
        source, confidence, method, _ = select_dated_origin({
            "eternaljk": dict(shared),
            "japro": dict(shared),
        }, shared_commit_preference="japro")
        self.assertEqual(source, "japro")
        self.assertEqual(confidence, "medium")
        self.assertEqual(method, "shared-earliest-commit-module-lineage")

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

    def test_openjk_pr_precedes_taystjk_first_merge(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "taystjk": event(
                300, "tayst-merge", content_author_timestamp=200,
                pr_created_timestamp=150, pr_url="https://github.com/taysta/TaystJK/pull/52",
            ),
            "japro": event(300, "tayst-merge", content_author_timestamp=200),
            "openjk": event(
                500, "openjk-merge", content_author_timestamp=200,
                pr_created_timestamp=100, pr_url="https://github.com/JACoders/OpenJK/pull/1185",
            ),
        })
        self.assertEqual(source, "openjk")
        self.assertEqual(confidence, "high")
        self.assertEqual(method, "earliest-authored-and-proposed-project-introduction")

    def test_commit_credit_beats_first_merge_date(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "taystjk": event(100, "shared", content_subject="jaPRO update"),
            "japro": event(100, "shared", content_subject="jaPRO update"),
        })
        self.assertEqual(source, "japro")
        self.assertEqual(confidence, "high")
        self.assertEqual(method, "introduction-commit-explicit-credit")

    def test_bucky_private_work_maps_to_eternaljk_not_japro(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "taystjk": event(
                100, "shared",
                content_subject=(
                    "[jaPRO/Bucky] Multicolored staff sabers "
                    "(cg_saberStaffMultiColor 0/1)"
                ),
            ),
            "japro": event(
                100, "shared",
                content_subject=(
                    "[jaPRO/Bucky] Multicolored staff sabers "
                    "(cg_saberStaffMultiColor 0/1)"
                ),
            ),
        })
        self.assertEqual(developer_lineage_sources("[jaPRO/Bucky] feature"), ["eternaljk"])
        self.assertEqual(source, "eternaljk")
        self.assertEqual(confidence, "high")
        self.assertEqual(method, "introduction-commit-developer-lineage-credit")
        self.assertEqual(
            reconcile_explicit_origin_credit(source, method, ["japro"]),
            [],
        )

    def test_single_available_pr_date_does_not_bias_missing_archives(self) -> None:
        source, _, _, _ = select_dated_origin({
            "japro": event(100, "japro", content_author_timestamp=50),
            "taystjk": event(
                200, "tayst", content_author_timestamp=50,
                pr_created_timestamp=25, pr_url="https://github.com/taysta/TaystJK/pull/1",
            ),
        })
        self.assertEqual(source, "japro")

    def test_shared_merge_subject_can_identify_upstream_project(self) -> None:
        source, confidence, method, _ = select_dated_origin({
            "openjk": event(100, "shared", subject="Merge branch from Razish/OpenJK"),
            "eternaljk": event(100, "shared", subject="Merge branch from Razish/OpenJK"),
        })
        self.assertEqual(source, "openjk")
        self.assertEqual(confidence, "high")
        self.assertEqual(method, "shared-integration-explicit-credit")

    def test_openjk_fork_url_is_still_openjk_evidence(self) -> None:
        source, _, method, _ = select_dated_origin({
            "openjk": event(
                100, "shared",
                subject="Merge branch of https://github.com/Razish/OpenJK into modrender-port",
            ),
            "eternaljk": event(
                100, "shared",
                subject="Merge branch of https://github.com/Razish/OpenJK into modrender-port",
            ),
        })
        self.assertEqual(source, "openjk")
        self.assertEqual(method, "shared-integration-explicit-credit")

    def test_merge_destination_is_not_treated_as_source(self) -> None:
        self.assertEqual(
            integration_subject_sources("Merge branch 'master' into japro"),
            set(),
        )

    @patch("provenance.introduction_content_event")
    def test_enrichment_uses_content_author_and_project_specific_pr(
        self, content_event: object,
    ) -> None:
        content_event.return_value = {
            "content_sha": "f" * 40,
            "content_author_timestamp": 200,
            "content_timestamp": 210,
        }
        prs = [
            {
                "number": 52, "merge_commit_sha": "a" * 40,
                "created_at": "1970-01-01T00:02:30Z", "html_url": "tayst",
                "_source": "taystjk",
            },
            {
                "number": 52, "merge_commit_sha": "b" * 40,
                "created_at": "1970-01-01T00:01:40Z", "html_url": "openjk",
                "_source": "openjk",
            },
        ]
        enriched = enrich_introduction_events({
            "taystjk": event(300, "a" * 40, path="code.cpp", line=10),
            "openjk": event(500, "b" * 40, path="code.cpp", line=20),
        }, prs)
        self.assertEqual(enriched["taystjk"]["pr_created_timestamp"], 150)
        self.assertEqual(enriched["openjk"]["pr_created_timestamp"], 100)
        self.assertEqual(select_dated_origin(enriched)[0], "openjk")

    def test_copied_upstream_pr_number_does_not_match_local_pr(self) -> None:
        commit = {"sha": "0" * 40, "subject": "Merge pull request #52"}
        prs = [{
            "number": 52, "merge_commit_sha": "1" * 40,
            "_source": "taystjk", "html_url": "unrelated",
        }]
        self.assertIsNone(pr_for_commit(commit, prs, "taystjk"))

    @patch("provenance.source_context")
    @patch("provenance.commit_body", return_value="SDL2 Windows Port")
    def test_nearby_project_comment_does_not_override_shared_origin(
        self, _body: object, context: object,
    ) -> None:
        context.return_value = (
            'Com_Printf("GPU Driver: %s\\n", driver); // Vulkan, debug\n'
            'Cmd_AddCommand("minimize", GLimp_Minimize);'
        )
        registration = {
            "name": "minimize", "kind": "Cmd_AddCommand",
            "path": "shared/sdl/sdl_window.cpp", "line": 791,
            "module": "engine-shared", "renderer": None,
            "handler": "GLimp_Minimize", "gating": [], "condition": None,
        }
        shared_event = {
            "sha": "a" * 40, "timestamp": 200,
            "author_timestamp": 200, "content_author_timestamp": 100,
            "content_sha": "b" * 40, "content_subject": "SDL2 window management",
        }
        sources = ("openjk", "eternaljk", "rend2", "taystjk", "vulkan")
        upstream = {
            source: {"minimize": [registration]}
            for source in sources if source != "taystjk"
        }
        introductions = {
            source: {"minimize": dict(shared_event)} for source in sources
        }

        result = resolve_one(
            "minimize", [registration], set(), upstream, [], Path("."), False,
            introductions, {}, {}, {}, False,
        )

        self.assertEqual(result["source"], "openjk")
        self.assertEqual(result["method"], "shared-earliest-commit-lineage-order")

    @patch("provenance.source_context", return_value='XCVAR_DEF( cg_chatBoxEmojis, "1", NULL, CVAR_ARCHIVE_ND )')
    @patch("provenance.commit_body", return_value="Merge remote-tracking branch 'JKSunny/features/Emojis'")
    def test_sunny_emoji_contribution_is_eternaljk_not_vulkan(
        self, _body: object, _context: object,
    ) -> None:
        registration = {
            "name": "cg_chatBoxEmojis", "kind": "XCVAR_DEF",
            "path": "codemp/cgame/cg_xcvar.h", "line": 67,
            "module": "cgame", "renderer": None,
            "handler": None, "gating": [], "condition": None,
        }
        shared_event = {
            "sha": "a" * 40, "timestamp": 200,
            "author_timestamp": 200, "content_author_timestamp": 100,
            "content_sha": "b" * 40, "content_subject": "Added Emoji support to chat",
        }
        sources = ("eternaljk", "taystjk", "japro", "vulkan")
        upstream = {
            source: {"cg_chatboxemojis": [registration]}
            for source in sources if source != "taystjk"
        }
        introductions = {
            source: {"cg_chatboxemojis": dict(shared_event)} for source in sources
        }

        result = resolve_one(
            "cg_chatboxemojis", [registration], set(), upstream, [], Path("."), False,
            introductions, {}, {}, {}, False,
        )

        self.assertEqual(result["source"], "eternaljk")
        self.assertEqual(result["confidence"], "high")
        self.assertEqual(result["status"], "documented")
        self.assertEqual(result["method"], "curated-historical-attribution")
        self.assertNotIn("explicitly credits vulkan", result["notes"])


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
