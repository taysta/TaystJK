---
title: "cl_chatBubbleSelf"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_chatBubbleSelf`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_chatBubbleSelf` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_input.cpp:1265](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1265) |
| `1` | Enabled. | [codemp/client/cl_input.cpp:1265](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1265) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`86f04849f381`](https://github.com/videoP/jaPRO/commit/86f04849f3811cf7ddbc79a13d19377e5e783665) on `2026-04-19` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#302](https://github.com/taysta/TaystJK/pull/302)
- Upstream registration evidence: [codemp/client/cl_input.cpp:1835](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/client/cl_input.cpp#L1835)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-04-19` | [`86f04849f381`](https://github.com/taysta/TaystJK/commit/86f04849f3811cf7ddbc79a13d19377e5e783665) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-04-19` | [`86f04849f381`](https://github.com/videoP/jaPRO/commit/86f04849f3811cf7ddbc79a13d19377e5e783665) | Ultimate origin |

## Evidence

- registration: [codemp/client/cl_input.cpp:1835](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1835) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1265](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1265)
