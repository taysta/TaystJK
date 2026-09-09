---
title: "ui_r_fullBright"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_r_fullBright`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_r_fullBright` in the ui module. Consult the cited behavior reads before relying on values not listed here.

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

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- TaystJK integration evidence: [`d93386f34b71`](https://github.com/taysta/TaystJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits rend2.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/eternalcodes/EternalJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/taysta/TaystJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/videoP/jaPRO/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/JKSunny/EternalJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Other project appearance |

## Evidence

- registration: [codemp/ui/ui_main.c:6362](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6362) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:6235](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6235)
- behavior: [codemp/ui/ui_main.c:6407](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6407)
