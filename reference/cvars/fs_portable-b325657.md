---
title: "fs_portable"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_portable`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Disable fs_homepath and use only one folder for all game files

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Ultimate-origin introduction: [`f993b7c81891`](https://github.com/jkanewmod/NewJK/commit/f993b7c81891704b9798e079a9e89b42ea649ebf) in <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> (content authored `2017-05-21`, integrated `2017-05-21`)
- TaystJK integration evidence: [`fae0fd307416`](https://github.com/taysta/TaystJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)
- Upstream registration evidence: [codemp/qcommon/files.cpp:3625](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/qcommon/files.cpp#L3625)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2017-05-21` | — | `2017-05-21` | [`f993b7c81891`](https://github.com/jkanewmod/NewJK/commit/f993b7c81891704b9798e079a9e89b42ea649ebf) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-06-12` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-06-12` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/taysta/TaystJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-06-12` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/videoP/jaPRO/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-06-12` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/JKSunny/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Other project appearance |

## Evidence

- registration: [codemp/qcommon/files.cpp:3922](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3922) (Cvar_Get)
- behavior: [shared/sys/sys_win32.cpp:176](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_win32.cpp#L176)
- behavior: [shared/sys/sys_win32.cpp:172](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_win32.cpp#L172)
- behavior: [shared/sys/sys_win32.cpp:174](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_win32.cpp#L174)
- behavior: [shared/sys/sys_win32.cpp:187](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_win32.cpp#L187)
