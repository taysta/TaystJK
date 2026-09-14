---
title: "In-game documentation (xdocs)"
layout: reference
parent: "Development"
nav_order: 6
description: "How a cvar or command documents itself inside the client, what the macros do, and how that relates to the description in its registration."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Developer documentation</p>

# In-game documentation

<p class="page-lede">Typing a cvar's name in the console prints what it does. That text is xdocs, and it is written separately from the cvar's registration.</p>
</div>

## Two places a description can come from

When the console prints a cvar, the engine asks the UI module for a description first, and
falls back to the string in the cvar's own registration
([`Cvar_DescriptionString`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L182)):

1. **xdocs**, compiled into the UI module from
   [`ui_xdocs.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h) — richer, and able to enumerate values
2. **The registration string**, the last argument to `Cvar_Get` — one line, no structure
3. Nothing, if neither exists

So xdocs do not replace a good registration description; they are the longer form shown to
somebody who is already in the console trying to work the cvar out. Write both.

**Because xdocs live in the UI module, they travel with it.** Load another mod's `ui`
library — JA+'s, say, as [install](/TaystJK/install/#run-taystjk-with-another-client-side-mod)
describes — and that module answers the engine instead, so TaystJK's in-game help is gone
until you switch back.

## Writing an entry

Entries are macro calls in `ui_xdocs.h`. The common case is a name, a short description and
an empty long one:

```c
XDOCS_CVAR_DEF("cg_zoomFov", "The field of view when using +zoom", "")
```

The third argument is the long form, and it is where values get enumerated. `SETTING` takes
a value and what it means, and `NL` separates lines:

```c
XDOCS_CVAR_DEF("cg_alwaysShowAbsorb", "Show absorb when it's in use",
    SETTING("0", "Absorb shows only when used against another power (Base behavior)") NL
    SETTING("1", "Absorb shows always when in use")
)
```

The short description shows on its own; the long one is added when the reader asks for the
full entry.

### Which macro

| Macro | For | Used |
|:--|:--|--:|
| `XDOCS_CVAR_DEF` | An ordinary cvar | 128 |
| `XDOCS_CMD_DEF` | A command — name and one description, no values | 6 |
| `XDOCS_CVAR_BITFLAG_DEF` | A bitmask cvar | 5 |
| `XDOCS_CVAR_KEYVALUE_DEF` | A cvar taking `key=value` pairs | 5 |
| `XDOCS_CVAR_BITVALUE_DEF` | A bitmask whose entry also carries exec text | 3 |

The bitflag and keyvalue variants are worth reaching for rather than describing the format
in prose: each prints a header explaining how to combine flags, or how key/value syntax
works, before your own lines
([`ui_xdocs.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L31)). That is the part a reader cannot guess, and
it is written once for everyone.

Inside a long description, the helpers mirror what a reader sees:

| Helper | Describes |
|:--|:--|
| `SETTING(value, text)` | One possible value |
| `BITFLAG(text)` | One bit of a bitmask |
| `KEY(key, text)` / `KEYVALUE(key, format, text)` | One key in a key/value cvar |
| `SPECIAL(token, text)` | A value that behaves unlike the rest, such as `-1` |
| `EXAMPLE(text, meaning)` | A worked example |

## Coverage

117 of 1,441 cvars have an entry. The [console reference](/TaystJK/reference/) tracks this
per entry: each detail page shows an **xdocs** badge, and the search filters include *Has
xdocs entry* and *Missing from xdocs*, so the gap is a list you can work from rather than a
guess.

That filter is the fastest way to find something worth writing. Start with a cvar you
already understand, and prefer the ones players actually set.

## When you add a cvar

An xdocs entry is on the [contributing checklist](/TaystJK/development/contributing/), along
with the registration description, the CHANGELOG line, and a menu entry where one makes
sense.
