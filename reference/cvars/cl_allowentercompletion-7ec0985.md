---
title: "cl_allowEnterCompletion"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_allowEnterCompletion`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Enables autocomplete when pressing enter

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L858) |
| `1` | Enabled. | [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L858) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`d23425fac341`](https://github.com/eternalcodes/EternalJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) on `2016-08-04` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:3275](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3275)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-08-04` | [`d23425fac341`](https://github.com/eternalcodes/EternalJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-08-04` | [`d23425fac341`](https://github.com/taysta/TaystJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-08-04` | [`d23425fac341`](https://github.com/videoP/jaPRO/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-08-04` | [`d23425fac341`](https://github.com/JKSunny/EternalJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2017-03-09` | [`acb5bdd2c483`](https://github.com/jkanewmod/NewJK/commit/acb5bdd2c483c02cf23e98d7d2703645b2b4edff) | Later project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3364](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3364) (Cvar_Get)
- behavior: [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L858)
