---
title: "rebuildUnlocks"
layout: reference
nav_exclude: true
search_exclude: false
---

# `rebuildUnlocks`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `SV_RebuildUnlocks_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `rebuildUnlocks` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`239adf14f0b0`](https://github.com/videoP/jaPRO/commit/239adf14f0b06a96f929e6f5a56ce4cb8ef9fd16) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-10`, integrated `2018-09-11`)
- Upstream registration evidence: [codemp/game/g_svcmds.c:1691](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_svcmds.c#L1691)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-10` | — | `2018-09-11` | [`239adf14f0b0`](https://github.com/eternalcodes/EternalJK/commit/239adf14f0b06a96f929e6f5a56ce4cb8ef9fd16) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-10` | — | `2018-09-11` | [`239adf14f0b0`](https://github.com/taysta/TaystJK/commit/239adf14f0b06a96f929e6f5a56ce4cb8ef9fd16) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-10` | — | `2018-09-11` | [`239adf14f0b0`](https://github.com/videoP/jaPRO/commit/239adf14f0b06a96f929e6f5a56ce4cb8ef9fd16) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-10` | — | `2018-09-11` | [`239adf14f0b0`](https://github.com/JKSunny/EternalJK/commit/239adf14f0b06a96f929e6f5a56ce4cb8ef9fd16) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8b3ccefa8978`](https://github.com/videoP/jaPRO/commit/8b3ccefa8978b455ac4ecfb70bd7ac2bf29c28e7)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2018-09-26` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`50d84d540837`](https://github.com/videoP/jaPRO/commit/50d84d54083775a21c419d4f1d511e755eb63e65)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2018-10-22` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`2b816e244108`](https://github.com/videoP/jaPRO/commit/2b816e2441089c3de73a8ad0f66e6a2c52bafe55)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/game/g_svcmds.c:1694](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1694) (game-console command table)
- handler: [codemp/game/g_account.c:1823](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L1823)
