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
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`eternalcodes/EternalJK@a40e793a802c`](https://github.com/eternalcodes/EternalJK/tree/a40e793a802c8db8df6132b711eea2fc846e5dd1) | public EternalJK additions and explicitly credited private continuation work |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`videoP/jaPRO@33d1f1e22ac6`](https://github.com/videoP/jaPRO/tree/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3) | jaPRO gameplay, HUD, movement, and admin work |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`mvdevs/jk2mv@7d601454c3db`](https://github.com/mvdevs/jk2mv/tree/7d601454c3db68492289d4d4e3dc30bff39e4246) | selected JK2MV ports |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | [`jkanewmod/NewJK@ad8d071f714a`](https://github.com/jkanewmod/NewJK/tree/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541) | NewJK and explicitly credited NewMod ports |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | [`SomaZ/OpenJK@788c19e97f02`](https://github.com/SomaZ/OpenJK/tree/788c19e97f02c0b68db29d63060305b6ad1580e5) | SomaZ rend2-unified renderer lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`JKSunny/EternalJK@b50059618803`](https://github.com/JKSunny/EternalJK/tree/b50059618803346a918f57220f856f1d0651dc39) | JKSunny Vulkan renderer lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`taysta/TaystJK@6ff04c0baf58`](https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655) | entries first evidenced in TaystJK after upstream checks |

## Evidence process

1. The extractor masks comments, follows preprocessor conditions, and recognizes XCVAR macros, legacy VM tables, direct and syscall `Cvar_Get`/`Cvar_Register` calls, dynamic format expansions, command tables, input tables, renderer tables, and server-forwarded command names.
2. The Raven baseline is OpenJK commit `14cea1563762076974bee277afadbd5bf234c494`, the initial JA source dump.
3. For every non-base name, the resolver finds its first registration on the current first-parent line of TaystJK, OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2, and Vulkan. It separately records the exact registration's first author date, the target project's PR creation date, and the mainline integration date. Authorship and submission are considered before merge order, so merging an upstream PR into TaystJK first does not make TaystJK its origin.
4. Equal chronology is resolved only afterward, using explicit cross-project PR links and shared commits as fork-lineage evidence. PR numbers are scoped to their target repository, and a lone available PR date is not compared against candidates whose PR archive was not supplied. Squash bullets, commit bodies, and PR descriptions can identify an immediate port source, while identifier-adjacent developer credit can identify an unpublished project continuation. A later intermediate source cannot displace an earlier authored, submitted, or explicitly credited origin.
5. After origin is established, a separate TaystJK first-parent patch scan records exact registration changes, changed bound cvar-variable references, and edits within registered command-handler hunks. Each change is dated and attributed from explicit commit/PR credit or project-mainline membership; shared change commits remain medium-confidence.
6. Semantics come from source descriptions, `ui_xdocs.h`, jaPRO's checked-in documentation, handler/read sites, masks, comparisons, and range checks. The generator separately records exact xdocs declarations and appearances in shipped `.menu` files.
7. Stable topic rules classify broad areas, while curated feature-family rules keep related controls such as `cg_killfeed…` together. Unproven semantic fields stay in the review queue.
8. The dedicated runtime registry is reconciled separately. One runtime cannot contain client, UI, every platform, and all renderers, so the published inventory is the static union.

NewMod is closed source. Its [published feature documentation](https://jkanewmod.github.io/documentation.html) is useful semantic context, but the resolver attributes NewMod/NewJK only where a commit, PR, or nearby source comment explicitly says so, or where the open NewJK tree supplies direct evidence. A feature-page resemblance alone is not treated as origin proof.

Bucky's later EternalJK continuation was also shared privately. Explicit `Bucky` or `Bucky21659` credit next to an identifier is therefore treated as EternalJK lineage even when the historical label says `jaPRO/Bucky`. The public-introduction table still shows where that code first became available in a published repository; it does not invent an EternalJK commit for unpublished source.

Contributor identity is not treated as permanent project identity. `cg_chatBoxEmojis` is a curated historical exception: Sunny contributed the feature to EternalJK before starting work on Vulkan, so the JKSunny branch name identifies the contributor there rather than Vulkan lineage.

## Confidence

- **High:** initial-import match, a unique earliest authored/submitted project introduction, explicit identifier/feature-group credit consistent with chronology, or curated maintainer-supplied historical attribution.
- **Medium:** shared-commit lineage (a Git object has no repository-of-origin field), tied author/PR/integration dates, or exact upstream-head presence when registration-file history cannot be followed.
- **Low:** no reliable attribution; these remain `unknown`.

The [audit report](/TaystJK/reference/audit/) lists every medium/low attribution, incomplete semantic entry, and ambiguous registration-signature change.
