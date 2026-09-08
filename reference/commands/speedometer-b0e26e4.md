---
title: "speedometer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `speedometer`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_SpeedometerSettings_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `speedometer [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) on `2018-04-19` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- TaystJK integration evidence: [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2198](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2198)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, vulkan; fork-lineage order selects eternaljk. The TaystJK integration evidence credits japro as an immediate port source, but eternaljk has an earlier dated introduction and remains the ultimate origin. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-19` | [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-19` | [`1d5acfc05276`](https://github.com/JKSunny/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Later project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-japro">jaPRO</span>. The earlier dated project remains the ultimate origin.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2018-09-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`88b547448bb8`](https://github.com/eternalcodes/EternalJK/commit/88b547448bb881aed4d42b537b3f8c6201fd91d1)<br>racemode roll fix, whitespace fix, followfastest optimization, getmovementstyle simplify | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1e4377ef412f`](https://github.com/eternalcodes/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293)<br>cosmetics | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ead7c2c37109`](https://github.com/eternalcodes/EternalJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06)<br>cg_speedometersettings -> cg_speedometer defaults to off cg_speedometer 1 = normal speedometer like ppl would expect | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc180aa113b3`](https://github.com/eternalcodes/EternalJK/commit/dc180aa113b3b4c7f07c2a6cbc39f3ad200b0772)<br>increase dropshadow distance to 512+misc fixes | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c`, `codemp/ui/ui_atoms.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2519](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2519) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:1529](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1529)
