# TaystJK documentation development

This is the shared project guide for coding agents working on the GitHub Pages wiki.
Read [CONVENTIONS.md](CONVENTIONS.md) for page structure, prose, source links, and
editorial overrides. Read [the audit guide](tools/cvar_audit/README.md) when changing
reference data or the generation pipeline.

## Working agreements

- Follow the user's requested scope. Make routine, reversible decisions and state
  material assumptions; ask when missing information would materially change the result.
  Continue independent work while waiting for an answer.
- Explicit user instructions take precedence over project guidelines. If a guideline
  prevents progress, name its file and the specific instruction rather than silently
  stopping or inventing an approval requirement.
- Keep changes focused, match the existing style, and preserve unrelated local work.
  Do not add speculative features, abstractions, dependencies, or adjacent refactors.
- Give a short plan for multistep work and concise progress updates. Finish with what
  changed, the checks actually run, and any remaining limitations.
- Use checks appropriate to the change. Add regression coverage for meaningful behavior
  changes; do not add tests that merely restate a prose edit or rerun passing checks
  without a new change or unresolved concern.

## Repository and source evidence

- `gh-pages` and its working branches contain the Jekyll site, served with
  `baseurl: /TaystJK`. `master` contains the C/C++ engine; it is not part of this branch.
- Documentation work normally edits this checkout and reads engine source from git refs
  or a separate worktree, usually `../TaystJK-src`. Keep that source worktree detached
  when using it for reference; do not switch the documentation checkout to `master`.
  If needed, create the reference worktree with
  `git worktree add --detach ../TaystJK-src origin/master`.
- Audit scripts use remote-tracking refs, not the source worktree's HEAD. Verify the
  available refs and `_data/reference-meta.json`'s `source_commit`; do not assume a local
  `origin/master` is current or that it matches the pinned reference commit.
- Link claims about engine behavior to GitHub blame at the full `source_commit` and
  verified lines. Preserve origin attribution and evidence. Unverified semantics stay
  visibly unresolved (`needs-review` in reference data, `TODO` in handwritten prose).
- The audit guide lists the upstream refs, PR metadata, cache refresh, and runtime
  capture requirements. Reuse those procedures instead of inventing provenance or
  fabricating missing runtime captures.

## Edit the source of generated content

Never hand-edit generated outputs. Read `tools/cvar_audit/generate_docs.py` to confirm
ownership and change its inputs or rendering code instead. Its outputs include:

- `index.md` and `reference.md` (both are generated).
- `reference/cvars/`, `reference/commands/`, and the category, feature, module, and origin
  collection pages and indexes under `reference/`, including the audit, sources, and
  removed pages.
- `features/whats-new.md` and `features/emoji.md`.
- The public reference JSON copies and compact catalog under `assets/data/`.

`_data/cvars.json`, `_data/commands.json`, and `_data/reference-meta.json` come from the
reference pipeline. `_data/reference_stats.json` comes from `generate_docs.py`; hand-written
pages quote reference counts from it instead of typing them. `_data/page_updated.json`
comes from `page_dates.py`. Update their source or generator rather than editing those
files directly.

For editorial changes to what's-new rows, use `tools/cvar_audit/whats-new-overrides.json`
as described in CONVENTIONS.md. For rendering or editorial-input changes that do not
change source registrations, regenerate from the existing evidence:

```sh
python3 tools/cvar_audit/generate_docs.py
```

When source registrations or provenance change, follow the full audit-guide sequence:
provenance, reference assembly, runtime reconciliation when captures are available,
then page generation. Inspect the generated diff for unexpected changes to attribution,
source commits, URLs, or unrelated entries.

Handwritten pages include the install, hosting, development, overview, glossary,
troubleshooting, and individual feature guides.
Check the generator and `generated: true` front matter before editing an unfamiliar page.

## Site structure and publication

- Jekyll uses local layouts and no theme. `_layouts/reference.html` provides the main
  navigation, breadcrumbs, section previous/next links, and shared page furniture.
  Top-level navigation is explicit; child sequencing and the active header tab use
  `parent` and `nav_order`. `_data/navigation.yml` holds the grouped cards on the Features
  and Help hubs, rendered by `_includes/browse-grid.html`.
- `_layouts/devlog.html` supplies post headings. `_layouts/none.html` handles raw output
  and redirect stubs. Follow CONVENTIONS.md's distinct guide and devlog structures.
- `assets/js/reference-app.js` handles reference filters and platform selection;
  `assets/js/site-search.js` handles header search and heading anchors. Search data comes
  from `search-index.json`. Preserve keyboard behavior and existing ARIA patterns.
- `assets/css/reference.css` is the shared stylesheet. Reuse color tokens and check
  both themes when changing presentation.
- Preserve retired URL stubs, including the published `cvars/miscellanous/` spelling
  and the old what's-new and emoji paths. Use `relative_url` for template links and
  keep `/TaystJK/` links valid in generated Markdown.
- `_config.yml`'s `exclude` list replaces Jekyll defaults. Keep agent guides, tooling,
  and local build artifacts excluded from publication. Keep non-page Markdown out of
  `page_dates.py` and `check_generated.py`'s page inventories too.
- `build/`, `cmake-build-*/`, `lib/`, `compile_commands.json`, and `.idea/` may be local
  engine artifacts. They are not documentation sources.

## Verification

Run commands from the repository root. Before finishing any documentation change:

```sh
python3 tools/cvar_audit/validate.py
python3 tools/cvar_audit/check_generated.py
```

For pipeline, generated-content, search, or navigation changes, the complete suite is:

```sh
tools/cvar_audit/run_all.sh --ref origin/master
```

It runs extractor and provenance tests, reference filtering, site search, contents-rail
navigation, Liquid checks, data validation, generated-page validation, and source drift.
Those final two checks cover the minimum documentation checks above; do not run both
sets unnecessarily. Use `--ref <ref>` when deliberately comparing another source ref.

Before handing off a PR, also run the additional checks used by
`.github/workflows/reference-drift.yml`:

```sh
python3 tools/cvar_audit/changelog_coverage.py --ref origin/master
bundle exec jekyll build
```

The Gemfile provides local Jekyll tooling; run `bundle install` if dependencies are
missing. GitHub Pages builds separately, so local output does not prove production
rendering is identical. Preview visible changes with `bundle exec jekyll serve` and
check the affected pages, navigation, search, and redirects. For exclusion changes,
inspect `_site` and its search index to ensure internal files are absent.

Record existing failures before changing behavior. Report any unavailable dependencies
or source refs precisely; do not describe skipped or incomplete checks as passing.
