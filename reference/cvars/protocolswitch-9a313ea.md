---
title: "protocolswitch"
layout: reference
nav_exclude: true
search_exclude: false
---

# `protocolswitch`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Sets protocol based on server info response

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
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
| `0` | Selects the code path tested for value 0. | [codemp/client/cl_main.cpp:1783](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1783) |
| `2` | Selects the code path tested for value 2. | [codemp/client/cl_main.cpp:335](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L335) |

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_NORESTART` — preserved across cvar restart
- `CVAR_PROTECTED` — protected from unsafe remote changes
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- TaystJK integration evidence: [`a983fa494fee`](https://github.com/taysta/TaystJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits jk2mv.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-26` | — | `2018-04-26` | [`a983fa494fee`](https://github.com/eternalcodes/EternalJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-04-26` | — | `2018-04-26` | [`a983fa494fee`](https://github.com/taysta/TaystJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-04-26` | — | `2018-04-26` | [`a983fa494fee`](https://github.com/videoP/jaPRO/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-26` | — | `2018-04-26` | [`a983fa494fee`](https://github.com/JKSunny/EternalJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2018-04-26` | — | `2020-04-02` | [`007750b49b3b`](https://github.com/jkanewmod/NewJK/commit/007750b49b3bfff586199e126ebdc4d90ba515d1) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-05-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`097a0d05fa4e`](https://github.com/eternalcodes/EternalJK/commit/097a0d05fa4edb25c14bf88d42ea2bff668fd232)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2018-10-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`952c06842ed0`](https://github.com/eternalcodes/EternalJK/commit/952c06842ed0717365fb37927585d6498e7a77a0)<br>Remove custom widescreen console background, now fixed with con_ratioFix | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2018-11-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`418f3e1fcc29`](https://github.com/eternalcodes/EternalJK/commit/418f3e1fcc29e35e3535604041949a71e97207ee)<br>Check engine support for new renderfx flags, use old behavior if necessary | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_main.c` | `medium` |
| `2026-08-13` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`5802c999168d`](https://github.com/taysta/TaystJK/commit/5802c999168db2f9759a48f1ef3a3d672fa99722) · [PR #366](https://github.com/taysta/TaystJK/pull/366)<br>Merge pull request #366 from taysta/pure-fix | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3335](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3335) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:335](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L335)
- behavior: [codemp/client/cl_main.cpp:1783](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1783)
- behavior: [codemp/client/cl_main.cpp:1794](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1794)
- behavior: [codemp/qcommon/files.cpp:4170](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4170)
- behavior: [codemp/cgame/cg_main.c:3173](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L3173)
