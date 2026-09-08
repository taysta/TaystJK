---
title: "clientkick"
layout: reference
nav_exclude: true
search_exclude: false
---

# `clientkick`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Kick a user from the server by userid

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `clientkick <client number>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:973](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_ccmds.cpp#L973)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9344b45fc2d8`](https://github.com/JACoders/OpenJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e)<br>Updates to sv_ccmds.c.  Adds kickall, kickbots, kicknum (clientkick alias). kick all and kick allbots still work. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c6e3f0479ac0`](https://github.com/JACoders/OpenJK/commit/c6e3f0479ac048e838ac002351fab307f726fa4d)<br>[MP] Meta: Remove unnecessary comments and names | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`73e537fdea26`](https://github.com/JACoders/OpenJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b)<br>[MP] Port ioq3 engine based ban code. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2321](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2321) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:580](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L580)
