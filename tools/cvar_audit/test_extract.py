#!/usr/bin/env python3
"""Regression tests for the tolerant source extractor."""

import unittest

from extract import extract_commands, extract_cvars
from build_reference import clean_description, command_syntax, infer_values


class ExtractTests(unittest.TestCase):
    def test_cvar_registration_forms_and_dead_code(self) -> None:
        source = r'''
XCVAR_DEF(cg_live, "1", NULL, CVAR_ARCHIVE)
// XCVAR_DEF(cg_comment, "1", NULL, CVAR_ARCHIVE)
// A nearby commented-out registration must never become cg_after's description.
XCVAR_DEF(cg_after, "0", NULL, CVAR_NONE) // Actual description
#if 0 // deliberately disabled
XCVAR_DEF(cg_dead, "1", NULL, CVAR_ARCHIVE)
#endif
static cvarTable_t cvarTable[] = {
    { &cg_old, "cg_oldName", "2", CVAR_CHEAT }, // legacy table
};
foo = Cvar_Get("foo_name", "3.5", CVAR_LATCH, "Foo description");
path = Cvar_Get("path_name", DefaultPath(), CVAR_INIT, "Dynamic default");
formatted = Cvar_Get("formatted_name", va("%d", sizeof(thing) + 5), CVAR_ARCHIVE);
trap->Cvar_Register(&bar, "bar_name", "hello", CVAR_USERINFO);
trap_Cvar_Register(&legacy, "legacy_syscall", "5", CVAR_ROM);
Cvar_Set("implicit_name", "4");
'''
        records = extract_cvars([("codemp/cgame/example.c", source)])
        names = {record.name for record in records}
        self.assertEqual(
            names,
            {"cg_live", "cg_after", "cg_oldName", "foo_name", "path_name", "formatted_name", "bar_name", "legacy_syscall", "implicit_name"},
        )
        foo = next(record for record in records if record.name == "foo_name")
        self.assertEqual(foo.variable, "foo")
        self.assertEqual(foo.description, "Foo description")
        formatted = next(record for record in records if record.name == "formatted_name")
        self.assertEqual(formatted.default, 'va("%d", sizeof(thing) + 5)')
        self.assertEqual(formatted.flags, ("CVAR_ARCHIVE",))
        old = next(record for record in records if record.name == "cg_oldName")
        self.assertEqual(old.variable, "cg_old")
        self.assertEqual(old.flags, ("CVAR_CHEAT",))
        after = next(record for record in records if record.name == "cg_after")
        self.assertEqual(after.line, 5)
        self.assertEqual(after.description, "Actual description")

    def test_macro_valued_defaults(self) -> None:
        source = r'''
#define MASTER_SERVER_NAME  "masterjk3.ravensoft.com"
#define DEFAULT_SABER       PRIMARY_SABER
#define PRIMARY_SABER       "Kyle"
#define DEFAULT_MODEL       "kyle"
#define SOURCE_DATE         __DATE__
#define MAX_CLIENTS_SHOWN   32
#define GREETING(who)       "hello " who
#ifdef _WIN32
#define PLATFORM_PATH       "windows"
#else
#define PLATFORM_PATH       "posix"
#endif
typedef enum { BOTH_WALK1, BOTH_RUN1 } animNumber_t;
Cvar_Get("sv_master1", MASTER_SERVER_NAME, CVAR_PROTECTED);
Cvar_Get("saber1", DEFAULT_SABER, CVAR_ARCHIVE);
Cvar_Get("model", DEFAULT_MODEL"/default", CVAR_USERINFO);
Cvar_Get("gamedate", SOURCE_DATE, CVAR_ROM);
Cvar_Get("ui_char_anim", "BOTH_WALK1", CVAR_ROM);
Cvar_Get("cg_shown", MAX_CLIENTS_SHOWN, CVAR_ARCHIVE);
Cvar_Get("fs_platform", PLATFORM_PATH, CVAR_INIT);
Cvar_Get("cg_missing", ABSENT_MACRO_NAME, CVAR_ARCHIVE);
Cvar_Get("cg_anim", BOTH_RUN1, CVAR_ARCHIVE);
'''
        records = {r.name: r for r in extract_cvars([("codemp/cgame/example.c", source)])}

        # A macro expanding straight to a string literal resolves, and the
        # identifier the source spells is preserved alongside it.
        self.assertEqual(records["sv_master1"].default, "masterjk3.ravensoft.com")
        self.assertEqual(records["sv_master1"].default_macro, "MASTER_SERVER_NAME")
        self.assertIsNone(records["sv_master1"].default_macro_kind)

        # A macro pointing at another macro resolves transitively.
        self.assertEqual(records["saber1"].default, "Kyle")
        self.assertEqual(records["saber1"].default_macro, "DEFAULT_SABER")

        # Adjacent-literal concatenation expands before joining.
        self.assertEqual(records["model"].default, "kyle/default")
        self.assertEqual(records["model"].default_macro, "DEFAULT_MODEL")

        # A numeric macro body is a literal too.
        self.assertEqual(records["cg_shown"].default, "32")

        # Not a literal: keep the identifier and say why, never invent a value.
        self.assertEqual(records["gamedate"].default, "SOURCE_DATE")
        self.assertEqual(records["gamedate"].default_macro_kind, "compiler-builtin")

        # Defined differently per platform: resolving would be a guess.
        self.assertEqual(records["fs_platform"].default, "PLATFORM_PATH")
        self.assertEqual(records["fs_platform"].default_macro_kind, "unresolved-identifier")

        # Undefined here, but visibly an enum constant.
        self.assertEqual(records["cg_anim"].default, "BOTH_RUN1")
        self.assertEqual(records["cg_anim"].default_macro_kind, "enum-constant")

        # Undefined and unclassifiable.
        self.assertEqual(records["cg_missing"].default, "ABSENT_MACRO_NAME")
        self.assertEqual(records["cg_missing"].default_macro_kind, "unresolved-identifier")

        # A quoted string is already the value, even when it looks like a
        # macro: r_drawBuffer really does default to the text "GL_BACK".
        self.assertEqual(records["ui_char_anim"].default, "BOTH_WALK1")
        self.assertIsNone(records["ui_char_anim"].default_macro)
        self.assertIsNone(records["ui_char_anim"].default_macro_kind)

    def test_command_tables_and_forwarded_commands(self) -> None:
        source = r'''
static consoleCommand_t commands[] = {
    { "local", CG_Local_f },
    // { "dead", CG_Dead_f },
};
static const char *gcmds[] = {
    "say",
    // "commented",
    "teamtask",
};
void init(void) {
    Cmd_AddCommand("engine", Engine_f, "Engine command");
    Cmd_AddCommand("colored", Color_f, "Warning " S_COLOR_RED "red");
}
'''
        records = extract_commands([("codemp/cgame/cg_consolecmds.c", source)])
        names = {record.name for record in records}
        self.assertEqual(names, {"local", "say", "teamtask", "engine", "colored"})
        forwarded = next(record for record in records if record.name == "teamtask")
        self.assertIn("sent-to-server", forwarded.gating)

    def test_documented_option_extraction_is_conservative(self) -> None:
        evidence = {"path": "example.cpp", "line": 7}
        values = infer_values(
            "int", [], [], {},
            "Mode: 0: disabled - 1: software - 2: hardware", evidence,
        )
        self.assertEqual([item["value"] for item in values], ["0", "1", "2"])
        self.assertEqual(
            infer_values("int", [], [], {}, "Range 0 - 240", evidence),
            [],
        )
        self.assertIsNone(clean_description("XCVAR_DEF( disabled, 0 )"))
        syntax, _usage = command_syntax(
            "cvarAdd",
            'Com_Printf("^3usage: %s <variable> <value>\\n", Cmd_Argv(0));',
        )
        self.assertEqual(syntax, "cvarAdd <variable> <value>")

    def test_shared_renderer_directory_classification(self) -> None:
        records = extract_cvars([
            ("codemp/rd-common/tr_font.cpp", 'font = Cvar_Get("r_font", "1", CVAR_ARCHIVE);'),
        ])
        self.assertEqual(records[0].module, "renderer")
        self.assertIsNone(records[0].renderer)


if __name__ == "__main__":
    unittest.main()
