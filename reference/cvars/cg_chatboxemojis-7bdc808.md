---
title: "cg_chatBoxEmojis"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBoxEmojis`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_chatBoxEmojis` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_setup.menu:3637](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L3637) |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_main.c:2894](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L2894) |
| `1` | Enabled. | [codemp/cgame/cg_main.c:2894](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L2894) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Ultimate-origin introduction: [`caa8f274580f`](https://github.com/JKSunny/EternalJK/commit/caa8f274580f151f8472d987144146ca02430d3f) in <span class="label ref-origin ref-origin-vulkan">Vulkan</span> (content authored `2020-04-29`, integrated `2020-05-15`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:67](https://github.com/JKSunny/EternalJK/blame/b50059618803346a918f57220f856f1d0651dc39/codemp/cgame/cg_xcvar.h#L67)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits vulkan. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2020-04-29` | — | `2020-05-15` | [`caa8f274580f`](https://github.com/eternalcodes/EternalJK/commit/caa8f274580f151f8472d987144146ca02430d3f) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2020-04-29` | — | `2020-05-15` | [`caa8f274580f`](https://github.com/taysta/TaystJK/commit/caa8f274580f151f8472d987144146ca02430d3f) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2020-04-29` | — | `2020-05-15` | [`caa8f274580f`](https://github.com/videoP/jaPRO/commit/caa8f274580f151f8472d987144146ca02430d3f) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2020-04-29` | — | `2020-05-15` | [`caa8f274580f`](https://github.com/JKSunny/EternalJK/commit/caa8f274580f151f8472d987144146ca02430d3f) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-05-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ef9756779211`](https://github.com/eternalcodes/EternalJK/commit/ef9756779211debb92cc375c0082be376ae3084a)<br>Update CG_LoadEmojis | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ea53d3689287`](https://github.com/eternalcodes/EternalJK/commit/ea53d36892876a6a13184e6dfa84655185e48ab5)<br>Chatbox Emoji improvements+refactoring+cleanup | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2023-11-01` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`8b2ad42d2ad0`](https://github.com/taysta/TaystJK/commit/8b2ad42d2ad0d52f86bbe88e4f1361665c153f9c)<br>Fix various GCC warnings in CGAME. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_main.c` | `medium` |
| `2024-02-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) · [PR #157](https://github.com/taysta/TaystJK/pull/157)<br>Upstream update (#157) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:80](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L80) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_main.c:2894](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L2894)
- behavior: [codemp/cgame/cg_draw.c:10766](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10766)
- behavior: [codemp/cgame/cg_draw.c:10819](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10819)
- behavior: [codemp/cgame/cg_draw.c:11022](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L11022)
- behavior: [codemp/cgame/cg_main.c:2895](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L2895)
