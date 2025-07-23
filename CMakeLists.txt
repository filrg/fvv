cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    fvv
    VERSION 0.1.0
    DESCRIPTION "An effort to reimplement ISO/IEC FDIS 23090-5 Visual Volumetric Video-based Coding and Video-based Point Cloud Compression (Draft)."
    HOMEPAGE_URL "https://filrg.github.io/fvv/"
    LANGUAGES C
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

file(GLOB FVV_SHARED_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source/*)

add_library(fvv_fvv ${FVV_SHARED_SOURCE})
add_library(fvv::fvv ALIAS fvv_fvv)

target_link_libraries(fvv_fvv PRIVATE m)

include(GenerateExportHeader)
generate_export_header(
    fvv_fvv
    BASE_NAME fvv
    EXPORT_FILE_NAME export/fvv/fvv_export.h
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(fvv_fvv PUBLIC FVV_STATIC_DEFINE)
endif()

set_target_properties(
    fvv_fvv PROPERTIES
    C_VISIBILITY_PRESET hidden
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME fvv
    OUTPUT_NAME fvv
)

target_include_directories(
    fvv_fvv ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    fvv_fvv SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(fvv_fvv PUBLIC c_std_11)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${fvv_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT fvv_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of fvv"
  )
endif()

include(cmake/dev-mode.cmake)
