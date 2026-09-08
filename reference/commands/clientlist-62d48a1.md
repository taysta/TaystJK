---
title: "clientlist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `clientlist`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Displays a list of all connected clients and their real client numbers

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `clientlist` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) on `2013-04-24` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:299](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/cgame/cg_consolecmds.c#L299)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-24` | [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-24` | [`3e986be9ab0d`](https://github.com/eternalcodes/EternalJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-24` | [`3e986be9ab0d`](https://github.com/SomaZ/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-24` | [`3e986be9ab0d`](https://github.com/taysta/TaystJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-24` | [`3e986be9ab0d`](https://github.com/videoP/jaPRO/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-24` | [`3e986be9ab0d`](https://github.com/jkanewmod/NewJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-24` | [`3e986be9ab0d`](https://github.com/JKSunny/EternalJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2013-11-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b2f3e89e2e75`](https://github.com/JACoders/OpenJK/commit/b2f3e89e2e75b4d6dc3d3bb0a04a0610aab20d2d)<br>[MP] Improve cg_consolecmds and cg_servercmds to use bsearch. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2451](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2451) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:158](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L158)
- documentation: [codemp/ui/ui_xdocs.h:619](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L619)
