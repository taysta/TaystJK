# TTF/OTF font support for the renderers (rd-common/tr_font.cpp) via FreeType.
#
# taystjk_target_use_freetype(<target>) links FreeType into a renderer and
# defines USE_FREETYPE for it. The system library is used when available and
# UseInternalFreeType is off; otherwise a pinned FreeType is built from source
# as a static library.

function(taystjk_target_use_freetype target)
	if(NOT BuildFreeTypeSupport)
		return()
	endif()

	if(NOT UseInternalFreeType AND NOT TARGET freetype)
		find_package(Freetype)
		if(FREETYPE_FOUND)
			target_include_directories(${target} PRIVATE ${FREETYPE_INCLUDE_DIRS})
			target_link_libraries(${target} ${FREETYPE_LIBRARIES})
			target_compile_definitions(${target} PRIVATE USE_FREETYPE)
			return()
		endif()
		message(STATUS "System FreeType not found; building it from source.")
	endif()

	if(NOT TARGET freetype)
		include(FetchContent)
		# Only outline rasterisation is needed, so none of the optional
		# dependencies are pulled in.
		set(FT_DISABLE_ZLIB     ON CACHE BOOL "" FORCE)
		set(FT_DISABLE_BZIP2    ON CACHE BOOL "" FORCE)
		set(FT_DISABLE_PNG      ON CACHE BOOL "" FORCE)
		set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)
		set(FT_DISABLE_BROTLI   ON CACHE BOOL "" FORCE)
		set(SKIP_INSTALL_ALL    ON)
		# FreeType includes CPack itself; keep it from overwriting our own
		# package configuration.
		set(CPACK_OUTPUT_CONFIG_FILE "${CMAKE_BINARY_DIR}/_deps/freetype-CPackConfig.cmake")
		set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "${CMAKE_BINARY_DIR}/_deps/freetype-CPackSourceConfig.cmake")
		set(BUILD_SHARED_LIBS   OFF)
		# The static library is linked into the renderer shared objects.
		set(CMAKE_POSITION_INDEPENDENT_CODE ON)
		FetchContent_Declare(freetype
			GIT_REPOSITORY "https://github.com/freetype/freetype.git"
			GIT_TAG "42608f77f20749dd6ddc9e0536788eaad70ea4b5") # VER-2-13-3
		FetchContent_MakeAvailable(freetype)
	endif()

	target_link_libraries(${target} freetype)
	target_compile_definitions(${target} PRIVATE USE_FREETYPE)
endfunction()
