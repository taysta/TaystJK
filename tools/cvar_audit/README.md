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
PR metadata may be passed as one or more GitHub API JSON files so squash commit
bodies and PR descriptions can be considered. NewMod attribution is accepted
only with explicit credit because the relevant implementation is closed source.

For every non-base identifier, the resolver records the first dated mainline
registration in every project. The earliest event is treated as the ultimate
origin and later events as downstream appearances, regardless of port direction.
An exact shared commit is a medium-confidence lineage tie because Git does not
record which remote received the object first; explicit commit/PR credit can
resolve the tie or identify an intermediate port source.

After resolving origin, the pipeline scans TaystJK's inherited first-parent
history again for post-origin changes. It records exact registration edits,
changed lines containing a bound cvar variable, and changed hunks inside a
registered command handler. Each event retains its date, commit, paths, PR,
attribution method, and confidence. This distinguishes “introduced by OpenJK”
from a later jaPRO, EternalJK, TaystJK, rend2, Vulkan, JK2MV, or NewJK change.

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
node tools/cvar_audit/test_reference_app.js
python3 tools/cvar_audit/test_provenance.py
python3 tools/cvar_audit/validate.py
python3 tools/cvar_audit/check_generated.py
python3 tools/cvar_audit/check_drift.py --ref origin/master
```

`provenance.py --limit 0` prewarms extraction caches without resolving entries.
Use `--refresh` after upstream refs move. Caches are ignored; the state,
provenance, and runtime reconciliation reports are retained as audit artifacts.

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
