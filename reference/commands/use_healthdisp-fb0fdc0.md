---
title: "use_healthdisp"
layout: reference
nav_exclude: true
search_exclude: false
---

# `use_healthdisp`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Use health dispenser item

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `use_healthdisp` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/client/cl_input.cpp:1868](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/client/cl_input.cpp#L1868)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_input.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/client/cl_input.cpp` | `medium` |
| `2025-04-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`8b353c2103fd`](https://github.com/taysta/TaystJK/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03) · [PR #219](https://github.com/taysta/TaystJK/pull/219)<br>Small bugfix/refactor (#219) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/client/cl_input.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_input.cpp:1805](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1805) (input command table)
- handler: [codemp/client/cl_input.cpp:302](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L302)
