---
title: "siegeCompleteCvarUpdate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `siegeCompleteCvarUpdate`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_SiegeCompleteCvarUpdate_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `siegeCompleteCvarUpdate` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:297](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_consolecmds.c#L297)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`86835c643c1b`](https://github.com/JACoders/OpenJK/commit/86835c643c1bed14b5075f0de0387ef2b411577e)<br>Removed unnecessary not used scoreboard code which was from Team Arena in cg_consolecmds.c and cg_draw.c | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2013-09-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`df98d2af72bb`](https://github.com/JACoders/OpenJK/commit/df98d2af72bbe8bf515e08aa82fde0ea82314be3)<br>General cleanup. Named anonymous structures, whitespace and name changes | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2013-11-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b2f3e89e2e75`](https://github.com/JACoders/OpenJK/commit/b2f3e89e2e75b4d6dc3d3bb0a04a0610aab20d2d)<br>[MP] Improve cg_consolecmds and cg_servercmds to use bsearch. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2016-03-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8e0993c3edd2`](https://github.com/eternalcodes/EternalJK/commit/8e0993c3edd2047009e11d8a0d75157507c906e0)<br>Add /afk command | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2016-03-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d0b29886a80d`](https://github.com/eternalcodes/EternalJK/commit/d0b29886a80d60ad1ed079f29aa6cda560ebeede)<br>Move "afk" cmd from cgame to client | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2463](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2463) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:294](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L294)
