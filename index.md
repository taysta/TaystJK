---
title: "TaystJK: one client for Jedi Academy multiplayer"
layout: reference
generated: true
nav_order: 1
wide: true
description: "TaystJK is a cross-platform Jedi Academy multiplayer client built for Base JKA, JA+/JA++, jaPRO, and Lugormod servers, on Windows, Linux, and macOS."
toc: true
---

<div class="docs-overview">
  <section class="docs-intro" aria-labelledby="page-title">
    <p class="eyebrow">TaystJK documentation</p>
    <h1 id="page-title">One client for Jedi Academy multiplayer</h1>
    <p class="page-lede">TaystJK replaces the multiplayer executable of your own copy of Jedi Academy. It plays on Base JKA, JA+ and JA++, jaPRO and Lugormod servers, and runs on Windows, Linux and macOS.</p>
    <div class="docs-intro-actions">
      <a class="button button-primary" href="{{ '/install/' | relative_url }}">Install TaystJK</a>
      <a class="button button-secondary" href="https://github.com/taysta/TaystJK/releases/latest">Latest release</a>
    </div>
    <nav class="docs-intro-links" aria-label="Project links">
      <a href="{{ '/overview/' | relative_url }}">How these docs are organised</a>
      <a href="https://github.com/taysta/TaystJK">Source repository</a>
    </nav>
  </section>

  <nav class="docs-quick-links" aria-labelledby="quick-links-heading">
    <h2 id="quick-links-heading" data-toc-skip>Quick links</h2>
    <a href="{{ '/server-hosting/run-a-server/' | relative_url }}">
      <strong>Run a server</strong>
      <span>Docker Compose or a native binary, then the checks before going public</span>
    </a>
    <a href="{{ '/troubleshooting/' | relative_url }}">
      <strong>Fix a problem</strong>
      <span>Common problems, listed by what you see</span>
    </a>
    <a href="{{ '/reference/' | relative_url }}">
      <strong>Find a console control</strong>
      <span>1,445 cvars and 573 commands derived from source</span>
    </a>
  </nav>
</div>

<section class="home-purpose" aria-labelledby="purpose-heading">
  <div class="home-section-heading">
    <div>
      <p class="section-kicker">What it does</p>
      <h2 id="purpose-heading">Works with every server mod</h2>
    </div>
    <p>Jedi Academy servers run different mods with different rules. TaystJK works out which one you joined and adjusts to it, so you do not need a separate client per community.</p>
  </div>

  <div class="purpose-principles">
    <article>
      <span>01</span>
      <h3>Adapts to the server</h3>
      <p>It recognises the server's mod and changes movement prediction and which client features it turns on. The server still decides how the game plays.</p>
    </article>
    <article>
      <span>02</span>
      <h3>Windows, Linux and macOS</h3>
      <p>32- and 64-bit builds for Windows and Linux, and Intel, Apple silicon and universal builds for macOS.</p>
    </article>
    <article>
      <span>03</span>
      <h3>Everyday fixes</h3>
      <p>HUD tools, console and bind improvements, server-side demos, HTTP downloads and three renderers.</p>
    </article>
  </div>

  <p class="project-lineage">TaystJK includes code from OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2, the community's Vulkan renderer work, and TaystJK's own contributors. Code brought across project boundaries is ported with permission and credited to its source. <a href="{{ '/reference/sources/' | relative_url }}">See the source lineage.</a></p>

  <p class="project-lineage"><strong>jaPRO</strong> is the largest single source of what this client can do: 481 of the 2,018 entries in the console reference originate there. TaystJK bundles jaPRO's gamecode on both sides: the client-side <code>cgame</code>, so its HUD and movement tools work on any server, and the server-side <code>jampgame</code>, so a TaystJK server hosts race, Tribes and the admin system with nothing else installed. The code is maintained upstream, so bugs in the rules belong to <a href="https://github.com/videoP/jaPRO">videoP/jaPRO</a> once you have checked they also happen without TaystJK. <a href="{{ '/overview/' | relative_url }}">What the split means.</a></p>
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
    <article class="compatibility-card">
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
      <h3>Server hosting</h3>
      <p>Dedicated server deployment, bundled game modes, downloads, and PK3 references.</p>
      <span>Server guide →</span>
    </a>
    <a class="home-guide" href="{{ '/features/' | relative_url }}">
      <h3>Features</h3>
      <p>What this client adds: HUD and movement tools, renderers, cosmetics, and movement styles.</p>
      <span>Browse the features →</span>
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
    <a class="home-guide" href="{{ '/help/' | relative_url }}">
      <h3>Help</h3>
      <p>Troubleshooting by symptom, where to report a problem, and the glossary.</p>
      <span>Get help →</span>
    </a>
  </div>
</section>
