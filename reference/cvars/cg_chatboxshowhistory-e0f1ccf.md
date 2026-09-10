---
title: "cg_chatBoxShowHistory"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBoxShowHistory`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Shows past messages when console is open

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Feature family | Chat box |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L217) |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled (baseJKA behavior) | [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L217) |
| `1` | Enabled | [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L217) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`afb2b659104b`](https://github.com/eternalcodes/EternalJK/commit/afb2b659104bbb636e81388544c43de1bb129028) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-07-29`, integrated `2019-07-29`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:61](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L61)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-07-29` | — | `2019-07-29` | [`afb2b659104b`](https://github.com/eternalcodes/EternalJK/commit/afb2b659104bbb636e81388544c43de1bb129028) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-07-29` | — | `2019-07-29` | [`afb2b659104b`](https://github.com/taysta/TaystJK/commit/afb2b659104bbb636e81388544c43de1bb129028) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-07-29` | — | `2019-07-29` | [`afb2b659104b`](https://github.com/videoP/jaPRO/commit/afb2b659104bbb636e81388544c43de1bb129028) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-07-29` | — | `2019-07-29` | [`afb2b659104b`](https://github.com/JKSunny/EternalJK/commit/afb2b659104bbb636e81388544c43de1bb129028) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ea53d3689287`](https://github.com/eternalcodes/EternalJK/commit/ea53d36892876a6a13184e6dfa84655185e48ab5)<br>Chatbox Emoji improvements+refactoring+cleanup | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:74](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L74) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10980](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10980)
- behavior: [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L217)
- documentation: [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L217)
