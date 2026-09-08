---
title: "con_ratioFix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_ratioFix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Correct console background height, should probably disable for custom console backgrounds.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`952c06842ed0`](https://github.com/eternalcodes/EternalJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) on `2018-10-21` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_console.cpp:541](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L541)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-21` | [`952c06842ed0`](https://github.com/eternalcodes/EternalJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-21` | [`952c06842ed0`](https://github.com/taysta/TaystJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-21` | [`952c06842ed0`](https://github.com/videoP/jaPRO/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-21` | [`952c06842ed0`](https://github.com/JKSunny/EternalJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Shared earliest lineage |

## Evidence

- registration: [codemp/client/cl_console.cpp:659](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L659) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1069](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1069)
