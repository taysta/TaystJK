---
title: "cp_altDimAlpha"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "Opacity (0-255) of JA+ players in the other alternate dimension"
---

# `cp_altDimAlpha`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Opacity (0-255) of JA+ players in the other alternate dimension

## At a glance

| Field | Value |
|:--|:--|
| Default | `40` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Category | Gameplay & combat |
| Module | `cgame` |
| Renderer | All / not renderer-specific |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2026-09-28 in [`1158d8281`](https://github.com/taysta/TaystJK/commit/1158d82810c44a055f16d59d89240469b0cfeb66) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Enforced ranges

- `1` through `255` (integer; manual clamp, not enforced on every path). Evidence: [codemp/cgame/cg_players.c:13229](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_players.c#L13229)

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`1158d82810c4`](https://github.com/taysta/TaystJK/commit/1158d82810c44a055f16d59d89240469b0cfeb66) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-09-27`, PR opened `2026-09-27`, integrated `2026-09-28`)
- Origin pull request: [#396](https://github.com/taysta/TaystJK/pull/396)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:196](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_xcvar.h#L196)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-09-27` | [2026-09-27](https://github.com/taysta/TaystJK/pull/396) | `2026-09-28` | [`1158d82810c4`](https://github.com/taysta/TaystJK/commit/1158d82810c44a055f16d59d89240469b0cfeb66) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:196](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_xcvar.h#L196) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_players.c:13229](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_players.c#L13229)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a"><code>c722804317d7</code></a> on 2026-09-28. Anything merged after that is not reflected here.</p>
