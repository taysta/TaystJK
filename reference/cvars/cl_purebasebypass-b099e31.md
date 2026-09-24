---
title: "cl_pureBaseBypass"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_pureBaseBypass`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Bypass pure checks on pure base servers, takes effect on next connect

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2026-09-23 in [`d376304c0`](https://github.com/taysta/TaystJK/commit/d376304c07aeb5d324354f8a78c7f44f83237b25) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_parse.cpp:457](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_parse.cpp#L457) |
| `1` | Enabled. | [codemp/client/cl_parse.cpp:457](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_parse.cpp#L457) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`d376304c07ae`](https://github.com/taysta/TaystJK/commit/d376304c07aeb5d324354f8a78c7f44f83237b25) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-09-23`, integrated `2026-09-23`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3460](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_main.cpp#L3460)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-09-23` | — | `2026-09-23` | [`d376304c07ae`](https://github.com/taysta/TaystJK/commit/d376304c07aeb5d324354f8a78c7f44f83237b25) | Ultimate origin |

## Evidence

- registration: [codemp/client/cl_main.cpp:3460](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_main.cpp#L3460) (Cvar_Get)
- behavior: [codemp/client/cl_parse.cpp:457](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_parse.cpp#L457)
- behavior: [codemp/client/cl_parse.cpp:456](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_parse.cpp#L456)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
