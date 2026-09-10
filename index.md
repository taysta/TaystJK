---
title: "TaystJK documentation"
layout: reference
nav_order: 1
wide: true
description: "Guides and reference material for the TaystJK client, dedicated server, source code, and console controls."
---

<div class="docs-overview">
  <section class="docs-intro" aria-labelledby="page-title">
    <p class="eyebrow">TaystJK</p>
    <h1 id="page-title">Documentation</h1>
    <p class="page-lede">Setup and reference material for players, server administrators, and contributors.</p>
    <nav class="docs-intro-links" aria-label="Project links">
      <a href="{{ '/install/' | relative_url }}">Installation</a>
      <a href="https://github.com/taysta/TaystJK/releases/tag/latest">Latest release</a>
      <a href="https://github.com/taysta/TaystJK">Source repository</a>
    </nav>
  </section>

  <nav class="docs-quick-links" aria-labelledby="quick-links-heading">
    <h2 id="quick-links-heading">Quick links</h2>
    <a href="{{ '/server-hosting/' | relative_url }}">
      <strong>Run a server</strong>
      <span>Docker Compose, server.cfg, downloads, and reflists</span>
    </a>
    <a href="{{ '/development/' | relative_url }}">
      <strong>Work on TaystJK</strong>
      <span>Compilation, debugging, and bundled libraries</span>
    </a>
    <a href="{{ '/reference/' | relative_url }}">
      <strong>Find a console control</strong>
      <span>1,441 cvars and 573 commands derived from source</span>
    </a>
  </nav>
</div>

<section class="home-guides" aria-labelledby="guides-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Guides and reference</p>
      <h2 id="guides-heading">Browse the documentation</h2>
    </div>
    <p>Use the task guides for setup and maintenance, or search the source-derived console reference.</p>
  </div>

  <div class="home-guide-grid">
    <a class="home-guide" href="{{ '/install/' | relative_url }}">
      <h3>Installation</h3>
      <p>Client setup, game files, clean directory layouts, and first launch.</p>
      <span>Windows · Linux · macOS</span>
    </a>
    <a class="home-guide" href="{{ '/server-hosting/' | relative_url }}">
      <h3>Server administration</h3>
      <p>Dedicated server deployment, map rotation, downloads, and PK3 references.</p>
      <span>Docker · server.cfg · reflists</span>
    </a>
    <a class="home-guide" href="{{ '/development/' | relative_url }}">
      <h3>Development</h3>
      <p>Build configuration, platform targets, debugging, and dependency details.</p>
      <span>CMake · debugging · libraries</span>
    </a>
    <a class="home-guide" href="{{ '/reference/' | relative_url }}">
      <h3>Console reference</h3>
      <p>Search controls by topic, module, origin, and documentation coverage.</p>
      <span>1,441 cvars · 573 commands</span>
    </a>
  </div>
</section>

<section class="home-resources" aria-labelledby="resources-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Project details</p>
      <h2 id="resources-heading">Technical information</h2>
    </div>
  </div>
  <div class="home-resource-list">
    <a href="{{ '/development/libraries/' | relative_url }}">
      <strong>Bundled libraries</strong>
      <span>Dependency versions and system-library selection rules.</span>
    </a>
    <a href="{{ '/reference/sources/' | relative_url }}">
      <strong>Source provenance</strong>
      <span>How reference entries and code lineage are determined.</span>
    </a>
    <a href="{{ '/ai-disclosure/' | relative_url }}">
      <strong>AI disclosure</strong>
      <span>How this documentation was produced and reviewed.</span>
    </a>
  </div>
</section>
