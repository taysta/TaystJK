# Documentation conventions

Rules every hand-written page on this branch follows, so pages do not diverge in front
matter, tone, or badge usage. This file is excluded from the built site.

The generated console reference does not follow this document — it is produced by
`tools/cvar_audit/generate_docs.py` and its conventions live in
`tools/cvar_audit/README.md`. Never hand-edit anything under `_data/`,
`reference/cvars/`, `reference/commands/`, or the generated pages under `reference/`.

---

## 1. Front matter

### Fields already in use

| Field | Type | Required | Notes |
|:--|:--|:--|:--|
| `title` | string | yes | Quoted. Non-ASCII is escaped, e.g. `"TaystJK — one client"`. Appears in `<title>` as `{title} · TaystJK`. |
| `layout` | string | yes | Always `reference`. `_config.yml` defaults supply it, but every page sets it explicitly. |
| `description` | string | yes | One sentence. Drives `<meta name="description">`, listing cards, and search previews. |
| `nav_order` | integer | no | Orders previous/next links among pages with the same `parent`. The top nav is hardcoded in `_layouts/reference.html`; add a page there. |
| `toc` | bool | no | Adds the collapsible "On this page" rail. See §3a for when a page wants one. |
| `wide` | bool | no | `true` opts into the wider content column (`--wide`, 1180px). Used by index, development, reference. |
| `reference_app` | bool | no | `reference.md` only. Adds `has-reference-app` to `<body>` and mounts the search app. |
| `parent` | string | no | Parent page title for breadcrumbs and, with `nav_order`, section previous/next links. |
| `nav_exclude` | bool | no | No longer affects navigation. The layout reuses it to decide whether to draw the reference breadcrumb. |
| `search_exclude` | bool | no | Keeps a page out of `/search-index.json`, and so out of the header search. |

`has_children` and anchor-target `permalink` appear only on the legacy orphaned pages
(`hardcoded-changes.md` and its child stubs). Do not use them on new pages.

### New optional fields

| Field | Values | Purpose |
|:--|:--|:--|
| `origin` | `basejka`, `openjk`, `japro`, `eternaljk`, `newjk`, `jk2mv`, `rend2`, `vulkan`, `taystjk` | Where the documented feature first appeared. Same vocabulary as `origin.source` in the reference data, so a page and a cvar entry can be grouped the same way. |
| `status` | `stable`, `experimental`, `deprecated` | Maturity of the documented feature. `stable` is the assumed default and renders no badge. |
| `added_on` | `YYYY-MM-DD (shorthash)` | When the feature landed. See §2. |

Rationale, one line each:

- `title` — the page name in the tab, the card, and search results.
- `layout` — explicit so a page never silently depends on a `defaults` change.
- `description` — the only summary the card grid and meta tags have; a page without one
  renders a blank card.
- `nav_order` — orders child pages within a section; the top nav is hand-ordered separately.
- `wide` — opt-in, because prose reads badly at 1180px but tables and grids need it.
- `reference_app` — loads a search app that only one page uses.
- `parent` — breadcrumbs and section sequencing; `nav_exclude` controls the reference breadcrumb fallback.
- `origin` — supplies the default baseline grouping for a hand-written feature page,
  so non-cvar features are not invisible; confirm the comparison when adding the page.
- `status` — marks a feature that a reader should not assume is finished or supported.
- `added_on` — the only way to express availability, because there are no version tags.

## 2. `added_on`

TaystJK has no release versioning. Releases are rolling: the `latest` tag is moved onto
each release commit, so a build identifies itself as `latest-<shorthash>` plus a compile
date, and availability is a date, never "added in vX.Y".

Format: `YYYY-MM-DD (shorthash)` — for example `2025-03-14 (a1b2c3d)`.

`version` ends with the engine's compile date (`SOURCE_DATE`, `codemp/qcommon/common.cpp`),
and `modversion` prints the game module's compile date and time followed by the
`GIT_TAG-GIT_HASH` pair (`CG_ModVersion_f`). `CMakeLists.txt` fills those from
`git describe --tags --abbrev=0` and `git rev-parse --short`, and because `latest` sits on
the release commit, describe resolves to `latest`.

Tell readers to compare **the date**; an older build does not have the entry. The hash does
not order builds — two short hashes cannot be ranked against each other — and the tag is
the same string on every release, so neither half of the identifier answers "is mine
newer". The semver-looking tags in the repository (`1.0` … `1.5.5`) are inherited from the
fork's ancestry and are not TaystJK releases.

State that comparison rule once and link to it from wherever `added_on` renders, rather
than repeating it per page. For generated entries that explanation lives on
`whats-new.md` under "How to tell what your build has"; move it to the overview page when
Phase 3 creates one.

### Which date, for generated entries

The reference derives `added_on` from `origin.first_commit` using that commit's
**committer** date, not its author date. The two answer different questions:

- *Attribution* — who had it first — is resolved in `provenance.py` across the upstream
  repositories, and ranks on author and PR dates so that work authored upstream keeps its
  credit even when TaystJK merged it first. Do not change that.
- *Availability* — is it in my build — is a question about this repository only.
  `first_commit` is always an ancestor of `origin/master`, and its committer date is when
  the change entered that history. An author date can be earlier and would claim a feature
  was available before TaystJK had it.

Nine of the 204 cited commits differ between the two dates, by one to fourteen days. The
largest blast radius is the original Raven source import, authored 2013-04-04 and committed
2013-04-08, which 1,043 entries date from.

A date is marked *needs review* when `origin.confidence` is `medium`: it is only as firm as
the attribution it rests on. A date is omitted entirely when the origin has no resolvable
first commit — never invented.

## 3. Headings

- One `#` H1 per page, inside the `page-heading` block described in §5.
- Sections are `##`. Subsections are `###`.
- Do not go deeper than `###`. If you need `####`, the page wants splitting.
- Sentence case, not Title Case: "Install for your platform", not "Install For Your Platform".
- Kramdown gives every heading a stable id, and `site-search.js` adds a hover anchor to
  `h2`–`h4`, so every section is linkable. Do not reword a heading another page links to
  without updating the link.

## 3a. When a page gets the contents rail

`toc: true` adds the collapsible rail down the left. **Any page that scrolls and has more
than one heading should have it.** In practice that is nearly every page with content; set
it and move on.

The rail suppresses itself below two headings, so `toc: true` on a short page is inert
rather than broken, and there is no need to count first.

Three things are left out of the rail automatically:

- Headings inside a tab panel, because only one panel is visible at a time and a link into
  a hidden one goes nowhere the reader can see. The tab strip is the navigation there.
- Headings marked `data-toc-skip`, for captions that label furniture rather than a section —
  the homepage's "Quick links" sidebar heading is the case this exists for.
- Nothing else. Earlier revisions of this file tried to judge which pages "deserved" a rail
  by section count and then by whether a page was read or navigated. Both produced results
  that could not be defended, so the rule is now the simple one.

The exception worth stating: `reference/all.md` has no rail despite qualifying. It is the
no-JavaScript index, and the rail is built by JavaScript — it would never appear for the
readers that page exists for.

## 3b. What the layout adds on every page

Written once, so pages do not reimplement them:

- **Heading anchors** on `h2`–`h4`, and the contents rail where `toc: true` is set (§3a).
- **A copy button on every code block**, added by JS. Nothing in the Markdown is needed.
- **Syntax highlighting** for fenced blocks with a language tag, which is why §4 requires
  one — an untagged fence renders flat.
- **Search**, which reads `search-index.json`; opt a page out with `search_exclude`.
- **An "Edit this page on GitHub" link**, on hand-written pages only. The generator stamps
  `generated: true`, and the layout hides the link on those — editing a generated page is
  work the next pipeline run throws away.
- **Print styles**, which drop the chrome and invert the palette, since the dark theme
  prints as a solid black page.
- **A breadcrumb** on any page with a `parent`, linking back to the section index.
- **Previous/next links** across a section, ordered by `parent` + `nav_order`. Those two
  fields were inert after the theme was removed; this gives them a job again, so a new
  child page needs both or it drops out of the sequence.
- **A "Last changed" date and a History link**, from `_data/page_updated.json`. Refresh it
  with `python3 tools/cvar_audit/page_dates.py`; it lags by one commit, which is fine for
  judging a page's age, and the History link is exact when precision matters.
- **Light and dark themes.** Every colour resolves from a token in `:root`, and tints are
  `color-mix()` on those tokens, so a theme is a second set of values rather than a second
  stylesheet. Do not add a raw colour to a rule — add a token. Both themes are checked to
  meet WCAG AA for body text, links and headings.

## 4. Code fences

Every fence carries a language tag. Tags in use:

- `text` — directory trees, file listings, console output, anything not a real language.
- `sh` — shell commands.
- `yaml`, `json`, `cpp` — as applicable.

Console commands and cvar names in prose go in single backticks: `cg_killfeed`, not bold
or quoted.

## 5. Page structure and prose

Every guide page opens with the same heading block:

```text
<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Install TaystJK

<p class="page-lede">One or two sentences framing the page.</p>
</div>
```

- `eyebrow` is a short audience or role label — "Player guide", "Administrator guide".
- `page-lede` is the opening sentence, set larger than body text.
- `markdown="1"` is required on the wrapper or the Markdown inside will not render.

Prose style, matching `install.md` and `server-hosting.md`:

- Direct and second person for instructions: "You need a legal Jedi Academy installation",
  "Choose your operating system", "Start with a small, private server".
- No marketing language. Describe what the software does, not how good it is.
- Prefer the concrete: name the file, the port, the cvar, the directory.
- State constraints as constraints ("do not copy only the executable, because …") and give
  the reason.
- Do not restate a cvar table the generated reference already produces. Link to the entry.

## 6. Source links

Every factual claim about behaviour links to its source, using a GitHub **blame** link
pinned to a commit — not `blob`, and never an unpinned branch link:

```text
https://github.com/taysta/TaystJK/blame/<full-commit-sha>/<path>#L<line>
```

Pin to the commit the reference was generated from. That value is `source_commit` in
`_data/reference-meta.json`; it is currently `6ff04c0baf588a89e5ec9361ad7a0992941d7655`,
and the existing guides already use it. Blame links survive later edits to the file in a
way that line-numbered `blob` links on a moving branch do not.

If you cannot verify a claim against source, write a visible `TODO` rather than a
plausible sentence.

### Link to a heading, not to a page

Every `h2`, `h3` and `h4` gets a hover anchor, and kramdown gives each one a stable id from
its text. When you cross-reference a specific point, link the section rather than the page:
`/TaystJK/install/#when-to-use-vm_legacy`, not `/TaystJK/install/`.

Renaming a heading changes its id and silently breaks inbound links. If you rename one that
other pages point at, update them — `check_generated.py` validates internal links, so run it
after.

### `master`'s `docs/` folder is a source to cite, not a copy to mirror

The source branch carries a `docs/` folder. Most of it did not originate here —
`japro_docs.md` and `Defrag Mapping Guide.md` arrived with a jaPRO update and are jaPRO's
own documentation, carried downstream alongside the gamecode.

This site is the documentation. Those files are **reference material to cite**, the same way
any upstream source is cited:

- Link to a file when it is the authority on something, as the movement styles page does for
  the mapping guide. Say whose account it is, since it is not this project's.
- Do not copy it here, and do not treat it as canonical. It changes when upstream changes,
  on someone else's schedule.
- Do not write a drift check against it. Divergence is expected, not a defect.

Where a page leans on one of these files, attribute it. "jaPRO's own guide" is accurate;
"the maintainer's account" is not.

### Do not cite issue or PR numbers

The tracker is the live record of what is broken and what was fixed; these pages are not a
mirror of it. A wiki page that says "#343 is fixed in #367" is stale the moment either
changes, and an open issue named here is a promise the page cannot keep.

Read the tracker freely — it is the best guide to which problems actually recur, and which
ones are worth a page at all. Then write the problem, not the report: the symptom a reader
would recognise, the cause, and what to do about it, in terms that stay true after the
issue is closed. A fault that is fixed does not need its history retold; "update your build
first" carries the whole of it.

Linking <https://github.com/taysta/TaystJK/issues> as somewhere to *file* a report is fine.
Citing individual numbers is not.

## 6a. Devlog posts

A post is one file in `_devlog/`. Nothing else needs editing — the index, the Atom feed and
the site search all read the collection, so a new file appears in all three on the next
build.

Name it `YYYY-MM-DD-short-slug.md`. The filename is the URL, so the date shows there too;
that is deliberate, because a devlog entry is a dated thing and the URL should say when.

```yaml
---
title: "A console reference generated from source"
date: 2026-09-13
author: tayst
description: "One sentence. Shown on the index, in the feed, and under the post title."
---
```

`date` is required — it orders the index and the feed, and it is what the feed's `updated`
timestamp comes from. `author` and `description` are optional but worth writing; without a
description the index entry is a bare title.

Do not add a `layout` or an H1. The layout supplies both, including the heading block, so a
post starts at its first `##`.

Posts follow the same heading, code fence and link rules as every other page. They are not
exempt from §6 either: write what changed and why, not which issue number it was.

## 7. Terminology

Use these consistently.

| Term | Means |
|:--|:--|
| **client** | The TaystJK executable a player runs. |
| **engine** | The shared platform layer: filesystem, network, console, renderer backends. In the reference these are the `engine-client`, `engine-server`, `engine-shared`, and `renderer` modules. |
| **module** | The game code loaded per mod: `game`, `cgame`, `ui`. Use "game module" when distinguishing from the engine. |
| **base directory** | `GameData/base`, holding the retail `assets0`–`assets3` pk3s. |
| **mod directory** | A sibling directory under `GameData` selected by `fs_game`. |
| `fs_game` | Selects the mod directory. Server-settable. |
| `fs_forcegame` | Client-side override of `fs_game`; cannot be set by the server. |
| **origin** | Where an entry or feature *first appeared* — not every fork that ships it. |

Write "Jedi Academy" in full on first use per page; "JKA" afterwards is fine.

## 8. Badges

`status: experimental` and `status: deprecated` render a chip above the page heading. The
chip reuses the existing chip styling in `assets/css/reference.css` — the same base rules
as `.status-chip`, `.meta-chip`, and the origin labels. `stable` renders nothing, because
stable is the assumed default and a badge on every page carries no information.

Do not introduce new colours. The palette is the custom properties on `:root`
(`--warning`, `--danger`, `--accent`, `--violet`, …).

The `needs review`, `xdocs`, and `menu` badges belong to the generated reference and are
emitted by `generate_docs.py`. Do not hand-write them onto guide pages.

## 9. The what's-new page

`features/whats-new.md` is generated. Do not edit it. It lists what TaystJK adds relative to the
client a reader is coming from, with a three-way baseline toggle, and it is built from two
sources: the reference data, and the editorial layer in
`tools/cvar_audit/whats-new-overrides.json`.

### Tuning a generated row

Rows for cvars and commands come from the reference data. To change how one is presented,
add it to the `entries` object by its exact name:

```json
"entries": {
  "cg_killfeed": { "promote": 1, "summary": "Shorter wording for this page." },
  "r_dither":    { "hide": true },
  "cl_filterGames": { "group": "Server & networking" }
}
```

| Key | Effect |
|:--|:--|
| `promote` | Integer rank. Lower sorts earlier within the topic; unranked rows follow alphabetically. |
| `summary` | Replaces the generated summary on this page only. The detail page is unaffected. |
| `group` | Puts the row under a different topic heading. |
| `hide` | Drops the row from this page. |

`hide` is editorial, never deletion. A hidden entry keeps its detail page, stays in the
reference and the search index, and is listed on the [audit page](reference/audit.md) under
"Hidden from the what's-new page", so nothing disappears without a record.

A name that no longer exists is a **hard error** in both `validate.py` and generation, so
the file cannot rot silently when a cvar is renamed. Fix or delete the override.

### Adding a feature that is not cvar-shaped

Some of the most significant additions have no cvar: `.oshader` overrides, the cosmetics
offsets format, modifier binds. They reach the page one of two ways.

**Once the page documenting it exists**, the page declares itself in front matter, and
nothing else needs editing:

```yaml
whats_new: true
origin: taystjk
added_on: "2025-03-14 (a1b2c3d)"
title: "Cosmetics custom offsets"
description: "One sentence; this becomes the row's summary."
```

For these handwritten features, `origin` supplies the default baseline grouping; confirm
that the feature is absent from the clients it is compared against. Generated cvars and
commands instead compare registrations independently against each upstream snapshot,
recorded in `_data/reference-meta.json`; origin attribution does not decide membership.
An origin of `basejka` is rejected — it is not new against any baseline.

**Before that page exists**, seed it in the `features` array instead:

```json
{
  "title": "Cosmetics custom offsets",
  "origin": "taystjk",
  "group": "Gameplay & combat",
  "summary": "One sentence.",
  "page": "/TaystJK/features/cosmetics/"
}
```

The build **warns** about a destination that does not resolve yet; it does not fail. When
the page is written and declares `whats_new: true`, it supersedes the seed by title —
delete the seed entry then.

Seed summaries are provisional. Verify them against source when writing the page, the same
as any other factual claim (§6).

### Adding a seventh feature

1. Decide the origin, and confirm the mapping puts it in the baseline you expect.
2. If the page exists, add the four front-matter fields to it and regenerate — done.
3. If it does not, add an object to `features` with a `page` pointing where it will live.
4. Run `python3 tools/cvar_audit/generate_docs.py` and read the warnings.
5. Run `python3 tools/cvar_audit/validate.py` and
   `python3 tools/cvar_audit/check_generated.py`.

## 10. Redirects

Three page trees left over from an older Just-the-Docs structure were retired: they were
unreachable from the navigation, their content had gone stale (the
`cg_drawTeamOverlay 3` / `4` description predated the overlay overhaul), and the
`hardcoded-changes/` children were front-matter-only stubs whose `permalink` pointed at
anchors on their own parent.

The prose of `hardcoded-changes.md` is preserved verbatim at
`.migration/hardcoded-changes-original.md`; the retired trees are preserved at
`.migration/orphaned-trees/`. `.migration/` is a scratch directory, not part of the site —
Jekyll ignores dot-directories.

**Approach: hand-written meta-refresh stubs, no plugin.** A redirect on GitHub Pages needs
a file at the old path — Pages serves static files and has no server-side redirect
configuration. `jekyll-redirect-from` is on the GitHub Pages allowed-plugin list, but it
does not help here: its `redirect_from` form puts the mapping on the *destination* page,
and the destination does not exist yet, while its `redirect_to` form generates exactly the
same stub file we would write by hand. That left a new build-time dependency, on a site
with no local Jekyll build to catch a misconfiguration, in exchange for nothing. If the
Features section later makes `redirect_from` natural, revisit this.

Destinations point at the Features page that covers each topic. Two entries route to the
console reference instead, because no feature page covers demos or sound.

| Retired URL | Destination |
|:--|:--|
| `/TaystJK/hardcoded-changes/` | `/TaystJK/features/client-behaviour/` |
| `/TaystJK/cvars/crosshair/` | `/TaystJK/features/hud-and-movement/` |
| `/TaystJK/cvars/hud/` | `/TaystJK/features/hud-and-movement/` |
| `/TaystJK/cvars/strafe/` | `/TaystJK/features/hud-and-movement/` |
| `/TaystJK/commands/strafe/` | `/TaystJK/features/hud-and-movement/` |
| `/TaystJK/cvars/demos/` | `/TaystJK/reference/` |
| `/TaystJK/cvars/sound/` | `/TaystJK/reference/` |
| `/TaystJK/cvars/miscellanous/` | `/TaystJK/reference/` |
| `/TaystJK/commands/miscellaneous/` | `/TaystJK/reference/` |
| `/TaystJK/whats-new/` | `/TaystJK/features/whats-new/` |
| `/TaystJK/emoji/` | `/TaystJK/features/emoji/` |

The last two are not retired content: both pages are generated, and moved into the Features
section when it was built. The old URLs were published in the interim, so they redirect.

`/TaystJK/cvars/miscellanous/` keeps the original misspelling, because that is the URL
that was published.

The retired child pages carried `permalink` values containing a `#`, such as
`/cvars/strafe#speedometer` and `/hardcoded-changes#vulkan`. Those are not separately
retrievable URLs — a browser reads everything after `#` as a fragment and requests the
parent path — so the parent stub above covers them. They needed no stub of their own. The
full list of retired anchor permalinks, for reference:

```text
/commands/miscellaneous#delay          /cvars/crosshair#crosshair-scope
/commands/miscellaneous#delay-cancel   /cvars/hud#hud-updates
/commands/miscellaneous#if-cvar        /cvars/hud#movement-keys
/commands/miscellaneous#music-controls /cvars/hud#pitch-helper
/commands/miscellaneous#string-substitution
/commands/miscellaneous#wait-freely    /cvars/sound#ambient-sounds
/commands/miscellaneous#wait-freely-cancel
                                       /cvars/strafe#race-timer
/hardcoded-changes#keybinds--commands  /cvars/strafe#speedometer
/hardcoded-changes#miscellaneous       /cvars/strafe#strafe-helper
/hardcoded-changes#shader-overrides    /cvars/strafe#trigger-slick-clip-rendering
/hardcoded-changes#vulkan
```

A stub is a `layout: none` page whose only job is to hold a URL. Build the target with the
`relative_url` filter rather than hardcoding `/TaystJK`, so the baseurl stays in one place.

## 11. Verification

Before finishing any documentation change:

```sh
python3 tools/cvar_audit/validate.py
python3 tools/cvar_audit/check_generated.py
```

The `Gemfile` provides a local Jekyll build: run `bundle install` if dependencies are
missing, then `bundle exec jekyll build`. GitHub Pages builds the published site
separately. `check_generated.py` validates generated pages and internal `/TaystJK/`
links. See [AGENTS.md](AGENTS.md#verification) for the complete suite and PR checks.
