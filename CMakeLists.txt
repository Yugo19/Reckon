cmake_minimum_required(VERSION 3.5)

project(Reckons1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(QT_USE_QTSQL TRUE)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.3.1\\mingw_64")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
#  CACHE STRING "Vcpkg toolchain file")

find_package(Qt6 REQUIRED COMPONENTS Core Sql PrintSupport Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets  REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        interface.h
        interface.cpp
        interface.ui
        registry.h
        registry.cpp
        registry.ui
        sell.h
        sell.cpp
        sell.ui
        server.h
        server.cpp
        stock.h
        stock.cpp
        stock.ui
        validation.h
        validation.cpp
        validation.ui
        #cfsell.h
        #cfsell.cpp
        #.ui
        imprimer.h
        imprimer.cpp
        imprimer.ui
)

if(${QT_VERSION_MAJOR}GREATER_EQUAL6)
    qt_add_executable(Reckons1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Reckons1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Reckons1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Reckons1
            ${PROJECT_SOURCES}

        )
    endif()
endif()

include_directories(${QT_QTSQL_INCLUDE_DIR})
target_link_libraries(Reckons1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Reckons1 PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(Reckons1 PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(Reckons1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Reckons1)
endif()
