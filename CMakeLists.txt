cmake_minimum_required( VERSION 3.0 FATAL_ERROR )

# Solution
project( HandmadeQuake )

set_property( GLOBAL PROPERTY USE_FOLDERS ON )

include_directories("${PROJECT_SOURCE_DIR}/src")

# Project HandmadeQuake
add_executable( HandmadeQuake
  ${PROJECT_SOURCE_DIR}/src/main.c
  ${PROJECT_SOURCE_DIR}/src/common.h
  ${PROJECT_SOURCE_DIR}/src/common.c
  ${PROJECT_SOURCE_DIR}/src/q_stl.h
  ${PROJECT_SOURCE_DIR}/src/q_stl.c
  ${PROJECT_SOURCE_DIR}/src/quakedef.h
  ${PROJECT_SOURCE_DIR}/src/winquake.h
)

# Visual Studio
if(MSVC)
    set_target_properties( HandmadeQuake PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
endif()
