cmake_minimum_required(VERSION 3.21)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(DirectionalTutorials LANGUAGES CXX)

  set(DIRECTIONAL_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." CACHE PATH
      "Path to the refactored Directional source tree")

  if(NOT EXISTS "${DIRECTIONAL_ROOT}/CMakeLists.txt")
    message(FATAL_ERROR
      "DIRECTIONAL_ROOT must point to the refactored Directional source tree")
  endif()

  set(BUILD_TUTORIALS OFF CACHE BOOL "" FORCE)
  add_subdirectory("${DIRECTIONAL_ROOT}" "${CMAKE_BINARY_DIR}/directional")
else()
  set(DIRECTIONAL_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")
endif()

if(NOT TARGET Directional::directional)
  message(FATAL_ERROR
    "The tutorials require the refactored Directional::directional target")
endif()

if(NOT TARGET polyscope)
  if(EXISTS "${DIRECTIONAL_ROOT}/external/polyscope/CMakeLists.txt")
    add_subdirectory("${DIRECTIONAL_ROOT}/external/polyscope"
                     "${CMAKE_BINARY_DIR}/polyscope")
  else()
    find_package(polyscope CONFIG QUIET)
  endif()
endif()

if(NOT TARGET polyscope)
  message(FATAL_ERROR
    "Polyscope is required to build the tutorials. Add it at "
    "external/polyscope or provide a package exporting the polyscope target.")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DIRECTIONAL_TUTORIALS "ALL" CACHE STRING
    "Semicolon-separated tutorial directories to build, or ALL")
set(TUTORIAL_DATA_PATH "${CMAKE_CURRENT_SOURCE_DIR}/data" CACHE PATH
    "Location of tutorial data resources")
set(TUTORIAL_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/output" CACHE PATH
    "Location for tutorial-generated files")

file(MAKE_DIRECTORY "${TUTORIAL_DATA_PATH}")
file(MAKE_DIRECTORY "${TUTORIAL_OUTPUT_PATH}")

add_library(directional_tutorial_common INTERFACE)
target_link_libraries(
  directional_tutorial_common
  INTERFACE Directional::directional polyscope)
target_include_directories(
  directional_tutorial_common
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(
  directional_tutorial_common
  INTERFACE
    TUTORIAL_DATA_PATH="${TUTORIAL_DATA_PATH}"
    TUTORIAL_OUTPUT_PATH="${TUTORIAL_OUTPUT_PATH}"
    GLM_ENABLE_EXPERIMENTAL)
target_compile_features(directional_tutorial_common INTERFACE cxx_std_20)

function(directional_add_tutorial tutorial_name)
  add_executable(${tutorial_name} main.cpp ${ARGN})
  target_link_libraries(${tutorial_name} PRIVATE directional_tutorial_common)

  set(_tutorial_output_dir "${CMAKE_BINARY_DIR}/install/bin")
  set_target_properties(
    ${tutorial_name}
    PROPERTIES
      RUNTIME_OUTPUT_NAME "${tutorial_name}-$<CONFIG>"
      RUNTIME_OUTPUT_DIRECTORY "${_tutorial_output_dir}"
      RUNTIME_OUTPUT_DIRECTORY_DEBUG "${_tutorial_output_dir}"
      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${_tutorial_output_dir}"
      RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${_tutorial_output_dir}"
      RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${_tutorial_output_dir}")
endfunction()

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
  605_HarmonicFields)

# Tutorial 701 depended on the removed IntrinsicFaceTangentBundle,
# polycurl_reduction, and SHM subdivision implementation. Replacing that
# algorithm with simple geometric subdivision would change the tutorial's
# mathematical claim, so it remains intentionally disabled.
set(DIRECTIONAL_NOOP_TUTORIALS
  701_SubdivisionFields)

if(DIRECTIONAL_TUTORIALS STREQUAL "ALL")
  set(DIRECTIONAL_SELECTED_TUTORIALS ${DIRECTIONAL_ALL_TUTORIALS})
else()
  string(REPLACE "," ";" DIRECTIONAL_TUTORIAL_REQUESTS
                 "${DIRECTIONAL_TUTORIALS}")
  set(DIRECTIONAL_SELECTED_TUTORIALS)

  foreach(request IN LISTS DIRECTIONAL_TUTORIAL_REQUESTS)
    set(resolved "")
    set(noop_match "")

    list(FIND DIRECTIONAL_NOOP_TUTORIALS "${request}" noop_index)
    if(NOT noop_index EQUAL -1)
      set(noop_match "${request}")
    elseif(request MATCHES "^[0-9]+$")
      foreach(candidate IN LISTS DIRECTIONAL_NOOP_TUTORIALS)
        if(candidate MATCHES "^${request}_")
          set(noop_match "${candidate}")
        endif()
      endforeach()
    endif()

    if(noop_match)
      message(FATAL_ERROR
        "Tutorial '${noop_match}' is intentionally disabled. It requires the "
        "removed libigl-dependent directional subdivision stack; see "
        "701_SubdivisionFields/README.md.")
    endif()

    list(FIND DIRECTIONAL_ALL_TUTORIALS "${request}" exact_index)
    if(NOT exact_index EQUAL -1)
      set(resolved "${request}")
    elseif(request MATCHES "^[0-9]+$")
      foreach(candidate IN LISTS DIRECTIONAL_ALL_TUTORIALS)
        if(candidate MATCHES "^${request}_")
          if(resolved)
            message(FATAL_ERROR "Tutorial prefix '${request}' is ambiguous")
          endif()
          set(resolved "${candidate}")
        endif()
      endforeach()
    endif()

    if(NOT resolved)
      message(FATAL_ERROR "Unknown tutorial '${request}'")
    endif()

    list(APPEND DIRECTIONAL_SELECTED_TUTORIALS "${resolved}")
  endforeach()

  list(REMOVE_DUPLICATES DIRECTIONAL_SELECTED_TUTORIALS)
endif()

message(STATUS "Directional tutorials: ${DIRECTIONAL_SELECTED_TUTORIALS}")
message(STATUS "Disabled tutorials: ${DIRECTIONAL_NOOP_TUTORIALS}")
foreach(tutorial_dir IN LISTS DIRECTIONAL_SELECTED_TUTORIALS)
  add_subdirectory("${tutorial_dir}")
endforeach()
