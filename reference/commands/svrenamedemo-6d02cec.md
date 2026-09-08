---
title: "svrenamedemo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `svrenamedemo`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Rename a server-side demo

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `svrenamedemo [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) on `2017-12-28` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:2049](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_ccmds.cpp#L2049)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. Current-line blame identifies the later differing registration after the patch path could not be followed.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-28` | [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-28` | [`668821b03696`](https://github.com/taysta/TaystJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-28` | [`668821b03696`](https://github.com/videoP/jaPRO/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-28` | [`668821b03696`](https://github.com/JKSunny/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `high` |
| `2018-10-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`724b58ba6bf5`](https://github.com/eternalcodes/EternalJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc)<br>add sv_listrecording command start servers with hibernation disabled | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2023-06-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`311ab67a5df6`](https://github.com/taysta/TaystJK/commit/311ab67a5df64a24b0f3aa582127a8062af3439d)<br>- Add sv_demoPreRecord->integer condition in WriteSnapshotToClient to prevent unexpected behavior when pre-recording is disabled. - Memset entire preRecord struct to 0 when clearing pre-record of a client. - Guard all serverside demo code with #ifdef DEDICATED, don't need it in client - Replace strlenConstExpr with sizeof() - Removed unused variables. - Set minDeltaFrame back to 0 in a few places, just in case. | The current differing registration line is blamed to this commit. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2348](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2348) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:1705](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1705)
- documentation: [docs/japro_docs.md:399](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L399)
