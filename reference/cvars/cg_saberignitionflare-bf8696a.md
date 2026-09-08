---
title: "cg_saberIgnitionFlare"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_saberIgnitionFlare`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_saberIgnitionFlare` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`66fe36b094c3`](https://github.com/taysta/TaystJK/commit/66fe36b094c3fbae2629049c48080c385f6d661a) on `2023-11-04` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#43](https://github.com/taysta/TaystJK/pull/43)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:175](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L175)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-04` | [`66fe36b094c3`](https://github.com/taysta/TaystJK/commit/66fe36b094c3fbae2629049c48080c385f6d661a) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-04` | [`66fe36b094c3`](https://github.com/videoP/jaPRO/commit/66fe36b094c3fbae2629049c48080c385f6d661a) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:175](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L175) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_players.c:6386](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_players.c#L6386)
- behavior: [codemp/cgame/cg_players.c:6628](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_players.c#L6628)
