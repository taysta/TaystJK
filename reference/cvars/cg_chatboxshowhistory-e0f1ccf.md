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
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled (baseJKA behavior) | [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217) |
| `1` | Enabled | [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`afb2b659104b`](https://github.com/eternalcodes/EternalJK/commit/afb2b659104bbb636e81388544c43de1bb129028) on `2019-07-29` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:61](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L61)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-07-29` | [`afb2b659104b`](https://github.com/eternalcodes/EternalJK/commit/afb2b659104bbb636e81388544c43de1bb129028) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-07-29` | [`afb2b659104b`](https://github.com/taysta/TaystJK/commit/afb2b659104bbb636e81388544c43de1bb129028) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-07-29` | [`afb2b659104b`](https://github.com/videoP/jaPRO/commit/afb2b659104bbb636e81388544c43de1bb129028) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-07-29` | [`afb2b659104b`](https://github.com/JKSunny/EternalJK/commit/afb2b659104bbb636e81388544c43de1bb129028) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ea53d3689287`](https://github.com/eternalcodes/EternalJK/commit/ea53d36892876a6a13184e6dfa84655185e48ab5)<br>Chatbox Emoji improvements+refactoring+cleanup | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:74](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L74) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10980)
- behavior: [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217)
- documentation: [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217)
