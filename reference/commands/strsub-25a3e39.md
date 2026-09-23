---
title: "strSub"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `strSub`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Executes a command after replacing text surrounded by dollar signs with the value of that cvar. A doubled dollar sign emits one literal dollar sign.

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
| Syntax | `strSub <command...>` |
| Cheat protected | No |

## Arguments and gating

Arguments: `command`.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- TaystJK integration evidence: [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)
- Attribution method: `introduction-commit-explicit-credit`
- Attribution confidence: `high`
- Notes: The exact registration's introduction commit explicitly imports it from newjk; the identifier is absent from that project's configured public snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2022-04-03` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2022-04-03` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/videoP/jaPRO/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Other project appearance |

## Evidence

- registration: [codemp/qcommon/common.cpp:1425](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/common.cpp#L1425) (Cmd_AddCommand)
- handler: [codemp/qcommon/common.cpp:433](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/common.cpp#L433)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
