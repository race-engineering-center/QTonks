cmake_minimum_required(VERSION 3.5)

project(QTonks VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        qtonks_widget.cpp
        qtonks_widget.h

        qtonks_parameter.h
        qtonks_parameterbuilder.h

        qtonks_parameterbuilderinjector.cpp
        qtonks_parameterbuilderinjector.h
        qtonks_parameterbuildermanager.cpp
        qtonks_parameterbuildermanager.h

        parameters/qtonks_switch.cpp
        parameters/qtonks_switch.h
        parameters/qtonks_enumeration.cpp
        parameters/qtonks_enumeration.h
        parameters/qtonks_integer.cpp
        parameters/qtonks_integer.h
        parameters/qtonks_group.h
        parameters/qtonks_group.cpp
)

qt_add_library(${PROJECT_NAME}
    STATIC
    ${PROJECT_SOURCES}
)

target_link_libraries(QTonks PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
    parameters
)
