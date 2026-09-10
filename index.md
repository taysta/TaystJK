---
title: "TaystJK documentation"
layout: reference
nav_order: 1
wide: true
description: "Guides and reference material for the TaystJK client, dedicated server, source code, and console controls."
---

<div class="docs-overview">
  <section class="docs-intro" aria-labelledby="page-title">
    <p class="eyebrow">Documentation</p>
    <h1 id="page-title">TaystJK</h1>
    <p class="page-lede">Installation, server administration, development, and console reference for the TaystJK client and dedicated server.</p>
    <nav class="docs-intro-links" aria-label="Project links">
      <a href="{{ '/install/' | relative_url }}">Installation guide</a>
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
      <span>2,014 source-derived cvars and commands</span>
    </a>
  </nav>
</div>

<section class="docs-index" aria-labelledby="docs-heading">
  <h2 id="docs-heading">Documentation</h2>
  <div class="docs-index-list">
    <section class="docs-index-entry">
      <h3><a href="{{ '/install/' | relative_url }}">Installation</a></h3>
      <p>Set up the client on Windows, Linux, or macOS, including separate layouts for multiple modded clients.</p>
    </section>
    <section class="docs-index-entry">
      <h3><a href="{{ '/server-hosting/' | relative_url }}">Server administration</a></h3>
      <p>Deploy the dedicated server, configure map rotation and HTTP downloads, and manage PK3 references.</p>
    </section>
    <section class="docs-index-entry">
      <h3><a href="{{ '/development/' | relative_url }}">Development</a></h3>
      <p>Configure CMake, build the available targets, debug engine and module code, and inspect bundled libraries.</p>
    </section>
    <section class="docs-index-entry">
      <h3><a href="{{ '/reference/' | relative_url }}">Console reference</a></h3>
      <p>Search 1,441 cvars and 573 commands by topic, module, origin, and documentation coverage.</p>
    </section>
  </div>
</section>

<section class="docs-related" aria-labelledby="project-heading">
  <h2 id="project-heading">Project information</h2>
  <ul>
    <li><a href="{{ '/development/libraries/' | relative_url }}">Bundled libraries</a> lists dependency versions and system-library selection rules.</li>
    <li><a href="{{ '/reference/sources/' | relative_url }}">Source provenance</a> explains how reference entries and their code lineage are determined.</li>
    <li><a href="{{ '/ai-disclosure/' | relative_url }}">AI disclosure</a> describes how this documentation was produced and reviewed.</li>
  </ul>
</section>
