---
title: "sv_snapsPolicy"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_snapsPolicy`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Determines which policy of enforcement is used for client's \"snaps\" cvar

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `2` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/server/sv_client.cpp:1233](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1233) |
| `2` | Selects the code path tested for value 2. | [codemp/server/sv_client.cpp:1243](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1243) |

## Enforced ranges

- `0` through `2` (integer; Cvar_CheckRange) — [codemp/server/sv_init.cpp:1013](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1013)

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`6aba69055e45`](https://github.com/JACoders/OpenJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4) on `2017-05-16` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)
- Upstream registration evidence: [codemp/server/sv_init.cpp:981](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L981)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2017-05-16` | [`6aba69055e45`](https://github.com/JACoders/OpenJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2017-05-16` | [`6aba69055e45`](https://github.com/SomaZ/OpenJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/eternalcodes/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/videoP/jaPRO/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/JKSunny/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/server.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` and 1 more | `medium` |
| `2019-02-03` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`52f85bb57c06`](https://github.com/taysta/TaystJK/commit/52f85bb57c06d6683c939b5de0cef66b4137b17d)<br>Don't discard userinfo changes, only postpone them (from JK2MV) | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`70a18c64101f`](https://github.com/eternalcodes/EternalJK/commit/70a18c64101f3920bce495bde1c9c3e6ca89a495)<br>Change sv_snapsPolicy default to 2, fix crash with sv_snapsMin/snapsMax set to 0 | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1012](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1012) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:1233](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1233)
- behavior: [codemp/server/sv_client.cpp:1243](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1243)
- behavior: [codemp/server/sv_main.cpp:1119](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1119)
- behavior: [codemp/server/sv_main.cpp:1133](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1133)
- behavior: [codemp/server/sv_main.cpp:1112](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1112)
