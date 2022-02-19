#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "asplib::Core" for configuration "Release"
set_property(TARGET asplib::Core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(asplib::Core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/usr/lib/libasplib_Core.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS asplib::Core )
list(APPEND _IMPORT_CHECK_FILES_FOR_asplib::Core "/usr/lib/libasplib_Core.a" )

# Import target "asplib::Biquad" for configuration "Release"
set_property(TARGET asplib::Biquad APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(asplib::Biquad PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/usr/lib/libasplib_Biquad.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS asplib::Biquad )
list(APPEND _IMPORT_CHECK_FILES_FOR_asplib::Biquad "/usr/lib/libasplib_Biquad.a" )

# Import target "asplib::IIR" for configuration "Release"
set_property(TARGET asplib::IIR APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(asplib::IIR PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/usr/lib/libasplib_IIR.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS asplib::IIR )
list(APPEND _IMPORT_CHECK_FILES_FOR_asplib::IIR "/usr/lib/libasplib_IIR.a" )

# Import target "asplib::Logger" for configuration "Release"
set_property(TARGET asplib::Logger APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(asplib::Logger PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/usr/lib/libasplib_Logger.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS asplib::Logger )
list(APPEND _IMPORT_CHECK_FILES_FOR_asplib::Logger "/usr/lib/libasplib_Logger.a" )

# Import target "asplib::Signals" for configuration "Release"
set_property(TARGET asplib::Signals APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(asplib::Signals PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/usr/lib/libasplib_Signals.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS asplib::Signals )
list(APPEND _IMPORT_CHECK_FILES_FOR_asplib::Signals "/usr/lib/libasplib_Signals.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
