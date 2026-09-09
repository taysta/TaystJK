---
title: "ui_isJAPro"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_isJAPro`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_isJAPro` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
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

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`f4405327b936`](https://github.com/videoP/jaPRO/commit/f4405327b9363ad0b91cd0ae1717fe9ed939982b) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-02-06`, integrated `2018-02-06`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:159](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/ui/ui_xcvar.h#L159)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-02-06` | — | `2018-02-06` | [`f4405327b936`](https://github.com/eternalcodes/EternalJK/commit/f4405327b9363ad0b91cd0ae1717fe9ed939982b) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-02-06` | — | `2018-02-06` | [`f4405327b936`](https://github.com/taysta/TaystJK/commit/f4405327b9363ad0b91cd0ae1717fe9ed939982b) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-02-06` | — | `2018-02-06` | [`f4405327b936`](https://github.com/videoP/jaPRO/commit/f4405327b9363ad0b91cd0ae1717fe9ed939982b) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-02-06` | — | `2018-02-06` | [`f4405327b936`](https://github.com/JKSunny/EternalJK/commit/f4405327b9363ad0b91cd0ae1717fe9ed939982b) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-02-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6a8d7a01015a`](https://github.com/eternalcodes/EternalJK/commit/6a8d7a01015af48013b58b64390de2ffe982cfa3)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-02-10` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`697cfad347d9`](https://github.com/videoP/jaPRO/commit/697cfad347d92f7833f5663f5f27014e9e83b290)<br>Moved ui_isJAPro from cgame to UI. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `high` |
| `2018-03-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`852cd1037427`](https://github.com/eternalcodes/EternalJK/commit/852cd10374272a0195a05ac15e9b69c2313ecaff)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:159](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L159) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:1061](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L1061)
- behavior: [codemp/ui/ui_main.c:628](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L628)
- behavior: [codemp/ui/ui_main.c:652](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L652)
