---
title: "name"
layout: reference
nav_exclude: true
search_exclude: false
---

# `name`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Player name

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [elegance_hud.menu:12](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/elegance_hud.menu#L12), [elegance_hud.menu:26](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/elegance_hud.menu#L26), [elegance_hud.menu:34](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/elegance_hud.menu#L34) |
| Default | `Padawan` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_USERINFO` — sent in the client's userinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_main.cpp:1269](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_main.cpp#L1269)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-04-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dbc43a2f54c0`](https://github.com/JACoders/OpenJK/commit/dbc43a2f54c0273732d0080a1a22bc6a30ea43d0)<br>[SP] Some cvar default fixes and remove additional commands on client shutdown. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e6ed053d8fa5`](https://github.com/eternalcodes/EternalJK/commit/e6ed053d8fa547a4e09b11d6708074bdc121edd4)<br>Improved Afk code | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1cdc9fc78b3b`](https://github.com/eternalcodes/EternalJK/commit/1cdc9fc78b3b1980874dd25de036b23468ecfbf8)<br>Afk bugfix Accidentally deleted essential code in cl_input Added 5 second wait time before using afk cmd again. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8e7c210be049`](https://github.com/eternalcodes/EternalJK/commit/8e7c210be049001869783f27373c4b68a4bb02eb)<br>Merge pull request #101 from eternalcodes/features/afkPrefix | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3416](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3416) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2368](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2368)
- behavior: [codemp/client/cl_main.cpp:2445](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2445)
- behavior: [codemp/client/cl_main.cpp:2446](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2446)
