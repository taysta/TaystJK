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
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
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

- Ultimate-origin introduction: [`aba934621843`](https://github.com/eternalcodes/EternalJK/commit/aba9346218436974329e85cbedbe5a7022651e14) on `2019-02-19` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:63](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L63)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-02-19` | [`aba934621843`](https://github.com/eternalcodes/EternalJK/commit/aba9346218436974329e85cbedbe5a7022651e14) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-02-19` | [`aba934621843`](https://github.com/taysta/TaystJK/commit/aba9346218436974329e85cbedbe5a7022651e14) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-02-19` | [`aba934621843`](https://github.com/videoP/jaPRO/commit/aba9346218436974329e85cbedbe5a7022651e14) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-02-19` | [`aba934621843`](https://github.com/JKSunny/EternalJK/commit/aba9346218436974329e85cbedbe5a7022651e14) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-08-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3ea9b3c38f7b`](https://github.com/eternalcodes/EternalJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704)<br>cg_chatBoxShowCutoff + emoji crash+whitespacing fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2023-10-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`6d949fdbbb78`](https://github.com/taysta/TaystJK/commit/6d949fdbbb78979c439b56d77bad5c6828572927)<br>Added additional checks to prevent unnecessary offsets lookups. - Fix dynamic table printing. - Remove unused cosmetic variables. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:76](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L76) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10949](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10949)
- behavior: [codemp/cgame/cg_draw.c:10986](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10986)
- behavior: [codemp/cgame/cg_draw.c:11002](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L11002)
