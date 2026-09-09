---
title: "cg_teamChatsOnly"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_teamChatsOnly`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Hide non-team chat messages

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:222](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L222) |
| In-game menu | Yes — [setup.menu:2736](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/setup.menu#L2736) |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Show all chat | [codemp/ui/ui_xdocs.h:223](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L223) |
| `1` | Hide global chat from all players | [codemp/ui/ui_xdocs.h:223](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L223) |
| `2` | Hide global chat from spectators while you are in-game (requires compatible server mod) | [codemp/ui/ui_xdocs.h:225](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L225) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:1009](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L1009)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-02-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`180b40ba0cc1`](https://github.com/eternalcodes/EternalJK/commit/180b40ba0cc1327c8eb50f2e15e94d60541ecfb8)<br>Chatbox/cgame chatlog code cleanup. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2019-07-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbc6e7872c2b`](https://github.com/eternalcodes/EternalJK/commit/dbc6e7872c2b238f2515cd52cbd5f6cd6f303f93)<br>Add g_gametype description to xdocs (Artemis) | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:355](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L355) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_servercmds.c:1691](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1691)
- behavior: [codemp/cgame/cg_servercmds.c:1763](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1763)
- behavior: [codemp/ui/ui_xdocs.h:222](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L222)
- documentation: [codemp/ui/ui_xdocs.h:222](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L222)
