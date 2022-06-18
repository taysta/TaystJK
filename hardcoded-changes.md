---
title: Hardcoded Changes
has_children: true
nav_order: 3
---

# Hardcoded Changes

As EternalJK is a total engine replacement, many hardcoded changes have been implemented to improve quality of life when playing Jedi Academy.

## Keybinds & Commands

- You can now bind key combinations using an <kbd>Alt</kbd> / <kbd>Ctrl</kbd> / <kbd>Shift</kbd> modifier key. For example, `bind ctrl+x kill` will make <kbd>Ctrl</kbd> + <kbd>X</kbd> perform `kill`.
- You can now bind the _right-side_ <kbd>Alt</kbd> / <kbd>Ctrl</kbd> / <kbd>Shift</kbd> keys separately from the _left-side_ keys. For example, `bind rctrl kill` will make the _right-side_ <kbd>Ctrl</kbd> key perform `kill`. Don't worry, your existing configuration is still 100% compatible — if no binding is specifically set for the right-side key, then the generic binding is used. The left-side key always uses the generic binding.
- Nested quotation marks are now supported in commands and binds, allowing for easier and more robust configuration. This allows entering commands like bind a "bind b "set c "d ; e" ; say "hello there"""

## Miscellaneous

- Fixed various Linux compiling problems and related crashes
- Fixed null skin name crash
- Water wake shader fix from Circa
- Textureless MP Swoop fix from MagSul
- Jawa sound fixes from eezstreet
- Broken effects fixes
- Weapon charge sounds now accurately reflect their charge times
- Reduced NPCs choppy/laggy movement
- Chat/console now support \[<kbd>shift</kbd>+\]<kbd>ctrl</kbd>+<kbd>backspace</kbd>/<kbd>del</kbd>/<kbd>left</kbd>/<kbd>right</kbd> shortcuts

## Shader Overrides

- If there are two shaders sharing the same name, the one that was found in a file later on JKA file list (phone book order) takes precedence. For example if there is a shader called gfx/2d/charsgrid\_med in both shaders/original.shader and shaders/fonts.shader only the shader found in shaders/original.shader will be used then.
- Before this change, combining multiple mods that target shaders from the same .shader file was impossible without merging the shaders of all the mods into one shader that is a complete copy of the base shader it originally existed in. This made it a hassle to use multiple mods that were designed to apply new shaders to base assets.

## Vulkan Renderer

- Enable with `cl_renderer rd-vulkan; vid_restart`
- `r_fbo 1; r_bloom 1` to enable bloom, adjust with `r_bloom_intensity` and `r_bloom_threshold`
- Based on [Quake3e's Vulkan renderer](https://github.com/ec-/Quake3e#vulkan-renderer)
- From [JKSunny/EternalJK](https://github.com/JKSunny/EternalJK)