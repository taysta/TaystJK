---
title: "cg_chatBox"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBox`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_chatBox` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `10000` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:955](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L955)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2019-02-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`180b40ba0cc1`](https://github.com/eternalcodes/EternalJK/commit/180b40ba0cc1327c8eb50f2e15e94d60541ecfb8)<br>Chatbox/cgame chatlog code cleanup. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2019-07-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7810594c683a`](https://github.com/eternalcodes/EternalJK/commit/7810594c683a50d643a0075ef3f9cd6473dd9ae6)<br>cg_chatSounds 2 will only beep for private and team messages | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`88ad023daf23`](https://github.com/eternalcodes/EternalJK/commit/88ad023daf2331e142902f8a284717f15bbee648)<br>Fix cg_chatSounds 2 setting | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ea53d3689287`](https://github.com/eternalcodes/EternalJK/commit/ea53d36892876a6a13184e6dfa84655185e48ab5)<br>Chatbox Emoji improvements+refactoring+cleanup | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2020-08-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`17c84c9c315e`](https://github.com/eternalcodes/EternalJK/commit/17c84c9c315e4478ae577403c7f337d18fa7da25)<br>Fix chatbox emoji line cutoff? | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:73](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L73) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10660](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10660)
- behavior: [codemp/cgame/cg_draw.c:10687](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10687)
- behavior: [codemp/cgame/cg_draw.c:10982](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10982)
- behavior: [codemp/cgame/cg_draw.c:10762](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10762)
