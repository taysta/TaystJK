---
title: "fs_game"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_game`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Mod directory

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_SYSTEMINFO` — replicated in systeminfo

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/files_console.cpp:685](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/files_console.cpp#L685)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f9edad82febe`](https://github.com/JACoders/OpenJK/commit/f9edad82febef0b016641a03a77e6d628d448032)<br>Removed cdkey code from mp/client | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_ui.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dcc17314ab11`](https://github.com/JACoders/OpenJK/commit/dcc17314ab1167547f172b0d21788c0ea1ecb760)<br>Removed cd key from mp/qcommon | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp`, `codemp/qcommon/files.cpp`, `codemp/qcommon/files_pc.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e83eda7e823`](https://github.com/JACoders/OpenJK/commit/3e83eda7e823dfaffdece9e782b29d20d7ce117f)<br>Removed cdkey code from mp/server | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_client.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files_console.cpp` | `medium` |
| `2013-04-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4981e49d44d6`](https://github.com/JACoders/OpenJK/commit/4981e49d44d627af1d2061b56f48e9de728bd823)<br>Adds fs_homepath cvar to sp (blank for now).  Some other fs fixes. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_pc.cpp` | `medium` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2013-11-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4)<br>[MP] Migrate files code to a single file. Use long instead of int in some file functions. Security to prevent mods from manipulating dll/so/dylib/pk3. Don't include client.h in every case. | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp`, `codemp/server/sv_snapshot.cpp` | `medium` |
| `2015-01-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c00c4904efbe`](https://github.com/JACoders/OpenJK/commit/c00c4904efbeca1152d105f386a8584d4b76ecb8)<br>[SP] Refactored files code to single file. Breaks compat with older jagame/jospgame modules and older renderer modules for SP/JKS2SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2018-04-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ae94795c1054`](https://github.com/eternalcodes/EternalJK/commit/ae94795c1054dce8a4b8aa1dffabe45afaf09550)<br>Ignore searchpaths outside of base/EternalJK, fs_globalcfg 0 can be set | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2018-12-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`546dfb076f6f`](https://github.com/videoP/jaPRO/commit/546dfb076f6f12d4fc8ebedb8302e7cfa6aad54e)<br>OSX: Fix basepath (japro-assets) not loading from apppath? | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) · [PR #52](https://github.com/taysta/TaystJK/pull/52)<br>Merge pull request #52 from taysta/daggo-fs | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3929](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3929) (Cvar_Get)
- behavior: [codemp/qcommon/files.cpp:3735](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3735)
- behavior: [codemp/qcommon/files.cpp:3975](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3975)
- behavior: [codemp/qcommon/files.cpp:4480](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4480)
- behavior: [codemp/qcommon/files.cpp:4506](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4506)
- behavior: [codemp/qcommon/files.cpp:4629](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4629)
