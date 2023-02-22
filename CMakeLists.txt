cmake_minimum_required(VERSION 3.24)
project(X_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(X_0 src/main.cpp src/Game.h src/Game.cpp src/UI.cpp src/UI.h src/UI.h)

include_directories(headers SFML/include)

set(SFML_ROOT libraries/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(X_0 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

