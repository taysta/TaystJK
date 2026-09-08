---
title: "sv_filterCommands"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_filterCommands`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `sv_filterCommands` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `2` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `2` | Selects the code path tested for value 2. | [codemp/server/sv_client.cpp:1512](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1512) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) on `2013-04-24` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/server/sv_init.cpp:1001](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1001)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/eternalcodes/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/SomaZ/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/taysta/TaystJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/videoP/jaPRO/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/jkanewmod/NewJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JKSunny/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`15c685c83005`](https://github.com/eternalcodes/EternalJK/commit/15c685c830057239017ac08c4a9be5ab8a98c300)<br>Merge pull request #95 from Yberion/serversideEngineFix | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1034](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1034) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:1510](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1510)
- behavior: [codemp/server/sv_client.cpp:1512](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1512)
