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
    addHeadingAnchors();
    setupSearch();
  }

  if (doc.readyState === "loading") {
    doc.addEventListener("DOMContentLoaded", init);
  } else {
    init();
  }
})(window);
