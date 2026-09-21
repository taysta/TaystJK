#!/usr/bin/env python3
"""Build evidence-backed cvar and command data from extraction/provenance caches."""

from __future__ import annotations

import argparse
import json
import re
import subprocess
from collections import Counter, defaultdict
from pathlib import Path
from typing import Any, Iterable

from extract import mask_comments, source_files, split_fields, string_literal
from provenance import BASEJKA_REF, CURRENT_REF, EXTRACTOR_VERSION, UPSTREAM_REFS, extract_ref


MODULE_ORDER = (
    "cgame", "game", "engine-client", "engine-server", "engine-shared",
    "ui", "renderer", "botlib", "game-console", "other",
)


def git(*args: str) -> str:
    result = subprocess.run(
        ["git", *args], check=False, text=True, errors="replace",
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    if result.returncode:
        raise RuntimeError(f"git {' '.join(args)} failed: {result.stderr.strip()}")
    return result.stdout


def load(path: Path) -> Any:
    return json.loads(path.read_text())


def write(path: Path, value: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n")


def group(records: Iterable[dict[str, Any]]) -> dict[str, list[dict[str, Any]]]:
    result: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        result[record["name"].casefold()].append(record)
    return dict(result)


def unique(values: Iterable[Any]) -> list[Any]:
    result: list[Any] = []
    for value in values:
        if value not in result:
            result.append(value)
    return result


def choose_module(name: str, modules: list[str]) -> str:
    hints = (
        ("cg_", "cgame"), ("ui_", "ui"), ("cl_", "engine-client"),
        ("sv_", "engine-server"), ("r_", "renderer"), ("s_", "engine-client"),
        ("g_", "game"), ("bot_", "botlib"),
    )
    folded = name.casefold()
    for prefix, module in hints:
        if folded.startswith(prefix) and module in modules:
            return module
    return next((module for module in MODULE_ORDER if module in modules), modules[0] if modules else "other")


def category_for(name: str, kind: str, module: str, summary: str) -> str:
    """Assign one stable, user-facing topic to each console entry."""
    value = name.casefold().lstrip("+-")
    feature_topics = {
        "Killfeed": "HUD & interface",
        "Movement keys": "Movement & race",
        "Speedometer": "Movement & race",
        "Strafe helper": "Movement & race",
        "Strafe trail": "Movement & race",
        "SnapHUD": "Movement & race",
        "Pitch HUD": "Movement & race",
        "Pitch helper": "Movement & race",
        "Race timer": "Movement & race",
        "Race start": "Movement & race",
        "Checkpoints": "Movement & race",
        "Chat box": "Chat & social",
        "Crosshair": "Crosshair & aiming",
        "Third-person camera": "HUD & interface",
        "HUD timer": "HUD & interface",
        "Console": "Engine & diagnostics",
        "Server browser": "Server & networking",
        "Downloads": "Files & downloads",
        "Automap": "HUD & interface",
        "Bloom": "Graphics & rendering",
        "Auto exposure": "Graphics & rendering",
        "Shadows": "Graphics & rendering",
        "Dynamic lights": "Graphics & rendering",
        "Volumetric fog": "Graphics & rendering",
        "Wind": "Graphics & rendering",
        "Renderer extensions": "Graphics & rendering",
        "Elo rankings": "Gameplay & combat",
        "Duel settings": "Gameplay & combat",
        "Grapple": "Gameplay & combat",
    }
    feature = feature_for(name)
    if feature:
        return feature_topics[feature]
    rules = (
        ("Movement & race", ("strafe", "snaphud", "pitchhud", "pitchhelper", "speedometer", "racetimer", "racestart", "checkpoint", "jumpgoal", "startgoal", "movementkeys")),
        ("Crosshair & aiming", ("crosshair", "crosshairnames", "zoomfov", "weaponfov", "fovviewmodel")),
        ("Audio & music", ("sound", "music", "openal", "volume", "s_mixahead", "s_doppler", "s_khz")),
        ("Demos & media", ("demo", "screenshot", "avi", "video", "record", "levelshot")),
        ("Files & downloads", ("download", "referencedpak", "fs_", "pak", "path", "fdir", "dir")),
        ("Server & networking", ("server", "connect", "disconnect", "net_", "sv_", "ping", "packet", "master", "heartbeat", "rcon")),
        ("Administration", ("admin", "ban", "kick", "silence", "freeze", "protect", "empower", "grant", "whois", "amlogin", "amlogout", "ammap", "amtele", "amrename", "amslap", "amsleep", "amwake")),
        ("Bots & AI", ("bot", "npc", "nav", "waypoint")),
        ("Input & controls", ("bind", "unbind", "key", "mouse", "joystick", "in_", "sensitivity", "m_pitch", "m_yaw", "button")),
        ("Chat & social", ("chat", "message", "tell", "say", "ignore", "clan", "vgs", "motd")),
        ("Gameplay & combat", ("saber", "weapon", "force", "duel", "attack", "damage", "health", "team", "gametype", "fraglimit", "timelimit", "kill", "score")),
        ("Graphics & rendering", ("renderer", "render", "r_", "gl_", "vulkan", "rend2", "bloom", "shadow", "texture", "light", "gamma", "fullscreen", "resolution", "vid_", "gfx")),
        ("HUD & interface", ("hud", "draw", "ui_", "menu", "scoreboard", "camera", "thirdperson")),
        ("Engine & diagnostics", ("com_", "sys_", "developer", "debug", "error", "crash", "memory", "mem", "cvar", "cmdlist", "version")),
    )
    for category, needles in rules:
        if any(needle in value for needle in needles):
            return category
    fallbacks = {
        "renderer": "Graphics & rendering",
        "ui": "HUD & interface",
        "engine-server": "Server & networking",
        "game-console": "Server & networking",
        "botlib": "Bots & AI",
        "cgame": "Gameplay & combat",
        "game": "Gameplay & combat",
        "engine-client": "Engine & diagnostics",
        "engine-shared": "Engine & diagnostics",
    }
    return fallbacks.get(module, "Other")


def feature_for(name: str) -> str | None:
    """Assign a narrow feature family when a name is one of several related controls."""
    value = name.casefold().lstrip("+-")
    rules = (
        ("Killfeed", ("cg_killfeed", "cg_killmessage")),
        ("Movement keys", ("cg_movementkeys",)),
        ("Speedometer", ("cg_speedometer", "speedometer")),
        ("Strafe helper", ("cg_strafehelper", "strafehelper")),
        ("Strafe trail", ("cg_logstrafetrail", "cg_strafetrail", "strafetrail")),
        ("SnapHUD", ("cg_snaphud",)),
        ("Pitch HUD", ("cg_pitchhud",)),
        ("Pitch helper", ("cg_pitchhelper",)),
        ("Race timer", ("cg_racetimer",)),
        ("Race start", ("cg_racestart",)),
        ("Checkpoints", ("addcheckpoint", "deletecheckpoint", "listcheckpoint", "migratecheckpoint", "teletocheckpoint", "cg_jumpgoal", "cg_startgoal")),
        ("Chat box", ("cg_chatbox", "cg_cleanchatbox")),
        ("Crosshair", ("cg_crosshair", "cg_drawcrosshair", "cg_dynamiccrosshair", "cg_thirdpersoncrosshair")),
        ("Third-person camera", ("cg_thirdperson",)),
        ("HUD timer", ("cg_drawtimer",)),
        ("Console", ("con_",)),
        ("Server browser", ("ui_browser",)),
        ("Downloads", ("cl_download",)),
        ("Automap", ("r_automap", "automap_")),
        ("Bloom", ("r_bloom",)),
        ("Auto exposure", ("r_autoexposure", "r_forceautoexposure", "ui_r_autoexposure")),
        ("Shadows", ("r_shadow", "ui_r_shadow")),
        ("Dynamic lights", ("r_dlight",)),
        ("Volumetric fog", ("r_volumetricfog",)),
        ("Wind", ("r_wind",)),
        ("Renderer extensions", ("r_ext_", "ui_r_ext_")),
        ("Elo rankings", ("g_elo",)),
        ("Duel settings", ("g_duel",)),
        ("Grapple", ("g_hook", "grapple")),
    )
    return next((feature for feature, prefixes in rules if value.startswith(prefixes)), None)


def source_url(path: str, line: int, sha: str) -> str:
    return f"https://github.com/taysta/TaystJK/blame/{sha}/{path}#L{line}"


def clean_description(value: str | None) -> str | None:
    if not value:
        return None
    value = value.replace("\\n", " ").replace("\\t", " ").strip().strip("/ ")
    folded = value.casefold()
    if (
        not value
        or folded in {
            "bitvalue", "fixme", "todo", "none", "s ?", "sad hack",
            "japro engine", "loda - fps unlock engine", "shared with ui module",
            "should remove", "cvar_temp )", "xd", "race also", "inherited bloat",
            "ethan wants this archive", "from smod", "wt_tribes",
        }
        or not re.search(r"[A-Za-z]{2}", value)
        or re.search(r"\b(?:XCVAR_DEF|Cvar_(?:Get|Register|Set))\s*\(", value)
    ):
        return None
    value = re.sub(r"\s+", " ", value)
    return value[0].upper() + value[1:] if value else None


def parse_japro_docs() -> dict[str, dict[str, Any]]:
    try:
        text = git("show", f"{CURRENT_REF}:docs/japro_docs.md")
    except RuntimeError:
        return {}
    descriptions: dict[str, dict[str, Any]] = {}
    for line_number, line in enumerate(text.splitlines(), 1):
        match = re.match(r"\s*([+A-Za-z_][A-Za-z0-9_+.-]*)\b(.*)", line)
        if not match or "//" not in match.group(2):
            continue
        description = clean_description(match.group(2).split("//", 1)[1])
        if description:
            descriptions.setdefault(match.group(1).casefold(), {
                "summary": description,
                "evidence": {"path": "docs/japro_docs.md", "line": line_number},
            })
    return descriptions


def parse_jk2mv_docs() -> dict[str, dict[str, Any]]:
    """Read JK2MV's checked-in cvar reference as upstream documentation."""
    try:
        text = git("show", "jk2mv/master:CVARS.rst")
        sha = git("rev-parse", "jk2mv/master").strip()
    except RuntimeError:
        return {}
    result: dict[str, dict[str, Any]] = {}
    starts = list(re.finditer(r"^:Name:\s*(\S+)\s*$", text, re.M))
    for index, match in enumerate(starts):
        end = starts[index + 1].start() if index + 1 < len(starts) else len(text)
        block = text[match.start():end]
        description_match = re.search(r"^:Description:\s*\n(.*?)(?=^\.\.\s*$|\Z)", block, re.M | re.S)
        if not description_match:
            continue
        description_start = match.start() + description_match.start(1)
        description_line = text.count("\n", 0, description_start) + 1
        raw_lines = description_match.group(1).splitlines()
        prose_parts: list[str] = []
        values: list[dict[str, Any]] = []
        for offset, raw_line in enumerate(raw_lines):
            line = raw_line.strip()
            if not line:
                continue
            option = re.match(r"\|\s*([^:]+):\s*(.+)", line)
            if option:
                values.append({
                    "value": option.group(1).strip().strip('"'),
                    "meaning": option.group(2).strip().rstrip(".") + ".",
                    "evidence": {
                        "path": "CVARS.rst", "line": description_line + offset,
                        "url": f"https://github.com/mvdevs/jk2mv/blame/{sha}/CVARS.rst#L{description_line + offset}",
                    },
                })
            else:
                prose_parts.append(line)
        prose = clean_description(" ".join(prose_parts).replace("``", "`"))
        if not prose and values:
            prose = f"Selects one of the modes documented by JK2MV for `{match.group(1)}`."
        if prose:
            result[match.group(1).casefold()] = {
                "summary": prose,
                "values": values,
                "evidence": {
                    "path": "CVARS.rst", "line": description_line,
                    "url": f"https://github.com/mvdevs/jk2mv/blame/{sha}/CVARS.rst#L{description_line}",
                },
            }
    return result


def macro_calls(text: str, prefix: str) -> Iterable[tuple[str, int, str]]:
    start_re = re.compile(rf"\b({re.escape(prefix)}[A-Z_]*)\s*\(")
    for match in start_re.finditer(text):
        depth = 1
        in_string = escaped = False
        pos = match.end()
        while pos < len(text) and depth:
            ch = text[pos]
            if in_string:
                if escaped:
                    escaped = False
                elif ch == "\\":
                    escaped = True
                elif ch == '"':
                    in_string = False
            elif ch == '"':
                in_string = True
            elif ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            pos += 1
        if depth == 0:
            yield match.group(1), text.count("\n", 0, match.start()) + 1, text[match.end():pos - 1]


def parse_xdocs() -> tuple[dict[str, dict[str, Any]], dict[str, dict[str, Any]]]:
    cvars: dict[str, dict[str, Any]] = {}
    commands: dict[str, dict[str, Any]] = {}
    for path in ("codemp/ui/ui_xdocs.h", "codemp/ui/nm_xdocumentation.h"):
        try:
            text = git("show", f"{CURRENT_REF}:{path}")
        except RuntimeError:
            continue
        for macro, line, body in macro_calls(mask_comments(text), "XDOCS_"):
            if macro not in {
                "XDOCS_CVAR_DEF", "XDOCS_CVAR_BITVALUE_DEF", "XDOCS_CVAR_BITFLAG_DEF",
                "XDOCS_CVAR_KEYVALUE_DEF", "XDOCS_CMD_DEF",
            }:
                continue
            fields = split_fields(body)
            if len(fields) < 2:
                continue
            name = string_literal(fields[0])
            summary = clean_description(string_literal(fields[1]))
            if not name:
                continue
            item: dict[str, Any] = {
                "summary": summary,
                "evidence": {"path": path, "line": line},
                "values": [],
            }
            if len(fields) > 2:
                long_text = fields[2]
                for setting in re.finditer(
                    r"SETTING\s*\(\s*\"((?:\\.|[^\"\\])*)\"\s*,\s*\"((?:\\.|[^\"\\])*)\"\s*\)",
                    long_text,
                ):
                    setting_line = line + body.count("\n", 0, setting.start())
                    item["values"].append({
                        "value": setting.group(1), "meaning": setting.group(2),
                        "evidence": {"path": path, "line": setting_line},
                    })
            destination = commands if macro == "XDOCS_CMD_DEF" else cvars
            destination.setdefault(name.casefold(), item)
    return cvars, commands


def parse_menu_entries(wanted: set[str]) -> dict[str, list[dict[str, Any]]]:
    """Find console names used by shipped in-game .menu definitions."""
    result: dict[str, list[dict[str, Any]]] = defaultdict(list)
    paths = [
        path for path in git("ls-tree", "-r", "--name-only", CURRENT_REF, "--", "assets").splitlines()
        if path.endswith(".menu")
    ]
    token_re = re.compile(r"(?<![A-Za-z0-9_])[+-]?[A-Za-z_][A-Za-z0-9_.+-]*(?![A-Za-z0-9_])")
    for path in paths:
        try:
            text = mask_comments(git("show", f"{CURRENT_REF}:{path}"))
        except RuntimeError:
            continue
        for line_number, line in enumerate(text.splitlines(), 1):
            keys = {token.casefold() for token in token_re.findall(line)} & wanted
            for key in keys:
                if len(result[key]) < 6:
                    result[key].append({"path": path, "line": line_number})
    return dict(result)


def build_occurrence_index(
    files: list[tuple[str, str]], wanted: set[str], limit: int = 120,
) -> dict[str, list[dict[str, Any]]]:
    index: dict[str, list[dict[str, Any]]] = defaultdict(list)
    token_re = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
    for path, text in files:
        for number, line in enumerate(text.splitlines(), 1):
            folded_tokens = {token.casefold() for token in token_re.findall(line)}
            for token in folded_tokens & wanted:
                if len(index[token]) < limit:
                    index[token].append({"path": path, "line": number, "text": line.strip()})
    return index


def useful_occurrences(
    name: str, variables: list[str], registrations: list[dict[str, Any]],
    index: dict[str, list[dict[str, Any]]], limit: int = 5,
) -> list[dict[str, Any]]:
    registration_sites = {(record["path"], record["line"]) for record in registrations}
    candidates: list[dict[str, Any]] = []
    tokens = variables or ([name] if len(name) > 3 else [])
    for token in tokens:
        for occurrence in index.get(token.casefold(), []):
            if (occurrence["path"], occurrence["line"]) in registration_sites:
                continue
            line = occurrence["text"]
            if re.search(r"(?:XCVAR_DEF|Cvar_(?:Register|Get|Update)|extern\s+.*cvar|vmCvar_t|cvar_t\s*\*)", line):
                continue
            score = 0
            if re.search(r"(?:\. |->)?(?:integer|value|string)".replace(" ", ""), line):
                score += 4
            if re.search(r"(?:if|switch|while)\s*\(", line):
                score += 2
            if any(operator in line for operator in ("&", "==", "!=", ">", "<")):
                score += 1
            candidate = dict(occurrence)
            candidate["score"] = score
            candidates.append(candidate)
    candidates.sort(key=lambda item: (-item["score"], item["path"], item["line"]))
    selected: list[dict[str, Any]] = []
    seen: set[tuple[str, int]] = set()
    for candidate in candidates:
        site = (candidate["path"], candidate["line"])
        if site in seen:
            continue
        seen.add(site)
        selected.append(candidate)
        if len(selected) == limit:
            break
    return selected


def numeric_default(default: str | None) -> float | None:
    if default is None:
        return None
    try:
        return float(default.rstrip("fF"))
    except ValueError:
        return None


def infer_type(default: str | None, variables: list[str], occurrences: list[dict[str, Any]]) -> str:
    text = "\n".join(item["text"] for item in occurrences)
    escaped = "|".join(re.escape(variable) for variable in variables)
    # A single `&` is a mask test; `&&` is just a boolean guard such as
    # `r_clear->integer && vk.clearAttachment`, which says nothing about the
    # value's shape.
    if escaped and re.search(rf"(?:{escaped})(?:\. |->)integer\s*&(?!&)".replace(" ", ""), text):
        return "bitmask"
    if escaped and re.search(rf"sscanf\s*\([^\n]*(?:{escaped})(?:\. |->)string[^\n]*%[fdi][^\n]*%[fdi][^\n]*%[fdi]".replace(" ", ""), text):
        return "color"
    if re.search(r"(?:\.string|->string)\b", text):
        return "string"
    if re.search(r"(?:\.value|->value)\b", text):
        return "float"
    if re.search(r"(?:\.integer|->integer)\b", text):
        compared = {int(value) for value in re.findall(r"(?:==|!=)\s*(-?\d+)", text)}
        if any(value not in {0, 1} for value in compared):
            return "enum"
        value = numeric_default(default)
        if value in {0.0, 1.0} and not compared.difference({0, 1}):
            return "bool"
        return "int"
    value = numeric_default(default)
    if value is not None:
        return "float" if any(ch in (default or "") for ch in ".eE") else "int"
    return "string" if default is not None else "unknown"


def define_index(files: list[tuple[str, str]]) -> dict[str, tuple[str, str, int]]:
    result: dict[str, tuple[str, str, int]] = {}
    for path, text in files:
        for number, line in enumerate(text.splitlines(), 1):
            match = re.match(r"\s*#\s*define\s+([A-Z][A-Z0-9_]*)\s+(.+?)(?:\s*//\s*(.*))?$", line)
            if match:
                value = match.group(2).strip()
                comment = (match.group(3) or "").strip()
                result[match.group(1)] = (value + (f" // {comment}" if comment else ""), path, number)
    return result


def infer_values(
    value_type: str, variables: list[str], occurrences: list[dict[str, Any]],
    definitions: dict[str, tuple[str, str, int]], description: str | None,
    documentation_evidence: dict[str, Any] | None = None,
) -> list[dict[str, Any]]:
    if description:
        markers = list(re.finditer(
            r"(?<![A-Za-z0-9_.])(-?\d+(?:\.\d+)?\+?)\s*(?:=|:|\s+-\s+)",
            description,
        ))
        # Multiple explicit value markers are strong enough to publish as an
        # option table. A lone number may just be a range, duration, or default.
        if len(markers) >= 2 and documentation_evidence:
            documented_values: list[dict[str, Any]] = []
            for index, marker in enumerate(markers):
                end = markers[index + 1].start() if index + 1 < len(markers) else len(description)
                meaning = description[marker.end():end].strip(" -.;|,")
                if meaning:
                    documented_values.append({
                        "value": marker.group(1),
                        "meaning": meaning[0].upper() + meaning[1:] + ("" if meaning.endswith(".") else "."),
                        "evidence": documentation_evidence,
                    })
            if len(documented_values) >= 2:
                return documented_values
    if value_type == "bool":
        evidence = occurrences[0] if occurrences else None
        return [
            {"value": "0", "meaning": "Disabled.", "evidence": evidence},
            {"value": "1", "meaning": "Enabled.", "evidence": evidence},
        ]
    values: list[dict[str, Any]] = []
    text = "\n".join(item["text"] for item in occurrences)
    if value_type == "enum":
        found = sorted({int(value) for value in re.findall(r"(?:==|!=)\s*(-?\d+)", text)})
        for value in found:
            evidence = next((item for item in occurrences if re.search(rf"(?:==|!=)\s*{value}\b", item["text"])), None)
            values.append({
                "value": str(value),
                "meaning": f"Selects the code path tested for value {value}.",
                "evidence": evidence,
            })
    elif value_type == "bitmask":
        symbols: set[str] = set()
        for variable in variables:
            pattern = rf"{re.escape(variable)}(?:\.integer|->integer)\s*&\s*([A-Z][A-Z0-9_]*)"
            symbols.update(re.findall(pattern, text))
        for symbol in sorted(symbols):
            definition = definitions.get(symbol)
            if definition:
                raw, path, line = definition
                shift = re.search(r"1\s*<<\s*(\d+)", raw)
                numeric = str(1 << int(shift.group(1))) if shift else raw.split("//", 1)[0].strip("() ")
                comment = clean_description(raw.split("//", 1)[1]) if "//" in raw else None
                values.append({
                    "value": numeric,
                    "meaning": comment or f"Enables the `{symbol}` code path.",
                    "symbol": symbol,
                    "evidence": {"path": path, "line": line},
                })
    if description:
        documented: dict[str, str] = {}
        for match in re.finditer(r"(?<!\d)(-?\d+)\s*=\s*([^.;]+)", description):
            documented[match.group(1)] = match.group(2).strip()
        for item in values:
            if item["value"] in documented:
                item["meaning"] = documented[item["value"]] + "."
    return values


# Editorial defaults for handwritten features without registration inventories.
# Cvars and commands use registration_baselines instead: origin does not prove
# whether another project currently ships an identifier.
BASELINE_BUCKETS: tuple[tuple[str, frozenset[str]], ...] = (
    ("eternaljk", frozenset({"taystjk", "rend2", "vulkan", "jk2mv", "newjk"})),
    ("openjk", frozenset({"japro", "eternaljk"})),
    ("basejka", frozenset({"openjk"})),
)


def commit_dates(shas: Iterable[str]) -> dict[str, tuple[str, str]]:
    """Map each commit to its (date, abbreviated hash).

    Committer date, not author date.  It is when the change entered this
    repository's history, which is what a reader can compare a build date
    against; an author date can predate integration, by up to two weeks in the
    commits this reference cites.  The abbreviation is Git's own, so it matches
    the hash a build prints.
    """
    wanted = sorted({sha for sha in shas if sha})
    if not wanted:
        return {}
    result = subprocess.run(
        ["git", "log", "--no-walk", "--format=%H %h %cI", "--stdin"],
        input="\n".join(wanted) + "\n", check=False, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    if result.returncode:
        raise RuntimeError(f"git log failed: {result.stderr.strip()}")
    dates: dict[str, tuple[str, str]] = {}
    for line in result.stdout.splitlines():
        full, _, rest = line.partition(" ")
        short, _, iso = rest.partition(" ")
        dates[full] = (iso[:10], short)
    return dates


def added_on_for(
    origin: dict[str, Any], dates: dict[str, tuple[str, str]],
) -> dict[str, Any] | None:
    """When an entry first landed, as `YYYY-MM-DD (shorthash)` plus its commit.

    `certain` is false when the origin itself is only medium-confidence: the
    date is then as provisional as the attribution it rests on, and must not be
    presented as settled.
    """
    sha = origin.get("first_commit")
    resolved = dates.get(sha) if sha else None
    if not resolved:
        return None  # origin unresolved: omit rather than invent a date
    date, short = resolved
    return {
        "date": date,
        "commit": sha,
        "short": short,
        "label": f"{date} ({short})",
        "certain": origin.get("confidence") == "high",
    }


def baseline_for(source: str | None) -> str | None:
    """The default baseline bucket for an editorial feature, or None."""
    for name, sources in BASELINE_BUCKETS:
        if source in sources:
            return name
    return None


def registration_baselines(name: str, inventories: dict[str, set[str]]) -> list[str]:
    """Compare each client independently; their inventories need not be nested."""
    return [baseline for baseline, names in inventories.items() if name.casefold() not in names]


# Flags the engine itself uses to keep a cvar out of the player's hands, plus
# the shape of a cvar the code only ever writes: declared nowhere, so nothing
# the player types survives the next write.  Each basis names its own evidence.
ENGINE_MANAGED_FLAGS = ("CVAR_ROM", "CVAR_INTERNAL")


def engine_managed_basis(
    flags: list[str], records: list[dict[str, Any]], mirror: dict[str, Any] | None = None,
) -> list[str]:
    """Return why a cvar is engine-managed, or an empty list when it is not."""
    basis = [flag for flag in ENGINE_MANAGED_FLAGS if flag in flags]
    if records and all(record["kind"].startswith("implicit") for record in records):
        basis.append("implicit-write")
    if mirror:
        basis.append("menu-mirror")
    return basis


# ``Cvar_Set("r_picmip", UI_Cvar_VariableString("ui_r_picmip"))``.  The menus
# stage a setting in a ``ui_`` copy so the player can discard the change, then
# write it through on accept; ``UI_GetVideoSetup`` reads the real value back the
# other way.  Either direction names the pair, so the mirror's page can say what
# it actually augments instead of leaving a reader to guess from the name.
MENU_MIRROR = re.compile(
    r'Cvar_Set\s*\(\s*"([A-Za-z0-9_]+)"\s*,\s*'
    r'(?:UI_)?Cvar_VariableString\s*\(\s*"([A-Za-z0-9_]+)"\s*\)'
)


# ``static bitInfo_T strafeTweaks[] = { {"Original style"}, ... };`` followed by
# the console handler that toggles one bit of a cvar per invocation.  The table
# is the only place each bit is named, and the handler is the intended way to
# change the cvar, so both belong on the cvar's page.
BIT_TABLE = re.compile(r'\bbitInfo_T\s+(\w+)\s*\[\s*\]\s*=\s*\{(.*?)\}\s*;', re.S)
BIT_LABEL = re.compile(r'\{\s*"((?:[^"\\]|\\.)*)"\s*\}')
BIT_SET = re.compile(r'Cvar_Set\s*\(\s*"([A-Za-z0-9_]+)"')
BIT_HANDLER = re.compile(r'\bvoid\s+(\w+)\s*\(\s*void\s*\)\s*\{')


def calling_handler(files: list[tuple[str, str]], handler: str) -> str | None:
    """The function that calls ``handler``, for a dispatcher one hop from a command.

    ``cosmetics`` registers ``CG_Cosmetics_f``, which forwards to the jaPRO
    variant holding the bit table, so the table's own function is not the name
    the command registration uses.
    """
    call = re.compile(rf"\b{re.escape(handler)}\s*\(")
    for _, text in files:
        masked = mask_comments(text)
        for definition in BIT_HANDLER.finditer(masked):
            # Match on the body, so the handler's own definition is not a call.
            if definition.group(1) == handler:
                continue
            if call.search(balanced_body(masked, definition.end() - 1)):
                return definition.group(1)
    return None


def balanced_body(text: str, brace: int) -> str:
    """Return the block starting at ``brace``, ignoring braces inside strings."""
    depth = 0
    in_string = escaped = False
    for pos in range(brace, len(text)):
        ch = text[pos]
        if in_string:
            if escaped:
                escaped = False
            elif ch == "\\":
                escaped = True
            elif ch == '"':
                in_string = False
        elif ch == '"':
            in_string = True
        elif ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return text[brace + 1:pos]
    return text[brace + 1:]


def bit_option_index(files: list[tuple[str, str]]) -> dict[str, dict[str, Any]]:
    """Pair each bit-label table with the cvars its console command toggles.

    The search is bounded by the handler's own body, not by the next table: the
    last table in a file would otherwise absorb every later function.
    ``toggleAdmin`` drives two cvars from one table, so each target is recorded
    rather than only the first.
    """
    index: dict[str, dict[str, Any]] = {}
    for path, text in files:
        masked = mask_comments(text)
        tables = list(BIT_TABLE.finditer(masked))
        for position, match in enumerate(tables):
            table = match.group(1)
            labels = BIT_LABEL.findall(match.group(2))
            end = tables[position + 1].start() if position + 1 < len(tables) else len(masked)
            following = masked[match.end():end]
            handler = BIT_HANDLER.search(following)
            # An account-flag table with no cvar behind it is not a cvar's bits.
            if not handler or not labels:
                continue
            region = balanced_body(following, following.index("{", handler.end() - 1))
            if table not in region:
                continue
            # Bit order is the array position; the trailing source comments
            # number from 0 in some tables and from 1 in others.
            options = [
                {"bit": bit, "value": str(1 << bit), "meaning": label}
                for bit, label in enumerate(labels) if label.strip()
            ]
            evidence = {"path": path, "line": masked[:match.start()].count("\n") + 1}
            for target in unique(BIT_SET.findall(region)):
                index[target.casefold()] = {
                    "handler": handler.group(1), "options": options, "evidence": evidence,
                }
    return index


def menu_mirror_index(files: list[tuple[str, str]]) -> dict[str, dict[str, Any]]:
    """Pair each menu staging copy with the cvar it writes through to."""
    mirrors: dict[str, dict[str, Any]] = {}
    for path, text in files:
        for number, line in enumerate(mask_comments(text).splitlines(), 1):
            for target, source in MENU_MIRROR.findall(line):
                staged = source.casefold().startswith("ui_")
                if staged == target.casefold().startswith("ui_"):
                    continue
                mirror = source if staged else target
                item = mirrors.setdefault(
                    mirror.casefold(),
                    {"name": mirror, "target": target if staged else source, "apply": None, "read": None},
                )
                item["apply" if staged else "read"] = {"path": path, "line": number}
    return mirrors


CONSTANT_BOUND = re.compile(r"[+-]?(?:0[xX][0-9a-fA-F]+|\d+\.?\d*(?:[eE][+-]?\d+)?)[uUlLfF]*")
MACRO_BOUND = re.compile(r"[A-Z][A-Z0-9_]{2,}")
# ``r_bloom = ri.Cvar_Get("r_bloom", ...)``.  Registrations reached through an
# interface pointer are the norm in the renderers and the game modules.
REGISTRATION_ASSIGNMENT = re.compile(
    r"([A-Za-z_]\w*)\s*=\s*(?:[A-Za-z_]\w*\s*(?:\.|->)\s*)*(?:trap_)?Cvar_Get\s*\(\s*\"([^\"]+)\""
)


def resolve_bound(value: str, definitions: dict[str, tuple[str, str, int]]) -> str:
    """Expand a macro bound such as ``MAX_CLIENTS`` to its literal value."""
    value = value.strip()
    if not MACRO_BOUND.fullmatch(value):
        return value
    definition = definitions.get(value)
    if not definition:
        return value
    body = definition[0].split("//")[0].strip()
    return body if CONSTANT_BOUND.fullmatch(body) else value


def range_index(
    files: list[tuple[str, str]], definitions: dict[str, tuple[str, str, int]],
) -> tuple[dict[str, list[dict[str, Any]]], dict[str, set[str]]]:
    """Index enforced value ranges, and the variables each cvar is bound to.

    Returns ranges keyed by C variable plus a cvar-name to variable map, because
    a cvar registered through an interface pointer records no variable of its
    own and would otherwise never match its own ``Cvar_CheckRange`` call.
    """
    result: dict[str, list[dict[str, Any]]] = defaultdict(list)
    aliases: dict[str, set[str]] = defaultdict(set)
    check = re.compile(
        r"Cvar_CheckRange\s*\(\s*&?([A-Za-z_]\w*)\s*,\s*([^,]+),\s*([^,]+),\s*([^\)]+)\)"
    )
    clamp = re.compile(
        r"Com_Clamp(?:i)?\s*\(\s*([^,]+),\s*([^,]+),\s*([A-Za-z_]\w*)(?:\.(?:integer|value))?\s*\)"
    )
    for path, text in files:
        # Commented-out code is not an enforced range.
        masked = mask_comments(text)
        for match in REGISTRATION_ASSIGNMENT.finditer(masked):
            aliases[match.group(2).casefold()].add(match.group(1).casefold())
        for match in check.finditer(masked):
            result[match.group(1).casefold()].append({
                "min": resolve_bound(match.group(2), definitions),
                "max": resolve_bound(match.group(3), definitions),
                "integral": match.group(4).strip() in {"qtrue", "true", "1"},
                "evidence": {"path": path, "line": masked.count("\n", 0, match.start()) + 1},
                "kind": "Cvar_CheckRange",
                # The call states the bounds; nothing is inferred.
                "confidence": "high",
            })
        for match in clamp.finditer(masked):
            result[match.group(3).casefold()].append({
                "min": resolve_bound(match.group(1), definitions),
                "max": resolve_bound(match.group(2), definitions),
                "integral": "Com_Clampi" in match.group(0),
                "evidence": {"path": path, "line": masked.count("\n", 0, match.start()) + 1},
                "kind": "manual clamp",
                # A clamp sits on one code path and is not a registration-level
                # guarantee the way Cvar_CheckRange is.
                "confidence": "medium",
            })
    return result, aliases


def function_body(
    files: dict[str, str], handler: str, occurrences: list[dict[str, Any]],
) -> tuple[str, str, int] | None:
    if not re.fullmatch(r"[A-Za-z_]\w*", handler):
        return None
    pattern = re.compile(rf"\b{re.escape(handler)}\s*\([^;]*?\)\s*\{{", re.S)
    candidate_paths = unique(item["path"] for item in occurrences if handler in item["text"])
    for path in candidate_paths:
        text = files[path]
        match = pattern.search(text)
        if not match:
            continue
        brace = text.find("{", match.start())
        depth = 0
        in_string = escaped = False
        for pos in range(brace, len(text)):
            ch = text[pos]
            if in_string:
                if escaped:
                    escaped = False
                elif ch == "\\":
                    escaped = True
                elif ch == '"':
                    in_string = False
            elif ch == '"':
                in_string = True
            elif ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    line = text.count("\n", 0, match.start()) + 1
                    return text[brace + 1:pos], path, line
    return None


def command_syntax(name: str, body: str | None) -> tuple[str, str | None]:
    if not body:
        return name, None
    literals = re.findall(r'"((?:\\.|[^"\\])*)"', body)
    usage = next((value for value in literals if re.search(r"usage\s*:", value, re.I)), None)
    if usage:
        rendered = usage.replace("\\n", " ").strip()
        rendered = re.sub(r"^.*?usage\s*:\s*", "", rendered, flags=re.I)
        rendered = re.sub(r"\^[0-9A-Za-z]", "", rendered)
        rendered = rendered.replace('\\"', "").replace("\\t", " ")
        rendered = re.sub(r"^/?\S+", name, rendered, count=1)
        rendered = rendered.replace("%d", "N").replace("%i", "N")
        rendered = re.sub(r"\s+", " ", rendered).strip(" \\.")
        return rendered, usage
    if re.search(r"(?:Cmd_Argv|CG_Argv|trap->Argv|trap_Argv|ConcatArgs)\s*\(", body):
        return f"{name} [arguments]", None
    return name, None


def main() -> None:
    global CURRENT_REF
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--ref", default=CURRENT_REF, help="TaystJK source snapshot to assemble")
    parser.add_argument("--cache", default=".cvar-audit/cache")
    parser.add_argument("--provenance", default=".cvar-audit/provenance.json")
    parser.add_argument("--overrides", default="tools/cvar_audit/overrides.json")
    parser.add_argument("--output-dir", default="_data")
    args = parser.parse_args()
    CURRENT_REF = args.ref

    cache = Path(args.cache)
    current_cvars = extract_ref(CURRENT_REF, "cvars", cache, False)
    current_commands = extract_ref(CURRENT_REF, "commands", cache, False)
    provenance = load(Path(args.provenance))
    overrides = load(Path(args.overrides)) if Path(args.overrides).exists() else {"cvars": {}, "commands": {}}
    files = list(source_files(CURRENT_REF, ".", None))
    current_sha = git("rev-parse", CURRENT_REF).strip()
    upstream_commits = {ref: git("rev-parse", ref).strip() for ref in UPSTREAM_REFS.values()}
    upstream_commits["origin/master"] = current_sha
    upstream_commits[BASEJKA_REF] = BASEJKA_REF
    baseline_refs = {"eternaljk": UPSTREAM_REFS["eternaljk"],
                     "openjk": UPSTREAM_REFS["openjk"], "basejka": BASEJKA_REF}
    baseline_inventories = {
        kind: {name: set(group(extract_ref(upstream_commits[ref], kind, cache, False)))
               for name, ref in baseline_refs.items()}
        for kind in ("cvars", "commands")
    }
    docs = parse_japro_docs()
    jk2mv_docs = parse_jk2mv_docs()
    xdoc_cvars, xdoc_commands = parse_xdocs()

    cvar_groups = group(current_cvars)
    command_groups = group(current_commands)
    menu_entries = parse_menu_entries(set(cvar_groups) | set(command_groups))
    wanted: set[str] = set(cvar_groups) | set(command_groups)
    all_variables: set[str] = set()
    for records in cvar_groups.values():
        all_variables.update(
            record["variable"].casefold() for record in records if record.get("variable")
        )
    wanted |= all_variables
    wanted_handlers = {
        record["handler"].casefold()
        for records in command_groups.values() for record in records
        if record.get("handler") and re.fullmatch(r"[A-Za-z_]\w*", record["handler"])
    }
    wanted |= wanted_handlers
    occurrences = build_occurrence_index(files, wanted)
    menu_mirrors = menu_mirror_index(files)
    bit_options = bit_option_index(files)
    cvar_names = {key: records[0]["name"] for key, records in cvar_groups.items()}
    # One handler can carry several registered names: `plugin` and
    # `pluginDisable` are the same command, so a cvar names both.
    command_by_handler: dict[str, list[str]] = defaultdict(list)
    for records in command_groups.values():
        for record in records:
            if record.get("handler"):
                command_by_handler[record["handler"].casefold()].append(records[0]["name"])
    command_by_handler = {
        handler: sorted(unique(names)) for handler, names in command_by_handler.items()
    }
    for item in bit_options.values():
        handler = item["handler"]
        if handler and handler.casefold() not in command_by_handler:
            item["handler"] = calling_handler(files, handler) or handler
    file_map = dict(files)
    definitions = define_index(files)
    ranges, range_aliases = range_index(files, definitions)
    first_commit_dates = commit_dates(
        entry.get("first_commit")
        for kind in ("cvars", "commands")
        for entry in provenance[kind].values()
    )

    cvars: list[dict[str, Any]] = []
    for key, records in sorted(cvar_groups.items()):
        origin = provenance["cvars"].get(key, {
            "source": "unknown", "confidence": "low", "status": "needs-review",
            "notes": "Provenance resolver has not processed this identifier.", "modified_by": [],
        })
        name = records[0]["name"]
        modules = unique(record["module"] for record in records)
        renderers = sorted({record["renderer"] for record in records if record.get("renderer")})
        variables = unique(record["variable"] for record in records if record.get("variable"))
        raw_flags = {flag for record in records for flag in record.get("flags", [])}
        expanded_flags: set[str] = set()
        for flag in raw_flags:
            if flag.startswith("CVAR_"):
                expanded_flags.add(flag)
                continue
            definition = definitions.get(flag)
            resolved = re.findall(r"\bCVAR_[A-Z0-9_]+\b", definition[0]) if definition else []
            expanded_flags.update(resolved or [flag])
        flags = sorted(expanded_flags)
        explicit_defaults = [
            record["default"] for record in records
            if record.get("default") is not None and not record["kind"].startswith("implicit")
        ]
        defaults = Counter(explicit_defaults)
        default = defaults.most_common(1)[0][0] if defaults else next(
            (record["default"] for record in records if record.get("default") is not None), None
        )
        # Carry the macro the chosen default came from, so a page can show both
        # the resolved value and the identifier the source actually spells.
        default_macro, default_macro_kind = next(
            ((record.get("default_macro"), record.get("default_macro_kind"))
             for record in records
             if record.get("default") == default and record.get("default_macro")),
            (None, None),
        )
        behavior = useful_occurrences(name, variables, records, occurrences)
        descriptions = [clean_description(record.get("description")) for record in records]
        xdoc = xdoc_cvars.get(key, {})
        docs_item = docs.get(key, {})
        jk2mv_item = jk2mv_docs.get(key, {}) if origin.get("source") == "jk2mv" else {}
        documented = (
            next((value for value in descriptions if value), None)
            or xdoc.get("summary") or docs_item.get("summary") or jk2mv_item.get("summary")
        )
        override = overrides.get("cvars", {}).get(key, {})
        summary = override.get("summary") or documented
        derivation = "documented" if summary else "code-trace"
        if not summary:
            if behavior:
                summary = f"Controls `{variables[0] if variables else name}` in the {choose_module(name, modules)} module."
            else:
                summary = "Registered by the current source, but no user-facing behavior description has been verified."
        description = override.get("description") or jk2mv_item.get("summary") or summary
        if not override.get("description") and not documented:
            description += " Consult the cited behavior reads before relying on values not listed here."
        value_type = override.get("value_type") or infer_type(default, variables, behavior)
        range_lookup = {variable.casefold() for variable in variables} | range_aliases.get(key, set())
        cvar_ranges = unique(
            json.dumps(item, sort_keys=True) for variable in sorted(range_lookup) for item in ranges.get(variable, [])
        )
        cvar_ranges = [json.loads(item) for item in cvar_ranges]
        if value_type == "bool":
            numeric_bounds = [
                numeric_default(str(bound))
                for item in cvar_ranges for bound in (item.get("min"), item.get("max"))
            ]
            if any(bound is not None and bound not in {0.0, 1.0} for bound in numeric_bounds):
                value_type = "int"
        documentation_evidence = next((
            {"path": record["path"], "line": record["line"]}
            for record in records if clean_description(record.get("description")) == documented
        ), None) or xdoc.get("evidence") or docs_item.get("evidence") or jk2mv_item.get("evidence")
        values = override.get("values") or xdoc.get("values") or jk2mv_item.get("values") or infer_values(
            value_type, variables, behavior, definitions, documented, documentation_evidence,
        )
        if len(values) >= 2 and value_type in {"bool", "int"} and not override.get("value_type"):
            option_values = {str(item.get("value")) for item in values}
            if not option_values.issubset({"0", "1"}):
                value_type = "enum"
        evidence = [
            {
                "kind": "registration", "path": record["path"], "line": record["line"],
                "url": source_url(record["path"], record["line"], current_sha),
                "registration_kind": record["kind"], "condition": record.get("condition"),
            }
            for record in records
        ]
        behavior_evidence = [
            {"kind": "behavior", "path": item["path"], "line": item["line"],
             "url": source_url(item["path"], item["line"], current_sha)}
            for item in behavior
        ]
        if xdoc.get("evidence"):
            item = xdoc["evidence"]
            behavior_evidence.append({
                "kind": "documentation", "path": item["path"], "line": item["line"],
                "url": source_url(item["path"], item["line"], current_sha),
            })
        if docs_item.get("evidence"):
            item = docs_item["evidence"]
            behavior_evidence.append({
                "kind": "documentation", "path": item["path"], "line": item["line"],
                "url": source_url(item["path"], item["line"], current_sha),
            })
        if jk2mv_item.get("evidence"):
            item = jk2mv_item["evidence"]
            behavior_evidence.append({
                "kind": "upstream-documentation", "path": item["path"], "line": item["line"],
                "url": item["url"],
            })
        network = "client-only"
        if "CVAR_USERINFO" in flags:
            network = "needs-server-support"
        if {"CVAR_SERVERINFO", "CVAR_SYSTEMINFO"} & set(flags) or choose_module(name, modules) in {"game", "engine-server", "game-console"}:
            network = "server-authoritative"
        if any(re.search(r"\b(?:taystJKinfo|jcinfo\d*)\b", item["text"], re.I) for item in behavior):
            network = "feature-flagged"
        status = origin.get("status", "needs-review")
        if (not documented and not override.get("summary")) or value_type == "unknown":
            status = "needs-review"
        bits = bit_options.get(key)
        mirror = menu_mirrors.get(key)
        basis = engine_managed_basis(flags, records, mirror)
        # An override settles the cases the flags and registration shape get
        # wrong in either direction: a hand-written hack the code never flags,
        # or a menu setting that happens to carry CVAR_INTERNAL.
        if isinstance(override.get("engine_managed"), bool):
            basis = basis if override["engine_managed"] else []
            if override["engine_managed"] and not basis:
                basis = ["editorial"]
        primary = choose_module(name, modules)
        cvars.append({
            "name": name, "kind": "cvar", "module": primary,
            "modules": modules, "renderer": renderers, "default": default,
            "defaults": [
                {"value": record.get("default"), "module": record["module"],
                 "renderer": record.get("renderer"), "condition": record.get("condition"),
                 "macro": record.get("default_macro"), "macro_kind": record.get("default_macro_kind")}
                for record in records if record.get("default") is not None
            ],
            "default_macro": default_macro, "default_macro_kind": default_macro_kind,
            "flags": flags, "value_type": value_type, "range": cvar_ranges,
            "engine_managed": bool(basis), "engine_managed_basis": basis,
            "bits": {
                "commands": command_by_handler.get((bits["handler"] or "").casefold(), []),
                "options": bits["options"],
                "evidence": dict(
                    bits["evidence"],
                    url=source_url(bits["evidence"]["path"], bits["evidence"]["line"], current_sha),
                ),
            } if bits else None,
            "menu_mirror": {
                "target": mirror["target"],
                "apply": mirror["apply"] and dict(
                    mirror["apply"], url=source_url(mirror["apply"]["path"], mirror["apply"]["line"], current_sha)),
                "read": mirror["read"] and dict(
                    mirror["read"], url=source_url(mirror["read"]["path"], mirror["read"]["line"], current_sha)),
            } if mirror else None,
            "values": values, "summary": summary, "description": description,
            "derivation": override.get("derivation", derivation), "network": network,
            "requires_restart": "CVAR_LATCH" in flags, "cheat_protected": "CVAR_CHEAT" in flags,
            "origin": {key2: value for key2, value in origin.items() if key2 != "modified_by"},
            "baselines": registration_baselines(name, baseline_inventories["cvars"]),
            "added_on": added_on_for(origin, first_commit_dates),
            "modified_by": origin.get("modified_by", []), "evidence": evidence + behavior_evidence,
            "confidence": origin.get("confidence", "low"), "status": status,
            "category": category_for(name, "cvar", primary, summary),
            "feature": feature_for(name),
            "xdocs": xdoc.get("evidence"), "menu_entries": menu_entries.get(key, []),
            "variables": variables, "source_commit": current_sha,
        })

    commands: list[dict[str, Any]] = []
    for key, records in sorted(command_groups.items()):
        name = records[0]["name"]
        modules = unique(record["module"] for record in records)
        renderers = sorted({record["renderer"] for record in records if record.get("renderer")})
        gating = sorted({flag for record in records for flag in record.get("gating", [])})
        handlers = unique(
            record["handler"] for record in records
            if record.get("handler") and record["handler"] not in {"NULL", "server game module"}
        )
        bodies = [function_body(file_map, handler, occurrences.get(handler.casefold(), [])) for handler in handlers]
        bodies = [body for body in bodies if body]
        body = bodies[0][0] if bodies else None
        syntax, usage = command_syntax(name, body)
        descriptions = [clean_description(record.get("description")) for record in records]
        xdoc = xdoc_commands.get(key, {})
        docs_item = docs.get(key, {})
        documented = next((value for value in descriptions if value), None) or xdoc.get("summary") or docs_item.get("summary")
        override = overrides.get("commands", {}).get(key, {})
        summary = override.get("summary") or documented
        if not summary:
            if any(record["kind"] == "forwarded client command table" for record in records):
                summary = "Forwards this command to the connected game server."
            elif handlers:
                summary = f"Runs `{handlers[0]}` in the {choose_module(name, modules)} module."
            else:
                summary = "Registered by the current source, but no user-facing behavior description has been verified."
        origin = provenance["commands"].get(key, {
            "source": "unknown", "confidence": "low", "status": "needs-review",
            "notes": "Provenance resolver has not processed this identifier.", "modified_by": [],
        })
        evidence = [
            {"kind": "registration", "path": record["path"], "line": record["line"],
             "url": source_url(record["path"], record["line"], current_sha),
             "registration_kind": record["kind"], "condition": record.get("condition")}
            for record in records
        ]
        for _function, path, line in bodies[:3]:
            evidence.append({"kind": "handler", "path": path, "line": line,
                             "url": source_url(path, line, current_sha)})
        if xdoc.get("evidence"):
            item = xdoc["evidence"]
            evidence.append({"kind": "documentation", "path": item["path"], "line": item["line"],
                             "url": source_url(item["path"], item["line"], current_sha)})
        if docs_item.get("evidence"):
            item = docs_item["evidence"]
            evidence.append({"kind": "documentation", "path": item["path"], "line": item["line"],
                             "url": source_url(item["path"], item["line"], current_sha)})
        primary = choose_module(name, modules)
        network = "client-only"
        if any(record["kind"] == "forwarded client command table" for record in records) or "game" in modules:
            network = "needs-server-support"
        if primary in {"engine-server", "game-console"} and "cgame" not in modules:
            network = "server-authoritative"
        status = origin.get("status", "needs-review")
        if not documented and not override.get("summary"):
            status = "needs-review"
        commands.append({
            "name": name, "kind": "command", "module": primary, "modules": modules,
            "configures": sorted(
                cvar_names[target] for target, item in bit_options.items()
                if item["handler"] and item["handler"].casefold() in {
                    handler.casefold() for handler in handlers
                } and target in cvar_names
            ),
            "renderer": renderers, "syntax": override.get("syntax", syntax),
            "arguments": override.get("arguments", []), "summary": summary,
            "description": override.get("description", summary),
            "derivation": override.get("derivation", "documented" if documented or usage else "code-trace"),
            "network": network, "cheat_protected": "CMD_CHEAT" in gating,
            "gating": gating, "handlers": handlers,
            "origin": {key2: value for key2, value in origin.items() if key2 != "modified_by"},
            "baselines": registration_baselines(name, baseline_inventories["commands"]),
            "added_on": added_on_for(origin, first_commit_dates),
            "modified_by": origin.get("modified_by", []), "evidence": evidence,
            "confidence": origin.get("confidence", "low"), "status": status,
            "category": category_for(name, "command", primary, summary),
            "feature": feature_for(name),
            "xdocs": xdoc.get("evidence"), "menu_entries": menu_entries.get(key, []),
            "source_commit": current_sha,
        })

    output = Path(args.output_dir)
    write(output / "cvars.json", cvars)
    write(output / "commands.json", commands)
    write(output / "reference-meta.json", {
        "source_commit": current_sha,
        # Committer date of the snapshot, so a reader can tell how stale the
        # reference is without resolving the hash themselves.
        "source_commit_date": git("show", "-s", "--format=%cI", current_sha).strip(),
        "basejka_commit": BASEJKA_REF,
        "counts": {"cvars": len(cvars), "commands": len(commands)},
        "extractor_version": EXTRACTOR_VERSION,
        "upstream_commits": upstream_commits,
    })
    print(f"wrote {len(cvars)} cvars and {len(commands)} commands to {output}")


if __name__ == "__main__":
    main()
