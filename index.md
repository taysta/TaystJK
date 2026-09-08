---
title: "TaystJK console reference"
layout: reference
nav_order: 1
wide: true
description: "Search every TaystJK cvar and console command, including options, renderer scope, and upstream provenance."
---

<section class="hero">
  <div class="hero-copy">
    <p class="eyebrow">TaystJK technical reference</p>
    <h1>Every console control.<br><span>Traced to its source.</span></h1>
    <p class="hero-lede">Search every cvar and command in TaystJK, see the accepted values, and tell Base JKA, OpenJK, EternalJK, jaPRO, rend2, Vulkan, and other upstream work apart.</p>
    <div class="hero-actions">
      <a class="button button-primary" href="{{ '/reference/' | relative_url }}">Explore 2,014 entries</a>
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
