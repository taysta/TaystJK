---
title: "ui_version"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_version`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Used by UI in the in-game "about" menu

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `Info_ValueForKey(info, "version")` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`e4ececfdb4d1`](https://github.com/videoP/jaPRO/commit/e4ececfdb4d1033473d6f502615964281530d401) on `2018-10-04` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/cgame/cg_servercmds.c:236](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_servercmds.c#L236)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/eternalcodes/EternalJK/commit/e4ececfdb4d1033473d6f502615964281530d401) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/taysta/TaystJK/commit/e4ececfdb4d1033473d6f502615964281530d401) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/videoP/jaPRO/commit/e4ececfdb4d1033473d6f502615964281530d401) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/JKSunny/EternalJK/commit/e4ececfdb4d1033473d6f502615964281530d401) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_servercmds.c:236](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_servercmds.c#L236) (implicit Cvar_Set)
- behavior: [codemp/ui/ui_main.c:3364](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L3364)
- behavior: [assets/japro/ui/jamp/menudef.h:346](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/assets/japro/ui/jamp/menudef.h#L346)
- behavior: [codemp/ui/menudef.h:346](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/menudef.h#L346)
- behavior: [codemp/ui/ui_main.c:3084](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L3084)
- behavior: [codemp/ui/ui_main.c:3087](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L3087)
