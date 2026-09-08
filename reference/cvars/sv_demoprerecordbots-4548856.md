---
title: "sv_demoPreRecordBots"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_demoPreRecordBots`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Do demo pre-recording for bots as well

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_snapshot.cpp:841](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L841) |
| `1` | Enabled. | [codemp/server/sv_snapshot.cpp:841](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L841) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`80bf35177f0a`](https://github.com/taysta/TaystJK/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) on `2024-01-14` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#88](https://github.com/taysta/TaystJK/pull/88)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1057](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1057)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-01-14` | [`80bf35177f0a`](https://github.com/taysta/TaystJK/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-01-14` | [`80bf35177f0a`](https://github.com/videoP/jaPRO/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) | Shared earliest lineage |

## Evidence

- registration: [codemp/server/sv_init.cpp:1057](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1057) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_snapshot.cpp:841](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L841)
- behavior: [codemp/server/sv_snapshot.cpp:863](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L863)
