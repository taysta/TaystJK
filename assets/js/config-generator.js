(function (global) {
  "use strict";

  // Server config generator. The first half is pure: it turns a state object and the data built
  // by tools/config_generator/build.py into config files, a zip and a paste-in shell command, and
  // the Node tests drive it directly. The second half binds the page. Passwords live only in
  // `secrets`: they are never stored on the device or written into the share link.

  var STORAGE_KEY = "taystjk-config-generator";
  var QUERY_KEY = "cfg";
  var STATE_VERSION = 1;
  var SECRET_FIELDS = ["rcon", "password", "fullAdmin", "juniorAdmin"];
  var MASTER_SERVERS = ["sv_master1", "sv_master2", "sv_master3", "sv_master4", "sv_master5"];
  var VSTR_VOTE_BIT = 12;
  var DEFAULT_ALLOW_VOTE = 12416; // map, vstr and poll, as the bundled default.cfg allows
  var MAX_CLIENTS = 32;

  var TARGETS = {
    japro: { label: "TaystJK's jaPRO module", mod: "taystjk", baseOnly: false, defaultCfg: true },
    base: { label: "Base game rules", mod: "base", baseOnly: true, defaultCfg: true },
    other: { label: "Another mod", mod: "", baseOnly: true, defaultCfg: false }
  };
  var HOSTING = { docker: "Docker Compose", dedicated: "Dedicated server" };

  // --- Small helpers -----------------------------------------------------------------------------

  function has(object, key) {
    return Object.prototype.hasOwnProperty.call(object, key);
  }

  // Config values are written inside double quotes, which the engine cannot escape, and one
  // line per setting. Keep printable ASCII only: the engine reads bytes, not UTF-8.
  function clean(value) {
    return String(value == null ? "" : value).replace(/["\r\n\t]/g, " ").replace(/[^\x20-\x7e]/g, "").trim();
  }

  function cleanName(value) {
    var text = String(value == null ? "" : value).trim();
    return /^[A-Za-z0-9_][A-Za-z0-9_.\-]*$/.test(text) ? text : "";
  }

  function cleanMap(value) {
    var text = String(value == null ? "" : value).trim().replace(/\.bsp$/i, "").replace(/^maps\//i, "");
    return /^[A-Za-z0-9_][A-Za-z0-9_\/.\-]*$/.test(text) ? text : "";
  }

  function cleanBans(value) {
    var parts = String(value == null ? "" : value).split(/[\s,]+/).filter(function (part) {
      return /^\d{1,3}(\.\d{1,3}){0,3}$/.test(part);
    });
    return parts.join(" ");
  }

  function toInt(value, fallback, min, max) {
    var number = parseInt(value, 10);
    if (!isFinite(number)) number = fallback;
    if (min != null && number < min) number = min;
    if (max != null && number > max) number = max;
    return number;
  }

  function unique(list) {
    var seen = {};
    return list.filter(function (item) {
      if (seen[item]) return false;
      seen[item] = true;
      return true;
    });
  }

  function cvarEntry(data, name) {
    return data.cvars[String(name).toLowerCase()] || null;
  }

  function isItemCvar(data, name) {
    var key = String(name).toLowerCase();
    if (key.indexOf("disable_") !== 0) return false;
    return data.items.some(function (item) { return "disable_" + item.toLowerCase() === key; });
  }

  // Whether a target may write a cvar: engine cvars and pickups everywhere, base-game cvars for
  // base and other mods, every game cvar for jaPRO. Engine-managed cvars never.
  function available(data, target, name) {
    if (isItemCvar(data, name)) return true;
    var entry = cvarEntry(data, name);
    if (!entry || entry.em) return false;
    if (entry.e) return true;
    return !TARGETS[target].baseOnly || entry.b === 1;
  }

  function scopeOf(data, target, name) {
    if (!TARGETS[target].defaultCfg) return "server";
    if (isItemCvar(data, name)) return "default";
    var entry = cvarEntry(data, name);
    return entry ? entry.f : "default";
  }

  function canonicalName(data, name) {
    var entry = cvarEntry(data, name);
    if (entry) return entry.n;
    var key = String(name).toLowerCase();
    var match = data.items.filter(function (item) { return "disable_" + item.toLowerCase() === key; })[0];
    return match ? "disable_" + match : name;
  }

  function referenceDefault(data, name) {
    if (isItemCvar(data, name)) return "0";
    var entry = cvarEntry(data, name);
    return entry ? entry.d : "";
  }

  // --- Catalogue lookups -------------------------------------------------------------------------

  function presetsFor(data, target) {
    return data.presets[target] || [];
  }

  function findPreset(data, target, id) {
    var list = presetsFor(data, target);
    return list.filter(function (preset) { return preset.id === id; })[0] || list[0];
  }

  function modesFor(data, target) {
    if (target === "japro") return data.modes.japro.modes;
    if (target === "base") return data.modes.base.modes;
    return [];
  }

  function addonsFor(data, target) {
    return target === "japro" ? data.modes.japro.addons : [];
  }

  function gametypeLabel(data, value) {
    var match = data.modes.gametypes.filter(function (g) { return g.value === value; })[0];
    return match ? match.label : "gametype " + value;
  }

  function presetFlow(data, target, presetId) {
    var preset = findPreset(data, target, presetId);
    var flow = { gametype: 0, map: "mp/ffa3", timelimit: 0, fraglimit: 0, capturelimit: 0 };
    if (preset.from_docker) {
      var bundled = data.docker.flow;
      flow.gametype = toInt(bundled.g_gametype, 0);
      flow.timelimit = toInt(bundled.timelimit, 0);
      flow.fraglimit = toInt(bundled.fraglimit, 0);
      flow.capturelimit = toInt(bundled.capturelimit, 0);
    }
    Object.keys(preset.flow || {}).forEach(function (key) { flow[key] = preset.flow[key]; });
    return flow;
  }

  // The value a preset's default.cfg gives a cvar, or null when it leaves it alone.
  function presetDefaultValue(data, target, presetId, name) {
    var key = String(name).toLowerCase();
    var found = null;
    presetSections(data, target, presetId).forEach(function (section) {
      section.lines.forEach(function (line) {
        if (line[0].toLowerCase() === key) found = line[1];
      });
    });
    return found;
  }

  // A preset's default.cfg as titled sections of [name, value, note] lines.
  function presetSections(data, target, presetId) {
    var preset = findPreset(data, target, presetId);
    if (preset.from_docker) return data.docker.default;
    var sections = [];
    var current = null;
    (preset.default || []).forEach(function (line) {
      if (!Array.isArray(line)) {
        current = { title: line.section, lines: [] };
        sections.push(current);
        return;
      }
      if (!current) {
        current = { title: preset.label, lines: [] };
        sections.push(current);
      }
      current.lines.push(line);
    });
    return sections;
  }

  // --- State -------------------------------------------------------------------------------------

  function applyPresetFlow(data, state) {
    var flow = presetFlow(data, state.target, state.preset);
    state.gametype = flow.gametype;
    state.maps = [flow.map];
    state.rotation = false;
    state.timelimit = flow.timelimit;
    state.fraglimit = flow.fraglimit;
    state.capturelimit = flow.capturelimit;
    var allow = state.target === "japro" ? presetDefaultValue(data, state.target, state.preset, "g_allowVote") : null;
    state.allowVote = allow != null ? toInt(allow, DEFAULT_ALLOW_VOTE) : DEFAULT_ALLOW_VOTE;
    return state;
  }

  function defaultState(data, target) {
    target = has(TARGETS, target) ? target : "japro";
    var state = {
      v: STATE_VERSION,
      target: target,
      run: "docker",
      mod: target === "other" ? "japlus" : "",
      arch32: false,
      hostname: "My TaystJK server",
      motd: "",
      maxclients: 16,
      listed: true,
      downloads: true,
      http: true,
      httpPort: 18200,
      bans: true,
      banList: "",
      preset: presetsFor(data, target)[0].id,
      bootMode: "",
      modes: [],
      addons: [],
      votes: target !== "other",
      voteGroups: data.votes.default_groups.slice(),
      tune: {},
      extra: ""
    };
    return applyPresetFlow(data, state);
  }

  // Coerce anything (a stored state, a share link, a form) into a complete, valid state.
  function normalizeState(data, raw) {
    raw = raw && typeof raw === "object" ? raw : {};
    var target = has(TARGETS, raw.target) ? raw.target : "japro";
    var state = defaultState(data, target);
    var presetIds = presetsFor(data, target).map(function (p) { return p.id; });
    var modeIds = modesFor(data, target).map(function (m) { return m.id; });
    var addonIds = addonsFor(data, target).map(function (a) { return a.id; });
    var groupIds = data.votes.groups.map(function (g) { return g.id; });
    var gametypes = data.modes.gametypes.map(function (g) { return g.value; });

    if (has(HOSTING, raw.run)) state.run = raw.run;
    if (presetIds.indexOf(raw.preset) !== -1 && raw.preset !== state.preset) {
      state.preset = raw.preset;
      applyPresetFlow(data, state);
    }
    if (target === "other") {
      state.mod = cleanName(raw.mod) || state.mod;
      if (state.mod.toLowerCase() === "taystjk") state.mod = "japlus";
    }
    if (target !== "japro") state.arch32 = raw.arch32 === true;
    if (typeof raw.hostname === "string") state.hostname = clean(raw.hostname).slice(0, 64);
    if (typeof raw.motd === "string") state.motd = clean(raw.motd).slice(0, 256);
    if (raw.maxclients != null) state.maxclients = toInt(raw.maxclients, 16, 1, MAX_CLIENTS);
    ["listed", "downloads", "http", "bans", "votes"].forEach(function (key) {
      if (typeof raw[key] === "boolean") state[key] = raw[key];
    });
    if (target === "other") state.votes = false;
    if (raw.httpPort != null) state.httpPort = toInt(raw.httpPort, 18200, 1, 65535);
    if (typeof raw.banList === "string") state.banList = cleanBans(raw.banList);

    if (gametypes.indexOf(raw.gametype) !== -1) state.gametype = raw.gametype;
    ["timelimit", "fraglimit", "capturelimit"].forEach(function (key) {
      if (raw[key] != null) state[key] = toInt(raw[key], 0, 0, 100000);
    });
    if (Array.isArray(raw.maps)) {
      var maps = unique(raw.maps.map(cleanMap).filter(Boolean)).slice(0, 64);
      if (maps.length) state.maps = maps;
    }
    if (typeof raw.rotation === "boolean") state.rotation = raw.rotation;

    if (Array.isArray(raw.modes)) state.modes = modeIds.filter(function (id) { return raw.modes.indexOf(id) !== -1; });
    if (Array.isArray(raw.addons)) state.addons = addonIds.filter(function (id) { return raw.addons.indexOf(id) !== -1; });
    if (typeof raw.bootMode === "string" && state.modes.indexOf(raw.bootMode) !== -1) state.bootMode = raw.bootMode;
    // A base mode loads its own map, so it cannot also start a rotation.
    if (target === "base" && state.bootMode) state.rotation = false;
    if (state.maps.length < 2) state.rotation = false;

    if (Array.isArray(raw.voteGroups)) {
      state.voteGroups = groupIds.filter(function (id) { return raw.voteGroups.indexOf(id) !== -1; });
    }
    if (raw.allowVote != null) state.allowVote = toInt(raw.allowVote, DEFAULT_ALLOW_VOTE, 0, 65535);

    if (raw.tune && typeof raw.tune === "object") {
      Object.keys(raw.tune).sort().forEach(function (name) {
        if (!available(data, target, name)) return;
        var canonical = canonicalName(data, name);
        if (isReserved(canonical)) return;
        state.tune[canonical] = clean(raw.tune[name]).slice(0, 256);
      });
    }
    if (target === "other" && typeof raw.extra === "string") {
      state.extra = String(raw.extra).replace(/\r/g, "").split("\n").map(clean).join("\n").trim().slice(0, 8000);
    }
    return state;
  }

  // Settings other steps own. Fine-tuning cannot set them, so every step's choice sticks.
  var RESERVED = [
    "sv_hostname", "g_motd", "sv_maxclients", "rconpassword", "g_password", "g_fulladminpass",
    "g_junioradminpass", "sv_allowdownload", "sv_httpdownloads", "sv_httpserverport", "g_gametype",
    "timelimit", "fraglimit", "capturelimit", "g_allowvote", "g_filterban", "g_banips", "vm_legacy",
    "fs_game", "dedicated", "net_port"
  ].concat(MASTER_SERVERS);

  function isReserved(name) {
    return RESERVED.indexOf(String(name).toLowerCase()) !== -1;
  }

  function persistable(state) {
    return JSON.parse(JSON.stringify(state));
  }

  // --- Config text -------------------------------------------------------------------------------

  function CfgWriter() {
    this.lines = [];
  }

  CfgWriter.prototype.blank = function () {
    if (this.lines.length && this.lines[this.lines.length - 1] !== "") this.lines.push("");
  };
  CfgWriter.prototype.comment = function (text) {
    this.lines.push("// " + text);
  };
  CfgWriter.prototype.raw = function (text) {
    this.lines.push(text);
  };
  CfgWriter.prototype.set = function (keyword, name, value, note) {
    this.lines.push(keyword + " " + name + " \"" + clean(value) + "\"" + (note ? " // " + clean(note) : ""));
  };
  CfgWriter.prototype.text = function () {
    while (this.lines.length && this.lines[this.lines.length - 1] === "") this.lines.pop();
    return this.lines.join("\n") + "\n";
  };

  // An ordered set of titled sections; putting a name that is already present changes it in place,
  // so a later step overrides a preset without duplicating the line.
  function SectionSet() {
    this.sections = [];
    this.index = {};
  }

  SectionSet.prototype.section = function (title) {
    var found = this.sections.filter(function (s) { return s.title === title; })[0];
    if (!found) {
      found = { title: title, lines: [] };
      this.sections.push(found);
    }
    return found;
  };
  SectionSet.prototype.get = function (name) {
    return this.index[String(name).toLowerCase()] || null;
  };
  SectionSet.prototype.put = function (title, name, value, note) {
    var existing = this.get(name);
    if (existing) {
      if (existing.value !== value) {
        existing.value = value;
        existing.note = note || null;
      }
      return existing;
    }
    var line = { name: name, value: value, note: note || null };
    this.section(title).lines.push(line);
    this.index[String(name).toLowerCase()] = line;
    return line;
  };
  SectionSet.prototype.write = function (writer, keyword) {
    this.sections.forEach(function (section) {
      if (!section.lines.length) return;
      writer.blank();
      if (section.title) writer.comment(section.title);
      section.lines.forEach(function (line) { writer.set(keyword, line.name, line.value, line.note); });
    });
  };

  // --- Modes -------------------------------------------------------------------------------------

  // The bundled files a jaPRO file runs with exec, other than default.cfg, recursively.
  function japroDependencies(data, id, seen) {
    seen = seen || {};
    (data.docker.files[id] || []).forEach(function (statement) {
      if (statement.t === "exec" && statement.file !== "default" && !seen[statement.file]) {
        seen[statement.file] = true;
        japroDependencies(data, statement.file, seen);
      }
    });
    return seen;
  }

  function japroFileIds(data, state) {
    var ids = {};
    state.modes.concat(state.addons).forEach(function (id) {
      ids[id] = true;
      Object.keys(japroDependencies(data, id)).forEach(function (dep) { ids[dep] = true; });
    });
    return Object.keys(ids).sort();
  }

  function writeJaproFile(data, id) {
    var writer = new CfgWriter();
    (data.docker.files[id] || []).forEach(function (statement) {
      if (statement.t === "blank") writer.blank();
      else if (statement.t === "comment") writer.comment(statement.text);
      else if (statement.t === "exec") writer.raw("exec " + statement.file);
      else if (statement.t === "cmd") writer.raw(statement.text);
      else writer.set("set", statement.name, statement.value, statement.note);
    });
    return writer.text();
  }

  function baseModeCvars(data, mode) {
    var lines = [
      ["g_gametype", String(mode.gametype)],
      ["fraglimit", String(mode.fraglimit)],
      ["timelimit", String(mode.timelimit)],
      ["g_forceRegenTime", String(mode.regen)]
    ];
    data.modes.base.pickup_items.forEach(function (item) {
      lines.push(["disable_" + item, mode.pickups ? "0" : "1"]);
    });
    return lines;
  }

  function writeBaseMode(data, mode) {
    var writer = new CfgWriter();
    writer.comment(mode.label + ": " + gametypeLabel(data, mode.gametype) + " on " + mode.map);
    writer.raw("exec default");
    writer.blank();
    baseModeCvars(data, mode).forEach(function (line) { writer.set("set", line[0], line[1]); });
    writer.blank();
    writer.raw("kick allbots");
    writer.raw("map " + mode.map);
    (mode.bots || []).forEach(function (bot) { writer.raw("addbot " + bot); });
    return writer.text();
  }

  // Every cvar a set of mode files changes, in first-seen order.
  function modeCvars(data, state) {
    var names = [];
    if (state.target === "japro") {
      japroFileIds(data, state).forEach(function (id) {
        (data.docker.files[id] || []).forEach(function (statement) {
          if (statement.t === "cvar") names.push(statement.name);
        });
      });
    } else if (state.target === "base") {
      modesFor(data, "base").forEach(function (mode) {
        if (state.modes.indexOf(mode.id) === -1) return;
        baseModeCvars(data, mode).forEach(function (line) { names.push(line[0]); });
      });
    }
    var seen = {};
    return names.filter(function (name) {
      var key = name.toLowerCase();
      if (seen[key]) return false;
      seen[key] = true;
      return true;
    });
  }

  // --- Generation --------------------------------------------------------------------------------

  function tuneFor(state, data, scope) {
    return Object.keys(state.tune).filter(function (name) {
      return scopeOf(data, state.target, name) === scope;
    }).map(function (name) { return [name, state.tune[name]]; });
  }

  function buildDefault(data, state) {
    var set = new SectionSet();
    var preset = findPreset(data, state.target, state.preset);
    presetSections(data, state.target, state.preset).forEach(function (section) {
      section.lines.forEach(function (line) { set.put(section.title, line[0], line[1], line[2]); });
    });

    var flow = "Game flow: the gametype and limits every mode returns to";
    if (state.target === "base") set.put(flow, "g_gametype", String(state.gametype), gametypeLabel(data, state.gametype));
    set.put(flow, "timelimit", String(state.timelimit));
    set.put(flow, "fraglimit", String(state.fraglimit));
    set.put(flow, "capturelimit", String(state.capturelimit));
    if (preset.from_docker && data.docker.flow.duel_fraglimit != null) {
      set.put(flow, "duel_fraglimit", data.docker.flow.duel_fraglimit);
    }

    if (state.target === "japro") {
      set.put("Votes", "g_allowVote", String(effectiveAllowVote(data, state)), "Which /callvote types players may use");
    } else {
      set.put("Votes", "g_allowVote", state.votes ? "-1" : "0", state.votes ? "Allow votes" : "No votes");
    }

    tuneFor(state, data, "default").forEach(function (pair) { set.put("Fine-tuning", pair[0], pair[1]); });

    var resets = state.target === "base" ? data.modes.base.baseline_resets : {};
    modeCvars(data, state).forEach(function (name) {
      if (set.get(name)) return;
      var value = has(resets, name) ? resets[name] : referenceDefault(data, name);
      set.put("Reset what the modes change", name, value, "Game default");
    });
    return set;
  }

  function effectiveAllowVote(data, state) {
    var value = state.allowVote;
    if (voteOptions(data, state, null).length) value |= 1 << VSTR_VOTE_BIT;
    return value;
  }

  function writeDefault(data, state, set) {
    var writer = new CfgWriter();
    writer.comment("Gameplay baseline. server.cfg runs it before the first map, and every mode runs it first,");
    writer.comment("so each mode starts from the same settings. Server settings belong in server.cfg, not here.");
    set.write(writer, "seta");
    if (state.target === "japro") {
      writer.blank();
      writer.comment("jaPRO's gametype command switches without a full map reload");
      writer.raw("gametype " + state.gametype);
    }
    return writer.text();
  }

  function voteOptions(data, state, baseline) {
    if (state.target !== "japro" || !state.votes) return [];
    var options = [];
    var modeOptions = [];
    modesFor(data, "japro").forEach(function (mode) {
      if (state.modes.indexOf(mode.id) === -1) return;
      modeOptions.push({ id: mode.id, run: "exec " + mode.id });
      (data.votes.mode_extras[mode.id] || []).forEach(function (extra) { modeOptions.push(extra); });
    });
    addonsFor(data, "japro").forEach(function (addon) {
      if (state.addons.indexOf(addon.id) !== -1) modeOptions.push({ id: addon.id, run: "exec " + addon.id });
    });
    data.votes.groups.forEach(function (group) {
      if (state.voteGroups.indexOf(group.id) === -1) return;
      group.options.forEach(function (option) {
        options.push({ group: group.label, id: option.id, run: option.run, note: option.note });
      });
    });
    if (!modeOptions.length && !options.length) return [];
    var always = data.votes.always.map(function (option) {
      return { group: "Modes", id: option.id, run: option.run, note: option.note };
    });
    var result = [always[0]].concat(modeOptions.map(function (option) {
      return { group: "Modes", id: option.id, run: option.run, note: option.note };
    }), always.slice(1), options);
    return result.map(function (option) {
      var run = option.run.replace(/\{baseline:(\w+)\}/g, function (match, name) {
        var line = baseline ? baseline.get(name) : null;
        return line ? line.value : referenceDefault(data, name);
      });
      return { group: option.group, id: option.id, run: run, note: option.note };
    });
  }

  function writeVotes(options) {
    var writer = new CfgWriter();
    writer.comment("Vote options. Players run these with /callvote vstr <name>.");
    var group = null;
    options.forEach(function (option) {
      if (option.group !== group) {
        writer.blank();
        writer.comment(option.group);
        group = option.group;
      }
      writer.set("set", option.id, option.run, option.note);
    });
    return writer.text();
  }

  function writeBans(state) {
    var writer = new CfgWriter();
    writer.comment("IP bans. Separate addresses with spaces and end the list with a space.");
    writer.comment("Leave off trailing numbers to ban a range: \"1.2.3 \" bans every 1.2.3.x address.");
    writer.comment("While g_banIPs stays commented out, bans added with the addip command are saved and kept.");
    writer.comment("Setting it replaces that saved list at every start, so copy any addip bans into it first.");
    // Written raw: the list must end with a space, which clean() would trim. cleanBans already
    // limited it to digits, dots and spaces.
    if (state.banList) writer.raw("seta g_banIPs \"" + state.banList + " \"");
    else writer.raw("//seta g_banIPs \"\"");
    writer.blank();
    writer.comment("1 = block the listed addresses, 0 = only allow the listed addresses");
    writer.set("seta", "g_filterBan", "1");
    return writer.text();
  }

  function serverTemplate(data, state) {
    var set = new SectionSet();
    if (state.target === "japro") {
      data.docker.server.forEach(function (section) {
        section.lines.forEach(function (line) { set.put(section.title, line[0], line[1], line[2]); });
      });
    }
    var preset = findPreset(data, state.target, state.preset);
    (preset.server || []).forEach(function (line) {
      set.put("From the " + preset.label + " preset", line[0], line[1], line[2]);
    });
    tuneFor(state, data, "server").forEach(function (pair) { set.put("Fine-tuning", pair[0], pair[1]); });
    return set;
  }

  function writeServer(data, state, secrets, options) {
    var target = TARGETS[state.target];
    var writer = new CfgWriter();
    writer.comment("Server config for " + target.label + ", written by the TaystJK server config generator.");
    if (target.defaultCfg) writer.comment("Server settings live here; gameplay lives in default.cfg and the mode files.");

    writer.blank();
    writer.comment("Identity");
    writer.set("seta", "sv_hostname", state.hostname);
    if (state.motd) writer.set("seta", "g_motd", state.motd);
    writer.set("seta", "sv_maxclients", String(state.maxclients));

    writer.blank();
    writer.comment("Passwords. \"set\" keeps them out of the config the server saves on shutdown.");
    if (state.run === "docker") writer.comment("Keep rconpassword on a \"set\" line: docker stop reads it from here to shut down cleanly.");
    writer.set("set", "rconpassword", secrets.rcon || "");
    if (secrets.password) writer.set("set", "g_password", secrets.password);
    if (state.target === "japro") {
      writer.set("set", "g_fullAdminPass", secrets.fullAdmin || "", "Empty disables this login");
      writer.set("set", "g_juniorAdminPass", secrets.juniorAdmin || "", "Empty disables this login");
    }

    if (!state.listed) {
      writer.blank();
      writer.comment("Private: tell no master server about this server");
      MASTER_SERVERS.forEach(function (name) { writer.set("set", name, ""); });
    }

    writer.blank();
    writer.comment("Downloads: HTTP for clients that support it, UDP for the rest");
    writer.set("seta", "sv_allowDownload", state.downloads ? "1" : "0");
    writer.set("seta", "sv_httpDownloads", state.downloads && state.http ? "1" : "0");
    if (state.downloads && state.http) {
      writer.set("seta", "sv_httpServerPort", String(state.httpPort), state.run === "docker" ? "Publish the same TCP port in docker-compose.yml" : null);
    }

    serverTemplate(data, state).write(writer, "seta");

    if (state.target === "other") {
      var gameplay = new SectionSet();
      gameplay.put("Game flow", "timelimit", String(state.timelimit));
      gameplay.put("Game flow", "fraglimit", String(state.fraglimit));
      gameplay.put("Game flow", "capturelimit", String(state.capturelimit));
      gameplay.write(writer, "seta");
      if (state.extra) {
        writer.blank();
        writer.comment("The mod's own settings, as entered");
        state.extra.split("\n").forEach(function (line) { if (line) writer.raw(line); });
      }
    }

    if (state.bans) {
      writer.blank();
      writer.comment("IP bans");
      writer.raw("exec bans");
    }
    if (options.votes) {
      writer.blank();
      writer.comment("Vote options for /callvote vstr");
      writer.raw("exec votes");
    }
    if (target.defaultCfg) {
      writer.blank();
      writer.comment("Start from the gameplay baseline, so settings saved by the last mode do not carry over");
      writer.raw("exec default");
    }

    writer.blank();
    if (state.target === "base" && state.bootMode) {
      writer.comment("Start the server in the " + state.bootMode + " mode, which loads its own map");
      writer.raw("exec " + state.bootMode);
      return writer.text();
    }
    writer.comment("Start the server: " + gametypeLabel(data, state.gametype));
    writer.set("seta", "g_gametype", String(state.gametype));
    if (state.rotation) {
      writer.comment("Map rotation: each entry loads a map and points nextmap at the next entry");
      state.maps.forEach(function (map, index) {
        var next = "m" + ((index + 1) % state.maps.length + 1);
        writer.set("set", "m" + (index + 1), "map " + map + "; set nextmap vstr " + next);
      });
      writer.raw("vstr m1");
    } else {
      writer.raw("map " + state.maps[0]);
    }
    if (state.target === "japro" && state.bootMode) {
      writer.comment("Switch to the boot mode once the map is running");
      writer.raw("exec " + state.bootMode);
    }
    return writer.text();
  }

  function mapsNeeded(data, state) {
    var maps = state.rotation ? state.maps.slice() : [state.maps[0]];
    if (state.target === "base" && state.bootMode) maps = [];
    if (state.target === "base") {
      modesFor(data, "base").forEach(function (mode) {
        if (state.modes.indexOf(mode.id) !== -1) maps.push(mode.map);
      });
    }
    var stock = data.modes.stock_maps.map(function (m) { return m.toLowerCase(); });
    var result = { stock: [], custom: [] };
    unique(maps).forEach(function (map) {
      (stock.indexOf(map.toLowerCase()) !== -1 ? result.stock : result.custom).push(map);
    });
    return result;
  }

  function modDir(state) {
    return state.target === "other" ? state.mod : TARGETS[state.target].mod;
  }

  function installDir(state) {
    return state.run === "docker" ? "homepath/" + modDir(state) : modDir(state);
  }

  function launchLine(state) {
    var binary = state.arch32 ? "./taystjkded.i386" : "./taystjkded.x86_64";
    var parts = [binary, "+set dedicated 2", "+set net_port 29070", "+set fs_game " + modDir(state), "+exec server.cfg"];
    return parts.join(" \\\n  ");
  }

  function dockerEnvironment(state) {
    if (state.target === "japro") return [];
    var env = ["TJK_MOD=" + modDir(state)];
    if (state.arch32) env.push("TJK_ARCH=i386");
    return env;
  }

  function writeReadme(data, state, files, maps) {
    var target = TARGETS[state.target];
    var preset = findPreset(data, state.target, state.preset);
    var out = [];
    out.push("TaystJK server configs");
    out.push("======================");
    out.push("");
    out.push("Target: " + target.label + " (mod directory " + modDir(state) + ")");
    out.push("Gameplay preset: " + preset.label);
    out.push("Run with: " + HOSTING[state.run]);
    out.push("");
    out.push("Files");
    out.push("-----");
    var width = Math.max.apply(null, files.map(function (file) { return file.name.length; }));
    files.forEach(function (file) { out.push("  " + (file.name + new Array(width + 1).join(" ")).slice(0, width) + "  " + file.about); });
    out.push("");
    out.push("Where they go");
    out.push("-------------");
    if (state.run === "docker") {
      out.push("Put the .cfg files in " + installDir(state) + "/ beside docker-compose.yml, then run");
      out.push("  docker compose restart taystjk");
      if (state.target === "japro") {
        out.push("A file there replaces the image's file of the same name. The image's other bundled");
        out.push("configs, such as its mode files, stay available unless you replace them.");
      }
      var env = dockerEnvironment(state);
      if (env.length) {
        out.push("Set these in the service's environment in docker-compose.yml:");
        env.forEach(function (line) { out.push("  - " + line); });
      }
    } else {
      out.push("Put the .cfg files in the " + modDir(state) + "/ directory beside the server binary, and launch:");
      launchLine(state).split("\n").forEach(function (line) { out.push("  " + line); });
      out.push("On Windows, use the .exe dedicated-server binary with the same options.");
    }
    if (state.target !== "japro") {
      out.push("");
      out.push("Game module");
      out.push("-----------");
      out.push("This bundle includes no game module. Install the jampgame library for " + (state.target === "base" ? "base game rules" : modDir(state)));
      out.push("in " + (state.run === "docker" ? installDir(state) : modDir(state)) + "/, built for the server's operating system and architecture.");
      out.push("The engine uses the library's GetModuleAPI entry point, or the older dllEntry/vmMain interface");
      out.push("when that is all it has, so no setting is needed for older modules such as JA+.");
      if (state.arch32) out.push("It is a 32-bit library, so the server runs taystjkded.i386" + (state.run === "docker" ? " (TJK_ARCH=i386)." : "."));
      else out.push("If the mod ships only a 32-bit library, as JA+ 2.4 does, run the 32-bit server: taystjkded.i386, or TJK_ARCH=i386 under Docker.");
    }
    out.push("");
    out.push("Maps");
    out.push("----");
    if (maps.stock.length) out.push("Stock, in the retail assets: " + maps.stock.join(", "));
    if (maps.custom.length) {
      out.push("Custom, install these on the server; players download them: " + maps.custom.join(", "));
    }
    var needsFlag = state.target === "japro" && state.modes.some(function (id) {
      var mode = modesFor(data, "japro").filter(function (m) { return m.id === id; })[0];
      return mode && mode.maps_note;
    });
    if (needsFlag) out.push("Rabbit and one-flag modes need a map with a neutral flag; the stock maps have none.");
    var notes = (preset.notes || []).slice();
    Object.keys(data.meta.dropped).forEach(function (name) {
      if (state.target === "japro") notes.push("Left out of the bundled configs: " + name + ". " + data.meta.dropped[name]);
    });
    if (notes.length) {
      out.push("");
      out.push("Notes");
      out.push("-----");
      notes.forEach(function (note) { out.push("- " + note); });
    }
    out.push("");
    out.push("Before going public, load every map and mode you plan to run and watch the console for errors.");
    return out.join("\n") + "\n";
  }

  // The whole bundle for a state. `secrets` holds the passwords; it is never persisted.
  function generate(data, rawState, secrets) {
    var state = normalizeState(data, rawState);
    secrets = secrets || {};
    var cleanSecrets = {};
    SECRET_FIELDS.forEach(function (key) { cleanSecrets[key] = clean(secrets[key] || "").slice(0, 128); });

    var files = [];
    var baseline = TARGETS[state.target].defaultCfg ? buildDefault(data, state) : null;
    var votes = voteOptions(data, state, baseline);
    files.push({ name: "server.cfg", about: "Server settings; the only file the server runs itself", text: writeServer(data, state, cleanSecrets, { votes: votes.length > 0 }) });
    if (baseline) files.push({ name: "default.cfg", about: "The gameplay baseline every mode starts from", text: writeDefault(data, state, baseline) });
    if (state.bans) files.push({ name: "bans.cfg", about: "IP bans", text: writeBans(state) });
    if (votes.length) files.push({ name: "votes.cfg", about: "Vote options for /callvote vstr", text: writeVotes(votes) });

    if (state.target === "japro") {
      japroFileIds(data, state).forEach(function (id) {
        var about = state.modes.indexOf(id) !== -1 ? "Mode" : state.addons.indexOf(id) !== -1 ? "Add-on" : "Needed by a mode";
        files.push({ name: id + ".cfg", about: about, text: writeJaproFile(data, id) });
      });
    } else if (state.target === "base") {
      modesFor(data, "base").forEach(function (mode) {
        if (state.modes.indexOf(mode.id) !== -1) files.push({ name: mode.id + ".cfg", about: "Mode: " + mode.label, text: writeBaseMode(data, mode) });
      });
    }

    var maps = mapsNeeded(data, state);
    var readme = { name: "README.txt", about: "This file", text: "" };
    files.push(readme);
    readme.text = writeReadme(data, state, files, maps);
    return { state: state, files: files, maps: maps, dir: installDir(state), votes: votes };
  }

  // --- Output formats ----------------------------------------------------------------------------

  function shellQuote(text) {
    return "'" + String(text).replace(/'/g, "'\\''") + "'";
  }

  function heredocDelimiter(files) {
    var base = "TAYSTJK_CFG_EOF";
    var delimiter = base;
    var n = 0;
    var clash = function (d) {
      return files.some(function (file) { return file.text.split("\n").indexOf(d) !== -1; });
    };
    while (clash(delimiter)) delimiter = base + "_" + (++n);
    return delimiter;
  }

  // A command that writes the same files, for hosts working in a server shell. Quoted heredocs
  // keep the shell from expanding anything inside the configs.
  function shellScript(result) {
    var delimiter = heredocDelimiter(result.files);
    var where = result.state.run === "docker" ? "the directory that holds docker-compose.yml" : "the server's install directory";
    var lines = [
      "# TaystJK server configs. Paste into a shell on the server, in " + where + ".",
      "# It contains your passwords: clear it from your shell history if others can read it.",
      "(",
      "set -e",
      "mkdir -p " + shellQuote(result.dir),
      "cd " + shellQuote(result.dir)
    ];
    result.files.forEach(function (file) {
      lines.push("cat > " + shellQuote(file.name) + " <<'" + delimiter + "'");
      lines.push(file.text.replace(/\n$/, ""));
      lines.push(delimiter);
    });
    lines.push("echo " + shellQuote("Wrote " + result.files.length + " files to " + result.dir));
    lines.push(")");
    return lines.join("\n") + "\n";
  }

  var CRC_TABLE = (function () {
    var table = [];
    for (var n = 0; n < 256; n++) {
      var c = n;
      for (var k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1;
      table[n] = c >>> 0;
    }
    return table;
  }());

  function crc32(bytes) {
    var crc = 0xffffffff;
    for (var i = 0; i < bytes.length; i++) crc = CRC_TABLE[(crc ^ bytes[i]) & 0xff] ^ (crc >>> 8);
    return (crc ^ 0xffffffff) >>> 0;
  }

  function asciiBytes(text) {
    var bytes = new Uint8Array(text.length);
    for (var i = 0; i < text.length; i++) bytes[i] = text.charCodeAt(i) & 0xff;
    return bytes;
  }

  // A stored (uncompressed) zip. Config text is ASCII, so bytes map one to one.
  function zip(files) {
    var chunks = [];
    var central = [];
    var offset = 0;
    var dosTime = 0;
    var dosDate = (2024 - 1980) << 9 | 1 << 5 | 1;

    files.forEach(function (file) {
      var name = asciiBytes(file.name);
      var body = asciiBytes(file.text);
      var crc = crc32(body);
      var local = new Uint8Array(30 + name.length);
      var view = new DataView(local.buffer);
      view.setUint32(0, 0x04034b50, true);
      view.setUint16(4, 10, true);
      view.setUint16(6, 0, true);
      view.setUint16(8, 0, true);
      view.setUint16(10, dosTime, true);
      view.setUint16(12, dosDate, true);
      view.setUint32(14, crc, true);
      view.setUint32(18, body.length, true);
      view.setUint32(22, body.length, true);
      view.setUint16(26, name.length, true);
      view.setUint16(28, 0, true);
      local.set(name, 30);
      chunks.push(local, body);

      var entry = new Uint8Array(46 + name.length);
      var cview = new DataView(entry.buffer);
      cview.setUint32(0, 0x02014b50, true);
      cview.setUint16(4, 20, true);
      cview.setUint16(6, 10, true);
      cview.setUint16(8, 0, true);
      cview.setUint16(10, 0, true);
      cview.setUint16(12, dosTime, true);
      cview.setUint16(14, dosDate, true);
      cview.setUint32(16, crc, true);
      cview.setUint32(20, body.length, true);
      cview.setUint32(24, body.length, true);
      cview.setUint16(28, name.length, true);
      cview.setUint32(42, offset, true);
      entry.set(name, 46);
      central.push(entry);
      offset += local.length + body.length;
    });

    var centralSize = central.reduce(function (sum, part) { return sum + part.length; }, 0);
    var end = new Uint8Array(22);
    var eview = new DataView(end.buffer);
    eview.setUint32(0, 0x06054b50, true);
    eview.setUint16(8, files.length, true);
    eview.setUint16(10, files.length, true);
    eview.setUint32(12, centralSize, true);
    eview.setUint32(16, offset, true);

    var parts = chunks.concat(central, [end]);
    var total = parts.reduce(function (sum, part) { return sum + part.length; }, 0);
    var out = new Uint8Array(total);
    var position = 0;
    parts.forEach(function (part) {
      out.set(part, position);
      position += part.length;
    });
    return out;
  }

  // --- Share links -------------------------------------------------------------------------------

  function toBase64Url(text) {
    var encoded = typeof global.btoa === "function"
      ? global.btoa(unescape(encodeURIComponent(text)))
      : Buffer.from(text, "utf8").toString("base64");
    return encoded.replace(/\+/g, "-").replace(/\//g, "_").replace(/=+$/, "");
  }

  function fromBase64Url(value) {
    var base64 = String(value).replace(/-/g, "+").replace(/_/g, "/");
    while (base64.length % 4) base64 += "=";
    return typeof global.atob === "function"
      ? decodeURIComponent(escape(global.atob(base64)))
      : Buffer.from(base64, "base64").toString("utf8");
  }

  function encodeShare(state) {
    return toBase64Url(JSON.stringify(persistable(state)));
  }

  function decodeShare(value) {
    try {
      return JSON.parse(fromBase64Url(value));
    } catch (error) {
      return null;
    }
  }

  // --- Page ------------------------------------------------------------------------------------

  var STEPS = [
    { id: "target", title: "Target and run method" },
    { id: "basics", title: "Server basics" },
    { id: "preset", title: "Gameplay preset" },
    { id: "flow", title: "Game flow" },
    { id: "modes", title: "Modes and add-ons", targets: ["japro", "base"] },
    { id: "votes", title: "Votes", targets: ["japro", "base"] },
    { id: "tune", title: "Fine-tuning" },
    { id: "output", title: "Download" }
  ];

  function escapeHtml(value) {
    return String(value == null ? "" : value).replace(/[&<>"']/g, function (c) {
      return { "&": "&amp;", "<": "&lt;", ">": "&gt;", "\"": "&quot;", "'": "&#39;" }[c];
    });
  }

  function stepsFor(state) {
    return STEPS.filter(function (step) { return !step.targets || step.targets.indexOf(state.target) !== -1; });
  }

  function bitIsSet(value, bit) {
    return Math.floor(Math.abs(Number(value) || 0) / Math.pow(2, bit)) % 2 === 1;
  }

  function toggleBit(value, bit) {
    var number = Math.abs(Number(value) || 0);
    return bitIsSet(number, bit) ? number - Math.pow(2, bit) : number + Math.pow(2, bit);
  }

  // What each setting is before fine-tuning, so the controls can show it and a change back to
  // it can drop the override.
  function baselineValues(data, state) {
    var plain = normalizeState(data, persistable(state));
    plain.tune = {};
    var values = {};
    if (TARGETS[plain.target].defaultCfg) {
      buildDefault(data, plain).sections.forEach(function (section) {
        section.lines.forEach(function (line) { values[line.name.toLowerCase()] = line.value; });
      });
    }
    serverTemplate(data, plain).sections.forEach(function (section) {
      section.lines.forEach(function (line) { values[line.name.toLowerCase()] = line.value; });
    });
    return values;
  }

  function stepSummary(data, state, id, result) {
    var target = TARGETS[state.target];
    if (id === "target") {
      var mod = state.target === "other" ? " (" + state.mod + ")" : "";
      return target.label + mod + (state.arch32 ? ", 32-bit" : "") + " · " + HOSTING[state.run];
    }
    if (id === "basics") {
      return (state.hostname || "Unnamed") + " · " + state.maxclients + " players · " +
        (state.listed ? "listed" : "private") + " · downloads " + (state.downloads ? "on" : "off");
    }
    if (id === "preset") return findPreset(data, state.target, state.preset).label;
    if (id === "flow") {
      if (state.target === "base" && state.bootMode) return "Starts in the " + state.bootMode + " mode";
      var where = state.rotation ? "a rotation of " + state.maps.length + " maps" : state.maps[0];
      return gametypeLabel(data, state.gametype) + " on " + where;
    }
    if (id === "modes") {
      var count = state.modes.length + state.addons.length;
      return count ? state.modes.concat(state.addons).join(", ") : "No extra modes";
    }
    if (id === "votes") {
      if (state.target === "base") return state.votes ? "Votes allowed" : "No votes";
      return result.votes.length ? result.votes.length + " vote options" : "No vote options";
    }
    if (id === "tune") {
      var changed = Object.keys(state.tune).length;
      var extra = state.extra ? " plus the mod's own lines" : "";
      return (changed ? changed + " changed" : "Nothing changed") + extra;
    }
    return result.files.length + " files";
  }

  function field(label, control, hint) {
    return '<label class="cfg-field"><span class="cfg-label">' + label + "</span>" + control +
      (hint ? '<span class="cfg-hint">' + hint + "</span>" : "") + "</label>";
  }

  function textInput(name, value, attrs) {
    return '<input type="text" data-field="' + name + '" value="' + escapeHtml(value) + '"' + (attrs || "") + ">";
  }

  function numberInput(name, value, min, max) {
    return '<input type="number" inputmode="numeric" data-field="' + name + '" value="' + escapeHtml(value) +
      '" min="' + min + '"' + (max != null ? ' max="' + max + '"' : "") + ">";
  }

  function checkbox(attrs, checked, label, hint) {
    return '<label class="cfg-check"><input type="checkbox" ' + attrs + (checked ? " checked" : "") + "><span><span>" + label + "</span>" +
      (hint ? "<small>" + hint + "</small>" : "") + "</span></label>";
  }

  function radioCard(name, value, checked, label, hint) {
    return '<label class="cfg-choice"><input type="radio" name="cfg-' + name + '" data-field="' + name + '" value="' +
      escapeHtml(value) + '"' + (checked ? " checked" : "") + "><span><strong>" + label + "</strong>" +
      (hint ? "<small>" + hint + "</small>" : "") + "</span></label>";
  }

  function refLink(data, name) {
    var entry = cvarEntry(data, name);
    var label = "<code>" + escapeHtml(canonicalName(data, name)) + "</code>";
    return entry ? '<a href="' + escapeHtml(entry.u) + '" target="_blank" rel="noopener">' + label + "</a>" : label;
  }

  function renderTarget(data, state) {
    var html = '<fieldset class="cfg-group"><legend>Game module</legend><div class="cfg-choices">';
    html += radioCard("target", "japro", state.target === "japro", "TaystJK's jaPRO module",
      "The bundled game module in the <code>taystjk</code> directory: modes, votes, tweaks, accounts and race mode.");
    html += radioCard("target", "base", state.target === "base", "Base game rules",
      "Base Jedi Academy settings only, for a base game module or a base-compatible proxy such as YBEProxy.");
    html += radioCard("target", "other", state.target === "other", "Another mod",
      "Engine settings and base cvars, plus the mod's own settings as free-form lines. JA+ goes here.");
    html += "</div></fieldset>";
    if (state.target === "other") {
      html += field("Mod directory", textInput("mod", state.mod, ' spellcheck="false" autocomplete="off"'),
        "The directory <code>fs_game</code> selects, such as <code>japlus</code>.");
    }
    if (state.target !== "japro") {
      html += checkbox('data-field="arch32"', state.arch32, "The game module is a 32-bit library",
        "JA+ 2.4 and the retail base module ship only 32-bit Linux libraries (<code>jampgamei386.so</code>). The server then runs <code>taystjkded.i386</code>, or <code>TJK_ARCH=i386</code> under Docker.");
    }
    html += '<fieldset class="cfg-group"><legend>Run the server with</legend><div class="cfg-choices cfg-choices-two">';
    html += radioCard("run", "docker", state.run === "docker", "Docker Compose", "Files go in the mounted <code>homepath</code>.");
    html += radioCard("run", "dedicated", state.run === "dedicated", "Dedicated server", "Files go beside the server binary.");
    html += "</div></fieldset>";
    return html;
  }

  function renderBasics(data, state, secrets) {
    var html = '<div class="cfg-grid">';
    html += field("Server name", textInput("hostname", state.hostname, ' maxlength="64"'), "Colour codes such as <code>^1</code> work.");
    html += field("Players", numberInput("maxclients", state.maxclients, 1, MAX_CLIENTS));
    html += "</div>";
    html += field("Message of the day", textInput("motd", state.motd, ' maxlength="256"'), "Shown while players connect. Leave empty for none.");
    html += '<fieldset class="cfg-group"><legend>Passwords</legend>';
    html += '<p class="cfg-note">Passwords stay in this page: they are not saved on this device or put in the share link, so enter them again after reloading.</p>';
    html += '<div class="cfg-grid">';
    html += field("Rcon password", '<input type="password" autocomplete="new-password" data-secret="rcon" value="' + escapeHtml(secrets.rcon || "") + '">', "Remote console access. Leave empty to disable rcon.");
    html += field("Join password", '<input type="password" autocomplete="new-password" data-secret="password" value="' + escapeHtml(secrets.password || "") + '">', "Leave empty for an open server.");
    if (state.target === "japro") {
      html += field("Full admin password", '<input type="password" autocomplete="new-password" data-secret="fullAdmin" value="' + escapeHtml(secrets.fullAdmin || "") + '">', "Empty disables this login.");
      html += field("Junior admin password", '<input type="password" autocomplete="new-password" data-secret="juniorAdmin" value="' + escapeHtml(secrets.juniorAdmin || "") + '">', "Empty disables this login.");
    }
    html += "</div></fieldset>";
    html += '<fieldset class="cfg-group"><legend>Listing and downloads</legend>';
    html += checkbox('data-field="listed"', state.listed, "List the server on the master servers", "Untick for a private server that players join by address.");
    html += checkbox('data-field="downloads"', state.downloads, "Let players download custom maps and files", "Off is written as <code>0</code>, not left out.");
    if (state.downloads) {
      html += checkbox('data-field="http"', state.http, "Serve them over HTTP", "Faster, for clients that support it; the rest use UDP.");
      if (state.http) html += field("HTTP port", numberInput("httpPort", state.httpPort, 1, 65535), state.run === "docker" ? "Publish the same TCP port in <code>docker-compose.yml</code>." : "Open this TCP port too.");
    }
    html += "</fieldset>";
    html += '<fieldset class="cfg-group"><legend>Bans</legend>';
    html += checkbox('data-field="bans"', state.bans, "Include <code>bans.cfg</code>", "Bans added with <code>addip</code> are saved and kept.");
    if (state.bans) {
      html += field("Addresses to ban", textInput("banList", state.banList, ' spellcheck="false" placeholder="1.2.3.4 5.6.7"'),
        "Optional. Separate with spaces; leave off trailing numbers to ban a range. A list here replaces any saved <code>addip</code> bans at every start.");
    }
    html += "</fieldset>";
    return html;
  }

  function renderPreset(data, state) {
    var html = '<div class="cfg-choices">';
    presetsFor(data, state.target).forEach(function (preset) {
      html += radioCard("preset", preset.id, state.preset === preset.id, escapeHtml(preset.label), escapeHtml(preset.summary));
    });
    html += "</div>";
    var preset = findPreset(data, state.target, state.preset);
    var sections = presetSections(data, state.target, state.preset);
    var count = sections.reduce(function (sum, s) { return sum + s.lines.length; }, 0) + (preset.server || []).length;
    if (count) {
      html += '<details class="cfg-details"><summary>What ' + escapeHtml(preset.label) + " sets (" + count + " settings)</summary>";
      if (preset.server && preset.server.length) {
        html += "<h4>In server.cfg</h4><ul class=\"cfg-setting-list\">";
        preset.server.forEach(function (line) {
          html += "<li>" + refLink(data, line[0]) + " <code>" + escapeHtml(line[1]) + "</code>" + (line[2] ? ": " + escapeHtml(line[2]) : "") + "</li>";
        });
        html += "</ul>";
      }
      sections.forEach(function (section) {
        html += "<h4>" + escapeHtml(section.title) + "</h4><ul class=\"cfg-setting-list\">";
        section.lines.forEach(function (line) {
          html += "<li>" + refLink(data, line[0]) + " <code>" + escapeHtml(line[1]) + "</code>" + (line[2] ? ": " + escapeHtml(line[2]) : "") + "</li>";
        });
        html += "</ul>";
      });
      html += "</details>";
    }
    (preset.notes || []).forEach(function (note) {
      html += '<p class="cfg-note">' + escapeHtml(note) + "</p>";
    });
    if (state.target === "japro" && !preset.from_docker) {
      html += '<p class="cfg-note">Every preset sets OpenJK\'s legacy fixes explicitly. The bundled modes still apply their own settings on top of any preset.</p>';
    }
    return html;
  }

  function renderFlow(data, state) {
    var html = "";
    var baseBoot = state.target === "base" && state.bootMode;
    var options = data.modes.gametypes.map(function (g) {
      return '<option value="' + g.value + '"' + (g.value === state.gametype ? " selected" : "") + ">" + escapeHtml(g.label) + "</option>";
    }).join("");
    html += '<div class="cfg-grid">';
    html += field("Gametype", '<select data-field="gametype">' + options + "</select>", state.target === "japro" ? "Modes that do not choose a gametype play this one." : null);
    if (state.modes.length) {
      var bootOptions = '<option value="">The baseline</option>' + state.modes.map(function (id) {
        return '<option value="' + escapeHtml(id) + '"' + (state.bootMode === id ? " selected" : "") + ">" + escapeHtml(id) + "</option>";
      }).join("");
      html += field("Start in", '<select data-field="bootMode">' + bootOptions + "</select>",
        state.target === "base" ? "A base mode loads its own map." : "The mode is loaded once the first map is running.");
    }
    html += "</div>";
    if (!baseBoot) {
      html += field("Maps", '<textarea rows="4" data-field="maps" spellcheck="false">' + escapeHtml(state.maps.join("\n")) + "</textarea>",
        "One per line, such as <code>mp/ffa3</code>. The first one starts the server.");
      html += checkbox('data-field="rotation"', state.rotation, "Rotate through these maps",
        state.maps.length < 2 ? "Add a second map to rotate." : "When a match ends the next map loads; without this the same map restarts.");
    }
    html += '<div class="cfg-grid cfg-grid-three">';
    html += field("Time limit (minutes)", numberInput("timelimit", state.timelimit, 0));
    html += field("Frag limit", numberInput("fraglimit", state.fraglimit, 0));
    html += field("Capture limit", numberInput("capturelimit", state.capturelimit, 0));
    html += "</div>";
    html += '<p class="cfg-note">0 means no limit. ' + (TARGETS[state.target].defaultCfg ? "The limits go in <code>default.cfg</code>, so every mode returns to them." : "") + "</p>";
    return html;
  }

  function renderModes(data, state) {
    var html = "";
    var docker = data.meta.docker_url;
    if (state.target === "japro") {
      html += '<p class="cfg-note">Each mode runs <code>default.cfg</code>, applies its own settings and restarts the map. Tick only the ones you want; the files they need come along.</p>';
    } else {
      html += '<p class="cfg-note">Each mode runs <code>default.cfg</code>, sets its gametype, limits and pickups, then loads its map. Load one from the console with <code>exec &lt;mode&gt;</code>.</p>';
    }
    html += '<div class="cfg-list">';
    modesFor(data, state.target).forEach(function (mode) {
      var label = state.target === "japro"
        ? '<code>' + escapeHtml(mode.id) + '</code> <a href="' + escapeHtml(docker + "/" + mode.id + ".cfg") + '" target="_blank" rel="noopener" class="cfg-source">source</a>'
        : escapeHtml(mode.label) + " <code>" + escapeHtml(mode.id) + "</code>";
      var hint = state.target === "japro"
        ? escapeHtml(mode.summary) + (mode.maps_note ? " " + escapeHtml(mode.maps_note) : "")
        : escapeHtml(gametypeLabel(data, mode.gametype) + " on " + mode.map + (mode.pickups ? ", pickups on" : "") + (mode.bots ? ", with bots" : ""));
      html += checkbox('data-list="modes" value="' + escapeHtml(mode.id) + '"', state.modes.indexOf(mode.id) !== -1, label, hint);
    });
    html += "</div>";
    var addons = addonsFor(data, state.target);
    if (addons.length) {
      html += '<h4 class="cfg-subhead">Pickup add-ons</h4><p class="cfg-note">Run on top of whatever is loaded; follow with a map restart. Modes that need <code>nopickups</code> include it anyway.</p><div class="cfg-list">';
      addons.forEach(function (addon) {
        html += checkbox('data-list="addons" value="' + escapeHtml(addon.id) + '"', state.addons.indexOf(addon.id) !== -1, "<code>" + escapeHtml(addon.id) + "</code>", escapeHtml(addon.summary));
      });
      html += "</div>";
    }
    return html;
  }

  function renderVotes(data, state, result) {
    if (state.target === "base") {
      return checkbox('data-field="votes"', state.votes, "Allow players to call votes", "Base's map, gametype, kick and limit votes.");
    }
    var html = checkbox('data-field="votes"', state.votes, "Offer vote options", "Players run them with <code>/callvote vstr &lt;name&gt;</code>. Every ticked mode and add-on gets one.");
    if (state.votes) {
      html += '<h4 class="cfg-subhead">Option groups</h4><div class="cfg-list cfg-list-compact">';
      data.votes.groups.forEach(function (group) {
        var ids = group.options.map(function (o) { return o.id; }).join(", ");
        html += checkbox('data-list="voteGroups" value="' + escapeHtml(group.id) + '"', state.voteGroups.indexOf(group.id) !== -1, escapeHtml(group.label), escapeHtml(ids));
      });
      html += "</div>";
    }
    var entry = cvarEntry(data, "g_allowVote");
    var value = effectiveAllowVote(data, state);
    html += '<h4 class="cfg-subhead">Vote types allowed (' + refLink(data, "g_allowVote") + " <code>" + value + "</code>)</h4>";
    html += '<div class="cfg-bits">';
    (entry.bits || []).forEach(function (bit) {
      var forced = bit[0] === VSTR_VOTE_BIT && result.votes.length > 0;
      html += checkbox('data-allowvote-bit="' + bit[0] + '"' + (forced ? " disabled" : ""), bitIsSet(value, bit[0]), escapeHtml(bit[1]), forced ? "Needed for the vote options" : null);
    });
    html += "</div>";
    return html;
  }

  function settingRow(data, state, name, baseline) {
    var key = name.toLowerCase();
    var entry = cvarEntry(data, name);
    var changed = has(state.tune, name);
    var current = changed ? state.tune[name] : (has(baseline, key) ? baseline[key] : "");
    var shown = has(baseline, key) ? baseline[key] : (entry ? entry.d : "0");
    var html = '<div class="cfg-setting' + (changed ? " is-changed" : "") + '">';
    html += '<div class="cfg-setting-head">' + refLink(data, name);
    html += '<span class="cfg-setting-where">' + (scopeOf(data, state.target, name) === "server" ? "server.cfg" : "default.cfg") + "</span>";
    html += '<button type="button" class="cfg-reset" data-untune="' + escapeHtml(name) + '"' + (changed ? "" : " hidden") + ">Undo</button>";
    html += "</div>";
    if (entry && entry.s) html += '<p class="cfg-setting-summary">' + escapeHtml(entry.s) + "</p>";
    if (entry && entry.bits) {
      html += '<div class="cfg-bits">';
      entry.bits.forEach(function (bit) {
        html += checkbox('data-tune-bit="' + escapeHtml(name) + '" value="' + bit[0] + '"', bitIsSet(current, bit[0]), escapeHtml(bit[1]), "bit " + bit[0] + " = " + Math.pow(2, bit[0]));
      });
      html += '</div><p class="cfg-hint">Value: <code>' + escapeHtml(current || "0") + "</code></p>";
    } else if (isItemCvar(data, name)) {
      html += checkbox('data-tune-item="' + escapeHtml(name) + '"', current === "1", "Disabled", null);
    } else {
      var list = entry && entry.v ? ' list="cfg-values-' + escapeHtml(key) + '"' : "";
      html += '<input type="text" class="cfg-setting-input" data-tune="' + escapeHtml(name) + '" value="' + escapeHtml(changed ? current : "") + '" placeholder="' + escapeHtml(shown === "" ? "(empty)" : shown) + '"' + list + ' spellcheck="false" autocomplete="off">';
      if (entry && entry.v) {
        html += '<datalist id="cfg-values-' + escapeHtml(key) + '">' + entry.v.map(function (v) {
          return '<option value="' + escapeHtml(v[0]) + '">' + escapeHtml(v[1]) + "</option>";
        }).join("") + "</datalist>";
        html += '<ul class="cfg-values">' + entry.v.map(function (v) {
          return "<li><code>" + escapeHtml(v[0]) + "</code> " + escapeHtml(v[1]) + "</li>";
        }).join("") + "</ul>";
      }
    }
    html += "</div>";
    return html;
  }

  function renderTune(data, state, ui) {
    var baseline = baselineValues(data, state);
    var html = '<p class="cfg-note">Common settings, grouped by topic. Empty boxes keep the value shown; each name links to its reference entry.</p>';
    var curated = {};
    data.settings.groups.forEach(function (group) {
      var names = group.names.filter(function (name) { return available(data, state.target, name) && !isReserved(name); });
      if (!names.length) return;
      var changed = names.filter(function (name) { return has(state.tune, name); }).length;
      names.forEach(function (name) { curated[name.toLowerCase()] = true; });
      var open = ui.openGroups[group.title] ? " open" : "";
      html += '<details class="cfg-details cfg-tune-group" data-group="' + escapeHtml(group.title) + '"' + open + "><summary>" + escapeHtml(group.title) +
        (changed ? ' <span class="cfg-badge">' + changed + " changed</span>" : "") + "</summary>";
      names.forEach(function (name) { html += settingRow(data, state, name, baseline); });
      html += "</details>";
    });
    var pickups = data.settings.pickups.map(function (item) { return "disable_" + item; });
    var pickupChanges = pickups.filter(function (name) { return has(state.tune, name); }).length;
    html += '<details class="cfg-details cfg-tune-group" data-group="Pickups"' + (ui.openGroups.Pickups ? " open" : "") + "><summary>Pickups" +
      (pickupChanges ? ' <span class="cfg-badge">' + pickupChanges + " changed</span>" : "") + "</summary>";
    html += '<p class="cfg-note">The game reads these only when it spawns items, so they take effect on the next map load.</p><div class="cfg-bits">';
    pickups.forEach(function (name) {
      curated[name.toLowerCase()] = true;
      var current = has(state.tune, name) ? state.tune[name] : (baseline[name.toLowerCase()] || "0");
      html += checkbox('data-tune-item="' + escapeHtml(name) + '"', current === "1", "<code>" + escapeHtml(name.replace(/^disable_/, "")) + "</code>", "Disabled");
    });
    html += "</div></details>";

    var others = Object.keys(state.tune).filter(function (name) { return !curated[name.toLowerCase()]; });
    html += '<div class="cfg-search"><label class="cfg-field"><span class="cfg-label">Find another setting</span>' +
      '<input type="search" data-tune-search value="' + escapeHtml(ui.search) + '" placeholder="Name or description" spellcheck="false" autocomplete="off"></label>';
    var query = ui.search.trim().toLowerCase();
    var shown = others.slice();
    if (query.length >= 2) {
      Object.keys(data.cvars).forEach(function (key) {
        var entry = data.cvars[key];
        if (curated[key] || shown.indexOf(entry.n) !== -1 || !available(data, state.target, entry.n) || isReserved(entry.n)) return;
        if (key.indexOf(query) !== -1 || entry.s.toLowerCase().indexOf(query) !== -1) shown.push(entry.n);
      });
    }
    var limit = others.length + 25;
    html += '<div class="cfg-search-results" data-search-results>';
    shown.slice(0, limit).forEach(function (name) { html += settingRow(data, state, name, baseline); });
    if (query.length >= 2 && shown.length === others.length) html += '<p class="cfg-note">No other setting matches.</p>';
    if (shown.length > limit) html += '<p class="cfg-note">' + (shown.length - limit) + " more match; type more of the name.</p>";
    html += "</div></div>";

    if (state.target === "other") {
      html += field("The mod's own settings", '<textarea rows="8" data-field="extra" spellcheck="false" placeholder="set jp_fixRoll 1">' + escapeHtml(state.extra) + "</textarea>",
        "Written into <code>server.cfg</code> as entered, before the map loads. Use <code>set</code> or <code>seta</code> on every line; a bare name and value is ignored before the first map.");
    }
    return html;
  }

  function renderOutput(data, state, result) {
    var html = '<p class="cfg-note">Everything is generated in this page; nothing is uploaded.</p>';
    html += '<div class="cfg-actions">';
    html += '<button type="button" class="button button-primary" data-action="download">Download the ' + result.files.length + " files (.zip)</button>";
    html += '<button type="button" class="button button-secondary" data-action="copy-shell">Copy a paste-in shell command</button>';
    html += '<button type="button" class="button button-quiet" data-action="copy-link">Copy a link to these choices</button>';
    html += "</div>";
    html += '<p class="cfg-status" data-status role="status" aria-live="polite"></p>';
    html += "<h4 class=\"cfg-subhead\">Where they go</h4>";
    if (state.run === "docker") {
      html += "<p>Put the files in <code>" + escapeHtml(result.dir) + "/</code> beside <code>docker-compose.yml</code>, then run <code>docker compose restart taystjk</code>.</p>";
      var env = dockerEnvironment(state);
      if (env.length) html += "<p>Set these in the service's <code>environment</code>:</p><pre><code>" + escapeHtml(env.map(function (l) { return "- " + l; }).join("\n")) + "</code></pre>";
    } else {
      html += "<p>Put the files in the <code>" + escapeHtml(modDir(state)) + "/</code> directory beside the server binary, and launch:</p>";
      html += "<pre><code>" + escapeHtml(launchLine(state)) + "</code></pre>";
    }
    html += "<h4 class=\"cfg-subhead\">Maps</h4><ul>";
    if (result.maps.stock.length) html += "<li>Stock, in the retail assets: " + result.maps.stock.map(function (m) { return "<code>" + escapeHtml(m) + "</code>"; }).join(", ") + "</li>";
    if (result.maps.custom.length) html += "<li>Custom, which you install on the server and players download: " + result.maps.custom.map(function (m) { return "<code>" + escapeHtml(m) + "</code>"; }).join(", ") + "</li>";
    html += "</ul>";
    if (state.target !== "japro") {
      html += '<p class="cfg-note">The bundle includes no game module; install the mod\'s own <code>jampgame</code> library as its documentation says.</p>';
    }
    html += '<p><button type="button" class="button button-quiet" data-action="reset">Start over</button></p>';
    return html;
  }

  function renderStepBody(data, state, secrets, id, result, ui) {
    if (id === "target") return renderTarget(data, state);
    if (id === "basics") return renderBasics(data, state, secrets);
    if (id === "preset") return renderPreset(data, state);
    if (id === "flow") return renderFlow(data, state);
    if (id === "modes") return renderModes(data, state);
    if (id === "votes") return renderVotes(data, state, result);
    if (id === "tune") return renderTune(data, state, ui);
    return renderOutput(data, state, result);
  }

  function readStored() {
    try {
      var stored = global.localStorage.getItem(STORAGE_KEY);
      return stored ? JSON.parse(stored) : null;
    } catch (error) {
      return null;
    }
  }

  function writeStored(state) {
    try {
      global.localStorage.setItem(STORAGE_KEY, JSON.stringify(persistable(state)));
    } catch (error) {
      // Choices still work for this visit when storage is unavailable.
    }
  }

  function copyText(text) {
    if (global.navigator && global.navigator.clipboard && global.navigator.clipboard.writeText) {
      return global.navigator.clipboard.writeText(text);
    }
    return new Promise(function (resolve, reject) {
      var area = document.createElement("textarea");
      area.value = text;
      area.setAttribute("readonly", "");
      area.style.position = "fixed";
      area.style.opacity = "0";
      document.body.appendChild(area);
      area.select();
      var ok = document.execCommand && document.execCommand("copy");
      document.body.removeChild(area);
      if (ok) resolve();
      else reject(new Error("copy failed"));
    });
  }

  function bind(root, data) {
    var query = "";
    try {
      query = new global.URLSearchParams(global.location.search).get(QUERY_KEY) || "";
    } catch (error) {
      query = "";
    }
    var shared = query ? decodeShare(query) : null;
    var state = normalizeState(data, shared || readStored() || defaultState(data, "japro"));
    if (query) {
      // The link's choices are now this device's; drop them from the address so a reload keeps
      // later edits instead of applying the link again.
      writeStored(state);
      try {
        var address = new global.URL(global.location.href);
        address.searchParams.delete(QUERY_KEY);
        global.history.replaceState(null, "", address.pathname + address.search + address.hash);
      } catch (error) {
        // Leaving the parameter in place only means a reload re-applies the link.
      }
    }
    var secrets = {};
    var ui = { step: "target", preview: "server.cfg", openGroups: {}, search: "" };
    var result = generate(data, state, secrets);
    var renderTimer = null;

    root.innerHTML =
      (shared ? '<p class="cfg-banner">Loaded choices from a shared link. Passwords are never included in a link, so enter your own.</p>' : "") +
      '<div class="cfg-app">' +
      '<div class="cfg-steps" data-steps></div>' +
      '<aside class="cfg-preview" aria-label="Generated files">' +
      '<div class="cfg-preview-shell">' +
      '<p class="platform-selector-label">Preview</p>' +
      '<div class="cfg-tabs" role="tablist" aria-label="Generated files" data-tabs></div>' +
      '<div class="cfg-preview-panel" role="tabpanel" id="cfg-preview-panel" tabindex="0" data-panel><pre><code data-preview></code></pre></div>' +
      "</div></aside></div>";

    var stepsEl = root.querySelector("[data-steps]");
    var tabsEl = root.querySelector("[data-tabs]");
    var panelEl = root.querySelector("[data-panel]");
    var previewEl = root.querySelector("[data-preview]");

    function previewItems() {
      return result.files.map(function (file) { return { id: file.name, text: file.text }; })
        .concat([{ id: "Paste-in command", text: shellScript(result) }]);
    }

    function renderPreview() {
      var items = previewItems();
      if (!items.some(function (item) { return item.id === ui.preview; })) ui.preview = items[0].id;
      var focused = document.activeElement && document.activeElement.parentNode === tabsEl ? document.activeElement.dataset.tab : null;
      tabsEl.innerHTML = items.map(function (item, index) {
        var selected = item.id === ui.preview;
        return '<button type="button" role="tab" id="cfg-tab-' + index + '" aria-controls="cfg-preview-panel" aria-selected="' + selected +
          '" tabindex="' + (selected ? 0 : -1) + '" data-tab="' + escapeHtml(item.id) + '">' + escapeHtml(item.id) + "</button>";
      }).join("");
      var current = items.filter(function (item) { return item.id === ui.preview; })[0];
      var selectedIndex = items.indexOf(current);
      panelEl.setAttribute("aria-labelledby", "cfg-tab-" + selectedIndex);
      previewEl.textContent = current.text;
      if (focused) {
        var again = tabsEl.querySelector('[data-tab="' + focused.replace(/"/g, "") + '"]');
        if (again) again.focus();
      }
    }

    function renderSteps() {
      var active = document.activeElement;
      var focusKey = active && stepsEl.contains(active) ? focusSignature(active) : null;
      var steps = stepsFor(state);
      if (!steps.some(function (step) { return step.id === ui.step; })) ui.step = steps[0].id;
      stepsEl.innerHTML = steps.map(function (step, index) {
        var open = step.id === ui.step;
        var next = steps[index + 1];
        return '<section class="cfg-step' + (open ? " is-open" : "") + '" data-step="' + step.id + '">' +
          '<h2 class="cfg-step-head"><button type="button" aria-expanded="' + open + '" aria-controls="cfg-step-' + step.id + '" data-open-step="' + step.id + '">' +
          '<span class="cfg-step-number">' + (index + 1) + '</span><span class="cfg-step-title">' + escapeHtml(step.title) + "</span>" +
          '<span class="cfg-step-summary" data-summary="' + step.id + '">' + escapeHtml(stepSummary(data, state, step.id, result)) + "</span></button></h2>" +
          '<div class="cfg-step-body" id="cfg-step-' + step.id + '"' + (open ? "" : " hidden") + ">" +
          (open ? renderStepBody(data, state, secrets, step.id, result, ui) +
            (next ? '<div class="cfg-step-nav"><button type="button" class="button button-secondary" data-open-step="' + next.id + '">Next: ' + escapeHtml(next.title) + "</button></div>" : "") : "") +
          "</div></section>";
      }).join("");
      if (focusKey) {
        var target = stepsEl.querySelector(focusKey);
        if (target) {
          target.focus();
          if (target.type === "search" || target.type === "text") {
            var end = target.value.length;
            try { target.setSelectionRange(end, end); } catch (error) { /* number inputs */ }
          }
        }
      }
    }

    function focusSignature(element) {
      var attrs = ["data-field", "data-secret", "data-list", "data-tune", "data-tune-bit", "data-tune-item", "data-allowvote-bit", "data-open-step", "data-tune-search", "data-action"];
      for (var i = 0; i < attrs.length; i++) {
        if (element.hasAttribute(attrs[i])) {
          var selector = "[" + attrs[i] + (element.getAttribute(attrs[i]) ? '="' + element.getAttribute(attrs[i]).replace(/"/g, "") + '"' : "") + "]";
          if (element.type === "radio" || element.type === "checkbox") selector += '[value="' + String(element.value).replace(/"/g, "") + '"]';
          return selector;
        }
      }
      return null;
    }

    function refreshSummaries() {
      stepsFor(state).forEach(function (step) {
        var el = stepsEl.querySelector('[data-summary="' + step.id + '"]');
        if (el) el.textContent = stepSummary(data, state, step.id, result);
      });
    }

    function update(options) {
      state = normalizeState(data, state);
      result = generate(data, state, secrets);
      writeStored(state);
      if (options && options.rerender) renderSteps();
      else refreshSummaries();
      clearTimeout(renderTimer);
      renderTimer = setTimeout(renderPreview, options && options.rerender ? 0 : 120);
    }

    function setStatus(text) {
      var el = root.querySelector("[data-status]");
      if (el) el.textContent = text;
    }

    stepsEl.addEventListener("click", function (event) {
      var opener = event.target.closest("[data-open-step]");
      if (opener) {
        ui.step = opener.getAttribute("data-open-step");
        renderSteps();
        var head = stepsEl.querySelector('.cfg-step-head [data-open-step="' + ui.step + '"]');
        if (head) {
          head.focus();
          if (opener.closest(".cfg-step-nav") && head.scrollIntoView) head.scrollIntoView({ block: "start", behavior: "smooth" });
        }
        return;
      }
      var untune = event.target.closest("[data-untune]");
      if (untune) {
        delete state.tune[untune.getAttribute("data-untune")];
        update({ rerender: true });
        return;
      }
      var action = event.target.closest("[data-action]");
      if (!action) return;
      var kind = action.getAttribute("data-action");
      if (kind === "download") {
        var blob = new Blob([zip(result.files)], { type: "application/zip" });
        var url = URL.createObjectURL(blob);
        var link = document.createElement("a");
        link.href = url;
        link.download = "taystjk-server-configs.zip";
        document.body.appendChild(link);
        link.click();
        document.body.removeChild(link);
        setTimeout(function () { URL.revokeObjectURL(url); }, 1000);
        setStatus("Downloaded taystjk-server-configs.zip.");
      } else if (kind === "copy-shell") {
        copyText(shellScript(result)).then(function () { setStatus("Copied. It writes the files into " + result.dir + "/."); }, function () { setStatus("Copying failed; select the command in the preview instead."); });
        ui.preview = "Paste-in command";
        renderPreview();
      } else if (kind === "copy-link") {
        var shareUrl = new global.URL(global.location.href);
        shareUrl.search = "";
        shareUrl.hash = "";
        shareUrl.searchParams.set(QUERY_KEY, encodeShare(state));
        copyText(shareUrl.toString()).then(function () { setStatus("Link copied. It holds every choice except the passwords."); }, function () { setStatus("Copying failed."); });
      } else if (kind === "reset") {
        state = defaultState(data, "japro");
        secrets = {};
        ui.step = "target";
        ui.search = "";
        ui.openGroups = {};
        update({ rerender: true });
      }
    });

    stepsEl.addEventListener("toggle", function (event) {
      var group = event.target.getAttribute && event.target.getAttribute("data-group");
      if (group) ui.openGroups[group] = event.target.open;
    }, true);

    function onChange(event, typing) {
      var el = event.target;
      if (el.hasAttribute("data-secret")) {
        secrets[el.getAttribute("data-secret")] = el.value;
        update();
        return;
      }
      if (el.hasAttribute("data-tune-search")) {
        ui.search = el.value;
        if (typing) {
          clearTimeout(onChange.searchTimer);
          onChange.searchTimer = setTimeout(function () { renderSteps(); }, 200);
        }
        return;
      }
      // Text fields update state as they are typed in and never re-render the step: a re-render
      // when one loses focus would replace the button being clicked and swallow the click.
      if (el.hasAttribute("data-tune")) {
        var name = el.getAttribute("data-tune");
        if (el.value.trim() === "") delete state.tune[name];
        else state.tune[name] = el.value;
        update();
        var row = el.closest(".cfg-setting");
        var changedNow = has(state.tune, name);
        if (row) {
          row.classList.toggle("is-changed", changedNow);
          var undo = row.querySelector("[data-untune]");
          if (undo) undo.hidden = !changedNow;
        }
        return;
      }
      var textField = el.getAttribute("data-field");
      if (textField && (el.tagName === "TEXTAREA" || el.type === "text" || el.type === "number")) {
        state[textField] = textField === "maps" ? el.value.split(/\s*\n\s*|\s*,\s*/) : el.value;
        update();
        return;
      }
      if (typing) return;
      var baseline;
      if (el.hasAttribute("data-tune-bit")) {
        var bitName = el.getAttribute("data-tune-bit");
        baseline = baselineValues(data, state)[bitName.toLowerCase()];
        var current = has(state.tune, bitName) ? state.tune[bitName] : baseline;
        var value = String(toggleBit(current, Number(el.value)));
        if (value === String(baseline)) delete state.tune[bitName];
        else state.tune[bitName] = value;
        update({ rerender: true });
        return;
      }
      if (el.hasAttribute("data-tune-item")) {
        var item = el.getAttribute("data-tune-item");
        baseline = baselineValues(data, state)[item.toLowerCase()] || "0";
        var wanted = el.checked ? "1" : "0";
        if (wanted === baseline) delete state.tune[item];
        else state.tune[item] = wanted;
        update({ rerender: true });
        return;
      }
      if (el.hasAttribute("data-allowvote-bit")) {
        state.allowVote = toggleBit(effectiveAllowVote(data, state), Number(el.getAttribute("data-allowvote-bit")));
        update({ rerender: true });
        return;
      }
      if (el.hasAttribute("data-list")) {
        var list = el.getAttribute("data-list");
        var values = state[list].filter(function (v) { return v !== el.value; });
        if (el.checked) values.push(el.value);
        state[list] = values;
        update({ rerender: true });
        return;
      }
      var key = el.getAttribute("data-field");
      if (!key) return;
      if (key === "target") {
        var fresh = defaultState(data, el.value);
        ["run", "hostname", "motd", "maxclients", "listed", "downloads", "http", "httpPort", "bans", "banList"].forEach(function (k) { fresh[k] = state[k]; });
        state = fresh;
        ui.search = "";
      } else if (key === "preset") {
        state.preset = el.value;
        applyPresetFlow(data, state);
      } else if (el.type === "checkbox") {
        state[key] = el.checked;
      } else if (key === "gametype") {
        state.gametype = Number(el.value);
      } else {
        state[key] = el.value;
      }
      update({ rerender: true });
    }

    stepsEl.addEventListener("input", function (event) { onChange(event, true); });
    stepsEl.addEventListener("change", function (event) { onChange(event, false); });

    tabsEl.addEventListener("click", function (event) {
      var tab = event.target.closest("[data-tab]");
      if (!tab) return;
      ui.preview = tab.getAttribute("data-tab");
      renderPreview();
    });
    tabsEl.addEventListener("keydown", function (event) {
      var tabs = Array.prototype.slice.call(tabsEl.querySelectorAll("[data-tab]"));
      var index = tabs.indexOf(document.activeElement);
      if (index === -1) return;
      var next = index;
      if (event.key === "ArrowRight") next = (index + 1) % tabs.length;
      else if (event.key === "ArrowLeft") next = (index - 1 + tabs.length) % tabs.length;
      else if (event.key === "Home") next = 0;
      else if (event.key === "End") next = tabs.length - 1;
      else return;
      event.preventDefault();
      ui.preview = tabs[next].getAttribute("data-tab");
      renderPreview();
      tabsEl.querySelector('[data-tab="' + ui.preview.replace(/"/g, "") + '"]').focus();
    });

    renderSteps();
    renderPreview();
  }

  function boot() {
    Array.prototype.forEach.call(document.querySelectorAll("[data-config-generator]"), function (root) {
      root.innerHTML = '<p class="cfg-loading">Loading the generator…</p>';
      fetch(root.dataset.dataUrl, { credentials: "same-origin" })
        .then(function (response) {
          if (!response.ok) throw new Error("HTTP " + response.status);
          return response.json();
        })
        .then(function (data) {
          document.documentElement.classList.add("cfg-ready");
          bind(root, data);
        })
        .catch(function (error) {
          root.innerHTML = '<p class="catalog-error">The generator\'s data could not be loaded. Reload the page, or start from the bundled configs linked above. <small>' + escapeHtml(error.message) + "</small></p>";
        });
    });
  }

  var api = {
    targets: TARGETS,
    secretFields: SECRET_FIELDS,
    defaultState: defaultState,
    normalizeState: normalizeState,
    applyPresetFlow: applyPresetFlow,
    available: available,
    scopeOf: scopeOf,
    isReserved: isReserved,
    presetSections: presetSections,
    presetDefaultValue: presetDefaultValue,
    modesFor: modesFor,
    addonsFor: addonsFor,
    generate: generate,
    shellScript: shellScript,
    zip: zip,
    crc32: crc32,
    encodeShare: encodeShare,
    decodeShare: decodeShare
  };

  if (typeof module !== "undefined" && module.exports) module.exports = api;
  global.TaystConfigGenerator = api;
  if (typeof document !== "undefined") {
    if (document.readyState === "loading") document.addEventListener("DOMContentLoaded", boot);
    else boot();
  }
}(typeof window !== "undefined" ? window : globalThis));
