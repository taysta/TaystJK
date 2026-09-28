---
title: "ui_browserFilterInvalidInfo"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_browserFilterInvalidInfo`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is internal UI/engine state, hidden from every cvar listing (<code>CVAR_INTERNAL</code>).</p>

Controls `ui_browserFilterInvalidInfo` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Manually settable | No; the game writes this value. |
| Cheat protected | No |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Category | Server & networking |
| Feature family | Server browser |
| Module | `ui` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2014-05-07 in [`938464848`](https://github.com/taysta/TaystJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/ui/ui_main.c:9156](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_main.c#L9156) |
| `1` | Enabled. | [codemp/ui/ui_main.c:9156](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_main.c#L9156) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration
- `CVAR_INTERNAL`: internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9384648488c0`](https://github.com/JACoders/OpenJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-05-08`, integrated `2014-05-08`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:57](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/ui/ui_xcvar.h#L57)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-05-08` | — | `2014-05-08` | [`9384648488c0`](https://github.com/JACoders/OpenJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-05-08` | — | `2014-05-08` | [`9384648488c0`](https://github.com/eternalcodes/EternalJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-05-08` | — | `2014-05-08` | [`9384648488c0`](https://github.com/SomaZ/OpenJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-05-08` | — | `2014-05-08` | [`9384648488c0`](https://github.com/taysta/TaystJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-05-08` | — | `2014-05-08` | [`9384648488c0`](https://github.com/videoP/jaPRO/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-05-08` | — | `2014-05-08` | [`9384648488c0`](https://github.com/jkanewmod/NewJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-05-08` | — | `2014-05-08` | [`9384648488c0`](https://github.com/JKSunny/EternalJK/commit/9384648488c06d42a7498256cdeeca2e13ae19ed) | Shared integration commit |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:62](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xcvar.h#L62) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:9156](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_main.c#L9156)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/b35ed06fec41c53644352743c6b199a5d5d500f3"><code>b35ed06fec41</code></a> on 2026-09-27. Anything merged after that is not reflected here.</p>
