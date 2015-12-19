cmake_minimum_required(VERSION 3.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core    REQUIRED)
include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
)

qt5_add_resources(COLD_SPIDER_RESOURCES
    src/resources.qrc
)

qt5_wrap_ui(COLD_SPIDER_UIS 
    src/idle.ui
    src/work.ui
)

find_package(STATEBUILDERCPP REQUIRED)
include(UseStateBuilderCpp)

statebuildercpp_compile(COLD_SPIDER_FSM src/ColdSpider.fsmcpp)

set(ColdSpider_SOURCES
    src/main.cpp
    
    src/WorkWindow.h
    src/WorkWindow.cpp
    
    src/IdleWindow.h
    src/IdleWindow.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_definitions(-fPIC -std=c++11)
add_executable(Cold-Spider ${ColdSpider_SOURCES} ${COLD_SPIDER_RESOURCES} ${COLD_SPIDER_UIS} ${COLD_SPIDER_FSM})
target_link_libraries(Cold-Spider 
    Qt5::Core 
    Qt5::Widgets
)