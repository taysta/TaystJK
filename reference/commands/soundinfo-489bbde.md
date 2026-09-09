---
title: "soundinfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `soundinfo`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Display information about the sound backend

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `soundinfo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/snd_dma.cpp:470](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/client/snd_dma.cpp#L470)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `high` |
| `2013-07-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a118ef1512c`](https://github.com/JACoders/OpenJK/commit/4a118ef1512c25b6fe5b24be4af48ef64a2232c6)<br>Merge pull request #318 from archSeer/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_dma_console.cpp`, `codemp/client/snd_dma_console.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `medium` |
| `2014-05-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8796b8716e49`](https://github.com/JACoders/OpenJK/commit/8796b8716e49c1613ad9a785251d4aecfbbb2c28)<br>[MP] Win64: Disable OpenAL for Win64 builds. | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `medium` |
| `2014-05-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16f7fe7ecc48`](https://github.com/JACoders/OpenJK/commit/16f7fe7ecc4842f32eea5dea5aeef4df9369b1ab)<br>[MP] Minor refactoring and cleanup in the sound code to move AL code all in a preprocessor. Removed an unnecessary loop in S_LoadSound_DirIsAllowedToKeepMP3s. | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `medium` |
| `2014-08-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b75a642873a7`](https://github.com/JACoders/OpenJK/commit/b75a642873a794d8fb0aad23ad48cb2e4cf95e9d)<br>[MP] Remove redundant sound is muted message in soundinfo. | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_dma.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/snd_dma.cpp` | `medium` |
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `medium` |
| `2025-05-22` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`94513af80121`](https://github.com/taysta/TaystJK/commit/94513af801211c817ed5607e7e3a49b49065189d) · [PR #241](https://github.com/taysta/TaystJK/pull/241)<br>Let non-windows users use OpenAL (#241) | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `medium` |
| `2025-07-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ad82e8b90`](https://github.com/taysta/TaystJK/commit/596ad82e8b90129c25458710b6af8d23944c78f4) · [PR #247](https://github.com/taysta/TaystJK/pull/247)<br>Merge pull request #247 from taysta/revert-linux-oal | Changed the registered command handler. `codemp/client/snd_dma.cpp` | `medium` |

## Evidence

- registration: [codemp/client/snd_dma.cpp:496](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L496) (Cmd_AddCommand)
- handler: [codemp/client/snd_dma.cpp:391](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L391)
