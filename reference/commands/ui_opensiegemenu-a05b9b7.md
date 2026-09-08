---
title: "ui_opensiegemenu"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_opensiegemenu`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `UI_OpenSiegeMenu_f` in the ui module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `ui_opensiegemenu` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) on `2013-04-07` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/ui/ui_atoms.c:90](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/ui/ui_atoms.c#L90)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | [`14cea1563762`](https://github.com/SomaZ/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | [`14cea1563762`](https://github.com/jkanewmod/NewJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-12-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f5c1b2ceb3ba`](https://github.com/JACoders/OpenJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1)<br>[MP] Made ui use bsearch for commands. Removed ui_teamOrders that did nothing. Made ui_test actually be considered a command to the engine. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/ui/ui_atoms.c` | `medium` |
| `2014-01-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d4ce8f0bbfe7`](https://github.com/JACoders/OpenJK/commit/d4ce8f0bbfe747de490416048277fa2a93d85233)<br>[MP] Clean up UI and bot code | Changed the registered command handler. `codemp/ui/ui_atoms.c` | `medium` |
| `2016-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`561b84ebefaf`](https://github.com/eternalcodes/EternalJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419)<br>Added modversion cmd for UI | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_atoms.c` | `medium` |
| `2018-04-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763)<br>Add /strafeHelper, /stylePlayer, and /speedometer commands to UI | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_atoms.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_atoms.c:112](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_atoms.c#L112) (ui command table)
- handler: [codemp/ui/ui_atoms.c:90](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_atoms.c#L90)
