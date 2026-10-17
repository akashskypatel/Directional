# Exact weighted-perfect-matching dependency for the M4 A3 conformity solver.
# LEMON is distributed under the Boost Software License 1.0. The seqan mirror
# is pinned to an immutable commit and consumed header-only for matching/list
# graph templates; its bounded default integer weight type is not semantic
# authority because Directional supplies an exact EInt-backed weight map.
include(FetchContent)

set(
  DIRECTIONAL_LEMON_REVISION
  "813c63d4f1d603858d941ac6f04abbe57901996a"
  CACHE STRING "Pinned seqan/lemon revision used by exact A3 matching")

FetchContent_Declare(
  directional_lemon
  GIT_REPOSITORY https://github.com/seqan/lemon.git
  GIT_TAG ${DIRECTIONAL_LEMON_REVISION}
  GIT_SHALLOW FALSE)
FetchContent_GetProperties(directional_lemon)
if(NOT directional_lemon_POPULATED)
  if(POLICY CMP0169)
    cmake_policy(PUSH)
    cmake_policy(SET CMP0169 OLD)
  endif()
  FetchContent_Populate(directional_lemon)
  if(POLICY CMP0169)
    cmake_policy(POP)
  endif()
endif()
