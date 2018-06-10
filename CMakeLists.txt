#Remeber to set the CMAKE_PREFIX_PATH as an environment variable
cmake_minimum_required(VERSION 3.7)
project(pong)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

set(SOURCES
   src/Main.cpp
   src/Ball.cpp
   src/Ball.h
   src/GameManager.cpp
   src/GameManager.h
   src/GameObject.cpp
   src/GameObject.h
   src/Globals.h
   src/Module.h
   src/ModuleEntityManager.cpp
   src/ModuleEntityManager.h
   src/ModuleGUI.cpp
   src/ModuleGUI.h
   src/ModuleInput.cpp
   src/ModuleInput.h
   src/ModuleRender.cpp
   src/ModuleRender.h
   src/ModuleScene.cpp
   src/ModuleScene.h
   src/ModuleWindow.cpp
   src/ModuleWindow.h
   src/Paddle.cpp
   src/Paddle.h
   src/Random.h
   src/Vector2D.h
   src/Vector2D.inl
)

add_executable(pong ${SOURCES})

target_include_directories(pong PUBLIC ${SDL2_INCLUDE_DIRS} PUBLIC ${SDL2_TTF_INCLUDE_DIRS} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
#target_include_directories(pong PUBLIC ${SDL2_INCLUDE_DIRS} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(pong PUBLIC ${SDL2_LIBRARIES} PUBLIC ${SDL2_TTF_LIBRARIES})

#include_directories(src ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
#link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_TTF_LIBRARY_DIRS})
