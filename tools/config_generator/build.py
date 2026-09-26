#!/usr/bin/env python3
"""Build the server config generator's data file, assets/data/config-generator.json.

Inputs:
  - The console reference (_data/cvars.json, _data/commands.json, _data/reference-meta.json)
    for cvar names, defaults, bit tables and base-game membership.
  - The bundled Docker configs, read with `git show` from the commit pinned in sources.json.
  - The item list and the weapon and force-power enums, read from the reference's source_commit.
  - The curated JSON beside this script: presets, modes, votes and common settings.

Every name the generator can write is checked here: it must be a server-side cvar or command in the
reference, or a `disable_<item>` cvar for a real item, and never an engine-managed cvar. Base-target
presets and modes may only use cvars that exist in base Jedi Academy.

  python3 tools/config_generator/build.py           # write the data file
  python3 tools/config_generator/build.py --check   # fail if the data file is out of date
"""

from __future__ import annotations

import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
sys.path.insert(0, str(ROOT / "tools" / "cvar_audit"))

from generate_docs import detail_url  # noqa: E402

OUTPUT = ROOT / "assets" / "data" / "config-generator.json"
SERVER_MODULES = {"game", "engine-server", "engine-shared"}
FLOW_CVARS = {"g_gametype", "timelimit", "fraglimit", "capturelimit", "duel_fraglimit"}
# Server identity, passwords and downloads come from the generator's basics step, not a template.
BASICS_CVARS = {
    "sv_hostname", "g_motd", "rconpassword", "g_password", "g_fulladminpass", "g_junioradminpass",
    "sv_maxclients", "sv_allowdownload", "sv_httpdownloads", "sv_httpserverport",
}


class BuildError(Exception):
    pass


def load(name: str):
    return json.loads((HERE / name).read_text())


def git_show(commit: str, path: str) -> str:
    result = subprocess.run(
        ["git", "show", f"{commit}:{path}"], cwd=ROOT, capture_output=True, text=True
    )
    if result.returncode != 0:
        raise BuildError(f"git show {commit}:{path} failed: {result.stderr.strip()}")
    return result.stdout


def git_ls(commit: str, directory: str) -> list[str]:
    result = subprocess.run(
        ["git", "ls-tree", "--name-only", commit, directory + "/"], cwd=ROOT, capture_output=True, text=True
    )
    if result.returncode != 0:
        raise BuildError(f"git ls-tree {commit} {directory} failed: {result.stderr.strip()}")
    return [Path(line).name for line in result.stdout.split()]


# --- Source tables -----------------------------------------------------------------------------


def item_classnames(source: str) -> list[str]:
    start = re.search(r"gitem_t\s+bg_itemlist\[\]\s*=", source)
    if not start:
        raise BuildError("bg_itemlist not found in bg_misc.c")
    block = source[start.end():source.index("\n};", start.end())]
    names = re.findall(r"\n\s*\{\s*\n\s*\"([A-Za-z_]+)\",", block)
    if len(names) < 40:
        raise BuildError(f"only {len(names)} item classnames found in bg_itemlist")
    return names


def enum_members(source: str, typename: str, prefix: str) -> list[str]:
    match = re.search(r"typedef\s+enum\s*\{(.*?)\}\s*" + typename + r"\s*;", source, re.S)
    if not match:
        raise BuildError(f"enum {typename} not found")
    body = re.sub(r"//[^\n]*|/\*.*?\*/", "", match.group(1), flags=re.S)
    members, value = [], -1
    for item in body.split(","):
        item = item.strip()
        if not item:
            continue
        name, _, explicit = item.partition("=")
        name = name.strip()
        value = int(explicit.strip(), 0) if explicit.strip() else value + 1
        if not name.startswith(prefix) or name.endswith("FIRST") or name.startswith(("NUM_", prefix + "NUM")):
            continue
        if value != len(members):
            raise BuildError(f"{typename}: {name} is {value}, expected {len(members)}")
        members.append(name)
    return members


def bit_table(members: list[str], labels: dict, what: str) -> list[dict]:
    missing = [m for m in members if m not in labels]
    if missing:
        raise BuildError(f"settings.json has no label for {what} {', '.join(missing)}")
    return [{"bit": index, "meaning": labels[name]} for index, name in enumerate(members)]


# --- Reference ---------------------------------------------------------------------------------


def power_of_two_bits(values: list[dict]) -> list[dict] | None:
    """A values list whose every value is a distinct power of two is really a bit table."""
    bits = []
    for value in values:
        try:
            number = int(value["value"])
        except ValueError:
            return None
        if number <= 0 or number & (number - 1):
            return None
        bits.append({"bit": number.bit_length() - 1, "meaning": value["meaning"]})
    if len(bits) < 3 or len({b["bit"] for b in bits}) != len(bits):
        return None
    return sorted(bits, key=lambda b: b["bit"])


PLACEHOLDER_SUMMARY = re.compile(r"^(Controls `[^`]+` in the [\w-]+ module\.|Registered by the current source)")


def summary(entry: dict) -> str:
    """The reference's one-line summary, left out where it only restates the name."""
    text = entry.get("summary") or ""
    return "" if PLACEHOLDER_SUMMARY.match(text) else text


def generic_boolean(values: list[dict]) -> bool:
    """The reference's inferred 0/1 pair says nothing a host needs, and is wrong for intervals
    such as g_forceRegenTime, so the generator leaves it out."""
    return [(v["value"], v["meaning"]) for v in values] == [("0", "Disabled."), ("1", "Enabled.")]


def reference_cvars(cvars: list[dict], server_scope: set[str], overrides: dict, settable: set[str]) -> dict:
    table = {}
    for entry in cvars:
        modules = set(entry.get("modules") or [entry["module"]])
        if not modules & SERVER_MODULES:
            continue
        key = entry["name"].lower()
        engine = not modules & {"game"}
        item = {
            "n": entry["name"],
            "u": detail_url(entry),
            "e": 1 if engine else 0,
            "b": 0 if "basejka" in entry.get("baselines", []) else 1,
            "d": entry.get("default") or "",
            "s": summary(entry),
            "f": "server" if engine or key in server_scope else "default",
        }
        if entry.get("engine_managed") and key not in settable:
            item["em"] = 1
        options = (entry.get("bits") or {}).get("options") or []
        if key in overrides:
            item["bits"] = [[o["bit"], o["meaning"]] for o in overrides[key]]
        elif options:
            item["bits"] = [[o["bit"], o["meaning"]] for o in options]
        else:
            as_bits = power_of_two_bits(entry.get("values") or [])
            if as_bits:
                item["bits"] = [[b["bit"], b["meaning"]] for b in as_bits]
            elif entry.get("values") and not generic_boolean(entry["values"]):
                item["v"] = [[v["value"], v["meaning"]] for v in entry["values"]]
        table[key] = item
    return table


def reference_commands(commands: list[dict], wanted: set[str]) -> dict:
    table = {}
    for entry in commands:
        key = entry["name"].lower()
        if key in wanted and set(entry.get("modules") or [entry["module"]]) & SERVER_MODULES:
            table[key] = {"n": entry["name"], "u": detail_url(entry), "b": 0 if "basejka" in entry.get("baselines", []) else 1}
    missing = wanted - set(table)
    if missing:
        raise BuildError(f"commands missing from the reference: {', '.join(sorted(missing))}")
    return table


# --- Config parsing ----------------------------------------------------------------------------


def split_comment(line: str) -> tuple[str, str]:
    """Split at the first // outside quotes, as the engine's tokenizer does."""
    quoted = False
    for index, char in enumerate(line):
        if char == '"':
            quoted = not quoted
        elif not quoted and line.startswith("//", index):
            return line[:index].rstrip(), line[index + 2:].strip()
    return line.rstrip(), ""


def tokens(text: str) -> list[str]:
    return [a if a else b for a, b in re.findall(r'"([^"]*)"|(\S+)', text)]


class Names:
    def __init__(self, cvars: dict, commands: dict, items: list[str], dropped: dict):
        self.cvars, self.commands, self.dropped = cvars, commands, dropped
        self.items = {f"disable_{name}".lower(): f"disable_{name}" for name in items}

    def cvar(self, name: str, where: str) -> str | None:
        key = name.lower()
        if key in self.dropped:
            return None
        if key in self.items:
            return self.items[key]
        entry = self.cvars.get(key)
        if not entry:
            raise BuildError(f"{where}: unknown cvar {name}")
        if entry.get("em"):
            raise BuildError(f"{where}: {name} is engine-managed and must never be written")
        return entry["n"]

    def is_cvar(self, name: str) -> bool:
        key = name.lower()
        return key in self.cvars or key in self.items or key in self.dropped

    def command(self, name: str, where: str) -> str:
        entry = self.commands.get(name.lower())
        if not entry:
            raise BuildError(f"{where}: unknown command {name}")
        return entry["n"]

    def check_run(self, run: str, where: str) -> None:
        """Validate a vote option's commands, separated by semicolons."""
        for part in run.split(";"):
            words = tokens(part)
            if not words:
                continue
            if self.is_cvar(words[0]):
                self.cvar(words[0], where)
            else:
                self.command(words[0], where)


def note_text(comment: str) -> str | None:
    """Trailing comments that only list old values are dropped; ones with words are kept."""
    return comment if re.search(r"[A-Za-z]", comment) else None


def parse_cfg(text: str, names: Names, where: str) -> list[dict]:
    statements = []
    for number, raw in enumerate(text.splitlines(), start=1):
        line = raw.strip()
        here = f"{where}:{number}"
        if not line:
            statements.append({"t": "blank"})
            continue
        code, comment = split_comment(line)
        if not code:
            statements.append({"t": "comment", "text": comment})
            continue
        words = tokens(code)
        head = words[0].lower()
        if head in ("set", "seta", "sets", "setu"):
            name = names.cvar(words[1], here)
            if name:
                statements.append({"t": "cvar", "name": name, "value": " ".join(words[2:]), "note": note_text(comment)})
        elif head == "exec":
            statements.append({"t": "exec", "file": words[1].removesuffix(".cfg")})
        elif names.is_cvar(words[0]):
            name = names.cvar(words[0], here)
            if name:
                statements.append({"t": "cvar", "name": name, "value": " ".join(words[1:]), "note": note_text(comment)})
        else:
            words[0] = names.command(words[0], here)
            statements.append({"t": "cmd", "text": " ".join(words)})
    while statements and statements[-1]["t"] == "blank":
        statements.pop()
    # A cvar set twice in one file ends at its last value; keep only that line.
    last = {s["name"].lower(): i for i, s in enumerate(statements) if s["t"] == "cvar"}
    return [s for i, s in enumerate(statements) if s["t"] != "cvar" or last[s["name"].lower()] == i]


def sections(statements: list[dict]) -> list[dict]:
    """Group a file into titled sections: a comment line after a blank line starts one."""
    result, current, previous = [], None, "blank"
    for statement in statements:
        kind = statement["t"]
        if kind == "comment" and previous == "blank":
            title = statement["text"].strip("-/ ")
            current = {"title": title, "lines": []}
            result.append(current)
        elif kind == "cvar":
            if current is None:
                current = {"title": "", "lines": []}
                result.append(current)
            current["lines"].append([statement["name"], statement["value"], statement["note"]])
        elif kind == "comment" and current is not None and current["lines"]:
            pass  # interior commentary is dropped; section titles carry the structure
        previous = kind
    return [s for s in result if s["lines"]]


# --- Build -------------------------------------------------------------------------------------


def build() -> dict:
    meta = json.loads((ROOT / "_data" / "reference-meta.json").read_text())
    source_commit = meta["source_commit"]
    sources, settings, presets, modes, votes = (load(n) for n in ("sources.json", "settings.json", "presets.json", "modes.json", "votes.json"))
    docker_commit = sources["docker_commit"]

    items = item_classnames(git_show(source_commit, "codemp/game/bg_misc.c"))
    weapons = enum_members(git_show(source_commit, "codemp/game/bg_weapons.h"), "weapon_t", "WP_")
    powers = enum_members(git_show(source_commit, "codemp/qcommon/q_shared.h"), "forcePowers_t", "FP_")
    weapon_bits = bit_table(weapons, settings["weapon_labels"], "weapon")
    force_bits = bit_table(powers, settings["force_labels"], "force power")

    docker_files = sorted(f for f in git_ls(docker_commit, sources["docker_dir"]) if f.endswith(".cfg"))
    docker_text = {f.removesuffix(".cfg"): git_show(docker_commit, f"{sources['docker_dir']}/{f}") for f in docker_files}

    # Game cvars the bundled server.cfg sets are server settings, never gameplay.
    server_scope = {n.lower() for n in settings["server_scope"]}
    for match in re.finditer(r"^\s*seta?\s+(\w+)", docker_text["server"], re.M):
        if match.group(1).lower() not in FLOW_CVARS:
            server_scope.add(match.group(1).lower())

    overrides = {name: table["options"] for name, table in settings["bit_overrides"].items()}
    overrides.update({"g_weapondisable": weapon_bits, "g_duelweapondisable": weapon_bits, "g_forcepowerdisable": force_bits})
    cvar_table = reference_cvars(
        json.loads((ROOT / "_data" / "cvars.json").read_text()), server_scope, overrides,
        {k.lower() for k in sources["settable"]},
    )
    wanted_commands = {"exec", "map", "map_restart", "vstr", "kick", "addbot", "gametype", "resetscores", "startingitems"}
    command_table = reference_commands(json.loads((ROOT / "_data" / "commands.json").read_text()), wanted_commands)
    names = Names(cvar_table, command_table, items, {k.lower(): v for k, v in sources["dropped"].items()})

    generated_here = ("votes", "bans")
    parsed = {
        name: parse_cfg(text, names, f"{sources['docker_dir']}/{name}.cfg")
        for name, text in docker_text.items() if name not in generated_here
    }

    # votes.cfg is regenerated from votes.json; fail when the bundled file gains an option it lacks.
    bundled_votes = dict(re.findall(r'^\s*seta?\s+(\S+)\s+"([^"]*)"', docker_text["votes"], re.M))
    catalogue = {o["id"] for o in votes["always"]} | {o["id"] for g in votes["groups"] for o in g["options"]}
    catalogue |= {o["id"] for extras in votes["mode_extras"].values() for o in extras}
    catalogue |= {m["id"] for m in modes["japro"]["modes"]} | {a["id"] for a in modes["japro"]["addons"]}
    missing_votes = set(bundled_votes) - catalogue - set(votes["left_out"])
    if missing_votes:
        raise BuildError(f"bundled votes.cfg options missing from votes.json: {', '.join(sorted(missing_votes))}")

    # The bundled default.cfg's flow settings move to the game-flow step.
    bundled_default = []
    bundled_flow = {}
    for statement in parsed["default"]:
        if statement["t"] == "cvar" and statement["name"].lower() in FLOW_CVARS:
            bundled_flow[statement["name"].lower()] = statement["value"]
        elif statement["t"] == "cmd" and statement["text"].startswith("gametype "):
            bundled_flow["g_gametype"] = statement["text"].split()[1]
        else:
            bundled_default.append(statement)
    unexpected = [s for s in bundled_default if s["t"] not in ("cvar", "comment", "blank")]
    if unexpected:
        raise BuildError(f"default.cfg has statements the generator cannot place: {unexpected}")

    server_sections = []
    for section in sections(parsed["server"]):
        lines = [l for l in section["lines"] if l[0].lower() not in BASICS_CVARS | FLOW_CVARS]
        if lines:
            server_sections.append({"title": section["title"], "lines": lines})

    mode_ids = [m["id"] for m in modes["japro"]["modes"]]
    addon_ids = [a["id"] for a in modes["japro"]["addons"]]
    known_files = set(mode_ids) | set(addon_ids) | set(modes["japro"]["helpers"]) | {"server", "default"}
    stray = set(parsed) - known_files
    if stray:
        raise BuildError(f"bundled configs not in modes.json: {', '.join(sorted(stray))}")
    for mode_id in mode_ids + addon_ids + list(modes["japro"]["helpers"]):
        if mode_id not in parsed:
            raise BuildError(f"modes.json names {mode_id}, which is not a bundled config")
        for statement in parsed[mode_id]:
            if statement["t"] == "exec" and statement["file"] not in parsed:
                raise BuildError(f"{mode_id}.cfg runs exec {statement['file']}, which is not bundled")
            if statement["t"] == "cvar" and cvar_table.get(statement["name"].lower(), {}).get("f") == "server":
                raise BuildError(f"{mode_id}.cfg sets {statement['name']}, a server setting modes must not change")

    # Presets: canonical names, and base-target presets use only base-game cvars.
    for target, entries in presets.items():
        if target.startswith("_"):
            continue
        for preset in entries:
            for part in ("default", "server"):
                for line in preset.get(part, []):
                    if isinstance(line, dict):
                        continue
                    where = f"presets.json {target}/{preset['id']}"
                    line[0] = names.cvar(line[0], where)
                    key = line[0].lower()
                    if part == "server" and key in cvar_table and cvar_table[key]["f"] != "server":
                        raise BuildError(f"{where}: {line[0]} is gameplay, not a server setting")
                    if part == "default" and key in cvar_table and cvar_table[key]["f"] == "server":
                        raise BuildError(f"{where}: {line[0]} is a server setting; put it under server")
                    if target != "japro" and key in cvar_table and not cvar_table[key]["b"]:
                        raise BuildError(f"{where}: {line[0]} is not in base Jedi Academy")

    for mode in modes["base"]["modes"]:
        for bot in mode.get("bots", []):
            if not re.fullmatch(r"\w+ \d+ (red|blue|free)", bot):
                raise BuildError(f"modes.json base/{mode['id']}: bot line {bot!r}")
    for item in modes["base"]["pickup_items"] + settings["pickups"]:
        if item not in items:
            raise BuildError(f"{item} is not an item classname")

    for group in settings["groups"]:
        group["names"] = [names.cvar(n, f"settings.json {group['title']}") for n in group["names"]]
    settings["notes"] = {names.cvar(n, "settings.json notes"): text for n, text in settings["notes"].items()}

    for option in votes["always"] + [o for extras in votes["mode_extras"].values() for o in extras]:
        names.check_run(option["run"], f"votes.json {option['id']}")
    for group in votes["groups"]:
        for option in group["options"]:
            names.check_run(re.sub(r"\{baseline:\w+\}", "0", option["run"]), f"votes.json {option['id']}")
    vote_ids = [o["id"] for o in votes["always"]] + [o["id"] for g in votes["groups"] for o in g["options"]]
    vote_ids += [o["id"] for extras in votes["mode_extras"].values() for o in extras] + mode_ids + addon_ids
    duplicates = {v for v in vote_ids if vote_ids.count(v) > 1}
    if duplicates:
        raise BuildError(f"vote option names used twice: {', '.join(sorted(duplicates))}")

    for part in (presets, modes, votes, settings):
        part.pop("_comment", None)
    del settings["bit_overrides"], settings["weapon_labels"], settings["force_labels"], settings["server_scope"]

    return {
        "meta": {
            "docker_commit": docker_commit,
            "source_commit": source_commit,
            "docker_url": f"https://github.com/taysta/TaystJK/tree/{docker_commit}/{sources['docker_dir']}",
            "settable": sources["settable"],
        },
        "cvars": cvar_table,
        "commands": command_table,
        "items": items,
        "docker": {
            "server": server_sections,
            "default": sections(bundled_default),
            "flow": bundled_flow,
            "files": {k: v for k, v in parsed.items() if k not in ("server", "default")},
        },
        "presets": presets,
        "modes": modes,
        "votes": votes,
        "settings": settings,
    }


def render(data: dict) -> str:
    """One line per cvar and per top-level section, so diffs stay readable without the bulk."""
    compact = lambda value: json.dumps(value, ensure_ascii=False, separators=(",", ":"))
    parts = []
    for key, value in data.items():
        if key == "cvars":
            rows = [f"  {compact(name)}:{compact(entry)}" for name, entry in value.items()]
            parts.append(f"{compact(key)}:{{\n" + ",\n".join(rows) + "\n}")
        else:
            parts.append(f"{compact(key)}:{compact(value)}")
    return "{\n" + ",\n".join(parts) + "\n}\n"


def main() -> None:
    try:
        text = render(build())
    except BuildError as error:
        raise SystemExit(f"config generator data: {error}")
    if "--check" in sys.argv[1:]:
        if not OUTPUT.exists() or OUTPUT.read_text() != text:
            raise SystemExit(f"{OUTPUT.relative_to(ROOT)} is out of date; run python3 tools/config_generator/build.py")
        print("config generator data is up to date")
        return
    OUTPUT.write_text(text)
    print(f"wrote {OUTPUT.relative_to(ROOT)} ({len(text) // 1024} KiB)")


if __name__ == "__main__":
    main()
