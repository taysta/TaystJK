"use strict";

/* Exercises the on-this-page navigation built by site-search.js.
 *
 * The rule worth pinning is that headings inside a tab panel are skipped: only one panel
 * is visible at a time, so a link into a hidden one goes nowhere the reader can see.
 * install.md, compiling.md and debugging.md all have that shape.
 *
 * No jsdom -- the other JS tests here hand-roll what they need, so this does too. */

const assert = require("assert");
const fs = require("fs");
const path = require("path");
const vm = require("vm");

function makeNode(tag) {
  return {
    tagName: tag.toUpperCase(),
    children: [],
    className: "",
    id: "",
    textContent: "",
    attrs: {},
    parent: null,
    setAttribute(k, v) { this.attrs[k] = v; },
    appendChild(child) { child.parent = this; this.children.push(child); return child; },
    insertBefore(child, ref) {
      child.parent = this;
      const i = this.children.indexOf(ref);
      this.children.splice(i === -1 ? this.children.length : i, 0, child);
      return child;
    },
    get firstChild() { return this.children[0] || null; },
    get nextSibling() {
      if (!this.parent) return null;
      const i = this.parent.children.indexOf(this);
      return this.parent.children[i + 1] || null;
    }
  };
}

/** heading stubs: `panel` marks one as living inside a tab panel */
function heading(tag, id, text, panel) {
  const node = makeNode(tag);
  node.id = id;
  node.textContent = text;
  node.closest = (sel) =>
    panel && sel.indexOf("panel") !== -1 ? { tag: "panel" } : null;
  return node;
}

function run(headings) {
  const main = makeNode("main");
  main.className = "site-main";
  main.classList = { add() {}, toggle() {} };
  main.dataset = {};

  const article = makeNode("article");
  main.appendChild(article);

  const doc = {
    readyState: "complete",
    querySelector(sel) {
      if (sel === ".page-content[data-toc]") return article;
      if (sel === ".site-main") return main;
      return null;
    },
    querySelectorAll: () => [],
    addEventListener() {},
    createElement(tag) {
      const n = makeNode(tag);
      n.dataset = {};
      n.classList = { add() {}, toggle() {} };
      n.addEventListener = () => {};
      Object.defineProperty(n, "innerHTML", { set(v) { n._html = v; }, get() { return n._html || ""; } });
      return n;
    }
  };
  article.querySelectorAll = () => headings;

  const sandbox = {
    document: doc,
    navigator: {},
    localStorage: { getItem: () => null, setItem() {} },
    location: { origin: "https://x.test", pathname: "/", search: "", hash: "" },
    history: { replaceState() {} },
    setTimeout,
    fetch: () => Promise.resolve({ ok: false })
  };
  sandbox.window = sandbox;
  vm.createContext(sandbox);
  vm.runInContext(
    fs.readFileSync(path.join(__dirname, "..", "..", "assets", "js", "site-search.js"), "utf8"),
    sandbox
  );

  return main.children.find((c) => c.className === "page-toc-rail") || null;
}

function titles(rail) {
  const nav = rail.children.find((c) => c.className === "page-toc");
  const list = nav.children.find((c) => c.tagName === "UL");
  return list.children.map((li) => ({
    text: li.children[0].textContent,
    sub: li.className === "page-toc-sub"
  }));
}

// Panel headings are skipped; everything else is listed, in order.
let toc = run([
  heading("h2", "before-you-start", "Before you start"),
  heading("h2", "install-for-your-platform", "Install for your platform"),
  heading("h2", "windows", "Windows", true),
  heading("h3", "install-prerequisites", "Install prerequisites", true),
  heading("h2", "linux", "Linux", true),
  heading("h2", "first-launch-checks", "First-launch checks"),
  heading("h3", "when-to-use-vm-legacy", "When to use vm_legacy")
]);
assert.ok(toc, "a contents rail is built");
assert.ok(toc.children.some((c) => c.className === "page-toc-toggle"), "it has an open/close toggle");
assert.deepStrictEqual(titles(toc).map((t) => t.text), [
  "Before you start", "Install for your platform", "First-launch checks", "When to use vm_legacy"
], "headings inside tab panels are skipped");

// h3 entries are marked so they can be indented.
assert.deepStrictEqual(titles(toc).map((t) => t.sub), [false, false, false, true], "h3s are marked as sub-entries");

// It is the first thing in the main column, so it reads as a left rail.
assert.strictEqual(toc.parent.children[0].className, "page-toc-rail", "rail comes before the article");

// Too few headings is not worth a contents block.
assert.strictEqual(run([
  heading("h2", "a", "A"),
  heading("h2", "b", "B")
]), null, "under three headings, no contents block");

// A page that is all panels gets nothing rather than an empty block.
assert.strictEqual(run([
  heading("h2", "w", "Windows", true),
  heading("h2", "l", "Linux", true),
  heading("h2", "m", "macOS", true)
]), null, "all-panel headings produce no contents block");

console.log("on-this-page navigation is valid");
