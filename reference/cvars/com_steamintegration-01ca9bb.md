---
title: "com_steamIntegration"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_steamIntegration`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Enables automatic Steam API integration (requires a steam_api64.dll to be in GameData)

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `int` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `engine-shared` | `—` | `!defined(DEDICATED) && defined(_WIN64)` |
| `1` | `engine-shared` | `—` | `!defined(DEDICATED) && else(defined(_WIN64))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`df21cc35f5ef`](https://github.com/eternalcodes/EternalJK/commit/df21cc35f5ef9cb78a9003abf7c5ab1acbe31dfe) on `2019-03-21` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/qcommon/common.cpp:1237](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/common.cpp#L1237)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-21` | [`df21cc35f5ef`](https://github.com/eternalcodes/EternalJK/commit/df21cc35f5ef9cb78a9003abf7c5ab1acbe31dfe) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-21` | [`df21cc35f5ef`](https://github.com/taysta/TaystJK/commit/df21cc35f5ef9cb78a9003abf7c5ab1acbe31dfe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-21` | [`df21cc35f5ef`](https://github.com/videoP/jaPRO/commit/df21cc35f5ef9cb78a9003abf7c5ab1acbe31dfe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-21` | [`df21cc35f5ef`](https://github.com/JKSunny/EternalJK/commit/df21cc35f5ef9cb78a9003abf7c5ab1acbe31dfe) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`115e1e877bc4`](https://github.com/taysta/TaystJK/commit/115e1e877bc4c3d27b022d3a1e37ddad8d2ec23d) · [PR #119](https://github.com/taysta/TaystJK/pull/119)<br>Search for 64-bit steamworks library on 64-bit versions (#119) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1452](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1452) (Cvar_Get); condition `!defined(DEDICATED) && defined(_WIN64)`
- registration: [codemp/qcommon/common.cpp:1454](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1454) (Cvar_Get); condition `!defined(DEDICATED) && else(defined(_WIN64))`
- behavior: [shared/sys/sys_win32.cpp:740](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L740)
- behavior: [shared/sys/sys_win32.cpp:742](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L742)
