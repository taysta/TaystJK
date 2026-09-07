---
title: "r_debugWeather"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_debugWeather`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_debugWeather` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Selects the code path tested for value 0. | [shared/rd-rend2/tr_weather.cpp:1137](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_weather.cpp#L1137) |
| `2` | Selects the code path tested for value 2. | [shared/rd-rend2/tr_backend.cpp:3274](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3274) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`b3a02ea3e936`](https://github.com/taysta/TaystJK/commit/b3a02ea3e93639c829cc2421fef08277d90f8ab4)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1484](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1484)
- Attribution method: `renderer-scope-and-upstream-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1518](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1518) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_backend.cpp:3274](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3274)
- behavior: [shared/rd-rend2/tr_weather.cpp:1137](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_weather.cpp#L1137)
