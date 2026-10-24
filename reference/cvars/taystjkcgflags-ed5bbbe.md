---
title: "taystJKcgflags"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `taystJKcgflags`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>).</p>

Controls `taystJKcgflags` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Manually settable | No; the game writes this value. |
| Cheat protected | No |
| Network scope | `needs-server-support`: Sent to, or only useful with, a supporting game server. |
| Category | Gameplay & combat |
| Module | `cgame` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2026-10-23 in [`76943f046`](https://github.com/taysta/TaystJK/commit/76943f046bbbdc23d67323b838cb1c4c1e3fba0e) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_cvar.c:293](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_cvar.c#L293) |
| `1` | Enabled. | [codemp/cgame/cg_cvar.c:293](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_cvar.c#L293) |

## Flags

- `CVAR_ROM`: read-only after registration
- `CVAR_USERINFO`: sent in the client's userinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`76943f046bbb`](https://github.com/taysta/TaystJK/commit/76943f046bbbdc23d67323b838cb1c4c1e3fba0e) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-10-23`, PR opened `2026-10-23`, integrated `2026-10-23`)
- Origin pull request: [#414](https://github.com/taysta/TaystJK/pull/414)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:457](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_xcvar.h#L457)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits taystjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-10-23` | [2026-10-23](https://github.com/taysta/TaystJK/pull/414) | `2026-10-23` | [`76943f046bbb`](https://github.com/taysta/TaystJK/commit/76943f046bbbdc23d67323b838cb1c4c1e3fba0e) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:457](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_xcvar.h#L457) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_cvar.c:293](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_cvar.c#L293)
- behavior: [codemp/cgame/cg_cvar.c:294](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_cvar.c#L294)
- behavior: [codemp/cgame/cg_main.c:3339](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_main.c#L3339)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/76943f046bbbdc23d67323b838cb1c4c1e3fba0e"><code>76943f046bbb</code></a> on 2026-10-23. Anything merged after that is not reflected here.</p>
