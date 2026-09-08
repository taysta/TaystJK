---
title: "s_language"
layout: reference
nav_exclude: true
search_exclude: false
---

# `s_language`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Sound language

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `english` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_NORESTART` — preserved across cvar restart

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/snd_dma.cpp:445](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/client/snd_dma.cpp#L445)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a118ef1512c`](https://github.com/JACoders/OpenJK/commit/4a118ef1512c25b6fe5b24be4af48ef64a2232c6)<br>Merge pull request #318 from archSeer/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_dma_console.cpp`, `codemp/client/snd_dma_console.cpp` | `medium` |
| `2013-08-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61cd6e979c3b`](https://github.com/JACoders/OpenJK/commit/61cd6e979c3bb37e8b05ca2c6f1a1fc0812aea17)<br>Removed stricmp etc, always use Q_ versions for consistency across platforms | Changed an exact bound cvar-variable reference. `codemp/client/snd_mem.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_dma.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/snd_dma.cpp` | `medium` |

## Evidence

- registration: [codemp/client/snd_dma.cpp:476](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L476) (Cvar_Get)
- behavior: [codemp/client/snd_mem.cpp:644](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_mem.cpp#L644)
- behavior: [codemp/client/snd_mem.cpp:646](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_mem.cpp#L646)
- behavior: [codemp/client/snd_mem.cpp:648](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_mem.cpp#L648)
- behavior: [codemp/client/snd_mem.cpp:643](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_mem.cpp#L643)
