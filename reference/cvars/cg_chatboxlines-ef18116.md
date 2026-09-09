---
title: "cg_chatBoxLines"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBoxLines`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

This would be called chatBoxHeight if baseJKA didn't use that

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `5` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`aba934621843`](https://github.com/eternalcodes/EternalJK/commit/aba9346218436974329e85cbedbe5a7022651e14) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-02-19`, integrated `2019-02-19`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:63](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L63)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-02-19` | — | `2019-02-19` | [`aba934621843`](https://github.com/eternalcodes/EternalJK/commit/aba9346218436974329e85cbedbe5a7022651e14) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-02-19` | — | `2019-02-19` | [`aba934621843`](https://github.com/taysta/TaystJK/commit/aba9346218436974329e85cbedbe5a7022651e14) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-02-19` | — | `2019-02-19` | [`aba934621843`](https://github.com/videoP/jaPRO/commit/aba9346218436974329e85cbedbe5a7022651e14) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-02-19` | — | `2019-02-19` | [`aba934621843`](https://github.com/JKSunny/EternalJK/commit/aba9346218436974329e85cbedbe5a7022651e14) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-08-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3ea9b3c38f7b`](https://github.com/eternalcodes/EternalJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704)<br>cg_chatBoxShowCutoff + emoji crash+whitespacing fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2023-10-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`6d949fdbbb78`](https://github.com/taysta/TaystJK/commit/6d949fdbbb78979c439b56d77bad5c6828572927)<br>Added additional checks to prevent unnecessary offsets lookups. - Fix dynamic table printing. - Remove unused cosmetic variables. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:76](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L76) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10949](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10949)
- behavior: [codemp/cgame/cg_draw.c:10986](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10986)
- behavior: [codemp/cgame/cg_draw.c:11002](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L11002)
