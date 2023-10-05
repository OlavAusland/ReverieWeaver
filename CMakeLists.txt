cmake_minimum_required(VERSION 3.8)
project(ReverieWeaver)

set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/vendors")
set(IMGUI_PATH "${PROJECT_SOURCE_DIR}/vendors/imgui")

file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/components/*.cpp")
file(GLOB ENGINE_SRC_FILES "${PROJECT_SOURCE_DIR}/engine/src/*.cpp")
file(GLOB IMGUI_SRC "${PROJECT_SOURCE_DIR}/vendors/imgui/*.cpp")



find_package(SDL2 REQUIRED)

include_directories(${CMAKE_PROJECT_NAME} 
					"${PROJECT_SOURCE_DIR}/include"
					"${PROJECT_SOURCE_DIR}/engine/include"
					${IMGUI_PATH})

add_executable(${CMAKE_PROJECT_NAME} 
				main.cpp 
				${SRC_FILES} 
				${IMGUI_SRC}
				${ENGINE_SRC_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)