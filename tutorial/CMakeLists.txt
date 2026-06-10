cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Directional_tutorials)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Optional: use -std=c++20 instead of -std=gnu++20

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      Debug
      CACHE STRING "Build type")
endif()

option(DIRECTIONAL_VIEWER "Directional Viewer" ON)
option(DIRECTIONAL_ENABLE_GMP "Enable GMP support if found" ON)
option(DIRECTIONAL_ENABLE_SUITESPARSE "Enable SuiteSparse support if found" ON)

set(DIRECTIONAL_TUTORIALS
    "ALL"
    CACHE STRING "Semicolon-separated tutorial directories to build, or ALL")

message(STATUS "CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")

set(DIRECTIONAL_ROOT "${CMAKE_CURRENT_LIST_DIR}/../")
set(DIRECTIONAL_SOURCE_DIR "${DIRECTIONAL_ROOT}/include")
set(DIRECTIONAL_EXTERNAL "${DIRECTIONAL_ROOT}/external")
list(APPEND CMAKE_MODULE_PATH "${DIRECTIONAL_ROOT}/cmake")
include(DirectionalDependencyConfig)
include(DirectionalVcpkg)
include(DirectionalRuntime)

message(STATUS "DIRECTIONAL_ROOT: ${DIRECTIONAL_ROOT}")

include_directories(${DIRECTIONAL_SOURCE_DIR})
include_directories(${DIRECTIONAL_EXTERNAL}/eigen)

# Polyscope
add_subdirectory(${DIRECTIONAL_EXTERNAL}/polyscope "polyscope")

# Tutorial data path and output path (create dirs if needed)
set(TUTORIAL_DATA_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/data"
    CACHE PATH "location of tutorial data resources")
set(TUTORIAL_OUTPUT_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/output"
    CACHE PATH "location of tutorial outputs")

file(MAKE_DIRECTORY "${TUTORIAL_DATA_PATH}")
file(MAKE_DIRECTORY "${TUTORIAL_OUTPUT_PATH}")

# Set runtime output dir and create
function(directional_finalize_tutorial_target target_name)
  set(_tutorial_output_dir "${CMAKE_BINARY_DIR}/install")
  set_target_properties(
    ${target_name}
    PROPERTIES RUNTIME_OUTPUT_NAME "${target_name}-$<CONFIG>"
               RUNTIME_OUTPUT_DIRECTORY 
               "${_tutorial_output_dir}/bin"
               RUNTIME_OUTPUT_DIRECTORY_DEBUG
               "${_tutorial_output_dir}/bin"
               RUNTIME_OUTPUT_DIRECTORY_RELEASE
               "${_tutorial_output_dir}/bin"
               RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO
               "${_tutorial_output_dir}/bin"
               RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL
               "${_tutorial_output_dir}/bin")
endfunction()

# Interface library for tutorial targets
add_library(tutorials INTERFACE)

target_compile_definitions(
  tutorials
  INTERFACE TUTORIAL_DATA_PATH=\"${TUTORIAL_DATA_PATH}\"
            TUTORIAL_OUTPUT_PATH=\"${TUTORIAL_OUTPUT_PATH}\"
            GLM_ENABLE_EXPERIMENTAL)

target_include_directories(
  tutorials
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${POLYSCOPE_SOURCE_DIR}/include
            ${POLYSCOPE_SOURCE_DIR}/deps/imgui/imgui
            ${POLYSCOPE_SOURCE_DIR}/deps/glm)

# Reuse the top-level dependency discovery so tutorial builds match the
# wheel/standalone builds.
if(DIRECTIONAL_ENABLE_GMP)
  message(STATUS "Attempting to find GMP...")
  _directional_find_gmp()
  if(NOT TARGET GMP::GMP OR NOT TARGET GMP::GMPXX)
    _directional_try_autoinstall_gmp()
    _directional_find_gmp()
  endif()

  if(TARGET GMP::GMP AND TARGET GMP::GMPXX)
    message(STATUS "GMP found:")
    target_compile_definitions(
      tutorials INTERFACE DIRECTIONAL_ENABLE_GMP USE_GMP USE_GMP_ENABLED
                          GMP_ENABLED ENABLE_GMP)
    target_link_libraries(tutorials INTERFACE GMP::GMP)
    target_link_libraries(tutorials INTERFACE GMP::GMPXX)
  else()
    message(WARNING "GMP not found. Disabling DIRECTIONAL_ENABLE_GMP.")
    set(DIRECTIONAL_ENABLE_GMP
        OFF
        CACHE BOOL "Enable GMP support if found" FORCE)
  endif()
endif()

if(DIRECTIONAL_ENABLE_SUITESPARSE)
  message(STATUS "Attempting to find SuiteSparse...")
  _directional_find_suitesparse()
  if(MSVC AND DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
    _directional_install_suitesparse_metis_windows()
  endif()

  _directional_find_suitesparse()

  if(NOT DIRECTIONAL_SUITESPARSE_CONFIG_FOUND)
    if(NOT SUITESPARSE_TARGETS)
      _directional_try_autoinstall_suitesparse()
      _directional_find_suitesparse()
    endif()
  endif()

  if(SUITESPARSE_TARGETS)
    message(STATUS "SuiteSparse found:")
    foreach(_target IN LISTS SUITESPARSE_TARGETS)
      if(TARGET ${_target})
        message(
          STATUS "SuiteSparse target found for Directional core: ${_target}")
        target_link_libraries(tutorials INTERFACE ${_target})
      endif()
    endforeach()
    target_compile_definitions(
      tutorials
      INTERFACE DIRECTIONAL_ENABLE_SUITESPARSE USE_SUITESPARSE
                USE_SUITESPARSE_ENABLED SUITESPARSE_ENABLED ENABLE_SUITESPARSE)
  else()
    message(
      WARNING "SuiteSparse not found. Disabling DIRECTIONAL_ENABLE_SUITESPARSE."
    )
    set(DIRECTIONAL_ENABLE_SUITESPARSE
        OFF
        CACHE BOOL "Enable SuiteSparse support if found" FORCE)
  endif()
endif()

# ===== Chapters =====
set(DIRECTIONAL_ALL_TUTORIALS
    101_GlyphRendering
    102_DiscreteTangentBundles
    103_StreamlineTracing
    104_FaceVertexEdgeData
    105_Sparsity
    106_PrincipalDirections
    201_PrincipalMatching
    202_Sampling
    203_Combing
    301_PowerFields
    302_PolyVectors
    303_GinzburgLandau
    304_IntegrableFields
    401_IndexPrescription
    501_SeamlessIntegration
    502_DifferentOrders
    503_SeamsSingsRounding
    504_LinearReductions
    505_Meshing
    601_FaceBasedFEM
    602_DiscreteExteriorCalculus
    603_HodgeDecomposition
    604_HodgeBoundary
    605_HarmonicFields
    701_SubdivisionFields)

if(DIRECTIONAL_TUTORIALS STREQUAL "ALL")
  set(DIRECTIONAL_SELECTED_TUTORIALS ${DIRECTIONAL_ALL_TUTORIALS})
else()
  string(REPLACE "," ";" DIRECTIONAL_TUTORIAL_REQUESTS
                 "${DIRECTIONAL_TUTORIALS}")
  set(DIRECTIONAL_SELECTED_TUTORIALS)
  foreach(DIRECTIONAL_TUTORIAL_REQUEST IN LISTS DIRECTIONAL_TUTORIAL_REQUESTS)
    set(DIRECTIONAL_RESOLVED_TUTORIAL "")
    list(FIND DIRECTIONAL_ALL_TUTORIALS "${DIRECTIONAL_TUTORIAL_REQUEST}"
         DIRECTIONAL_TUTORIAL_INDEX)
    if(NOT DIRECTIONAL_TUTORIAL_INDEX EQUAL -1)
      set(DIRECTIONAL_RESOLVED_TUTORIAL "${DIRECTIONAL_TUTORIAL_REQUEST}")
    elseif(DIRECTIONAL_TUTORIAL_REQUEST MATCHES "^[0-9]+$")
      foreach(DIRECTIONAL_CANDIDATE IN LISTS DIRECTIONAL_ALL_TUTORIALS)
        if(DIRECTIONAL_CANDIDATE MATCHES "^${DIRECTIONAL_TUTORIAL_REQUEST}_")
          if(DIRECTIONAL_RESOLVED_TUTORIAL)
            message(
              FATAL_ERROR
                "Tutorial prefix '${DIRECTIONAL_TUTORIAL_REQUEST}' is ambiguous. "
                "Use one of the full names: ${DIRECTIONAL_ALL_TUTORIALS}")
          endif()
          set(DIRECTIONAL_RESOLVED_TUTORIAL "${DIRECTIONAL_CANDIDATE}")
        endif()
      endforeach()
    endif()

    if(NOT DIRECTIONAL_RESOLVED_TUTORIAL)
      message(
        FATAL_ERROR
          "Unknown tutorial '${DIRECTIONAL_TUTORIAL_REQUEST}'. "
          "Use a numeric prefix like 501 or a full name from: ${DIRECTIONAL_ALL_TUTORIALS}"
      )
    endif()

    list(APPEND DIRECTIONAL_SELECTED_TUTORIALS
         "${DIRECTIONAL_RESOLVED_TUTORIAL}")
  endforeach()

  list(REMOVE_DUPLICATES DIRECTIONAL_SELECTED_TUTORIALS)
  if(NOT DIRECTIONAL_SELECTED_TUTORIALS)
    message(FATAL_ERROR "No tutorials selected.")
  endif()
endif()

message(
  STATUS "Directional tutorials selected: ${DIRECTIONAL_SELECTED_TUTORIALS}")

if(DIRECTIONAL_VIEWER)
  foreach(DIRECTIONAL_TUTORIAL_DIR IN LISTS DIRECTIONAL_SELECTED_TUTORIALS)
    add_subdirectory("${DIRECTIONAL_TUTORIAL_DIR}")
  endforeach()
endif()

if(WIN32)
  if(DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
    foreach(_excluded IN LISTS _directional_tutorials_exclude)
      get_target_property(_runtime_dll SuiteSparse::${_excluded} SUITESPARSE_RUNTIME_DLL)
      if(_runtime_dll)
        install(FILES "${_runtime_dll}" DESTINATION "${CMAKE_BINARY_DIR}/install/bin")
      endif()
    endforeach()
  endif()
endif()