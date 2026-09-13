---
title: "How this site is built"
layout: reference
parent: "Development"
description: "The pipeline that generates the console reference from engine source, what each script does, and how to add or change a page."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Developer documentation</p>

# How this site is built

<p class="page-lede">Most of this site is generated from the engine source. The rest is hand-written Markdown. Knowing which is which is the difference between a change that sticks and one that is overwritten.</p>
</div>

The site lives on the `gh-pages` branch; the engine lives on `master`. The pipeline reads
`master` and writes `gh-pages`. Neither branch contains the other.

## Generated or hand-written

**Never edit these by hand** — they are rewritten wholesale:

- `_data/cvars.json`, `_data/commands.json`, `_data/reference-meta.json`
- `reference/cvars/*.md`, `reference/commands/*.md`
- `reference/{all,audit,categories,features,modules,origins,removed}.md`
- `features/whats-new.md`, `features/emoji.md`, `assets/data/catalog.json`
- `index.md` — the homepage is generated too, which catches people out

Everything else is hand-written: the guides, the Features pages, this page.
`check_generated.py` fails if a generated file has been edited, so a mistake here is caught
rather than silently lost.

## The pipeline

Six scripts, each doing one thing, under `tools/cvar_audit/`:

| Script | Does |
|:--|:--|
| `extract.py` | Parses the C and C++ source at a git ref and pulls out every cvar and command registration, keeping file and line. Dependency-free, and tolerant of X-macros. |
| `provenance.py` | Works out which upstream project each entry originated in, by walking the history of every project this fork descends from. Caches under `.cvar-audit/cache`. |
| `build_reference.py` | Assembles `_data/*.json` from the extraction and provenance caches. |
| `runtime_check.py` | Reconciles the data against a real `+cvarlist` / `+cmdlist` capture from a running client. Supplements static extraction; never replaces it. |
| `generate_docs.py` | Renders the Markdown pages and `catalog.json` from `_data/*.json`. |
| `validate.py` | Checks the records against `schema.json`. |

Two data files steer the result by hand: `overrides.json` corrects individual fields where
the source cannot be read correctly, and `removed.json` records entries intentionally
dropped.

### Regenerating

From the repository root, in this order:

```sh
python3 tools/cvar_audit/provenance.py --pr-json <page-1.json> --pr-json <page-2.json>
python3 tools/cvar_audit/build_reference.py
python3 tools/cvar_audit/runtime_check.py --cvars <cvarlist.txt> --commands <cmdlist.txt> --build <BUILD_ID>
python3 tools/cvar_audit/generate_docs.py
```

`provenance.py` expects remote-tracking refs for every upstream — `origin/master`,
`openjk/master`, `eternaljk/master`, `japro/main`, `jk2mv/master`, `newjk/master`,
`somaz/rend2-unified-wip`, `Sunny/master` — and PR metadata as JSON. `runtime_check.py`
needs console output captured from a client you actually launched.

**This is why regeneration is not automated.** No CI runner has eight upstream remotes, your
PR metadata, and a game that can launch. What CI does instead is notice when the result has
gone stale: `check_drift.py` compares the registrations at a source ref against the
checked-in data and fails when they diverge. `tools/cvar_audit/README.md` is the full
contract.

## Verifying a change

One script runs everything CI runs, and keeps going after a failure so one run reports
every problem:

```sh
tools/cvar_audit/run_all.sh
```

The site also builds locally, which is the only way to check anything that depends on
rendering — Liquid templates, the search index, or how Markdown inside an HTML block is
parsed:

```sh
bundle install
bundle exec jekyll build
```

Local Jekyll is 4.x while GitHub Pages runs 3.x, so a local build proves the templates
render rather than being byte-identical to production.

## Adding a page

Create a Markdown file, give it front matter per `CONVENTIONS.md`, and add it to the nav.

The nav is **hardcoded** in `_layouts/reference.html` — there is no theme and nothing reads
`nav_order` — so a new top-level page means editing that file. Add hand-written pages to the
list in `check_generated.py` too, or their internal links are never validated.

Everything else is automatic: the page is picked up by the site search through
`search-index.json`, and its headings become linkable anchors.

## What the site is built with

No theme and no plugins. Jekyll renders Markdown through kramdown; the layouts, the CSS and
the two JavaScript files are all local and hand-written. The search index and the Atom feed
are Liquid templates rather than plugins, so they cannot break when an upstream gem changes.
