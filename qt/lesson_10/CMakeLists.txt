cmake_minimum_required(VERSION 3.16)

project(dz_10_1 VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(QT NAMES Qt5 Qt6 CONFIG REQUIRED COMPONENTS Core Test QuickTest)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test QuickTest)

set(CMAKE_AUTOMOC TRUE)
set(CMAKE_AUTORCC TRUE)

qt_add_executable(appdz_10_1
    main.cpp
    task.h
    task.cpp
)

qt_add_qml_module(appdz_10_1
    URI dz_10_1
    VERSION 1.0
    QML_FILES
        main.qml
        MyWindow.qml
        MyBut.qml

)

set_target_properties(appdz_10_1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appdz_10_1
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(appdz_10_1 PRIVATE Qt6::Quick)
#target_link_libraries(appdz_10_1 PRIVATE Qt6::Quick TestLibs)

add_library(TestLibs SHARED task.h task.cpp)
target_link_libraries(TestLibs Qt6::Quick)

#add_library(TestQMLLibs SHARED MyBut.qml)
#target_link_libraries(TestQMLLibs Qt6::QuickTest)

add_subdirectory(Tests)
