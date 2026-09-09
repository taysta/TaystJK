---
title: "g_reducesaberblock"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_reducesaberblock`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Percent chance to deny a valid MP saber block/clash. 0=off, 100=always.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Off. | [docs/japro_docs.md:14](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L14) |
| `100` | Always. | [docs/japro_docs.md:14](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L14) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`1ca8755a9105`](https://github.com/videoP/jaPRO/commit/1ca8755a910522142deee632f607e2505f6c083a) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2026-06-02`, integrated `2026-06-03`)
- Origin pull request: [#317](https://github.com/taysta/TaystJK/pull/317)
- Upstream registration evidence: [codemp/game/g_xcvar.h:195](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L195)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-06-02` | [2026-06-03](https://github.com/taysta/TaystJK/pull/317) | `2026-06-03` | [`1ca8755a9105`](https://github.com/taysta/TaystJK/commit/1ca8755a910522142deee632f607e2505f6c083a) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-06-02` | — | `2026-06-03` | [`1ca8755a9105`](https://github.com/videoP/jaPRO/commit/1ca8755a910522142deee632f607e2505f6c083a) | Ultimate origin |

## Evidence

- registration: [codemp/game/g_xcvar.h:194](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L194) (XCVAR_DEF)
- behavior: [codemp/game/w_saber.c:5000](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_saber.c#L5000)
- documentation: [docs/japro_docs.md:14](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L14)
