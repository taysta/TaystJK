---
title: "cg_forceOwnSaber"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_forceOwnSaber`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_forceOwnSaber` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `none` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`72143799d75b`](https://github.com/eternalcodes/EternalJK/commit/72143799d75befe6f03d9d834333378a5d1f8168) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-06-12`, integrated `2019-06-12`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:146](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L146)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-06-12` | — | `2019-06-12` | [`72143799d75b`](https://github.com/eternalcodes/EternalJK/commit/72143799d75befe6f03d9d834333378a5d1f8168) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-06-12` | — | `2019-06-12` | [`72143799d75b`](https://github.com/taysta/TaystJK/commit/72143799d75befe6f03d9d834333378a5d1f8168) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-06-12` | — | `2019-06-12` | [`72143799d75b`](https://github.com/videoP/jaPRO/commit/72143799d75befe6f03d9d834333378a5d1f8168) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-06-12` | — | `2019-06-12` | [`72143799d75b`](https://github.com/JKSunny/EternalJK/commit/72143799d75befe6f03d9d834333378a5d1f8168) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:174](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L174) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_cvar.c:259](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_cvar.c#L259)
- behavior: [codemp/cgame/cg_players.c:2384](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L2384)
- behavior: [codemp/cgame/cg_cvar.c:257](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_cvar.c#L257)
- behavior: [codemp/cgame/cg_players.c:2386](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L2386)
- behavior: [codemp/cgame/cg_cvar.c:260](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_cvar.c#L260)
