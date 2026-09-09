---
title: "g_allowRegistration"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_allowRegistration`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_allowRegistration` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
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
| `0` | Disabled. | [codemp/game/g_account.c:3544](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L3544) |
| `1` | Enabled. | [codemp/game/g_account.c:3544](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L3544) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2015-11-17`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:324](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L324)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-11-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-11-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-11-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-11-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c`, `codemp/game/g_cmds.c` | `medium` |
| `2018-09-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd)<br>Added jcinfo2 to allow UI to only show Race button when relevant | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cvar.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2018-09-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`879b06083542`](https://github.com/videoP/jaPRO/commit/879b060835428b28fe2bd771d1ba2a1e8f9fcb65)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cvar.c`, `codemp/game/g_xcvar.h` | `high` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8f30394e6606`](https://github.com/eternalcodes/EternalJK/commit/8f30394e6606502b32d0737274803ce2e4a9f3c6)<br>Fix compile | Changed an exact bound cvar-variable reference. `codemp/game/g_cvar.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:323](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L323) (XCVAR_DEF)
- behavior: [codemp/game/g_account.c:3544](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L3544)
- behavior: [codemp/game/g_account.c:3773](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L3773)
- behavior: [codemp/game/g_cmds.c:5719](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L5719)
- behavior: [codemp/game/g_cmds.c:5725](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L5725)
- behavior: [codemp/game/g_account.c:3422](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L3422)
