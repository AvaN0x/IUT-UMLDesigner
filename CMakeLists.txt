cmake_minimum_required(VERSION 3.5)

project(UMLDesigner LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES UMLDesigner_en_150.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        exportclass.cpp
        exportclass.h
        exportclass.ui
        newclass.cpp
        newclass.h
        newclass.ui
        newmethod.cpp
        newmethod.h
        newmethod.ui
        newvar.cpp
        newvar.h
        newvar.ui
        models/Class.cpp
        models/Attribute.cpp
        models/Class.hpp
        models/Attribute.hpp
        models/List.hpp
        models/Queue.hpp
        models/Stack.hpp
        models/Base.cpp
        models/Base.hpp
        models/types.cpp
        models/types.h
        models/visibility.cpp
        models/visibility.h
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(UMLDesigner
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(UMLDesigner SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(UMLDesigner
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(UMLDesigner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
