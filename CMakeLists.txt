# Remeber to set the CMAKE_PREFIX_PATH as an environment variable for Windows
cmake_minimum_required(VERSION 3.7)
project(pong)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_executable(pong "")
include(src/CMakeLists.txt)

target_include_directories(pong PUBLIC ${SDL2_INCLUDE_DIRS} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(pong PUBLIC ${SDL2_LIBRARIES} PUBLIC ${SDL2_TTF_LIBRARIES})
