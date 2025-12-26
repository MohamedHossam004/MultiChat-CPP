# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MeshWhatsApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MeshWhatsApp_autogen.dir\\ParseCache.txt"
  "MeshWhatsApp_autogen"
  )
endif()
