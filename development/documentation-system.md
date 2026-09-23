---
title: "How this site is built"
layout: reference
parent: "Development"
nav_order: 7
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

**Never edit these by hand.** They are rewritten wholesale:

- `_data/cvars.json`, `_data/commands.json`, `_data/reference-meta.json`,
  `_data/reference_stats.json`, and `_data/page_updated.json` (from `page_dates.py`)
- `reference.md`, `reference/cvars/*.md`, `reference/commands/*.md`
- `reference/{all,audit,sources,removed}.md` and the `reference/categories/`,
  `reference/features/`, `reference/modules/` and `reference/origins/` collections
- `features/whats-new.md`, `features/emoji.md`, and the JSON under `assets/data/`
- `index.md`: the homepage is generated too, which catches people out

Everything else is hand-written: the guides, the Features pages, this page.
`check_generated.py` fails if a generated file has been edited, so a mistake here is caught
rather than silently lost.

Hand-written pages that quote a count from the reference read it from
`_data/reference_stats.json` rather than typing it, so the figure changes when the
reference does.

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

`provenance.py` expects remote-tracking refs for every upstream: `origin/master`,
`openjk/master`, `eternaljk/master`, `japro/main`, `jk2mv/master`, `newjk/master`,
`somaz/rend2-unified-wip`, and `Sunny/master`, plus PR metadata as JSON. `runtime_check.py`
needs console output captured from a client you actually launched.

**The static part is automated; the runtime part is not.** `reference-check.yml` on
`master` fetches every upstream, collects the PR metadata, reruns provenance, reference
assembly and page generation, runs every check and a Jekyll build, and opens or updates a
pull request against `gh-pages`. It runs weekly, when a release is published, and after each
automatic `latest` build. Nothing is pushed to the published branch without review.

It keeps the existing runtime reconciliation rather than redoing it, because no runner
launches the game, and an old `+cvarlist` capture must not be relabelled as current. A
person with a real capture still runs `runtime_check.py` by hand.

Between refreshes, `check_drift.py` compares the registrations at a source ref against the
checked-in data and fails when they diverge. `tools/cvar_audit/README.md` is the full
contract.

A refresh moves the reference to a new source commit, but hand-written guides keep citing
the commit they were checked against. Their blame links stay valid; the prose is only as
current as that check. When you re-verify a guide, re-pin its links to `source_commit`.

## Verifying a change

One script runs everything CI runs, and keeps going after a failure so one run reports
every problem:

```sh
tools/cvar_audit/run_all.sh
```

The site also builds locally, which is the only way to check anything that depends on
rendering, including Liquid templates, the search index, or how Markdown inside an HTML block is
parsed:

```sh
bundle install
bundle exec jekyll build
```

Local Jekyll is 4.x while GitHub Pages runs 3.x, so a local build proves the templates
render rather than being byte-identical to production.

## Adding a page

Create a Markdown file, give it front matter per `CONVENTIONS.md`, and place it in a section.

The header tabs are **hardcoded** in `_layouts/reference.html`; there is no theme. A page joins
a section through its `parent` (the section page's title) and `nav_order`, which give it a
breadcrumb, previous/next links, and the section's highlighted header tab. Also add a card for
it to `_data/navigation.yml`, which draws the Install, Features, Development and Help hubs.
Only a new top-level section means editing the layout. Add hand-written pages to the list in
`check_generated.py` too, or their internal links are never validated.

Everything else is automatic: the page is picked up by the site search through
`search-index.json`, and its headings become linkable anchors.

## What the site is built with

No theme and no plugins. Jekyll renders Markdown through kramdown; the layouts, the CSS and
the two JavaScript files are all local and hand-written. The search index and the Atom feed
are Liquid templates rather than plugins, so they cannot break when an upstream gem changes.
