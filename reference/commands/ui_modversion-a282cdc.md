---
title: "ui_modversion"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_modversion`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `UI_Modversion_f` in the ui module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `ui_modversion` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`561b84ebefaf`](https://github.com/eternalcodes/EternalJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) on `2016-02-05` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/ui/ui_atoms.c:319](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_atoms.c#L319)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-02-05` | [`561b84ebefaf`](https://github.com/eternalcodes/EternalJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-02-05` | [`561b84ebefaf`](https://github.com/taysta/TaystJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-02-05` | [`561b84ebefaf`](https://github.com/videoP/jaPRO/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-02-05` | [`561b84ebefaf`](https://github.com/JKSunny/EternalJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-04-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763)<br>Add /strafeHelper, /stylePlayer, and /speedometer commands to UI | Changed the registered command handler. `codemp/ui/ui_atoms.c` | `medium` |
| `2024-01-04` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b4aae0d60465`](https://github.com/taysta/TaystJK/commit/b4aae0d604653021090c08f5a585c3959fcbdabe) · [PR #76](https://github.com/taysta/TaystJK/pull/76)<br>Merge pull request #76 from taysta/change | Changed the registered command handler. `codemp/ui/ui_atoms.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_atoms.c:110](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_atoms.c#L110) (ui command table)
- handler: [codemp/ui/ui_atoms.c:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_atoms.c#L53)
