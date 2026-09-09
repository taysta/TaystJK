---
title: "g_disableServerG2"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_disableServerG2`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_disableServerG2` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_active.c:4896](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L4896) |
| `1` | Enabled. | [codemp/game/g_active.c:4896](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L4896) |

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:285](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L285)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_main.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2023-10-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`530446764ef0`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) · [PR #29](https://github.com/taysta/TaystJK/pull/29)<br>Merge pull request #29 from taysta/reconcile | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `medium` |
| `2024-02-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) · [PR #157](https://github.com/taysta/TaystJK/pull/157)<br>Upstream update (#157) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:86](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L86) (XCVAR_DEF); condition `defined(_DEBUG)`
- behavior: [codemp/game/g_active.c:4896](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L4896)
- behavior: [codemp/game/w_saber.c:8482](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_saber.c#L8482)
