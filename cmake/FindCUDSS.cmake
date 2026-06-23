# Finds NVIDIA cuDSS and defines CUDSS::cudss.
#
# Supported layouts include:
#   <root>/include/cudss.h
#   <root>/lib/<CUDA major>/cudss.lib
#   <root>/bin/<CUDA major>/cudss64_0.dll
#
# On Windows, versioned default installations under
#   C:/Program Files/NVIDIA cuDSS/v*
# are discovered automatically. An explicit CUDSS_ROOT always takes priority.
#
# Result variables:
#   CUDSS_FOUND
#   CUDSS_ROOT_DIR
#   CUDSS_INCLUDE_DIR
#   CUDSS_LIBRARY
#   CUDSS_RUNTIME_LIBRARY
#   CUDSS_VERSION

include(FindPackageHandleStandardArgs)

find_package(CUDAToolkit QUIET)

set(_CUDSS_EXPLICIT_ROOTS)
foreach(_variable IN ITEMS CUDSS_ROOT CUDSS_DIR)
  if(DEFINED ${_variable} AND NOT "${${_variable}}" STREQUAL "")
    list(APPEND _CUDSS_EXPLICIT_ROOTS "${${_variable}}")
  endif()
  if(DEFINED ENV{${_variable}} AND NOT "$ENV{${_variable}}" STREQUAL "")
    list(APPEND _CUDSS_EXPLICIT_ROOTS "$ENV{${_variable}}")
  endif()
endforeach()

set(_CUDSS_DEFAULT_ROOTS)
if(WIN32)
  set(_cudss_program_files_roots)
  foreach(_program_files_variable IN ITEMS ProgramFiles PROGRAMFILES)
    if(DEFINED ENV{${_program_files_variable}} AND
       NOT "$ENV{${_program_files_variable}}" STREQUAL "")
      list(APPEND _cudss_program_files_roots
           "$ENV{${_program_files_variable}}/NVIDIA cuDSS")
    endif()
  endforeach()

  # CMake environments do not always preserve the same ProgramFiles spelling.
  list(APPEND _cudss_program_files_roots "C:/Program Files/NVIDIA cuDSS")
  list(REMOVE_DUPLICATES _cudss_program_files_roots)

  foreach(_base IN LISTS _cudss_program_files_roots)
    if(IS_DIRECTORY "${_base}")
      file(GLOB _versioned_roots LIST_DIRECTORIES true "${_base}/v*")
      if(_versioned_roots)
        # Prefer the newest installed cuDSS version.
        list(SORT _versioned_roots COMPARE NATURAL ORDER DESCENDING)
        list(APPEND _CUDSS_DEFAULT_ROOTS ${_versioned_roots})
      endif()
    endif()
  endforeach()
endif()

# Explicit roots are searched first, followed by dynamically discovered roots.
set(_CUDSS_ROOT_HINTS ${_CUDSS_EXPLICIT_ROOTS} ${_CUDSS_DEFAULT_ROOTS})
list(REMOVE_DUPLICATES _CUDSS_ROOT_HINTS)

set(_CUDSS_CUDA_MAJORS)
if(DEFINED CUDAToolkit_VERSION_MAJOR AND
   NOT "${CUDAToolkit_VERSION_MAJOR}" STREQUAL "")
  list(APPEND _CUDSS_CUDA_MAJORS "${CUDAToolkit_VERSION_MAJOR}")
endif()

# Allow discovery even when CUDAToolkit was not found yet. Newer supported
# CUDA majors are preferred, while unversioned layouts remain a fallback.
list(APPEND _CUDSS_CUDA_MAJORS 13 12)
list(REMOVE_DUPLICATES _CUDSS_CUDA_MAJORS)

set(_CUDSS_LIBRARY_SUFFIXES)
set(_CUDSS_RUNTIME_SUFFIXES)
foreach(_cuda_major IN LISTS _CUDSS_CUDA_MAJORS)
  list(APPEND _CUDSS_LIBRARY_SUFFIXES
       "lib/${_cuda_major}"
       "lib64/${_cuda_major}")
  list(APPEND _CUDSS_RUNTIME_SUFFIXES "bin/${_cuda_major}")
endforeach()
list(APPEND _CUDSS_LIBRARY_SUFFIXES lib lib64 lib/x64)
list(APPEND _CUDSS_RUNTIME_SUFFIXES bin)

find_path(
  CUDSS_INCLUDE_DIR
  NAMES cudss.h
  HINTS ${_CUDSS_ROOT_HINTS}
  PATH_SUFFIXES include)

find_library(
  CUDSS_LIBRARY
  NAMES cudss
  HINTS ${_CUDSS_ROOT_HINTS}
  PATH_SUFFIXES ${_CUDSS_LIBRARY_SUFFIXES})

if(WIN32)
  find_file(
    CUDSS_RUNTIME_LIBRARY
    NAMES cudss64_0.dll
    HINTS ${_CUDSS_ROOT_HINTS}
    PATH_SUFFIXES ${_CUDSS_RUNTIME_SUFFIXES})
endif()

# Derive the selected installation root and version from the include path.
if(CUDSS_INCLUDE_DIR)
  get_filename_component(CUDSS_ROOT_DIR "${CUDSS_INCLUDE_DIR}" DIRECTORY)
  get_filename_component(_cudss_root_name "${CUDSS_ROOT_DIR}" NAME)
  if(_cudss_root_name MATCHES "^v(.+)$")
    set(CUDSS_VERSION "${CMAKE_MATCH_1}")
  endif()
endif()

find_package_handle_standard_args(
  CUDSS
  REQUIRED_VARS CUDSS_INCLUDE_DIR CUDSS_LIBRARY
  VERSION_VAR CUDSS_VERSION)

if(CUDSS_FOUND AND NOT TARGET CUDSS::cudss)
  add_library(CUDSS::cudss SHARED IMPORTED)
  if(EXISTS "${CUDSS_INCLUDE_DIR}")
    set_target_properties(
      CUDSS::cudss
      PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CUDSS_INCLUDE_DIR}")
    message(STATUS "NVIDIA cuDSS include directory: ${CUDSS_INCLUDE_DIR}")
  else()
    message(FATAL_ERROR "CUDSS_INCLUDE_DIR not found at expected location: ${CUDSS_INCLUDE_DIR}")
  endif()

  if(WIN32)
    # CUDSS_LIBRARY is the import library. Supplying the DLL location lets
    # CMake runtime dependency handling and install rules locate the binary.
    if(EXISTS "${CUDSS_LIBRARY}")
      set_target_properties(
        CUDSS::cudss
        PROPERTIES
          IMPORTED_IMPLIB "${CUDSS_LIBRARY}")
      message(STATUS "NVIDIA cuDSS link library: ${CUDSS_LIBRARY}")
    else()
      message(FATAL_ERROR "CUDSS_LIBRARY not found at expected location: ${CUDSS_LIBRARY}")
    endif()
    if(CUDSS_RUNTIME_LIBRARY)
      set_target_properties(
        CUDSS::cudss
        PROPERTIES
          IMPORTED_LOCATION "${CUDSS_RUNTIME_LIBRARY}")
      message(STATUS "NVIDIA cuDSS runtime library: ${CUDSS_RUNTIME_LIBRARY}")
    else()
      message(FATAL_ERROR "CUDSS_RUNTIME_LIBRARY not found at expected location: ${CUDSS_RUNTIME_LIBRARY}")
    endif()
  else()
    set_target_properties(
      CUDSS::cudss
      PROPERTIES
        IMPORTED_LOCATION "${CUDSS_LIBRARY}")
    message(STATUS "NVIDIA cuDSS link library: ${CUDSS_LIBRARY}")
  endif()

  if(TARGET CUDA::cudart)
    target_link_libraries(CUDSS::cudss INTERFACE CUDA::cudart)
  endif()
  if(TARGET CUDA::cublas)
    target_link_libraries(CUDSS::cudss INTERFACE CUDA::cublas)
  endif()
endif()

mark_as_advanced(
  CUDSS_ROOT_DIR
  CUDSS_INCLUDE_DIR
  CUDSS_LIBRARY
  CUDSS_RUNTIME_LIBRARY)
