---
title: Shader Overrides
parent: Hardcoded Changes
has_children: false
nav_order: 3
---

# Shader Overrides

-   If there are two shaders sharing the same name, the one that was found in a file later on JKA file list (phone book order) takes precedence. For example if there is a shader called gfx/2d/charsgrid\_med in both shaders/original.shader and shaders/fonts.shader only the shader found in shaders/original.shader will be used then.
-   Before this change, combining multiple mods that target shaders from the same .shader file was impossible without merging the shaders of all the mods into one shader that is a complete copy of the base shader it originally existed in. This made it a hassle to use multiple mods that were designed to apply new shaders to base assets.
