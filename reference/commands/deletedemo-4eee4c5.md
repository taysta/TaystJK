---
title: "deletedemo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `deletedemo`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Delete a demo

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `deletedemo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`98e5c2a48010`](https://github.com/eternalcodes/EternalJK/commit/98e5c2a48010c576340c61f85b857123fbd74b4c) on `2018-04-26` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:3374](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3374)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-26` | [`98e5c2a48010`](https://github.com/eternalcodes/EternalJK/commit/98e5c2a48010c576340c61f85b857123fbd74b4c) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-04-26` | [`98e5c2a48010`](https://github.com/taysta/TaystJK/commit/98e5c2a48010c576340c61f85b857123fbd74b4c) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-04-26` | [`98e5c2a48010`](https://github.com/videoP/jaPRO/commit/98e5c2a48010c576340c61f85b857123fbd74b4c) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-26` | [`98e5c2a48010`](https://github.com/JKSunny/EternalJK/commit/98e5c2a48010c576340c61f85b857123fbd74b4c) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-04-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c199071ce9a4`](https://github.com/eternalcodes/EternalJK/commit/c199071ce9a4431d0022986ce2fe11780fd0cb2a)<br>Added "delete demo" button in UI | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-04-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6107f5fbcf59`](https://github.com/eternalcodes/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847)<br>1.00 demo (*.dm_25) support, "playdemo" alias command | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`825d63b114ab`](https://github.com/eternalcodes/EternalJK/commit/825d63b114abfecc502c4136dc3ce4dad0e0841a)<br>Fix demo_restart+fix bugs in demo commands from 1.00 demo support | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3473](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3473) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:642](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L642)
