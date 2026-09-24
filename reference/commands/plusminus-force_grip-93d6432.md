---
title: "+force_grip"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `+force_grip`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Hold to use grip force power

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [controls.menu:2716](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/assets/japro/ui/jamp/controls.menu#L2716), [ingame_controls.menu:2344](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/assets/japro/ui/jamp/ingame_controls.menu#L2344) |
| Syntax | `+force_grip` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_input.cpp:1076](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_input.cpp#L1076)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_input.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/client/cl_input.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_input.cpp:1739](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_input.cpp#L1739) (input command table)
- handler: [codemp/client/cl_input.cpp:777](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_input.cpp#L777)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
