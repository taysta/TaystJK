---
title: "g_fixWeaponAttackAnim"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixWeaponAttackAnim`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fixWeaponAttackAnim` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/bg_misc.c:466](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_misc.c#L466) |
| `1` | Enabled. | [codemp/game/bg_misc.c:466](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_misc.c#L466) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`1e8a7998ca2f`](https://github.com/JACoders/OpenJK/commit/1e8a7998ca2fe434daebb41d586ac3cd5296433a) on `2024-02-20` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d)
- Pull request: [#157](https://github.com/taysta/TaystJK/pull/157)
- Matching squash bullet: `move BASE_COMPAT flag behind cmake option BuildMPWithCompatMode, add g_fixWeaponAttackAnim making use of CS_LEGACY_FIXES`
- Upstream registration evidence: [codemp/game/g_xcvar.h:98](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L98)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-20` | [`1e8a7998ca2f`](https://github.com/JACoders/OpenJK/commit/1e8a7998ca2fe434daebb41d586ac3cd5296433a) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-26` | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-26` | [`cd784cbf26da`](https://github.com/videoP/jaPRO/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) | Later project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Later project appearance |

## Evidence

- registration: [codemp/game/g_xcvar.h:96](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L96) (XCVAR_DEF)
- behavior: [codemp/game/bg_misc.c:466](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_misc.c#L466)
- behavior: [codemp/game/g_cvar.c:636](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cvar.c#L636)
