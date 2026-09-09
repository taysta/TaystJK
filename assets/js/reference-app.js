(function (global) {
  "use strict";

  var PAGE_SIZE = 48;
  var FILTER_KEYS = ["origin", "module", "category", "renderer", "status", "network", "coverage", "flag"];
  var FILTER_DEFAULTS = {
    origin: "Any origin",
    module: "Any module",
    category: "Any topic",
    renderer: "Any renderer",
    status: "Any status",
    network: "Any scope",
    coverage: "Any coverage",
    flag: "Any flag"
  };
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
      entry.category,
      entry.origin,
      entry.network,
      (entry.renderer || []).join(" "),
      (entry.flags || []).join(" "),
      entry.syntax,
      (entry.arguments || []).join(" "),
      (entry.gating || []).join(" "),
      entry.xdocs ? "xdocs in-game documentation" : "missing xdocs",
      entry.menu ? "in-game menu" : "missing menu",
      optionText
    ].join(" "));
    return entry;
  }

  function selectedValues(state, key) {
    var value = state[key];
    if (Array.isArray(value)) return value.filter(Boolean);
    return value ? [value] : [];
  }

  function hasSelectedValue(state, key, value) {
    return selectedValues(state, key).indexOf(value) !== -1;
  }

  function entryMatches(entry, state) {
    if (state.kind !== "all" && entry.kind !== state.kind) return false;
    var origins = selectedValues(state, "origin");
    var modules = selectedValues(state, "module");
    var categories = selectedValues(state, "category");
    var statuses = selectedValues(state, "status");
    var networks = selectedValues(state, "network");
    var coverage = selectedValues(state, "coverage");
    var flags = selectedValues(state, "flag");
    var renderers = selectedValues(state, "renderer");
    if (origins.length && origins.indexOf(entry.origin) === -1) return false;
    if (modules.length && !modules.some(function (moduleName) { return (entry.modules || [entry.module]).indexOf(moduleName) !== -1; })) return false;
    if (categories.length && categories.indexOf(entry.category) === -1) return false;
    if (statuses.length && statuses.indexOf(entry.status) === -1) return false;
    if (networks.length && networks.indexOf(entry.network) === -1) return false;
    if (coverage.length && !coverage.some(function (value) {
      if (value === "xdocs") return Boolean(entry.xdocs);
      if (value === "menu") return Boolean(entry.menu);
      if (value === "no-xdocs") return !entry.xdocs;
      if (value === "no-menu") return !entry.menu;
      return false;
    })) return false;
    if (flags.length && !flags.some(function (flag) { return (entry.flags || []).indexOf(flag) !== -1; })) return false;
    if (renderers.length && !renderers.some(function (renderer) {
      if (renderer === "renderer-specific") return Boolean((entry.renderer || []).length);
      if (renderer === "none") return !(entry.renderer || []).length;
      return (entry.renderer || []).indexOf(renderer) !== -1;
    })) return false;
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
      if (!result && state.sort === "category") result = a.category.localeCompare(b.category);
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

  function checkboxOption(container, name, value, label) {
    var optionLabel = document.createElement("label");
    var input = document.createElement("input");
    var text = document.createElement("span");
    optionLabel.className = "filter-checkbox";
    input.type = "checkbox";
    input.name = name;
    input.value = value;
    input.dataset.filter = name;
    text.textContent = label;
    optionLabel.appendChild(input);
    optionLabel.appendChild(text);
    container.appendChild(optionLabel);
  }

  function selectOption(select, value, label) {
    var optionNode = document.createElement("option");
    optionNode.value = value;
    optionNode.textContent = label;
    select.appendChild(optionNode);
  }

  function addFilterOption(root, name, value, label) {
    var checkboxContainer = root.querySelector('[data-filter-options="' + name + '"]');
    if (checkboxContainer) checkboxOption(checkboxContainer, name, value, label);
    else selectOption(root.querySelector('select[data-filter="' + name + '"]'), value, label);
  }

  function populateFilters(root, entries) {
    ORIGIN_ORDER.filter(function (value) {
      return entries.some(function (entry) { return entry.origin === value; });
    }).forEach(function (value) { addFilterOption(root, "origin", value, ORIGIN_LABELS[value] || value); });

    unique(entries, function (entry) { return entry.modules || [entry.module]; }).sort().forEach(function (value) {
      addFilterOption(root, "module", value, value);
    });
    unique(entries, function (entry) { return entry.category; }).sort().forEach(function (value) {
      addFilterOption(root, "category", value, value);
    });
    unique(entries, function (entry) { return entry.renderer; }).sort().forEach(function (value) {
      addFilterOption(root, "renderer", value, value);
    });
    unique(entries, function (entry) { return entry.network; }).sort().forEach(function (value) {
      addFilterOption(root, "network", value, NETWORK_LABELS[value] || value);
    });
    unique(entries, function (entry) { return entry.flags || []; }).sort().forEach(function (value) {
      addFilterOption(root, "flag", value, value);
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

    var meta = '<span class="meta-chip">' + escapeHtml(entry.category) + '</span>' +
      '<span class="meta-chip">' + escapeHtml(entry.module) + '</span>' +
      '<span class="meta-chip">' + escapeHtml(NETWORK_LABELS[entry.network] || entry.network) + '</span>';
    if (entry.xdocs) meta += '<span class="coverage-chip">xdocs</span>';
    if (entry.menu) meta += '<span class="coverage-chip">menu</span>';
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

  function paramValues(params, key) {
    var seen = Object.create(null);
    return params.getAll(key).filter(function (value) {
      if (!value || seen[value]) return false;
      seen[value] = true;
      return true;
    });
  }

  function valueLabel(key, value) {
    if (key === "origin") return ORIGIN_LABELS[value] || value;
    if (key === "network") return NETWORK_LABELS[value] || value;
    if (key === "status") return value === "documented" ? "Documented" : "Needs review";
    if (key === "coverage") return { xdocs: "Has xdocs entry", menu: "Has menu entry", "no-xdocs": "Missing from xdocs", "no-menu": "Missing from menus" }[value] || value;
    if (key === "renderer" && value === "renderer-specific") return "Renderer-specific only";
    if (key === "renderer" && value === "none") return "Not renderer-specific";
    return value;
  }

  function stateFrom(root) {
    var params = new URLSearchParams(global.location.search);
    var mode = root.dataset.mode || "all";
    var kind = mode === "all" && ["cvar", "command"].indexOf(params.get("kind")) !== -1 ? params.get("kind") : mode;
    var presets = {
      origin: root.dataset.presetOrigin || "",
      module: root.dataset.presetModule || "",
      category: root.dataset.presetCategory || "",
      renderer: root.dataset.presetRenderer || ""
    };
    var state = {
      mode: mode,
      kind: kind,
      query: normalize(params.get("q")),
      tokens: normalize(params.get("q")).split(" ").filter(Boolean),
      origin: presets.origin ? [presets.origin] : paramValues(params, "origin"),
      module: presets.module ? [presets.module] : paramValues(params, "module"),
      category: presets.category ? [presets.category] : paramValues(params, "category"),
      renderer: presets.renderer ? [presets.renderer] : paramValues(params, "renderer"),
      status: paramValues(params, "status"),
      network: paramValues(params, "network"),
      coverage: paramValues(params, "coverage"),
      flag: paramValues(params, "flag"),
      sort: ["relevance", "name", "category", "origin", "module"].indexOf(params.get("sort")) !== -1 ? params.get("sort") : "relevance",
      limit: PAGE_SIZE,
      presets: presets
    };
    if (kind === "command") state.flag = [];
    return state;
  }

  function updateFilterSummary(root, state, key) {
    var summary = root.querySelector('[data-filter-summary="' + key + '"]');
    if (!summary) return;
    var values = selectedValues(state, key);
    summary.textContent = values.length === 0
      ? FILTER_DEFAULTS[key]
      : (values.length === 1 ? valueLabel(key, values[0]) : values.length + " selected");
    var toggle = root.querySelector('[data-filter-toggle="' + key + '"]');
    toggle.classList.toggle("has-selection", values.length > 0);
    var clear = root.querySelector('[data-clear-filter="' + key + '"]');
    clear.disabled = values.length === 0 || Boolean(state.presets[key]);
  }

  function closeDropdown(root, key) {
    var popover = root.querySelector('[data-filter-popover="' + key + '"]');
    var toggle = root.querySelector('[data-filter-toggle="' + key + '"]');
    if (!popover || !toggle) return;
    popover.hidden = true;
    toggle.setAttribute("aria-expanded", "false");
  }

  function closeDropdowns(root, except) {
    Array.prototype.forEach.call(root.querySelectorAll("[data-filter-popover]"), function (popover) {
      var key = popover.dataset.filterPopover;
      if (key !== except) closeDropdown(root, key);
    });
  }

  function applyState(root, state) {
    root.querySelector("[data-search]").value = state.query;
    FILTER_KEYS.forEach(function (key) {
      var controls = root.querySelectorAll('[data-filter="' + key + '"]');
      var requested = state.presets[key] ? [state.presets[key]] : selectedValues(state, key);
      var isSelect = controls.length === 1 && controls[0].tagName === "SELECT";
      if (isSelect) {
        var value = requested[0] || "";
        if (!Array.prototype.some.call(controls[0].options, function (optionNode) { return optionNode.value === value; })) value = "";
        state[key] = value ? [value] : [];
        controls[0].value = value;
        controls[0].disabled = Boolean(state.presets[key]);
      } else {
        var available = Array.prototype.map.call(controls, function (control) { return control.value; });
        state[key] = requested.filter(function (value) { return available.indexOf(value) !== -1; });
        Array.prototype.forEach.call(controls, function (control) {
          control.checked = hasSelectedValue(state, key, control.value);
          control.disabled = Boolean(state.presets[key]);
        });
      }
      updateFilterSummary(root, state, key);
    });
    root.querySelector("[data-sort]").value = state.sort;
    root.querySelector("[data-kind-tabs]").classList.toggle("is-fixed", state.mode !== "all");
    Array.prototype.forEach.call(root.querySelectorAll("[data-kind]"), function (button) {
      var active = button.dataset.kind === state.kind;
      button.classList.toggle("active", active);
      button.setAttribute("aria-pressed", active ? "true" : "false");
    });
    root.querySelector("[data-cvar-filter]").hidden = state.kind === "command";
    if (state.kind === "command") closeDropdown(root, "flag");
  }

  function syncUrl(state) {
    var params = new URLSearchParams(global.location.search);
    ["q", "kind", "origin", "module", "category", "renderer", "status", "network", "coverage", "flag", "sort"].forEach(function (key) { params.delete(key); });
    if (state.query) params.set("q", state.query);
    if (state.mode === "all" && state.kind !== "all") params.set("kind", state.kind);
    FILTER_KEYS.forEach(function (key) {
      if (state.presets[key]) return;
      selectedValues(state, key).forEach(function (value) { params.append(key, value); });
    });
    if (state.sort !== "relevance") params.set("sort", state.sort);
    var query = params.toString();
    global.history.replaceState(null, "", global.location.pathname + (query ? "?" + query : "") + global.location.hash);
  }

  function activeFilterText(state) {
    var values = [];
    var groupLabels = { origin: "Origin", module: "Module", category: "Topic", renderer: "Renderer", status: "Documentation", network: "Network", coverage: "In game", flag: "Flag" };
    FILTER_KEYS.forEach(function (key) {
      var selected = selectedValues(state, key);
      if (selected.length) values.push(groupLabels[key] + ": " + selected.map(function (value) { return valueLabel(key, value); }).join(", "));
    });
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
    Array.prototype.forEach.call(root.querySelectorAll("[data-filter]"), function (control) {
      control.addEventListener("change", function () {
        var key = control.dataset.filter;
        if (control.type === "checkbox") {
          state[key] = Array.prototype.filter.call(root.querySelectorAll('[data-filter="' + key + '"]'), function (checkbox) {
            return checkbox.checked;
          }).map(function (checkbox) { return checkbox.value; });
        } else {
          state[key] = control.value ? [control.value] : [];
        }
        state.limit = PAGE_SIZE;
        applyState(root, state);
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
        if (state.kind === "command") state.flag = [];
        state.limit = PAGE_SIZE;
        applyState(root, state);
        update(true);
      });
    });
    Array.prototype.forEach.call(root.querySelectorAll("[data-filter-toggle]"), function (toggle) {
      toggle.addEventListener("click", function () {
        var key = toggle.dataset.filterToggle;
        var popover = root.querySelector('[data-filter-popover="' + key + '"]');
        var opening = popover.hidden;
        closeDropdowns(root, opening ? key : "");
        popover.hidden = !opening;
        toggle.setAttribute("aria-expanded", opening ? "true" : "false");
      });
    });
    Array.prototype.forEach.call(root.querySelectorAll("[data-clear-filter]"), function (button) {
      button.addEventListener("click", function () {
        state[button.dataset.clearFilter] = [];
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
      state.origin = state.presets.origin ? [state.presets.origin] : [];
      state.module = state.presets.module ? [state.presets.module] : [];
      state.category = state.presets.category ? [state.presets.category] : [];
      state.renderer = state.presets.renderer ? [state.presets.renderer] : [];
      state.status = [];
      state.network = [];
      state.coverage = [];
      state.flag = [];
      state.sort = "relevance";
      state.limit = PAGE_SIZE;
      closeDropdowns(root, "");
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
      if (event.key === "Escape") {
        var openToggle = root.querySelector('[data-filter-toggle][aria-expanded="true"]');
        if (openToggle) {
          closeDropdown(root, openToggle.dataset.filterToggle);
          openToggle.focus();
        }
      }
      if (event.key === "/" && !isTyping) {
        event.preventDefault();
        root.querySelector("[data-search]").focus();
      }
    });
    document.addEventListener("click", function (event) {
      if (!event.target.closest || !event.target.closest("[data-filter-dropdown]")) closeDropdowns(root, "");
    });
    update(false);
  }

  function isPlatform(value) {
    return ["windows", "linux", "macos"].indexOf(value) !== -1;
  }

  function detectPlatform(platformText) {
    var value = normalize(platformText);
    if (value.indexOf("windows") !== -1 || value.indexOf("win32") !== -1 || value.indexOf("win64") !== -1) return "windows";
    if (value.indexOf("mac") !== -1 || value.indexOf("darwin") !== -1) return "macos";
    if (value.indexOf("linux") !== -1 || value.indexOf("x11") !== -1) return "linux";
    return "windows";
  }

  function choosePlatform(queryPlatform, storedPlatform, platformText) {
    queryPlatform = normalize(queryPlatform);
    storedPlatform = normalize(storedPlatform);
    if (isPlatform(queryPlatform)) return queryPlatform;
    if (isPlatform(storedPlatform)) return storedPlatform;
    return detectPlatform(platformText);
  }

  function bindPlatformGuide(root) {
    var storageKey = "taystjk-install-platform";
    var choices = Array.prototype.slice.call(root.querySelectorAll("[data-platform-choice]"));
    var panels = Array.prototype.slice.call(root.querySelectorAll("[data-platform-panel]"));
    var queryPlatform = "";
    var storedPlatform = "";
    var navigatorInfo = "";

    if (!choices.length || !panels.length) return;

    try {
      queryPlatform = new global.URLSearchParams(global.location.search).get("platform") || "";
    } catch (error) {
      queryPlatform = "";
    }
    try {
      storedPlatform = global.localStorage.getItem(storageKey) || "";
    } catch (error) {
      storedPlatform = "";
    }
    if (global.navigator) {
      navigatorInfo = [
        global.navigator.userAgentData && global.navigator.userAgentData.platform,
        global.navigator.platform,
        global.navigator.userAgent
      ].filter(Boolean).join(" ");
    }

    function selectPlatform(platform, persist) {
      choices.forEach(function (choice) {
        var selected = choice.dataset.platformChoice === platform;
        choice.setAttribute("aria-selected", selected ? "true" : "false");
        choice.tabIndex = selected ? 0 : -1;
      });
      panels.forEach(function (panel) {
        panel.hidden = panel.dataset.platformPanel !== platform;
      });

      if (!persist) return;
      try {
        global.localStorage.setItem(storageKey, platform);
      } catch (error) {
        // The selector still works when storage is unavailable.
      }
      try {
        var url = new global.URL(global.location.href);
        url.searchParams.set("platform", platform);
        global.history.replaceState(null, "", url.pathname + url.search + url.hash);
      } catch (error) {
        // URL updates are optional; selecting a panel is not.
      }
    }

    choices.forEach(function (choice, index) {
      choice.addEventListener("click", function () {
        selectPlatform(choice.dataset.platformChoice, true);
      });
      choice.addEventListener("keydown", function (event) {
        var nextIndex = index;
        if (event.key === "ArrowRight") nextIndex = (index + 1) % choices.length;
        else if (event.key === "ArrowLeft") nextIndex = (index - 1 + choices.length) % choices.length;
        else if (event.key === "Home") nextIndex = 0;
        else if (event.key === "End") nextIndex = choices.length - 1;
        else return;

        event.preventDefault();
        choices[nextIndex].focus();
        selectPlatform(choices[nextIndex].dataset.platformChoice, true);
      });
    });

    selectPlatform(choosePlatform(queryPlatform, storedPlatform, navigatorInfo), false);
  }

  function boot() {
    Array.prototype.forEach.call(document.querySelectorAll("[data-platform-guide]"), bindPlatformGuide);
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
    relevance: relevance,
    detectPlatform: detectPlatform,
    choosePlatform: choosePlatform
  };

  if (typeof module !== "undefined" && module.exports) module.exports = api;
  global.TaystReference = api;
  if (typeof document !== "undefined") {
    if (document.readyState === "loading") document.addEventListener("DOMContentLoaded", boot);
    else boot();
  }
}(typeof window !== "undefined" ? window : globalThis));
