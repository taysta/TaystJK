---
title: "amWait"
layout: reference
nav_exclude: true
search_exclude: false
---

# `amWait`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `amWait` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`f4d14139b3e3`](https://github.com/eternalcodes/EternalJK/commit/f4d14139b3e338ccf67b024999497e5201cdb7a6) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-12-07`, integrated `2018-12-07`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2364](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2364)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-12-07` | — | `2018-12-07` | [`f4d14139b3e3`](https://github.com/eternalcodes/EternalJK/commit/f4d14139b3e338ccf67b024999497e5201cdb7a6) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-12-07` | — | `2018-12-07` | [`f4d14139b3e3`](https://github.com/taysta/TaystJK/commit/f4d14139b3e338ccf67b024999497e5201cdb7a6) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-12-07` | — | `2018-12-07` | [`f4d14139b3e3`](https://github.com/videoP/jaPRO/commit/f4d14139b3e338ccf67b024999497e5201cdb7a6) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-12-07` | — | `2018-12-07` | [`f4d14139b3e3`](https://github.com/JKSunny/EternalJK/commit/f4d14139b3e338ccf67b024999497e5201cdb7a6) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-02-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7e17adfdee87`](https://github.com/eternalcodes/EternalJK/commit/7e17adfdee87f92a0c4cbb72ab7ddce8b9d9e452)<br>Rename some JA+ plugin options | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2689](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2689) (forwarded client command table)
