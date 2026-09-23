---
title: "cg_speedometer"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cg_speedometer`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-notice"><strong>Set with <code>speedometer</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Configure with the /speedometer command

## At a glance

| Field | Value |
|:--|:--|
| Category | Movement & race |
| Feature family | Speedometer |
| Module | `cgame` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2018-11-04 in [`ead7c2c37`](https://github.com/taysta/TaystJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | Yes: [codemp/ui/ui_xdocs.h:107](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xdocs.h#L107) |
| In-game menu | Yes: [ingame_setup.menu:3998](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/assets/japro/ui/jamp/ingame_setup.menu#L3998) |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`speedometer`](/TaystJK/reference/commands/speedometer-b0e26e4/) |

## Bits

Use [`speedometer`](/TaystJK/reference/commands/speedometer-b0e26e4/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own. [The labels come from the source table](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L1509).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | Enable speedometer | [codemp/cgame/hud_strafehelper.h:84](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.h#L84) |
| 1 | `2` | Pre-speed display | — |
| 2 | `4` | Jump height display | [codemp/cgame/hud_strafehelper.h:86](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.h#L86) |
| 3 | `8` | Jump distance display | [codemp/cgame/hud_strafehelper.h:87](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.h#L87) |
| 4 | `16` | Vertical speed indicator | — |
| 5 | `32` | Yaw speed indicator | — |
| 6 | `64` | Accel meter | [codemp/cgame/hud_strafehelper.h:90](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.h#L90) |
| 7 | `128` | Speed graph | — |
| 8 | `256` | Display speed in kilometers instead of units | — |
| 9 | `512` | Display speed in imperial miles instead of units | — |
| 10 | `1024` | Pre-speed jumps array | — |
| 11 | `2048` | Disable speedometer colors | — |
| 12 | `4096` | Array Colors 1 | — |
| 13 | `8192` | Array Colors 2 | — |
| 14 | `16384` | Old Speedgraph | — |
| 15 | `32768` | XYZ Speed | — |
## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`ead7c2c37109`](https://github.com/videoP/jaPRO/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-11-04`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:46](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L46)
- Attribution method: `introduction-commit-explicit-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/eternalcodes/EternalJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/taysta/TaystJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/videoP/jaPRO/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/JKSunny/EternalJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0b6764d0171e`](https://github.com/eternalcodes/EternalJK/commit/0b6764d0171edd446ef75464ad2edeaaead40e92)<br>cg_showpos | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc180aa113b3`](https://github.com/eternalcodes/EternalJK/commit/dc180aa113b3b4c7f07c2a6cbc39f3ad200b0772)<br>increase dropshadow distance to 512+misc fixes | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c`, `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2023-11-02` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1d83811e8ebc`](https://github.com/taysta/TaystJK/commit/1d83811e8ebc205a6d46481f6a9006ee2da181ae)<br>[EternalJK/Bucky] Add the rest of the xdocs defines and include the documentation file, improve xdocs help text. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2023-11-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a0faccba9b0f`](https://github.com/taysta/TaystJK/commit/a0faccba9b0f2aa6c902d11de9a24ee2baf0b871) · [PR #38](https://github.com/taysta/TaystJK/pull/38)<br>Merge pull request #38 from taysta/strafehelper-patch | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2023-12-30` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`136ead02a1e2`](https://github.com/taysta/TaystJK/commit/136ead02a1e2e6811b96d74b15fa1d8675ecdbe3)<br>XYZ velocity speedometer option | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2026-02-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d5aa0d6c8b70`](https://github.com/taysta/TaystJK/commit/d5aa0d6c8b70de0cb6b99ee228b2097216bbe333) · [PR #289](https://github.com/taysta/TaystJK/pull/289)<br>Merge pull request #289 from taysta/movement-keys | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:46](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_xcvar.h#L46) (XCVAR_DEF)
- registration: [codemp/ui/ui_xcvar.h:164](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xcvar.h#L164) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:1962](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_draw.c#L1962)
- behavior: [codemp/cgame/hud_strafehelper.c:418](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.c#L418)
- behavior: [codemp/cgame/hud_strafehelper.c:422](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.c#L422)
- behavior: [codemp/cgame/hud_strafehelper.c:424](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.c#L424)
- behavior: [codemp/cgame/hud_strafehelper.c:426](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/hud_strafehelper.c#L426)
- documentation: [codemp/ui/ui_xdocs.h:107](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xdocs.h#L107)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
