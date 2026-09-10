---
title: "ui_browserShowPasswordProtected"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_browserShowPasswordProtected`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_browserShowPasswordProtected` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Feature family | Server browser |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/ui/ui_main.c:9181](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9181) |
| `1` | Enabled. | [codemp/ui/ui_main.c:9181](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9181) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-09-28`, integrated `2013-09-28`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:60](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/ui/ui_xcvar.h#L60)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-09-28` | — | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-09-28` | — | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/eternalcodes/EternalJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-09-28` | — | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/SomaZ/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-09-28` | — | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/taysta/TaystJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-09-28` | — | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/videoP/jaPRO/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-09-28` | — | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/jkanewmod/NewJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-09-28` | — | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/JKSunny/EternalJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2ca29aebe0e9`](https://github.com/JACoders/OpenJK/commit/2ca29aebe0e9b6eddc6d754b36ea850b23c83517)<br>[MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:65](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L65) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:9181](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9181)
- behavior: [codemp/ui/ui_main.c:9183](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9183)
