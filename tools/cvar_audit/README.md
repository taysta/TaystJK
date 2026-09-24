# TaystJK console-reference audit

This directory contains the reproducible pipeline behind the GitHub Pages cvar
and command reference. The checked-in `_data` records and generated Markdown
describe the static union of the engine, client, dedicated server, game,
cgame, UI, platform-conditional code, and every renderer backend.

## Evidence inputs

The provenance resolver expects these local remote-tracking refs:

| Origin | Ref |
|:--|:--|
| Current TaystJK source | `origin/master` |
| OpenJK | `openjk/master` |
| EternalJK | `eternaljk/master` |
| jaPRO | `japro/main` |
| JK2MV | `jk2mv/master` |
| NewJK / explicitly credited NewMod work | `newjk/master` |
| rend2 | `somaz/rend2-unified-wip` |
| Vulkan | `Sunny/master` |

The Base Jedi Academy baseline is OpenJK commit
`14cea1563762076974bee277afadbd5bf234c494`, its initial Raven source import.
PR metadata from every relevant target repository may be passed as one or more
GitHub API JSON files. Duplicate PR numbers are scoped to the PR's base
repository, and `created_at` remains distinct from its eventual merge date.
NewMod attribution is accepted only with explicit credit because the relevant
implementation is closed source. Developer-lineage credit is handled the same
way when code was shared privately: Bucky/Bucky21659 credit maps to his
unpublished EternalJK continuation even if a historical `jaPRO/Bucky` label is
used and the identifier is absent from EternalJK's public repository.
Contributor identity is not treated as permanent project identity:
`cg_chatBoxEmojis` is a curated exception because Sunny contributed that
feature to EternalJK before starting work on Vulkan.
`cl_filterGames` is another curated exception: Daggolin's OpenJK PR #1188
was imported by TaystJK PR #53 before its upstream squash merge. The import
commit for `ifCvar`, `strSub`, `delay`, and `waitf` explicitly credits
NewJK/NewMod; such explicit import credit does not require the identifier to
remain registered in the configured public upstream snapshot.
`g_fixSaberDisarmBonus` and `g_fixSaberMoveData` follow the same upstream-first
case: Razish opened OpenJK PR #1178 with both cvars on 2023-10-08, before
TaystJK PR #29 imported the still-open work. They expose optional fixes that
restore Base JKA behavior, but the new cvar registrations are OpenJK-originated,
not part of the Base JKA source snapshot.

For every non-base identifier, the resolver records the first mainline
registration in every project. It distinguishes the exact registration's first
author date, the target project's PR creation date, and its first-parent
integration date. Origin is ranked in that order, so an OpenJK PR merged into
TaystJK while still open upstream remains OpenJK-originated. PR dates are used
comparatively only when metadata exists for at least two candidates; an explicit
cross-project import link remains direct evidence. Shared commits remain
reviewable ties when authorship, submission, and integration cannot resolve them.
For an exact shared-commit tie involving a `game`-module registration, the resolver
uses jaPRO as the provider lineage because TaystJK bundles jaPRO's server-side game
module. Identifier-adjacent commit or PR credit and independently dated introductions
remain stronger evidence, while a broad squash-group label does not override the known
module provider. A project name in the subject of that shared merge is likewise port-route
context rather than identifier-specific origin evidence. This keeps the provider rule from
erasing a demonstrated upstream origin.
An import link identifies an intermediate port when another project has older
authorship; for example, `fs_forcegame` reached TaystJK through OpenJK but
originated in JK2MV. Installation paths and cvar default values are not project
credits. Content history stops at a complete removal of the identifier, so a
reverted, same-named setting cannot supply the current implementation's author
date; reducing duplicate occurrences during a refactor does not break history.

After resolving origin, the pipeline scans TaystJK's inherited first-parent
history again for post-origin changes. It records exact registration edits,
changed lines containing a bound cvar variable, and changed hunks inside a
registered command handler. Each event retains its date, commit, paths, PR,
attribution method, and confidence. This distinguishes “introduced by OpenJK”
from a later jaPRO, EternalJK, TaystJK, rend2, Vulkan, JK2MV, or NewJK change.

## Engine-managed cvars

Not every registered cvar is a setting. `build_reference.py` marks one as
`engine_managed` when the source says the engine owns the value, and records the
basis alongside it so the generated callout can name its own evidence:

| Basis | Meaning |
|:--|:--|
| `CVAR_ROM` | Read-only after registration. |
| `CVAR_INTERNAL` | Internal UI/engine state, kept out of every cvar listing. |
| `implicit-write` | No registration at all; every cited site only writes the name with `Cvar_Set`, so a value the player sets is replaced the next time that code runs. |
| `menu-mirror` | A menu staging copy that exists to augment another cvar. |
| `editorial` | Asserted by an override with no matching flag or registration shape. |

`ui_tribesMode` is the `implicit-write` case: `UI_UpdateCurrentServerInfo` clears it
and the other jaPRO server-info mirrors on every refresh, then sets them from the
server's `jcinfo2` key. Nothing declares them, so nothing on the page would
otherwise distinguish them from a setting.

A menu mirror is paired from the source, not guessed from its name:
`Cvar_Set("r_picmip", UI_Cvar_VariableString("ui_r_picmip"))` in
`UI_UpdateVideoSetup` writes the staged value through when the player accepts the
change, and `UI_GetVideoSetup` reads the real value back the other way. The pair
is recorded as `menu_mirror` with the line for each direction, so the mirror's
page names and links the setting it stands in for. Comments are masked first: a
commented-out pair is not a pair. Every mirror found so far is already
engine-managed through its flags, so this basis adds the reason rather than new
entries. `ui_r_picmip_custom` shows why the pairing comes from the source:
its counterpart is `r_picmip`, which no name-prefix rule would find.

Both directions are wrong sometimes: a hand-written mirror the code never flags, or a
menu setting that happens to carry `CVAR_INTERNAL`. Settle either with an
`engine_managed` boolean in that entry's `tools/cvar_audit/overrides.json` record,
next to its `summary` and `description`, and regenerate. An override that asserts
the marker keeps whichever basis the source already supports.

## Bitmask cvars and the commands that own them

Several bitmask cvars are meant to be changed with a console command rather than
by typing a value: `strafeHelper 4` toggles one option and leaves the rest alone,
where `cg_strafeHelper 16` would replace all of them. jaPRO's game module uses the
same arrangement for its server tweaks.

The pairing is read from the source. A `bitInfo_T` table names each bit in array
order, and the handler that follows it toggles one bit per invocation:

```c
static bitInfo_T strafeTweaks[] = { {"Original style"}, {"Updated style"}, ... };
void CG_StrafeHelper_f( void ) {
        trap->Cvar_Set( "cg_strafeHelper", va( "%i", (1 << index) ^ ... ) );
}
```

`build_reference.py` records the labels as `bits.options` on the cvar and the
registered command names as `bits.commands`, and lists the cvars back on the
command as `configures`. `validate.py` checks the two agree. The bit table
replaces the inferred value list on those pages, keeping any traced read site
beside the source's own label.

Four details the scan has to get right:

- The search is bounded by the handler's own body. Bounding it by the next table
  instead lets a file's last table absorb every function after it.
- Bit order is the array position. The trailing comments in these tables number
  from 0 in some and from 1 in others; the code shifts by the array index.
- One table can drive several cvars. `toggleAdmin` writes `g_juniorAdminLevel`
  or `g_fullAdminLevel` depending on its first argument, and one handler can
  carry several registered names, as `plugin` and `pluginDisable` do.
- A command may reach the table through a dispatcher: `cosmetics` registers
  `CG_Cosmetics_f`, which forwards to the jaPRO variant, so an unregistered
  handler is resolved one hop to its caller.

Comments are masked first, which is why the commented-out `weaponDisable` table
in `g_svcmds.c` is not published, and `accountFlags` is skipped because no cvar
stands behind it.

## Regenerate

Run from the repository root:

```sh
python3 tools/cvar_audit/provenance.py \
  --pr-json /path/to/pull-page-1.json \
  --pr-json /path/to/pull-page-2.json
python3 tools/cvar_audit/build_reference.py
python3 tools/cvar_audit/runtime_check.py \
  --cvars /path/to/cvarlist-output.txt \
  --commands /path/to/cmdlist-output.txt \
  --build BUILD_IDENTIFIER
python3 tools/cvar_audit/generate_docs.py
python3 tools/cvar_audit/validate.py --update-baseline-totals
node tools/cvar_audit/test_reference_app.js
python3 tools/cvar_audit/test_provenance.py
python3 tools/cvar_audit/validate.py
python3 tools/cvar_audit/check_generated.py
python3 tools/cvar_audit/check_drift.py --ref origin/master
```

`provenance.py --limit 0` prewarms extraction caches without resolving entries.
Extraction caches include the source commit and extractor version, so changed refs and
extractor updates are read automatically. Resolved provenance has its own schema version;
extractor-only changes preserve the existing PR attribution. Use `--refresh` when
re-resolving provenance, and supply the original PR exports to retain that evidence.
Caches are ignored; the state,
provenance, and runtime reconciliation reports are retained as audit artifacts.

The default branch's `reference-check.yml` automates the static portion of this
sequence after a release and on its weekly schedule. An automatic `latest` release
from `build.yml` first assembles a temporary reference and compares the meaningful
cvar and command fields with the checked-in data. Moving source commit pins, URLs,
and line numbers do not count as source drift because their old blame links remain
valid at the pinned commit. When that comparison is unchanged, the workflow skips
provenance collection, regeneration, and PR creation.

Scheduled, manually dispatched, and independently published-release runs remain
full audits so they can discover provenance changes outside TaystJK. A full run
checks out `gh-pages`, fetches every configured upstream, downloads public
pull-request metadata, regenerates the reference, updates the reviewed
baseline-total and changelog coverage ratchets, runs the complete checks and site
build, then opens or updates an `automation/reference-refresh` pull request. It
then dispatches this branch's own reference workflow on the bot commit, because
events created with `GITHUB_TOKEN` do not recursively start workflows. It never
pushes generated output directly to `gh-pages`.

The automation deliberately retains the checked-in runtime report. A runner has
not launched a real client or dedicated server, so it cannot truthfully replace
that capture. Supply fresh `cvarlist` and `cmdlist` output and run
`runtime_check.py` manually when a new runtime reconciliation is available.

`baseline-totals.json` records the three independently compared inventory totals.
The refresh workflow updates it in the generated pull request, where a reviewer
can confirm that the shift matches the added or removed registrations. Running
`validate.py` without `--update-baseline-totals` continues to fail on an
unreviewed count change.

To rebuild the existing source snapshot without advancing it, pass its full
`_data/reference-meta.json` `source_commit` as `--ref <sha>` to both `provenance.py`
and `build_reference.py`. The assembly records the upstream commits used for independent
baseline inventory comparisons. Page generation reuses those recorded commits and reads
emoji assets from the same pinned TaystJK snapshot.

For runtime capture, launch cvars and commands separately with
`+cvarlist +quit` and `+cmdlist +quit`, redirecting stdout to different files.
This avoids both lists competing for console scrollback. Load a map first when
checking game-module registrations. A dedicated run cannot load client, cgame,
UI, platform, or renderer-specific entries, so it supplements rather than
replaces static extraction.

## Verification

```sh
(cd tools/cvar_audit && python3 -m unittest test_extract.py)
python3 tools/cvar_audit/test_provenance.py
node tools/cvar_audit/test_reference_app.js
python3 tools/cvar_audit/validate.py
python3 tools/cvar_audit/check_generated.py
python3 tools/cvar_audit/check_drift.py --ref origin/master
```

The generator writes a compact `assets/data/catalog.json` for the interactive
search UI as well as the complete evidence-rich JSON exports. The Pages
workflow tests both the extractor and the browser-independent filtering logic
whenever `gh-pages` changes. Missing or stale case-insensitive names fail CI.
Unproven semantics or attribution are published as `needs-review` and collected
in the audit page rather than guessed.
