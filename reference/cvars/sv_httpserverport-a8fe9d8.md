---
title: "sv_httpServerPort"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_httpServerPort`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Configures the HTTP auto-download endpoint. A numeric value selects the built-in web server's port; a value beginning with http:// advertises that external base URL instead.

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
| Value type | `string` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

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
| `2024-05-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3beb186e7772`](https://github.com/taysta/TaystJK/commit/3beb186e7772b05e693b96c2d831dd1c1e888fb2) · [PR #197](https://github.com/taysta/TaystJK/pull/197)<br>Autodl fixup (#197) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/server/server.h`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:761](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L761) (Cvar_Get)
- behavior: [codemp/server/sv_init.cpp:764](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L764)
- behavior: [codemp/server/sv_main.cpp:580](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L580)
- behavior: [codemp/server/sv_init.cpp:765](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L765)
- behavior: [codemp/server/sv_init.cpp:767](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L767)
- behavior: [codemp/server/sv_main.cpp:581](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L581)
