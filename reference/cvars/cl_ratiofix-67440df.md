---
title: "cl_ratioFix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_ratioFix`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Widescreen aspect ratio correction

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `cgame`, `engine-client`, `renderer`, `ui` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/rd-common/tr_font.cpp:1458](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1458) |
| `2` | Selects the code path tested for value 2. | [codemp/rd-common/tr_font.cpp:1461](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1461) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `cgame` | `—` | `always` |
| `1` | `engine-client` | `—` | `always` |
| `1` | `renderer` | `rd-rend2` | `always` |
| `1` | `renderer` | `rd-vanilla` | `always` |
| `1` | `renderer` | `rd-vulkan` | `always` |
| `1` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`b713e21a0ea8`](https://github.com/videoP/jaPRO/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2017-12-04`, integrated `2017-12-04`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:140](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L140)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-04` | — | `2017-12-04` | [`b713e21a0ea8`](https://github.com/eternalcodes/EternalJK/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-04` | — | `2017-12-04` | [`b713e21a0ea8`](https://github.com/taysta/TaystJK/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-04` | — | `2017-12-04` | [`b713e21a0ea8`](https://github.com/videoP/jaPRO/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-04` | — | `2017-12-04` | [`b713e21a0ea8`](https://github.com/JKSunny/EternalJK/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2019-06-02` | — | `2019-06-02` | [`e2b6a454fbf6`](https://github.com/jkanewmod/NewJK/commit/e2b6a454fbf6aab9491ac691d66b836f0a925c16) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3)<br>Merge pull request #3 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2017-12-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7f89e408e24d`](https://github.com/eternalcodes/EternalJK/commit/7f89e408e24db297110b4ab3f952a52f33a55ddf)<br>CGame Fix CG_Set2DRatio | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-03-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b541a7cae32a`](https://github.com/eternalcodes/EternalJK/commit/b541a7cae32a079e46a4d32b46890747d5be65e6)<br>Ratio fix character width with cl_ratioFix 1 | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-common/tr_font.cpp`, `codemp/rd-vanilla/tr_init.cpp`, `codemp/rd-vanilla/tr_local.h` | `medium` |
| `2018-03-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`36618a2e4800`](https://github.com/eternalcodes/EternalJK/commit/36618a2e480004c923bb5f65e9507e8b7b9d5d3c)<br>Ratiofix spaces. | Changed an exact bound cvar-variable reference. `codemp/rd-common/tr_font.cpp` | `medium` |
| `2018-03-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ea109c7da9c2`](https://github.com/eternalcodes/EternalJK/commit/ea109c7da9c2138437224f9ca4cd27803882ce9a)<br>Fixed dropshadows. | Changed an exact bound cvar-variable reference. `codemp/rd-common/tr_font.cpp` | `medium` |
| `2018-03-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`25a0b7fef8a3`](https://github.com/eternalcodes/EternalJK/commit/25a0b7fef8a386f3dbf6c8de98bd0f137c5184e4)<br>Cleaned up ratio correction code in engine and renderer | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/rd-common/tr_font.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_xcvar.h`, `codemp/client/cl_main.cpp`, `codemp/rd-common/tr_font.cpp` and 1 more | `high` |
| `2019-01-14` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`18a8e8c9a528`](https://github.com/taysta/TaystJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47)<br>FPS independent camera damping (cg_cameraFPS from fau's SaberMod) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803)<br>Implement Blackwolf's Discord Integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_xcvar.h`, `codemp/rd-vanilla/tr_cmds.cpp`, `codemp/ui/ui_shared.c` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cmds.cpp`, `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/vk_init.cpp` | `high` |
| `2022-02-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`723c24a13050`](https://github.com/JKSunny/EternalJK/commit/723c24a130509bedc156847c5dbc4b5bf39ed0fb)<br>Vulkan: Fixed entity wall clipping & refactor fastsky color for performance | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cmds.cpp` | `high` |
| `2022-04-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`a781c5543017`](https://github.com/JKSunny/EternalJK/commit/a781c5543017fdc50f01161f0303fc68e03da38d)<br>Vulkan: Fix missing oneShotAnimMap & missing lightmap/vertexlight on certain surfaces | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_init.cpp` | `high` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_cmds.cpp`, `shared/rd-rend2/tr_local.h` | `medium` |
| `2024-05-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`52eb7b38693d`](https://github.com/taysta/TaystJK/commit/52eb7b38693d9a401b48a58a87af6e9a7dfdbac9) · [PR #195](https://github.com/taysta/TaystJK/pull/195)<br>Fixup discord rich presence application ID/Name, 64-bit discord integration (#195) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2025-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`792015e7f511`](https://github.com/taysta/TaystJK/commit/792015e7f5112ec789617327e3f5817130d2d074) · [PR #276](https://github.com/taysta/TaystJK/pull/276)<br>Merge pull request #276 from slash-fr/levelshots_16_9 | Changed an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp`, `codemp/rd-vulkan/vk_init.cpp` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:143](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L143) (XCVAR_DEF)
- registration: [codemp/client/cl_main.cpp:3442](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3442) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1696](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1696) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1743](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1743) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:905](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L905) (Cvar_Get)
- registration: [codemp/ui/ui_xcvar.h:37](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L37) (XCVAR_DEF)
- behavior: [codemp/client/cl_main.cpp:2422](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2422)
- behavior: [codemp/rd-common/tr_font.cpp:1458](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1458)
- behavior: [codemp/rd-common/tr_font.cpp:1461](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1461)
- behavior: [codemp/rd-common/tr_font.cpp:1760](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1760)
- behavior: [codemp/rd-common/tr_font.cpp:1764](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1764)
