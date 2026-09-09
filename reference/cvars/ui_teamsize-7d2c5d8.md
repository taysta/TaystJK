---
title: "ui_teamSize"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_teamSize`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_teamSize` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_callvote_japro.menu:832](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_callvote_japro.menu#L832) |
| Default | `3` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`3a5f856a0bb4`](https://github.com/eternalcodes/EternalJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2015-04-24`, integrated `2015-04-24`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:149](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L149)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-24` | — | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/eternalcodes/EternalJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-24` | — | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/taysta/TaystJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-24` | — | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/videoP/jaPRO/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-24` | — | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/JKSunny/EternalJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-09-30` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`5b7d8d89e02c`](https://github.com/videoP/jaPRO/commit/5b7d8d89e02c9852395b59575bcd07dde759a368)<br>Remove japro support | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_xcvar.h` | `high` |
| `2017-12-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b0b6ee187247`](https://github.com/videoP/jaPRO/commit/b0b6ee1872471eaed87e815be25d7926199c1181)<br>Revert "Remove japro support" | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_xcvar.h` | `high` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:151](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L151) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:7802](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L7802)
- behavior: [codemp/ui/ui_main.c:7803](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L7803)
