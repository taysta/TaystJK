---
title: "fs_restart"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_restart`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Restarts the filesystem if no module is currently using files from a pk3

## At a glance

| Field | Value |
|:--|:--|
| Category | Files & downloads |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `fs_restart` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`97745ce2823e`](https://github.com/eternalcodes/EternalJK/commit/97745ce2823e9cb6f7ab683fcfe765cea40540ca) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-05-06`, integrated `2019-05-06`)
- Upstream registration evidence: [codemp/qcommon/files.cpp:4142](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/files.cpp#L4142)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-05-06` | — | `2019-05-06` | [`97745ce2823e`](https://github.com/eternalcodes/EternalJK/commit/97745ce2823e9cb6f7ab683fcfe765cea40540ca) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-05-06` | — | `2019-05-06` | [`97745ce2823e`](https://github.com/taysta/TaystJK/commit/97745ce2823e9cb6f7ab683fcfe765cea40540ca) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-05-06` | — | `2019-05-06` | [`97745ce2823e`](https://github.com/videoP/jaPRO/commit/97745ce2823e9cb6f7ab683fcfe765cea40540ca) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-05-06` | — | `2019-05-06` | [`97745ce2823e`](https://github.com/JKSunny/EternalJK/commit/97745ce2823e9cb6f7ab683fcfe765cea40540ca) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2019-12-14` | — | `2019-12-14` | [`491cc5c18cb6`](https://github.com/jkanewmod/NewJK/commit/491cc5c18cb6aac76cb30fba976634cc90d4cd12) | Other project appearance |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2023-02-26` | — | `2023-02-26` | [`ba97223aeff0`](https://github.com/mvdevs/jk2mv/commit/ba97223aeff0dec998fd555ef94d6c286a60d920) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-06` | [2023-11-07](https://github.com/JACoders/OpenJK/pull/1185) | `2024-04-07` | [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-06` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) · [PR #52](https://github.com/taysta/TaystJK/pull/52)<br>Merge pull request #52 from taysta/daggo-fs | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/files.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/files.cpp:4009](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4009) (Cmd_AddCommand)
- registration: [codemp/qcommon/files.cpp:4419](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4419) (Cmd_AddCommand)
- handler: [codemp/qcommon/files.cpp:4532](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4532)
