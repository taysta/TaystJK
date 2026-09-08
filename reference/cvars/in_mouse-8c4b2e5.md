---
title: "in_mouse"
layout: reference
nav_exclude: true
search_exclude: false
---

# `in_mouse`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `in_mouse` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/unix/linux_glimp.c:1303](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/unix/linux_glimp.c#L1303)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/unix/linux_glimp.c`, `codemp/unix/linux_glimp.c` | `high` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_input.cpp` | `medium` |
| `2016-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`13791f7ad4fe`](https://github.com/taysta/TaystJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_input.cpp` | `medium` |
| `2018-01-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8365e2db3b6b`](https://github.com/eternalcodes/EternalJK/commit/8365e2db3b6b632713f8c6f35cf3d84275fabd99)<br>Alt+tabbing now triggers chat bubble. | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2018-11-08` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7bc2134b98d4`](https://github.com/eternalcodes/EternalJK/commit/7bc2134b98d469a1a5d59ae6c7efff6d1b703ef8)<br>Minimized/unfocused chatbubble recode | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2018-12-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`20a2e73abca8`](https://github.com/eternalcodes/EternalJK/commit/20a2e73abca817d0ab29f0bd39334a1272ccd13a)<br>Allow right shift/ALT (ALTGR?)/CTRL to be bound separately as RCTRL/RALT/RCTRL | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2019-06-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`586b8a6aefe8`](https://github.com/eternalcodes/EternalJK/commit/586b8a6aefe8fd72820ea82f341f9214999b95e9)<br>Accomodate for SDL_SetHint failing with in_mouse 2. | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2019-06-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`95bd6ae28589`](https://github.com/eternalcodes/EternalJK/commit/95bd6ae28589147d1f292e936fad2d42b0cffc41)<br>Fix non-raw-input option after 01081bc | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cf5f50918b74`](https://github.com/taysta/TaystJK/commit/cf5f50918b744e1f99f36241ca1df889ce0514b6) · [PR #125](https://github.com/taysta/TaystJK/pull/125)<br>Small fixes (#125) | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2024-03-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`027d7505bfd1`](https://github.com/taysta/TaystJK/commit/027d7505bfd17765eaf4402d43d80524158cc8d6) · [PR #173](https://github.com/taysta/TaystJK/pull/173)<br>Macos input, libjpeg, libpng, zlib version updates (#173) | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |

## Evidence

- registration: [shared/sdl/sdl_input.cpp:644](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L644) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:652](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L652)
- behavior: [shared/sdl/sdl_input.cpp:650](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L650)
- behavior: [shared/sdl/sdl_input.cpp:908](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L908)
