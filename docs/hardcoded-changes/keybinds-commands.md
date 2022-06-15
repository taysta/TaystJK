---
title: Keybinds & Commands
parent: Hardcoded Changes
has_children: false
nav_order: 1
---

# Keybind & Command Updates

-   You can now bind key combinations using an <kbd>Alt</kbd> / <kbd>Ctrl</kbd> / <kbd>Shift</kbd> modifier key. For example, `bind ctrl+x kill` will make <kbd>Ctrl</kbd> + <kbd>X</kbd> perform `kill`.
-   You can now bind the _right-side_ <kbd>Alt</kbd> / <kbd>Ctrl</kbd> / <kbd>Shift</kbd> keys separately from the _left-side_ keys. For example, `bind rctrl kill` will make the _right-side_ <kbd>Ctrl</kbd> key perform `kill`. Don't worry, your existing configuration is still 100% compatible — if no binding is specifically set for the right-side key, then the generic binding is used. The left-side key always uses the generic binding.
-   Nested quotation marks are now supported in commands and binds, allowing for easier and more robust configuration. This allows entering commands like bind a "bind b "set c "d ; e" ; say "hello there"""
