---
title: "cg_chatBoxShowCutoff"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBoxShowCutoff`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_chatBoxShowCutoff` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_draw.c:10777](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10777) |
| `1` | Enabled. | [codemp/cgame/cg_draw.c:10777](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10777) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`3ea9b3c38f7b`](https://github.com/eternalcodes/EternalJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704) on `2020-08-10` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:68](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L68)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2020-08-10` | [`3ea9b3c38f7b`](https://github.com/eternalcodes/EternalJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2020-08-10` | [`3ea9b3c38f7b`](https://github.com/taysta/TaystJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2020-08-10` | [`3ea9b3c38f7b`](https://github.com/videoP/jaPRO/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2020-08-10` | [`3ea9b3c38f7b`](https://github.com/JKSunny/EternalJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-08-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`17c84c9c315e`](https://github.com/eternalcodes/EternalJK/commit/17c84c9c315e4478ae577403c7f337d18fa7da25)<br>Fix chatbox emoji line cutoff? | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:81](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L81) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10777](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10777)
- behavior: [codemp/cgame/cg_draw.c:10846](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10846)
