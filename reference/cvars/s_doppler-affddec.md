---
title: "s_doppler"
layout: reference
nav_exclude: true
search_exclude: false
---

# `s_doppler`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `s_doppler` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
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

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`69800e894dff`](https://github.com/JACoders/OpenJK/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) on `2013-10-22` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/client/snd_dma.cpp:452](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/snd_dma.cpp#L452)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-10-22` | [`69800e894dff`](https://github.com/JACoders/OpenJK/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-10-22` | [`69800e894dff`](https://github.com/eternalcodes/EternalJK/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-10-22` | [`69800e894dff`](https://github.com/SomaZ/OpenJK/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-10-22` | [`69800e894dff`](https://github.com/taysta/TaystJK/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-10-22` | [`69800e894dff`](https://github.com/videoP/jaPRO/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-10-22` | [`69800e894dff`](https://github.com/jkanewmod/NewJK/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-10-22` | [`69800e894dff`](https://github.com/JKSunny/EternalJK/commit/69800e894dff5ea9fcad22c26cc41c9bbf250216) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2015-03-19` | [`907e53cc40d4`](https://github.com/mvdevs/jk2mv/commit/907e53cc40d4a9a3b0ea7cc9abf815221eef8e1a) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/snd_dma.cpp` | `medium` |

## Evidence

- registration: [codemp/client/snd_dma.cpp:478](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L478) (Cvar_Get)
- behavior: [codemp/client/snd_dma.cpp:2012](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L2012)
