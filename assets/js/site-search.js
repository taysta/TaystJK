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
      link.setAttribute("aria-label", "Link to this section");
      link.innerHTML = "<span aria-hidden=\"true\">#</span>";

      link.addEventListener("click", function (event) {
        if (event.metaKey || event.ctrlKey || event.shiftKey || !global.navigator.clipboard) return;
        event.preventDefault();
        var url = global.location.origin + global.location.pathname + "#" + heading.id;
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
        return !heading.closest("[data-platform-panel], [data-baseline-panel]");
      }
    );

    if (headings.length < 3) return;

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
    if (!input || !list) return;

    var base = form.dataset.baseurl || "";
    var active = -1;

    function close() {
      list.hidden = true;
      active = -1;
    }

    function currentLinks() {
      return list.querySelectorAll("a");
    }

    function runSearch() {
      var query = normalize(input.value).trim();
      if (query.length < 2) { close(); return; }
      loadIndex(base).then(function (items) {
        if (normalize(input.value).trim() !== query) return;
        render(list, rank(items, query), base);
        active = -1;
      });
    }

    input.addEventListener("input", runSearch);
    input.addEventListener("focus", function () { if (input.value.trim().length >= 2) runSearch(); });

    input.addEventListener("keydown", function (event) {
      var links = currentLinks();
      if (event.key === "Escape") { close(); input.blur(); return; }
      if (!links.length) return;
      if (event.key === "ArrowDown" || event.key === "ArrowUp") {
        event.preventDefault();
        active += event.key === "ArrowDown" ? 1 : -1;
        if (active < 0) active = links.length - 1;
        if (active >= links.length) active = 0;
        Array.prototype.forEach.call(links, function (link, i) {
          link.classList.toggle("is-active", i === active);
        });
        links[active].focus();
      } else if (event.key === "Enter" && active >= 0) {
        event.preventDefault();
        links[active].click();
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
    buildToc();
    addHeadingAnchors();
    setupSearch();
  }

  if (doc.readyState === "loading") {
    doc.addEventListener("DOMContentLoaded", init);
  } else {
    init();
  }
})(window);
