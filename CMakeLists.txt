cmake_minimum_required(VERSION 3.20)

project(lunar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LUNAR_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(LUNAR_BINARY_ROOT ${CMAKE_CURRENT_BINARY_DIR})

# Sources
add_subdirectory(engine)
add_subdirectory(vendor)

# Tests
#set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1) # will hide generated CTest targets
include(CTest) # required for automatic test registration (Test Explorer VS22), at root level
add_subdirectory(tests)