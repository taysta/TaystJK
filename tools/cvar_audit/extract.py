#!/usr/bin/env python3
"""Extract TaystJK CVAR and console-command registrations from a Git ref.

The parser is intentionally dependency-free.  It understands the registration
patterns used by OpenJK and its descendants, preserves source line numbers, and
keeps conditional registrations as separate evidence records.  It is tolerant
of C/C++ that is not valid in isolation (X-macros are common in this tree).
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Iterable, Iterator


SOURCE_SUFFIXES = (".c", ".cc", ".cpp", ".cxx", ".h", ".hpp")


@dataclass(frozen=True)
class Registration:
    name: str
    kind: str
    path: str
    line: int
    module: str
    renderer: str | None = None
    default: str | None = None
    flags: tuple[str, ...] = ()
    description: str | None = None
    handler: str | None = None
    variable: str | None = None
    condition: str | None = None
    gating: tuple[str, ...] = ()


def run_git(*args: str, cwd: str | None = None) -> str:
    proc = subprocess.run(
        ["git", *args], cwd=cwd, check=False, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, errors="replace",
    )
    if proc.returncode:
        raise RuntimeError(f"git {' '.join(args)} failed: {proc.stderr.strip()}")
    return proc.stdout


def iter_git_sources(ref: str, repo: str = ".") -> Iterator[tuple[str, str]]:
    names = run_git("ls-tree", "-r", "--name-only", ref, cwd=repo).splitlines()
    paths = [path for path in names if path.endswith(SOURCE_SUFFIXES)]
    # One `git show` process per source file made a cold provenance run take
    # many minutes. `cat-file --batch` returns the exact same blob contents
    # while keeping a single Git process alive for the whole snapshot.
    process = subprocess.Popen(
        ["git", "cat-file", "--batch"], cwd=repo,
        stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    assert process.stdin is not None and process.stdout is not None
    try:
        for path in paths:
            process.stdin.write(f"{ref}:{path}\n".encode())
            process.stdin.flush()
            header = process.stdout.readline().decode(errors="replace").rstrip("\n")
            fields = header.rsplit(" ", 2)
            if len(fields) != 3 or fields[1] != "blob":
                raise RuntimeError(f"git cat-file failed for {ref}:{path}: {header}")
            size = int(fields[2])
            data = process.stdout.read(size)
            process.stdout.read(1)  # record-terminating newline
            yield path, data.decode(errors="replace")
    finally:
        process.stdin.close()
        return_code = process.wait()
        if return_code:
            stderr = process.stderr.read().decode(errors="replace") if process.stderr else ""
            raise RuntimeError(f"git cat-file --batch failed: {stderr.strip()}")


def iter_fs_sources(root: str) -> Iterator[tuple[str, str]]:
    base = Path(root)
    for path in sorted(base.rglob("*")):
        if path.is_file() and path.suffix in SOURCE_SUFFIXES and ".git" not in path.parts:
            yield str(path.relative_to(base)), path.read_text(errors="replace")


def source_files(ref: str | None, repo: str, root: str | None) -> Iterator[tuple[str, str]]:
    if root:
        yield from iter_fs_sources(root)
    elif ref:
        yield from iter_git_sources(ref, repo)
    else:
        raise ValueError("a Git ref or --root is required")


def mask_comments(text: str) -> str:
    """Replace comments with spaces, preserving newlines and byte positions."""
    out = list(text)
    i = 0
    in_string = False
    in_char = False
    escaped = False
    while i < len(out):
        ch = out[i]
        nxt = out[i + 1] if i + 1 < len(out) else ""
        if in_string or in_char:
            if escaped:
                escaped = False
            elif ch == "\\":
                escaped = True
            elif in_string and ch == '"':
                in_string = False
            elif in_char and ch == "'":
                in_char = False
            i += 1
            continue
        if ch == '"':
            in_string = True
            i += 1
            continue
        if ch == "'":
            in_char = True
            i += 1
            continue
        if ch == "/" and nxt == "/":
            j = i
            while j < len(out) and out[j] != "\n":
                out[j] = " "
                j += 1
            i = j
            continue
        if ch == "/" and nxt == "*":
            out[i] = out[i + 1] = " "
            i += 2
            while i < len(out):
                if i + 1 < len(out) and out[i] == "*" and out[i + 1] == "/":
                    out[i] = out[i + 1] = " "
                    i += 2
                    break
                if out[i] != "\n":
                    out[i] = " "
                i += 1
            continue
        i += 1
    return "".join(out)


def preprocessor_conditions(text: str) -> list[str | None]:
    """Return the active preprocessor expression for each 1-based source line."""
    conditions: list[str | None] = [None]
    stack: list[str] = []
    for line in mask_comments(text).splitlines():
        directive = re.match(r"\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b\s*(.*)", line)
        if directive:
            op, expr = directive.groups()
            expr = expr.strip()
            if op == "if":
                stack.append(expr)
            elif op == "ifdef":
                stack.append(f"defined({expr})")
            elif op == "ifndef":
                stack.append(f"!defined({expr})")
            elif op == "elif" and stack:
                stack[-1] = expr
            elif op == "else" and stack:
                stack[-1] = f"else({stack[-1]})"
            elif op == "endif" and stack:
                stack.pop()
        conditions.append(" && ".join(stack) or None)
    return conditions


def disabled(condition: str | None) -> bool:
    if not condition:
        return False
    terms = {term.strip(" ()") for term in condition.split("&&")}
    return "0" in terms or "false" in {term.lower() for term in terms}


def line_number(text: str, offset: int) -> int:
    return text.count("\n", 0, offset) + 1


def compact(value: str | None) -> str | None:
    if value is None:
        return None
    return re.sub(r"\s+", " ", value.strip())


def split_fields(value: str) -> list[str]:
    """Split a C initializer/call argument list at top-level commas."""
    fields: list[str] = []
    start = 0
    parens = brackets = braces = 0
    in_string = in_char = escaped = False
    for pos, ch in enumerate(value):
        if in_string or in_char:
            if escaped:
                escaped = False
            elif ch == "\\":
                escaped = True
            elif in_string and ch == '"':
                in_string = False
            elif in_char and ch == "'":
                in_char = False
            continue
        if ch == '"':
            in_string = True
        elif ch == "'":
            in_char = True
        elif ch == "(":
            parens += 1
        elif ch == ")":
            parens -= 1
        elif ch == "[":
            brackets += 1
        elif ch == "]":
            brackets -= 1
        elif ch == "{":
            braces += 1
        elif ch == "}":
            braces -= 1
        elif ch == "," and parens == brackets == braces == 0:
            fields.append(compact(value[start:pos]) or "")
            start = pos + 1
    fields.append(compact(value[start:]) or "")
    return fields


def string_literal(value: str) -> str | None:
    match = re.fullmatch(r'\s*"((?:\\.|[^"\\])*)"\s*', value, re.S)
    return match.group(1) if match else None


def literal_or_expression(value: str) -> str:
    literal = string_literal(value)
    return literal if literal is not None else (compact(value) or "")


def assignment_variable(text: str, offset: int) -> str | None:
    line_start = text.rfind("\n", 0, offset) + 1
    prefix = text[line_start:offset]
    match = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\s*=\s*$", prefix)
    return match.group(1) if match else None


def concatenated_string_literals(value: str) -> str | None:
    parts = re.findall(r'"((?:\\.|[^"\\])*)"', value, re.S)
    rendered = "".join(parts).strip()
    return rendered or None


def iter_calls(text: str, function_pattern: str) -> Iterator[tuple[int, int, list[str]]]:
    """Yield balanced call arguments for a function-name regex."""
    pattern = re.compile(rf"{function_pattern}\s*\(")
    for match in pattern.finditer(text):
        opening = text.find("(", match.start(), match.end())
        depth = 1
        in_string = in_char = escaped = False
        pos = opening + 1
        while pos < len(text) and depth:
            ch = text[pos]
            if in_string or in_char:
                if escaped:
                    escaped = False
                elif ch == "\\":
                    escaped = True
                elif in_string and ch == '"':
                    in_string = False
                elif in_char and ch == "'":
                    in_char = False
            elif ch == '"':
                in_string = True
            elif ch == "'":
                in_char = True
            elif ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            pos += 1
        if depth == 0:
            yield match.start(), line_number(text, match.start()), split_fields(text[opening + 1:pos - 1])


def split_flags(expr: str | None) -> tuple[str, ...]:
    if not expr:
        return ()
    names = re.findall(r"\bCVAR_[A-Z0-9_]+\b", expr)
    if names:
        return tuple(dict.fromkeys(names))
    clean = compact(expr)
    return (clean,) if clean and clean not in {"0", "CVAR_NONE"} else ()


def source_comment(original_lines: list[str], line: int) -> str | None:
    if not 0 < line <= len(original_lines):
        return None
    current = original_lines[line - 1]
    if "//" in current:
        comment = current.split("//", 1)[1].strip()
        if comment:
            return comment
    return None


def classify_path(path: str) -> tuple[str, str | None]:
    norm = "/" + path.replace("\\", "/")
    renderer_match = re.search(r"/(rd-(?:vanilla|rend2|vulkan|dedicated))(/|$)", norm)
    if renderer_match:
        renderer = renderer_match.group(1)
        return "renderer", renderer
    if "/rd-common/" in norm:
        return "renderer", None
    for segment, module in (
        ("/cgame/", "cgame"), ("/game/", "game"), ("/ui/", "ui"),
        ("/client/", "engine-client"), ("/server/", "engine-server"),
        ("/botlib/", "botlib"), ("/qcommon/", "engine-shared"),
        ("/shared/", "engine-shared"),
    ):
        if segment in norm:
            return module, None
    return "other", None


def extract_cvars(files: Iterable[tuple[str, str]], include_implicit: bool = True) -> list[Registration]:
    registrations: list[Registration] = []
    explicit_names: set[str] = set()

    xcvar = re.compile(
        r"^\s*XCVAR_DEF\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*"
        r"(?:\"((?:\\.|[^\"\\])*)\"|([^,]+))\s*,\s*([^,]+)\s*,\s*([^\)]+)\)",
        re.M,
    )
    implicit = re.compile(
        r"(?:\btrap_|\b|\.|->)Cvar_(Set|SetValue)\s*\(\s*\"([^\"]+)\"\s*,\s*"
        r"(?:\"((?:\\.|[^\"\\])*)\"|([^,\)]+))\s*\)",
        re.S,
    )

    materialized = list(files)
    numeric_defines: dict[str, int] = {}
    for _path, source in materialized:
        for define in re.finditer(r"^\s*#\s*define\s+([A-Za-z_]\w*)\s+(-?\d+)\b", mask_comments(source), re.M):
            numeric_defines[define.group(1)] = int(define.group(2))
    for path, original in materialized:
        masked = mask_comments(original)
        conditions = preprocessor_conditions(original)
        lines = original.splitlines()
        module, renderer = classify_path(path)

        for match in xcvar.finditer(masked):
            # ``^\s*`` intentionally permits indentation, but ``\s`` also
            # spans blank/comment-only lines. Anchor evidence and inline
            # descriptions to the identifier itself, not the match prefix.
            line = line_number(masked, match.start(1))
            condition = conditions[line] if line < len(conditions) else None
            if disabled(condition):
                continue
            name = match.group(1)
            explicit_names.add(name.casefold())
            registrations.append(Registration(
                name=name, kind="XCVAR_DEF", path=path, line=line,
                module=module, renderer=renderer,
                default=match.group(2) if match.group(2) is not None else compact(match.group(3)),
                flags=split_flags(match.group(5)), description=source_comment(lines, line),
                variable=name, condition=condition,
            ))

        # Raven's initial source dump predates the XCVAR headers and stores VM
        # registrations directly in cvarTable_t initializer arrays.
        table_pattern = r"(?:static\s+)?(?:const\s+)?cvarTable_t\s+[A-Za-z0-9_]+\[\]\s*="
        for entry, line in iter_initializer_entries(masked, table_pattern):
            fields = split_fields(entry)
            if len(fields) < 4:
                continue
            name = string_literal(fields[1])
            if not name:
                continue
            condition = conditions[line] if line < len(conditions) else None
            if disabled(condition):
                continue
            default = literal_or_expression(fields[2])
            flag_expr = next((field for field in fields[3:] if "CVAR_" in field), None)
            if flag_expr is None and len(fields) == 4:
                flag_expr = fields[3]
            variable = re.sub(r"^\s*&\s*", "", fields[0]).strip()
            explicit_names.add(name.casefold())
            registrations.append(Registration(
                name=name, kind="cvar table", path=path, line=line,
                module=module, renderer=renderer, default=default,
                flags=split_flags(flag_expr), description=source_comment(lines, line),
                variable=variable if re.fullmatch(r"[A-Za-z_]\w*", variable) else None,
                condition=condition,
            ))

        for offset, line, args in iter_calls(masked, r"\b(?:trap_)?Cvar_Get"):
            if len(args) < 3:
                continue
            name = string_literal(args[0])
            expanded_names: list[str] = []
            if name:
                expanded_names = [name]
            else:
                dynamic = re.fullmatch(
                    r'va\s*\(\s*"([^"]*%d[^"]*)"\s*,\s*([A-Za-z_]\w*)\s*\+\s*(\d+)\s*\)',
                    args[0], re.S,
                )
                before = masked[max(0, offset - 600):offset]
                loop = re.search(
                    r"for\s*\(\s*([A-Za-z_]\w*)\s*=\s*(-?\d+)\s*;\s*\1\s*<\s*([A-Za-z_]\w*|-?\d+)",
                    before,
                )
                if dynamic and loop and dynamic.group(2) == loop.group(1):
                    upper = numeric_defines.get(loop.group(3), None)
                    if upper is None and re.fullmatch(r"-?\d+", loop.group(3)):
                        upper = int(loop.group(3))
                    if upper is not None:
                        start = int(loop.group(2))
                        addend = int(dynamic.group(3))
                        expanded_names = [dynamic.group(1) % (value + addend) for value in range(start, upper)]
            if not expanded_names:
                continue
            condition = conditions[line] if line < len(conditions) else None
            if disabled(condition):
                continue
            for expanded_name in expanded_names:
                explicit_names.add(expanded_name.casefold())
                registrations.append(Registration(
                    name=expanded_name,
                    kind="Cvar_Get" if name else "dynamic Cvar_Get expansion",
                    path=path, line=line, module=module, renderer=renderer,
                    default=literal_or_expression(args[1]),
                    flags=split_flags(args[2]),
                    description=concatenated_string_literals(args[3]) if len(args) > 3 else source_comment(lines, line),
                    variable=assignment_variable(masked, offset), condition=condition,
                ))

        for offset, line, args in iter_calls(masked, r"\b(?:trap_)?Cvar_Register"):
            if len(args) < 4:
                continue
            name = string_literal(args[1])
            if not name:
                continue
            condition = conditions[line] if line < len(conditions) else None
            if disabled(condition):
                continue
            variable = re.sub(r"^\s*&\s*", "", args[0]).strip()
            explicit_names.add(name.casefold())
            registrations.append(Registration(
                name=name, kind="Cvar_Register", path=path, line=line,
                module=module, renderer=renderer,
                default=literal_or_expression(args[2]), flags=split_flags(args[3]),
                description=source_comment(lines, line),
                variable=variable if re.fullmatch(r"[A-Za-z_]\w*", variable) and variable != "NULL" else None,
                condition=condition,
            ))

    if include_implicit:
        for path, original in materialized:
            masked = mask_comments(original)
            conditions = preprocessor_conditions(original)
            lines = original.splitlines()
            module, renderer = classify_path(path)
            for match in implicit.finditer(masked):
                name = match.group(2)
                if name.casefold() in explicit_names:
                    continue
                line = line_number(masked, match.start())
                condition = conditions[line] if line < len(conditions) else None
                if disabled(condition):
                    continue
                registrations.append(Registration(
                    name=name, kind=f"implicit Cvar_{match.group(1)}", path=path, line=line,
                    module=module, renderer=renderer,
                    default=match.group(3) if match.group(3) is not None else compact(match.group(4)),
                    description=source_comment(lines, line), condition=condition,
                ))
            existing_sites = {(record.path, record.line, record.kind) for record in registrations}
            for operation in ("Set", "SetValue"):
                for _offset, line, args in iter_calls(masked, rf"\b(?:trap_)?Cvar_{operation}"):
                    kind = f"implicit Cvar_{operation}"
                    if len(args) < 2 or (path, line, kind) in existing_sites:
                        continue
                    name = string_literal(args[0])
                    if not name or name.casefold() in explicit_names:
                        continue
                    condition = conditions[line] if line < len(conditions) else None
                    if disabled(condition):
                        continue
                    registrations.append(Registration(
                        name=name, kind=kind, path=path, line=line,
                        module=module, renderer=renderer,
                        default=literal_or_expression(args[1]),
                        description=source_comment(lines, line), condition=condition,
                    ))
    return sorted(set(registrations), key=lambda r: (r.name.casefold(), r.path, r.line, r.kind))


def table_body(text: str, start: int) -> tuple[int, int] | None:
    brace = text.find("{", start)
    if brace < 0:
        return None
    depth = 0
    in_string = False
    escaped = False
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
                return brace + 1, pos
    return None


def iter_initializer_entries(text: str, start_pattern: str) -> Iterator[tuple[str, int]]:
    """Yield top-level braced entries from matching initializer arrays."""
    for start in re.finditer(start_pattern, text, re.M):
        bounds = table_body(text, start.end())
        if not bounds:
            continue
        body_start, body_end = bounds
        depth = 0
        entry_start: int | None = None
        in_string = in_char = escaped = False
        for pos in range(body_start, body_end):
            ch = text[pos]
            if in_string or in_char:
                if escaped:
                    escaped = False
                elif ch == "\\":
                    escaped = True
                elif in_string and ch == '"':
                    in_string = False
                elif in_char and ch == "'":
                    in_char = False
                continue
            if ch == '"':
                in_string = True
            elif ch == "'":
                in_char = True
            elif ch == "{":
                if depth == 0:
                    entry_start = pos + 1
                depth += 1
            elif ch == "}" and depth:
                depth -= 1
                if depth == 0 and entry_start is not None:
                    yield text[entry_start:pos], line_number(text, entry_start - 1)
                    entry_start = None


def iter_table_entries(text: str, start_pattern: str) -> Iterator[tuple[str, int, list[str], str]]:
    for start in re.finditer(start_pattern, text, re.M):
        bounds = table_body(text, start.end())
        if not bounds:
            continue
        body_start, body_end = bounds
        body = text[body_start:body_end]
        entry_re = re.compile(r"\{\s*\"((?:\\.|[^\"\\])+)\"\s*,\s*([^}\n]+)\}")
        for match in entry_re.finditer(body):
            fields = split_fields(match.group(2))
            line = line_number(text, body_start + match.start())
            yield match.group(1), line, fields, match.group(0)


def command_tables_for(path: str) -> list[tuple[str, str]]:
    norm = "/" + path.replace("\\", "/")
    if re.search(r"/cgame/cg_consolecmds\.(?:c|cpp)$", norm):
        return [(r"static\s+consoleCommand_t\s+commands\[\]\s*=", "cgame")]
    if re.search(r"/game/g_cmds\.(?:c|cpp)$", norm):
        return [(r"command_t\s+commands\[\]\s*=", "game")]
    if re.search(r"/game/g_svcmds\.(?:c|cpp)$", norm):
        return [(r"svcmd_t\s+svcmds\[\]\s*=", "game-console")]
    if re.search(r"/ui/ui_atoms\.(?:c|cpp)$", norm):
        return [(r"static\s+consoleCommand_t\s+commands\[\]\s*=", "ui")]
    if re.search(r"/rd-(?:vanilla|rend2|vulkan)/tr_init\.cpp$", norm):
        return [(r"static\s+consoleCommand_t\s+commands\[\]\s*=", "renderer")]
    return []


def extract_commands(files: Iterable[tuple[str, str]]) -> list[Registration]:
    registrations: list[Registration] = []
    add = re.compile(
        r"\bCmd_AddCommand\s*\(\s*\"([^\"]+)\"\s*,\s*([^,\)]+)"
        r"(?:\s*,\s*\"((?:\\.|[^\"\\])*)\")?\s*\)", re.S,
    )
    trap_add = re.compile(
        r"(?:\btrap_AddCommand|\btrap->AddCommand)\s*\(\s*\"([^\"]+)\"\s*\)", re.S,
    )
    cmdlist = re.compile(r"(?:static\s+)?(?:const\s+)?cmdList_t\s+[A-Za-z0-9_]+\[\]\s*=", re.M)

    for path, original in files:
        masked = mask_comments(original)
        conditions = preprocessor_conditions(original)
        lines = original.splitlines()
        module, renderer = classify_path(path)

        for match in add.finditer(masked):
            line = line_number(masked, match.start())
            condition = conditions[line] if line < len(conditions) else None
            if disabled(condition):
                continue
            registrations.append(Registration(
                name=match.group(1), kind="Cmd_AddCommand", path=path, line=line,
                module=module, renderer=renderer, handler=compact(match.group(2)),
                description=(match.group(3) or source_comment(lines, line) or None),
                condition=condition,
            ))

        existing_add_sites = {(record.path, record.line) for record in registrations if record.kind == "Cmd_AddCommand"}
        for _offset, line, args in iter_calls(masked, r"\bCmd_AddCommand"):
            if len(args) < 2 or (path, line) in existing_add_sites:
                continue
            name = string_literal(args[0])
            if not name:
                continue
            condition = conditions[line] if line < len(conditions) else None
            if disabled(condition):
                continue
            registrations.append(Registration(
                name=name, kind="Cmd_AddCommand", path=path, line=line,
                module=module, renderer=renderer, handler=compact(args[1]),
                description=(concatenated_string_literals(args[2]) if len(args) > 2 else source_comment(lines, line)),
                condition=condition,
            ))

        for match in trap_add.finditer(masked):
            line = line_number(masked, match.start())
            condition = conditions[line] if line < len(conditions) else None
            if disabled(condition):
                continue
            registrations.append(Registration(
                name=match.group(1), kind="trap AddCommand", path=path, line=line,
                module=module, renderer=renderer, description=source_comment(lines, line),
                condition=condition,
            ))

        for pattern, context in command_tables_for(path):
            for name, line, fields, _entry in iter_table_entries(masked, pattern):
                condition = conditions[line] if line < len(conditions) else None
                if disabled(condition):
                    continue
                handler = fields[0] if fields else None
                gating = tuple(re.findall(r"\b(?:CMD|CVAR)_[A-Z0-9_]+\b", " ".join(fields[1:])))
                registrations.append(Registration(
                    name=name, kind=f"{context} command table", path=path, line=line,
                    module=module, renderer=renderer, handler=handler,
                    description=source_comment(lines, line), condition=condition, gating=gating,
                ))

        for table in cmdlist.finditer(masked):
            pattern = re.escape(table.group(0))
            for name, line, fields, entry in iter_table_entries(masked, pattern):
                condition = conditions[line] if line < len(conditions) else None
                if disabled(condition):
                    continue
                strings = re.findall(r'\"((?:\\.|[^\"\\])*)\"', entry)
                description = strings[1] if len(strings) > 1 else source_comment(lines, line)
                registrations.append(Registration(
                    name=name, kind="input command table", path=path, line=line,
                    module=module, renderer=renderer,
                    handler=fields[1] if len(fields) > 1 else None,
                    description=description or None, condition=condition,
                ))

        if re.search(r"/cgame/cg_consolecmds\.(?:c|cpp)$", "/" + path.replace("\\", "/")):
            string_table = r"static\s+const\s+char\s*\*\s*gcmds\[\]\s*="
            for start in re.finditer(string_table, masked, re.M):
                bounds = table_body(masked, start.end())
                if not bounds:
                    continue
                body_start, body_end = bounds
                for item in re.finditer(r'"((?:\\.|[^"\\])+)"', masked[body_start:body_end]):
                    line = line_number(masked, body_start + item.start())
                    condition = conditions[line] if line < len(conditions) else None
                    if disabled(condition):
                        continue
                    registrations.append(Registration(
                        name=item.group(1), kind="forwarded client command table", path=path, line=line,
                        module="cgame", handler="server game module",
                        description=source_comment(lines, line), condition=condition,
                        gating=("sent-to-server",),
                    ))
    return sorted(set(registrations), key=lambda r: (r.name.casefold(), r.path, r.line, r.kind))


def write_json(records: list[Registration], destination: str | None) -> None:
    data = [asdict(record) for record in records]
    rendered = json.dumps(data, indent=2, sort_keys=True) + "\n"
    if destination:
        Path(destination).parent.mkdir(parents=True, exist_ok=True)
        Path(destination).write_text(rendered)
    else:
        sys.stdout.write(rendered)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("kind", choices=("cvars", "commands"))
    parser.add_argument("--ref", default="origin/master")
    parser.add_argument("--repo", default=".")
    parser.add_argument("--root", help="read a checked-out tree instead of a Git ref")
    parser.add_argument("--output")
    parser.add_argument("--no-implicit", action="store_true",
                        help="exclude literal Cvar_Set sites lacking an explicit registration")
    parser.add_argument("--summary", action="store_true")
    args = parser.parse_args()

    files = list(source_files(args.ref, args.repo, args.root))
    records = (extract_cvars(files, include_implicit=not args.no_implicit)
               if args.kind == "cvars" else extract_commands(files))
    if args.summary:
        names = {record.name.casefold() for record in records}
        print(f"{len(records)} evidence records; {len(names)} unique {args.kind}")
    else:
        write_json(records, args.output)


if __name__ == "__main__":
    main()
