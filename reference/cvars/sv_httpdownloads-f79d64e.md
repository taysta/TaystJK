---
title: "sv_httpDownloads"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_httpDownloads`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Enables fast HTTP downloads for referenced PK3 files. When enabled, the server advertises either its built-in HTTP endpoint or the external URL configured by sv_httpServerPort to supporting clients.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `mixed` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disable HTTP auto-download advertising and stop the built-in HTTP server. | [codemp/server/sv_init.cpp:763](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L763) |
| `1` | Advertise HTTP downloads and start or redirect the HTTP endpoint. | [codemp/server/sv_init.cpp:763](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L763) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted
- `CVAR_SERVERINFO` — published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- TaystJK integration evidence: [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d)
- Origin pull request: [#169](https://github.com/taysta/TaystJK/pull/169)
- Matching squash bullet: `[HTTP-AutoDL] Libmongoose 7 port from jk2mv`
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits jk2mv.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-03-21` | [2024-03-07](https://github.com/taysta/TaystJK/pull/169) | `2024-03-21` | [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-03-21` | — | `2024-03-21` | [`2a5ea5d885dc`](https://github.com/videoP/jaPRO/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-05-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3beb186e7772`](https://github.com/taysta/TaystJK/commit/3beb186e7772b05e693b96c2d831dd1c1e888fb2) · [PR #197](https://github.com/taysta/TaystJK/pull/197)<br>Autodl fixup (#197) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/server/server.h`, `codemp/server/sv_init.cpp` and 1 more | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:760](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L760) (Cvar_Get)
- behavior: [codemp/server/sv_init.cpp:763](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L763)
- behavior: [codemp/server/sv_main.cpp:579](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L579)
- behavior: [codemp/server/sv_init.cpp:755](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L755)
- behavior: [codemp/client/cl_main.cpp:1707](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1707)
- behavior: [codemp/client/cl_main.cpp:1714](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1714)
