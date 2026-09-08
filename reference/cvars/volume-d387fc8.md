---
title: "volume"
layout: reference
nav_exclude: true
search_exclude: false
---

# `volume`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Volume

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1.0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) on `2013-04-07` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/snd_dma.cpp:454](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/snd_dma.cpp#L454)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3218605424b4`](https://github.com/JACoders/OpenJK/commit/3218605424b4341ccccb88705da1f43454606040)<br>Copied missing file from xbox dump. | Changed an exact bound cvar-variable reference. `ui/menudef.h` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed an exact bound cvar-variable reference. `codemp/ui/menudef.h` | `medium` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_shader.cpp`, `codemp/rd-vanilla/tr_bsp.cpp`, `codemp/rd-vanilla/tr_ghoul2.cpp` and 6 more | `high` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/game/g_misc.c` | `high` |
| `2013-10-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a053a56c558c`](https://github.com/JACoders/OpenJK/commit/a053a56c558cd195e6513410a24779ca411b6bab)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/game/surfaceflags.h`, `codemp/rd-dedicated/tr_shader.cpp`, `codemp/rd-vanilla/tr_shader.cpp` | `high` |
| `2013-10-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7d70edf1d46a`](https://github.com/JACoders/OpenJK/commit/7d70edf1d46a8f74fdb49811b745738d76c43725)<br>[MP] Style: remove vec_t, add matrix3_t | Changed an exact bound cvar-variable reference. `codemp/botlib/be_aas_reach.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/client/snd_ambient.cpp`, `codemp/client/snd_dma.cpp` | `medium` |
| `2014-07-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8c7cdd8ee135`](https://github.com/JACoders/OpenJK/commit/8c7cdd8ee135e1f3d94832f5a5bb4d7f9a228d48)<br>[MP] Revert 80f12fa97d4050cce9f9c1f5fb4e6c0f5d14cced. Apply several commits from ioq3's shader parser / COM_Parse fixes that were still missing. Remove deferLoad variable from ded and vanilla renderer tr_shader.cpp | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_shader.cpp` | `medium` |
| `2015-01-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8081c741036e`](https://github.com/JACoders/OpenJK/commit/8081c741036e5d75f22b3ac42a480a3cc3ba7426)<br>[MP] Fixed overlapping `s_channels` variable name in S_RawSamples. | Changed an exact bound cvar-variable reference. `codemp/client/snd_dma.cpp`, `codemp/client/snd_public.h` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_audio.h` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/snd_dma.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7f47620dbcbe`](https://github.com/eternalcodes/EternalJK/commit/7f47620dbcbe31a136df62264ebb2f387d502145)<br>Merge remote-tracking branch 'upstream/master' | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_hints.h` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/sqlite3.c` | `high` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `assets/japro/ui/jamp/menudef.h` | `medium` |
| `2018-05-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`097a0d05fa4e`](https://github.com/eternalcodes/EternalJK/commit/097a0d05fa4edb25c14bf88d42ea2bff668fd232)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_cin.cpp`, `codemp/client/snd_dma.cpp`, `codemp/client/snd_local.h` and 1 more | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_bsp.cpp`, `codemp/rd-vulkan/tr_ghoul2.cpp`, `codemp/rd-vulkan/tr_main.cpp` and 5 more | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_main.cpp`, `codemp/rd-vulkan/tr_shader.cpp`, `codemp/rd-vulkan/tr_shadows.cpp` and 1 more | `high` |
| `2021-10-24` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`bd3a458a8bb2`](https://github.com/JKSunny/EternalJK/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5)<br>Various fixes and upstream changes from Quake3e | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_shadows.cpp` | `high` |
| `2022-09-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`fe42dacccf12`](https://github.com/taysta/TaystJK/commit/fe42dacccf124754b9a9ff248910b546a4177cc3)<br>fix assets | Changed an exact bound cvar-variable reference. `assets/japro/ui/jamp/menudef.h` | `medium` |
| `2022-09-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`31d171b91e59`](https://github.com/taysta/TaystJK/commit/31d171b91e593464716899ecab11473e6316cb65)<br>fix assets | Changed an exact bound cvar-variable reference. `assets/japro/ui/jamp/menudef.h` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`405022446ca4`](https://github.com/taysta/TaystJK/commit/405022446ca43e90b746b5b9331fcaacc059e83b)<br>[OpenJK] Re-merge OpenJK into EJK [1] | Changed an exact bound cvar-variable reference. `codemp/client/snd_ambient.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_bsp.cpp`, `shared/rd-rend2/tr_flares.cpp`, `shared/rd-rend2/tr_ghoul2.cpp` and 7 more | `medium` |
| `2024-02-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) · [PR #157](https://github.com/taysta/TaystJK/pull/157)<br>Upstream update (#157) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_flares.cpp` | `medium` |
| `2024-02-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d69b773d4f8a`](https://github.com/videoP/jaPRO/commit/d69b773d4f8a1717f7237c7091a5cd7ac03acd60)<br>[jaPRO/Tribes] Add sound effect based on your speed for tribesmod | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |
| `2024-03-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0aa72e38fe9a`](https://github.com/videoP/jaPRO/commit/0aa72e38fe9a32fd94f7c768fc7dfa2395cb3a0c) · [PR #164](https://github.com/taysta/TaystJK/pull/164)<br>Japro update (#164) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |
| `2024-03-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`027d7505bfd1`](https://github.com/taysta/TaystJK/commit/027d7505bfd17765eaf4402d43d80524158cc8d6) · [PR #173](https://github.com/taysta/TaystJK/pull/173)<br>Macos input, libjpeg, libpng, zlib version updates (#173) | Changed an exact bound cvar-variable reference. `lib/jpeg-9c/jquant2.c` | `medium` |
| `2024-04-06` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`159821bdb1e0`](https://github.com/taysta/TaystJK/commit/159821bdb1e09d9265fa8313173521ae62ab15d3) · [PR #186](https://github.com/taysta/TaystJK/pull/186)<br>Upstream update (#186) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2025-04-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) · [PR #228](https://github.com/taysta/TaystJK/pull/228)<br>Update built in SDL version for windows to 2.32.4 (#228) | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_audio.h`, `lib/SDL2/include/SDL_hints.h` | `medium` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |

## Evidence

- registration: [codemp/client/snd_dma.cpp:454](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L454) (Cvar_Get)
- behavior: [codemp/client/cl_cin.cpp:1179](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cin.cpp#L1179)
- behavior: [codemp/client/cl_cin.cpp:1189](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cin.cpp#L1189)
- behavior: [codemp/client/snd_dma.cpp:4986](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L4986)
- behavior: [codemp/client/snd_dma.cpp:4998](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L4998)
- behavior: [codemp/client/snd_dma.cpp:5058](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L5058)
