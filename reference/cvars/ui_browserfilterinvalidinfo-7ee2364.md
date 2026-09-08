---
title: "ui_browserFilterInvalidInfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_browserFilterInvalidInfo`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_browserFilterInvalidInfo` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/ui/ui_main.c:9156](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L9156) |
| `1` | Enabled. | [codemp/ui/ui_main.c:9156](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L9156) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9384648488c0`](https://github.com/JACoders/OpenJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) on `2014-05-08` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:57](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/ui/ui_xcvar.h#L57)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-05-08` | [`9384648488c0`](https://github.com/JACoders/OpenJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-05-08` | [`9384648488c0`](https://github.com/eternalcodes/EternalJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-05-08` | [`9384648488c0`](https://github.com/SomaZ/OpenJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-05-08` | [`9384648488c0`](https://github.com/taysta/TaystJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-05-08` | [`9384648488c0`](https://github.com/videoP/jaPRO/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-05-08` | [`9384648488c0`](https://github.com/jkanewmod/NewJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-05-08` | [`9384648488c0`](https://github.com/JKSunny/EternalJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared earliest lineage |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:62](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L62) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:9156](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L9156)
