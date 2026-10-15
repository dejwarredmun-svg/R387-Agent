cmake_minimum_required(VERSION 3.21)
project(r387-agent CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Geode REQUIRED)

geode_include_directories()

add_geode_mod(r387-agent
    src/main.cpp
    src/EditorIntegration.cpp
    src/DecoratorUI.cpp
    src/ObjectPicker.cpp
    src/ImageProcessor.cpp
    src/ObjectGenerator.cpp
    src/Settings.cpp
)

target_link_libraries(r387-agent PRIVATE Geode::Geode)