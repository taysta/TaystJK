---
title: "Console scripting"
layout: reference
nav_order: 11
parent: "Features"
description: "Nested quotes, conditional commands with ifCvar, cvar substitution with strSub, and the delay and waitf timers."
toc: true
origin: newjk
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Console scripting

<p class="page-lede">Four additions turn binds and configs from fixed strings into something you can branch on, substitute into, and schedule. They are most useful together, so this page covers all four.</p>
</div>

Everything here came from NewJK and NewMod, and
[their documentation](https://jkanewmod.github.io/documentation_commands.html) is the
original account of `ifCvar` and `strSub`. This page describes what the TaystJK client
actually does, which is not identical. See [things to watch for](#things-to-watch-for).

The console reference has the catalogue entries:
[`ifCvar`](/TaystJK/reference/commands/ifcvar-a68f57c/),
[`strSub`](/TaystJK/reference/commands/strsub-25a3e39/),
[`delay`](/TaystJK/reference/commands/delay-ab464f0/),
[`waitf`](/TaystJK/reference/commands/waitf-1b1b6e3/),
[`delaycancel`](/TaystJK/reference/commands/delaycancel-8b62c65/) and
[`waitfcancel`](/TaystJK/reference/commands/waitfcancel-4f1a371/).

## Quoting and nested quotes

Stock Jedi Academy ends a quoted string at the next `"`, so a bind cannot contain a bind.
TaystJK tracks how deeply quotes are nested instead, and one rule makes it work:

**Each time a command is executed, exactly one layer of quotes is removed.**

So this is a single bind that, when pressed, creates another bind:

```text
bind a "bind b "set c "d ; e" ; say "hello there"""
```

Pressing <kbd>A</kbd> peels the outer quotes and runs `bind b "set c "d ; e" ; say "hello
there""`. Pressing <kbd>B</kbd> peels the next layer. Count your closing quotes at the end;
three in a row is not a typo.

A `"` counts as **opening** a level only when the character after it is not a space, a `;`
or another `"`, and the character before it is not a `"`
([`IsOpeningQuote`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cmd.cpp#L251)).
That heuristic is what lets the parser tell `say "hi"` from a stray quote, and it is why
`""` is treated as an empty argument rather than as one level of nesting.

Three places count depth the same way, which is why the feature holds up across all the
routes a command can take: the command buffer, so a `;` inside quotes no longer splits the
line
([`Cbuf_Execute`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cmd.cpp#L337));
the tokenizer that splits a line into arguments
([`Cmd_TokenizeStringNestedQuotes`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cmd.cpp#L820),
used by
[`Cmd_ExecuteString`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cmd.cpp#L1043));
and bind parsing, so a bound string containing `;` inside quotes stays one command
([`CL_ParseBinding`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_keys.cpp#L1655)).

There is no backslash escape. `\"` is not special; depth counting is the only mechanism.

## Substituting cvar values: `strSub`

`strSub` runs the command that follows it, first replacing every `$cvarname$` with that
cvar's current value
([`Com_StrSub_f`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/common.cpp#L433)).

```text
strSub say "Hello, I am $name$"
```

The name is delimited on **both** sides by `$`. Write `$$` for a literal dollar sign
([`common.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/common.cpp#L454)).
Substitution happens per argument, so a value containing spaces is re-quoted as one
argument before the command runs.

This is the difference between `say My fps cap is $com_maxfps$` under `strSub`, which sends
the number, and `vstr`, which executes a cvar's contents as a command. Use `strSub` when you
want a value *inside* a string; use `vstr` when the cvar *is* the command.

## Branching on a cvar: `ifCvar`

`ifCvar` reads one cvar, tests it against conditions in order, and runs the command
belonging to the **first** match
([`Com_IfCvar_f`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/common.cpp#L346)).
Nothing runs if no condition matches.

```text
ifCvar <cvar> <setting> <count> <command...> [<setting> <count> <command...> ...]
```

The simplest form compares the value as text:

```text
ifCvar cg_myCvar 0 2 say_team hi 1 2 say_team bye
```

If `cg_myCvar` is `0` it says `hi`; if it is `1` it says `bye`. The `2` before each command
is the argument count, explained [below](#counting-arguments).

### Modifiers

A setting may start with one of these. Without one, the comparison is a case-insensitive
string match.

| Modifier | Test |
|:--|:--|
| `$=` | Numeric equality |
| `$!=` | Numeric inequality |
| `$>` | Numerically greater than |
| `$<` | Numerically less than |
| `$>=` | Numerically greater than or equal |
| `$<=` | Numerically less than or equal |
| `$contains` | The value contains this text anywhere |
| `$beginswith` | The value starts with this text |
| `$startswith` | Alias for `$beginswith` |
| `$endswith` | The value ends with this text |
| `$else` | Always true |

`$startswith` is accepted alongside `$beginswith`
([`common.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/common.cpp#L394));
the NewMod documentation lists only `$beginswith`.

The text follows the modifier with no space: `$containsbeer`, `$>=50`, `$else`. Put a
`$` in front of the comparison value to read it from another cvar instead of using it
literally, for example `$>=$cg_someOtherCvar` or `$contains$cg_someOtherCvar`. It works
with every modifier and with plain equality
([`common.cpp`](https://github.com/taysta/TaystJK/blame/4cca97d97551d2fda974e7fe7d5693f21900a2f3/codemp/qcommon/common.cpp#L389)). If a `$contains`, `$beginswith` or `$endswith` condition always
matches, update your build: older builds looked up the wrong cvar for those.

An empty setting, `""`, matches a cvar whose value is empty.

`$else` should be last. It always matches, so anything after it is unreachable.

### Counting arguments

The number before each command is **how many arguments that command occupies, including the
command's own name**. This is the part that trips people up.

| Command to run | Count | Why |
|:--|:--|:--|
| `quit` | `1` | The command name only. |
| `say_team hi` | `2` | Name plus one word. |
| `set model desann` | `3` | Name plus two words. |
| `bind x say_team "hello there"` | `4` | `"hello there"` is quoted, so it is **one** argument. |

A quoted phrase counts once, and the client re-adds the quotes when it runs the command
([`common.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/common.cpp#L417)).
Get the count wrong and `ifCvar` reads the following condition from the middle of your
command; the count must be between 1 and 1023 or it refuses and prints why
([`common.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/common.cpp#L410)).

Putting it together:

```text
ifCvar cg_myCvar $>=$cg_someOtherCvar 1 quit $containsbeer 3 set model desann $else 4 bind x say_team "hello there"
```

Greater than or equal to `cg_someOtherCvar` quits; otherwise a value containing `beer`
switches model; otherwise the bind is set.

## Timed commands: `delay` and `waitf`

Stock `wait` stalls the entire command buffer. `delay` and `waitf` take what comes after them
out of the buffer and run it later, so the game keeps going in the meantime. `delay` counts
milliseconds, `waitf` counts frames.

```text
say darth;delay 1000;say vader
```

Two things about the syntax are not obvious, and both follow from these being intercepted
in the command buffer rather than run as ordinary commands
([`Cbuf_Execute`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cmd.cpp#L290)):

- **A `;` or a newline must follow the number.** `delay 1000 say vader` prints usage and
  does nothing. `delay 1000;say vader` works.
- **Everything after that `;` is deferred as one unit**: not just the rest of the line, but
  everything else waiting in the command buffer
  ([`cmd.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cmd.cpp#L324)).
  So `a;delay 500;b;delay 500;c` runs `a`, waits, then runs `b;delay 500;c`; the delays chain
  instead of both counting from now. In a config run with `exec`, a `delay` holds back every
  line after it in that file too.

Omitting the number entirely is the same as `1`, but a space must remain between the
command and the separator: `delay ;say vader` works, while `delay;say vader` does not
([`cmd.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cmd.cpp#L301)).

`delaycancel` and `waitfcancel` drop pending entries whose text contains the argument, so
`delaycancel vader` cancels the example above. `delaycancel ""` cancels every pending
`delay`. Each cancels only its own kind.

## Things to watch for

**`strSub` needs the closing `$`.** `$name` without a trailing `$` takes the rest of the
argument as the cvar name
([`common.cpp`](https://github.com/taysta/TaystJK/blame/4cca97d97551d2fda974e7fe7d5693f21900a2f3/codemp/qcommon/common.cpp#L459)), which is rarely the cvar you meant.

Report anything else you hit at
<https://github.com/taysta/TaystJK/issues>.
