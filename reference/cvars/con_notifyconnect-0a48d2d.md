---
title: "con_notifyconnect"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_notifyconnect`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Notifies you when someone connects to the server

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_cgame.cpp:615](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L615) |
| `1` | Enabled. | [codemp/client/cl_cgame.cpp:615](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L615) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`8fff5e2c8dc2`](https://github.com/eternalcodes/EternalJK/commit/8fff5e2c8dc2a92e8070998bb28ded23ac644b27) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-04-15`, integrated `2016-04-15`)
- Upstream registration evidence: [codemp/client/cl_console.cpp:544](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L544)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-04-15` | — | `2016-04-15` | [`8fff5e2c8dc2`](https://github.com/eternalcodes/EternalJK/commit/8fff5e2c8dc2a92e8070998bb28ded23ac644b27) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-04-15` | — | `2016-04-15` | [`8fff5e2c8dc2`](https://github.com/taysta/TaystJK/commit/8fff5e2c8dc2a92e8070998bb28ded23ac644b27) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-04-15` | — | `2016-04-15` | [`8fff5e2c8dc2`](https://github.com/videoP/jaPRO/commit/8fff5e2c8dc2a92e8070998bb28ded23ac644b27) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-04-15` | — | `2016-04-15` | [`8fff5e2c8dc2`](https://github.com/JKSunny/EternalJK/commit/8fff5e2c8dc2a92e8070998bb28ded23ac644b27) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`00588c8f6da8`](https://github.com/eternalcodes/EternalJK/commit/00588c8f6da89586c2b12a2cfe321eabe7071bd2)<br>Better fix for verbose/fs_debug logging option | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1379d10d1d14`](https://github.com/eternalcodes/EternalJK/commit/1379d10d1d14941746bae18edd287ff621c8c9c4)<br>Fix con_notifyconnect condition | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`55d350a25827`](https://github.com/eternalcodes/EternalJK/commit/55d350a258277bc7312ce89bcc00e173455129ac)<br>con_notifynames -1 blinks for every chat msg https://github.com/eternalcodes/EternalJK/issues/66 | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `high` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9b5228bcfe2f`](https://github.com/eternalcodes/EternalJK/commit/9b5228bcfe2f7a054365fa28ca1b83eee44b82a7)<br>Move engine chatlogging to chat cmd, instead of scanning console Start of fix for con_notifyname https://github.com/eternalcodes/EternalJK/issues/53, https://github.com/eternalcodes/EternalJK/issues/52 | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp`, `codemp/client/cl_console.cpp` | `high` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b9e48ef6bd40`](https://github.com/eternalcodes/EternalJK/commit/b9e48ef6bd405d14bc7014ea1498b6a50a1d88c1)<br>Fix timestamp colors | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ede80a39ef3f`](https://github.com/eternalcodes/EternalJK/commit/ede80a39ef3f290fb56a4d80bcf6ebf26722a815)<br>Notifyconnect fix? | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2018-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e689fdabde75`](https://github.com/eternalcodes/EternalJK/commit/e689fdabde75b870d5ec2ce342fbb18ea59e1861)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2018-05-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`097a0d05fa4e`](https://github.com/eternalcodes/EternalJK/commit/097a0d05fa4edb25c14bf88d42ea2bff668fd232)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:662](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L662) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:615](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L615)
