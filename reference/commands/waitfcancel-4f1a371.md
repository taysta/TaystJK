---
title: "waitfcancel"
layout: reference
nav_exclude: true
search_exclude: false
---

# `waitfcancel`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Cancels pending frame-based waitf entries whose command text contains the supplied text. An empty string matches every pending waitf.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `waitfcancel <text>` |
| Cheat protected | No |

## Arguments and gating

Arguments: `text`.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Ultimate-origin introduction: [`0954d89c63db`](https://github.com/jkanewmod/NewJK/commit/0954d89c63db6e154452770c50c358667e29373c) on `2021-05-21` in <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>
- TaystJK integration evidence: [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)
- Upstream registration evidence: [codemp/qcommon/cmd.cpp:1189](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/qcommon/cmd.cpp#L1189)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2021-05-21` | [`0954d89c63db`](https://github.com/jkanewmod/NewJK/commit/0954d89c63db6e154452770c50c358667e29373c) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2022-04-20` | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2022-04-20` | [`1dd571383a0d`](https://github.com/videoP/jaPRO/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Later project appearance |

## Evidence

- registration: [codemp/qcommon/cmd.cpp:1221](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L1221) (Cmd_AddCommand)
- handler: [codemp/qcommon/cmd.cpp:118](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L118)
