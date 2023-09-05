# EternalJK
[![build](https://github.com/JKSunny/EternalJK/actions/workflows/build.yml/badge.svg)](https://github.com/JKSunny/EternalJK/actions/workflows/build.yml)

This fork focuses on the jaPRO integration and Client Engine modifications.

If you have any suggestions or would like to submit a bug report, please post them in [issues](https://github.com/JKSunny/EternalJK/issues).

[![Website](https://img.shields.io/badge/website-japro-brightgreen.svg)](http://playja.pro) [![Fork](https://img.shields.io/badge/repository-japro%20game%20library-blue.svg)](https://github.com/videoP/jaPRO)

## License

[![License](https://img.shields.io/github/license/eternalcodes/EternalJK.svg)](https://github.com/eternalcodes/EternalJK/blob/master/LICENSE.txt)

OpenJK is licensed under GPLv2 as free software. You are free to use, modify and redistribute OpenJK following the terms in LICENSE.txt.


## For players

Installing and running EternalJK:

1. [Download the latest release](https://github.com/JKSunny/EternalJK/releases).
2. Extract the file into the Jedi Academy `GameData` folder. For Steam users, this will be in `<Steam Folder>/steamapps/common/Jedi Academy/GameData/`.
3. Run eternaljk.x86.exe (Rename to jamp.exe for better steam support)

#### How to enable vulkan 
1. Open up the console by pressing <kbd>~ Tilde</kbd> key
2. Type "/cl_renderer rd-vulkan; vid_restart" and hit enter

## For Developers

### Contributing to EternalJK
* [Fork](https://github.com/JKSunny/EternalJK/fork) the EternalJK project on GitHub
* Create a new branch on your fork and make your changes
* Send a [pull request](https://help.github.com/articles/creating-a-pull-request) to upstream (eternaljk/master)

### Vulkan support
Support Initially started by porting to [Quake-III-Arena-Kenny-Edition](https://github.com/kennyalive/Quake-III-Arena-Kenny-Edition).<br />
After that, I found [vkQuake3](https://github.com/suijingfeng/vkQuake3/tree/master/code), hence the file structure.

Lastly, I stumbled across [Quake3e](https://github.com/ec-/Quake3e).<br />
Which is highly maintained, and is packed with many additions compared to the other repositories.

Therefore the vulkan renderer is now based on Quake3e. <br />A list of the additions can be found on [here](https://github.com/ec-/Quake3e#user-content-vulkan-renderer).

Many thanks to all the contributors that worked & are still working hard on improving the Q3 engine!

## Maintainers

* [eternal](https://github.com/eternalcodes)

## Contributors 
* [bucky](https://github.com/Bucky21659)
* [loda](https://github.com/videoP)
