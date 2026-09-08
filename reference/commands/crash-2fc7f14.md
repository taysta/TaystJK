---
title: "crash"
layout: reference
nav_exclude: true
search_exclude: false
---

# `crash`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Com_Crash_f` in the engine-shared module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Syntax | `crash` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/common.cpp:1057](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/common.cpp#L1057)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dcc17314ab11`](https://github.com/JACoders/OpenJK/commit/dcc17314ab1167547f172b0d21788c0ea1ecb760)<br>Removed cd key from mp/qcommon | Changed the registered command handler. `codemp/qcommon/common.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed the registered command handler. `codemp/qcommon/common.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/qcommon/common.cpp` | `high` |
| `2013-07-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b2afca07b43c`](https://github.com/JACoders/OpenJK/commit/b2afca07b43c126553236315c5a90c8fbbf76f05)<br>Merge pull request #299 from xycaleth/fix-warnings | Changed the registered command handler. `codemp/qcommon/common.cpp` | `medium` |
| `2013-07-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9e2ed38faed0`](https://github.com/JACoders/OpenJK/commit/9e2ed38faed06f59064add98791664ca02c82afa)<br>Removed com_introPlayed cvar.  Was leftover q3 cruft. Added com_bootlogo cvar that defaults to 1.  Disable to turn off starting movies without having to alter startup parameters. | Changed the registered command handler. `codemp/qcommon/common.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `high` |
| `2014-05-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b25d81d3ac77`](https://github.com/JACoders/OpenJK/commit/b25d81d3ac77ebbcda76f446c2338d2b5a783ec4)<br>[MP] Remove MEM_DEBUG blocks that are unused. | Changed the registered command handler. `codemp/qcommon/common.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed the registered command handler. `codemp/qcommon/common.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a175acc4858a`](https://github.com/JACoders/OpenJK/commit/a175acc4858ad2d7d6be3d459933fbba16a6926b)<br>Merge pull request #622 from smcv/warnings | Changed the registered command handler. `codemp/qcommon/common.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1403](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1403) (Cmd_AddCommand)
- handler: [codemp/qcommon/common.cpp:1238](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1238)
