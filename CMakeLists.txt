cmake_minimum_required(VERSION 3.5)

project(QTonks VERSION 0.1 LANGUAGES CXX)

add_subdirectory(src)

option(QTONKS_BUILD_EXAMPLE "Build example app" On)
if(${QTONKS_BUILD_EXAMPLE})
    add_subdirectory(example)
endif()
