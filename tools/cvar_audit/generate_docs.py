#!/usr/bin/env python3
"""Generate the GitHub Pages console reference from _data JSON files."""

from __future__ import annotations

import argparse
import hashlib
import html
import json
import re
import subprocess
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Iterable


ORIGIN_LABELS = {
    "taystjk": "TaystJK",
    "eternaljk": "EternalJK",
    "japro": "jaPRO",
    "jk2mv": "JK2MV",
    "newjk": "NewJK / NewMod",
    "rend2": "rend2",
    "vulkan": "Vulkan",
    "openjk": "OpenJK",
    "basejka": "Base Jedi Academy",
    "quake3": "Quake III lineage",
    "unknown": "Unknown",
}
ORIGIN_ORDER = tuple(ORIGIN_LABELS)
ORIGIN_REPOS = {
    "taystjk": "taysta/TaystJK",
    "eternaljk": "eternalcodes/EternalJK",
    "japro": "videoP/jaPRO",
    "jk2mv": "mvdevs/jk2mv",
    "newjk": "jkanewmod/NewJK",
    "rend2": "SomaZ/OpenJK",
    "vulkan": "JKSunny/EternalJK",
    "openjk": "JACoders/OpenJK",
    "basejka": "JACoders/OpenJK",
    "quake3": "id-Software/Quake-III-Arena",
}
FLAG_HELP = {
    "CVAR_ARCHIVE": "saved to the user configuration",
    "CVAR_ARCHIVE_ND": "saved to configuration without marking the cvar as user-created",
    "CVAR_LATCH": "latched until the relevant subsystem or map is restarted",
    "CVAR_CHEAT": "requires cheats",
    "CVAR_INIT": "initialization/command-line setting",
    "CVAR_ROM": "read-only after registration",
    "CVAR_USERINFO": "sent in the client's userinfo",
    "CVAR_SERVERINFO": "published in serverinfo",
    "CVAR_SYSTEMINFO": "replicated in systeminfo",
    "CVAR_NORESTART": "preserved across cvar restart",
    "CVAR_PROTECTED": "protected from unsafe remote changes",
    "CVAR_INTERNAL": "internal UI/engine state",
    "CVAR_TEMP": "temporary and not archived",
}
NETWORK_HELP = {
    "client-only": "Local to the client/UI/renderer.",
    "needs-server-support": "Sent to, or only useful with, a supporting game server.",
    "server-authoritative": "Owned or enforced by the server.",
    "feature-flagged": "Client behavior is negotiated through a server feature flag.",
}


def git(*args: str) -> str:
    result = subprocess.run(["git", *args], text=True, errors="replace", stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return result.stdout.strip() if result.returncode == 0 else ""


def introduction_date(item: dict[str, Any]) -> str:
    return datetime.fromtimestamp(int(item["timestamp"]), timezone.utc).date().isoformat()


def introduction_commit_link(item: dict[str, Any]) -> str:
    repo = ORIGIN_REPOS.get(item["source"])
    sha = item["sha"]
    if not repo:
        return code(sha[:12])
    return f"[`{sha[:12]}`](https://github.com/{repo}/commit/{sha})"


def change_commit_link(item: dict[str, Any]) -> str:
    sha = item.get("commit")
    if not sha:
        return "—"
    repo = ORIGIN_REPOS.get(item.get("repository", "taystjk"), ORIGIN_REPOS["taystjk"])
    return f"[`{sha[:12]}`](https://github.com/{repo}/commit/{sha})"


def load(path: Path) -> Any:
    return json.loads(path.read_text())


def write(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text.rstrip() + "\n")


def frontmatter(
    title: str,
    nav_order: int | None = None,
    parent: str | None = None,
    nav_exclude: bool = False,
    *,
    wide: bool = False,
    reference_app: bool = False,
    description: str | None = None,
) -> str:
    lines = ["---", f"title: {json.dumps(title)}", "layout: reference"]
    if nav_order is not None:
        lines.append(f"nav_order: {nav_order}")
    if parent:
        lines.append(f"parent: {json.dumps(parent)}")
    if nav_exclude:
        lines.extend(["nav_exclude: true", "search_exclude: false"])
    if wide:
        lines.append("wide: true")
    if reference_app:
        lines.append("reference_app: true")
    if description:
        lines.append(f"description: {json.dumps(description)}")
    lines.extend(["---", ""])
    return "\n".join(lines)


def code(value: Any) -> str:
    return f"`{str(value).replace('`', '&#96;')}`"


def esc(value: Any) -> str:
    return html.escape(str(value), quote=True)


def slug(name: str) -> str:
    value = name.casefold().replace("+", "plus-").replace("-", "minus-")
    value = re.sub(r"[^a-z0-9_]+", "-", value).strip("-") or "entry"
    # Jekyll does not publish pages whose filename begins with an underscore.
    if value.startswith("_"):
        value = f"entry-{value}"
    return f"{value}-{hashlib.sha1(name.casefold().encode()).hexdigest()[:7]}"


def detail_url(entry: dict[str, Any]) -> str:
    return f"/TaystJK/reference/{entry['kind']}s/{slug(entry['name'])}/"


def badge(origin: str) -> str:
    return f'<span class="label ref-origin ref-origin-{esc(origin)}">{esc(ORIGIN_LABELS.get(origin, origin))}</span>'


def catalog_app(
    mode: str = "all",
    *,
    preset_key: str | None = None,
    preset_value: str | None = None,
    multi_select: bool = False,
) -> str:
    """Return the progressively enhanced catalog shell.

    The browser receives a compact search index rather than thousands of table
    rows. Detail pages remain static and crawlable.
    """
    catalog_title = {
        "cvar": "Find a cvar",
        "command": "Find a command",
    }.get(mode, "Find a cvar or command")
    attrs = [
        'class="reference-catalog"',
        'id="catalog"',
        'data-reference-app',
        f'data-mode="{esc(mode)}"',
        'data-catalog-url="{{ \'/assets/data/catalog.json\' | relative_url }}"',
    ]
    if preset_key and preset_value:
        attrs.append(f'data-preset-{esc(preset_key)}="{esc(preset_value)}"')
    if multi_select:
        filters = """    <div class="catalog-filters">
      <div class="filter-dropdown" data-filter-dropdown="origin">
        <button class="filter-toggle" type="button" data-filter-toggle="origin" aria-expanded="false"><span>Origin</span><strong data-filter-summary="origin">Any origin</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="origin" hidden>
          <div class="filter-options" data-filter-options="origin"></div>
          <button class="filter-clear" type="button" data-clear-filter="origin">Clear origin</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="module">
        <button class="filter-toggle" type="button" data-filter-toggle="module" aria-expanded="false"><span>Module</span><strong data-filter-summary="module">Any module</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="module" hidden>
          <div class="filter-options" data-filter-options="module"></div>
          <button class="filter-clear" type="button" data-clear-filter="module">Clear module</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="renderer">
        <button class="filter-toggle" type="button" data-filter-toggle="renderer" aria-expanded="false"><span>Renderer</span><strong data-filter-summary="renderer">Any renderer</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="renderer" hidden>
          <div class="filter-options" data-filter-options="renderer">
            <label class="filter-checkbox"><input type="checkbox" name="renderer" value="renderer-specific" data-filter="renderer"><span>Renderer-specific only</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="renderer" value="none" data-filter="renderer"><span>Not renderer-specific</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="renderer">Clear renderer</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="status">
        <button class="filter-toggle" type="button" data-filter-toggle="status" aria-expanded="false"><span>Documentation</span><strong data-filter-summary="status">Any status</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="status" hidden>
          <div class="filter-options">
            <label class="filter-checkbox"><input type="checkbox" name="status" value="documented" data-filter="status"><span>Documented</span></label>
            <label class="filter-checkbox"><input type="checkbox" name="status" value="needs-review" data-filter="status"><span>Needs review</span></label>
          </div>
          <button class="filter-clear" type="button" data-clear-filter="status">Clear documentation</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="network">
        <button class="filter-toggle" type="button" data-filter-toggle="network" aria-expanded="false"><span>Network scope</span><strong data-filter-summary="network">Any scope</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="network" hidden>
          <div class="filter-options" data-filter-options="network"></div>
          <button class="filter-clear" type="button" data-clear-filter="network">Clear network scope</button>
        </div>
      </div>
      <div class="filter-dropdown" data-filter-dropdown="flag" data-cvar-filter>
        <button class="filter-toggle" type="button" data-filter-toggle="flag" aria-expanded="false"><span>Cvar flag</span><strong data-filter-summary="flag">Any flag</strong><span class="filter-chevron" aria-hidden="true"></span></button>
        <div class="filter-popover" data-filter-popover="flag" hidden>
          <div class="filter-options" data-filter-options="flag"></div>
          <button class="filter-clear" type="button" data-clear-filter="flag">Clear cvar flags</button>
        </div>
      </div>
    </div>"""
    else:
        filters = """    <div class="catalog-filters">
      <label><span>Origin</span><select name="origin" data-filter="origin"><option value="">Any origin</option></select></label>
      <label><span>Module</span><select name="module" data-filter="module"><option value="">Any module</option></select></label>
      <label><span>Renderer</span><select name="renderer" data-filter="renderer"><option value="">Any renderer</option><option value="renderer-specific">Renderer-specific only</option><option value="none">Not renderer-specific</option></select></label>
      <label><span>Documentation</span><select name="status" data-filter="status"><option value="">Any status</option><option value="documented">Documented</option><option value="needs-review">Needs review</option></select></label>
      <label><span>Network scope</span><select name="network" data-filter="network"><option value="">Any scope</option></select></label>
      <label data-cvar-filter><span>Cvar flag</span><select name="flag" data-filter="flag"><option value="">Any flag</option></select></label>
    </div>"""
    return f"""
<section {' '.join(attrs)} aria-labelledby="catalog-title">
  <div class="catalog-heading">
    <div>
      <p class="section-kicker">Console index</p>
      <h2 id="catalog-title">{catalog_title}</h2>
    </div>
    <p class="catalog-shortcut"><kbd>/</kbd> to search</p>
  </div>

  <form class="catalog-controls" data-catalog-form role="search">
    <label class="catalog-search">
      <span>Search the reference</span>
      <span class="search-field">
        <svg aria-hidden="true" viewBox="0 0 24 24"><path d="m21 21-4.35-4.35m2.35-5.65a8 8 0 1 1-16 0 8 8 0 0 1 16 0Z"/></svg>
        <input type="search" name="q" data-search autocomplete="off" spellcheck="false" placeholder="Try cg_fov, download, bloom…">
      </span>
    </label>

    <div class="catalog-kind" data-kind-tabs aria-label="Entry type">
      <button type="button" data-kind="all">All</button>
      <button type="button" data-kind="cvar">Cvars</button>
      <button type="button" data-kind="command">Commands</button>
    </div>

{filters}

    <div class="catalog-actions">
      <button type="reset" class="button button-quiet" data-reset>Clear filters</button>
      <label class="catalog-sort"><span>Sort</span><select name="sort" data-sort><option value="relevance">Relevance</option><option value="name">Name</option><option value="origin">Origin</option><option value="module">Module</option></select></label>
    </div>
  </form>

  <div class="catalog-status" aria-live="polite">
    <p data-result-count>Loading the reference…</p>
    <p class="active-filters" data-active-filters></p>
  </div>
  <div class="catalog-results" data-results aria-busy="true"></div>
  <div class="catalog-empty" data-empty hidden>
    <h3>No matching entries</h3>
    <p>Try a shorter search or clear one of the filters.</p>
  </div>
  <div class="catalog-more"><button type="button" class="button button-secondary" data-load-more hidden>Show more</button></div>
  <noscript><p class="catalog-noscript">JavaScript is required for the interactive index. You can still browse the <a href="{{{{ '/reference/all/' | relative_url }}}}">static A–Z index</a> or use the generated JSON files.</p></noscript>
</section>
""".strip()


def evidence_link(item: dict[str, Any], label: str | None = None) -> str:
    text = label or f"{item.get('path')}:{item.get('line')}"
    url = item.get("url")
    return f"[{text}]({url})" if url else code(text)


def upstream_evidence_link(origin: dict[str, Any], refs: dict[str, str]) -> str | None:
    item = origin.get("origin_evidence")
    source = origin.get("source")
    repo = ORIGIN_REPOS.get(source)
    if not item or not repo:
        return None
    ref = item.get("ref") or "master"
    sha = refs.get(ref, ref)
    url = f"https://github.com/{repo}/blob/{sha}/{item['path']}#L{item['line']}"
    return f"[{item['path']}:{item['line']}]({url})"


def value_table(entry: dict[str, Any]) -> str:
    values = entry.get("values", [])
    if not values:
        return "No discrete value list is enforced or documented in the inspected source."
    lines = ["| Value | Meaning | Evidence |", "|:--|:--|:--|"]
    for item in values:
        evidence = item.get("evidence")
        if evidence and not evidence.get("url") and evidence.get("path"):
            sha = entry["source_commit"]
            evidence = dict(evidence, url=source_url(evidence["path"], evidence["line"], sha))
        lines.append(f"| {code(item['value'])} | {item['meaning']} | {evidence_link(evidence) if evidence else '—'} |")
    return "\n".join(lines)


def source_url(path: str, line: int, sha: str) -> str:
    return f"https://github.com/taysta/TaystJK/blob/{sha}/{path}#L{line}"


def detail_page(entry: dict[str, Any], refs: dict[str, str]) -> str:
    origin = entry["origin"]
    lines = [frontmatter(entry["name"], nav_exclude=True), f"# {code(entry['name'])}", "", badge(origin["source"]), ""]
    if entry["status"] != "documented":
        lines.extend([
            '<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>', "",
        ])
    lines.extend([entry["description"], "", "## At a glance", "", "| Field | Value |", "|:--|:--|"])
    lines.extend([
        f"| Module | {code(entry['module'])} |",
        f"| Also registered in | {', '.join(code(value) for value in entry.get('modules', []))} |",
        f"| Renderer | {', '.join(code(value) for value in entry.get('renderer', [])) or 'All / not renderer-specific'} |",
        f"| Network scope | {code(entry['network'])} — {NETWORK_HELP.get(entry['network'], '')} |",
        f"| Derivation | {code(entry['derivation'])} |",
        f"| Confidence | {code(entry['confidence'])} |",
    ])
    if entry["kind"] == "cvar":
        lines.extend([
            f"| Default | {code(entry['default'] if entry['default'] is not None else 'dynamic')} |",
            f"| Value type | {code(entry['value_type'])} |",
            f"| Restart | {'Yes; the value is latched.' if entry['requires_restart'] else 'No latch flag is registered.'} |",
            f"| Cheat protected | {'Yes' if entry['cheat_protected'] else 'No'} |",
            "", "## Values", "", value_table(entry), "",
        ])
        if entry.get("range"):
            lines.extend(["## Enforced ranges", ""])
            for item in entry["range"]:
                lines.append(
                    f"- {code(item['min'])} through {code(item['max'])}"
                    f" ({'integer' if item.get('integral') else 'numeric'}; {item.get('kind', 'range check')}) — "
                    f"{evidence_link(dict(item['evidence'], url=source_url(item['evidence']['path'], item['evidence']['line'], entry['source_commit'])))}"
                )
            lines.append("")
        lines.extend(["## Flags", ""])
        if entry.get("flags"):
            lines.extend(f"- {code(flag)} — {FLAG_HELP.get(flag, 'fork/source-defined flag; see registration evidence')}" for flag in entry["flags"])
        else:
            lines.append("No cvar flags are registered at the cited site.")
        defaults = {(item.get("value"), item.get("module"), item.get("renderer"), item.get("condition")) for item in entry.get("defaults", [])}
        if len(defaults) > 1:
            lines.extend(["", "## Registration-specific defaults", "", "| Default | Module | Renderer | Compile condition |", "|:--|:--|:--|:--|"])
            for value, module, renderer, condition in sorted(defaults, key=lambda item: tuple(str(x) for x in item)):
                lines.append(f"| {code(value)} | {code(module)} | {code(renderer or '—')} | {code(condition or 'always')} |")
    else:
        lines.extend([
            f"| Syntax | {code(entry['syntax'])} |",
            f"| Cheat protected | {'Yes' if entry['cheat_protected'] else 'No'} |",
            "", "## Arguments and gating", "",
        ])
        if entry.get("arguments"):
            lines.append("Arguments: " + ", ".join(code(value) for value in entry["arguments"]) + ".")
        else:
            lines.append("No verified argument schema is available beyond the syntax shown above.")
        if entry.get("gating"):
            lines.append("Gating: " + ", ".join(code(value) for value in entry["gating"]) + ".")
    lines.extend(["", "## Provenance", "", f"Origin: {badge(origin['source'])}", ""])
    origin_introduction = origin.get("origin_introduction")
    if origin_introduction:
        lines.append(
            f"- Ultimate-origin introduction: {introduction_commit_link(origin_introduction)} "
            f"on {code(introduction_date(origin_introduction))} in {badge(origin_introduction['source'])}"
        )
    if origin.get("first_commit"):
        # Except for the Raven baseline (and optional deep-pickaxe mode), the
        # first-addition SHA is from TaystJK's own registration-file history.
        # The separately linked origin_evidence points into the upstream repo.
        repo = "JACoders/OpenJK" if origin["first_commit"] == "14cea1563762076974bee277afadbd5bf234c494" else "taysta/TaystJK"
        if not origin_introduction or origin["first_commit"] != origin_introduction.get("sha"):
            label = "Baseline evidence" if origin["first_commit"] == "14cea1563762076974bee277afadbd5bf234c494" else "TaystJK integration evidence"
            lines.append(f"- {label}: [`{origin['first_commit'][:12]}`](https://github.com/{repo}/commit/{origin['first_commit']})")
    if origin.get("pr_url"):
        lines.append(f"- Pull request: [#{origin['pr']}]({origin['pr_url']})")
    if origin.get("squash_bullet"):
        lines.append(f"- Matching squash bullet: {code(origin['squash_bullet'])}")
    upstream = upstream_evidence_link(origin, refs)
    if upstream:
        lines.append(f"- Upstream registration evidence: {upstream}")
    lines.extend([
        f"- Attribution method: {code(origin.get('method', 'unknown'))}",
        f"- Attribution confidence: {code(origin.get('confidence', 'low'))}",
    ])
    if origin.get("notes"):
        lines.append(f"- Notes: {origin['notes']}")
    introductions = origin.get("introduction_evidence", [])
    if introductions:
        lines.extend([
            "", "### Dated project introductions", "",
            "These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.", "",
            "| Project | Date | Commit | Relationship |", "|:--|:--|:--|:--|",
        ])
        origin_timestamp = origin_introduction.get("timestamp") if origin_introduction else None
        for item in introductions:
            if origin_introduction and item["source"] == origin_introduction["source"] and item["sha"] == origin_introduction["sha"]:
                relationship = "Ultimate origin"
            elif origin_timestamp is not None and item["timestamp"] == origin_timestamp:
                relationship = "Shared earliest lineage"
            elif origin_timestamp is not None and item["timestamp"] > origin_timestamp:
                relationship = "Later project appearance"
            else:
                relationship = "Additional dated evidence"
            lines.append(
                f"| {badge(item['source'])} | {code(introduction_date(item))} | "
                f"{introduction_commit_link(item)} | {relationship} |"
            )
    if origin.get("ported_via"):
        lines.extend([
            "", "Immediate port-source credit: "
            + ", ".join(badge(source) for source in origin["ported_via"])
            + ". The earlier dated project remains the ultimate origin.",
        ])
    if entry.get("modified_by"):
        lines.extend([
            "", "### Later changes", "",
            "These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.", "",
            "| Date | Change source | Commit / subject | Evidence | Confidence |", "|:--|:--|:--|:--|:--|",
        ])
        for change in entry["modified_by"]:
            date = code(introduction_date(change)) if change.get("timestamp") else "—"
            subject = str(change.get("subject") or "unresolved").replace("|", "\\|")
            commit = change_commit_link(change)
            if change.get("pr_url"):
                commit += f" · [PR #{change['pr']}]({change['pr_url']})"
            paths = change.get("paths", [])
            path_note = ", ".join(code(path) for path in paths[:3])
            if len(paths) > 3:
                path_note += f" and {len(paths) - 3} more"
            evidence = change["change"] + (f" {path_note}" if path_note else "")
            lines.append(
                f"| {date} | {badge(change['source'])} | {commit}<br>{subject} | "
                f"{evidence} | {code(change.get('confidence', 'unknown'))} |"
            )
    lines.extend(["", "## Evidence", ""])
    for item in entry["evidence"]:
        extra = f" ({item.get('registration_kind')})" if item.get("registration_kind") else ""
        condition = f"; condition {code(item['condition'])}" if item.get("condition") else ""
        lines.append(f"- {item['kind']}: {evidence_link(item)}{extra}{condition}")
    return "\n".join(lines)


def count_table(entries: list[dict[str, Any]], key) -> str:
    counts = Counter(key(entry) for entry in entries)
    return "\n".join(["| Group | Count |", "|:--|--:|"] + [f"| {label} | {count} |" for label, count in sorted(counts.items())])


def compact_table(entries: list[dict[str, Any]]) -> str:
    if not entries:
        return "None."
    lines = ["| Name | Kind | Module | Summary |", "|:--|:--|:--|:--|"]
    for entry in entries:
        lines.append(f"| [{code(entry['name'])}]({detail_url(entry)}) | {entry['kind']} | {entry['module']} | {entry['summary']} |")
    return "\n".join(lines)


def collection_page(
    title: str,
    intro: str,
    entries: list[dict[str, Any]],
    nav_order: int,
    parent: str,
    *,
    preset_key: str,
    preset_value: str,
    mode: str = "all",
) -> str:
    cvar_count = sum(entry["kind"] == "cvar" for entry in entries)
    command_count = sum(entry["kind"] == "command" for entry in entries)
    breakdown = []
    if cvar_count:
        breakdown.append(f"{cvar_count:,} cvars")
    if command_count:
        breakdown.append(f"{command_count:,} commands")
    lines = [
        frontmatter(
            title,
            nav_order,
            parent,
            wide=True,
            reference_app=True,
            description=f"Browse {', '.join(breakdown)} in the TaystJK console reference.",
        ),
        '<div class="page-heading" markdown="1">',
        '<p class="eyebrow">Filtered collection</p>',
        f"<h1>{esc(title)}</h1>",
        f'<p class="page-lede">{intro} This collection contains {", ".join(breakdown)}.</p>',
        "</div>",
        "",
        catalog_app(mode, preset_key=preset_key, preset_value=preset_value),
        "",
    ]
    return "\n".join(lines)


def compact_catalog_entry(entry: dict[str, Any]) -> dict[str, Any]:
    """Build the public search record without shipping source-evidence payloads."""
    item: dict[str, Any] = {
        "kind": entry["kind"],
        "name": entry["name"],
        "url": detail_url(entry),
        "module": entry["module"],
        "modules": entry.get("modules", [entry["module"]]),
        "renderer": entry.get("renderer", []),
        "summary": entry["summary"],
        "description": entry["description"],
        "network": entry["network"],
        "status": entry["status"],
        "confidence": entry["confidence"],
        "derivation": entry["derivation"],
        "cheat_protected": entry["cheat_protected"],
        "origin": entry["origin"]["source"],
        "origin_confidence": entry["origin"]["confidence"],
    }
    if entry["kind"] == "cvar":
        item.update({
            "default": entry.get("default"),
            "flags": entry.get("flags", []),
            "value_type": entry.get("value_type"),
            "requires_restart": entry.get("requires_restart", False),
            "values": [
                {"value": option["value"], "meaning": option["meaning"]}
                for option in entry.get("values", [])
            ],
        })
    else:
        item.update({
            "syntax": entry.get("syntax"),
            "arguments": entry.get("arguments", []),
            "gating": entry.get("gating", []),
        })
    return item


def static_index_page(cvars: list[dict[str, Any]], commands: list[dict[str, Any]]) -> str:
    lines = [
        frontmatter(
            "Static A–Z index",
            wide=True,
            description="A no-JavaScript index of every TaystJK cvar and console command.",
        ),
        '<div class="page-heading" markdown="1">',
        '<p class="eyebrow">No-JavaScript directory</p>',
        '<h1>Static A–Z index</h1>',
        '<p class="page-lede">Every detail page in the generated reference, listed alphabetically.</p>',
        '</div>',
    ]
    for title, selected in (("Cvars", cvars), ("Commands", commands)):
        lines.extend(["", f"## {title}", '<div class="static-index-list">'])
        for entry in selected:
            lines.append(f'<a href="{detail_url(entry)}"><code>{esc(entry["name"])}</code></a>')
        lines.append("</div>")
    return "\n".join(lines)


def home_page(cvars: list[dict[str, Any]], commands: list[dict[str, Any]]) -> str:
    total = len(cvars) + len(commands)
    origins = {entry["origin"]["source"] for entry in cvars + commands}
    return frontmatter(
        "TaystJK console reference",
        1,
        wide=True,
        description="Search every TaystJK cvar and console command, including options, renderer scope, and upstream provenance.",
    ) + f"""
<section class="hero">
  <div class="hero-copy">
    <p class="eyebrow">TaystJK technical reference</p>
    <h1>Every console control.<br><span>Traced to its source.</span></h1>
    <p class="hero-lede">Search every cvar and command in TaystJK, see the accepted values, and tell Base JKA, OpenJK, EternalJK, jaPRO, rend2, Vulkan, and other upstream work apart.</p>
    <div class="hero-actions">
      <a class="button button-primary" href="{{{{ '/reference/' | relative_url }}}}">Explore {total:,} entries</a>
      <a class="button button-secondary" href="{{{{ '/reference/sources/' | relative_url }}}}">How attribution works</a>
    </div>
  </div>
  <div class="hero-terminal" aria-label="Example console lookup">
    <div class="terminal-bar"><span></span><span></span><span></span><b>console reference</b></div>
    <div class="terminal-body">
      <a class="terminal-entry" href="{{{{ '/reference/cvars/r_dynamicglowbloom-d4ab76d/' | relative_url }}}}">
        <p><span class="terminal-prompt">›</span> <strong>r_dynamicGlowBloom</strong></p>
        <p class="terminal-muted">Dynamic-glow bloom strength · default <code>0.0</code></p>
        <p><span class="mini-origin ref-origin-rend2">rend2</span> <span class="terminal-scope">rd-rend2</span></p>
      </a>
      <hr>
      <a class="terminal-entry" href="{{{{ '/reference/cvars/cg_camerafps-62ac0e1/' | relative_url }}}}">
        <p><span class="terminal-prompt">›</span> <strong>cg_cameraFPS</strong></p>
        <p class="terminal-muted">Frame-independent third-person camera damping</p>
        <p><span class="mini-origin ref-origin-jk2mv">JK2MV</span> <code>&lt;15</code> legacy · <code>≥15</code> adjusted</p>
      </a>
    </div>
  </div>
</section>

<section class="reference-stats" aria-label="Reference coverage">
  <div><strong>{len(cvars):,}</strong><span>cvars</span></div>
  <div><strong>{len(commands):,}</strong><span>commands</span></div>
  <div><strong>{len(origins)}</strong><span>source lineages</span></div>
  <div><strong>4</strong><span>renderer targets</span></div>
</section>

<section class="method-banner">
  <div><p class="section-kicker">Evidence, not guesswork</p><h2>Source registrations, history, PRs, and upstream trees.</h2></div>
  <p>The inventory combines static extraction with a runtime reconciliation. Squashed pull requests are traced through their retained commit bullets and PR descriptions; uncertain semantics stay visibly marked for review.</p>
  <a class="text-link" href="{{{{ '/reference/sources/' | relative_url }}}}">Read the methodology →</a>
</section>
"""


def audit_page(entries: list[dict[str, Any]], runtime: dict[str, Any] | None) -> str:
    review = [entry for entry in entries if entry["status"] != "documented"]
    ambiguous = [entry for entry in entries if entry["origin"]["confidence"] != "high"]
    modified = [entry for entry in entries if entry.get("modified_by")]
    modification_count = sum(len(entry.get("modified_by", [])) for entry in entries)
    lines = [frontmatter("Audit report", 7, "Console reference"), "# Audit report", "",
             "This is the deliberately untidy review queue behind the published reference. `unknown` and `needs-review` are used instead of guesses.", "",
             "## Totals by origin", "", count_table(entries, lambda entry: ORIGIN_LABELS.get(entry["origin"]["source"], entry["origin"]["source"])), "",
             "## Runtime reconciliation", ""]
    if runtime:
        lines.extend([
            f"Runtime target: {code(runtime['target'])}; build: {code(runtime['build'])}.", "",
            runtime["notes"], "",
            "| Registry | Runtime | Static union | Runtime-only | Expected static-only |", "|:--|--:|--:|--:|--:|",
            f"| Cvars | {runtime['cvars']['runtime_count']} | {runtime['cvars']['static_union_count']} | {len(runtime['cvars']['runtime_only'])} | {len(runtime['cvars']['static_not_in_runtime_target'])} |",
            f"| Commands | {runtime['commands']['runtime_count']} | {runtime['commands']['static_union_count']} | {len(runtime['commands']['runtime_only'])} | {len(runtime['commands']['static_not_in_runtime_target'])} |", "",
            "Runtime-only cvars: " + (", ".join(code(value) for value in runtime["cvars"]["runtime_only"]) or "none") + ".", "",
            "Runtime-only commands: " + (", ".join(code(value) for value in runtime["commands"]["runtime_only"]) or "none") + ".", "",
            "The dump was captured from stdout after loading `mp/ffa3`; stdout does not use the client console scrollback buffer. Cvars and commands were dumped in separate launches so neither list could displace the other.", "",
        ])
    else:
        lines.extend(["No runtime report was supplied to the generator.", ""])
    lines.extend([
        f"## Provenance needing review ({len(ambiguous)})", "", compact_table(ambiguous), "",
        f"## Semantics or options needing review ({len(review)})", "", compact_table(review), "",
        f"## Post-origin change history ({len(modified)} entries; {modification_count} events)", "",
        "These entries have dated post-origin registration or behavior evidence on TaystJK's inherited first-parent history. Each detail page links the exact commit and records whether attribution comes from explicit credit, a unique project mainline, shared lineage, or an unresolved registration difference.", "",
        compact_table(modified), "",
    ])
    return "\n".join(lines)


def sources_page(refs: dict[str, str]) -> str:
    rows = ["| Origin | Repository / snapshot | Role |", "|:--|:--|:--|"]
    details = {
        "basejka": "Raven/id JA source present in OpenJK's initial import",
        "openjk": "post-import OpenJK additions",
        "eternaljk": "EternalJK additions",
        "japro": "jaPRO gameplay, HUD, movement, and admin work",
        "jk2mv": "selected JK2MV ports",
        "newjk": "NewJK and explicitly credited NewMod ports",
        "rend2": "SomaZ rend2-unified renderer lineage",
        "vulkan": "JKSunny Vulkan renderer lineage",
        "taystjk": "entries first evidenced in TaystJK after upstream checks",
    }
    ref_for = {
        "basejka": "14cea1563762076974bee277afadbd5bf234c494",
        "openjk": "openjk/master", "eternaljk": "eternaljk/master", "japro": "japro/main",
        "jk2mv": "jk2mv/master", "newjk": "newjk/master", "rend2": "somaz/rend2-unified-wip",
        "vulkan": "Sunny/master", "taystjk": "origin/master",
    }
    for source in details:
        repo = ORIGIN_REPOS[source]
        ref = ref_for[source]
        sha = refs.get(ref, ref)
        rows.append(f"| {badge(source)} | [`{repo}@{sha[:12]}`](https://github.com/{repo}/tree/{sha}) | {details[source]} |")
    return frontmatter("Sources and methodology", 6, "Console reference") + """
# Sources and methodology

The reference separates origin from current availability. An entry inherited from Raven remains **Base Jedi Academy** even though OpenJK and every fork ship it. A cvar registered only by `rd-vulkan` is not automatically Vulkan-originated: the resolver checks rend2 and other upstream snapshots first.

""" + "\n".join(rows) + """

## Evidence process

1. The extractor masks comments, follows preprocessor conditions, and recognizes XCVAR macros, legacy VM tables, direct and syscall `Cvar_Get`/`Cvar_Register` calls, dynamic format expansions, command tables, input tables, renderer tables, and server-forwarded command names.
2. The Raven baseline is OpenJK commit `14cea1563762076974bee277afadbd5bf234c494`, the initial JA source dump.
3. For every non-base name, the resolver dates its first registration on the current first-parent line of TaystJK, OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2, and Vulkan. The earliest dated project is the ultimate origin; later appearances are recorded as downstream ports rather than treated as proof of origin. Current-head presence is only a fallback when file history cannot be followed.
4. Equal-date appearances are resolved only after chronology, using a shared commit as fork-lineage evidence. Squash bullets, commit bodies, and PR descriptions can identify an immediate port source, but a later intermediate source cannot displace an earlier dated origin.
5. After origin is established, a separate TaystJK first-parent patch scan records exact registration changes, changed bound cvar-variable references, and edits within registered command-handler hunks. Each change is dated and attributed from explicit commit/PR credit or project-mainline membership; shared change commits remain medium-confidence.
6. Semantics come from source descriptions, `ui_xdocs.h`, jaPRO's checked-in documentation, handler/read sites, masks, comparisons, and range checks. Unproven fields stay in the review queue.
7. The dedicated runtime registry is reconciled separately. One runtime cannot contain client, UI, every platform, and all renderers, so the published inventory is the static union.

NewMod is closed source. Its [published feature documentation](https://jkanewmod.github.io/documentation.html) is useful semantic context, but the resolver attributes NewMod/NewJK only where a commit, PR, or nearby source comment explicitly says so, or where the open NewJK tree supplies direct evidence. A feature-page resemblance alone is not treated as origin proof.

## Confidence

- **High:** initial-import match, a unique earliest dated project introduction, or explicit identifier/feature-group credit consistent with chronology.
- **Medium:** shared-commit lineage (a Git object has no repository-of-origin field), tied earliest dates, or exact upstream-head presence when registration-file history cannot be followed.
- **Low:** no reliable attribution; these remain `unknown`.

The [audit report](/TaystJK/reference/audit/) lists every medium/low attribution, incomplete semantic entry, and ambiguous registration-signature change.
"""


def removed_page(items: list[dict[str, Any]], source_sha: str) -> str:
    lines = [frontmatter("Removed and inactive", 6, "Console reference"), "# Removed and inactive names", "",
             "These identifiers are not part of the active static inventory, but remain useful search targets. `inactive` means the apparent registration is commented/disabled in the current tree; `renamed` identifies a verified replacement.", "",
             "| Name | Kind | Status | Replacement | Reason | Evidence |", "|:--|:--|:--|:--|:--|:--|"]
    for item in items:
        evidence = item["evidence"]
        evidence["url"] = source_url(evidence["path"], evidence["line"], source_sha)
        replacement = code(item["replacement"]) if item.get("replacement") else "—"
        lines.append(f"| {code(item['name'])} | {item['kind']} | {item['status']} | {replacement} | {item['summary']} | {evidence_link(evidence)} |")
    lines.extend(["", "This list covers inactive registration candidates found by the current-tree audit plus verified renames. Fully deleted historical names require an additional all-revision extraction and remain a future audit item."])
    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cvars", default="_data/cvars.json", type=Path)
    parser.add_argument("--commands", default="_data/commands.json", type=Path)
    parser.add_argument("--runtime", default=".cvar-audit/runtime-report.json", type=Path)
    args = parser.parse_args()
    cvars = load(args.cvars)
    commands = load(args.commands)
    entries = cvars + commands
    refs = {ref: git("rev-parse", ref) for ref in ["origin/master", *[
        "openjk/master", "eternaljk/master", "japro/main", "jk2mv/master", "newjk/master",
        "somaz/rend2-unified-wip", "Sunny/master",
    ]]}
    refs["14cea1563762076974bee277afadbd5bf234c494"] = "14cea1563762076974bee277afadbd5bf234c494"

    write(Path("index.md"), home_page(cvars, commands))
    write(Path("reference.md"), frontmatter(
        "Console reference",
        3,
        wide=True,
        reference_app=True,
        description="Search and filter every cvar and console command available in TaystJK.",
    ) + f"""
<div class="page-heading" markdown="1">
<p class="eyebrow">Complete source-derived inventory</p>

<h1>Console reference</h1>

<p class="page-lede">Search {len(cvars) + len(commands):,} cvars and commands across the client, dedicated server, game, cgame, UI, platform code, and every renderer backend.</p>
</div>

{catalog_app("all", multi_select=True)}

## How to read an entry

The **origin** badge identifies where an entry first appeared, not merely every fork that ships it. Later changes to defaults or flags are listed separately. **Renderer scope** says which current backend registers a cvar, while **network scope** distinguishes local controls from server-owned or negotiated behavior.

An entry marked **needs review** is real and has registration evidence, but one or more behavior, option, or attribution fields could not be proven precisely enough to present as settled fact.

### More ways to browse

- [Browse by origin](/TaystJK/reference/origins/)
- [Browse by module](/TaystJK/reference/modules/)
- [Read the sources and methodology](/TaystJK/reference/sources/)
- [See removed and inactive names](/TaystJK/reference/removed/)
- [Open the audit and review queue](/TaystJK/reference/audit/)
- [Use the static A–Z index](/TaystJK/reference/all/) without JavaScript
- Download the machine-readable [catalog JSON](/TaystJK/assets/data/catalog.json), [full cvars JSON](/TaystJK/assets/data/cvars.json), [full commands JSON](/TaystJK/assets/data/commands.json), [metadata](/TaystJK/assets/data/reference-meta.json), or [JSON Schema](/TaystJK/assets/data/schema.json)
""")
    for entry in entries:
        write(Path("reference") / f"{entry['kind']}s" / f"{slug(entry['name'])}.md", detail_page(entry, refs))
    write(Path("reference/all.md"), static_index_page(cvars, commands))

    origin_cards = []
    for source in ORIGIN_ORDER:
        count = sum(entry["origin"]["source"] == source for entry in entries)
        if count:
            origin_cards.append(
                f'<a class="directory-card" href="/TaystJK/reference/origins/{source}/">'
                f'{badge(source)}<strong>{ORIGIN_LABELS[source]}</strong><span>{count:,} entries</span></a>'
            )
    write(Path("reference/origins.md"), frontmatter("By origin", 3, "Console reference", wide=True) + """
<div class="page-heading" markdown="1">
<p class="eyebrow">Provenance</p>

<h1>Browse by origin</h1>

<p class="page-lede">Origin means the earliest source supported by the inspected code, Git history, pull requests, and upstream snapshots—not simply every project that now contains the name.</p>
</div>

<div class="directory-grid">
""" + "\n".join(origin_cards) + "\n</div>")
    for order, source in enumerate(ORIGIN_ORDER, 1):
        selected = [entry for entry in entries if entry["origin"]["source"] == source]
        if selected:
            intro = "Entries whose evidence identifies this project as the original source. Later consumers do not change the origin badge."
            if source == "taystjk":
                intro = "Entries first found in TaystJK after all configured upstream snapshots and explicit port credits were checked. Medium-confidence entries remain in the audit queue."
            write(Path("reference/origins") / f"{source}.md", collection_page(
                ORIGIN_LABELS[source], intro, selected, order, "By origin",
                preset_key="origin", preset_value=source,
            ))

    modules = sorted({entry["module"] for entry in entries})
    module_cards = []
    for module in modules:
        count = sum(entry["module"] == module for entry in entries)
        module_cards.append(
            f'<a class="directory-card" href="/TaystJK/reference/modules/{module}/">'
            f'<span class="directory-code">{esc(module)}</span><strong>{count:,}</strong><span>entries</span></a>'
        )
    write(Path("reference/modules.md"), frontmatter("By module", 4, "Console reference", wide=True) + """
<div class="page-heading" markdown="1">
<p class="eyebrow">Registration context</p>

<h1>Browse by module</h1>

<p class="page-lede">Find controls registered by the engine, game, cgame, UI, or renderer portions of the current TaystJK tree.</p>
</div>

<div class="directory-grid">
""" + "\n".join(module_cards) + "\n</div>")
    for order, module in enumerate(modules, 1):
        selected = [entry for entry in entries if entry["module"] == module]
        write(Path("reference/modules") / f"{module}.md", collection_page(
            module, "Entries whose primary registration or dispatch context is this module.", selected, order, "By module",
            preset_key="module", preset_value=module,
        ))

    runtime = load(args.runtime) if args.runtime.exists() else None
    write(Path("reference/audit.md"), audit_page(entries, runtime))
    write(Path("reference/sources.md"), sources_page(refs))
    removed_path = Path("tools/cvar_audit/removed.json")
    write(Path("reference/removed.md"), removed_page(load(removed_path), cvars[0]["source_commit"]))
    Path("assets/data").mkdir(parents=True, exist_ok=True)
    write(Path("assets/data/cvars.json"), json.dumps(cvars, separators=(",", ":")))
    write(Path("assets/data/commands.json"), json.dumps(commands, separators=(",", ":")))
    write(Path("assets/data/reference-meta.json"), json.dumps(load(Path("_data/reference-meta.json")), separators=(",", ":")))
    write(Path("assets/data/schema.json"), json.dumps(load(Path("tools/cvar_audit/schema.json")), separators=(",", ":")))
    write(Path("assets/data/catalog.json"), json.dumps([compact_catalog_entry(entry) for entry in entries], separators=(",", ":")))
    print(f"generated {len(entries)} detail entries and collection pages")


if __name__ == "__main__":
    main()
