---
title: "con_datetime"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_datetime`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Display human readable date/time in console

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_console.cpp:1090](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1090) |
| `1` | Enabled. | [codemp/client/cl_console.cpp:1090](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1090) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`837d02412668`](https://github.com/taysta/TaystJK/commit/837d024126688db090380ec8381db2e7b3fd2cb5) on `2026-06-01` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#316](https://github.com/taysta/TaystJK/pull/316)
- Upstream registration evidence: [codemp/client/cl_console.cpp:668](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L668)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-06-01` | [`837d02412668`](https://github.com/taysta/TaystJK/commit/837d024126688db090380ec8381db2e7b3fd2cb5) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-06-01` | [`837d02412668`](https://github.com/videoP/jaPRO/commit/837d024126688db090380ec8381db2e7b3fd2cb5) | Shared earliest lineage |

## Evidence

- registration: [codemp/client/cl_console.cpp:668](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L668) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1090](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1090)
