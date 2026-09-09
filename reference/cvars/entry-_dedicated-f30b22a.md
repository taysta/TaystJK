---
title: "_dedicated"
layout: reference
nav_exclude: true
search_exclude: false
---

# `_dedicated`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_dedicated` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Enforced ranges

- `1` through `2` (integer; Cvar_CheckRange) — [codemp/qcommon/common.cpp:1436](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1436)
- `0` through `2` (integer; Cvar_CheckRange) — [codemp/qcommon/common.cpp:1445](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1445)

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes
- `CVAR_ROM` — read-only after registration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `engine-shared` | `—` | `always` |
| `0` | `engine-shared` | `—` | `else(defined(DEDICATED))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-05-09`, integrated `2013-05-11`)
- Upstream registration evidence: [codemp/qcommon/common.cpp:1233](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/common.cpp#L1233)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-05-09` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-05-09` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/eternalcodes/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-05-09` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/SomaZ/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-05-09` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/taysta/TaystJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-05-09` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/videoP/jaPRO/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-05-09` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/jkanewmod/NewJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-05-09` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/JKSunny/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7f053f0964cc`](https://github.com/JACoders/OpenJK/commit/7f053f0964cc98e9de60911ebe4befb0a1215028)<br>Improved status command for the console.  Is mostly inspired by the SOURCE status cmd. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6f98a53f4616`](https://github.com/JACoders/OpenJK/commit/6f98a53f461663328222a2c40cdf36351dc169fa)<br>Merge branch 'master' of github.com:Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/client/cl_scrn.cpp` | `medium` |
| `2013-08-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61cd6e979c3b`](https://github.com/JACoders/OpenJK/commit/61cd6e979c3bb37e8b05ca2c6f1a1fc0812aea17)<br>Removed stricmp etc, always use Q_ versions for consistency across platforms | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2013-11-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2e90f9c19be1`](https://github.com/JACoders/OpenJK/commit/2e90f9c19be1a2b74a1ac71f8ff0dcdadfa3103c)<br>[MP] Removed leftover delayFreeVM references. Init lastTime to 0 in Com_Frame. Bring back ERR_NEED_CD handling just for conformity sake. Init the jakey randomizer first thing in Com_Init. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2013-11-14` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5d5eef61b5e4`](https://github.com/JACoders/OpenJK/commit/5d5eef61b5e4bdb33710730a693b4ac054ba5e5e)<br>[MP] Fixed early prints to the ingame console. This does not hurt anything since we don't allow dedicated in the main bin right now. Check this if we decide to re-enable without going the in-game console for openjk regular executable dedicated. | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `high` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`adce8465b4b5`](https://github.com/JACoders/OpenJK/commit/adce8465b4b5acf64dbba3bbbd79a7d8766a7c34)<br>[MP] Allow dedicated cvar to be set to during init instead of not at all with dedicated executable. | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2014-08-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`03bba21225bb`](https://github.com/JACoders/OpenJK/commit/03bba21225bbdfe484236d00966b6783bd2077a7)<br>[MP] Add svtell command to send message to clients from server console. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-08-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`036c904c5bd8`](https://github.com/JACoders/OpenJK/commit/036c904c5bd8134e33e69388ca77542a207e35f0)<br>[MP] Tweaked client list in status rcon cmd Cut client number down to 2 width since 32 is max players. Remove lastmsg and qport. Increased size of address to accommodate for future ipv6 support. Fix colored name padding. Based on ioquake/ioq3@94e36c288c6ce6b5273055e61077c29e81fbd2bf | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `shared/sys/sys_main.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `codemp/server/sv_main.cpp`, `shared/sys/sys_main.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05f1ac70497e`](https://github.com/eternalcodes/EternalJK/commit/05f1ac70497e667ca2e6005753ff8bc76641c425)<br>rcon status cleanup move name to end of line, remove notrunc, cleanup status info | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`701070354c7c`](https://github.com/eternalcodes/EternalJK/commit/701070354c7ca1e7bb1847d74b1710d23c52369f)<br>Fix OOB IP rate limiter breaking non-dedicated servers | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`405022446ca4`](https://github.com/taysta/TaystJK/commit/405022446ca43e90b746b5b9331fcaacc059e83b)<br>[OpenJK] Re-merge OpenJK into EJK [1] | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_main.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1444](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1444) (Cvar_Get); condition `else(defined(DEDICATED))`
- registration: [codemp/qcommon/common.cpp:1816](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1816) (Cvar_Get)
- behavior: [codemp/client/cl_scrn.cpp:608](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L608)
- behavior: [codemp/qcommon/common.cpp:310](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L310)
- behavior: [codemp/qcommon/common.cpp:1521](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1521)
- behavior: [codemp/qcommon/common.cpp:1535](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1535)
- behavior: [codemp/qcommon/common.cpp:1661](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1661)
