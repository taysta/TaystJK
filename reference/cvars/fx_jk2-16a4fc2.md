---
title: "fx_jk2"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fx_jk2`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Displays jk2 style projectile fx - 0: Disabled - 1: Enabled

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L119) |
| `1` | Enabled. | [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L119) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`8b353c2103fd`](https://github.com/videoP/jaPRO/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03) on `2025-04-15` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#219](https://github.com/taysta/TaystJK/pull/219)
- Matching squash bullet: `Refactor cl_jk2fx cvar into fx_jk2 - enabled jk2 projectiles fx`
- Upstream registration evidence: [codemp/client/FxUtil.cpp:119](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/client/FxUtil.cpp#L119)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-15` | [`8b353c2103fd`](https://github.com/taysta/TaystJK/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-15` | [`8b353c2103fd`](https://github.com/videoP/jaPRO/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2025-04-16` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`8f46a4c6b4cd`](https://github.com/taysta/TaystJK/commit/8f46a4c6b4cdc2bdbdc54e5c7d8dc1b3b23d2b5a)<br>Check fx_jk2 is registered before trying to access it | Changed an exact bound cvar-variable reference. `codemp/client/FxScheduler.cpp` | `medium` |

## Evidence

- registration: [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L119) (Cvar_Get)
- behavior: [codemp/client/FxScheduler.cpp:464](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxScheduler.cpp#L464)
