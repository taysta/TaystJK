---
title: "sv_lanForceRate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_lanForceRate`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `sv_lanForceRate` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-08`, integrated `2013-04-08`)
- Upstream registration evidence: [codemp/server/sv_init.cpp:999](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L999)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-08` | — | `2013-04-08` | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-08` | — | `2013-04-08` | [`9950d594349c`](https://github.com/eternalcodes/EternalJK/commit/9950d594349cfc625be716fa33372a493604a948) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-08` | — | `2013-04-08` | [`9950d594349c`](https://github.com/SomaZ/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-08` | — | `2013-04-08` | [`9950d594349c`](https://github.com/taysta/TaystJK/commit/9950d594349cfc625be716fa33372a493604a948) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-08` | — | `2013-04-08` | [`9950d594349c`](https://github.com/videoP/jaPRO/commit/9950d594349cfc625be716fa33372a493604a948) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-08` | — | `2013-04-08` | [`9950d594349c`](https://github.com/jkanewmod/NewJK/commit/9950d594349cfc625be716fa33372a493604a948) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-08` | — | `2013-04-08` | [`9950d594349c`](https://github.com/JKSunny/EternalJK/commit/9950d594349cfc625be716fa33372a493604a948) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_main.cpp`, `codemp/server/sv_snapshot.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1032](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1032) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:1202](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1202)
- behavior: [codemp/server/sv_main.cpp:1070](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1070)
- behavior: [codemp/server/sv_main.cpp:1090](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1090)
- behavior: [codemp/server/sv_snapshot.cpp:930](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L930)
- behavior: [codemp/server/sv_snapshot.cpp:929](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L929)
