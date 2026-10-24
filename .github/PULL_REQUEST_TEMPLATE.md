## What this changes

<!-- One or two sentences. What behaviour is different after this merges? -->

## Why

<!-- The problem it solves, or the report it came from. -->

---

### Checklist

- [ ] `CHANGELOG.md` updated under **Features → Tayst's Fork**, with the right marker:
      `[+]` new · `[\*]` modified, including bug fixes · `[-]` removed
- [ ] Any new cvar or command is named in that line, in backticks
- [ ] Any new cvar or command has a description in its registration
- [ ] Any new cvar or command has an `XDOCS_*` entry in `codemp/ui/ui_xdocs.h`
- [ ] Menu entry added under `assets/japro/ui/`, if a player would change it without the console
- [ ] Behaviour with no cvar attached is documented on the wiki
- [ ] `taystJKinfo` feature flag added, if the server has to agree for it to work
- [ ] Platform or renderer differences noted, if it is not built everywhere

<!--
Strike out what does not apply rather than deleting it, so a reviewer can see it was
considered. The reasoning behind each line is at:
https://taysta.github.io/TaystJK/development/contributing/
-->
