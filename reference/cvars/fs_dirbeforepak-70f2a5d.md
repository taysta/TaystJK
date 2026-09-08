---
title: "fs_dirbeforepak"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_dirbeforepak`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Prioritize directories before paks if not pure

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/qcommon/files.cpp:2961](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/qcommon/files.cpp#L2961)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp`, `codemp/qcommon/files_pc.cpp` | `high` |
| `2013-11-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4)<br>[MP] Migrate files code to a single file. Use long instead of int in some file functions. Security to prevent mods from manipulating dll/so/dylib/pk3. Don't include client.h in every case. | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2015-01-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c00c4904efbe`](https://github.com/JACoders/OpenJK/commit/c00c4904efbeca1152d105f386a8584d4b76ecb8)<br>[SP] Refactored files code to single file. Breaks compat with older jagame/jospgame modules and older renderer modules for SP/JKS2SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3931](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3931) (Cvar_Get)
- behavior: [codemp/qcommon/files.cpp:3468](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3468)
- behavior: [codemp/qcommon/files.cpp:4410](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L4410)
