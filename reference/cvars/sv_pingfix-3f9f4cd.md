---
title: "sv_pingFix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_pingFix`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Enable more accurate and bug-free ping calculation.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`c318f53b8b22`](https://github.com/mvdevs/jk2mv/commit/c318f53b8b22e64d301fd19f0abf83613b8f6940) on `2017-12-13` in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>
- TaystJK integration evidence: [`dc3c8171d100`](https://github.com/taysta/TaystJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae)
- Upstream registration evidence: [src/server/sv_init.cpp:887](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/server/sv_init.cpp#L887)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`
- Notes: The TaystJK integration evidence credits eternaljk as an immediate port source, but jk2mv has an earlier dated introduction and remains the ultimate origin. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2017-12-13` | [`c318f53b8b22`](https://github.com/mvdevs/jk2mv/commit/c318f53b8b22e64d301fd19f0abf83613b8f6940) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-15` | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-15` | [`dc3c8171d100`](https://github.com/taysta/TaystJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-15` | [`dc3c8171d100`](https://github.com/videoP/jaPRO/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Later project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-15` | [`dc3c8171d100`](https://github.com/JKSunny/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae) | Later project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>. The earlier dated project remains the ultimate origin.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/server.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` and 2 more | `high` |
| `2019-05-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`953b37ce8fef`](https://github.com/eternalcodes/EternalJK/commit/953b37ce8fefe7b3345243263f0334975ef59845)<br>kick cheaters | Changed an exact bound cvar-variable reference. `codemp/server/server.h` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1065](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1065) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:1743](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1743)
- behavior: [codemp/server/sv_main.cpp:924](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L924)
- behavior: [codemp/server/sv_client.cpp:1744](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1744)
- behavior: [codemp/server/sv_snapshot.cpp:813](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L813)
- behavior: [codemp/server/sv_client.cpp:1742](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1742)
- upstream-documentation: [CVARS.rst:634](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L634)
