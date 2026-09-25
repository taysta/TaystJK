"use strict";

// Run the real browser scripts with a small event-bubbling DOM fixture.
const assert = require("assert");
const fs = require("fs");
const path = require("path");
const vm = require("vm");
const source = name => fs.readFileSync(path.join(__dirname, "../../assets/js", name), "utf8");

function environment(href) {
  const doc = { readyState: "complete", querySelector: () => null, querySelectorAll: () => [],
    addEventListener() {}, getElementById: () => null };
  const listeners = {};
  const window = { document: doc, navigator: { platform: "MacIntel" }, location: new URL(href),
    URL, URLSearchParams, setTimeout, localStorage: { getItem: () => null, setItem() {} },
    history: { replaceState(a, b, url) { window.location = new URL(url, window.location); } },
    addEventListener(name, fn) { (listeners[name] ||= []).push(fn); },
    dispatch(name) { for (const fn of listeners[name] || []) fn(); } };
  window.window = window;
  return { window, doc };
}

function node(doc, tag, parent = null) {
  const listeners = {};
  const classes = new Set();
  return { tagName: tag.toUpperCase(), parent, dataset: {}, attrs: {}, children: [],
    classList: { add(x) { classes.add(x); }, remove(x) { classes.delete(x); },
      toggle(x, on) { if (on) classes.add(x); else classes.delete(x); } },
    setAttribute(k, v) { this.attrs[k] = v; },
    addEventListener(name, fn) { (listeners[name] ||= []).push(fn); },
    emit(name, event) { for (const fn of listeners[name] || []) fn(event); },
    key(key) {
      const event = { key, target: this, defaultPrevented: false,
        preventDefault() { this.defaultPrevented = true; } };
      for (let n = this; n; n = n.parent) n.emit("keydown", event);
      return event;
    },
    focus() { doc.activeElement = this; this.emit("focus", {}); },
    blur() { doc.activeElement = null; },
    contains(target) { for (let n = target; n; n = n.parent) if (n === this) return true; return false; },
    appendChild(child) { child.parent = this; this.children.push(child); },
    closest() { return null; }, querySelector() { return null; },
    scrollIntoView() { this.scrolled = true; }
  };
}

function testPanelLinks(type, names) {
  const { window, doc } = environment("https://example.test/TaystJK/install/?" + type + "=" + names[0] + "#target");
  const root = node(doc, "section");
  const choices = names.map(name => {
    const choice = node(doc, "button", root); choice.dataset[type + "Choice"] = name; return choice;
  });
  const panels = names.map(name => {
    const panel = node(doc, "section", root); panel.dataset[type + "Panel"] = name; return panel;
  });
  const target = node(doc, "h2", panels[1]);
  doc.getElementById = id => id === "target" ? target : id === "first" ? panels[0] : null;
  root.querySelectorAll = selector => selector.includes("choice") ? choices : panels;
  doc.querySelectorAll = selector => selector === "[data-" + type + "-guide]" ? [root] : [];
  vm.runInNewContext(source("reference-app.js"), window);
  assert.strictEqual(panels[1].hidden, false, type + " fragment overrides initial query/preference");
  assert.strictEqual(choices[1].attrs["aria-selected"], "true");
  assert.ok(target.scrolled, "scroll happens after revealing the target");
  choices[0].emit("click", {});
  assert.strictEqual(window.location.hash, "", "manual selection clears a fragment in the hidden tab");
  assert.strictEqual(window.location.searchParams.get(type), names[0]);
  assert.strictEqual(panels[0].hidden, false);
  window.location.hash = "#target";
  window.dispatch("hashchange");
  assert.strictEqual(panels[1].hidden, false);
  window.location.hash = "#first";
  window.dispatch("hashchange");
  assert.strictEqual(panels[0].hidden, false, "same-page links reveal another panel");
  window.location.hash = "#%broken";
  window.dispatch("hashchange"); // malformed external links must not break the selector
  assert.strictEqual(panels[0].hidden, false);
}

async function testSearchKeys() {
  const { window, doc } = environment("https://example.test/TaystJK/");
  const form = node(doc, "form");
  const input = node(doc, "input", form);
  const list = node(doc, "ul", form);
  const status = node(doc, "span", form);
  let links = [];
  Object.defineProperty(list, "innerHTML", { set(html) {
    links = [...html.matchAll(/<a /g)].map(() => node(doc, "a", list));
  } });
  list.querySelectorAll = () => links;
  list.hidden = true;
  form.querySelector = selector => ({ input, ".search-results": list, ".search-status": status })[selector];
  doc.querySelector = selector => selector === ".site-search" ? form : null;
  window.fetch = async () => ({ ok: true, json: async () => [
    { t: "Windows", u: "/install/#windows", k: "section" },
    { t: "Windows builds", u: "/development/compiling/#windows", k: "section" }
  ] });
  vm.runInNewContext(source("site-search.js"), window);
  input.value = "windows";
  input.focus();
  await new Promise(setImmediate);
  input.key("ArrowDown");
  assert.strictEqual(doc.activeElement, links[0]);
  links[0].key("ArrowDown");
  assert.strictEqual(doc.activeElement, links[1], "second arrow advances from a focused link");
  links[1].key("ArrowDown");
  assert.strictEqual(doc.activeElement, links[0], "arrows wrap");
  links[0].key("ArrowUp");
  assert.strictEqual(doc.activeElement, links[1], "up wraps back");
  assert.strictEqual(links[1].key("Enter").defaultPrevented, false, "Enter retains native link activation");
  links[1].key("Escape");
  await new Promise(setImmediate);
  assert.strictEqual(list.hidden, true, "Escape closes without focus reopening the list");
  assert.strictEqual(doc.activeElement, input, "Escape restores input focus");
  input.emit("input", {});
  input.key("Escape");
  await new Promise(setImmediate);
  assert.strictEqual(list.hidden, true, "an outstanding search cannot reopen a dismissed list");
}

async function testCopiedHeadingQuery() {
  const { window, doc } = environment("https://example.test/TaystJK/install/?platform=windows#old");
  const article = node(doc, "article");
  const heading = node(doc, "h2", article);
  heading.id = "windows"; heading.textContent = "Windows";
  article.querySelectorAll = selector => selector.startsWith("h2") ? [heading] : [];
  doc.querySelector = selector => selector === ".page-content" ? article : null;
  doc.createElement = tag => node(doc, tag);
  window.setTimeout = () => {};
  let copied;
  window.navigator.clipboard = { writeText: async text => { copied = text; } };
  vm.runInNewContext(source("site-search.js"), window);
  heading.children[0].emit("click", { preventDefault() {} });
  await new Promise(setImmediate);
  assert.strictEqual(copied, "https://example.test/TaystJK/install/?platform=windows#windows");
}

(async () => {
  testPanelLinks("platform", ["macos", "windows", "linux"]);
  testPanelLinks("baseline", ["eternaljk", "openjk", "basejka"]);
  testPanelLinks("hosting", ["docker", "dedicated"]);
  await testSearchKeys();
  await testCopiedHeadingQuery();
  console.log("Tab links, search keyboard navigation, and copied headings are valid");
})().catch(error => { console.error(error); process.exitCode = 1; });
