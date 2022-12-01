# Script that sets the COMPILER_TYPE variable according to the current variable
#
# Possible values:
# "msvc" (windows-only)
# "gcc" (linux, mingw not supported yet)


if (CMAKE_COMPILER_IS_GNUCC)
  set(COMPILER_TYPE "gcc")
  ## Add the flags for the compilation ##
  add_compile_options(
    "-Wall" "-Wextra" "-Werror"
  )

  ## TESTING ##
  option(TESTING OFF)
  if (TESTING)
    enable_testing()
    add_compile_options("-lcriterion --coverage" "-fprofile-arcs" "-ftest-coverage")
    add_link_options("-lcriterion" "--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_subdirectory(tests)
  endif()
elseif (MSVC)
  set(COMPILER_TYPE "msvc")
else ()
  set(COMPILER_TYPE "unknown")
  message(WARNING "Unknown compiler type, compilation may not work as expected")
endif()
