# TaystJK

[![Build](https://github.com/taysta/TaystJK/actions/workflows/build.yml/badge.svg)](https://github.com/taysta/TaystJK/actions/workflows/build.yml)
[![License](https://img.shields.io/github/license/taysta/TaystJK.svg)](LICENSE.txt)

TaystJK is a Jedi Academy multiplayer client and dedicated server built on EternalJK, which is built on OpenJK and jaPRO. It focuses on compatibility across Base JKA, JA+, jaPRO, and Lugormod servers, engine stability and performance, and improvements to everyday play.

**[Download the latest build](https://github.com/taysta/TaystJK/releases/tag/latest)** · **[Documentation and wiki](https://taysta.github.io/TaystJK/)**

When you join a server, its game module determines the gameplay and which mod-specific features are available.

## Getting started

You need a copy of Jedi Academy and its retail `base/assets0.pk3` through `base/assets3.pk3` files.

1. Download the [latest build](https://github.com/taysta/TaystJK/releases/tag/latest) for your operating system and architecture, and extract the whole archive into a writable directory.
2. Copy the game's `base` directory beside the TaystJK executable or macOS app bundle, or point TaystJK at an existing installation with `fs_cdPath` as described in the installation guide.
3. Launch the TaystJK executable or app included in the archive.

Follow the [installation guide](https://taysta.github.io/TaystJK/install/) for platform prerequisites, launch commands, and layouts for sharing game files between clients.

## Documentation

The [documentation site](https://taysta.github.io/TaystJK/) contains the setup guides, feature explanations, and a searchable console reference generated from the source code.

| Guide | What it covers |
| --- | --- |
| [Installation](https://taysta.github.io/TaystJK/install/) | Platform setup, build choices, game files, and mod compatibility. |
| [Server hosting](https://taysta.github.io/TaystJK/server-hosting/) | Dedicated servers, Docker Compose, bundled game modes, and PK3 downloads. |
| [Features](https://taysta.github.io/TaystJK/features/) | HUD and movement tools, renderers, cosmetics, scripting, and [what's new](https://taysta.github.io/TaystJK/features/whats-new/). |
| [Console reference](https://taysta.github.io/TaystJK/reference/) | Cvars and commands, defaults, options, module and renderer scope, and source links. |
| [Development](https://taysta.github.io/TaystJK/development/) | Compilation, debugging, libraries, and contributing. |
| [Help](https://taysta.github.io/TaystJK/help/) | Troubleshooting, the glossary, and where to report problems. |

## Development and contributions

TaystJK uses CMake. Start with the [compilation guide](https://taysta.github.io/TaystJK/development/compiling/) and [debugging guide](https://taysta.github.io/TaystJK/development/debugging/) for this project's build options and platform instructions.

Fork the repository, make your changes on a branch, and open a pull request against `master` unless asked otherwise. The [contributing guide](https://taysta.github.io/TaystJK/development/contributing/) covers review, CI builds, and documenting changes.

The documentation site lives on the [`gh-pages` branch](https://github.com/taysta/TaystJK/tree/gh-pages). See [how the site is built](https://taysta.github.io/TaystJK/development/documentation-system/) before editing guides or regenerating the reference.

## Maintainer and upstream projects

Maintained by [tayst](https://github.com/taysta).

TaystJK incorporates work from [OpenJK](https://github.com/JACoders/OpenJK), [jaPRO](https://github.com/videoP/jaPRO), [EternalJK](https://github.com/eternalcodes/EternalJK), [SomaZ's rend2](https://github.com/SomaZ/OpenJK/tree/rend2-unified-wip), and [JKSunny's Vulkan renderer](https://github.com/JKSunny/EternalJK), among other community projects.

## License

TaystJK is free software licensed under GPLv2. You may use, modify, and redistribute it under the terms in [LICENSE.txt](LICENSE.txt).
