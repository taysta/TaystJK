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
| `nav_order` | integer | top-level pages | Top nav order: index 1, install 2, server-hosting 3, development 4, reference 5. |
| `wide` | bool | no | `true` opts into the wider content column (`--wide`, 1180px). Used by index, development, reference. |
| `reference_app` | bool | no | `reference.md` only. Adds `has-reference-app` to `<body>` and mounts the search app. |
| `parent` | string | child pages | Just-the-Docs parent title. |
| `nav_exclude` | bool | no | Keeps a page out of navigation. Also drives the reference breadcrumb in the layout. |

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
- `nav_order` — the top nav is hand-ordered, not alphabetical.
- `wide` — opt-in, because prose reads badly at 1180px but tables and grids need it.
- `reference_app` — loads a search app that only one page uses.
- `parent` / `nav_exclude` — placement and suppression in the sidebar.
- `origin` — lets a hand-written feature page be grouped into the same baseline buckets as
  reference entries, so non-cvar features are not invisible.
- `status` — marks a feature that a reader should not assume is finished or supported.
- `added_on` — the only way to express availability, because there are no version tags.

## 2. `added_on`

TaystJK has no version tags. Releases are rolling under a single `latest` tag and builds
identify themselves as `latest-<shorthash>` with a build date. Feature availability is
therefore a date plus a commit, never "added in vX.Y".

Format: `YYYY-MM-DD (shorthash)` — for example `2025-03-14 (a1b2c3d)`.

The date is what a reader compares against. Tell readers to compare the build date printed
by `version` / `modversion` against the date shown: an older build date means the feature
is absent. Comparing short hashes alone tells them nothing about ordering.

State that comparison rule once on the overview page and link to it from wherever
`added_on` renders, rather than repeating it per page. The overview page does not exist
yet; until it does, link to nothing and keep the rule in this file.

## 3. Headings

- One `#` H1 per page, inside the `page-heading` block described in §5.
- Sections are `##`. Subsections are `###`.
- Do not go deeper than `###`. If you need `####`, the page wants splitting.
- Sentence case, not Title Case: "Install for your platform", not "Install For Your Platform".
- Headings are anchor targets (`heading_anchors: true`), so do not reword one that another
  page links to without updating the link.

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

## 9. Redirects

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

> **TODO — destinations are placeholders.** Every retired URL currently points at
> `/TaystJK/features/`, which **does not exist yet**. Revisit this table once the Features
> section is built, and point each URL at the most specific page: shader-override and
> keybind content to `features/client-behaviour.md`, the Vulkan stub to
> `features/renderers.md`, and the `cvars/` and `commands/` URLs to the feature page that
> covers each topic. Until then these stubs redirect to a 404.

| Retired URL | Destination |
|:--|:--|
| `/TaystJK/hardcoded-changes/` | `/TaystJK/features/` |
| `/TaystJK/cvars/crosshair/` | `/TaystJK/features/` |
| `/TaystJK/cvars/demos/` | `/TaystJK/features/` |
| `/TaystJK/cvars/hud/` | `/TaystJK/features/` |
| `/TaystJK/cvars/miscellanous/` | `/TaystJK/features/` |
| `/TaystJK/cvars/sound/` | `/TaystJK/features/` |
| `/TaystJK/cvars/strafe/` | `/TaystJK/features/` |
| `/TaystJK/commands/miscellaneous/` | `/TaystJK/features/` |
| `/TaystJK/commands/strafe/` | `/TaystJK/features/` |

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

## 10. Verification

Before finishing any documentation change:

```sh
python3 tools/cvar_audit/validate.py
python3 tools/cvar_audit/check_generated.py
```

There is no local Jekyll build (no `Gemfile`, no jekyll gem installed); the site is built
by GitHub Pages. `check_generated.py` is the local proxy — it validates the generated
pages and every internal `/TaystJK/` link.
