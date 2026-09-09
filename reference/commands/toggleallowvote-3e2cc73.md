---
title: "toggleallowvote"
layout: reference
nav_exclude: true
search_exclude: false
---

# `toggleallowvote`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Svcmd_ToggleAllowVote_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `toggleallowvote [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`bb3ed393a5fb`](https://github.com/JACoders/OpenJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-08-07`, integrated `2014-08-07`)
- Upstream registration evidence: [codemp/game/g_svcmds.c:491](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_svcmds.c#L491)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-08-07` | — | `2014-08-07` | [`bb3ed393a5fb`](https://github.com/JACoders/OpenJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-08-07` | — | `2014-08-07` | [`bb3ed393a5fb`](https://github.com/eternalcodes/EternalJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-08-07` | — | `2014-08-07` | [`bb3ed393a5fb`](https://github.com/SomaZ/OpenJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-08-07` | — | `2014-08-07` | [`bb3ed393a5fb`](https://github.com/taysta/TaystJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-08-07` | — | `2014-08-07` | [`bb3ed393a5fb`](https://github.com/videoP/jaPRO/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-08-07` | — | `2014-08-07` | [`bb3ed393a5fb`](https://github.com/jkanewmod/NewJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-08-07` | — | `2014-08-07` | [`bb3ed393a5fb`](https://github.com/JKSunny/EternalJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_svcmds.c` | `high` |
| `2019-02-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`08ee038fa4de`](https://github.com/eternalcodes/EternalJK/commit/08ee038fa4deede4ad45290f6a7358314d29f3df)<br>Allow onlybhop target_restrict change force jump level with count value, | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_svcmds.c` | `medium` |

## Evidence

- registration: [codemp/game/g_svcmds.c:1709](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1709) (game-console command table)
- handler: [codemp/game/g_cmds.c:3106](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3106)
