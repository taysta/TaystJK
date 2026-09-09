---
title: "sv_pingFix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_pingFix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Improved scoreboard client ping calculation

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-10-15`, integrated `2018-10-15`)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1026](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_init.cpp#L1026)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: eternaljk retains origin because content authorship and PR submission predate the project that merged the work first. The identifier's single-prefix squash feature group explicitly credits eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2017-09-03` | — | `2017-12-13` | [`c318f53b8b22`](https://github.com/mvdevs/jk2mv/commit/c318f53b8b22e64d301fd19f0abf83613b8f6940) | Other project appearance |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-15` | — | `2018-10-15` | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-15` | — | `2018-10-15` | [`dc3c8171d100`](https://github.com/taysta/TaystJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-15` | — | `2018-10-15` | [`dc3c8171d100`](https://github.com/videoP/jaPRO/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-15` | — | `2018-10-15` | [`dc3c8171d100`](https://github.com/JKSunny/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-05-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`953b37ce8fef`](https://github.com/eternalcodes/EternalJK/commit/953b37ce8fefe7b3345243263f0334975ef59845)<br>kick cheaters | Changed an exact bound cvar-variable reference. `codemp/server/server.h` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1065](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1065) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:1743](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1743)
- behavior: [codemp/server/sv_main.cpp:924](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L924)
- behavior: [codemp/server/sv_client.cpp:1744](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1744)
- behavior: [codemp/server/sv_snapshot.cpp:813](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L813)
- behavior: [codemp/server/sv_client.cpp:1742](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1742)
