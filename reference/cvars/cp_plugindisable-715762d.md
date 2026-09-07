---
title: "cp_pluginDisable"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cp_pluginDisable`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

'enable' holstered saber (512) and ledge grab (1536) by default, to avoid missing JA+ animations

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `feature-flagged` — Client behavior is negotiated through a server feature flag. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1536` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `524288` | Enables the `JAPRO_PLUGIN_BHOP` code path. | [codemp/game/bg_public.h:538](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_public.h#L538) |
| `134217728` | Enables the `JAPRO_PLUGIN_CENTERMUZZLE` code path. | [codemp/game/bg_public.h:546](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_public.h#L546) |
| `2` | Enables the `JAPRO_PLUGIN_DUELSEEOTHERS` code path. | [codemp/game/bg_public.h:516](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_public.h#L516) |
| `1048576` | Enables the `JAPRO_PLUGIN_NOROLL` code path. | [codemp/game/bg_public.h:539](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_public.h#L539) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_USERINFO` — sent in the client's userinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`6d1ce422d75a`](https://github.com/taysta/TaystJK/commit/6d1ce422d75a7878d14afb9669f410b497580dcf)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:175](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/cgame/cg_xcvar.h#L175)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:195](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L195) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_ents.c:933](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_ents.c#L933)
- behavior: [codemp/cgame/cg_players.c:10782](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_players.c#L10782)
- behavior: [codemp/cgame/cg_weapons.c:2390](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L2390)
- behavior: [codemp/game/bg_pmove.c:3546](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L3546)
- behavior: [codemp/game/bg_pmove.c:6220](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L6220)
