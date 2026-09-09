---
title: "devmap"
layout: reference
nav_exclude: true
search_exclude: false
---

# `devmap`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Load a new map with cheats enabled

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `devmap [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/server/sv_ccmds.cpp:453](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/server/sv_ccmds.cpp#L453)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af4b4c2de891`](https://github.com/JACoders/OpenJK/commit/af4b4c2de891e091c429bcf9cc2d2f36d9d9d181)<br>Removed most Xbox stuff | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-06-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`873b95b64cc6`](https://github.com/JACoders/OpenJK/commit/873b95b64cc699afea28cf072479a516c3db9997)<br>Removed spmap and spdevmap. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-06-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`da269e1cb11f`](https://github.com/JACoders/OpenJK/commit/da269e1cb11f37611f42daf9f259b3f15aa93a3b)<br>Still allow devmapmdl and devmapall to enable cheats. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/server/sv_ccmds.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`08ec047719aa`](https://github.com/eternalcodes/EternalJK/commit/08ec047719aa8e4b8e613dbda5bb225d52d34870)<br>Set sv_pure 0 on local client when loading a map with /map or /devmap | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2330](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2330) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:177](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L177)
