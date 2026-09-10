---
title: "Console reference"
layout: reference
nav_order: 5
wide: true
reference_app: true
description: "Search and filter every cvar and console command available in TaystJK."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Complete source-derived inventory</p>

<h1>Console reference</h1>

<p class="page-lede">Search 2,014 cvars and commands across the client, dedicated server, game, cgame, UI, platform code, and every renderer backend.</p>
</div>

<section class="reference-catalog" id="catalog" data-reference-app data-mode="all" data-catalog-url="{{ '/assets/data/catalog.json' | relative_url }}" aria-labelledby="catalog-title">
  <div class="catalog-heading">
    <div>
      <p class="section-kicker">Console index</p>
      <h2 id="catalog-title">Find a cvar or command</h2>
    </div>
    <p class="catalog-shortcut"><kbd>/</kbd> to search</p>
  </div>

  <form class="catalog-controls" data-catalog-form role="search">
    <label class="catalog-search">
      <span>Search the reference</span>
      <span class="search-field">
        <svg aria-hidden="true" viewBox="0 0 24 24"><path d="m21 21-4.35-4.35m2.35-5.65a8 8 0 1 1-16 0 8 8 0 0 1 16 0Z"/></svg>
        <input type="search" name="q" data-search autocomplete="off" spellcheck="false" placeholder="Try cg_fov, download, bloom…">
      </span>
    </label>

    <div class="catalog-kind" data-kind-tabs aria-label="Entry type">
      <button type="button" data-kind="all">All</button>
      <button type="button" data-kind="cvar">Cvars</button>
      <button type="button" data-kind="command">Commands</button>
    </div>

    <div class="catalog-filters">
      <div class="filter-dropdown" data-filter-dropdown="origin">
        <button class="filter-toggle" type="button" data-filter-toggle="origin" aria-expanded="false"><span>Origin</span><strong data-filter-summary="origin">Any origin</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="origin" hidden>
          <div class="filter-options" data-filter-options="origin"></div>
          <button class="filter-clear" type="button" data-clear-filter="origin">Clear origin</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="module">
        <button class="filter-toggle" type="button" data-filter-toggle="module" aria-expanded="false"><span>Module</span><strong data-filter-summary="module">Any module</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="module" hidden>
          <div class="filter-options" data-filter-options="module"></div>
          <button class="filter-clear" type="button" data-clear-filter="module">Clear module</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="category">
        <button class="filter-toggle" type="button" data-filter-toggle="category" aria-expanded="false"><span>Topic</span><strong data-filter-summary="category">Any topic</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="category" hidden>
          <div class="filter-options" data-filter-options="category"></div>
          <button class="filter-clear" type="button" data-clear-filter="category">Clear topic</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="feature">
        <button class="filter-toggle" type="button" data-filter-toggle="feature" aria-expanded="false"><span>Feature</span><strong data-filter-summary="feature">Any feature</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="feature" hidden>
          <div class="filter-options" data-filter-options="feature"></div>
          <button class="filter-clear" type="button" data-clear-filter="feature">Clear feature</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="renderer">
        <button class="filter-toggle" type="button" data-filter-toggle="renderer" aria-expanded="false"><span>Renderer</span><strong data-filter-summary="renderer">Any renderer</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="renderer" hidden>
          <div class="filter-options" data-filter-options="renderer">
            <label class="filter-checkbox"><input type="checkbox" name="renderer" value="renderer-specific" data-filter="renderer"><span>Renderer-specific only</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="renderer" value="none" data-filter="renderer"><span>Not renderer-specific</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="renderer">Clear renderer</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="status">
        <button class="filter-toggle" type="button" data-filter-toggle="status" aria-expanded="false"><span>Documentation</span><strong data-filter-summary="status">Any status</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="status" hidden>
          <div class="filter-options">
            <label class="filter-checkbox"><input type="checkbox" name="status" value="documented" data-filter="status"><span>Documented</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="status" value="needs-review" data-filter="status"><span>Needs review</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="status">Clear documentation</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="network">
        <button class="filter-toggle" type="button" data-filter-toggle="network" aria-expanded="false"><span>Network scope</span><strong data-filter-summary="network">Any scope</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="network" hidden>
          <div class="filter-options" data-filter-options="network"></div>
          <button class="filter-clear" type="button" data-clear-filter="network">Clear network scope</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="coverage">
        <button class="filter-toggle" type="button" data-filter-toggle="coverage" aria-expanded="false"><span>In game</span><strong data-filter-summary="coverage">Any coverage</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="coverage" hidden>
          <div class="filter-options">
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="xdocs" data-filter="coverage"><span>Has xdocs entry</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="menu" data-filter="coverage"><span>Has menu entry</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="no-xdocs" data-filter="coverage"><span>Missing from xdocs</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="coverage" value="no-menu" data-filter="coverage"><span>Missing from menus</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="coverage">Clear in-game coverage</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="flag" data-cvar-filter>
        <button class="filter-toggle" type="button" data-filter-toggle="flag" aria-expanded="false"><span>Cvar flag</span><strong data-filter-summary="flag">Any flag</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="flag" hidden>
          <div class="filter-options" data-filter-options="flag"></div>
          <button class="filter-clear" type="button" data-clear-filter="flag">Clear cvar flags</button>
        </div>
      </div>
    </div>

    <div class="catalog-actions">
      <button type="reset" class="button button-quiet" data-reset>Clear filters</button>
      <label class="catalog-sort"><span>Sort</span><select name="sort" data-sort><option value="origin">Origin</option><option value="relevance">Relevance</option><option value="name">Name</option><option value="category">Topic</option><option value="feature">Feature</option><option value="module">Module</option></select></label>
    </div>
  </form>

  <div class="catalog-status" aria-live="polite">
    <p data-result-count>Loading the reference…</p>
    <p class="active-filters" data-active-filters></p>
  </div>
  <div class="catalog-results" data-results aria-busy="true"></div>
  <div class="catalog-empty" data-empty hidden>
    <h3>No matching entries</h3>
    <p>Try a shorter search or clear one of the filters.</p>
  </div>
  <div class="catalog-more"><button type="button" class="button button-secondary" data-load-more hidden>Show more</button></div>
  <noscript><p class="catalog-noscript">JavaScript is required for the interactive index. You can still browse the <a href="{{ '/reference/all/' | relative_url }}">static A–Z index</a> or use the generated JSON files.</p></noscript>
</section>

## How to read an entry

The **topic** is a broad area such as HUD & interface or Movement & race. A **feature** is a narrower family of related controls, such as Killfeed, Movement keys, or Speedometer. The **origin** badge identifies where an entry first appeared, not merely every fork that ships it. Later changes to defaults or flags are listed separately. **Renderer scope** says which current backend registers a cvar, while **network scope** distinguishes local controls from server-owned or negotiated behavior.

The **xdocs** and **menu** badges show whether the current name already has an entry in TaystJK's in-game documentation or shipped menu definitions. Each detail page links the matching source line.

An entry marked **needs review** is real and has registration evidence, but one or more behavior, option, or attribution fields could not be proven precisely enough to present as settled fact.

### More ways to browse

- [Browse by origin](/TaystJK/reference/origins/)
- [Browse by module](/TaystJK/reference/modules/)
- [Browse by topic](/TaystJK/reference/categories/)
- [Browse by feature](/TaystJK/reference/features/)
- [Read the sources and methodology](/TaystJK/reference/sources/)
- [See removed and inactive names](/TaystJK/reference/removed/)
- [Open the audit and review queue](/TaystJK/reference/audit/)
- [Use the static A–Z index](/TaystJK/reference/all/) without JavaScript
- Download the machine-readable [catalog JSON](/TaystJK/assets/data/catalog.json), [full cvars JSON](/TaystJK/assets/data/cvars.json), [full commands JSON](/TaystJK/assets/data/commands.json), [metadata](/TaystJK/assets/data/reference-meta.json), or [JSON Schema](/TaystJK/assets/data/schema.json)
