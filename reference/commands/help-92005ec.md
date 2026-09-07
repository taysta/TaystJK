---
title: "help"
layout: reference
nav_exclude: true
search_exclude: false
---

# `help`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Print command help

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `help [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`9da8e37d4ee2`](https://github.com/taysta/TaystJK/commit/9da8e37d4ee236e1a2ecd34469151920fcad469d)
- Upstream registration evidence: [codemp/qcommon/cmd.cpp:984](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/cmd.cpp#L984)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2506](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2506) (cgame command table)
- registration: [codemp/qcommon/cmd.cpp:1208](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L1208) (Cmd_AddCommand)
- handler: [codemp/cgame/cg_consolecmds.c:537](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L537)
- handler: [codemp/qcommon/cmd.cpp:1151](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L1151)
