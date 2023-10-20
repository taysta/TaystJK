#!/bin/bash

#BUILDDIR=build
#BUILDDIR=build64
BUILDDIR=buildi686

if [ -d "$BUILDDIR" ]; then
	cd "$BUILDDIR"
else
	mkdir "$BUILDDIR"
	cd "$BUILDDIR"
fi

cmake -DCMAKE_TOOLCHAIN_FILE=CMakeModules/Toolchains/linux-i686-icc.cmake -DBuildMPRend2=OFF ..


make -j8

