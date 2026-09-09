---
title: "sv_snapShotDuelCull"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_snapShotDuelCull`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Snapshot-based duel isolation

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/duel_cull.cpp:102](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/duel_cull.cpp#L102) |
| `1` | Enabled. | [codemp/server/duel_cull.cpp:102](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/duel_cull.cpp#L102) |

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`7504815f10f9`](https://github.com/eternalcodes/EternalJK/commit/7504815f10f917215457c6a228aa7b7c8e117192) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-09-11`, integrated `2018-09-11`)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1024](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_init.cpp#L1024)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-11` | — | `2018-09-11` | [`7504815f10f9`](https://github.com/eternalcodes/EternalJK/commit/7504815f10f917215457c6a228aa7b7c8e117192) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-11` | — | `2018-09-11` | [`7504815f10f9`](https://github.com/taysta/TaystJK/commit/7504815f10f917215457c6a228aa7b7c8e117192) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-11` | — | `2018-09-11` | [`7504815f10f9`](https://github.com/videoP/jaPRO/commit/7504815f10f917215457c6a228aa7b7c8e117192) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-11` | — | `2018-09-11` | [`7504815f10f9`](https://github.com/JKSunny/EternalJK/commit/7504815f10f917215457c6a228aa7b7c8e117192) | Shared integration commit |

## Evidence

- registration: [codemp/server/sv_init.cpp:1063](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1063) (Cvar_Get)
- behavior: [codemp/server/duel_cull.cpp:102](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/duel_cull.cpp#L102)
