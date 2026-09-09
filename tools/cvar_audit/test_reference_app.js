"use strict";

const assert = require("node:assert/strict");
const catalog = require("../../assets/js/reference-app.js");
const generatedEntries = require("../../assets/data/catalog.json").map(catalog.prepareEntry);
const metadata = require("../../assets/data/reference-meta.json");

const cvar = catalog.prepareEntry({
  kind: "cvar",
  name: "r_bloom",
  summary: "Enable bloom post-processing",
  category: "Graphics & rendering",
  module: "renderer",
  renderer: ["rd-rend2", "rd-vulkan"],
  flags: ["CVAR_ARCHIVE"],
  network: "client-only",
  origin: "rend2",
  xdocs: true,
  menu: false,
  values: [{ value: "1", meaning: "Enable bloom" }]
});
const command = catalog.prepareEntry({
  kind: "command",
  name: "download",
  summary: "Download a file from the server",
  category: "Files & downloads",
  module: "engine-client",
  renderer: [],
  network: "needs-server-support",
  origin: "taystjk",
  xdocs: false,
  menu: true,
  syntax: "download <path>"
});

function state(overrides = {}) {
  return Object.assign({
    kind: "all",
    origin: "",
    module: "",
    category: "",
    renderer: "",
    status: "",
    network: "",
    coverage: "",
    flag: "",
    query: "",
    tokens: [],
    sort: "relevance"
  }, overrides);
}

assert.equal(catalog.entryMatches(cvar, state({ query: "bloom", tokens: ["bloom"] })), true);
assert.equal(catalog.entryMatches(cvar, state({ query: "enable 1", tokens: ["enable", "1"] })), true);
assert.equal(catalog.entryMatches(cvar, state({ origin: "vulkan" })), false);
assert.equal(catalog.entryMatches(cvar, state({ origin: ["japro", "rend2"] })), true);
assert.equal(catalog.entryMatches(command, state({ origin: ["japro", "rend2"] })), false);
assert.equal(catalog.entryMatches(cvar, state({ renderer: "renderer-specific" })), true);
assert.equal(catalog.entryMatches(command, state({ renderer: ["rd-vulkan", "none"] })), true);
assert.equal(catalog.entryMatches(command, state({ renderer: "none" })), true);
assert.equal(catalog.entryMatches(command, state({ kind: "cvar" })), false);
assert.equal(catalog.entryMatches(cvar, state({ flag: "CVAR_ARCHIVE" })), true);
assert.equal(catalog.entryMatches(cvar, state({ category: "Graphics & rendering" })), true);
assert.equal(catalog.entryMatches(cvar, state({ coverage: "xdocs" })), true);
assert.equal(catalog.entryMatches(cvar, state({ coverage: "menu" })), false);
assert.equal(catalog.entryMatches(command, state({ coverage: ["xdocs", "menu"] })), true);
assert.deepEqual(catalog.sortEntries([command, cvar], state({ query: "r_bloom", tokens: ["r_bloom"] }))[0], cvar);
assert.equal(generatedEntries.filter((entry) => catalog.entryMatches(entry, state({ kind: "cvar" }))).length, metadata.counts.cvars);
assert.equal(generatedEntries.filter((entry) => catalog.entryMatches(entry, state({ kind: "command" }))).length, metadata.counts.commands);
const japroEntries = generatedEntries.filter((entry) => catalog.entryMatches(entry, state({ origin: "japro" })));
assert.ok(japroEntries.length > 0 && japroEntries.every((entry) => entry.origin === "japro"));
const multiOriginEntries = generatedEntries.filter((entry) => catalog.entryMatches(entry, state({ origin: ["japro", "taystjk"] })));
assert.ok(multiOriginEntries.length > japroEntries.length && multiOriginEntries.every((entry) => ["japro", "taystjk"].includes(entry.origin)));
const vulkanCvars = generatedEntries.filter((entry) => catalog.entryMatches(entry, state({ kind: "cvar", renderer: "rd-vulkan" })));
assert.ok(vulkanCvars.length > 0 && vulkanCvars.every((entry) => entry.kind === "cvar" && entry.renderer.includes("rd-vulkan")));
const cameraSearch = state({ query: "cg_camerafps", tokens: ["cg_camerafps"] });
assert.equal(catalog.sortEntries(generatedEntries.filter((entry) => catalog.entryMatches(entry, cameraSearch)), cameraSearch)[0].name, "cg_cameraFPS");

assert.equal(catalog.detectPlatform("Win32"), "windows");
assert.equal(catalog.detectPlatform("MacIntel"), "macos");
assert.equal(catalog.detectPlatform("X11; Linux x86_64"), "linux");
assert.equal(catalog.detectPlatform("unknown"), "windows");
assert.equal(catalog.choosePlatform("linux", "windows", "MacIntel"), "linux");
assert.equal(catalog.choosePlatform("", "macos", "Win32"), "macos");
assert.equal(catalog.choosePlatform("invalid", "invalid", "Linux x86_64"), "linux");
assert.equal(catalog.choosePlatform("Windows", "", "Linux x86_64"), "windows");

console.log("reference app filtering is valid");
