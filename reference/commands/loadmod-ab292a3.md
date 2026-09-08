---
title: "loadmod"
layout: reference
nav_exclude: true
search_exclude: false
---

# `loadmod`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Restart the renderer (with specified mod folder) - or change the resolution

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `loadmod <folder name>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`04db4f373079`](https://github.com/eternalcodes/EternalJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) on `2018-02-25` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:3382](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3382)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-02-25` | [`04db4f373079`](https://github.com/eternalcodes/EternalJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-02-25` | [`04db4f373079`](https://github.com/taysta/TaystJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-02-25` | [`04db4f373079`](https://github.com/videoP/jaPRO/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-02-25` | [`04db4f373079`](https://github.com/JKSunny/EternalJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Shared earliest lineage |

## Evidence

- registration: [codemp/client/cl_main.cpp:3481](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3481) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:1302](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1302)
