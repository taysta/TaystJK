---
title: "sv_demoPreRecordBots"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_demoPreRecordBots`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Do demo pre-recording for bots as well

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_snapshot.cpp:841](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L841) |
| `1` | Enabled. | [codemp/server/sv_snapshot.cpp:841](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L841) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`80bf35177f0a`](https://github.com/taysta/TaystJK/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2024-01-10`, PR opened `2024-01-12`, integrated `2024-01-14`)
- Origin pull request: [#88](https://github.com/taysta/TaystJK/pull/88)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1057](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1057)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-01-10` | [2024-01-12](https://github.com/taysta/TaystJK/pull/88) | `2024-01-14` | [`80bf35177f0a`](https://github.com/taysta/TaystJK/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-01-10` | — | `2024-01-14` | [`80bf35177f0a`](https://github.com/videoP/jaPRO/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) | Shared integration commit |

## Evidence

- registration: [codemp/server/sv_init.cpp:1057](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1057) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_snapshot.cpp:841](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L841)
- behavior: [codemp/server/sv_snapshot.cpp:863](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L863)
