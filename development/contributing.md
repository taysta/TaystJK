---
title: "Contributing"
layout: reference
parent: "Development"
description: "How changes reach TaystJK: which branch to target, what CI builds, how to test a fix without compiling it yourself, and what a new cvar owes the documentation."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Developer documentation</p>

# Contributing

<p class="page-lede">What to do with a change once you have it, and what a reviewer will expect. If you have a problem rather than a change, start with where to report instead.</p>
</div>

Before anything else, check the problem belongs here at all. A great deal of what looks
like client behaviour is the server's game module, and reports sent to the wrong project sit
unanswered — see [where to report](/TaystJK/where-to-report/).

## Branches

Pull requests target `master` or `beta`
([`build.yml`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/workflows/build.yml#L13)).
Use `master` unless you have been asked otherwise.

Every pull request is reviewed by the maintainers team, which owns every path in the
repository
([`CODEOWNERS`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/CODEOWNERS)).

## What CI does with your PR

Opening a pull request builds the client for every supported platform and architecture:
Windows x86 and x86-64, Linux x86 and x86-64, macOS Intel and Apple Silicon, and a macOS
universal binary. Both Debug and Release are compiled as a check; only Release is packaged.

Changes touching only Markdown, `.gitignore` or `docs/` skip the build entirely
([`build.yml`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/workflows/build.yml#L7)),
so a docs-only PR showing no build is behaving correctly.

## Testing a fix without building it

You do not need a compiler to confirm a fix works. Every pull request's build produces
downloadable artifacts, one per platform, named like:

```text
TaystJK-windows-x86_64-Release-Portable
TaystJK-linux-x86_64-Release-Portable
TaystJK-macos-arm64-Release-Portable
```

Open the pull request, go to its **Checks** tab, choose the build for your platform, and
download the artifact from the run's Artifacts section. Unzip it somewhere separate from
your normal install — these are portable builds, so they keep their settings beside the
executable and will not disturb anything, as described in
[builds and versioning](/TaystJK/features/builds-and-versioning/).

This is the fastest way to answer "does this actually fix it for you", and reporters are
often asked for exactly that.

If you would rather build it yourself, see [compiling](/TaystJK/development/compiling/).

## Checklist before opening the pull request

Paste this into the pull request description and strike out what does not apply. Most of it
is one line of work; the point is that none of it gets remembered later.

```markdown
- [ ] CHANGELOG.md updated, with the right marker
- [ ] Classified: new feature / bug fix / improvement to something existing
- [ ] New cvars and commands have a description in their registration
- [ ] New cvars and commands have an xdocs entry
- [ ] Menu entry added, if it is user-facing
- [ ] Behaviour with no cvar attached is documented on the wiki
- [ ] Feature flag added, if the server has to agree for it to work
- [ ] Platform differences noted, if it is not built everywhere
```

### CHANGELOG.md

Add a line under `# Features` → `## Tayst's Fork`. Every other section is inherited OpenJK
text describing single-player as well as multiplayer, so leave those alone.

The marker is how the change gets classified, and there are three:

| Marker | Means |
|:--|:--|
| `[+]` | New — a feature that did not exist |
| `[\*]` | Modified — an improvement or a fix to something that did |
| `[-]` | Removed |

Bug fixes take `[\*]`, alongside improvements; the fork's changelog does not separate them.
Name the cvar or command in the line, in backticks, because that is how coverage is measured
— `changelog_coverage.py` matches entry names as whole words against this file.

### xdocs

xdocs are the in-client help: they are what `/help <name>` shows a player who never opens a
browser. They live in
[`ui_xdocs.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h)
and are plain macro calls:

```c
XDOCS_CVAR_DEF("cg_zoomFov", "The field of view when using +zoom", "")

XDOCS_CVAR_DEF("cg_alwaysShowAbsorb", "Show absorb when it's in use",
    SETTING("0", "Absorb shows only when used against another power (Base behavior)") NL
    SETTING("1", "Absorb shows always when in use")
)
```

Use `XDOCS_CMD_DEF` for a command, and the `BITFLAG` and `KEYVALUE` variants for cvars
shaped that way — they print a header explaining how to combine or format values, which is
exactly what a reader cannot guess.

Only 117 of 1,441 cvars have an entry today, so this is a backlog rather than a rule that
has always been kept. New ones should have one.

### Menu entries

229 cvars are reachable from the in-game menus, defined under
`assets/japro/ui/jamp/`. If your cvar is something a player would plausibly want to change
without the console, add it there too. If it is a developer or diagnostic setting, do not.

### Registration descriptions

The [console reference](/TaystJK/reference/) is generated by reading registrations straight
out of the source, so a new cvar appears there on its own. What it cannot invent is what the
cvar means — the description string in the registration is what the reference shows, and a
missing one produces a placeholder that reads like documentation while saying nothing.

Say explicitly if the cvar is a bitmask or takes structured values. Those are the entries
readers most often cannot guess, and the reference cannot work it out from a number.

### Behaviour with no cvar attached

A feature with no setting — a new key binding rule, a file format the client now reads, a
change in how something is drawn — has nothing for the reference to hang itself on. It needs
a page on this site instead, or a section on an existing one. The
[Features](/TaystJK/features/) pages are all of this shape.

### Behaviour the server has to agree with

Client features that depend on the server agreeing are gated on which mod the server runs.
If you are adding one, read
[feature flags](/TaystJK/development/feature-flags/) first, so other game modules have a way
to opt in rather than being locked out by name.

### Anything not built everywhere

If the feature is compiled in conditionally — a platform, an architecture, a renderer
backend — say so, and add a row to
[platform support](/TaystJK/features/platform-support/). A feature that is absent rather
than disabled looks like a bug to the person missing it, and no cvar will explain it.
