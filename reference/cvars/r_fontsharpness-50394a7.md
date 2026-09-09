---
title: "r_fontSharpness"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_fontSharpness`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Relative font sharpness (doesn't affect console font).

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Always use original low-res fonts. | [CVARS.rst:291](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L291) |
| `1` | Best quality (in fau's opinion). | [CVARS.rst:292](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L292) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`c97dadc5db5c`](https://github.com/mvdevs/jk2mv/commit/c97dadc5db5c49c3eb5d893ff3ef4d3655aceb5d) in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> (content authored `2016-02-29`, integrated `2016-03-01`)
- TaystJK integration evidence: [`e8e1da168ed5`](https://github.com/taysta/TaystJK/commit/e8e1da168ed586bb1f7c64ec1f9d2baf764bba63)
- Upstream registration evidence: [src/renderer/tr_init.cpp:1231](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/renderer/tr_init.cpp#L1231)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-02-29` | — | `2016-03-01` | [`c97dadc5db5c`](https://github.com/mvdevs/jk2mv/commit/c97dadc5db5c49c3eb5d893ff3ef4d3655aceb5d) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-12` | — | `2023-11-28` | [`e8e1da168ed5`](https://github.com/taysta/TaystJK/commit/e8e1da168ed586bb1f7c64ec1f9d2baf764bba63) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-12` | — | `2023-11-28` | [`e8e1da168ed5`](https://github.com/videoP/jaPRO/commit/e8e1da168ed586bb1f7c64ec1f9d2baf764bba63) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-12` | — | `2024-02-08` | [`01697e61fe58`](https://github.com/JACoders/OpenJK/commit/01697e61fe586e31591dd236e1d4441c92f41a8a) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-12` | — | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`e8e1da168ed5`](https://github.com/taysta/TaystJK/commit/e8e1da168ed586bb1f7c64ec1f9d2baf764bba63)<br>Merge branch 'font-sharpness' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-common/tr_font.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-common/tr_font.cpp:1842](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1842) (Cvar_Get)
- behavior: [codemp/rd-common/tr_font.cpp:1171](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1171)
- upstream-documentation: [CVARS.rst:289](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L289)
