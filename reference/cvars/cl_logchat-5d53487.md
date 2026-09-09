---
title: "cl_logChat"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_logChat`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Toggle engine chat logs

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `2` | Selects the code path tested for value 2. | [codemp/client/cl_cgame.cpp:782](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L782) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`b8696a7ad9f9`](https://github.com/eternalcodes/EternalJK/commit/b8696a7ad9f93b7dc3e4db632fbd16cf0e4b61f3) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-03-25`, integrated `2016-03-25`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3357](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3357)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-25` | — | `2016-03-25` | [`b8696a7ad9f9`](https://github.com/eternalcodes/EternalJK/commit/b8696a7ad9f93b7dc3e4db632fbd16cf0e4b61f3) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-25` | — | `2016-03-25` | [`b8696a7ad9f9`](https://github.com/taysta/TaystJK/commit/b8696a7ad9f93b7dc3e4db632fbd16cf0e4b61f3) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-25` | — | `2016-03-25` | [`b8696a7ad9f9`](https://github.com/videoP/jaPRO/commit/b8696a7ad9f93b7dc3e4db632fbd16cf0e4b61f3) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-25` | — | `2016-03-25` | [`b8696a7ad9f9`](https://github.com/JKSunny/EternalJK/commit/b8696a7ad9f93b7dc3e4db632fbd16cf0e4b61f3) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-04-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`cc95a484132f`](https://github.com/eternalcodes/EternalJK/commit/cc95a484132f02cdf1f95e7abf47d49f809aa12f)<br>Added cvar cl_afkTimeUnfocused, Added Cvar/Cmd descriptions This will allow you to set the amount of minutes to autorename to afk while the jka window is unfocused or minimized. The default is 1 minute. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`135f109285cb`](https://github.com/eternalcodes/EternalJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a)<br>Added con_scale from JK2MV. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6e955a7e1e61`](https://github.com/eternalcodes/EternalJK/commit/6e955a7e1e6143f8fce3a6e0c1c1855b3a4d2b9b)<br>chatlog fix | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ecf5e7eb6bae`](https://github.com/eternalcodes/EternalJK/commit/ecf5e7eb6bae37f9e2202facf0e766cad43c07c5)<br>Better chatlog format https://github.com/eternalcodes/EternalJK/issues/35 | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `high` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `high` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803)<br>Implement Blackwolf's Discord Integration | Changed an exact bound cvar-variable reference. `codemp/client/client.h` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c55cb9d28c23`](https://github.com/eternalcodes/EternalJK/commit/c55cb9d28c231c78a01be32ad62094f7f67f9c4f)<br>Engine chat logging - don't log "end log" message until something has been logged | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268)<br>chat styles | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3456](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3456) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:563](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L563)
- behavior: [codemp/client/cl_cgame.cpp:700](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L700)
- behavior: [codemp/client/cl_cgame.cpp:773](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L773)
- behavior: [codemp/client/cl_cgame.cpp:782](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L782)
