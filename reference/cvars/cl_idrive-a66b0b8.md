---
title: "cl_idrive"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_idrive`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_idrive` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`e0d7a341bc6c`](https://github.com/videoP/jaPRO/commit/e0d7a341bc6c9a68a359941a4065e9c6b408305a) on `2017-12-05` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/client/cl_input.cpp:1832](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/client/cl_input.cpp#L1832)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. An identifier-adjacent source/commit/PR line explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-05` | [`e0d7a341bc6c`](https://github.com/eternalcodes/EternalJK/commit/e0d7a341bc6c9a68a359941a4065e9c6b408305a) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-05` | [`e0d7a341bc6c`](https://github.com/taysta/TaystJK/commit/e0d7a341bc6c9a68a359941a4065e9c6b408305a) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-05` | [`e0d7a341bc6c`](https://github.com/videoP/jaPRO/commit/e0d7a341bc6c9a68a359941a4065e9c6b408305a) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-05` | [`e0d7a341bc6c`](https://github.com/JKSunny/EternalJK/commit/e0d7a341bc6c9a68a359941a4065e9c6b408305a) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_input.cpp`, `codemp/client/cl_main.cpp`, `codemp/client/client.h` | `high` |
| `2018-01-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`29fab10414c2`](https://github.com/videoP/jaPRO/commit/29fab10414c2fb7cc29d04a1dbff04f912709fab)<br>Unused japro engine code part 3 | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `high` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_input.cpp:1832](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1832) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:494](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L494)
- behavior: [codemp/client/cl_input.cpp:904](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L904)
- behavior: [codemp/client/cl_input.cpp:918](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L918)
- behavior: [codemp/client/cl_input.cpp:931](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L931)
- behavior: [codemp/client/cl_input.cpp:944](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L944)
