---
title: "r_arb_vertex_type_2_10_10_10_rev"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_arb_vertex_type_2_10_10_10_rev`

<span class="label ref-origin ref-origin-rend2">rend2</span>

Disable/enable 1010102 UI data type

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `int` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`888786b5d290`](https://github.com/taysta/TaystJK/commit/888786b5d290d44d192e3d14e3f73a978eec8dfc)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1466](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1466)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits rend2.

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1500](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1500) (Cvar_Get)
