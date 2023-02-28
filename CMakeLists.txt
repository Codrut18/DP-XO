cmake_minimum_required(VERSION 3.24)
project(X_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Logic Logic/main.cpp Logic/Headers/Game.h Logic/Sources/Game.cpp Logic/Headers/Player.h Logic/Sources/Player.cpp Logic/Headers/Computer.h Logic/Sources/Computer.cpp Logic/Headers/Board.h Logic/Sources/Board.cpp)
add_executable(UI UI/main.cpp)
add_executable(Console Console/main.cpp Console/main.cpp)

include_directories(headers /libraries/SFML UI/assets/fonts)

set(SFML_ROOT libraries/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(UI ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY UI/assets DESTINATION ${CMAKE_BINARY_DIR})

