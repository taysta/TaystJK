---
title: "delaycancel"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `delaycancel`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Cancels pending millisecond-based delay entries whose command text contains the supplied text. An empty string matches every pending delay.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2022-04-20 in [`1dd571383`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `delaycancel <text>` |
| Cheat protected | No |

## Arguments and gating

Arguments: `text`.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Ultimate-origin introduction: [`0954d89c63db`](https://github.com/jkanewmod/NewJK/commit/0954d89c63db6e154452770c50c358667e29373c) in <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> (content authored `2021-05-21`, integrated `2021-05-21`)
- TaystJK integration evidence: [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)
- Upstream registration evidence: [codemp/qcommon/cmd.cpp:1187](https://github.com/jkanewmod/NewJK/blame/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/qcommon/cmd.cpp#L1187)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2021-05-21` | — | `2021-05-21` | [`0954d89c63db`](https://github.com/jkanewmod/NewJK/commit/0954d89c63db6e154452770c50c358667e29373c) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2022-04-03` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2022-04-03` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/videoP/jaPRO/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Other project appearance |

## Evidence

- registration: [codemp/qcommon/cmd.cpp:1219](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/qcommon/cmd.cpp#L1219) (Cmd_AddCommand)
- handler: [codemp/qcommon/cmd.cpp:114](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/qcommon/cmd.cpp#L114)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
