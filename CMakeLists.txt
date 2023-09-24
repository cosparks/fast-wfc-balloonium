cmake_minimum_required(VERSION 3.9)
project(fastwfc VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/lib/wave.cpp src/lib/propagator.cpp src/lib/wfc.cpp)

add_library(${PROJECT_NAME}_static STATIC ${SOURCE_FILES})
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/lib CACHE PATH "Build directory" FORCE)

target_include_directories(${PROJECT_NAME}_static PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>)

set_target_properties(${PROJECT_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1)

export(TARGETS ${PROJECT_NAME} FILE FastWFCConfig.cmake)
export(TARGETS ${PROJECT_NAME}_static FILE FastWFCStaticConfig.cmake)
