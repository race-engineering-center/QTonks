cmake_minimum_required(VERSION 3.5)

project(QTonks VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

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
        parameters/qtonks_group.h
        parameters/qtonks_group.cpp
)

qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(QTonks PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(QTonks PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTonks)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    .
    parameters
)
