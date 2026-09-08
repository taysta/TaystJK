---
title: "sv_flushbans"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_flushbans`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Removes all bans and exceptions

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `sv_flushbans` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9c68d9f362bc`](https://github.com/JACoders/OpenJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) on `2014-08-19` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1991](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_ccmds.cpp#L1991)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-08-19` | [`9c68d9f362bc`](https://github.com/JACoders/OpenJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-08-19` | [`9c68d9f362bc`](https://github.com/eternalcodes/EternalJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-08-19` | [`9c68d9f362bc`](https://github.com/SomaZ/OpenJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-08-19` | [`9c68d9f362bc`](https://github.com/taysta/TaystJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-08-19` | [`9c68d9f362bc`](https://github.com/videoP/jaPRO/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-08-19` | [`9c68d9f362bc`](https://github.com/jkanewmod/NewJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-08-19` | [`9c68d9f362bc`](https://github.com/JKSunny/EternalJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2357](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2357) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:1075](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1075)
