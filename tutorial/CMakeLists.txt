cmake_minimum_required(VERSION 3.20)
project(Directional_tutorials)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Optional: use -std=c++20 instead of -std=gnu++20

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()

option(DIRECTIONAL_VIEWER "Directional Viewer" ON)
option(USE_GMP "Enable GMP support if found" ON)
set(DIRECTIONAL_TUTORIALS "ALL" CACHE STRING "Semicolon-separated tutorial directories to build, or ALL")

message(STATUS "CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")

set(DIRECTIONAL_ROOT "${CMAKE_CURRENT_LIST_DIR}/../")
set(DIRECTIONAL_SOURCE_DIR "${DIRECTIONAL_ROOT}/include")
set(DIRECTIONAL_EXTERNAL "${DIRECTIONAL_ROOT}/external")

message(STATUS "DIRECTIONAL_ROOT: ${DIRECTIONAL_ROOT}")

include_directories(${DIRECTIONAL_SOURCE_DIR})
include_directories(${DIRECTIONAL_EXTERNAL}/eigen)

# Polyscope
add_subdirectory(${DIRECTIONAL_EXTERNAL}/polyscope "polyscope")

# Tutorial data path and output path (create dirs if needed)
set(TUTORIAL_DATA_PATH "${CMAKE_CURRENT_SOURCE_DIR}/data" CACHE PATH "location of tutorial data resources")
set(TUTORIAL_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/output" CACHE PATH "location of tutorial outputs")

file(MAKE_DIRECTORY "${TUTORIAL_DATA_PATH}")
file(MAKE_DIRECTORY "${TUTORIAL_OUTPUT_PATH}")

# Set runtime output dir and create
function(directional_finalize_tutorial_target target_name)
  set(_tutorial_output_dir "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/$<CONFIG>")
  set_target_properties(${target_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${_tutorial_output_dir}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/RelWithDebInfo"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/MinSizeRel"
  )

  if(WIN32 AND DIRECTIONAL_GMP_RUNTIME_FILES)
    add_custom_command(
      TARGET ${target_name}
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${target_name}>"
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DIRECTIONAL_GMP_RUNTIME_FILES}
        "$<TARGET_FILE_DIR:${target_name}>"
      VERBATIM
    )
  endif()
endfunction()

# Interface library for tutorial targets
add_library(tutorials INTERFACE)

target_compile_definitions(tutorials INTERFACE
  TUTORIAL_DATA_PATH=\"${TUTORIAL_DATA_PATH}\"
  TUTORIAL_OUTPUT_PATH=\"${TUTORIAL_OUTPUT_PATH}\"
  GLM_ENABLE_EXPERIMENTAL
)


target_include_directories(tutorials INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${POLYSCOPE_SOURCE_DIR}/include
    ${POLYSCOPE_SOURCE_DIR}/deps/imgui/imgui
    ${POLYSCOPE_SOURCE_DIR}/deps/glm
)

# ===== GMP Handling (Cross-platform) =====
if(USE_GMP)
    message(STATUS "Attempting to find GMP...")

    find_path(GMP_INCLUDE_DIR
        NAMES gmp.h
        HINTS
            $ENV{GMP_DIR}/include
            ${CMAKE_PREFIX_PATH}/include
            /usr/include
            /usr/local/include
            "C:/Program Files/GMP/include"
    )

    find_library(GMP_LIBRARIES
        NAMES gmp libgmp
        HINTS
            $ENV{GMP_DIR}/lib
            ${CMAKE_PREFIX_PATH}/lib
            /usr/lib
            /usr/local/lib
            "C:/Program Files/GMP/lib"
    )

    if(GMP_INCLUDE_DIR AND GMP_LIBRARIES)
        message(STATUS "GMP found:")
        message(STATUS "  Include: ${GMP_INCLUDE_DIR}")
        message(STATUS "  Library: ${GMP_LIBRARIES}")
        add_compile_definitions(USE_GMP)
        include_directories(${GMP_INCLUDE_DIR})
        link_libraries(${GMP_LIBRARIES})
    else()
        message(WARNING "GMP not found. Disabling USE_GMP.")
        set(USE_GMP OFF CACHE BOOL "Enable GMP support if found" FORCE)
    endif()
endif()

if(USE_GMP)
    add_compile_definitions(USE_GMP_ENABLED)
endif()

if(DIRECTIONAL_ENABLE_CUDA AND CUDAToolkit_FOUND)
    add_compile_definitions(DIRECTIONAL_ENABLE_CUDA)
    target_link_libraries(tutorials INTERFACE CUDA::cudart CUDA::cusolver CUDA::cusparse)
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
  701_SubdivisionFields
)

if(DIRECTIONAL_TUTORIALS STREQUAL "ALL")
  set(DIRECTIONAL_SELECTED_TUTORIALS ${DIRECTIONAL_ALL_TUTORIALS})
else()
  string(REPLACE "," ";" DIRECTIONAL_TUTORIAL_REQUESTS "${DIRECTIONAL_TUTORIALS}")
  set(DIRECTIONAL_SELECTED_TUTORIALS)
  foreach(DIRECTIONAL_TUTORIAL_REQUEST IN LISTS DIRECTIONAL_TUTORIAL_REQUESTS)
    set(DIRECTIONAL_RESOLVED_TUTORIAL "")
    list(FIND DIRECTIONAL_ALL_TUTORIALS "${DIRECTIONAL_TUTORIAL_REQUEST}" DIRECTIONAL_TUTORIAL_INDEX)
    if(NOT DIRECTIONAL_TUTORIAL_INDEX EQUAL -1)
      set(DIRECTIONAL_RESOLVED_TUTORIAL "${DIRECTIONAL_TUTORIAL_REQUEST}")
    elseif(DIRECTIONAL_TUTORIAL_REQUEST MATCHES "^[0-9]+$")
      foreach(DIRECTIONAL_CANDIDATE IN LISTS DIRECTIONAL_ALL_TUTORIALS)
        if(DIRECTIONAL_CANDIDATE MATCHES "^${DIRECTIONAL_TUTORIAL_REQUEST}_")
          if(DIRECTIONAL_RESOLVED_TUTORIAL)
            message(FATAL_ERROR
              "Tutorial prefix '${DIRECTIONAL_TUTORIAL_REQUEST}' is ambiguous. "
              "Use one of the full names: ${DIRECTIONAL_ALL_TUTORIALS}"
            )
          endif()
          set(DIRECTIONAL_RESOLVED_TUTORIAL "${DIRECTIONAL_CANDIDATE}")
        endif()
      endforeach()
    endif()

    if(NOT DIRECTIONAL_RESOLVED_TUTORIAL)
      message(FATAL_ERROR
        "Unknown tutorial '${DIRECTIONAL_TUTORIAL_REQUEST}'. "
        "Use a numeric prefix like 501 or a full name from: ${DIRECTIONAL_ALL_TUTORIALS}"
      )
    endif()

    list(APPEND DIRECTIONAL_SELECTED_TUTORIALS "${DIRECTIONAL_RESOLVED_TUTORIAL}")
  endforeach()

  list(REMOVE_DUPLICATES DIRECTIONAL_SELECTED_TUTORIALS)
  if(NOT DIRECTIONAL_SELECTED_TUTORIALS)
    message(FATAL_ERROR "No tutorials selected.")
  endif()
endif()

message(STATUS "Directional tutorials selected: ${DIRECTIONAL_SELECTED_TUTORIALS}")

if(DIRECTIONAL_VIEWER)
  foreach(DIRECTIONAL_TUTORIAL_DIR IN LISTS DIRECTIONAL_SELECTED_TUTORIALS)
    add_subdirectory("${DIRECTIONAL_TUTORIAL_DIR}")
  endforeach()
endif()
