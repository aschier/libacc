cmake_minimum_required(VERSION 2.8.10)
project(libacc)
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(LIBACC_USE_EIGEN FALSE CACHE BOOL "Use libeigen vectors")

add_library(libacc INTERFACE)
target_include_directories(libacc INTERFACE
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
if(LIBACC_USE_EIGEN)
target_compile_definitions(libacc INTERFACE USE_LIBEIGEN)
endif()

configure_package_config_file(libaccConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/libaccConfig.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX})
install(TARGETS libacc EXPORT libacc-targets)

install(EXPORT libacc-targets FILE libaccTargets.cmake DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/libacc/cmake)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libaccConfig.cmake DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/libacc/cmake)
install(DIRECTORY "" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libacc FILES_MATCHING PATTERN "*.h" PATTERN ".git" EXCLUDE)
