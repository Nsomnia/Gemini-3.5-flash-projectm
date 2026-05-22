# File: cmake/CPM.cmake

# CPM.cmake - CMake Package Manager
# Copyright (c) 2019-2023 Lars Melchior and contributors
# GPL-3.0 License or MIT License

set(CPM_DOWNLOAD_VERSION 0.38.3)

if(CPM_DIRECTORY)
  # CPM.cmake found in another directory
  return()
endif()

set(CPM_DIRECTORY "${CMAKE_BINARY_DIR}/cpm-packages" CACHE PATH "Directory to store CPM packages")

if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
  set(CPM_DOWNLOAD_LOCATION "${CMAKE_CURRENT_LIST_DIR}/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
  message(STATUS "Downloading CPM.cmake version ${CPM_DOWNLOAD_VERSION} to ${CPM_DOWNLOAD_LOCATION}...")
  file(DOWNLOAD
       "https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake"
       "${CPM_DOWNLOAD_LOCATION}"
       STATUS download_status
  )
  list(GET download_status 0 error_code)
  if(NOT error_code EQUAL 0)
    message(FATAL_ERROR "CPM.cmake download failed with error: ${download_status}")
  endif()
endif()

include("${CMAKE_CURRENT_LIST_DIR}/CPM_${CPM_DOWNLOAD_VERSION}.cmake")