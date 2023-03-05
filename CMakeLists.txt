cmake_minimum_required(VERSION 3.17)
project(UI)

set(CMAKE_CXX_STANDARD 20)

#add_executable(Logic Logic/main.cpp Logic/Headers/Game.h Logic/Sources/Game.cpp Logic/Headers/Player.h Logic/Sources/Player.cpp Logic/Headers/Computer.h Logic/Sources/Computer.cpp Logic/Headers/Board.h Logic/Sources/Board.cpp)
add_executable(UI UI/main.cpp)
add_executable(Console Console/main.cpp Console/main.cpp)

add_library(LogicLib SHARED Logic/main.cpp Logic/Headers/Game.h Logic/Sources/Game.cpp Logic/Headers/Player.h Logic/Sources/Player.cpp Logic/Headers/Computer.h Logic/Sources/Computer.cpp Logic/Headers/Board.h Logic/Sources/Board.cpp)

target_include_directories(LogicLib PUBLIC Logic)

include_directories(Headers /SFML/include)

set(SFML_ROOT SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(UI ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} LogicLib)
endif()

file(COPY UI/assets DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(Google_tests)




