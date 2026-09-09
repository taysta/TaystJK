---
title: "cl_discordRichPresenceSharePassword"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_discordRichPresenceSharePassword`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

If set, sends password to Discord friends who request to join your game

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`53b43cd32500`](https://github.com/eternalcodes/EternalJK/commit/53b43cd32500dfc4544b7213f14e69064037acfb) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-03-21`, integrated `2019-03-21`)
- Upstream registration evidence: [codemp/client/cl_discordrpc.cpp:382](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_discordrpc.cpp#L382)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-21` | — | `2019-03-21` | [`53b43cd32500`](https://github.com/eternalcodes/EternalJK/commit/53b43cd32500dfc4544b7213f14e69064037acfb) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-21` | — | `2019-03-21` | [`53b43cd32500`](https://github.com/taysta/TaystJK/commit/53b43cd32500dfc4544b7213f14e69064037acfb) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-21` | — | `2019-03-21` | [`53b43cd32500`](https://github.com/videoP/jaPRO/commit/53b43cd32500dfc4544b7213f14e69064037acfb) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-21` | — | `2019-03-21` | [`53b43cd32500`](https://github.com/JKSunny/EternalJK/commit/53b43cd32500dfc4544b7213f14e69064037acfb) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6c6472650cc`](https://github.com/eternalcodes/EternalJK/commit/f6c6472650ccd08fb0d010755094ab09ca8aced7)<br>Discord RPC integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_discordrpc.cpp:448](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L448) (Cvar_Get); condition `defined DISCORD && !(_DEBUG)`
- behavior: [codemp/client/cl_discordrpc.cpp:193](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L193)
