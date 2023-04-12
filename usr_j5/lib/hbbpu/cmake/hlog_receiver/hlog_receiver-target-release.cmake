#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "bole::hlog_receiver" for configuration "Release"
set_property(TARGET bole::hlog_receiver APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bole::hlog_receiver PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhlog_receiver.so.1.1.3"
  IMPORTED_SONAME_RELEASE "libhlog_receiver.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS bole::hlog_receiver )
list(APPEND _IMPORT_CHECK_FILES_FOR_bole::hlog_receiver "${_IMPORT_PREFIX}/lib/libhlog_receiver.so.1.1.3" )

# Import target "bole::hlog_receiver-static" for configuration "Release"
set_property(TARGET bole::hlog_receiver-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bole::hlog_receiver-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhlog_receiver.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS bole::hlog_receiver-static )
list(APPEND _IMPORT_CHECK_FILES_FOR_bole::hlog_receiver-static "${_IMPORT_PREFIX}/lib/libhlog_receiver.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
