# TaystJK wiki — implementation plan and agent prompts

Companion to `taystjk-docs-plan.md`, which holds the harvested inventory and audit findings.
Part 1 is the plan. Part 2 is a prompt per work package, written for an agentic coding model
working directly in the repository.

---

# Part 1 — Implementation plan

## Repository facts the plan assumes

| Thing | Value |
|:--|:--|
| Source branch | `master` |
| Docs branch | `gh-pages`, served at `https://taysta.github.io/TaystJK/`, `baseurl: /TaystJK` |
| Site engine | Jekyll, `remote_theme: just-the-docs/just-the-docs`, single custom layout `_layouts/reference.html` applied to all pages by default |
| Site assets | `assets/js/reference-app.js` (search app **and** the platform selector), `assets/css/reference.css` |
| Reference data | `_data/cvars.json` (1,441), `_data/commands.json` (573), `_data/reference-meta.json` |
| Reference pipeline | `tools/cvar_audit/` — `extract.py`, `provenance.py`, `build_reference.py`, `runtime_check.py`, `generate_docs.py`, `validate.py`, `check_generated.py`, `check_drift.py`, `overrides.json`, `removed.json`, `schema.json`, plus three test entry points |
| CI | `.github/workflows/reference-drift.yml` on `gh-pages` only |
| Generated pages | `reference/cvars/*.md`, `reference/commands/*.md`, `reference/{all,audit,categories,features,modules,origins,removed}.md` |
| Hand-written pages | `index.md`, `install.md`, `server-hosting.md`, `development.md`, `development/*.md`, `reference/sources.md`, `ai-disclosure.md` |
| Orphaned | `hardcoded-changes.md` + 4 child stubs, `cvars/*`, `commands/*` |

Baseline buckets for the "what's new" toggle, from `origin.source` across all 2,014 entries:

| Baseline | Origins rolled up | Entries |
|:--|:--|--:|
| vs EternalJK | taystjk, rend2, vulkan, jk2mv, newjk | 217 |
| vs OpenJK | + japro, eternaljk | 823 |
| vs base JKA | + openjk | 990 |

## Phase sequencing

```
0  Conventions          ─┬─> 1  Data corrections ──┬─> 2  Generator work ──┬─> 4  Feature content
                         │                          │                       │
                         └─> 3  IA restructure ─────┘                       ├─> 5  Task content
                                                                            │
                                                                            ├─> 6  Devlog
                                                                            │
                                                                            └─> 7  Automation ──> 8  Final audit
```

Phases 0–3 are structural and should land before content work, otherwise pages get written
twice. Phases 4, 5 and 6 are independent of each other and can run in any order or in parallel.

---

## Phase 0 — Conventions

**Goal:** a single checked-in document that every later phase conforms to, so pages don't
diverge in front matter, tone or badge usage.

Work items:

1. `CONVENTIONS.md` on `gh-pages` defining: front matter schema for hand-written pages
   (`title`, `description`, `nav_order`, `parent`, `origin`, `status`, `added_on`),
   the allowed `origin` values matching `origin.source`, the allowed `status` values
   (`stable`, `experimental`, `deprecated`), heading depth rules, code-fence language tags,
   source-link policy (blame links with pinned commits), and terminology.
2. Badge rendering for `status: experimental` in `_layouts/reference.html` plus styles in
   `assets/css/reference.css`, matching the existing `needs review` badge treatment.
3. `added_on` convention: `YYYY-MM-DD (shorthash)`, with the comparison rule stated once in
   the overview page and linked from each badge.
4. Decide and record the fate of orphaned pages. Recommended: delete `cvars/`, `commands/`
   and the four `hardcoded-changes/` child stubs, keep `hardcoded-changes.md` as a redirect
   stub to the new Features index for one release cycle, then delete.
5. Redirect map file listing every retired URL and its destination, implemented with
   `jekyll-redirect-from` or a minimal meta-refresh include.

**Acceptance:** conventions document exists; experimental badge renders on a test page;
redirect map covers every path currently reachable that Phase 3 will move.

---

## Phase 1 — Reference data corrections

**Goal:** stop the reference stating things that are wrong or empty before building pages on top of it.

Work items:

1. Resolve macro-valued defaults. 17 entries show a C macro instead of its value —
   `sv_master1` → `masterjk3.ravensoft.com`, `sv_master2` → `master.jkhub.org`,
   `cl_renderer` → `DEFAULT_RENDER_LIBRARY`, plus `model`, `saber1`, `forcepowers`,
   `gamename`, `gamedate`, `r_drawBuffer`, `r_textureMode`, `ui_blueteam`,
   `ui_opponentName`, `ui_char_anim`, `ui_redteam`, `ui_saber`, `cl_motdServer1`,
   `cl_motdServer2`. Resolve in the
   extractor by following `#define` chains in `codemp/qcommon/qcommon.h` and siblings;
   fall back to `overrides.json` only where the macro is genuinely platform-conditional,
   and record both the macro name and the resolved value so the page can show either.
2. `range` is populated on 16 of 2,014 entries. Either extract ranges from clamp calls
   (`Cvar_Get` with min/max, `Cvar_CheckRange`) or drop the field from `schema.json` and
   the detail template. Do not leave it as-is.
3. Surface `reference-meta.json`'s `source_commit` and its commit date on `reference.md`
   and in the page footer of every generated entry.
4. Placeholder triage tooling: a script that emits the review queue ordered by
   (origin = taystjk first), then by whether an xdocs entry exists, then alphabetically,
   so the 1,135 placeholder summaries can be worked down in a sensible order. Output as a
   checklist file, not a new site page.

**Acceptance:** zero entries display an unresolved macro as a default; `range` is either
populated or gone; the reference landing page states which commit it was generated from and
when; the triage checklist exists and starts with the 79 TaystJK-origin entries.

---

## Phase 2 — Generator extensions

**Goal:** everything that can be generated is generated, so the changelog gap can't reopen.

Work items:

1. Origin→baseline mapping in the generator, per the table above. Explicit mapping, not a
   read of `origin.source`.
2. Generate `whats-new.md` with a three-way baseline toggle reusing the platform-selector
   pattern already in `assets/js/reference-app.js` (same tablist markup, same
   saved-per-device behaviour, different storage key). Entries grouped by topic, each
   showing name, one-line summary, origin badge and `added_on`.
3. Hand-tuning path: a `whats-new-overrides.json` (or a section in `overrides.json`) that
   can promote, demote, reword or group entries, plus an include point for hand-written
   non-cvar features so `.oshader` and cosmetic offsets appear in the same list. Those come
   from the `origin` front matter added in Phase 0.
4. `added_on` derivation from `origin.first_commit` plus author date, emitted into the
   entry data so both the reference and the what's-new page can render it.
5. Changelog coverage report: a script comparing entry names against `master`'s
   `CHANGELOG.md`, emitting a gap list. Current state is 57 of 79 TaystJK-origin entries
   missing. Run it in CI so the number can't grow silently.
6. Emoji index generation from `assets/japro/gfx/emoji/` on `master` — filenames are the
   chat tokens, so the page is a straight listing with images.

**Acceptance:** `whats-new.md` is generated, toggles between three baselines, and the totals
match 217 / 823 / 990; the coverage report runs and reports a number; the emoji index
renders every shipped emoji with its token.

---

## Phase 3 — IA restructure

**Goal:** a home for the content Phase 4 and 5 produce, and no orphaned pages.

Work items:

1. New top-level `Features` section with index page, positioned between Host and Develop.
2. Child page stubs with front matter and nav order, no body content yet: what's new,
   client behaviour changes, cosmetics, HUD and movement tools, renderers, movement styles,
   Tribes, shipped configs, emoji index, platform support matrix, builds and versioning.
3. New Develop children: documentation system, in-game docs (xdocs), contributing.
4. New pages elsewhere: overview (how the reference works, how the docs are laid out),
   glossary, troubleshooting hub, where to report what, mod compatibility matrix,
   attribution and licensing.
5. Retire the orphans per the Phase 0 decision; apply the redirect map.
6. jaPRO explainer placed on `index.md` and expanded in the overview.

**Acceptance:** `check_generated.py` passes; no page is unreachable from the nav; every
retired URL redirects; the link checker reports zero broken internal links.

---

## Phase 4 — Feature content

Write the bodies for the Features section, sourced from the inventory in
`taystjk-docs-plan.md` §2 and verified against `master`. Each page carries source links.

Order, hardest evidence first:

1. Client behaviour changes — `.oshader` (all three renderers), shader phone-book order,
   modifier and side-specific binds, nested quotes, console shortcuts, `con_datetime`,
   `con_height`, widescreen levelshots and `menu/splash_16_9`, `r_fontSharpness`.
2. Cosmetics — `cosmetics` command, `cg_forceCosmetics -1`, adding an `.md3`, the
   `.cosmetic` JSON offsets format with wildcards and `modelFallback`, seasonal cosmetics.
3. Renderers — what each backend is for, `cl_renderer` + `vid_restart`, differences,
   where Vulkan bugs go, known switching instability.
4. HUD and movement tools — killfeed, team overlays, SnapHUD, PitchHUD, strafe helper,
   speedometer, movement keys, score and status placement, the centre timer and team score
   (`cg_drawTimer 7` / `cg_drawScores 3` / `cg_drawStatus 2`), and `cg_hudFiles`.
   [2026-09-13: written. `hud_tayst.cfg` is the reference for which options the new HUD
   turns on; the bitmask tools are configured by their companion commands, not by hand.]
5. Movement styles — all nineteen `MV_*` entries from `codemp/game/bg_public.h:562-585`,
   one table row each. WSW is an ordinary CPM-family Warsow style and gets a row like the
   rest; the "not part of Tribes" point is a filing note for whoever writes the page, not
   page content. [2026-09-13: it was published as an argument and has been removed.]
6. Tribes — its own page, `status: experimental`.
7. Shipped configs — the fourteen `.cfg` files under `assets/japro/`.
8. Platform support matrix, builds and versioning, emoji index body text.

**Acceptance:** every factual claim links to a source line or a shipped file; no page
restates a cvar table the reference already generates — it links instead.

---

## Phase 5 — Task and troubleshooting content

Use the issue tracker to decide *which* problems are worth a page — the ones that recur.
Do not cite issue or PR numbers in the pages themselves; see "Do not cite issue or PR
numbers" in `CONVENTIONS.md`. The numbers below are the evidence for writing each entry,
not something to reproduce on the site. An entry is finished when it would still read
correctly after every issue behind it is closed.

1. Troubleshooting hub: server not in the list (#215, #294), updating a build on macOS
   (#261, #355, #343), multiple mods in one GameData (#269, #275), Linux audio (#245, #246).
2. Where to report what (#268, #266, #267, #121, #244, #73, #107).
3. Mod compatibility matrix — `serverMod` detection, feature flags, Lugormod
   `STAT_EXTRA_FORCE_BITS` collisions.
   [2026-09-13: written as `mod-compatibility.md`. The load-bearing fact is that the six
   server kinds are an ordered enum and most checks read "at least JA+". Also records the
   recommendation to run NewJK/NewMod rather than TaystJK on base_enhanced and
   base_entranced, which share an author with NewMod. The Lugormod stat collisions were not
   covered -- they are an implementation detail with no player-facing symptom identified
   yet, so they need a reader-visible symptom before they earn a paragraph.]
4. Server hosting additions: master servers and heartbeat, don't hand-edit
   `taystjk_server.cfg`, `sv_pure` on non-base `fs_game`, the real-world Docker Compose
   example, filesystem and downloads internals, serverside demo recording.
   [2026-09-13: done. `sv_pure` turned out to be two separate facts: a mod with loose
   cgame/ui libraries fails pure validation outright, and -- not in this plan at all --
   TaystJK bypasses pure entirely when the server's gamename is exactly `basejka`, so
   `sv_pure` is not an asset-parity guarantee for these clients.]
5. Feature flags spec on the Develop side — `taystJKinfo`, bits from
   `codemp/game/bg_public.h:550-556`, how a server mod advertises them.
   [2026-09-13: written as `development/feature-flags.md`.]
6. Contributing — PR flow, grabbing artifacts from a PR's Actions run to test a fix,
   build-from-source pointer for reporters.
   [2026-09-13: written as `development/contributing.md`.]
7. Glossary and attribution pages.

**Acceptance:** every troubleshooting entry names the symptom a user would actually search
for, not the internal cause, and carries no issue or PR citation.

---

## Phase 6 — Devlog

1. `devlog/` collection configured in `_config.yml`, a post layout, an index page with
   reverse-chronological listing, and an Atom feed.
2. One seed post so the layout is exercised.
3. Authoring instructions in `CONVENTIONS.md`.

**Acceptance:** a new file in `_devlog/` with front matter appears on the index and in the
feed with no other edits.
[2026-09-13: done, and the acceptance test was run rather than assumed -- a second post was
added, built, confirmed on the index and in the feed in the right order, then deleted. Built
without jekyll-feed: there is no theme and no plugins, so the feed is a Liquid template like
search-index.json. Posts are also picked up by the site search. The seed post is a
placeholder written to exercise the layout and should be rewritten or replaced before it is
treated as an announcement.]

---

## Phase 7 — Maintenance automation

1. ~~Add `schedule:` to `reference-drift.yml` (weekly)~~ — **the schedule cannot live
   there.** GitHub runs scheduled workflows only from the default branch, which is `master`;
   a cron in a `gh-pages`-only workflow never fires. Done instead as
   `weekly-reference-check.yml` on `master`, which checks `gh-pages` out and runs its
   `run_all.sh`, opening or updating an issue on failure. [2026-09-13]
2. Master-side PR check: grep the diff for `Cvar_Get`, `Cvar_Register`, `AddCommand`; when
   matched, comment with links to the xdocs macros, the reference pipeline and the docs
   checklist. Non-blocking.
3. PR checklist in `.github/PULL_REQUEST_TEMPLATE.md` on `master`: new cvar → xdocs entry →
   menu entry if user-facing → overrides entry if the auto-summary would be a placeholder →
   wiki page if the feature isn't cvar-shaped.
4. Wire the Phase 2 changelog coverage report into CI with a ratchet, so the gap can shrink
   but not grow.
5. ~~Drift check between `master`'s `docs/` files and the wiki, or a canonical-copy notice
   on each.~~ **Dropped 2026-09-13.** Both options assume those files are this project's
   documentation. They are not — the jaPRO ones came downstream with the gamecode. The wiki
   is canonical and cites them as external sources; see "master's `docs/` folder is a source
   to cite" in `CONVENTIONS.md`.
6. Regenerate the reference as part of the release workflow.

**Acceptance:** a new cvar merged to `master` produces a visible signal within a week without
anyone touching `gh-pages`. [Met once `weekly-reference-check.yml` is merged to `master` —
it is on a branch awaiting review, so the criterion is not satisfied until then.]

---

## Phase 8 — Final audit

1. Full internal and external link check.
2. Every page has `description` front matter, since it drives the listing cards and meta tags.
3. Accessibility pass on the new toggles — the platform selector's tablist pattern is already
   correct, so match it.
4. Re-run the whole `tools/cvar_audit` suite plus the site build.
5. Update `ai-disclosure.md` to describe the current process.
6. Re-read the four original guides for claims that Phases 1–5 invalidated.

---

# Part 2 — Agent prompts

Each prompt is self-contained. Run them in order within a phase; phases 4, 5 and 6 are
independent. Every prompt assumes the agent has both branches available locally.

Substitute `<REPO>` with your local checkout path. Where a prompt says "ask before
proceeding", it means the work has a decision embedded that shouldn't be guessed.

---

## Prompt 0.1 — Conventions document and badge

```
You are working in the TaystJK documentation repository at <REPO>, on the `gh-pages`
branch. This branch is a Jekyll site using `remote_theme: just-the-docs/just-the-docs`
with a single custom layout at `_layouts/reference.html` applied to every page via
`defaults` in `_config.yml`. Site JS lives in `assets/js/reference-app.js` and CSS in
`assets/css/reference.css`. The `master` branch of the same repository holds the C/C++
game source.

Task: establish the conventions that all future documentation work will follow.

1. Read `_config.yml`, `_layouts/reference.html`, `assets/css/reference.css`, `index.md`,
   `install.md` and `reference.md` before writing anything. Note the existing front matter
   fields actually in use and the existing badge markup for "needs review" and "xdocs".

2. Create `CONVENTIONS.md` at the repository root, excluded from the built site via the
   `exclude` list in `_config.yml`. It must define:
   - The front matter schema for hand-written pages: `title`, `description`, `nav_order`,
     `parent`, and three new optional fields — `origin` (one of: basejka, openjk, japro,
     eternaljk, newjk, jk2mv, rend2, vulkan, taystjk), `status` (one of: stable,
     experimental, deprecated), and `added_on` (format `YYYY-MM-DD (shorthash)`).
   - Heading depth rules, code fence language tags, and the existing source-link policy
     (GitHub blame links with a pinned commit, as used throughout the current guides).
   - Terminology: when to write "client" vs "engine" vs "module"; "base" vs "mod
     directory"; `fs_game` vs `fs_forcegame`.
   - A short style note matching the existing prose: direct, second person for
     instructions, no marketing language.

3. Implement the `status: experimental` badge. Render it in `_layouts/reference.html` next
   to the page title when the field is present, and style it in `assets/css/reference.css`
   consistently with the existing badges. Do not invent a new colour system — reuse the
   existing custom properties.

4. Add a temporary page `_conventions-test.md` with `status: experimental` so the badge can
   be verified, and tell me to delete it once I have seen it render.

Constraints:
- Do not modify any file under `reference/cvars/`, `reference/commands/` or `_data/`.
  Those are generated.
- Do not change the nav structure in this task.
- Run `python3 tools/cvar_audit/check_generated.py` and `python3 tools/cvar_audit/validate.py`
  before finishing; both must pass.

Deliverable: a single commit with a message describing the convention additions, and a
summary of every field you defined with a one-line rationale for each.
```

---

## Prompt 0.2 — Retire the orphaned pages with redirects

```
You are working in the TaystJK documentation repository at <REPO>, on the `gh-pages` branch.

Context: three groups of pages are left over from an older Just-the-Docs structure and are
no longer linked from the site navigation, but are still built and reachable by URL:
- `hardcoded-changes.md` plus `hardcoded-changes/{keybinds-commands,miscellaneous,shader-overrides,vulkan}.md`
  — the child files are front-matter-only stubs whose `permalink` points at anchors on the
  parent page.
- `cvars/` — `crosshair.md`, `demos.md`, `hud.md`, `miscellanous.md` (note the misspelling),
  `sound.md`, `strafe.md` and subdirectories.
- `commands/` — `miscellaneous.md`, `strafe.md` and a subdirectory.

The `cvars/` and `commands/` pages are marked `nav_exclude` and `search_exclude` in
`_config.yml` but still build. Their content is stale: for example the
`cg_drawTeamOverlay 3` / `4` description predates a later overlay overhaul.

Task:
1. Inventory every URL these pages currently produce, including the permalink overrides on
   the `hardcoded-changes/` stubs. Produce the list before deleting anything.
2. Add `jekyll-redirect-from` to `_config.yml` plugins and `Gemfile` if one exists;
   if adding a plugin is not viable on GitHub Pages' allowed plugin list, implement the
   redirects as minimal meta-refresh stub pages instead and say which approach you took
   and why.
3. Delete the `cvars/` and `commands/` trees and the four `hardcoded-changes/` child stubs.
   Keep `hardcoded-changes.md` as a redirect stub only.
4. Point every retired URL at `/TaystJK/features/` as a placeholder destination. That page
   does not exist yet — leave a clearly marked TODO in the redirect map noting that the
   destinations need revisiting after the Features section is built.
5. Record the full old-URL-to-new-URL map in `CONVENTIONS.md` under a "Redirects" heading.

Constraints:
- Preserve the prose content of `hardcoded-changes.md` verbatim in a scratch file at
  `.migration/hardcoded-changes-original.md` before you delete or replace anything. That
  text is the seed for several future pages and must not be lost.
- Do not touch generated reference pages.
- Verify the site still builds and that `python3 tools/cvar_audit/check_generated.py` passes.

Deliverable: the URL inventory, the approach decision with rationale, and a commit.
```

---

## Prompt 1.1 — Resolve macro-valued defaults

```
You are working in the TaystJK repository at <REPO>. The documentation branch is
`gh-pages`; the C/C++ source is on `master`. The reference pipeline lives at
`tools/cvar_audit/` on `gh-pages` and extracts cvar and command registrations from the
source branch.

Problem: 17 cvar entries in `_data/cvars.json` show an unresolved C macro as their default
value instead of the value the user would see. Confirmed cases:

  cl_motdServer1 = UPDATE_SERVER_NAME        cl_motdServer2 = JKHUB_UPDATE_SERVER_NAME
  cl_renderer    = DEFAULT_RENDER_LIBRARY    forcepowers    = DEFAULT_FORCEPOWERS
  gamedate       = SOURCE_DATE               gamename       = GAMEVERSION
  model          = DEFAULT_MODEL             r_drawBuffer   = GL_BACK
  r_textureMode  = GL_LINEAR_MIPMAP_LINEAR   saber1         = DEFAULT_SABER
  sv_master1     = MASTER_SERVER_NAME        sv_master2     = JKHUB_MASTER_SERVER_NAME
  ui_blueteam    = DEFAULT_BLUETEAM_NAME     ui_char_anim   = BOTH_WALK1
  ui_opponentName = DEFAULT_BLUETEAM_NAME    ui_redteam     = DEFAULT_REDTEAM_NAME
  ui_saber       = DEFAULT_SABER

For reference, `codemp/qcommon/qcommon.h` defines `MASTER_SERVER_NAME` as
"masterjk3.ravensoft.com" and `JKHUB_MASTER_SERVER_NAME` as "master.jkhub.org".

Task:
1. Read `tools/cvar_audit/extract.py` and understand how default values are currently
   captured. Do not start editing until you can explain the existing path in one paragraph.
2. Extend the extractor to resolve object-like `#define` chains from the source branch when
   a captured default is a bare identifier matching `[A-Z][A-Z0-9_]{3,}`. Resolve
   transitively. Handle the case where the macro expands to another macro.
3. Where a macro is platform-conditional or expands to something that is not a literal
   (for example `GL_BACK`, which is an OpenGL enum, or `BOTH_WALK1`, which is an animation
   enum), do not fabricate a value. Keep the identifier and record its kind, so the page can
   render "GL_BACK (OpenGL enum)" rather than a misleading literal.
4. Preserve both forms in the data: add a `default_macro` field alongside the existing
   `default`, so provenance is not lost.
5. Where resolution is genuinely impossible from source, add an entry to
   `tools/cvar_audit/overrides.json` with a comment explaining why — do not hardcode values
   into the extractor.
6. Update `tools/cvar_audit/schema.json` for the new field and extend
   `tools/cvar_audit/test_extract.py` with cases covering: a simple literal macro, a
   transitive macro chain, and an unresolvable enum identifier.
7. Regenerate and verify.

Verification, all of which must pass:
  python3 tools/cvar_audit/test_extract.py
  python3 tools/cvar_audit/validate.py
  python3 tools/cvar_audit/check_generated.py
  node tools/cvar_audit/test_reference_app.js

Report: the before/after value for all 17 entries, and any you deliberately left as
identifiers with the reason.
```

---

## Prompt 1.2 — Decide the fate of the `range` field

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.

Problem: the reference schema has a `range` field, but it is populated on only 16 of 2,014
entries. A field that is empty 99.2% of the time is worse than no field, because readers
infer that unconstrained cvars have no limits.

Task — investigate first, then implement one of two outcomes:

Investigation:
1. Determine how the 16 populated ranges were derived. Read `tools/cvar_audit/extract.py`
   and `tools/cvar_audit/build_reference.py`.
2. Survey the source branch for the mechanisms that actually constrain cvar values:
   `Cvar_Get` variants carrying min/max, `Cvar_CheckRange`, `Cvar_Set` clamping,
   and manual clamping inside the registering function. Count how many registrations
   could have a range extracted mechanically with reasonable confidence.
3. Report the count and your confidence assessment before implementing.

Then, if mechanical extraction can reach a substantial fraction of constrained cvars:
   implement it, mark each extracted range with a confidence level consistent with the
   existing `confidence` vocabulary, and never present an inferred range as certain.

Otherwise:
   remove `range` from `schema.json`, the entry template and the filter UI, and migrate the
   16 existing values into the entry description text so the information is not lost.

Constraints:
- Do not guess ranges from cvar names or from what seems sensible.
- Whichever path you take, `python3 tools/cvar_audit/validate.py` and
  `python3 tools/cvar_audit/check_generated.py` must pass, and
  `node tools/cvar_audit/test_reference_app.js` must pass with the filter UI in its new state.

Deliverable: the investigation report, your recommendation, and — only after I confirm the
direction — the implementation.
```

---

## Prompt 2.1 — Baseline mapping and the what's-new generator

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.

Goal: generate a single "What's new" page with a three-way baseline toggle, replacing the
hand-maintained `CHANGELOG.md` on `master` as the source of truth for cvar-shaped changes.

Background: every entry in `_data/cvars.json` and `_data/commands.json` carries
`origin.source`, one of: basejka, openjk, japro, eternaljk, newjk, jk2mv, rend2, vulkan,
taystjk. Current distribution across 2,014 entries: basejka 1024, japro 458, openjk 167,
eternaljk 148, rend2 90, taystjk 79, vulkan 24, jk2mv 14, newjk 10.

Origin labels are not baselines. rend2, Vulkan, JK2MV and NewJK work arrived on the TaystJK
side rather than with EternalJK, so they belong in the narrowest bucket. The mapping is:

  vs EternalJK : taystjk, rend2, vulkan, jk2mv, newjk           -> 217 entries
  vs OpenJK    : the above + japro, eternaljk                   -> 823 entries
  vs base JKA  : the above + openjk                             -> 990 entries

Task:
1. Add the mapping to `tools/cvar_audit/build_reference.py` as an explicit, commented
   constant. Do not derive baselines from `origin.source` at render time.
2. Extend `tools/cvar_audit/generate_docs.py` to emit `whats-new.md`, with entries grouped
   by the existing `category`/topic taxonomy, each showing name, summary, origin badge and
   `added_on` (see Prompt 2.3 — if that field does not exist yet, leave a clearly marked
   insertion point).
3. Implement the baseline toggle by extending the existing platform-selector component in
   `assets/js/reference-app.js`. Read that component first. Match its tablist markup, its
   ARIA attributes, and its saved-per-device behaviour, but use a distinct storage key so
   the two selectors do not interfere. Default to "vs EternalJK".
4. The page must be usable without JavaScript: render all three groupings in the HTML and
   hide with CSS, the same way the platform panels work.
5. Assert the three counts in `tools/cvar_audit/validate.py` so a future data change that
   silently reshuffles baselines fails CI.

Constraints:
- Do not modify `master` in this task.
- Do not delete or edit `CHANGELOG.md` yet; superseding it is a later decision.
- `node tools/cvar_audit/test_reference_app.js` must pass, extended with coverage for the
  new toggle.

Deliverable: the generated page, the mapping constant, the toggle, and a note on any entry
whose origin looked misassigned while you worked — do not fix those here, just list them.
```

---

## Prompt 2.2 — Hand-tuning layer and non-cvar feature inclusion

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.
This task depends on Prompt 2.1 having landed.

Problem: the generated "What's new" page covers only cvars and commands. Several of the
most significant additions in this fork are not cvar-shaped and would be invisible:
`.oshader` override shaders, the cosmetics custom-offsets JSON format, modifier key binds,
widescreen levelshots, the Tribes movement mode, and the `taystJKinfo` feature flag system.
The page also needs editorial control — some entries deserve promotion, some are noise.

Task:
1. Add a hand-tuning layer. Recommended shape: `tools/cvar_audit/whats-new-overrides.json`
   supporting, per entry name — `hide`, `promote` (with a rank), `summary` (replacement
   text), and `group` (override the derived topic). Validate it against a schema and fail
   loudly on an unknown entry name, so the file cannot rot silently when a cvar is renamed.
2. Add a manual-entries mechanism for non-cvar features. Recommended shape: any page whose
   front matter carries `origin`, `added_on` and `whats_new: true` is collected into the
   generated page under the baseline its origin maps to. This reuses the front matter fields
   defined in CONVENTIONS.md rather than inventing a parallel list.
3. Seed the manual entries with these six, each pointing at the page that will document it.
   Pages may not exist yet — emit them with a TODO destination and make the build warn, not
   fail:
     .oshader override shaders            origin: taystjk
     Cosmetics custom offsets             origin: taystjk
     Modifier and side-specific binds     origin: newjk
     Widescreen levelshots                origin: taystjk
     Tribes movement mode                 origin: japro
     taystJKinfo feature flags            origin: taystjk
4. Document both mechanisms in CONVENTIONS.md.

Constraints:
- Hand-tuning must never silently drop a generated entry. `hide` must be recorded in the
  audit output so hidden entries remain discoverable.
- Validation and generated-page checks must pass.

Deliverable: both mechanisms, the six seeded entries, and documentation of the workflow for
adding a seventh.
```

---

## Prompt 2.3 — `added_on` markers

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Context: TaystJK has no version tags. Releases are rolling under a single `latest` tag, and
builds are identified as `latest-<shorthash>` with a build date. Users report builds that
way in issues, for example "latest-f5a861c63, built Aug 10 2026". So feature availability
cannot be expressed as "added in vX.Y" — it has to be a date plus a commit.

Task:
1. Derive an `added_on` value for every reference entry from `origin.first_commit` and its
   author date, formatted `YYYY-MM-DD (shorthash)`, with the commit hash linking to the
   commit on GitHub.
2. Emit it into `_data/cvars.json` and `_data/commands.json` via the normal pipeline, add it
   to `schema.json`, and render it on entry detail pages and on the what's-new page.
3. Add a short explanatory block, written once and included wherever `added_on` renders:
   the reader should compare the build date printed by `version` / `modversion` against the
   date shown, since an older build date means the feature is absent. Make clear that
   comparing hashes alone tells them nothing about ordering.
4. Handle the entries where `origin.confidence` is `medium` — do not present an uncertain
   first-commit date as settled. Mark it consistently with how the existing "needs review"
   state is presented.

Constraints:
- Do not invent dates for entries whose origin could not be resolved. Omit the field.
- The full test suite must pass.

Deliverable: the field, the rendering, the explanatory copy, and a count of entries where
you omitted the field and why.
```

---

## Prompt 2.4 — Changelog coverage report

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Context: `master` has a hand-maintained `CHANGELOG.md`, 266 lines, whose "Tayst's Fork"
section lists fork additions. It has fallen well behind. Of the 79 cvars and commands whose
resolved origin is `taystjk`, only 22 appear anywhere in the file; 57 do not, including the
entire SnapHUD family, the entire PitchHUD family, the whole killfeed set and all the
disruptor effect cvars.

Task:
1. Write `tools/cvar_audit/changelog_coverage.py`. It reads the reference data and
   `master`'s `CHANGELOG.md`, and reports, per origin bucket, which entry names are present
   and which are absent. Match on the cvar or command name as a word, case-insensitively;
   be careful with names that are substrings of others (`cg_killfeed` vs `cg_killfeedX`) —
   a match on the longer name must not count as covering the shorter one.
2. Emit two outputs: a human-readable summary to stdout, and a machine-readable JSON
   artifact for CI.
3. Add a ratchet: store the current gap count in a checked-in file, and fail if the gap
   grows. Provide a documented way to update the ratchet when the gap legitimately shrinks.
4. Wire it into `.github/workflows/reference-drift.yml`.

Constraints:
- Read-only with respect to `master`. Do not edit `CHANGELOG.md` in this task.
- Report the current numbers as your first output so they can be compared against the
  expected 79 / 22 / 57 for the taystjk bucket.

Deliverable: the script, the CI wiring, the ratchet file, and the current per-bucket numbers.
```

---

## Prompt 3.1 — Features section scaffold

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.

Goal: create the navigation home for a new top-level "Features" section, covering additions
that the cvar and command reference cannot express on its own. This replaces a section that
existed in an older version of the site called "Hardcoded Changes".

Task:
1. Read `index.md`, `development.md` and `server-hosting.md` to learn the existing patterns
   for a section index page — the card grid, the eyebrow text above the H1, and the nav
   front matter.
2. Create `features.md` as the section index, positioned between Host and Develop in the
   top nav. Write its index copy: one paragraph explaining what belongs in this section
   versus what belongs in the console reference.
3. Create stub child pages with complete front matter — `title`, `description`, `nav_order`,
   `parent`, and where applicable `status` and `origin` — and a single-sentence placeholder
   body plus a visible "not yet written" note:
     features/whats-new.md            (generated later — leave a marker, do not hand-write)
     features/client-behaviour.md
     features/cosmetics.md
     features/hud-and-movement.md
     features/renderers.md
     features/movement-styles.md
     features/tribes.md               (status: experimental)
     features/shipped-configs.md
     features/emoji.md                (generated later)
     features/platform-support.md
     features/builds-and-versioning.md
4. Add the top-nav entry and confirm the section renders in the sidebar at the right depth.
5. Update the redirect destinations left as TODO by the orphan-retirement task so they now
   point at real pages: shader-override content to `features/client-behaviour.md`, the
   Vulkan stub to `features/renderers.md`, keybinds to `features/client-behaviour.md`, and
   the old `cvars/` and `commands/` pages to the most specific relevant feature page.

Constraints:
- No body content beyond placeholders. Content comes in later tasks.
- Every stub must have a `description`, because it drives both the card grid and meta tags.
- `python3 tools/cvar_audit/check_generated.py` must pass and the internal link check must
  report zero breaks.

Deliverable: the scaffold, the nav change, and the updated redirect map.
```

---

## Prompt 3.2 — Overview, glossary, and the jaPRO explainer

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.

Three related pages are missing, and their absence forces every other page to over-explain.

Task 1 — Overview page (`overview.md`, linked prominently from `index.md`):
Explain how this documentation is organised and how the console reference works. It must
cover: the four task guides versus the generated reference; what "origin" means and that it
identifies where an entry first appeared rather than every fork that ships it; what the
`needs review`, `xdocs` and `menu` badges mean; what "network scope" and "renderer scope"
distinguish; how `added_on` should be compared against a build date; and where the data
comes from, including that it is regenerated from a pinned source commit. Read
`reference.md` and `reference/sources.md` first and do not contradict them — link to
`reference/sources.md` for methodology rather than restating it.

Task 2 — jaPRO explainer:
jaPRO is the bundled mod and this is assumed knowledge across the install, hosting and
reference pages without ever being stated. Write a concise explanation, placed on `index.md`
with a fuller version in the overview, covering: what jaPRO is; that it is the largest
single origin in the reference at 458 of 2,014 entries; that TaystJK ships jaPRO client-side
features and assets (`taystjk/japro-assets.pk3`, `assets/japro/` on the source branch); and
the distinction between those client-side features and a server running the jaPRO game
module. State plainly that game-module bugs belong at https://github.com/videoP/jaPRO —
this distinction is the single most common source of misdirected bug reports.

Task 3 — Glossary (`glossary.md`):
Define, each in one or two sentences with a link to the page that covers it in depth:
CGAZ, snaps and snap zones, ski, IFF, pure server, reflist, `fs_game` versus `fs_forcegame`,
base directory versus mod directory, cgame / game / UI module, QVM versus native module,
homepath / basepath / cdpath, serverinfo, feature flag, movement style, levelshot.

Constraints:
- Verify every factual claim against the source or the existing pages. If you cannot verify
  a claim, leave a clearly marked TODO rather than writing a plausible sentence.
- Match the existing prose style: direct, second person for instructions, no marketing tone.
- Do not restate cvar tables. Link to the reference.

Deliverable: three pages, nav entries, and a list of every TODO you left with the reason.
```

---

## Prompt 4.1 — Client behaviour changes

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Write `features/client-behaviour.md`: engine and client behaviour that differs from stock
Jedi Academy and that the cvar reference cannot express. The prose seed for part of this
page was preserved at `.migration/hardcoded-changes-original.md` — read it, but verify every
claim against current source before reusing it, because it predates several changes.

Cover at minimum, verifying each against `master`:

1. `.oshader` override shaders. Files matching `shaders/*.oshader` are listed and parsed
   after all `.shader` files and take final precedence when the shader list is built.
   Implemented in all three renderers — see `codemp/rd-vanilla/tr_shader.cpp` around
   line 3983, `shared/rd-rend2/tr_shader.cpp` around line 5035, and
   `codemp/rd-vulkan/tr_shader.cpp`. Explain why this exists: combining mods that patch
   shaders in the same base `.shader` file previously required merging them by hand.
   Give a concrete worked example of overriding one shader.
2. Shader phone-book precedence for same-named shaders across `.shader` files.
3. Bind system: `ctrl+`/`alt+`/`shift+` modifier combinations; separately bindable
   right-side `rctrl` / `ralt` / `rshift` with fallback to the generic bind; nested
   quotation marks in commands and binds.
4. Console and chat editing shortcuts, including the ctrl+backspace/delete/left/right
   family, and `con_datetime` and `con_height`.
5. Widescreen levelshots — `levelshots_16_9/<map_name>` — and `menu/splash_16_9` for
   ultrawide displays. Explain what an asset author has to provide.
6. `r_fontSharpness` and its dependency on newer assets.
7. Anything else you find in the same category while reading. List candidates you found but
   did not write up, rather than silently dropping them.

Requirements:
- Every behavioural claim carries a source link in the style used by the existing guides:
  a GitHub blame link with a pinned commit.
- Do not duplicate cvar tables that the reference generates. Link to reference entries.
- Add the front matter fields from CONVENTIONS.md, including `origin` and `added_on` where
  a feature is a fork addition, so it feeds the what's-new page.
- If a claim in the preserved original text is no longer true, say so explicitly in your
  report rather than quietly correcting it — I want to know what drifted.

Deliverable: the page, the drift report, and the list of unwritten candidates.
```

---

## Prompt 4.2 — Cosmetics

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Write `features/cosmetics.md`. This is a user-facing feature with a file format that is
currently undocumented outside a single example file.

Cover:

1. What the cosmetics system is, and the three modes: forced cosmetics for all players,
   individual cosmetics selected per player (enabled with `cg_forceCosmetics -1`), and
   seasonal cosmetics. Read the `cg_forceCosmetics` handling in `codemp/cgame/cg_players.c`
   and the `cosmetics` command implementation before writing.
2. The `cosmetics` console command — usage, what it lists, how selection works.
3. Adding a new cosmetic: where the `.md3` goes (`models/cosmetics/hats` or
   `models/cosmetics/capes` on the source branch), what the shader requirements are
   (see `assets/japro/shaders/japro_hats.shader` and `japro_capes.shader`), and what has to
   be packaged for other players to see it.
4. Custom offsets. The format is a JSON file per cosmetic at
   `cosmetics/{hats,capes}/<name>.cosmetic`. A worked example ships at
   `assets/settings/cosmetics/example.cosmetic` — read it. Document: top-level keys are
   model names; each model may carry `xOffset`, `yOffset`, `zOffset` and `modelFallback`;
   nested keys are skin names with their own offsets; skin keys support `*` wildcards and
   the longest matching key wins; `modelFallback` true means a skin with no entry inherits
   the model's offsets, false means it gets none. Verify all of this against the
   implementation rather than trusting my summary.
5. Seasonal cosmetics, including that the activation dates are set in code.

Requirements:
- Include the full shipped example file as a fenced code block with per-key commentary.
- Explain how someone tests their offsets in-game without restarting.
- Source-link every claim about the format.
- Front matter per CONVENTIONS.md; this is a fork addition so it needs `origin` and
  `added_on`.

Deliverable: the page, plus a note on any part of the format that the implementation
supports but the example file does not demonstrate.
```

---

## Prompt 4.3 — Renderers and movement styles

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Two pages, both reference-adjacent but not expressible as cvar tables.

Page 1 — `features/renderers.md`:
- The three backends: `rd-vanilla`, `rd-rend2`, `rd-vulkan`. What each is for, in practical
  terms a player can act on. rend2 is the feature-rich modern backend with higher memory
  use; Vulkan is derived from Quake3e's Vulkan renderer and is maintained downstream by
  JKSunny; vanilla is the compatibility baseline.
- Switching: `cl_renderer <name>` then `vid_restart`. Note the UI exposes this and that
  rend2-specific options are hidden when another backend is selected.
- Practical differences a user will notice: bloom via `r_fbo` / `r_bloom` on the Vulkan
  path, rend2 memory pressure on 32-bit builds, `.oshader` support present in all three.
- Where bugs go: Vulkan renderer issues to https://github.com/JKSunny/EternalJK, not here.
- Known instability, stated plainly: switching renderers can crash on some maps and asset
  sets. Reference the open issues rather than promising a fix.

Page 2 — `features/movement-styles.md`:
- Document all nineteen styles in the `MV_*` enum at `codemp/game/bg_public.h` lines 562-585:
  SIEGE, JKA, QW, CPM, Q3, PJK, WSW, RJQ3, RJCPM, SWOOP, JETPACK, SPEED, SP, SLICK, BOTCPM,
  COOP_JKA, OCPM, TRIBES, SURF.
- For each: what it is derived from and how it plays. `docs/Defrag Mapping Guide.md` on
  `master` already describes siege, jka, qw, cpm and q3 — read it and stay consistent.
- Be precise about WSW. It is a Warsow-inspired style in the CPM family: it shares
  double-jump handling with CPM/RJCPM/SLICK/BOTCPM, has its own constants
  `pm_wsw_accelerate` (12.0) and `pm_wsw_duckScale` (0.3125) in `codemp/game/bg_pmove.c`,
  and its rampjump is deliberately weakened because the style has no speedloss. It is NOT
  part of Tribes. The only thing the two share is the dash button (`BUTTON_DASH` /
  `STAT_DASHTIME`), which Tribes also uses to gate its slick-friction path.
- Note which styles are selectable by players versus set by the server, and how.
- Link to the Tribes page for that style rather than describing it fully here.

Requirements:
- Verify the derived-from claims against the source and comments; if a style's lineage is
  not stated anywhere, say it is undocumented rather than guessing.
- Source-link the enum and the constants.

Deliverable: both pages, and a list of any style you could not describe confidently.
```

---

## Prompt 4.4 — Tribes, shipped configs, platform support, builds

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Four smaller pages.

Page 1 — `features/tribes.md`, front matter `status: experimental`:
Tribes is a jaPRO movement mode with substantial supporting systems, built out across
roughly 48 commits in this fork. Document, verifying each against source: skiing with a
speed-based sound effect; the jetpack with a fuel bar; class and pack selection via a
dedicated menu; IFF with distance-based scaling; the `invfree` command and its HUD keybind
prompt; shots-remaining rather than total ammo on the HUD; single-fire and select-fire
modes; the mortar; midair and frag sounds; and the dedicated Tribes HUD. Note the shipped
configs `japro_tribes.cfg` and `japro_tribes_server.cfg` under `assets/japro/`.
State clearly at the top that the mode is experimental and lightly played.

Page 2 — `features/shipped-configs.md`:
Fourteen `.cfg` files ship under `assets/japro/` and nothing documents them:
hud_tayst.cfg, japro_default.cfg, japro_loda.cfg, japro_tribes.cfg, japro_tribes_server.cfg,
noMotion.cfg, restoreMotion.cfg, strafehelper.cfg, strafehelper_jk2.cfg,
strafehelper_loda.cfg, strafehelper_off.cfg, strafehelper_source.cfg,
strafehelper_tayst.cfg, strafehelper_tayst2.cfg.
Read each one. For each: what it configures, who it is for, and how to apply it
(`exec <name>`). Group them — HUD presets, strafe helper presets, Tribes, motion toggles.

Page 3 — `features/platform-support.md`:
A matrix of features whose availability varies by platform or architecture. Verified cases:
EAX environmental audio is 32-bit Windows only because `EaxMan64.dll` is not shipped;
music commands ported from NewMod are Windows only; Discord Rich Presence is disabled on
arm64 macOS because the prebuilt library is Intel-only, and disabled under AddressSanitizer
on MSVC; portable builds store user files beside the executable and fall back to the install
path for logs because homepath is null. Search for other platform-conditional behaviour
while you work and add what you find.

Page 4 — `features/builds-and-versioning.md`:
There are no version tags. Explain the rolling release model: a single `latest` tag, builds
identified as `latest-<shorthash>`, a build date, and a short hash in `/modversion`. Cover
`version` and `modversion` output, how to read it, how to report it in a bug report, and how
to compare it against an `added_on` marker to work out whether a build has a feature.
Mention portable and debug build variants and the Windows AddressSanitizer artifact.

Requirements for all four: source links, front matter per CONVENTIONS.md, no invented
claims — mark anything unverifiable as TODO.
```

---

## Prompt 5.1 — Troubleshooting hub and report routing

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.

These pages come from the issue tracker at https://github.com/taysta/TaystJK/issues.
Read the referenced issues before writing; the useful content is usually in the comments.

Page 1 — `troubleshooting.md`, organised by symptom as a user would search for it:
- "My server does not appear in the server list" (issues #215, #294). Cover the master
  server situation: `sv_master1` defaults to `masterjk3.ravensoft.com`, which is long dead,
  and `sv_master2` defaults to `master.jkhub.org`, which is the one that works. Cover
  heartbeat, UDP port forwarding, `dedicated 2` versus `1`, and checking the local versus
  internet tabs. This is the highest-volume support question in the tracker.
- "The game will not open on macOS after updating" (#261, #355, #343). The quarantine
  attribute is reapplied on every fresh download; link the existing install-page coverage
  rather than duplicating it.
- "The client crashes on a modded server" (#269, #275). Root cause is architecture mismatch
  when a mod directory in the same GameData supplies a 32-bit `ui` or `cgame` library to a
  64-bit client. Describe the symptoms, not just the layout advice the install page gives.
- "No saber hum, or sound distance is wrong, on Linux" (#245, #246). Cover the audio backend
  situation and how to switch.
- "The dedicated server rewrites my config" (#294). Use `+exec server.cfg`; do not hand-edit
  the generated config.

Page 2 — `where-to-report.md`:
A routing table. Game-module and gameplay bugs go to https://github.com/videoP/jaPRO
(issues #268, #266, #267, #121, #244 were all redirected there). Vulkan renderer bugs go to
https://github.com/JKSunny/EternalJK (#73, #107). JA+ is closed source and cannot be fixed
by anyone here (#178). Everything else belongs on TaystJK. Include a short "how to tell
which" guide, since the distinction is not obvious to players.

Requirements:
- Symptom-first headings. A reader searching their error message must land on the right one.
- Do not promise fixes for open bugs. Link the issue and describe the current state.
- Cross-link to the reference for any cvar you mention.
- List the issues each page makes closable.
```

---

## Prompt 5.2 — Server hosting expansion and mod compatibility

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Task 1 — extend `server-hosting.md`. Read the existing page fully first; it is accurate and
well structured, and this is an addition rather than a rewrite. Add:
- Master servers and the server list, cross-linked to the troubleshooting page.
- A warning not to hand-edit the generated server config; use `+exec server.cfg`.
- `sv_pure` on a non-base `fs_game`. Issue #365 documents a client disconnect against a
  JA+ server with pure enabled; all JA+ servers on the list run `sv_pure 0`. Read that issue
  and the linked PR before writing, and describe current post-fix behaviour, not the bug.
- The real-world Docker Compose example from issue #331's comments: `TJK_MOD=japlus`,
  `TJK_OPTS=+exec server.cfg +set net_port 29080 +set vm_legacy "7"`, `network_mode: host`.
  Explain the port and `net_port` interaction, which is the trap in that example.
- Filesystem and downloads internals not currently covered: the `fs_restart` command; the
  removed 1024-pk3 limit and the `-maxfds` launch override; native libraries not being
  unpacked from pk3s by default; the high-kernel-load workaround for large pk3 counts;
  `cl_filterGames`; the download overlay and `cl_downloadPrompt`.
- Serverside demo recording: `sv_demoPreRecord`, `sv_demoPreRecordTime`,
  `sv_demoPreRecordKeyframeDistance`, `sv_demoPreRecordBots`, `sv_demoWriteMeta`, the
  metadata-setting game commands, and the JK2DemoCutter-derived metadata format. Partial
  documentation exists in `docs/japro_docs.md` on `master` — read it and stay consistent.

Task 2 — new page `mod-compatibility.md`:
Which client features change behaviour depending on the server mod. The mechanism is the
`serverMod` detection (`SVMOD_JAPLUS`, `SVMOD_JAPRO`, `SVMOD_LMD`) combined with the
`taystJKinfo` feature flags. Build a matrix by reading the `cgs.serverMod` and
`cgs.taystJKinfo` checks in `codemp/cgame/` and `codemp/game/bg_pmove.c`. Include the
Lugormod `STAT_EXTRA_FORCE_BITS` collisions that were fixed across roughly ten commits —
they are a good illustration of why stat reuse across mods is fragile. Answer the question
players actually ask: why does feature X work on one server and not another.

Task 3 — new page `development/feature-flags.md`:
The `taystJKinfo` serverinfo key lets a server advertise TaystJK-supported features in a
mod-independent way. The bits are defined in `codemp/game/bg_public.h` lines 550-556:
1 RGB sabers, 2 black sabers, 4 flipkick, 8 grapple, 16 fixroll variant 1 (roll while
gripping), 32 fixroll variant 2 (adds roll chaining), 64 fixroll variant 3 (JK2 roll).
Document how a server mod sets the key, how the client reads it in `cg_servercmds.c`, the
interaction with `serverMod` detection, and a worked example for a mod author. This closes
issue #308.

Requirements: source links throughout; verify the bit values rather than trusting the list
above; note anything in the flag system that looks incomplete or unused.
```

---

## Prompt 5.3 — Contributing, attribution, and the documentation system

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Three developer-facing pages.

Page 1 — `development/contributing.md`:
- PR flow against `master`, what CI runs, and the build matrix.
- How to test a fix without building: download artifacts from a PR's Actions run. This
  workflow was used successfully in issues #300 and #334 and is not written down anywhere.
- How to build from source as a reporter rather than a developer — link the existing
  compiling guide, do not duplicate it.
- What makes a good bug report here: build identifier from `version` / `modversion`, OS and
  architecture, renderer, server and mod, and reproduction steps.
- Where changes belong: engine versus game module versus upstream projects. Cross-link the
  report-routing page.

Page 2 — `attribution.md`:
TaystJK is GPLv2 and incorporates substantial ported work. Build a credits page covering at
minimum: OpenJK, EternalJK, jaPRO (videoP), JK2MV, NewJK/NewMod, rend2 (SomaZ, Xycaleth),
the Vulkan renderer (JKSunny, derived from Quake3e), the killfeed from the q3 bloodrun
champions mod with icons from Circa, disruptor effects from jaMME, cosmetics assets from
MB2, movement key assets from TriForceX, and individual contributors including Daggolin,
Alereon, Slash, Tom Arrow, lumayaa and Vincent Marnier. Derive the contributor list from
`git shortlog -sn` on the fork delta rather than from my list, and state the licensing
obligation for anyone redistributing modified binaries. Issue #22 raised GPL compliance, so
be precise rather than decorative.

Page 3 — `development/documentation-system.md`:
How the docs are built and maintained. Cover: the `gh-pages` branch and Jekyll setup; the
`tools/cvar_audit/` pipeline and what each script does; the evidence inputs and the remote
refs the provenance resolver expects; how to regenerate; what `check_drift.py` detects;
the in-game xdocs system in `codemp/ui/ui_xdocs.h`, `codemp/ui/nm_xdocumentation.h`,
`codemp/cgame/cg_xcvar.h` and `codemp/ui/ui_xcvar.h`, and how to add an entry for a new
cvar; and the relationship between xdocs, the shipped menu definitions and the wiki, which
is what the `xdocs` and `menu` badges in the reference report on. Much of the pipeline
detail already exists in `tools/cvar_audit/README.md` — read it and link rather than fork it.

Requirements: verify the xdocs macro names and usage by reading the headers; do not
describe a workflow you have not traced through the code.
```

---

## Prompt 6.1 — Devlog

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.
Jekyll with `remote_theme: just-the-docs/just-the-docs`, single layout at
`_layouts/reference.html`, all pages defaulted to it via `_config.yml`.

Goal: a devlog the maintainer can post to occasionally — notes on work in progress, design
decisions, ideas. Low ceremony: adding one markdown file with front matter should be the
entire workflow.

Task:
1. Configure a `devlog` collection in `_config.yml` with `output: true` and a permalink
   scheme of `/devlog/:year/:month/:day/:title/`. Do not use Jekyll's built-in `_posts`,
   because the theme's defaults handling makes it awkward here — but if you find that posts
   are in fact the cleaner fit after reading the theme, say so and justify the choice.
2. Create `_layouts/devlog.html` extending the existing layout: title, date, optional
   `tags`, and body. Match the site's visual language using the existing CSS custom
   properties; do not introduce a new palette.
3. Create `devlog.md` as the index — reverse-chronological listing with title, date and an
   excerpt, and a link to the feed.
4. Add an Atom feed at `devlog/feed.xml` so posts can be syndicated to Discord.
5. Add the nav entry.
6. Write one seed post dated today that exercises every feature of the layout: headings,
   a code block, a list, an image reference, and tags. Content can be a short note about
   the documentation rework itself.
7. Document the authoring workflow in CONVENTIONS.md: where the file goes, required front
   matter, and how to preview locally.

Constraints:
- No new build dependencies beyond what GitHub Pages allows.
- The index and feed must update from the file alone, with no manual registration step.
- The site must build clean and `check_generated.py` must pass.

Deliverable: the collection, layout, index, feed, seed post, and the authoring docs.
```

---

## Prompt 7.1 — Maintenance automation

```
You are working in the TaystJK repository at <REPO>. Docs on `gh-pages`, source on `master`.

Problem: `.github/workflows/reference-drift.yml` on `gh-pages` runs the extractor tests,
provenance tests, search-app test, record validation, generated-page validation, and
`check_drift.py --ref origin/master`. But it only triggers on `gh-pages` push, `gh-pages`
PR, and manual dispatch. A cvar added on `master` therefore produces no signal at all until
somebody happens to touch the docs branch.

Task:
1. Add a weekly `schedule:` trigger to the drift workflow.
2. Change the drift step so that on a scheduled run, detected drift opens or updates a
   tracking issue with the specific entries that drifted, instead of only failing the job.
   Keep hard failure behaviour for PR and push triggers. Use the built-in GITHUB_TOKEN;
   do not add third-party actions beyond what is already in use.
3. On `master`, add a non-blocking PR check that greps the diff for `Cvar_Get`,
   `Cvar_Register` and command-registration calls, and when matched posts a comment linking
   the xdocs headers, the reference pipeline README and the documentation checklist.
   Non-blocking is deliberate — it must never gate a merge.
4. On `master`, add `.github/PULL_REQUEST_TEMPLATE.md` with a documentation checklist:
   new cvar has an xdocs entry; has a menu entry if user-facing; has an `overrides.json`
   entry if the generated summary would be a placeholder; has a wiki page if the feature is
   not cvar-shaped.
5. Wire the changelog coverage report into the drift workflow with its ratchet.
6. Add a drift check between `master`'s `docs/` markdown files and the wiki pages that
   overlap them (`docs/developer/libraries.md` against `development/libraries.md` is the
   clearest case), or, if a meaningful automated comparison is not practical, add a
   canonical-copy notice to the top of each `docs/` file instead — and say which you chose.
7. Make the release workflow regenerate the reference rather than relying on ad-hoc runs.

Constraints:
- Changes span both branches. Keep them in separate commits per branch and state clearly
  which change lands where.
- Do not make any new check blocking without saying so explicitly and justifying it.
- Test the workflow logic as far as `act` or a dry-run allows, and state what you could not
  verify without pushing.
```

---

## Prompt 8.1 — Final audit

```
You are working in the TaystJK documentation repository at <REPO>, branch `gh-pages`.
All content and structural work is complete. This is the closing review.

Task:
1. Link integrity: check every internal link across all hand-written and generated pages,
   including anchors, and every external link for a 200 response. Report broken links with
   the file and line.
2. Front matter completeness: every page has `title` and `description`; every page in the
   Features section has `origin` and `added_on` where it documents a fork addition; `status`
   is present wherever a feature is experimental.
3. Accessibility: the new baseline toggle and any other new interactive component match the
   ARIA tablist pattern already used by the platform selector in
   `assets/js/reference-app.js`. Verify keyboard navigation and focus handling.
4. Run the full pipeline and test suite:
     python3 tools/cvar_audit/test_extract.py
     python3 tools/cvar_audit/test_provenance.py
     node  tools/cvar_audit/test_reference_app.js
     python3 tools/cvar_audit/validate.py
     python3 tools/cvar_audit/check_generated.py
     python3 tools/cvar_audit/check_drift.py --ref origin/master
   plus a local Jekyll build with no warnings.
5. Consistency sweep: re-read `install.md`, `server-hosting.md`, `development/compiling.md`
   and `development/debugging.md` for claims invalidated by the new pages — particularly
   anything about renderers, mod loading, downloads or configuration that a Features page
   now covers in more depth. Report contradictions; do not silently rewrite them.
6. Update `ai-disclosure.md` to describe the current process accurately, including what is
   generated from source versus hand-written, and what verification each goes through.
7. Produce a coverage report: which of the 2,014 reference entries now have a hand-written
   page linking to them, and which feature areas from the original inventory remain
   unwritten.

Deliverable: an audit report with every finding categorised as blocking, should-fix, or
nice-to-have. Fix only the blocking ones in this task; list the rest for me to triage.
```

---

# Notes on using these prompts

- Run one per session. Several touch the generator and the data at the same time; running
  two in parallel will produce merge conflicts in `_data/`.
- Prompts 1.2 and 7.1 have decisions embedded. Both are written to report and ask rather
  than pick, so expect a round trip.
- Prompts 4.x and 5.x will produce factual errors if the agent is allowed to write from
  its own knowledge of Jedi Academy. The "verify against source, mark unverifiable as TODO"
  instruction is doing real work in each of them — do not trim it.
- The counts quoted throughout (2,014 entries, 1,135 placeholders, 217/823/990 baselines,
  57 of 79 changelog gap) were measured against source commit `6ff04c0`. Re-measure before
  relying on them if the reference has been regenerated since. Every figure was re-verified
  on 2026-09-13 against that same commit; all held except the placeholder count, which was
  stated as 1,029. See the note at the top of `taystjk-docs-plan.md`.
