---
title: "cl_chatStylePrefix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_chatStylePrefix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

String inserted before sent chat messages

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) on `2019-06-13` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:3349](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3349)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-06-13` | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-06-13` | [`986358853af6`](https://github.com/taysta/TaystJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-06-13` | [`986358853af6`](https://github.com/videoP/jaPRO/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-06-13` | [`986358853af6`](https://github.com/JKSunny/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Shared earliest lineage |

## Evidence

- registration: [codemp/client/cl_main.cpp:3448](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3448) (Cvar_Get)
- behavior: [codemp/client/cl_keys.cpp:1027](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L1027)
- behavior: [codemp/client/cl_keys.cpp:1028](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L1028)
