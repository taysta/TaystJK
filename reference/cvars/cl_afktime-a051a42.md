---
title: "cl_afkTime"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_afkTime`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Minutes to autorename to afk, 0 to disable

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `10` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`09b3f68fcc6f`](https://github.com/eternalcodes/EternalJK/commit/09b3f68fcc6f09e1eceaf03dd9881005a74c2a53) on `2016-03-14` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:3353](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3353)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-14` | [`09b3f68fcc6f`](https://github.com/eternalcodes/EternalJK/commit/09b3f68fcc6f09e1eceaf03dd9881005a74c2a53) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-14` | [`09b3f68fcc6f`](https://github.com/taysta/TaystJK/commit/09b3f68fcc6f09e1eceaf03dd9881005a74c2a53) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-14` | [`09b3f68fcc6f`](https://github.com/videoP/jaPRO/commit/09b3f68fcc6f09e1eceaf03dd9881005a74c2a53) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-14` | [`09b3f68fcc6f`](https://github.com/JKSunny/EternalJK/commit/09b3f68fcc6f09e1eceaf03dd9881005a74c2a53) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9eaeb0619c13`](https://github.com/eternalcodes/EternalJK/commit/9eaeb0619c131e0ff65f2de4cd84ae6ff4880a56)<br>/cl_afkTime 0 now disables automatic afk | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |
| `2016-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6709f6e5ecef`](https://github.com/eternalcodes/EternalJK/commit/6709f6e5ecefc13f2523870e9dcd159e48fb9158)<br>Access cl_afkTime directly | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_input.cpp`, `codemp/client/cl_main.cpp`, `codemp/client/client.h` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e6ed053d8fa5`](https://github.com/eternalcodes/EternalJK/commit/e6ed053d8fa547a4e09b11d6708074bdc121edd4)<br>Improved Afk code | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1cdc9fc78b3b`](https://github.com/eternalcodes/EternalJK/commit/1cdc9fc78b3b1980874dd25de036b23468ecfbf8)<br>Afk bugfix Accidentally deleted essential code in cl_input Added 5 second wait time before using afk cmd again. | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b01a0a6ba02a`](https://github.com/eternalcodes/EternalJK/commit/b01a0a6ba02ad389f86be663857b77d164826c39)<br>Unfocus execute afk after 30 seconds | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |
| `2016-03-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`844387592b09`](https://github.com/eternalcodes/EternalJK/commit/844387592b09da5ca3a2b0f2f69f0646cf04bc1e)<br>Reset afkTime when window is refocused | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`cc95a484132f`](https://github.com/eternalcodes/EternalJK/commit/cc95a484132f02cdf1f95e7abf47d49f809aa12f)<br>Added cvar cl_afkTimeUnfocused, Added Cvar/Cmd descriptions This will allow you to set the amount of minutes to autorename to afk while the jka window is unfocused or minimized. The default is 1 minute. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-01-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2f4bc0464535`](https://github.com/eternalcodes/EternalJK/commit/2f4bc046453512d9d3faf5efce672a75ada83542)<br>Better defaults for afkTime* | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268)<br>chat styles | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3452](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3452) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1390](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1390)
- behavior: [codemp/client/cl_input.cpp:1398](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1398)
