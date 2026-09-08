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
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
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

- Ultimate-origin introduction: [`3a5f856a0bb4`](https://github.com/eternalcodes/EternalJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) on `2015-04-24` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:149](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L149)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/eternalcodes/EternalJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/taysta/TaystJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/videoP/jaPRO/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-24` | [`3a5f856a0bb4`](https://github.com/JKSunny/EternalJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-09-30` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`5b7d8d89e02c`](https://github.com/videoP/jaPRO/commit/5b7d8d89e02c9852395b59575bcd07dde759a368)<br>Remove japro support | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_xcvar.h` | `high` |
| `2017-12-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b0b6ee187247`](https://github.com/videoP/jaPRO/commit/b0b6ee1872471eaed87e815be25d7926199c1181)<br>Revert "Remove japro support" | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_xcvar.h` | `high` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:151](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L151) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:7802](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L7802)
- behavior: [codemp/ui/ui_main.c:7803](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L7803)
