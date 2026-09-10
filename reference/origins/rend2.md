---
title: "rend2"
layout: reference
nav_order: 6
parent: "By origin"
wide: true
reference_app: true
description: "Browse 87 cvars, 3 commands in the TaystJK console reference."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Filtered collection</p>
<h1>rend2</h1>
<p class="page-lede">Entries whose evidence identifies this project as the original source. Later consumers do not change the origin badge. This collection contains 87 cvars, 3 commands.</p>
</div>

<section class="reference-catalog" id="catalog" data-reference-app data-mode="all" data-catalog-url="{{ '/assets/data/catalog.json' | relative_url }}" data-preset-origin="rend2" aria-labelledby="catalog-title">
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
      <label><span>Origin</span><select name="origin" data-filter="origin"><option value="">Any origin</option></select></label>
      <label><span>Module</span><select name="module" data-filter="module"><option value="">Any module</option></select></label>
      <label><span>Topic</span><select name="category" data-filter="category"><option value="">Any topic</option></select></label>
      <label><span>Feature</span><select name="feature" data-filter="feature"><option value="">Any feature</option></select></label>
      <label><span>Renderer</span><select name="renderer" data-filter="renderer"><option value="">Any renderer</option><option value="renderer-specific">Renderer-specific only</option><option value="none">Not renderer-specific</option></select></label>
      <label><span>Documentation</span><select name="status" data-filter="status"><option value="">Any status</option><option value="documented">Documented</option><option value="needs-review">Needs review</option></select></label>
      <label><span>Network scope</span><select name="network" data-filter="network"><option value="">Any scope</option></select></label>
      <label><span>In game</span><select name="coverage" data-filter="coverage"><option value="">Any coverage</option><option value="xdocs">Has xdocs entry</option><option value="menu">Has menu entry</option><option value="no-xdocs">Missing from xdocs</option><option value="no-menu">Missing from menus</option></select></label>
      <label data-cvar-filter><span>Cvar flag</span><select name="flag" data-filter="flag"><option value="">Any flag</option></select></label>
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
