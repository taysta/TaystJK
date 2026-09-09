---
title: "g_showHealth"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_showHealth`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Show healthbars above players heads when aimed at. Requires map restart.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-02-01`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:282](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L282)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-02-01` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-02-01` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-02-01` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-02-01` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`33d933ca5f12`](https://github.com/eternalcodes/EternalJK/commit/33d933ca5f122abf278f8f6fefc5607c5f2c3b20)<br>rtop season support / rtop rewrite / rtop fix | Changed an exact bound cvar-variable reference. `codemp/game/g_cvar.c` | `medium` |
| `2024-01-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b5dff40126c7`](https://github.com/videoP/jaPRO/commit/b5dff40126c7922718f6b2ebb359463b8af78205) · [PR #82](https://github.com/taysta/TaystJK/pull/82)<br>Japro update (#82) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cvar.c`, `codemp/game/g_xcvar.h` | `high` |
| `2024-01-10` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`90d3c68f2da9`](https://github.com/videoP/jaPRO/commit/90d3c68f2da918f353b24bff60e49066dd018806) · [PR #84](https://github.com/taysta/TaystJK/pull/84)<br>Japro update (#84) | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `high` |
| `2024-03-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9912f30e367f`](https://github.com/taysta/TaystJK/commit/9912f30e367f9857bb65dc3047f77fd1b325ad4b) · [PR #166](https://github.com/taysta/TaystJK/pull/166)<br>Japro update (#166) | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c` | `medium` |
| `2024-05-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`13eac340e1ce`](https://github.com/videoP/jaPRO/commit/13eac340e1ce2e81ab6cbb47e21d984892a78c2a) · [PR #193](https://github.com/taysta/TaystJK/pull/193)<br>Japro update (#193) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c`, `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:281](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L281) (XCVAR_DEF)
- behavior: [codemp/game/g_client.c:4215](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L4215)
- behavior: [codemp/game/g_active.c:4496](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L4496)
- behavior: [codemp/game/g_cmds.c:4397](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L4397)
- behavior: [codemp/game/g_cmds.c:8290](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8290)
- behavior: [codemp/game/g_cvar.c:536](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cvar.c#L536)
- documentation: [docs/japro_docs.md:93](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L93)
