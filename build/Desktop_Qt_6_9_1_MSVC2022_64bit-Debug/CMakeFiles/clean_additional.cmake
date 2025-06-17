# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EasyReverse_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EasyReverse_autogen.dir\\ParseCache.txt"
  "EasyReverse_autogen"
  )
endif()
