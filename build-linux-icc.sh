#!/bin/bash

#BUILDDIR=build
BUILDDIR=build64
#BUILDDIR=build-x86_64

if [ -d "$BUILDDIR" ]; then
	cd "$BUILDDIR"
else
	mkdir "$BUILDDIR"
	cd "$BUILDDIR"
fi

#cmake -DCMAKE_TOOLCHAIN_FILE=CMakeModules/Toolchains/linux-icc.cmake -DBuildMPRend2=OFF ..
cmake -DCMAKE_TOOLCHAIN_FILE=CMakeModules/Toolchains/linux-icc.cmake -DBuildMPRend2=OFF -DUseInternalSDL2=ON ..
