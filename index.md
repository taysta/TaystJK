---
title: "TaystJK console reference"
layout: reference
nav_order: 1
wide: true
reference_app: true
description: "Search every TaystJK cvar and console command, including options, renderer scope, and upstream provenance."
---

<section class="hero">
  <div class="hero-copy">
    <p class="eyebrow">TaystJK technical reference</p>
    <h1>Every console control.<br><span>Traced to its source.</span></h1>
    <p class="hero-lede">Search every cvar and command in TaystJK, see the accepted values, and tell Base JKA, OpenJK, EternalJK, jaPRO, rend2, Vulkan, and other upstream work apart.</p>
    <div class="hero-actions">
      <a class="button button-primary" href="#catalog">Search 2,014 entries</a>
      <a class="button button-secondary" href="{{ '/reference/sources/' | relative_url }}">How attribution works</a>
    </div>
  </div>
  <div class="hero-terminal" aria-label="Example console lookup">
    <div class="terminal-bar"><span></span><span></span><span></span><b>console reference</b></div>
    <div class="terminal-body">
      <p><span class="terminal-prompt">›</span> <strong>r_dynamicGlowBloom</strong></p>
      <p class="terminal-muted">Dynamic-glow bloom strength · default <code>0.0</code></p>
      <p><span class="mini-origin ref-origin-rend2">rend2</span> <span class="terminal-scope">rd-rend2</span></p>
      <hr>
      <p><span class="terminal-prompt">›</span> <strong>cg_cameraFPS</strong></p>
      <p class="terminal-muted">Frame-independent third-person camera damping</p>
      <p><span class="mini-origin ref-origin-jk2mv">JK2MV</span> <code>&lt;15</code> legacy · <code>≥15</code> adjusted</p>
    </div>
  </div>
</section>

<section class="reference-stats" aria-label="Reference coverage">
  <div><strong>1,441</strong><span>cvars</span></div>
  <div><strong>573</strong><span>commands</span></div>
  <div><strong>9</strong><span>source lineages</span></div>
  <div><strong>4</strong><span>renderer targets</span></div>
</section>

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
      <label><span>Origin</span><select name="origin" data-filter="origin"><option value="">Any origin</option></select></label>
      <label><span>Module</span><select name="module" data-filter="module"><option value="">Any module</option></select></label>
      <label><span>Renderer</span><select name="renderer" data-filter="renderer"><option value="">Any renderer</option><option value="renderer-specific">Renderer-specific only</option><option value="none">Not renderer-specific</option></select></label>
      <label><span>Documentation</span><select name="status" data-filter="status"><option value="">Any status</option><option value="documented">Documented</option><option value="needs-review">Needs review</option></select></label>
      <label><span>Network scope</span><select name="network" data-filter="network"><option value="">Any scope</option></select></label>
      <label data-cvar-filter><span>Cvar flag</span><select name="flag" data-filter="flag"><option value="">Any flag</option></select></label>
    </div>

    <div class="catalog-actions">
      <button type="reset" class="button button-quiet" data-reset>Clear filters</button>
      <label class="catalog-sort"><span>Sort</span><select name="sort" data-sort><option value="relevance">Relevance</option><option value="name">Name</option><option value="origin">Origin</option><option value="module">Module</option></select></label>
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

<section class="browse-section">
  <div class="section-heading">
    <div><p class="section-kicker">Browse with context</p><h2>Start from what you know</h2></div>
    <p>Each entry keeps its current behavior separate from where the feature originated.</p>
  </div>
  <div class="browse-grid">
    <a class="browse-card" href="{{ '/cvars/' | relative_url }}"><span class="browse-icon">c_</span><h3>Cvars</h3><p>Defaults, accepted values, flags, ranges, restart behavior, and network scope.</p><b>Browse 1,441 →</b></a>
    <a class="browse-card" href="{{ '/commands/' | relative_url }}"><span class="browse-icon">&gt;_</span><h3>Commands</h3><p>Syntax, arguments, handlers, cheat protection, and server-side gating.</p><b>Browse 573 →</b></a>
    <a class="browse-card" href="{{ '/reference/renderers/' | relative_url }}"><span class="browse-icon">◈</span><h3>Renderer scope</h3><p>Compare vanilla, rend2, Vulkan, and dedicated renderer registrations.</p><b>Compare renderers →</b></a>
    <a class="browse-card" href="{{ '/reference/origins/' | relative_url }}"><span class="browse-icon">↗</span><h3>Provenance</h3><p>Separate Base JKA and upstream work from TaystJK-specific additions.</p><b>Browse origins →</b></a>
  </div>
</section>

<section class="method-banner">
  <div><p class="section-kicker">Evidence, not guesswork</p><h2>Source registrations, history, PRs, and upstream trees.</h2></div>
  <p>The inventory combines static extraction with a runtime reconciliation. Squashed pull requests are traced through their retained commit bullets and PR descriptions; uncertain semantics stay visibly marked for review.</p>
  <a class="text-link" href="{{ '/reference/sources/' | relative_url }}">Read the methodology →</a>
</section>
