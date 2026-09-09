---
title: "thrownade"
layout: reference
nav_exclude: true
search_exclude: false
---

# `thrownade`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Cmd_ThrowNade_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `thrownade` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_ALIVE`, `CMD_NOINTERMISSION`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`7dce9a576823`](https://github.com/videoP/jaPRO/commit/7dce9a5768238bbc22a004660c36c252c217701f) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2024-02-05`, integrated `2024-02-05`)
- Origin pull request: [#134](https://github.com/taysta/TaystJK/pull/134)
- Matching squash bullet: `thrownade command`
- Upstream registration evidence: [codemp/game/g_cmds.c:9066](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_cmds.c#L9066)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-05` | [2024-02-05](https://github.com/taysta/TaystJK/pull/134) | `2024-02-05` | [`7dce9a576823`](https://github.com/taysta/TaystJK/commit/7dce9a5768238bbc22a004660c36c252c217701f) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-05` | — | `2024-02-05` | [`7dce9a576823`](https://github.com/videoP/jaPRO/commit/7dce9a5768238bbc22a004660c36c252c217701f) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`f2d91900f16d`](https://github.com/taysta/TaystJK/commit/f2d91900f16d4db283e580386b9597c3ab0808d5) · [PR #135](https://github.com/taysta/TaystJK/pull/135)<br>Merge vulkan updates + jaPRO typo fix (#135) | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2024-05-28` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`87145eba654c`](https://github.com/videoP/jaPRO/commit/87145eba654c70609b15f9e6f6e9588d72ae0a5e) · [PR #206](https://github.com/taysta/TaystJK/pull/206)<br>Japro update (#206) | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_cmds.c:9064](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L9064) (game command table)
- handler: [codemp/game/g_cmds.c:8660](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8660)
