/* Heading anchors and site-wide search. Independent of reference-app.js, which owns the
   console reference's own filtering UI. */
(function (global) {
  "use strict";

  var doc = global.document;

  /* ---------------------------------------------------------------- anchors */

  function addHeadingAnchors() {
    var article = doc.querySelector(".page-content");
    if (!article) return;

    var headings = article.querySelectorAll("h2[id], h3[id], h4[id]");
    Array.prototype.forEach.call(headings, function (heading) {
      if (heading.querySelector(".heading-anchor")) return;
      /* The "On this page" label is a heading with an id too, but it is furniture -- an
         anchor to it is not something anyone wants to copy. */
      if (heading.closest(".page-toc")) return;

      var link = doc.createElement("a");
      link.className = "heading-anchor";
      link.href = "#" + heading.id;
      /* Naming the section matters: without it a screen reader announces the same
         "link to this section" once per heading, with nothing to tell them apart. */
      link.setAttribute("aria-label", "Link to section: " + heading.textContent.trim());
      link.innerHTML = "<span aria-hidden=\"true\">#</span>";

      link.addEventListener("click", function (event) {
        if (event.metaKey || event.ctrlKey || event.shiftKey || !global.navigator.clipboard) return;
        event.preventDefault();
        var url = global.location.origin + global.location.pathname + global.location.search + "#" + heading.id;
        global.navigator.clipboard.writeText(url).then(function () {
          global.history.replaceState(null, "", "#" + heading.id);
          heading.classList.add("heading-copied");
          global.setTimeout(function () { heading.classList.remove("heading-copied"); }, 1400);
        }, function () {
          global.location.hash = heading.id;
        });
      });

      heading.appendChild(link);
    });
  }

  /* ----------------------------------------------------------------- theme */

  function setupTheme() {
    var toggle = doc.querySelector(".theme-toggle");
    if (!toggle) return;

    var root = doc.documentElement;
    var media = global.matchMedia ? global.matchMedia("(prefers-color-scheme: light)") : null;

    function current() {
      var explicit = root.getAttribute("data-theme");
      if (explicit) return explicit;
      return media && media.matches ? "light" : "dark";
    }

    function apply(theme) {
      root.setAttribute("data-theme", theme);
      toggle.setAttribute("aria-pressed", theme === "light" ? "true" : "false");
      toggle.title = theme === "light" ? "Switch to dark theme" : "Switch to light theme";
      try {
        global.localStorage.setItem("taystjk-theme", theme);
      } catch (error) {
        // The toggle still works for this page view without storage.
      }
    }

    apply(current());
    toggle.addEventListener("click", function () {
      apply(current() === "light" ? "dark" : "light");
    });
  }

  /* ------------------------------------------------------------- copy code */

  function addCopyButtons() {
    if (!global.navigator.clipboard) return;
    var article = doc.querySelector(".page-content");
    if (!article) return;

    Array.prototype.forEach.call(article.querySelectorAll("pre"), function (block) {
      if (block.parentElement.classList.contains("code-block")) return;

      var wrap = doc.createElement("div");
      wrap.className = "code-block";
      block.parentNode.insertBefore(wrap, block);
      wrap.appendChild(block);

      var button = doc.createElement("button");
      button.type = "button";
      button.className = "code-copy";
      button.textContent = "Copy";
      /* Most blocks here are commands to paste into a console, so name what is being
         copied rather than leaving a screen reader with a row of bare "Copy" buttons. */
      button.setAttribute("aria-label", "Copy code to clipboard");

      button.addEventListener("click", function () {
        global.navigator.clipboard.writeText(block.innerText.replace(/\n$/, "")).then(function () {
          button.textContent = "Copied";
          button.classList.add("is-copied");
          global.setTimeout(function () {
            button.textContent = "Copy";
            button.classList.remove("is-copied");
          }, 1400);
        }, function () {
          button.textContent = "Press Ctrl+C";
          global.setTimeout(function () { button.textContent = "Copy"; }, 1800);
        });
      });

      wrap.appendChild(button);
    });
  }

  /* -------------------------------------------------------------------- toc */

  function buildToc() {
    var article = doc.querySelector(".page-content[data-toc]");
    var main = doc.querySelector(".site-main");
    if (!article || !main) return;

    /* Headings inside a tab panel are skipped. Only one panel is visible at a time, so a
       link to a heading in a hidden one goes nowhere the reader can see -- and the tab
       strip is already the navigation for that part of the page. */
    var headings = Array.prototype.filter.call(
      article.querySelectorAll("h2[id], h3[id]"),
      function (heading) {
        /* data-toc-skip marks a heading that labels furniture rather than a section of
           the page -- a sidebar caption, a mounted widget's title. */
        if (heading.hasAttribute("data-toc-skip")) return false;
        return !heading.closest("[data-platform-panel], [data-baseline-panel]");
      }
    );

    /* Two is enough to be worth navigating; one is just the page itself. */
    if (headings.length < 2) return;

    var storageKey = "taystjk-toc-collapsed";
    var collapsed = false;
    try {
      collapsed = global.localStorage.getItem(storageKey) === "true";
    } catch (error) {
      collapsed = false;
    }

    var rail = doc.createElement("aside");
    rail.className = "page-toc-rail";

    var toggle = doc.createElement("button");
    toggle.type = "button";
    toggle.className = "page-toc-toggle";
    toggle.setAttribute("aria-controls", "page-toc-nav");
    toggle.innerHTML =
      '<span class="page-toc-chevron" aria-hidden="true"></span>' +
      '<span class="page-toc-label">On this page</span>';
    rail.appendChild(toggle);

    var nav = doc.createElement("nav");
    nav.id = "page-toc-nav";
    nav.className = "page-toc";
    nav.setAttribute("aria-label", "On this page");

    var list = doc.createElement("ul");
    headings.forEach(function (item) {
      var li = doc.createElement("li");
      if (item.tagName === "H3") li.className = "page-toc-sub";
      var link = doc.createElement("a");
      link.href = "#" + item.id;
      link.textContent = item.textContent.trim();
      li.appendChild(link);
      list.appendChild(li);
    });
    nav.appendChild(list);
    rail.appendChild(nav);

    function apply(next, persist) {
      collapsed = next;
      rail.dataset.collapsed = next ? "true" : "false";
      main.dataset.tocCollapsed = next ? "true" : "false";
      toggle.setAttribute("aria-expanded", next ? "false" : "true");
      toggle.setAttribute("title", next ? "Show page sections" : "Hide page sections");
      if (!persist) return;
      try {
        global.localStorage.setItem(storageKey, next ? "true" : "false");
      } catch (error) {
        // The toggle still works when storage is unavailable.
      }
    }

    toggle.addEventListener("click", function () { apply(!collapsed, true); });

    main.classList.add("has-toc");
    main.insertBefore(rail, main.firstChild);
    apply(collapsed, false);

    markCurrentSection(nav, headings);
  }

  /* Highlights the section currently in view, so the rail says where you are. */
  function markCurrentSection(nav, headings) {
    if (!global.IntersectionObserver) return;
    var links = {};
    Array.prototype.forEach.call(nav.querySelectorAll("a"), function (link) {
      links[link.getAttribute("href").slice(1)] = link;
    });

    var seen = {};
    var observer = new global.IntersectionObserver(function (entries) {
      entries.forEach(function (entry) { seen[entry.target.id] = entry.isIntersecting; });

      var currentId = null;
      for (var i = 0; i < headings.length; i++) {
        if (seen[headings[i].id]) { currentId = headings[i].id; break; }
      }
      if (!currentId) return;

      Object.keys(links).forEach(function (id) {
        links[id].classList.toggle("is-current", id === currentId);
      });
    }, { rootMargin: "-80px 0px -70% 0px" });

    headings.forEach(function (heading) { observer.observe(heading); });
  }

  /* ----------------------------------------------------------------- search */

  var index = null;
  var loading = null;

  function loadIndex(base) {
    if (index) return Promise.resolve(index);
    if (loading) return loading;
    loading = global.fetch(base + "/search-index.json")
      .then(function (res) { return res.ok ? res.json() : []; })
      .then(function (data) { index = Array.isArray(data) ? data : []; return index; })
      .catch(function () { index = []; return index; });
    return loading;
  }

  function normalize(value) {
    return (value || "").toString().toLowerCase();
  }

  function score(item, query) {
    var title = normalize(item.t);
    if (title === query) return 0;
    if (title.indexOf(query) === 0) return 1;
    /* Console entries are conventionally prefixed -- cg_, r_, sv_. Searching "killfeed"
       should reach cg_killfeed as readily as a heading that happens to start with it. */
    var underscore = title.indexOf("_");
    if (underscore !== -1 && title.slice(underscore + 1).indexOf(query) === 0) return 1;
    if (title.indexOf(query) !== -1) return 2;
    if (item.k === "page" && normalize(item.d).indexOf(query) !== -1) return 3;
    if (item.k === "page" && normalize(item.b).indexOf(query) !== -1) return 4;
    return -1;
  }

  function rank(items, query) {
    var kindWeight = { entry: 0, section: 1, page: 0 };
    var scored = [];
    for (var i = 0; i < items.length; i++) {
      var s = score(items[i], query);
      if (s === -1) continue;
      scored.push({ item: items[i], score: s * 10 + (kindWeight[items[i].k] || 0) });
      if (scored.length > 600) break;
    }
    scored.sort(function (a, b) {
      if (a.score !== b.score) return a.score - b.score;
      return a.item.t.length - b.item.t.length;
    });
    return scored.slice(0, 12).map(function (row) { return row.item; });
  }

  function escapeHtml(value) {
    return (value || "").toString()
      .replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;")
      .replace(/"/g, "&quot;").replace(/'/g, "&#39;");
  }

  function contextFor(item) {
    if (item.k === "entry") return "Console reference";
    if (item.k === "section") return item.p;
    return item.d || "";
  }

  function render(list, results, base) {
    if (!results.length) {
      list.innerHTML = "<li class=\"search-empty\">No matches.</li>";
      list.hidden = false;
      return;
    }
    list.innerHTML = results.map(function (item) {
      return "<li><a href=\"" + escapeHtml(base + item.u) + "\">" +
        "<span class=\"search-title\">" + escapeHtml(item.t) + "</span>" +
        (item.k === "entry" ? "<span class=\"search-kind\">entry</span>" : "") +
        "<span class=\"search-context\">" + escapeHtml(contextFor(item)) + "</span>" +
        "</a></li>";
    }).join("");
    list.hidden = false;
  }

  function setupSearch() {
    var form = doc.querySelector(".site-search");
    if (!form) return;
    var input = form.querySelector("input");
    var list = form.querySelector(".search-results");
    var status = form.querySelector(".search-status");
    if (!input || !list) return;

    function announce(text) {
      if (status) status.textContent = text;
    }

    var base = form.dataset.baseurl || "";
    var active = -1;
    var restoringFocus = false;
    var searchRun = 0;

    function close() {
      searchRun += 1;
      list.hidden = true;
      active = -1;
      announce("");
    }

    function currentLinks() {
      return list.querySelectorAll("a");
    }

    function runSearch() {
      var query = normalize(input.value).trim();
      if (query.length < 2) { close(); return; }
      var run = ++searchRun;
      loadIndex(base).then(function (items) {
        if (run !== searchRun || normalize(input.value).trim() !== query) return;
        var results = rank(items, query);
        render(list, results, base);
        active = -1;
        announce(results.length
          ? results.length + (results.length === 1 ? " result" : " results") + " for " + query
          : "No results for " + query);
      });
    }

    input.addEventListener("input", runSearch);
    input.addEventListener("focus", function () {
      if (!restoringFocus && input.value.trim().length >= 2) runSearch();
    });

    form.addEventListener("keydown", function (event) {
      var links = currentLinks();
      if (event.key === "Escape") {
        event.preventDefault();
        restoringFocus = true;
        input.focus();
        restoringFocus = false;
        close();
        return;
      }
      if (list.hidden || !links.length) return;
      if (event.key === "ArrowDown" || event.key === "ArrowUp") {
        event.preventDefault();
        active = Array.prototype.indexOf.call(links, doc.activeElement);
        active += event.key === "ArrowDown" ? 1 : -1;
        if (active < 0) active = links.length - 1;
        if (active >= links.length) active = 0;
        Array.prototype.forEach.call(links, function (link, i) {
          link.classList.toggle("is-active", i === active);
        });
        links[active].focus();
      }
    });

    form.addEventListener("submit", function (event) {
      event.preventDefault();
      var links = currentLinks();
      if (links.length) links[0].click();
    });

    doc.addEventListener("click", function (event) {
      if (!form.contains(event.target)) close();
    });

    doc.addEventListener("keydown", function (event) {
      if (event.key === "/" && doc.activeElement !== input &&
          ["INPUT", "TEXTAREA", "SELECT"].indexOf((doc.activeElement || {}).tagName) === -1) {
        event.preventDefault();
        input.focus();
        input.select();
      }
    });
  }

  function init() {
    /* Order matters: the table of contents reads heading text, and addHeadingAnchors
       appends a "#" link inside each heading. */
    setupTheme();
    buildToc();
    addHeadingAnchors();
    addCopyButtons();
    setupSearch();
  }

  if (doc.readyState === "loading") {
    doc.addEventListener("DOMContentLoaded", init);
  } else {
    init();
  }
})(window);
