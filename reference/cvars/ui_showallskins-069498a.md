---
title: "ui_showAllSkins"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_showAllSkins`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_showAllSkins` in the ui module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`452010cb69e8`](https://github.com/eternalcodes/EternalJK/commit/452010cb69e89d0c546144d5373bdb954e90afd5) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-04-11`, integrated `2019-04-11`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:164](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L164)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-04-11` | — | `2019-04-11` | [`452010cb69e8`](https://github.com/eternalcodes/EternalJK/commit/452010cb69e89d0c546144d5373bdb954e90afd5) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-04-11` | — | `2019-04-11` | [`452010cb69e8`](https://github.com/taysta/TaystJK/commit/452010cb69e89d0c546144d5373bdb954e90afd5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-04-11` | — | `2019-04-11` | [`452010cb69e8`](https://github.com/videoP/jaPRO/commit/452010cb69e89d0c546144d5373bdb954e90afd5) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-04-11` | — | `2019-04-11` | [`452010cb69e8`](https://github.com/JKSunny/EternalJK/commit/452010cb69e89d0c546144d5373bdb954e90afd5) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`adaea450a575`](https://github.com/eternalcodes/EternalJK/commit/adaea450a575c60e5e4909df2a2b0bcfc865fa8e)<br>Add default icons for skins with missing icon images. -Artemis | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d53968753a73`](https://github.com/eternalcodes/EternalJK/commit/d53968753a739eb8efb2399e8eae81c288b262c3)<br>Only show missing icons if we want to see them | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_xcvar.h` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:166](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L166) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:8938](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8938)
- behavior: [codemp/ui/ui_main.c:9838](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9838)
- behavior: [codemp/ui/ui_main.c:11328](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L11328)
- behavior: [codemp/ui/ui_main.c:11169](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L11169)
