---
title: "ui_headCount"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_headCount`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_headCount` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `-1` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`0b9f190a7a4b`](https://github.com/eternalcodes/EternalJK/commit/0b9f190a7a4b85682fcc0f1ff0d15e5a153e1180) on `2019-03-19` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:163](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L163)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-19` | [`0b9f190a7a4b`](https://github.com/eternalcodes/EternalJK/commit/0b9f190a7a4b85682fcc0f1ff0d15e5a153e1180) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-19` | [`0b9f190a7a4b`](https://github.com/taysta/TaystJK/commit/0b9f190a7a4b85682fcc0f1ff0d15e5a153e1180) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-19` | [`0b9f190a7a4b`](https://github.com/videoP/jaPRO/commit/0b9f190a7a4b85682fcc0f1ff0d15e5a153e1180) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-19` | [`0b9f190a7a4b`](https://github.com/JKSunny/EternalJK/commit/0b9f190a7a4b85682fcc0f1ff0d15e5a153e1180) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`452010cb69e8`](https://github.com/eternalcodes/EternalJK/commit/452010cb69e89d0c546144d5373bdb954e90afd5)<br>Add option to list skins that don't belong to another team under default | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:165](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L165) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:8955](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L8955)
- behavior: [codemp/ui/ui_main.c:8959](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L8959)
- behavior: [codemp/ui/ui_main.c:8956](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L8956)
- behavior: [codemp/ui/ui_main.c:8962](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L8962)
