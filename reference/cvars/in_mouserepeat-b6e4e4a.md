---
title: "in_mouserepeat"
layout: reference
nav_exclude: true
search_exclude: false
---

# `in_mouserepeat`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `in_mouserepeat` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) on `2017-12-28` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [shared/sdl/sdl_input.cpp:624](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/shared/sdl/sdl_input.cpp#L624)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-28` | [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-28` | [`668821b03696`](https://github.com/taysta/TaystJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-28` | [`668821b03696`](https://github.com/videoP/jaPRO/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-28` | [`668821b03696`](https://github.com/JKSunny/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-25` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`e19a3cbf6cb5`](https://github.com/videoP/jaPRO/commit/e19a3cbf6cb54a99eb5f2274d3d092deba66db8f)<br>-Added RGB color selection to custom character menu. | Changed registration, default, flags, module, renderer scope, handler, or gating. `shared/sdl/sdl_input.cpp` | `high` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc10f7b67c56`](https://github.com/eternalcodes/EternalJK/commit/dc10f7b67c5611ae941cecbde51a85649a27c606)<br>Auto stash before rebase of "origin/master" | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2018-03-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`07e3be09739d`](https://github.com/eternalcodes/EternalJK/commit/07e3be09739db97c90d4054c47d4e4c3a458ced8)<br>in_mouserepeat every other frame | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |

## Evidence

- registration: [shared/sdl/sdl_input.cpp:646](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L646) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:985](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L985)
- behavior: [shared/sdl/sdl_input.cpp:988](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L988)
