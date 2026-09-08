---
title: "sv_banFile"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_banFile`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

File to use to store bans and exceptions

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `serverbans.dat` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`73e537fdea26`](https://github.com/JACoders/OpenJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) on `2014-08-16` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/server/sv_init.cpp:1011](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1011)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-08-16` | [`73e537fdea26`](https://github.com/JACoders/OpenJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-08-16` | [`73e537fdea26`](https://github.com/eternalcodes/EternalJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-08-16` | [`73e537fdea26`](https://github.com/SomaZ/OpenJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-08-16` | [`73e537fdea26`](https://github.com/taysta/TaystJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-08-16` | [`73e537fdea26`](https://github.com/videoP/jaPRO/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-08-16` | [`73e537fdea26`](https://github.com/jkanewmod/NewJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-08-16` | [`73e537fdea26`](https://github.com/JKSunny/EternalJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1049](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1049) (Cvar_Get)
- behavior: [codemp/server/sv_ccmds.cpp:628](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L628)
- behavior: [codemp/server/sv_ccmds.cpp:702](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L702)
- behavior: [codemp/server/sv_ccmds.cpp:631](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L631)
- behavior: [codemp/server/sv_ccmds.cpp:705](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L705)
