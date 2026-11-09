---
title: "s_UseOpenAL"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "Use OpenAL with EAX environmental audio instead of the software mixer."
---

# `s_UseOpenAL`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Selects the OpenAL sound backend instead of the software mixer. With OpenAL, EAX environmental reverb is applied through the bundled OpenAL Soft and EalMan, using the current map's `eagle/<mapname>.eal` file when one exists. If OpenAL cannot open a device the client prints a warning and falls back to the software mixer. Latched: takes effect after `snd_restart`. Video capture records no audio while it is on.

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Category | Audio & music |
| Module | `engine-client` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [ingame_setup.menu:4485](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/assets/japro/ui/jamp/ingame_setup.menu#L4485), [setup.menu:2530](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/assets/japro/ui/jamp/setup.menu#L2530), [setup.menu:2553](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/assets/japro/ui/jamp/setup.menu#L2553) |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Use the software mixer. | [codemp/client/snd_dma.cpp:533](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/client/snd_dma.cpp#L533) |
| `1` | Use OpenAL, with EAX when the OpenAL implementation supports it. | [codemp/client/snd_dma.cpp:536](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/client/snd_dma.cpp#L536) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration
- `CVAR_LATCH`: latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/snd_dma.cpp:475](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/client/snd_dma.cpp#L475)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-05-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16f7fe7ecc48`](https://github.com/JACoders/OpenJK/commit/16f7fe7ecc4842f32eea5dea5aeef4df9369b1ab)<br>[MP] Minor refactoring and cleanup in the sound code to move AL code all in a preprocessor. Removed an unnecessary loop in S_LoadSound_DirIsAllowedToKeepMP3s. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/snd_dma.cpp` | `medium` |
| `2014-05-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`575263a31897`](https://github.com/JACoders/OpenJK/commit/575263a318979ff328ffdf16321244c16ca7271d)<br>[SP] Minor refactoring and cleanup in the sound code to move AL code all in a preprocessor. Removed an unnecessary loop in S_LoadSound_DirIsAllowedToKeepMP3s. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_dma.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_dma.cpp` | `medium` |

## Evidence

- registration: [codemp/client/snd_dma.cpp:533](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/client/snd_dma.cpp#L533) (Cvar_Get); condition `defined(USE_OPENAL)`
- behavior: [codemp/client/snd_dma.cpp:516](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/client/snd_dma.cpp#L516)
- behavior: [codemp/game/NPC_misc.c:38](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/game/NPC_misc.c#L38)
- behavior: [codemp/game/NPC_misc.c:67](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/game/NPC_misc.c#L67)
- behavior: [codemp/qcommon/cm_patch.cpp:1317](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/qcommon/cm_patch.cpp#L1317)
- behavior: [codemp/qcommon/cm_patch.cpp:1514](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/codemp/qcommon/cm_patch.cpp#L1514)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/d843fa409b7e269a3775392e569f8f4694a7cb25"><code>d843fa409b7e</code></a> on 2026-11-09. Anything merged after that is not reflected here.</p>
