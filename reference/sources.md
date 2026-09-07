---
title: "Sources and methodology"
layout: reference
nav_order: 6
parent: "Console reference"
---

# Sources and methodology

The reference separates origin from current availability. An entry inherited from Raven remains **Base Jedi Academy** even though OpenJK and every fork ship it. A cvar registered only by `rd-vulkan` is not automatically Vulkan-originated: the resolver checks rend2 and other upstream snapshots first.

| Origin | Repository / snapshot | Role |
|:--|:--|:--|
| <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span> | [`JACoders/OpenJK@14cea1563762`](https://github.com/JACoders/OpenJK/tree/14cea1563762076974bee277afadbd5bf234c494) | Raven/id JA source present in OpenJK's initial import |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`JACoders/OpenJK@1a6a643427aa`](https://github.com/JACoders/OpenJK/tree/1a6a643427aa347553e9073dac5570b33337c4d9) | post-import OpenJK additions |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`eternalcodes/EternalJK@a40e793a802c`](https://github.com/eternalcodes/EternalJK/tree/a40e793a802c8db8df6132b711eea2fc846e5dd1) | EternalJK additions |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`videoP/jaPRO@a48764f18226`](https://github.com/videoP/jaPRO/tree/a48764f18226001c93680d7da6815b7d05c3784a) | jaPRO gameplay, HUD, movement, and admin work |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`mvdevs/jk2mv@7d601454c3db`](https://github.com/mvdevs/jk2mv/tree/7d601454c3db68492289d4d4e3dc30bff39e4246) | selected JK2MV ports |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | [`jkanewmod/NewJK@ad8d071f714a`](https://github.com/jkanewmod/NewJK/tree/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541) | NewJK and explicitly credited NewMod ports |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | [`SomaZ/OpenJK@788c19e97f02`](https://github.com/SomaZ/OpenJK/tree/788c19e97f02c0b68db29d63060305b6ad1580e5) | SomaZ rend2-unified renderer lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`JKSunny/EternalJK@b50059618803`](https://github.com/JKSunny/EternalJK/tree/b50059618803346a918f57220f856f1d0651dc39) | JKSunny Vulkan renderer lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`taysta/TaystJK@5802c999168d`](https://github.com/taysta/TaystJK/tree/5802c999168db2f9759a48f1ef3a3d672fa99722) | entries first evidenced in TaystJK after upstream checks |

## Evidence process

1. The extractor masks comments, follows preprocessor conditions, and recognizes XCVAR macros, legacy VM tables, direct and syscall `Cvar_Get`/`Cvar_Register` calls, dynamic format expansions, command tables, input tables, renderer tables, and server-forwarded command names.
2. The Raven baseline is OpenJK commit `14cea1563762076974bee277afadbd5bf234c494`, the initial JA source dump.
3. Exact names are compared across all configured upstream snapshots. Every non-base registration is also traced through TaystJK's registration-file history; squash bullets and PR bodies provide explicit port evidence even when several upstream heads share the same name.
4. Semantics come from source descriptions, `ui_xdocs.h`, jaPRO's checked-in documentation, handler/read sites, masks, comparisons, and range checks. Unproven fields stay in the review queue.
5. The dedicated runtime registry is reconciled separately. One runtime cannot contain client, UI, every platform, and all renderers, so the published inventory is the static union.

NewMod is closed source. Its [published feature documentation](https://jkanewmod.github.io/documentation.html) is useful semantic context, but the resolver attributes NewMod/NewJK only where a commit, PR, or nearby source comment explicitly says so, or where the open NewJK tree supplies direct evidence. A feature-page resemblance alone is not treated as origin proof.

## Confidence

- **High:** initial-import match, renderer-lineage proof, shared upstream commit, or explicit identifier/feature-group credit.
- **Medium:** exact upstream-head presence where multiple fork lineages overlap, or a current-only first-addition trace without independent upstream proof.
- **Low:** no reliable attribution; these remain `unknown`.

The [audit report](/TaystJK/reference/audit/) lists every medium/low attribution, incomplete semantic entry, and ambiguous registration-signature change.
