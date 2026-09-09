---
title: "ui_sv_pure"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_sv_pure`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_sv_pure` in the ui module. Consult the cited behavior reads before relying on values not listed here.

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

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_NORESTART` — preserved across cvar restart
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-06-13`, integrated `2019-06-13`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:165](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L165)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/taysta/TaystJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/videoP/jaPRO/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/JKSunny/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Shared integration commit |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:167](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L167) (XCVAR_DEF)
- behavior: [codemp/ui/ui_cvar.c:103](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_cvar.c#L103)
- behavior: [codemp/ui/ui_main.c:8936](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8936)
- behavior: [codemp/ui/ui_main.c:8938](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8938)
- behavior: [codemp/ui/ui_main.c:8945](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8945)
- behavior: [codemp/ui/ui_main.c:9829](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9829)
