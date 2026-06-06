cmake_minimum_required(VERSION 3.22...4.3)
project(UnitConverter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(UnitConverter
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.hpp
        src/mainwindow.ui
)

target_compile_features(UnitConverter PRIVATE cxx_std_23)

target_link_libraries(UnitConverter PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

#if(UNIX AND NOT APPLE)
#    target_link_libraries(SonicAtlasVisualizer PRIVATE pthread m dl)
#endif()