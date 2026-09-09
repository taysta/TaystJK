---
title: "sv_listrecording"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_listrecording`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Lists demos being recorded

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `sv_listrecording` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`724b58ba6bf5`](https://github.com/eternalcodes/EternalJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-10-17`, integrated `2018-10-17`)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:2052](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_ccmds.cpp#L2052)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-17` | — | `2018-10-17` | [`724b58ba6bf5`](https://github.com/eternalcodes/EternalJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-17` | — | `2018-10-17` | [`724b58ba6bf5`](https://github.com/taysta/TaystJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-17` | — | `2018-10-17` | [`724b58ba6bf5`](https://github.com/videoP/jaPRO/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-17` | — | `2018-10-17` | [`724b58ba6bf5`](https://github.com/JKSunny/EternalJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-06-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64b8343c85ea`](https://github.com/taysta/TaystJK/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) · [PR #2](https://github.com/taysta/TaystJK/pull/2)<br>Merge pull request #2 from TomArrow/taysternal | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2349](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2349) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:1730](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L1730)
