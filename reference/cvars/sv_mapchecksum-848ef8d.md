---
title: "sv_mapChecksum"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_mapChecksum`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ckSum` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-server` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM` — read-only after registration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `` | `engine-server` | `—` | `always` |
| `` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/server/sv_init.cpp:500](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/server/sv_init.cpp#L500)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61779788b020`](https://github.com/JACoders/OpenJK/commit/61779788b0207e43c974b10b79dfba4709369636)<br>Botlib improvements. Moved some botlib headers to the botlib folder | Changed an exact bound cvar-variable reference. `codemp/botlib/botlib.h` | `medium` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bb29d3a516fb`](https://github.com/JACoders/OpenJK/commit/bb29d3a516fbc8f6dd8ca30864df3bd8b5ffea65)<br>Finished up most of the code now for the modular SP renderer. The things I need to fix still: - Some undefined externals - Some of the imports - The whole DLL import routine - Actual testing (???) Should be done by the end of this weekend, hopefully. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_main.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp`, `code/server/sv_init.cpp` | `medium` |

## Evidence

- registration: [codemp/game/g_main.c:412](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L412) (Cvar_Register)
- registration: [codemp/game/g_main.c:3373](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3373) (Cvar_Register)
- registration: [codemp/server/sv_init.cpp:1031](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1031) (Cvar_Get)
- behavior: [codemp/game/g_main.c:3390](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3390)
- behavior: [codemp/game/g_main.c:414](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L414)
- behavior: [codemp/game/sqlite3.c:41949](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/sqlite3.c#L41949)
- behavior: [codemp/game/g_main.c:3379](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3379)
- behavior: [codemp/game/g_main.c:3392](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3392)
