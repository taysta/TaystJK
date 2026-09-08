---
title: "cl_motdServer2"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_motdServer2`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `JKHUB_UPDATE_SERVER_NAME` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`3a70129c5dd2`](https://github.com/JACoders/OpenJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) on `2014-05-17` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:2744](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2744)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-05-17` | [`3a70129c5dd2`](https://github.com/JACoders/OpenJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-05-17` | [`3a70129c5dd2`](https://github.com/eternalcodes/EternalJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-05-17` | [`3a70129c5dd2`](https://github.com/SomaZ/OpenJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-05-17` | [`3a70129c5dd2`](https://github.com/taysta/TaystJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-05-17` | [`3a70129c5dd2`](https://github.com/videoP/jaPRO/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-05-17` | [`3a70129c5dd2`](https://github.com/jkanewmod/NewJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-05-17` | [`3a70129c5dd2`](https://github.com/JKSunny/EternalJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared earliest lineage |

## Evidence

- registration: [codemp/client/cl_main.cpp:3314](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3314) (Cvar_Get)
