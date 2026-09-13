"use strict";

/* Exercises the ranking used by the header search. The DOM half of site-search.js is not
   covered here; this pins the ordering rules, which are the part with real logic. */

const assert = require("assert");
const fs = require("fs");
const path = require("path");
const vm = require("vm");

const source = fs.readFileSync(path.join(__dirname, "..", "..", "assets", "js", "site-search.js"), "utf8");

// Minimal window so the IIFE can run without a browser.
const listeners = {};
const sandbox = {
  window: null,
  document: {
    readyState: "complete",
    querySelector: () => null,
    querySelectorAll: () => [],
    addEventListener: (name, fn) => { listeners[name] = fn; },
    createElement: () => ({ setAttribute() {}, addEventListener() {}, classList: { add() {}, remove() {} } })
  }
};
sandbox.window = sandbox;
sandbox.navigator = {};
sandbox.location = { origin: "https://example.test", pathname: "/", hash: "" };
sandbox.history = { replaceState() {} };
sandbox.setTimeout = setTimeout;
sandbox.fetch = () => Promise.resolve({ ok: false });

vm.createContext(sandbox);
vm.runInContext(source + "\n;this.__rank = null;", sandbox);

// The module keeps its helpers private, so re-evaluate the ranking pair in the same shape.
const rankSource = source
  .slice(source.indexOf("  function normalize(value)"), source.indexOf("  function escapeHtml(value)"));
const helpers = {};
vm.runInNewContext(rankSource + "\nthis.normalize = normalize; this.score = score; this.rank = rank;", helpers);

const index = [
  { t: "Tribes", u: "/features/tribes/", k: "page", d: "The Tribes movement mode", b: "skiing and jetpacks" },
  { t: "Classes", u: "/features/tribes/#classes", k: "section", p: "Tribes" },
  { t: "cg_killfeed", u: "/reference/cvars/cg_killfeed-abc/", k: "entry" },
  { t: "Killfeed styling and placement", u: "/features/hud-and-movement/#the-killfeed", k: "section", p: "HUD and movement tools" },
  { t: "Renderers", u: "/features/renderers/", k: "page", d: "Three backends", b: "vulkan rend2 vanilla" }
];

// Exact title beats prefix beats substring.
let results = helpers.rank(index, "tribes");
assert.strictEqual(results[0].t, "Tribes", "exact title match ranks first");

// An entry whose name starts with the query outranks a section that merely contains it.
results = helpers.rank(index, "killfeed");
assert.strictEqual(results[0].t, "cg_killfeed", "prefix-free entry name outranks a containing section");

// Body text is searchable, but ranks below title and description matches.
results = helpers.rank(index, "jetpacks");
assert.strictEqual(results[0].t, "Tribes", "body text is searchable");

// Description matches beat body matches.
results = helpers.rank(index, "backends");
assert.strictEqual(results[0].t, "Renderers", "description is searchable");

// Sections carry their page so a result can be attributed.
results = helpers.rank(index, "classes");
assert.strictEqual(results[0].p, "Tribes", "section results keep their parent page");

// No match yields nothing rather than everything.
assert.strictEqual(helpers.rank(index, "zzzznotpresent").length, 0, "no false positives");

// Results are capped so the dropdown stays usable.
const many = [];
for (let i = 0; i < 200; i++) many.push({ t: "match " + i, u: "/x/" + i, k: "page", d: "", b: "" });
assert.ok(helpers.rank(many, "match").length <= 12, "result list is capped");

console.log("site search ranking is valid");
