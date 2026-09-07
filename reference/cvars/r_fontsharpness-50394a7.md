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

- Commit evidence: [`9fbdb124bc72`](https://github.com/taysta/TaystJK/commit/9fbdb124bc7265eb93d0a291ff0e68f9fe9458c2)
- Upstream registration evidence: [src/renderer/tr_init.cpp:1231](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/renderer/tr_init.cpp#L1231)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-common/tr_font.cpp:1842](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1842) (Cvar_Get)
- behavior: [codemp/rd-common/tr_font.cpp:1171](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1171)
- upstream-documentation: [CVARS.rst:289](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L289)
