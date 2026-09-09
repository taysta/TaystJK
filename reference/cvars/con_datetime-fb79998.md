---
title: "con_datetime"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_datetime`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Display human readable date/time in console

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
| `0` | Disabled. | [codemp/client/cl_console.cpp:1090](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L1090) |
| `1` | Enabled. | [codemp/client/cl_console.cpp:1090](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L1090) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`837d02412668`](https://github.com/taysta/TaystJK/commit/837d024126688db090380ec8381db2e7b3fd2cb5) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-06-01`, PR opened `2026-06-01`, integrated `2026-06-01`)
- Origin pull request: [#316](https://github.com/taysta/TaystJK/pull/316)
- Upstream registration evidence: [codemp/client/cl_console.cpp:668](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L668)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-06-01` | [2026-06-01](https://github.com/taysta/TaystJK/pull/316) | `2026-06-01` | [`837d02412668`](https://github.com/taysta/TaystJK/commit/837d024126688db090380ec8381db2e7b3fd2cb5) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-06-01` | — | `2026-06-01` | [`837d02412668`](https://github.com/videoP/jaPRO/commit/837d024126688db090380ec8381db2e7b3fd2cb5) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_console.cpp:668](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L668) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1090](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L1090)
