cmake_minimum_required(VERSION 3.15)

project(Directional VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BUILD_TUTORIALS "Build Directional tutorials" OFF)
option(BUILD_PYTHON "Build Python bindings" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(USE_GMP "Enable GMP support if found" ON)
option(DIRECTIONAL_AUTO_INSTALL_GMP "Attempt to auto-install GMP when missing on supported platforms" ON)

add_library(directional SHARED
  src/directional_core.cpp
)
add_library(Directional::directional ALIAS directional)

set_target_properties(directional PROPERTIES
  OUTPUT_NAME directional
  WINDOWS_EXPORT_ALL_SYMBOLS ON
)

target_include_directories(directional
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/eigen>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(directional PUBLIC cxx_std_20)

function(_directional_find_gmp)
  set(_directional_gmp_include_hints
    $ENV{GMP_DIR}/include
    ${CMAKE_PREFIX_PATH}/include
    /usr/include
    /usr/local/include
    /opt/homebrew/include
    "C:/Program Files/GMP/include"
  )

  set(_directional_gmp_library_hints
    $ENV{GMP_DIR}/lib
    ${CMAKE_PREFIX_PATH}/lib
    /usr/lib
    /usr/local/lib
    /opt/homebrew/lib
    "C:/Program Files/GMP/lib"
  )

  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")
    list(APPEND _directional_gmp_include_hints
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/installed/x64-windows/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/packages/gmp_x64-windows/include"
    )
    list(APPEND _directional_gmp_library_hints
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/installed/x64-windows/lib"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/installed/x64-windows/debug/lib"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/packages/gmp_x64-windows/lib"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/packages/gmp_x64-windows/debug/lib"
    )
  endif()

  find_path(GMP_INCLUDE_DIR
    NAMES gmp.h
    HINTS ${_directional_gmp_include_hints}
  )

  find_library(GMP_LIBRARIES
    NAMES gmp libgmp
    HINTS ${_directional_gmp_library_hints}
  )

  set(GMP_INCLUDE_DIR "${GMP_INCLUDE_DIR}" PARENT_SCOPE)
  set(GMP_LIBRARIES "${GMP_LIBRARIES}" PARENT_SCOPE)
endfunction()

function(_directional_try_autoinstall_gmp)
  if(NOT DIRECTIONAL_AUTO_INSTALL_GMP)
    return()
  endif()

  if(MSVC)
    set(_directional_vcpkg_root "")
    if(DEFINED ENV{VCPKG_ROOT} AND EXISTS "$ENV{VCPKG_ROOT}")
      set(_directional_vcpkg_root "$ENV{VCPKG_ROOT}")
    elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")
      set(_directional_vcpkg_root "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")
    endif()

    if(_directional_vcpkg_root)
      set(_directional_vcpkg_exe "${_directional_vcpkg_root}/vcpkg.exe")
      if(NOT EXISTS "${_directional_vcpkg_exe}")
        set(_directional_vcpkg_exe "${_directional_vcpkg_root}/vcpkg")
      elseif(NOT EXISTS "${_directional_vcpkg_exe}")
        # run bootstrap-vcpkg.bat
        execute_process(
          COMMAND ${_directional_vcpkg_root}/bootstrap-vcpkg.bat
          WORKING_DIRECTORY "${_directional_vcpkg_root}"
          RESULT_VARIABLE _directional_vcpkg_result
        )
        if(_directional_vcpkg_result EQUAL 0)
          set(_directional_vcpkg_exe "${_directional_vcpkg_root}/vcpkg")
        else()
          message(WARNING "Failed to bootstrap vcpkg")
          set(USE_GMP OFF PARENT_SCOPE)
          return()
        endif()
      endif()

      if(EXISTS "${_directional_vcpkg_exe}")
        message(STATUS "GMP not found. Attempting auto-install via vcpkg: ${_directional_vcpkg_exe}")
        set(_directional_vcpkg_cmd "${_directional_vcpkg_exe}")
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg.json")
          list(APPEND _directional_vcpkg_cmd install)
        else()
          list(APPEND _directional_vcpkg_cmd install gmp:x64-windows)
        endif()
        execute_process(
          COMMAND ${_directional_vcpkg_cmd}
          WORKING_DIRECTORY "${_directional_vcpkg_root}"
          RESULT_VARIABLE _directional_vcpkg_result
        )
        if(_directional_vcpkg_result EQUAL 0)
          list(APPEND CMAKE_PREFIX_PATH "${_directional_vcpkg_root}/installed/x64-windows")
          set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
          message(STATUS "vcpkg GMP install completed successfully.")
        else()
          message(WARNING "vcpkg GMP auto-install failed with exit code ${_directional_vcpkg_result}.")
        endif()
      else()
        message(STATUS "Vcpkg root was found, but no vcpkg executable exists at ${_directional_vcpkg_root}.")
      endif()
    else()
      message(STATUS "GMP not found and no VCPKG_ROOT/external/vcpkg checkout was detected.")
    endif()
  elseif(APPLE)
    find_program(_directional_brew_exe brew)
    if(_directional_brew_exe)
      message(STATUS "GMP not found. Attempting auto-install via Homebrew.")
      execute_process(
        COMMAND "${_directional_brew_exe}" install gmp
        RESULT_VARIABLE _directional_brew_result
      )
      if(_directional_brew_result EQUAL 0)
        execute_process(
          COMMAND "${_directional_brew_exe}" --prefix gmp
          OUTPUT_VARIABLE _directional_brew_prefix
          OUTPUT_STRIP_TRAILING_WHITESPACE
          RESULT_VARIABLE _directional_brew_prefix_result
        )
        if(_directional_brew_prefix_result EQUAL 0 AND EXISTS "${_directional_brew_prefix}")
          list(APPEND CMAKE_PREFIX_PATH "${_directional_brew_prefix}")
          set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
          message(STATUS "Homebrew GMP install completed successfully.")
        endif()
      else()
        message(WARNING "Homebrew GMP auto-install failed with exit code ${_directional_brew_result}.")
      endif()
    else()
      message(STATUS "GMP not found and Homebrew is unavailable.")
    endif()
  endif()
endfunction()

if(USE_GMP)
  message(STATUS "Attempting to find GMP for Directional core...")

  _directional_find_gmp()

  if(NOT (GMP_INCLUDE_DIR AND GMP_LIBRARIES))
    _directional_try_autoinstall_gmp()
    _directional_find_gmp()
  endif()

  if(GMP_INCLUDE_DIR AND GMP_LIBRARIES)
    message(STATUS "GMP found for Directional core:")
    message(STATUS "  Include: ${GMP_INCLUDE_DIR}")
    message(STATUS "  Library: ${GMP_LIBRARIES}")
    target_compile_definitions(directional PUBLIC USE_GMP USE_GMP_ENABLED)
    target_include_directories(directional PUBLIC $<BUILD_INTERFACE:${GMP_INCLUDE_DIR}>)
    target_link_libraries(directional PRIVATE ${GMP_LIBRARIES})
  else()
    message(WARNING "GMP not found for Directional core. Continuing without USE_GMP.")
    set(USE_GMP OFF CACHE BOOL "Enable GMP support if found" FORCE)
  endif()
endif()

if(BUILD_TUTORIALS)
  add_subdirectory(tutorial)
endif()

if(BUILD_PYTHON)
  find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
  find_package(pybind11 CONFIG REQUIRED)

  pybind11_add_module(_directional MODULE
    python/src/bindings.cpp
  )
  target_link_libraries(_directional PRIVATE Directional::directional)
  target_compile_features(_directional PRIVATE cxx_std_20)

  install(
    TARGETS _directional
    LIBRARY DESTINATION directional
    RUNTIME DESTINATION directional
  )

  install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/python/directional/__init__.py
    DESTINATION directional
  )
endif()

install(
  TARGETS directional
  EXPORT DirectionalTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/Eigen
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/unsupported")
  install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/unsupported
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
endif()

install(
  EXPORT DirectionalTargets
  FILE DirectionalTargets.cmake
  NAMESPACE Directional::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/DirectionalConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional
)
