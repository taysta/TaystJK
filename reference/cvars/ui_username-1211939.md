---
title: "ui_username"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_username`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_username` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_NORESTART` — preserved across cvar restart

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`c6eb4507a9c5`](https://github.com/eternalcodes/EternalJK/commit/c6eb4507a9c53d8a50b61c37ab72cb3491d41cdf) on `2015-04-27` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:154](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L154)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-27` | [`c6eb4507a9c5`](https://github.com/eternalcodes/EternalJK/commit/c6eb4507a9c53d8a50b61c37ab72cb3491d41cdf) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-27` | [`c6eb4507a9c5`](https://github.com/taysta/TaystJK/commit/c6eb4507a9c53d8a50b61c37ab72cb3491d41cdf) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-27` | [`c6eb4507a9c5`](https://github.com/videoP/jaPRO/commit/c6eb4507a9c53d8a50b61c37ab72cb3491d41cdf) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-27` | [`c6eb4507a9c5`](https://github.com/JKSunny/EternalJK/commit/c6eb4507a9c53d8a50b61c37ab72cb3491d41cdf) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd)<br>Added jcinfo2 to allow UI to only show Race button when relevant | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:156](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L156) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:7806](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L7806)
- behavior: [codemp/ui/ui_main.c:7808](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L7808)
