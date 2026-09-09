---
title: "listip"
layout: reference
nav_exclude: true
search_exclude: false
---

# `listip`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Svcmd_ListIP_f` in the game module.

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
| Syntax | `listip` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-04`, integrated `2013-04-07`)
- Upstream registration evidence: [codemp/game/g_svcmds.c:488](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_svcmds.c#L488)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-04` | — | `2013-04-07` | [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-04` | — | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-04` | — | `2013-04-07` | [`14cea1563762`](https://github.com/SomaZ/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-04` | — | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-04` | — | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-04` | — | `2013-04-07` | [`14cea1563762`](https://github.com/jkanewmod/NewJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-04` | — | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-11-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`03e8231c183e`](https://github.com/JACoders/OpenJK/commit/03e8231c183ef3208e54acaccb73288d33a14de1)<br>[MP] Make g_svcmds use bsearch method for commands. Improve listip command. Improve ded server say cmd. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_svcmds.c` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`66a3ee395159`](https://github.com/JACoders/OpenJK/commit/66a3ee3951598dde11d9217d9851bf59b5b9b92e)<br>[MP] Fix some gcc warnings. Improve byte aliasing code | Changed the registered command handler. `codemp/game/g_svcmds.c` | `medium` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed the registered command handler. `codemp/game/g_svcmds.c` | `medium` |

## Evidence

- registration: [codemp/game/g_svcmds.c:1681](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1681) (game-console command table)
- handler: [codemp/game/g_svcmds.c:287](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L287)
