# Editing the hand-written pages

A checklist for revising the guides without breaking search, navigation, the generated
reference or the page dates. This file is not published. The rules behind it are in
[CONVENTIONS.md](CONVENTIONS.md); [AGENTS.md](AGENTS.md) covers the reference pipeline.

## Set up once

Work in a `gh-pages` worktree, not the engine checkout:

```sh
git worktree add ../TaystJK-docs gh-pages
cd ../TaystJK-docs
bundle config set --local path vendor/bundle
bundle install
```

## Which files are yours

**Hand-written, edit freely:** `install.md` and `install/`, `server-hosting.md` and
`server-hosting/`, `features.md` and the feature guides, `development.md` and
`development/`, `help.md`, `troubleshooting.md`, `where-to-report.md`, `overview.md`,
`glossary.md`, `licensing.md`, `ai-disclosure.md`, `404.md`, `devlog.md`, and the posts in
`_devlog/`.

**Generated, never edit:** anything with `generated: true` in its front matter. That is
`index.md`, `reference.md`, everything under `reference/`, `features/whats-new.md`,
`features/emoji.md`, and the JSON in `_data/` and `assets/data/`. `check_generated.py`
fails if one of them has been edited by hand.

**The homepage** is generated, but its wording is yours. It lives in
`tools/cvar_audit/generate_docs.py`: change it there, then run
`python3 tools/cvar_audit/generate_docs.py`. Only `index.md` should change.

## What a page is connected to

- **Title.** A child page names its section by the section page's title:
  `parent: "Server hosting"` points at `server-hosting.md`. Renaming a section page means
  updating `parent:` in every page under it, or their breadcrumbs and next/previous links
  break.
- **Description.** It is what search results and link previews show. Section pages also
  show a card for each page, and the card's text is a separate copy in
  `_data/navigation.yml`, so change both.
- **Headings.** Every `##` and `###` becomes a search result and a link target, such as
  `/TaystJK/install/#when-to-use-vm_legacy`. Renaming one breaks links to the old anchor;
  `check_generated.py` reports them.
- **Liquid.** Keep `{% include browse-grid.html section="…" %}` on section pages, and
  `{{ site.data.reference_stats.… }}` wherever a count from the reference appears. Do not
  type those counts by hand.
- **Links.** Internal links are `/TaystJK/…` paths. There are no redirects, so moving or
  renaming a file means updating every link to it; an outside link to the old address
  lands on the 404 page.
- **Source links.** Claims about how the engine behaves link to GitHub blame at a pinned
  commit. If you change one of those claims, check it against the code and pin the link to
  `source_commit` in `_data/reference-meta.json`.
- **Search** is rebuilt from the pages on every build. `search_exclude: true` in the front
  matter keeps a page out of it.
- **The "Last changed" date** is automatic. The deploy workflow works it out from git on
  every push.

## For each page or batch

1. `git pull`
2. Edit.
3. Check: `python3 tools/cvar_audit/validate.py && python3 tools/cvar_audit/check_generated.py`
4. Preview: `bundle exec jekyll serve`, then open <http://localhost:4000/TaystJK/>. To see
   the dates locally, run `python3 tools/cvar_audit/page_dates.py` first.
5. `git commit -am "[docs] …"`
6. `git push origin gh-pages`. "Deploy site" in the Actions tab builds and publishes it,
   and "Console reference drift" reruns every check.

The "Edit this page on GitHub" link works too. It skips steps 3 and 4, but CI still runs
the checks and the date still updates.

## Adding, moving or removing a page

- **New page:** front matter as in CONVENTIONS.md §1 (`title`, `layout`, `description`,
  `parent`, `nav_order`, `toc`), and a card for it in `_data/navigation.yml`. A new file at
  the top level, outside the existing section folders, also needs adding to the `pages`
  list in `tools/cvar_audit/check_generated.py`, or its links are never checked.
- **New section:** the header tabs are written out in `_layouts/reference.html`.
- **Moving or removing:** update every link to it. `check_generated.py` finds the internal
  ones.

## Devlog

A post is one file in `_devlog/`, named `YYYY-MM-DD-short-slug.md`, with `title`, `date`,
`author` and `description` in its front matter and no `layout` or H1. See CONVENTIONS.md
§6a.

## As the pages become yours

`ai-disclosure.md` says how the pages were written. Update it as you rewrite them.
