---
title: "ui_resolution"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_resolution`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_resolution` in the ui module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`e1abb59c8c45`](https://github.com/eternalcodes/EternalJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) on `2015-06-21` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/ui/ui_main.c:6258](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_main.c#L6258)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-06-21` | [`e1abb59c8c45`](https://github.com/eternalcodes/EternalJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-06-21` | [`e1abb59c8c45`](https://github.com/taysta/TaystJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-06-21` | [`e1abb59c8c45`](https://github.com/videoP/jaPRO/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-06-21` | [`e1abb59c8c45`](https://github.com/JKSunny/EternalJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Shared earliest lineage |

## Evidence

- registration: [codemp/ui/ui_main.c:6343](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6343) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:5924](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L5924)
- behavior: [codemp/ui/ui_main.c:6302](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6302)
- behavior: [codemp/ui/ui_main.c:6304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6304)
- behavior: [codemp/ui/ui_main.c:6307](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6307)
- behavior: [codemp/ui/ui_main.c:6312](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6312)
