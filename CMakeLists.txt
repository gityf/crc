if(DEFINED CRC_LIBRARY)
  return()
else()
  set(CRC_LIBRARY 1)
endif()

project(crc)

if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()

cmake_minimum_required(VERSION 3.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_SHARED_LIBS "Enable or disable shared libraries" OFF)

file(GLOB SOURCE_CPP
    "crc/*.h"
    "crc/*.cpp"
    "crc/*.c"
)

add_library(${PROJECT_NAME} ${SOURCE_CPP})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
