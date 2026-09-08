---
title: "sv_minRate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_minRate`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Min bandwidth rate allowed on server. Use 0 for unlimited.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_snapshot.cpp:773](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L773) |
| `1` | Enabled. | [codemp/server/sv_snapshot.cpp:773](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L773) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_SERVERINFO` — published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`6aba69055e45`](https://github.com/JACoders/OpenJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4) on `2017-05-16` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)
- Upstream registration evidence: [codemp/server/sv_init.cpp:961](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L961)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk.

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
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2020-03-07` | [`ec128dd15cd4`](https://github.com/mvdevs/jk2mv/commit/ec128dd15cd4baebfb78b5097f4ca14738f48456) | Later project appearance |

## Evidence

- registration: [codemp/server/sv_init.cpp:992](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L992) (Cvar_Get)
- behavior: [codemp/server/sv_snapshot.cpp:773](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L773)
- behavior: [codemp/server/sv_snapshot.cpp:774](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L774)
- behavior: [codemp/server/sv_snapshot.cpp:777](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L777)
- behavior: [codemp/server/sv_client.cpp:1218](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1218)
- behavior: [codemp/server/sv_main.cpp:1099](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1099)
