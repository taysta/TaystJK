---
title: "killserver"
layout: reference
nav_exclude: true
search_exclude: false
---

# `killserver`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Shuts the server down and disconnects all clients

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `killserver` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:989](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_ccmds.cpp#L989)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`59e3f64538a1`](https://github.com/JACoders/OpenJK/commit/59e3f64538a19235a7d5309ce35e762d812d1f2a)<br>Added some more commands to tab completion. Adjusted how commands, cvars and binds are listed. Added grey colour code (^8) | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`44d5666875f3`](https://github.com/JACoders/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348)<br>Merge pull request #480 from dpadgett/svdemo | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2023-06-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64b8343c85ea`](https://github.com/taysta/TaystJK/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) · [PR #2](https://github.com/taysta/TaystJK/pull/2)<br>Merge pull request #2 from TomArrow/taysternal | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2337](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2337) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:1521](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1521)
