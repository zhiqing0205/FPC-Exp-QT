# Minimal FFTW3 finder for CMake.
#
# Provides:
#   FFTW3_FOUND
#   FFTW3_INCLUDE_DIR
#   FFTW3_LIBRARY
#   FFTW3::fftw3 target

set(_FFTW3_HINTS "")
if(DEFINED FFTW3_ROOT)
  list(APPEND _FFTW3_HINTS "${FFTW3_ROOT}")
endif()
if(DEFINED ENV{FFTW3_ROOT})
  list(APPEND _FFTW3_HINTS "$ENV{FFTW3_ROOT}")
endif()
if(DEFINED ENV{FFTW_ROOT})
  list(APPEND _FFTW3_HINTS "$ENV{FFTW_ROOT}")
endif()

find_path(FFTW3_INCLUDE_DIR NAMES fftw3.h
  HINTS ${_FFTW3_HINTS}
  PATH_SUFFIXES include
)

find_library(FFTW3_LIBRARY
  NAMES
    fftw3
    fftw3-3
    libfftw3-3
  HINTS ${_FFTW3_HINTS}
  PATH_SUFFIXES lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FFTW3 DEFAULT_MSG FFTW3_LIBRARY FFTW3_INCLUDE_DIR)

if(FFTW3_FOUND AND NOT TARGET FFTW3::fftw3)
  add_library(FFTW3::fftw3 UNKNOWN IMPORTED)
  set_target_properties(FFTW3::fftw3 PROPERTIES
    IMPORTED_LOCATION "${FFTW3_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${FFTW3_INCLUDE_DIR}"
  )
endif()
