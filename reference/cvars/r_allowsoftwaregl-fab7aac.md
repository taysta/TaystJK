---
title: "r_allowSoftwareGL"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_allowSoftwareGL`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_allowSoftwareGL` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sdl/sdl_window.cpp:602](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L602) |
| `1` | Enabled. | [shared/sdl/sdl_window.cpp:602](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L602) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/win32/win_glimp.cpp:1638](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/win32/win_glimp.cpp#L1638)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_glimp.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c2bb91dfb8d0`](https://github.com/JACoders/OpenJK/commit/c2bb91dfb8d0d702af9714e4163a8b580f26e2b2)<br>Added the Ghoul 2 crap to the SP modular renderer. Next up: more unresolved symbols and RMG. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_glimp.cpp` | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/unix/linux_glimp.c` | `high` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_glimp.cpp` | `medium` |
| `2013-11-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3cd6879507ff`](https://github.com/JACoders/OpenJK/commit/3cd6879507ff807896562e9fa6256295dc4a2c7e)<br>[SP] Clean up renderer files, removed ununsed files | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_glimp.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_glimp.cpp` | `medium` |
| `2016-03-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`045d03ae795c`](https://github.com/eternalcodes/EternalJK/commit/045d03ae795ca7abc1bff348273e4c13c7d15fd4)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `shared/sdl/sdl_window.cpp` | `medium` |
| `2016-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`13791f7ad4fe`](https://github.com/taysta/TaystJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_glimp.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `shared/sdl/sdl_window.cpp` | `medium` |
| `2021-10-24` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`bd3a458a8bb2`](https://github.com/JKSunny/EternalJK/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5)<br>Various fixes and upstream changes from Quake3e | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_window.cpp` | `high` |

## Evidence

- registration: [shared/sdl/sdl_window.cpp:795](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L795) (Cvar_Get)
- behavior: [shared/sdl/sdl_window.cpp:602](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L602)
