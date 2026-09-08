---
title: "rHardest"
layout: reference
nav_exclude: true
search_exclude: false
---

# `rHardest`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `rHardest <style (optional)> <current season (optional - example: s) <page (optional)>. This displays hardest completed courses for the specified style` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) on `2018-02-05` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2375](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2375)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-02-05` | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-02-05` | [`675e97128f48`](https://github.com/taysta/TaystJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-02-05` | [`675e97128f48`](https://github.com/videoP/jaPRO/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-02-05` | [`675e97128f48`](https://github.com/JKSunny/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`bd2baec5d0cb`](https://github.com/eternalcodes/EternalJK/commit/bd2baec5d0cbef6f2908d4f9777f7880e444d772)<br>error print fix | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e9cc9f99e33c`](https://github.com/eternalcodes/EternalJK/commit/e9cc9f99e33cf51323270505b0c76cbf1b33dc8f)<br>database error prints to console | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2024-01-10` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`90d3c68f2da9`](https://github.com/videoP/jaPRO/commit/90d3c68f2da918f353b24bff60e49066dd018806) · [PR #84](https://github.com/taysta/TaystJK/pull/84)<br>Japro update (#84) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2024-02-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`391790395694`](https://github.com/videoP/jaPRO/commit/391790395694e26a8ad9ab2ef6e2bd9f22710ecd) · [PR #145](https://github.com/taysta/TaystJK/pull/145)<br>Japro update (#145) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2026-06-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`ca5625290071`](https://github.com/videoP/jaPRO/commit/ca5625290071860c03fbda26bf6082dfa47a0df0) · [PR #319](https://github.com/taysta/TaystJK/pull/319)<br>Merge pull request #319 from taysta/japro-up | Changed the registered command handler. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2700](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2700) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9027](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L9027) (game command table)
- handler: [codemp/game/g_account.c:5857](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L5857)
