cmake_minimum_required(VERSION 3.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core    REQUIRED)
include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
)

qt5_add_resources(ColdSpider_RESOURCES
    src/resources.qrc
)

qt5_wrap_ui(ColdSpider_UIs 
    src/idle.ui
    src/work.ui
)

find_package(STATEBUILDERCPP REQUIRED)
include(UseStateBuilderCpp)

statebuildercpp_compile(ColdSpider_Fsm 
    src/ColdSpider.fsmcpp
)

set(ColdSpider_SOURCES
    src/main.cpp
    src/WorkWindow.cpp
    src/IdleWindow.cpp
    src/Login.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_definitions(-fPIC -std=c++11)
add_executable(Cold-Spider 
    ${ColdSpider_SOURCES} 
    ${ColdSpider_RESOURCES} 
    ${ColdSpider_UIs} 
    ${ColdSpider_Fsm}
)
target_link_libraries(Cold-Spider 
    Qt5::Core 
    Qt5::Widgets
)