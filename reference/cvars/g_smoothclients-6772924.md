---
title: "g_smoothClients"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_smoothClients`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

How the server sends players who are moving

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | Yes: [codemp/ui/ui_xdocs.h:461](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L461) |
| In-game menu | No |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Send each player where they are | [codemp/ui/ui_xdocs.h:461](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L461) |
| `1` | Move lagging players on by up to two frames | [codemp/ui/ui_xdocs.h:461](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L461) |
| `2` | Send players moving on from their last command, for clients to extrapolate (Base behavior) | [codemp/ui/ui_xdocs.h:462](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L462) |

## Flags

- `CVAR_NONE`: fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:395](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L395)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_active.c`, `codemp/game/g_main.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c`, `codemp/game/g_trigger.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:154](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_xcvar.h#L154) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:5530](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_active.c#L5530)
- behavior: [codemp/game/g_active.c:6284](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_active.c#L6284)
- behavior: [codemp/game/g_active.c:6318](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_active.c#L6318)
- behavior: [codemp/game/g_trigger.c:1349](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_trigger.c#L1349)
- behavior: [codemp/ui/ui_xdocs.h:455](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L455)
- documentation: [codemp/ui/ui_xdocs.h:461](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L461)
- documentation: [docs/japro_docs.md:89](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/docs/japro_docs.md#L89)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/b35ed06fec41c53644352743c6b199a5d5d500f3"><code>b35ed06fec41</code></a> on 2026-09-27. Anything merged after that is not reflected here.</p>
