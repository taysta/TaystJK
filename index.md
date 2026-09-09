---
title: "TaystJK documentation"
layout: reference
nav_order: 1
wide: true
description: "Install, host, build, debug, and configure TaystJK."
---

<section class="hero">
  <div class="hero-copy">
    <p class="eyebrow">TaystJK documentation</p>
    <h1>Play it. Host it.<br><span>Build it.</span></h1>
    <p class="hero-lede">Practical documentation for installing TaystJK, running a dedicated server, working on the engine, and understanding every console control.</p>
    <div class="hero-actions">
      <a class="button button-primary" href="{{ '/install/' | relative_url }}">Install TaystJK</a>
      <a class="button button-secondary" href="https://github.com/taysta/TaystJK/releases/tag/latest">Download latest build</a>
    </div>
  </div>
  <div class="hero-terminal" aria-label="Documentation quick links">
    <div class="terminal-bar"><span></span><span></span><span></span><b>quick paths</b></div>
    <div class="terminal-body">
      <a class="terminal-entry" href="{{ '/server-hosting/' | relative_url }}">
        <p class="terminal-entry-heading"><span class="terminal-prompt">01</span> <strong>Run a server</strong><span class="terminal-entry-action">Open →</span></p>
        <p class="terminal-muted">Docker Compose, server.cfg, downloads, and reflists</p>
      </a>
      <hr>
      <a class="terminal-entry" href="{{ '/development/' | relative_url }}">
        <p class="terminal-entry-heading"><span class="terminal-prompt">02</span> <strong>Work on TaystJK</strong><span class="terminal-entry-action">Open →</span></p>
        <p class="terminal-muted">Compilation, debugging, and bundled libraries</p>
      </a>
      <hr>
      <a class="terminal-entry" href="{{ '/reference/' | relative_url }}">
        <p class="terminal-entry-heading"><span class="terminal-prompt">03</span> <strong>Find a console control</strong><span class="terminal-entry-action">Open →</span></p>
        <p class="terminal-muted">2,014 source-derived cvars and commands</p>
      </a>
    </div>
  </div>
</section>

<section class="browse-section home-browse" aria-labelledby="docs-heading">
  <div class="section-heading">
    <div><p class="section-kicker">Documentation</p><h2 id="docs-heading">Choose where to start</h2></div>
    <p>From first launch to engine development, each guide is written for TaystJK's current layout and tooling.</p>
  </div>
  <div class="browse-grid">
    <a class="browse-card" href="{{ '/install/' | relative_url }}"><span class="browse-icon">01</span><h3>Install</h3><p>Set up TaystJK on Windows, Linux, or macOS, including clean layouts for multiple modded clients.</p><b>Installation guide →</b></a>
    <a class="browse-card" href="{{ '/server-hosting/' | relative_url }}"><span class="browse-icon">02</span><h3>Host a server</h3><p>Deploy the dedicated server, write a rotation, enable HTTP downloads, and control PK3 references.</p><b>Server guide →</b></a>
    <a class="browse-card" href="{{ '/development/' | relative_url }}"><span class="browse-icon">03</span><h3>Build &amp; debug</h3><p>Configure CMake, compile every platform target, attach a debugger, and use sanitizers.</p><b>Developer guides →</b></a>
    <a class="browse-card" href="{{ '/reference/' | relative_url }}"><span class="browse-icon">04</span><h3>Console reference</h3><p>Search 1,441 cvars and 573 commands by topic, module, origin, and documentation coverage.</p><b>Search the reference →</b></a>
  </div>
</section>

<section class="method-banner">
  <div><p class="section-kicker">Under the hood</p><h2>Know exactly what ships.</h2></div>
  <p>See bundled library versions, build options, and source-linked evidence. Console source links open GitHub blame at the exact line.</p>
  <a class="text-link" href="{{ '/development/libraries/' | relative_url }}">Library inventory →</a>
</section>
