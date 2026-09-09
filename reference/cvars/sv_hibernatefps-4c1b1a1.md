---
title: "sv_hibernateFPS"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_hibernateFPS`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

The fps to use while the server is in hibernation mode.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `2` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Enforced ranges

- `1` through `1000` (integer; Cvar_CheckRange) — [codemp/server/sv_init.cpp:1068](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1068)

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`78f1a2051c05`](https://github.com/mvdevs/jk2mv/commit/78f1a2051c0535bee856781ffa59229e61974432) in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> (content authored `2017-05-21`, integrated `2017-05-21`)
- TaystJK integration evidence: [`c648f59e6b35`](https://github.com/taysta/TaystJK/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1)
- Upstream registration evidence: [src/server/sv_init.cpp:885](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/server/sv_init.cpp#L885)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2017-05-21` | — | `2017-05-21` | [`78f1a2051c05`](https://github.com/mvdevs/jk2mv/commit/78f1a2051c0535bee856781ffa59229e61974432) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-14` | — | `2018-10-14` | [`c648f59e6b35`](https://github.com/eternalcodes/EternalJK/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-14` | — | `2018-10-14` | [`c648f59e6b35`](https://github.com/taysta/TaystJK/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-14` | — | `2018-10-14` | [`c648f59e6b35`](https://github.com/videoP/jaPRO/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-14` | — | `2018-10-14` | [`c648f59e6b35`](https://github.com/JKSunny/EternalJK/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-10-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c648f59e6b35`](https://github.com/eternalcodes/EternalJK/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1)<br>hibernate redo | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/server.h`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1067](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1067) (Cvar_Get)
- behavior: [codemp/server/sv_main.cpp:1165](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1165)
- behavior: [codemp/server/sv_main.cpp:1232](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1232)
- behavior: [codemp/server/sv_init.cpp:1068](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1068)
- upstream-documentation: [CVARS.rst:581](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L581)
