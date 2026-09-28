---
title: "sv_legacyGameAPI"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "1 when the game module loaded through Raven's dllEntry/vmMain API, 0 through OpenJK's GetModuleAPI"
---

# `sv_legacyGameAPI`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>).</p>

1 when the game module loaded through Raven's dllEntry/vmMain API, 0 through OpenJK's GetModuleAPI

## At a glance

| Field | Value |
|:--|:--|
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Manually settable | No; the game writes this value. |
| Cheat protected | No |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Category | Server & networking |
| Module | `engine-server` |
| Renderer | All / not renderer-specific |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2026-09-27 in [`6d85dffac`](https://github.com/taysta/TaystJK/commit/6d85dffacc76b77ea398e89e3cddbf4c2c38be7c) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM`: read-only after registration
- `CVAR_SERVERINFO`: published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`6d85dffacc76`](https://github.com/taysta/TaystJK/commit/6d85dffacc76b77ea398e89e3cddbf4c2c38be7c) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-09-26`, PR opened `2026-09-25`, integrated `2026-09-26`)
- Origin pull request: [#389](https://github.com/taysta/TaystJK/pull/389)
- Upstream registration evidence: [codemp/server/sv_gameapi.cpp:2845](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/server/sv_gameapi.cpp#L2845)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-09-26` | [2026-09-25](https://github.com/taysta/TaystJK/pull/389) | `2026-09-26` | [`6d85dffacc76`](https://github.com/taysta/TaystJK/commit/6d85dffacc76b77ea398e89e3cddbf4c2c38be7c) | Ultimate origin |

## Evidence

- registration: [codemp/server/sv_gameapi.cpp:2845](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/server/sv_gameapi.cpp#L2845) (Cvar_Get)
- behavior: [codemp/server/sv_gameapi.cpp:2846](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/server/sv_gameapi.cpp#L2846)
- behavior: [codemp/cgame/cg_servercmds.c:302](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/cgame/cg_servercmds.c#L302)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/b35ed06fec41c53644352743c6b199a5d5d500f3"><code>b35ed06fec41</code></a> on 2026-09-27. Anything merged after that is not reflected here.</p>
