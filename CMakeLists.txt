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

        src/core/category.hpp
        src/core/unit.hpp
        src/core/registry.hpp
        src/core/converter.hpp
        src/core/service.hpp
        src/core/category.cpp
        src/core/unit.cpp
        src/core/converter.cpp
        src/core/service.cpp
        src/core/registry.cpp
        
        src/core/modules/length.cpp
        src/core/modules/mass.cpp
        src/core/modules/temperature.cpp
        src/core/modules/data.cpp
)

qt_add_resources(RESOURCES icons/icons.qrc)
target_sources(UnitConverter PRIVATE ${RESOURCES})

target_compile_features(UnitConverter PRIVATE cxx_std_23)

target_link_libraries(UnitConverter PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

if (MSVC)
  target_compile_options(UnitConverter PRIVATE /EHsc) # Exception Handler
endif()

#if(UNIX AND NOT APPLE)
#    target_link_libraries(SonicAtlasVisualizer PRIVATE pthread m dl)
#endif()