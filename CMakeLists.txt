cmake_minimum_required(VERSION 3.10)
project(hellocpp)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


add_executable(
    ${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/mainwindow.cpp
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE  Qt6::Widgets
)