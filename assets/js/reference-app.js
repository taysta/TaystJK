(function (global) {
  "use strict";

  var PAGE_SIZE = 48;
  var ORIGIN_ORDER = ["taystjk", "eternaljk", "japro", "jk2mv", "newjk", "rend2", "vulkan", "openjk", "basejka", "quake3", "unknown"];
  var ORIGIN_LABELS = {
    taystjk: "TaystJK",
    eternaljk: "EternalJK",
    japro: "jaPRO",
    jk2mv: "JK2MV",
    newjk: "NewJK / NewMod",
    rend2: "rend2",
    vulkan: "Vulkan",
    openjk: "OpenJK",
    basejka: "Base Jedi Academy",
    quake3: "Quake III lineage",
    unknown: "Unknown"
  };
  var NETWORK_LABELS = {
    "client-only": "Client only",
    "needs-server-support": "Needs server support",
    "server-authoritative": "Server authoritative",
    "feature-flagged": "Negotiated feature"
  };

  function normalize(value) {
    return String(value == null ? "" : value).toLowerCase().replace(/\s+/g, " ").trim();
  }

  function escapeHtml(value) {
    return String(value == null ? "" : value)
      .replace(/&/g, "&amp;")
      .replace(/</g, "&lt;")
      .replace(/>/g, "&gt;")
      .replace(/"/g, "&quot;")
      .replace(/'/g, "&#39;");
  }

  function inlineCode(value) {
    return escapeHtml(value).replace(/`([^`]+)`/g, "<code>$1</code>");
  }

  function prepareEntry(entry) {
    var optionText = (entry.values || []).map(function (option) {
      return option.value + " " + option.meaning;
    }).join(" ");
    entry._name = normalize(entry.name);
    entry._search = normalize([
      entry.name,
      entry.summary,
      entry.description,
      entry.kind,
      entry.module,
      (entry.modules || []).join(" "),
      entry.origin,
      entry.network,
      (entry.renderer || []).join(" "),
      (entry.flags || []).join(" "),
      entry.syntax,
      (entry.arguments || []).join(" "),
      (entry.gating || []).join(" "),
      optionText
    ].join(" "));
    return entry;
  }

  function entryMatches(entry, state) {
    if (state.kind !== "all" && entry.kind !== state.kind) return false;
    if (state.origin && entry.origin !== state.origin) return false;
    if (state.module && (entry.modules || [entry.module]).indexOf(state.module) === -1) return false;
    if (state.status && entry.status !== state.status) return false;
    if (state.network && entry.network !== state.network) return false;
    if (state.flag && (entry.flags || []).indexOf(state.flag) === -1) return false;
    if (state.renderer === "renderer-specific" && !(entry.renderer || []).length) return false;
    if (state.renderer === "none" && (entry.renderer || []).length) return false;
    if (state.renderer && state.renderer !== "renderer-specific" && state.renderer !== "none" && (entry.renderer || []).indexOf(state.renderer) === -1) return false;
    if (state.tokens.length && !state.tokens.every(function (token) { return entry._search.indexOf(token) !== -1; })) return false;
    return true;
  }

  function relevance(entry, query) {
    if (!query) return 10;
    if (entry._name === query) return 0;
    if (entry._name.indexOf(query) === 0) return 1;
    if (entry._name.indexOf(query) !== -1) return 2;
    if (normalize(entry.summary).indexOf(query) !== -1) return 3;
    return 4;
  }

  function sortEntries(entries, state) {
    return entries.slice().sort(function (a, b) {
      var result = 0;
      if (state.sort === "relevance" && state.query) result = relevance(a, state.query) - relevance(b, state.query);
      if (!result && state.sort === "origin") result = ORIGIN_ORDER.indexOf(a.origin) - ORIGIN_ORDER.indexOf(b.origin);
      if (!result && state.sort === "module") result = a.module.localeCompare(b.module);
      if (!result) result = a._name.localeCompare(b._name);
      return result;
    });
  }

  function unique(entries, getter) {
    var found = Object.create(null);
    entries.forEach(function (entry) {
      var values = getter(entry);
      (Array.isArray(values) ? values : [values]).forEach(function (value) {
        if (value) found[value] = true;
      });
    });
    return Object.keys(found);
  }

  function option(select, value, label) {
    var node = document.createElement("option");
    node.value = value;
    node.textContent = label;
    select.appendChild(node);
  }

  function populateFilters(root, entries) {
    var origin = root.querySelector('[data-filter="origin"]');
    ORIGIN_ORDER.filter(function (value) {
      return entries.some(function (entry) { return entry.origin === value; });
    }).forEach(function (value) { option(origin, value, ORIGIN_LABELS[value] || value); });

    unique(entries, function (entry) { return entry.modules || [entry.module]; }).sort().forEach(function (value) {
      option(root.querySelector('[data-filter="module"]'), value, value);
    });
    unique(entries, function (entry) { return entry.renderer; }).sort().forEach(function (value) {
      option(root.querySelector('[data-filter="renderer"]'), value, value);
    });
    unique(entries, function (entry) { return entry.network; }).sort().forEach(function (value) {
      option(root.querySelector('[data-filter="network"]'), value, NETWORK_LABELS[value] || value);
    });
    unique(entries, function (entry) { return entry.flags || []; }).sort().forEach(function (value) {
      option(root.querySelector('[data-filter="flag"]'), value, value);
    });
  }

  function originBadge(entry) {
    return '<span class="mini-origin ref-origin-' + escapeHtml(entry.origin) + '">' + escapeHtml(ORIGIN_LABELS[entry.origin] || entry.origin) + '</span>';
  }

  function signature(entry) {
    if (entry.kind === "command") {
      return '<div class="card-signature"><strong>Usage</strong> <code>' + escapeHtml(entry.syntax || entry.name) + '</code></div>';
    }
    var value = entry.default == null ? "dynamic" : (entry.default === "" ? '\"\"' : entry.default);
    return '<div class="card-signature"><strong>Default</strong> <code>' + escapeHtml(value) + '</code>' +
      (entry.value_type ? ' &nbsp; <strong>Type</strong> ' + escapeHtml(entry.value_type) : "") + '</div>';
  }

  function optionsPreview(entry) {
    if (entry.kind !== "cvar" || !(entry.values || []).length) return "";
    var values = entry.values.slice(0, 2).map(function (item) {
      return '<div class="card-option"><code>' + escapeHtml(item.value) + '</code><span title="' + escapeHtml(item.meaning) + '">' + escapeHtml(item.meaning) + '</span></div>';
    }).join("");
    var more = entry.values.length > 2 ? '<span class="card-option-more">+' + (entry.values.length - 2) + ' more documented value' + (entry.values.length === 3 ? '' : 's') + '</span>' : "";
    return '<div class="card-options">' + values + more + '</div>';
  }

  function card(entry) {
    var scopes = originBadge(entry);
    (entry.renderer || []).forEach(function (renderer) {
      scopes += '<span class="renderer-chip">' + escapeHtml(renderer) + '</span>';
    });
    if (entry.status !== "documented") scopes += '<span class="status-chip">Needs review</span>';

    var meta = '<span class="meta-chip">' + escapeHtml(entry.module) + '</span>' +
      '<span class="meta-chip">' + escapeHtml(NETWORK_LABELS[entry.network] || entry.network) + '</span>';
    if (entry.cheat_protected) meta += '<span class="meta-chip">Cheat protected</span>';
    if (entry.requires_restart) meta += '<span class="meta-chip">Restart required</span>';
    (entry.flags || []).slice(0, 2).forEach(function (flag) { meta += '<span class="meta-chip">' + escapeHtml(flag) + '</span>'; });

    return '<article class="reference-card">' +
      '<div class="card-head"><a class="card-title" href="' + escapeHtml(entry.url) + '"><code>' + escapeHtml(entry.name) + '</code></a>' +
      '<span class="kind-badge kind-' + entry.kind + '">' + entry.kind + '</span></div>' +
      '<p class="card-summary">' + inlineCode(entry.summary) + '</p>' +
      signature(entry) + optionsPreview(entry) +
      '<div class="card-scopes">' + scopes + '</div>' +
      '<div class="card-meta">' + meta + '</div>' +
      '</article>';
  }

  function stateFrom(root) {
    var params = new URLSearchParams(global.location.search);
    var mode = root.dataset.mode || "all";
    var kind = mode === "all" && ["cvar", "command"].indexOf(params.get("kind")) !== -1 ? params.get("kind") : mode;
    return {
      mode: mode,
      kind: kind,
      query: normalize(params.get("q")),
      tokens: normalize(params.get("q")).split(" ").filter(Boolean),
      origin: root.dataset.presetOrigin || params.get("origin") || "",
      module: root.dataset.presetModule || params.get("module") || "",
      renderer: root.dataset.presetRenderer || params.get("renderer") || "",
      status: params.get("status") || "",
      network: params.get("network") || "",
      flag: params.get("flag") || "",
      sort: ["relevance", "name", "origin", "module"].indexOf(params.get("sort")) !== -1 ? params.get("sort") : "relevance",
      limit: PAGE_SIZE,
      presets: {
        origin: root.dataset.presetOrigin || "",
        module: root.dataset.presetModule || "",
        renderer: root.dataset.presetRenderer || ""
      }
    };
  }

  function applyState(root, state) {
    root.querySelector("[data-search]").value = state.query;
    ["origin", "module", "renderer", "status", "network", "flag"].forEach(function (key) {
      var select = root.querySelector('[data-filter="' + key + '"]');
      if (Array.prototype.some.call(select.options, function (item) { return item.value === state[key]; })) select.value = state[key];
      if (state.presets[key]) {
        select.value = state.presets[key];
        select.disabled = true;
      }
    });
    root.querySelector("[data-sort]").value = state.sort;
    root.querySelector("[data-kind-tabs]").classList.toggle("is-fixed", state.mode !== "all");
    Array.prototype.forEach.call(root.querySelectorAll("[data-kind]"), function (button) {
      var active = button.dataset.kind === state.kind;
      button.classList.toggle("active", active);
      button.setAttribute("aria-pressed", active ? "true" : "false");
    });
    root.querySelector("[data-cvar-filter]").hidden = state.kind === "command";
  }

  function syncUrl(state) {
    var params = new URLSearchParams(global.location.search);
    ["q", "kind", "origin", "module", "renderer", "status", "network", "flag", "sort"].forEach(function (key) { params.delete(key); });
    if (state.query) params.set("q", state.query);
    if (state.mode === "all" && state.kind !== "all") params.set("kind", state.kind);
    ["origin", "module", "renderer"].forEach(function (key) {
      if (state[key] && !state.presets[key]) params.set(key, state[key]);
    });
    ["status", "network", "flag"].forEach(function (key) { if (state[key]) params.set(key, state[key]); });
    if (state.sort !== "relevance") params.set("sort", state.sort);
    var query = params.toString();
    global.history.replaceState(null, "", global.location.pathname + (query ? "?" + query : "") + global.location.hash);
  }

  function activeFilterText(state) {
    var values = [];
    if (state.origin) values.push("Origin: " + (ORIGIN_LABELS[state.origin] || state.origin));
    if (state.module) values.push("Module: " + state.module);
    if (state.renderer) values.push("Renderer: " + state.renderer);
    if (state.status) values.push(state.status === "documented" ? "Documented" : "Needs review");
    if (state.network) values.push(NETWORK_LABELS[state.network] || state.network);
    if (state.flag) values.push(state.flag);
    return values.join(" · ");
  }

  function render(root, entries, state) {
    var matches = sortEntries(entries.filter(function (entry) { return entryMatches(entry, state); }), state);
    var shown = matches.slice(0, state.limit);
    var results = root.querySelector("[data-results]");
    results.innerHTML = shown.map(card).join("");
    results.setAttribute("aria-busy", "false");
    root.querySelector("[data-result-count]").textContent = matches.length.toLocaleString() + " " + (matches.length === 1 ? "entry" : "entries") + (state.query ? ' matching “' + state.query + '”' : "");
    root.querySelector("[data-active-filters]").textContent = activeFilterText(state);
    root.querySelector("[data-empty]").hidden = matches.length !== 0;
    var more = root.querySelector("[data-load-more]");
    more.hidden = shown.length >= matches.length;
    more.textContent = shown.length < matches.length ? "Show " + Math.min(PAGE_SIZE, matches.length - shown.length) + " more" : "Show more";
    root._matchingEntries = matches;
  }

  function showSkeleton(root) {
    root.querySelector("[data-results]").innerHTML = new Array(7).join('<article class="reference-card loading-card" aria-hidden="true"></article>');
  }

  function bind(root, entries) {
    var state = stateFrom(root);
    populateFilters(root, entries);
    applyState(root, state);

    var scheduled = false;
    function update(updateUrl) {
      if (scheduled) return;
      scheduled = true;
      global.requestAnimationFrame(function () {
        scheduled = false;
        render(root, entries, state);
        if (updateUrl !== false) syncUrl(state);
      });
    }

    root.querySelector("[data-search]").addEventListener("input", function (event) {
      state.query = normalize(event.target.value);
      state.tokens = state.query.split(" ").filter(Boolean);
      state.limit = PAGE_SIZE;
      update(true);
    });
    Array.prototype.forEach.call(root.querySelectorAll("[data-filter]"), function (select) {
      select.addEventListener("change", function () {
        state[select.dataset.filter] = select.value;
        state.limit = PAGE_SIZE;
        update(true);
      });
    });
    root.querySelector("[data-sort]").addEventListener("change", function (event) {
      state.sort = event.target.value;
      state.limit = PAGE_SIZE;
      update(true);
    });
    Array.prototype.forEach.call(root.querySelectorAll("[data-kind]"), function (button) {
      button.addEventListener("click", function () {
        state.kind = button.dataset.kind;
        if (state.kind === "command") state.flag = "";
        state.limit = PAGE_SIZE;
        applyState(root, state);
        update(true);
      });
    });
    root.querySelector("[data-catalog-form]").addEventListener("submit", function (event) { event.preventDefault(); });
    root.querySelector("[data-catalog-form]").addEventListener("reset", function (event) {
      event.preventDefault();
      state.kind = state.mode;
      state.query = "";
      state.tokens = [];
      state.origin = state.presets.origin;
      state.module = state.presets.module;
      state.renderer = state.presets.renderer;
      state.status = "";
      state.network = "";
      state.flag = "";
      state.sort = "relevance";
      state.limit = PAGE_SIZE;
      applyState(root, state);
      update(true);
    });
    root.querySelector("[data-load-more]").addEventListener("click", function () {
      state.limit += PAGE_SIZE;
      render(root, entries, state);
    });
    document.addEventListener("keydown", function (event) {
      var target = event.target;
      var isTyping = /^(INPUT|TEXTAREA|SELECT)$/.test(target.tagName) || target.isContentEditable;
      if (event.key === "/" && !isTyping) {
        event.preventDefault();
        root.querySelector("[data-search]").focus();
      }
    });
    update(false);
  }

  function boot() {
    Array.prototype.forEach.call(document.querySelectorAll("[data-reference-app]"), function (root) {
      showSkeleton(root);
      fetch(root.dataset.catalogUrl, { credentials: "same-origin" })
        .then(function (response) {
          if (!response.ok) throw new Error("HTTP " + response.status);
          return response.json();
        })
        .then(function (entries) { bind(root, entries.map(prepareEntry)); })
        .catch(function (error) {
          root.querySelector("[data-results]").innerHTML = '<p class="catalog-error">The search index could not be loaded. Reload the page or use the browse links below. <small>' + escapeHtml(error.message) + '</small></p>';
          root.querySelector("[data-result-count]").textContent = "Reference unavailable";
        });
    });
  }

  var api = {
    normalize: normalize,
    prepareEntry: prepareEntry,
    entryMatches: entryMatches,
    sortEntries: sortEntries,
    relevance: relevance
  };

  if (typeof module !== "undefined" && module.exports) module.exports = api;
  global.TaystReference = api;
  if (typeof document !== "undefined") {
    if (document.readyState === "loading") document.addEventListener("DOMContentLoaded", boot);
    else boot();
  }
}(typeof window !== "undefined" ? window : globalThis));
