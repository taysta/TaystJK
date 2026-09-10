---
title: "fx_jk2"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fx_jk2`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Displays jk2 style projectile fx - 0: Disabled - 1: Enabled

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/FxUtil.cpp#L119) |
| `1` | Enabled. | [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/FxUtil.cpp#L119) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`8b353c2103fd`](https://github.com/taysta/TaystJK/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2025-04-15`, PR opened `2025-04-07`, integrated `2025-04-15`)
- Origin pull request: [#219](https://github.com/taysta/TaystJK/pull/219)
- Matching squash bullet: `Refactor cl_jk2fx cvar into fx_jk2 - enabled jk2 projectiles fx`
- Upstream registration evidence: [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/FxUtil.cpp#L119)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-15` | [2025-04-07](https://github.com/taysta/TaystJK/pull/219) | `2025-04-15` | [`8b353c2103fd`](https://github.com/taysta/TaystJK/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-15` | — | `2025-04-15` | [`8b353c2103fd`](https://github.com/videoP/jaPRO/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2025-04-16` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`8f46a4c6b4cd`](https://github.com/taysta/TaystJK/commit/8f46a4c6b4cdc2bdbdc54e5c7d8dc1b3b23d2b5a)<br>Check fx_jk2 is registered before trying to access it | Changed an exact bound cvar-variable reference. `codemp/client/FxScheduler.cpp` | `medium` |

## Evidence

- registration: [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/FxUtil.cpp#L119) (Cvar_Get)
- behavior: [codemp/client/FxScheduler.cpp:464](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/FxScheduler.cpp#L464)
