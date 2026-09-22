---
title: "g_tweakSaber"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_tweakSaber`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>tweakSaber</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Configured with /tweakSaber command.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2018-01-01 in [`d9d510063`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) <span class="status-chip">needs review</span> — [how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`tweakSaber`](/TaystJK/reference/commands/tweaksaber-e5f1b57/) |

## Bits

Use [`tweakSaber`](/TaystJK/reference/commands/tweaksaber-e5f1b57/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own — [the labels come from the source table](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L915).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | Skip saber interpolate for MP dmgs | — |
| 1 | `2` | JK2 1.02 style damage system | — |
| 2 | `4` | Reduced saberblock for MP damages | — |
| 3 | `8` | Reduce saberdrops for MP damages | — |
| 4 | `16` | Allow rollcancel for saber swings | [codemp/game/g_local.h:277](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L277) |
| 5 | `32` | JK2 1.02 style swings | [codemp/game/g_local.h:278](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L278) |
| 6 | `64` | Fixed saberswitch | [codemp/game/g_local.h:279](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L279) |
| 7 | `128` | No aim backslash | [codemp/game/g_local.h:280](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L280) |
| 8 | `256` | JK2 red DFA | [codemp/game/g_local.h:281](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L281) |
| 9 | `512` | Fix yellow DFA | — |
| 10 | `1024` | Spin red DFA | — |
| 11 | `2048` | Spin backslash | [codemp/game/g_local.h:284](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L284) |
| 12 | `4096` | JK2 lunge | — |
| 13 | `8192` | Remove red DFA Boost | — |
| 14 | `16384` | Make red DFA cost 0 forcepoints | — |
| 15 | `32768` | Remove all backslash restrictions | — |
| 16 | `65536` | Allow sabergun | — |
| 17 | `131072` | Allow fast style change for single saber | — |
| 18 | `262144` | New dmg calculation for SP damage (no vel dmg) | — |
| 19 | `524288` | The slow blade penetrates the sheild | — |
| 20 | `1048576` | New dmg calculation for SP damage (capped vel dmg) | — |
## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2015-04-17`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:194](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L194)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/game/bg_saber.c`, `codemp/game/g_active.c` | `high` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6b8655edcd6a`](https://github.com/eternalcodes/EternalJK/commit/6b8655edcd6adab847f2f929153cce5f35908e96)<br>ok | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c`, `codemp/game/w_saber.c` | `high` |
| `2018-10-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d5b95947d04f`](https://github.com/videoP/jaPRO/commit/d5b95947d04f3fb485bbfccb41c5ecadd1587946)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/w_saber.c` | `high` |
| `2020-03-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`27748943c598`](https://github.com/eternalcodes/EternalJK/commit/27748943c59875f3840c521a89089d5936d632c8)<br>Fix active saber blocks with MP damages | Changed an exact bound cvar-variable reference. `codemp/game/w_saber.c` | `medium` |
| `2020-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64349df34731`](https://github.com/eternalcodes/EternalJK/commit/64349df34731d25ab2efaaed8e9025d7cb2d9cf4)<br>JK2 style swing improvements | Changed an exact bound cvar-variable reference. `codemp/game/bg_local.h`, `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c` | `medium` |
| `2020-05-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c01c9ba41a7f`](https://github.com/eternalcodes/EternalJK/commit/c01c9ba41a7f8c8433c35985d4c8ed107d2f1192)<br>fix client staff/duals attack prediction after JK2 swing style updates | Changed an exact bound cvar-variable reference. `codemp/game/bg_saber.c` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f124ea7347c4`](https://github.com/eternalcodes/EternalJK/commit/f124ea7347c4f2a6587be2359d0a525bcbc20a50)<br>Fix JK2 swing sabertweak x2 | Changed an exact bound cvar-variable reference. `codemp/game/bg_panimate.c`, `codemp/game/bg_saber.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/w_saber.c` | `high` |
| `2024-04-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`959f7e18d624`](https://github.com/taysta/TaystJK/commit/959f7e18d624c6dba465b711f6f7447d005a6450) · [PR #191](https://github.com/taysta/TaystJK/pull/191)<br>Rend2 & jaPRO updates (#191) | Changed an exact bound cvar-variable reference. `codemp/game/w_saber.c` | `medium` |
| `2024-05-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`13eac340e1ce`](https://github.com/videoP/jaPRO/commit/13eac340e1ce2e81ab6cbb47e21d984892a78c2a) · [PR #193](https://github.com/taysta/TaystJK/pull/193)<br>Japro update (#193) | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:193](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L193) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:8387](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L8387)
- behavior: [codemp/game/bg_panimate.c:2701](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_panimate.c#L2701)
- behavior: [codemp/game/bg_pmove.c:4465](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L4465)
- behavior: [codemp/game/bg_pmove.c:6227](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L6227)
- behavior: [codemp/game/bg_pmove.c:9055](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L9055)
- documentation: [docs/japro_docs.md:13](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L13)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
