"use strict";

// Generates every target, preset, run method and mode combination the server config generator
// can produce and checks each bundle against the rules in its design: every name exists for its
// target, nothing engine-managed is written, server settings stay out of gameplay files, the
// baseline resets whatever a mode changes, and the map line comes last.

const assert = require("node:assert/strict");
const generator = require("../../assets/js/config-generator.js");
const data = require("../../assets/data/config-generator.json");

const COMMANDS = new Set(["exec", "map", "map_restart", "vstr", "kick", "addbot", "gametype", "resetscores", "startingitems"]);
const SECRETS = { rcon: "rcon-secret-1", password: "join-secret-2", fullAdmin: "full-secret-3", juniorAdmin: "junior-secret-4" };

function statements(text) {
  return text.split("\n").map((line, index) => ({ line, number: index + 1 }))
    .filter(({ line }) => line.trim() && !line.trim().startsWith("//"));
}

function parseSet(line) {
  const match = line.match(/^(set|seta) (\S+) "([^"]*)"( \/\/ .*)?$/);
  return match ? { keyword: match[1], name: match[2], value: match[3] } : null;
}

function cvar(name) {
  return data.cvars[name.toLowerCase()];
}

function isItem(name) {
  return data.items.some((item) => `disable_${item}`.toLowerCase() === name.toLowerCase());
}

function scope(target, name) {
  return generator.scopeOf(data, target, name);
}

function checkBundle(state, result, label) {
  const files = new Map(result.files.map((file) => [file.name, file.text]));
  const target = state.target;
  const where = (file, number) => `${label}: ${file}:${number}`;

  for (const [name, text] of files) {
    if (name === "README.txt") continue;
    assert.ok(text.endsWith("\n") && !text.endsWith("\n\n"), `${label}: ${name} ends with one newline`);
    const seen = new Set();
    for (const { line, number } of statements(text)) {
      assert.ok(/^[\x20-\x7e]*$/.test(line), `${where(name, number)} is printable ASCII`);
      const set = parseSet(line);
      if (set) {
        const key = set.name.toLowerCase();
        if (name === "votes.cfg") continue; // vote options are user cvars holding commands, checked below
        if (name === "server.cfg" && /^m\d+$/.test(set.name)) continue; // map rotation entries
        assert.ok(generator.available(data, target, set.name), `${where(name, number)}: ${set.name} is not available for ${target}`);
        assert.ok(!(cvar(set.name) || {}).em, `${where(name, number)}: ${set.name} is engine-managed`);
        assert.ok(!seen.has(key), `${where(name, number)}: ${set.name} is set twice`);
        seen.add(key);
        if (name !== "server.cfg" && name !== "bans.cfg") {
          assert.equal(scope(target, set.name), "default", `${where(name, number)}: ${set.name} is a server setting outside server.cfg`);
        }
        continue;
      }
      const word = line.trim().split(/\s+/)[0];
      if (target === "other" && name === "server.cfg" && state.extra.split("\n").includes(line)) continue;
      assert.ok(COMMANDS.has(word.toLowerCase()), `${where(name, number)}: unexpected line ${JSON.stringify(line)}`);
      if (word === "exec") {
        const file = line.trim().split(/\s+/)[1] + ".cfg";
        assert.ok(files.has(file), `${where(name, number)}: exec ${file}, which the bundle does not include`);
      }
    }
  }

  // server.cfg: passwords on set lines, downloads explicit, the map (or the boot mode) last.
  const server = statements(files.get("server.cfg")).map((s) => s.line);
  assert.ok(server.includes(`set rconpassword "${SECRETS.rcon}"`), `${label}: rconpassword on a set line`);
  for (const secret of ["g_password", "g_fullAdminPass", "g_juniorAdminPass"]) {
    for (const line of server) assert.ok(!line.startsWith(`seta ${secret} `), `${label}: ${secret} must not be archived`);
  }
  assert.ok(server.some((l) => /^seta sv_allowDownload "[01]"$/.test(l)), `${label}: sv_allowDownload written explicitly`);
  assert.ok(server.some((l) => /^seta sv_httpDownloads "[01]"$/.test(l)), `${label}: sv_httpDownloads written explicitly`);
  const bootIndex = server.findIndex((l) => /^(map |vstr m1$)/.test(l) || (target === "base" && state.bootMode && l === `exec ${state.bootMode}`));
  assert.ok(bootIndex !== -1, `${label}: server.cfg loads a map`);
  const afterBoot = server.slice(bootIndex + 1);
  if (target === "japro" && state.bootMode) assert.deepEqual(afterBoot, [`exec ${state.bootMode}`], `${label}: only the boot mode follows the map`);
  else assert.deepEqual(afterBoot, [], `${label}: nothing follows the map line`);
  if (TARGET_HAS_DEFAULT(target)) {
    const execDefault = server.indexOf("exec default");
    assert.ok(execDefault !== -1 && execDefault < bootIndex, `${label}: exec default runs before the first map`);
  }
  if (state.bans) assert.ok(server.includes("exec bans"), `${label}: exec bans`);
  if (state.rotation) {
    const count = state.maps.length;
    for (let i = 1; i <= count; i++) {
      const next = (i % count) + 1;
      assert.ok(server.includes(`set m${i} "map ${state.maps[i - 1]}; set nextmap vstr m${next}"`), `${label}: rotation entry m${i}`);
    }
  }

  // bans.cfg keeps saved addip bans unless the host lists addresses.
  if (files.has("bans.cfg")) {
    const bans = files.get("bans.cfg");
    if (state.banList) assert.match(bans, /^seta g_banIPs "[\d. ]+ "$/m, `${label}: g_banIPs set from the list`);
    else assert.match(bans, /^\/\/seta g_banIPs ""$/m, `${label}: g_banIPs left commented`);
  }

  // The baseline resets every cvar a mode file changes.
  if (files.has("default.cfg")) {
    const baseline = new Set(statements(files.get("default.cfg")).map((s) => parseSet(s.line)).filter(Boolean).map((s) => s.name.toLowerCase()));
    for (const [name, text] of files) {
      if (["server.cfg", "default.cfg", "bans.cfg", "votes.cfg", "README.txt"].includes(name)) continue;
      for (const { line } of statements(text)) {
        const set = parseSet(line);
        if (set) assert.ok(baseline.has(set.name.toLowerCase()), `${label}: ${name} changes ${set.name}, which default.cfg never resets`);
      }
    }
    assert.ok(!/^map /m.test(files.get("default.cfg")), `${label}: default.cfg loads no map`);
  }

  // Vote options: only for ticked modes and add-ons, each running known cvars and commands.
  if (files.has("votes.cfg")) {
    assert.ok(server.includes("exec votes"), `${label}: server.cfg runs exec votes`);
    const allModes = generator.modesFor(data, "japro").map((m) => m.id).concat(generator.addonsFor(data, "japro").map((a) => a.id));
    for (const { line } of statements(files.get("votes.cfg"))) {
      const set = parseSet(line);
      assert.ok(set && set.keyword === "set", `${label}: vote line ${line}`);
      if (allModes.includes(set.name)) {
        assert.ok(state.modes.includes(set.name) || state.addons.includes(set.name), `${label}: vote option for unticked ${set.name}`);
      }
      for (const part of set.value.split(";")) {
        const word = part.trim().split(/\s+/)[0];
        if (word === "exec") {
          const file = part.trim().split(/\s+/)[1] + ".cfg";
          assert.ok(files.has(file), `${label}: vote ${set.name} runs ${file}, which the bundle does not include`);
        } else if (!COMMANDS.has(word.toLowerCase())) {
          assert.ok(generator.available(data, "japro", word), `${label}: vote ${set.name} sets unknown ${word}`);
        }
      }
    }
    // The baseline puts back everything a vote option changes, so the default vote and every mode undo it.
    const baselineNames = new Set(statements(files.get("default.cfg")).map((s) => parseSet(s.line)).filter(Boolean).map((s) => s.name.toLowerCase()));
    for (const { line } of statements(files.get("votes.cfg"))) {
      for (const part of parseSet(line).value.split(";")) {
        const word = part.trim().split(/\s+/)[0].toLowerCase();
        const cvarName = word === "startingitems" ? "g_startingitems" : (cvar(word) || isItem(word)) ? word : null;
        if (cvarName) assert.ok(baselineNames.has(cvarName), `${label}: a vote changes ${cvarName}, which default.cfg never resets`);
      }
    }
    const allow = statements(files.get("default.cfg")).map((s) => parseSet(s.line)).find((s) => s && s.name === "g_allowVote");
    assert.ok(allow && Math.floor(Number(allow.value) / 4096) % 2 === 1, `${label}: g_allowVote allows vstr when there are vote options`);
  }

  // No module needs vm_legacy: the engine falls back to the legacy interface by itself.
  for (const [name, text] of files) assert.ok(!text.includes("vm_legacy 1"), `${label}: ${name} sets vm_legacy`);
  const readme = files.get("README.txt");
  const runs32 = /^  - TJK_ARCH=i386$/m.test(readme) || /^  \.\/taystjkded\.i386 /m.test(readme);
  assert.equal(runs32, state.target !== "japro" && state.arch32, `${label}: README picks the server matching the module's architecture`);

  // A dedicated server has no Docker run.sh saving its console, so it keeps its own log.
  if (state.target === "japro" && state.run === "dedicated") {
    assert.ok(!files.get("server.cfg").includes("run.sh"), `${label}: dedicated server.cfg mentions Docker's run.sh`);
    assert.match(files.get("server.cfg"), /^seta logfile "1"/m, `${label}: dedicated server.cfg writes a console log`);
  }
  if (state.target !== "japro") assert.ok(readme.includes("serverinfo shows the mod's gamename"), `${label}: README explains the module fallback`);
  // Only Windows unpacks a library from a PK3, and the Docker image runs Linux.
  assert.equal(readme.includes("com_unpackLibraries 1"), state.target !== "japro" && state.run !== "docker", `${label}: README mentions PK3 unpacking only for another mod on a dedicated server`);

  // Passwords appear in server.cfg only.
  for (const [name, text] of files) {
    if (name === "server.cfg") continue;
    for (const secret of Object.values(SECRETS)) assert.ok(!text.includes(secret), `${label}: a password leaked into ${name}`);
  }
}

function TARGET_HAS_DEFAULT(target) {
  return generator.targets[target].defaultCfg;
}

function readZip(bytes) {
  const view = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  const end = bytes.length - 22;
  assert.equal(view.getUint32(end, true), 0x06054b50, "zip end record");
  const count = view.getUint16(end + 10, true);
  let offset = view.getUint32(end + 16, true);
  const entries = [];
  for (let i = 0; i < count; i++) {
    assert.equal(view.getUint32(offset, true), 0x02014b50, "zip central header");
    const crc = view.getUint32(offset + 16, true);
    const size = view.getUint32(offset + 20, true);
    const nameLength = view.getUint16(offset + 28, true);
    const local = view.getUint32(offset + 42, true);
    const name = Buffer.from(bytes.slice(offset + 46, offset + 46 + nameLength)).toString("latin1");
    const localNameLength = view.getUint16(local + 26, true);
    const body = bytes.slice(local + 30 + localNameLength, local + 30 + localNameLength + size);
    assert.equal(generator.crc32(body), crc, `zip CRC of ${name}`);
    entries.push({ name, text: Buffer.from(body).toString("latin1") });
    offset += 46 + nameLength;
  }
  return entries;
}

function readShell(script) {
  const files = [];
  const lines = script.split("\n");
  for (let i = 0; i < lines.length; i++) {
    const match = lines[i].match(/^cat > '([^']+)' <<'(\w+)'$/);
    if (!match) continue;
    const body = [];
    for (i++; lines[i] !== match[2]; i++) body.push(lines[i]);
    files.push({ name: match[1], text: body.join("\n") + "\n" });
  }
  return files;
}

function modeSets(target) {
  const modes = generator.modesFor(data, target).map((m) => m.id);
  const addons = generator.addonsFor(data, target).map((a) => a.id);
  const sets = [{ modes: [], addons: [] }, { modes, addons }];
  for (const mode of modes) sets.push({ modes: [mode], addons: [] });
  for (const addon of addons) sets.push({ modes: [], addons: [addon] });
  return sets;
}

let bundles = 0;
for (const target of Object.keys(generator.targets)) {
  for (const preset of data.presets[target]) {
    for (const run of ["docker", "dedicated"]) {
      for (const choice of modeSets(target)) {
        for (const variant of [0, 1, 2]) {
          const raw = generator.defaultState(data, target);
          raw.preset = preset.id;
          generator.applyPresetFlow(data, raw);
          Object.assign(raw, { run, modes: choice.modes, addons: choice.addons });
          if (variant === 1) {
            Object.assign(raw, {
              listed: false, downloads: false, bans: false, votes: false, arch32: true,
              maps: ["mp/ffa1", "mp/ffa3", "ffa_custom"], rotation: true,
              bootMode: choice.modes[0] || "", motd: "Hi \"there\"\nsecond line", hostname: "^1Red ^7Server"
            });
          }
          if (variant === 2) {
            Object.assign(raw, {
              banList: "1.2.3.4 5.6.7 not-an-ip", voteGroups: [], allowVote: 0,
              tune: { g_speed: "300", sv_fps: "30", g_weaponDisable: "0", disable_item_seeker: "0", sv_cheats: "1", g_needpass: "1", sv_hostname: "sneaky", bogus_cvar: "1" },
              extra: target === "other" ? "set jp_fixRoll 1\nseta jp_allowflipkick 1" : ""
            });
          }
          const state = generator.normalizeState(data, raw);
          const label = `${target}/${preset.id}/${run}/${choice.modes.concat(choice.addons).join("+") || "no modes"}/v${variant}`;
          const result = generator.generate(data, state, SECRETS);
          checkBundle(state, result, label);
          assert.deepEqual(generator.generate(data, state, SECRETS), result, `${label}: deterministic`);
          assert.deepEqual(generator.normalizeState(data, state), state, `${label}: normalizeState is idempotent`);
          bundles++;
        }
      }
    }
  }
}

// Zip and paste-in command carry exactly the generated files.
{
  const state = generator.normalizeState(data, Object.assign(generator.defaultState(data, "japro"), { modes: ["saberonly", "tribesctf", "midair"], addons: ["noboons"] }));
  const result = generator.generate(data, state, SECRETS);
  assert.deepEqual(readZip(generator.zip(result.files)), result.files.map((f) => ({ name: f.name, text: f.text })));
  assert.deepEqual(readShell(generator.shellScript(result)), result.files.map((f) => ({ name: f.name, text: f.text })));
  const names = result.files.map((f) => f.name);
  for (const dependency of ["tribesbase.cfg", "tribesctf.cfg", "nopickups.cfg", "noboons.cfg"]) assert.ok(names.includes(dependency), `includes ${dependency}`);
  assert.equal(result.dir, "homepath/taystjk");
}

// Share links and stored state never hold passwords, and round-trip every choice.
{
  const state = generator.normalizeState(data, Object.assign(generator.defaultState(data, "base"), { modes: ["ffa", "duel"], bootMode: "duel", tune: { g_speed: "280" } }));
  const encoded = generator.encodeShare(state);
  assert.deepEqual(generator.normalizeState(data, generator.decodeShare(encoded)), state);
  const withSecrets = Object.assign({}, state, { rcon: "leak", secrets: SECRETS });
  const decoded = generator.normalizeState(data, generator.decodeShare(generator.encodeShare(withSecrets)));
  assert.ok(!JSON.stringify(decoded).includes("leak") && !JSON.stringify(decoded).includes("secret"), "normalizeState drops unknown fields, passwords included");
  assert.equal(generator.decodeShare("%%%"), null);
}

// Switching preset drops bitmask overrides, which hold the old preset's whole value, and keeps the rest.
{
  const state = generator.normalizeState(data, { target: "japro", preset: "bundled", tune: { g_tweakSaber: "396877", g_speed: "300", disable_item_seeker: "0" } });
  const dropped = generator.switchPreset(data, state, "base-like");
  assert.deepEqual(dropped, ["g_tweakSaber"]);
  assert.deepEqual(state.tune, { disable_item_seeker: "0", g_speed: "300" });
  const baseline = generator.generate(data, state, {}).files.find((f) => f.name === "default.cfg").text;
  assert.match(baseline, /^seta g_tweakSaber "0"/m, "Close to base keeps its own g_tweakSaber after the switch");
}

// Password lines in the mod's own settings stay out of storage and share links, but reach server.cfg.
{
  const state = generator.normalizeState(data, { target: "other", extra: 'set jp_councilPass "hunter2"\nseta jp_fixRoll 1\nset jp_clanPass abc' });
  const stored = generator.persistable(state);
  assert.equal(stored.extra, "seta jp_fixRoll 1");
  assert.ok(!generator.encodeShare(state).includes("hunter2") && !JSON.stringify(generator.decodeShare(generator.encodeShare(state))).includes("hunter2"));
  assert.match(generator.generate(data, state, {}).files[0].text, /^set jp_councilPass "hunter2"$/m);
  const quoted = generator.generate(data, { target: "other", extra: 'set jp_motd "Welcome; have fun"' }, {}).files[0].text;
  assert.match(quoted, /^set jp_motd "Welcome; have fun"$/m, "free-form lines keep their quotes");
}

// Passwords a config cannot hold are flagged rather than silently rewritten.
assert.equal(generator.secretProblem(""), "");
assert.equal(generator.secretProblem("Correct-Horse_42!"), "");
assert.ok(generator.secretProblem('ab"cd'));
assert.ok(generator.secretProblem(" padded "));
assert.ok(generator.secretProblem("caf\u00e9"));

// Reserved, engine-managed and unknown settings never reach the files through fine-tuning.
{
  const state = generator.normalizeState(data, { target: "japro", tune: { sv_cheats: "1", g_needpass: "1", sv_hostname: "x", g_allowVote: "1", nonsense: "1", g_speed: "300" } });
  assert.deepEqual(state.tune, { g_speed: "300" });
}

// Values that would break out of their quotes are cleaned.
{
  const result = generator.generate(data, { target: "japro", hostname: "a\"b\nc" }, { rcon: "p\"w\nx" });
  const server = result.files[0].text;
  assert.match(server, /^seta sv_hostname "a b c"$/m);
  assert.match(server, /^set rconpassword "p w x"$/m);
}

// Presets carry the audit's settings.
function presetValue(target, presetId, name) {
  return generator.presetDefaultValue(data, target, presetId, name);
}
assert.equal(presetValue("japro", "base-like", "d_saberSPStyleDamage"), "1");
assert.equal(presetValue("japro", "base-like", "g_fixSaberDisarmBonus"), "1");
for (const fix of ["g_fixSaberMoveData", "g_fixRunWalkAnims", "g_fixWeaponAttackAnim"]) {
  assert.equal(presetValue("japro", "base-like", fix), "0");
  assert.equal(presetValue("japro", "japlus-like", fix), "0");
}
assert.equal(presetValue("japro", "japlus-like", "g_fixSaberDisarmBonus"), "0");
assert.equal(presetValue("japro", "japlus-like", "g_tweakForce"), "388");
assert.equal(presetValue("japro", "japlus-like", "g_tweakSaber"), "513");
assert.equal(presetValue("japro", "base-like", "dmflags"), "256");
assert.equal(presetValue("japro", "bundled", "disable_item_medpak"), null, "the bundled preset drops the dead disable_item_medpak");
for (const target of Object.keys(generator.targets)) {
  for (const preset of data.presets[target]) {
    assert.notEqual(presetValue(target, preset.id, "sv_pure"), "1", `${target}/${preset.id} must not turn on sv_pure`);
  }
}

// A base mode resets force regeneration to base's own default, not jaPRO's.
{
  const state = generator.normalizeState(data, { target: "base", preset: "defaults", modes: ["training"] });
  const baseline = generator.generate(data, state, {}).files.find((f) => f.name === "default.cfg").text;
  assert.match(baseline, /^seta g_forceRegenTime "200"/m);
}

console.log(`config generator: ${bundles} bundles checked`);
