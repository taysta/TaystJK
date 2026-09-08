---
title: "flagAccount"
layout: reference
nav_exclude: true
search_exclude: false
---

# `flagAccount`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Svcmd_FlagAccount_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `flagAccount <username> <set (optional)> <flag>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3) on `2018-11-04` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/game/g_svcmds.c:1645](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/game/g_svcmds.c#L1645)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-11-04` | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-11-04` | [`ad634ee5d2ff`](https://github.com/taysta/TaystJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-11-04` | [`ad634ee5d2ff`](https://github.com/videoP/jaPRO/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-11-04` | [`ad634ee5d2ff`](https://github.com/JKSunny/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-11-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a84c41a53dab`](https://github.com/videoP/jaPRO/commit/a84c41a53dab98f496eea9045bfa142eb8fbc6bd)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2020-05-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cf5f50918b74`](https://github.com/taysta/TaystJK/commit/cf5f50918b744e1f99f36241ca1df889ce0514b6) · [PR #125](https://github.com/taysta/TaystJK/pull/125)<br>Small fixes (#125) | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |

## Evidence

- registration: [codemp/game/g_svcmds.c:1674](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_svcmds.c#L1674) (game-console command table)
- handler: [codemp/game/g_account.c:2862](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L2862)
