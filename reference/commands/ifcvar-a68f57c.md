---
title: "ifCvar"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ifCvar`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Tests a cvar against conditions in order and executes the command belonging to the first match. Conditions support literal string equality; numeric $=, $!=, $>, $<, $>= and $<= comparisons; $contains; $beginswith/$startswith; $endswith; $else; and values read from another cvar with a leading $. The argument count includes the command itself.

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
| Syntax | `ifCvar <cvar> <setting> <argument-count> <command...> [<setting> <argument-count> <command...> ...]` |
| Cheat protected | No |

## Arguments and gating

Arguments: `cvar`, `setting`, `argument-count`, `command`, `...`.

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

- registration: [codemp/qcommon/common.cpp:1426](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/common.cpp#L1426) (Cmd_AddCommand)
- handler: [codemp/qcommon/common.cpp:346](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/common.cpp#L346)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
