---
title: "status"
layout: reference
nav_exclude: true
search_exclude: false
---

# `status`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Prints status of server and connected clients

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `status` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/server/sv_ccmds.cpp:447](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/server/sv_ccmds.cpp#L447)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9344b45fc2d8`](https://github.com/JACoders/OpenJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e)<br>Updates to sv_ccmds.c.  Adds kickall, kickbots, kicknum (clientkick alias). kick all and kick allbots still work. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ba6cfa57790c`](https://github.com/JACoders/OpenJK/commit/ba6cfa57790c572649aa0f0327e93c8378b08563)<br>Fixed a lot of vsprintfs and sprintfs.  Some sprintfs still remain on purpose because debug who cares, and in botlib | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `high` |
| `2013-06-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3b85d3fe89f0`](https://github.com/JACoders/OpenJK/commit/3b85d3fe89f0850e9b03ab537b91f5d2d059fbae)<br>Fix svsay not printing output to dedicated server console. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-06-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9893377ad980`](https://github.com/JACoders/OpenJK/commit/9893377ad980acdddca56d87db8dbfb97de399d5)<br>Add number of clients out of possible number of clients to status command. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7f053f0964cc`](https://github.com/JACoders/OpenJK/commit/7f053f0964cc98e9de60911ebe4befb0a1215028)<br>Improved status command for the console.  Is mostly inspired by the SOURCE status cmd. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6f98a53f4616`](https://github.com/JACoders/OpenJK/commit/6f98a53f461663328222a2c40cdf36351dc169fa)<br>Merge branch 'master' of github.com:Razish/OpenJK | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `high` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c6e3f0479ac0`](https://github.com/JACoders/OpenJK/commit/c6e3f0479ac048e838ac002351fab307f726fa4d)<br>[MP] Meta: Remove unnecessary comments and names | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-04-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`815fbd0bff6f`](https://github.com/JACoders/OpenJK/commit/815fbd0bff6f8514719ecf110a9262e1e63af3f4)<br>[MP] Remove colors from hostname in /status. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-08-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`036c904c5bd8`](https://github.com/JACoders/OpenJK/commit/036c904c5bd8134e33e69388ca77542a207e35f0)<br>[MP] Tweaked client list in status rcon cmd Cut client number down to 2 width since 32 is max players. Remove lastmsg and qport. Increased size of address to accommodate for future ipv6 support. Fix colored name padding. Based on ioquake/ioq3@94e36c288c6ce6b5273055e61077c29e81fbd2bf | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-10-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`706b8efe7848`](https://github.com/JACoders/OpenJK/commit/706b8efe784846d0a8f08a02413f3558464c1d65)<br>[MP] Added uptime to server console status command | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/server/sv_ccmds.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05f1ac70497e`](https://github.com/eternalcodes/EternalJK/commit/05f1ac70497e667ca2e6005753ff8bc76641c425)<br>rcon status cleanup move name to end of line, remove notrunc, cleanup status info | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0db4ffc5f66d`](https://github.com/eternalcodes/EternalJK/commit/0db4ffc5f66d247d9031f3efe8a893e3d95d7153)<br>rcon status cleanup pt2 | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2322](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2322) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:1145](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L1145)
