---
title: "TaystJK — one client for Jedi Academy multiplayer"
layout: reference
nav_order: 1
wide: true
description: "TaystJK is a cross-platform Jedi Academy multiplayer client built for Base JKA, JA+/JA++, jaPRO, and Lugormod servers, with modern performance and quality-of-life improvements."
---

<div class="docs-overview">
  <section class="docs-intro" aria-labelledby="page-title">
    <p class="eyebrow">TaystJK documentation</p>
    <h1 id="page-title">One client for Jedi Academy multiplayer</h1>
    <p class="page-lede">Move between the game's major server communities without giving up a modern, responsive client. TaystJK combines mod-aware compatibility with cross-platform performance and practical quality-of-life improvements.</p>
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

<section class="home-purpose" aria-labelledby="purpose-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Why TaystJK exists</p>
      <h2 id="purpose-heading">Keep the community connected</h2>
    </div>
    <p>Jedi Academy multiplayer is spread across server mods with distinct rules and features. TaystJK is maintained as a dependable everyday client across those communities.</p>
  </div>

  <div class="purpose-principles">
    <article>
      <span>01</span>
      <h3>Compatibility first</h3>
      <p>Detect the server family and adapt prediction, presentation, and client behavior while leaving gameplay authority with the server.</p>
    </article>
    <article>
      <span>02</span>
      <h3>Modern where it matters</h3>
      <p>Maintain fast, stable builds for Windows, Linux, and macOS—including current 64-bit and Apple Silicon systems.</p>
    </article>
    <article>
      <span>03</span>
      <h3>Better to live with</h3>
      <p>Refine the HUD, controls, console, demos, downloads, rendering, and other everyday details without losing the feel of JKA.</p>
    </article>
  </div>

  <p class="project-lineage">TaystJK is a considered assembly of proven work from OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2, the community's Vulkan renderer work, and TaystJK's own contributors. Code brought across project boundaries is ported with permission, credited to its source, and maintained as part of a coherent client rather than a loose collection of patches. <a href="{{ '/reference/sources/' | relative_url }}">See the source lineage.</a></p>
</section>

<section class="home-compatibility" aria-labelledby="compatibility-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">Server compatibility</p>
      <h2 id="compatibility-heading">What each integration covers</h2>
    </div>
    <p>Support is adapted to the information and features each server exposes, so its depth differs by mod.</p>
  </div>

  <div class="compatibility-grid">
    <article class="compatibility-card">
      <div><span class="compatibility-mark">Base</span><h3>Base JKA</h3></div>
      <p>Standard multiplayer with no companion server mod required, augmented by engine fixes, renderer choices, interface controls, and safer networking.</p>
    </article>
    <article class="compatibility-card">
      <div><span class="compatibility-mark">JA+</span><h3>JA+ / JA++</h3></div>
      <p>Server detection and feature-aware handling for the JA+ family: roll variants, flip-kicks, grappling, custom animations, plugin settings, and private-duel isolation.</p>
    </article>
    <article class="compatibility-card compatibility-card-primary">
      <div><span class="compatibility-mark">PRO</span><h3>jaPRO</h3></div>
      <p>The deepest integration: racing and custom movement styles, timing and checkpoint tools, movement analysis, demo workflows, improved prediction, and Tribes mode.</p>
    </article>
    <article class="compatibility-card">
      <div><span class="compatibility-mark">LMD</span><h3>Lugormod</h3></div>
      <p>A dedicated compatibility path for extended jumping and Force Rage, player scaling, Lugormod's custom stat layout, and its command behavior.</p>
    </article>
  </div>

  <p class="compatibility-note"><strong>Client support does not replace the server mod.</strong> The connected server still defines gameplay and determines which mod-specific features are available.</p>
</section>

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
      <span>Installation guide →</span>
    </a>
    <a class="home-guide" href="{{ '/server-hosting/' | relative_url }}">
      <h3>Server administration</h3>
      <p>Dedicated server deployment, map rotation, downloads, and PK3 references.</p>
      <span>Server guide →</span>
    </a>
    <a class="home-guide" href="{{ '/development/' | relative_url }}">
      <h3>Development</h3>
      <p>Build configuration, platform targets, debugging, and dependency details.</p>
      <span>Development guide →</span>
    </a>
    <a class="home-guide" href="{{ '/reference/' | relative_url }}">
      <h3>Console reference</h3>
      <p>Search controls by topic, module, origin, and documentation coverage.</p>
      <span>Browse the reference →</span>
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
