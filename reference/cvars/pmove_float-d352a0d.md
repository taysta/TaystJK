---
title: "pmove_float"
layout: reference
nav_exclude: true
search_exclude: false
---

# `pmove_float`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `pmove_float` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_predict.c:1137](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_predict.c#L1137) |
| `1` | Enabled. | [codemp/cgame/cg_predict.c:1137](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_predict.c#L1137) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_SYSTEMINFO` — replicated in systeminfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) on `2013-05-11` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:158](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/cgame/cg_xcvar.h#L158)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-05-11` | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-05-11` | [`f203e799b14c`](https://github.com/eternalcodes/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-05-11` | [`f203e799b14c`](https://github.com/SomaZ/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-05-11` | [`f203e799b14c`](https://github.com/taysta/TaystJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-05-11` | [`f203e799b14c`](https://github.com/videoP/jaPRO/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-05-11` | [`f203e799b14c`](https://github.com/jkanewmod/NewJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-05-11` | [`f203e799b14c`](https://github.com/JKSunny/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b12414718708`](https://github.com/JACoders/OpenJK/commit/b1241471870888d0e2b7c2613dadcd5da8761ae2)<br>[MP] Improve cvar code a bit further.  Based mostly on zturtleman/spearmint@778bce425a2e6b6860e9d5ec4c7fc736311f9351. With some changes for legacy support still (and extra cvars that should be allowed in mods, if the mods were incorrectly setting them). And also some other misc stuff related to OpenJK specific. | Changed an exact bound cvar-variable reference. `codemp/qcommon/cvar.cpp` | `high` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6551f0ce2a0b`](https://github.com/eternalcodes/EternalJK/commit/6551f0ce2a0bafaa447abcc1795a467a243c12d8)<br>racemode jerkyness tweak? test | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_slidemove.c` | `high` |
| `2023-12-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`06c84155e1fb`](https://github.com/videoP/jaPRO/commit/06c84155e1fb0b3aecfdffd9488d910345d80ea1) · [PR #65](https://github.com/taysta/TaystJK/pull/65)<br>Japro fixup (#65) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:380](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L380) (XCVAR_DEF)
- registration: [codemp/game/g_xcvar.h:173](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L173) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_predict.c:1137](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_predict.c#L1137)
- behavior: [codemp/game/g_active.c:4888](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L4888)
- behavior: [codemp/game/bg_pmove.c:15505](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L15505)
- behavior: [codemp/game/bg_pmove.c:15515](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L15515)
- behavior: [codemp/game/bg_pmove.c:14949](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L14949)
