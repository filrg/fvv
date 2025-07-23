if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/fvv-${PROJECT_VERSION}"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package fvv)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT fvv_Development
)

install(
    TARGETS fvv_fvv
    EXPORT fvvTargets
    RUNTIME #
    COMPONENT fvv_Runtime
    LIBRARY #
    COMPONENT fvv_Runtime
    NAMELINK_COMPONENT fvv_Development
    ARCHIVE #
    COMPONENT fvv_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    fvv_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE fvv_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(fvv_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${fvv_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT fvv_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${fvv_INSTALL_CMAKEDIR}"
    COMPONENT fvv_Development
)

install(
    EXPORT fvvTargets
    NAMESPACE fvv::
    DESTINATION "${fvv_INSTALL_CMAKEDIR}"
    COMPONENT fvv_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
