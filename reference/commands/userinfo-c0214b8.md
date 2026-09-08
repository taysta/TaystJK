---
title: "userinfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `userinfo`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CL_Clientinfo_f` in the engine-client module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `userinfo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) on `2013-04-07` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:3397](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3397)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2018-04-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`98e5c2a48010`](https://github.com/eternalcodes/EternalJK/commit/98e5c2a48010c576340c61f85b857123fbd74b4c)<br>start of delete demo command+"delete demo" button in menu | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3496) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:1459](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1459)
