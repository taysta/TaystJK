---
title: "help"
layout: reference
nav_exclude: true
search_exclude: false
---

# `help`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Print command help

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `help [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`55d9184d89f7`](https://github.com/JACoders/OpenJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2016-03-22`, integrated `2016-03-22`)
- TaystJK integration evidence: [`c9c6ab99fdd2`](https://github.com/taysta/TaystJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)
- Upstream registration evidence: [codemp/qcommon/cmd.cpp:984](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/cmd.cpp#L984)
- Attribution method: `shared-integration-explicit-credit`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2016-03-22` | — | `2016-03-22` | [`55d9184d89f7`](https://github.com/JACoders/OpenJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2016-03-22` | — | `2016-03-22` | [`55d9184d89f7`](https://github.com/SomaZ/OpenJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/taysta/TaystJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/videoP/jaPRO/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/JKSunny/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/cmd.cpp` | `medium` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c`, `codemp/qcommon/cmd.cpp` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2506](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2506) (cgame command table)
- registration: [codemp/qcommon/cmd.cpp:1208](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cmd.cpp#L1208) (Cmd_AddCommand)
- handler: [codemp/cgame/cg_consolecmds.c:537](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L537)
- handler: [codemp/qcommon/cmd.cpp:1151](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cmd.cpp#L1151)
