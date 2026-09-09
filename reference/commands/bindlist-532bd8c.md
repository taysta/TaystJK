---
title: "bindlist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `bindlist`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Show all bindings in the console

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `bindlist` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_keys.cpp:1266](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_keys.cpp#L1266)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`393874137c54`](https://github.com/JACoders/OpenJK/commit/393874137c54b70b27856e62013bd283059ef6e0)<br>First batch of changes from Ensi | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`55c2d54b3409`](https://github.com/JACoders/OpenJK/commit/55c2d54b34097448d9e5c8d8a62bcb35fe00391f)<br>Major improvements to command completion | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7ee03d5d1507`](https://github.com/JACoders/OpenJK/commit/7ee03d5d15076bbac3931556a08974ac2f1b077d)<br>Improve bindlist command formatting to be more like cvarlist. | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2013-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`aca8a3445035`](https://github.com/JACoders/OpenJK/commit/aca8a344503520d6704304cd8ed0d87715577b99)<br>Demoname completion for MP. Rcon command completion for MP. Fixed map command completion having some weird stuff in it. Display "Key  " in grey before keynames when doing /bind <TAB>. Display "File " in grey before filenames when doing /map <TAB> or others with filename completion. Fixed /bind key displaying bind <KEY> = "" as opposed to "<KEY>" is not bound when unbound sometimes. | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2013-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`82badfabf174`](https://github.com/JACoders/OpenJK/commit/82badfabf174a20512a5c895b58af25eade3e972)<br>Massive SP upgrade patch. Merges the console overhaul to SP. Fixes extension functions in SP. Rename qport to net_qport in SP. Remove alt-tab diasabler from SP. Fixed up command buffer code in SP. Fixed up configs loading on startup in SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_keys.cpp` | `medium` |
| `2014-02-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b276c56dd51c`](https://github.com/JACoders/OpenJK/commit/b276c56dd51c9934657fe418620165990229e97f)<br>[MP] Merged some ioq3 bind changes to MP along with togglemenu support. Console Command intercept should still work. | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2015-06-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f614bc372a41`](https://github.com/taysta/TaystJK/commit/f614bc372a41cca80c0e1e401d584a57318bd495)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_keys.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_keys.cpp` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_keys.cpp:1572](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_keys.cpp#L1572) (Cmd_AddCommand)
- handler: [codemp/client/cl_keys.cpp:1497](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_keys.cpp#L1497)
