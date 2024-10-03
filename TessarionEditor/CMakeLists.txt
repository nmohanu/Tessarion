cmake_minimum_required(VERSION 3.21)

project(tessarion)

find_package(SDL2 REQUIRED)

set(IMGUI_PATH  "./imgui/")
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH})

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main main.cpp)

target_link_libraries(main PUBLIC ${SDL2_LIBRARIES} ImGui)
