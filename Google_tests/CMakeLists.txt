cmake_minimum_required(VERSION 3.21)
project(Google_tests)
add_subdirectory(googletest)
include_directories(googletest/include ../February)

set (SOURCE_FILES
        compare-version-test.cpp
        ../February/compare-version.cpp
        ../February/sortlist.cpp
        )

add_executable(google_tests ${SOURCE_FILES})

target_link_libraries(google_tests PRIVATE gtest gtest_main)