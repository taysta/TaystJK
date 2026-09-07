---
title: "sv_legacyFixes"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_legacyFixes`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `sv_legacyFixes` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `128` | Rancor/wampa skins | [codemp/server/server.h:356](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/server.h#L356) |
| `8` | Enables the `SVFIXES_ALLOW_INVALID_FORCEPOWERS` code path. | [codemp/server/server.h:352](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/server.h#L352) |
| `64` | Enables the `SVFIXES_ALLOW_INVALID_PLAYER_NAMES` code path. | [codemp/server/server.h:355](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/server.h#L355) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `engine-server` | `—` | `!defined(DEDICATED)` |
| `1` | `engine-server` | `—` | `else(!defined(DEDICATED))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`8b07e58c1c28`](https://github.com/taysta/TaystJK/commit/8b07e58c1c2875e94823c8afe5443e003370349b)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1009](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1009)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/server/sv_init.cpp:1044](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1044) (Cvar_Get); condition `!defined(DEDICATED)`
- registration: [codemp/server/sv_init.cpp:1046](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1046) (Cvar_Get); condition `else(!defined(DEDICATED))`
- behavior: [codemp/server/sv_client.cpp:1181](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1181)
- behavior: [codemp/server/sv_client.cpp:1286](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1286)
- behavior: [codemp/server/sv_client.cpp:1304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1304)
- behavior: [codemp/server/sv_client.cpp:1477](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1477)
- behavior: [codemp/server/sv_client.cpp:1483](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1483)
