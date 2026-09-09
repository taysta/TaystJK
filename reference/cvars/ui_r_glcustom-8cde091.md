---
title: "ui_r_glCustom"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_r_glCustom`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_r_glCustom` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `4` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/ui/ui_main.cpp:4171](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/ui/ui_main.cpp#L4171)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bdbf4bcc40d2`](https://github.com/JACoders/OpenJK/commit/bdbf4bcc40d206f22dadff61ab5c124b93c32bf8)<br>Show default status in cvar<enter> and print cvar<enter> for SP. Fixed bad Cvar getting with UI Cvar Create (SP). Cleaned up SP's old usage of range checking in renderer. Limit primitives to 0...3 in normal play. (SP) Remove ROM from ui_r_glcustom in SP ui, as ROM and ARCHIVE are mutually exclusive. Fix JK2 cvar sp_language being registered in renderer when not compiled with JK2 support at all. Removed some cruft from tr_public.h (SP) | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/ui/ui_main.cpp` | `medium` |
| `2013-09-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`06310990a9eb`](https://github.com/JACoders/OpenJK/commit/06310990a9eb57f977411533d1c9907a88497190)<br>Some cleanup and fixes for UI code. Also disables automatic overstrike mode in UI fields. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_main.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/ui/ui_main.cpp` | `medium` |
| `2023-10-14` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`aa48e28a7d4f`](https://github.com/taysta/TaystJK/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75) · [PR #26](https://github.com/taysta/TaystJK/pull/26)<br>Merge pull request #26 from taysta/rend2menu | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_main.c:6339](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6339) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:6081](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6081)
- behavior: [codemp/ui/ui_main.c:8041](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8041)
