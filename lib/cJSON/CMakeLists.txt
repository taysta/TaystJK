#============================================================================
# Copyright (C) 2013 - 2018, OpenJK contributors
#
# This file is part of the OpenJK source code.
#
# OpenJK is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
#============================================================================

# We only execute this script if the user wants to use our bundled libimgui.
#
# It is built as a static relocatable library, and linked into any target that
# requires it.
include_directories(include/)

add_library(bundled_cJSON STATIC cJSON.c)

set(CJSON_LIBRARIES bundled_cJSON PARENT_SCOPE)
set(CJSON_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/lib/cJSON/include/ PARENT_SCOPE)

mark_as_advanced(CJSON_LIBRARIES CJSON_INCLUDE_DIRS)

set_property(TARGET bundled_cJSON PROPERTY POSITION_INDEPENDENT_CODE True)