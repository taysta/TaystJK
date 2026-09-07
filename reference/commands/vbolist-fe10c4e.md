---
title: "vbolist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `vbolist`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `R_VBOList_f` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Syntax | `vbolist` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`b2cb9bd9a57f`](https://github.com/taysta/TaystJK/commit/b2cb9bd9a57fcf68a00c4c791c5ce17a6b9e785c)
- Upstream registration evidence: [code/rd-rend2/tr_init.cpp:1471](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/code/rd-rend2/tr_init.cpp#L1471)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits rend2.

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1468](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1468) (renderer command table)
- handler: [shared/rd-rend2/tr_vbo.cpp:358](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_vbo.cpp#L358)
