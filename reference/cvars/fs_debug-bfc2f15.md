---
title: "fs_debug"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_debug`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `fs_debug` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/qcommon/files.cpp:869](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L869) |
| `1` | Enabled. | [codemp/qcommon/files.cpp:869](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L869) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/files_console.cpp:681](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/files_console.cpp#L681)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files_console.cpp` | `medium` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2013-11-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4)<br>[MP] Migrate files code to a single file. Use long instead of int in some file functions. Security to prevent mods from manipulating dll/so/dylib/pk3. Don't include client.h in every case. | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2015-01-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c00c4904efbe`](https://github.com/JACoders/OpenJK/commit/c00c4904efbeca1152d105f386a8584d4b76ecb8)<br>[SP] Refactored files code to single file. Breaks compat with older jagame/jospgame modules and older renderer modules for SP/JKS2SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2018-02-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8a3b2a103496`](https://github.com/eternalcodes/EternalJK/commit/8a3b2a103496fd2963486763c68b24c22dec3da3)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`00588c8f6da8`](https://github.com/eternalcodes/EternalJK/commit/00588c8f6da89586c2b12a2cfe321eabe7071bd2)<br>Better fix for verbose/fs_debug logging option | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`eae527f62504`](https://github.com/eternalcodes/EternalJK/commit/eae527f62504cbf1daf6cac23d388004bb546b91)<br>Only show PK3 list if fs_debug is 1 https://github.com/eternalcodes/EternalJK/issues/65 | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a)<br>Merge pull request #97 from aufau/ratelimiter | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2024-01-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d36aa60aa802`](https://github.com/taysta/TaystJK/commit/d36aa60aa80205f94b57c9221c32945383f16185) · [PR #66](https://github.com/taysta/TaystJK/pull/66)<br>Defrag racemode demo prerecording fixups (#66) | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3908](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3908) (Cvar_Get)
- behavior: [codemp/qcommon/files.cpp:869](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L869)
- behavior: [codemp/qcommon/files.cpp:912](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L912)
- behavior: [codemp/qcommon/files.cpp:958](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L958)
- behavior: [codemp/qcommon/files.cpp:974](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L974)
- behavior: [codemp/qcommon/files.cpp:996](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L996)
