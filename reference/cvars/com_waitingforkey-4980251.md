---
title: "com_waitingForKey"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_waitingForKey`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_waitingForKey` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sdl/sdl_input.cpp:203](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L203) |
| `1` | Enabled. | [shared/sdl/sdl_input.cpp:203](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L203) |

## Flags

- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`a1ee9793b45d`](https://github.com/taysta/TaystJK/commit/a1ee9793b45d409840c6b75b3da75fdebca685a2) on `2025-04-26` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#225](https://github.com/taysta/TaystJK/pull/225)
- Upstream registration evidence: [shared/sdl/sdl_input.cpp:201](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L201)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-26` | [`a1ee9793b45d`](https://github.com/taysta/TaystJK/commit/a1ee9793b45d409840c6b75b3da75fdebca685a2) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-26` | [`a1ee9793b45d`](https://github.com/videoP/jaPRO/commit/a1ee9793b45d409840c6b75b3da75fdebca685a2) | Shared earliest lineage |

## Evidence

- registration: [shared/sdl/sdl_input.cpp:201](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L201) (Cvar_Get)
- registration: [shared/sys/sys_main.cpp:181](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_main.cpp#L181) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:203](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L203)
- behavior: [codemp/ui/ui_shared.c:1480](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_shared.c#L1480)
- behavior: [codemp/ui/ui_shared.c:4389](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_shared.c#L4389)
- behavior: [codemp/ui/ui_shared.c:4449](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_shared.c#L4449)
- behavior: [codemp/ui/ui_shared.c:5286](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_shared.c#L5286)
