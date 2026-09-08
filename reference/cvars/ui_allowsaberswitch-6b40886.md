---
title: "ui_allowSaberSwitch"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_allowSaberSwitch`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_allowSaberSwitch` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/ui/ui_main.c:6809](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6809) |
| `1` | Enabled. | [codemp/ui/ui_main.c:6809](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6809) |

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) on `2018-09-10` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:158](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L158)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-10` | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-10` | [`dbfd735d1da2`](https://github.com/taysta/TaystJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-10` | [`dbfd735d1da2`](https://github.com/videoP/jaPRO/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-10` | [`dbfd735d1da2`](https://github.com/JKSunny/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:160](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L160) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:6809](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6809)
- behavior: [codemp/ui/ui_main.c:632](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L632)
- behavior: [codemp/ui/ui_main.c:648](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L648)
- behavior: [codemp/ui/ui_main.c:665](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L665)
