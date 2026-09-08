---
title: "sv_snapsMin"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_snapsMin`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

1 <=> sv_snapsMax

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
| `0` | Disabled. | [codemp/server/sv_client.cpp:1227](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1227) |
| `1` | Enabled. | [codemp/server/sv_client.cpp:1227](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1227) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) on `2013-04-27` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/server/sv_init.cpp:979](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L979)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-27` | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-27` | [`9f0123a1e1fd`](https://github.com/eternalcodes/EternalJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-27` | [`9f0123a1e1fd`](https://github.com/SomaZ/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-27` | [`9f0123a1e1fd`](https://github.com/taysta/TaystJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-27` | [`9f0123a1e1fd`](https://github.com/videoP/jaPRO/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-27` | [`9f0123a1e1fd`](https://github.com/jkanewmod/NewJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-27` | [`9f0123a1e1fd`](https://github.com/JKSunny/EternalJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`70a18c64101f`](https://github.com/eternalcodes/EternalJK/commit/70a18c64101f3920bce495bde1c9c3e6ca89a495)<br>Change sv_snapsPolicy default to 2, fix crash with sv_snapsMin/snapsMax set to 0 | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1010](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1010) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:1227](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1227)
- behavior: [codemp/server/sv_main.cpp:1137](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1137)
- behavior: [codemp/server/sv_client.cpp:1226](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1226)
- behavior: [codemp/server/sv_main.cpp:1110](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1110)
- behavior: [codemp/server/sv_main.cpp:1115](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1115)
