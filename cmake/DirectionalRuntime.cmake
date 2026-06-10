function(_directional_find_file out_var)
  set(options)
  set(one_value_args)
  set(multi_value_args PATTERNS DIRECTORIES)
  cmake_parse_arguments(ARG "${options}" "${one_value_args}"
                        "${multi_value_args}" ${ARGN})

  set(_matches)

  foreach(_dir IN LISTS ARG_DIRECTORIES)
    if(NOT IS_DIRECTORY "${_dir}")
      continue()
    endif()

    foreach(_pattern IN LISTS ARG_PATTERNS)
      file(
        GLOB_RECURSE _found
        LIST_DIRECTORIES FALSE
        "${_dir}/${_pattern}")
      list(APPEND _matches ${_found})
    endforeach()
  endforeach()

  list(REMOVE_DUPLICATES _matches)
  list(LENGTH _matches _count)

  if(_count EQUAL 0)
    set(${out_var}
        "${out_var}-NOTFOUND"
        PARENT_SCOPE)
    message(
      WARNING
        "No matching file matching patterns ${ARG_PATTERNS}\nfound in directories: ${ARG_DIRECTORIES}"
    )
  elseif(_count EQUAL 1)
    list(GET _matches 0 _selected)
    set(${out_var}
        "${_selected}"
        PARENT_SCOPE)
  else()
    list(GET _matches 0 _selected)
    set(${out_var}
        "${_selected}"
        PARENT_SCOPE)
    message(DEBUG "Multiple files matched for patterns ${ARG_PATTERNS}:\n"
            "  ${_matches}\n" "Selecting the first one: ${_selected}")
  endif()
endfunction()

function(_directional_find_directory out_var)
  set(options)
  set(one_value_args)
  set(multi_value_args PATTERNS DIRECTORIES)
  cmake_parse_arguments(ARG "${options}" "${one_value_args}"
                        "${multi_value_args}" ${ARGN})

  set(_all_found_dirs "")
  set(_final_matches "")

  foreach(_dir IN LISTS ARG_DIRECTORIES)
    if(NOT IS_DIRECTORY "${_dir}")
      continue()
    endif()

    file(
      GLOB_RECURSE _current_scan
      LIST_DIRECTORIES TRUE
      "${_dir}/*")
    list(APPEND _all_found_dirs ${_current_scan})
  endforeach()

  foreach(_item IN LISTS _all_found_dirs)
    if(IS_DIRECTORY "${_item}")

      foreach(_pattern IN LISTS ARG_PATTERNS)
        string(REGEX REPLACE "([.+?^$\(\)\[\]{}|\\-])" "\\\\\\1" _safe_pattern
                             "${_pattern}")
        string(REGEX REPLACE "\\*" "[^/]*" _regex_pattern "${_safe_pattern}")
        if(_item MATCHES "/${_regex_pattern}$")
          list(APPEND _final_matches "${_item}")
          break()
        endif()
      endforeach()

    endif()
  endforeach()

  list(REMOVE_DUPLICATES _final_matches)
  list(LENGTH _final_matches _count)

  if(_count EQUAL 0)
    set(${out_var}
        "${out_var}-NOTFOUND"
        PARENT_SCOPE)
    message(
      WARNING
        "No directory matching patterns ${ARG_PATTERNS}\nfound in directories: ${ARG_DIRECTORIES}"
    )
  else()
    list(GET _final_matches 0 _selected)
    set(${out_var}
        "${_selected}"
        PARENT_SCOPE)

    if(_count GREATER 1)
      message(DEBUG "Multiple directories matched for ${out_var}:\n"
              "  ${_final_matches}\n" "Selecting the first one: ${_selected}")
    endif()
  endif()
endfunction()
