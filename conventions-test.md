---
title: "Conventions test page"
layout: reference
nav_exclude: true
status: experimental
origin: taystjk
added_on: "2026-09-13 (6ff04c0)"
description: "Temporary page for verifying the experimental status badge. Delete once the badge has been seen rendering."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Temporary</p>

# Conventions test page

<p class="page-lede">This page exists only to verify that the <code>status: experimental</code> badge renders. Delete it once you have seen it.</p>
</div>

## What to look for

An uppercase **EXPERIMENTAL** chip in amber (`--warning`) directly above the "Temporary"
eyebrow, using the same pill shape and border treatment as the chips on the generated
reference cards.

To check the `deprecated` variant, change `status` in this page's front matter to
`deprecated`; the chip should turn red (`--danger`). Setting it to `stable`, or removing
it, should render no chip at all.

## Front matter on this page

```yaml
status: experimental
origin: taystjk
added_on: "2026-09-13 (6ff04c0)"
```

See `CONVENTIONS.md` at the repository root for what each field means.
