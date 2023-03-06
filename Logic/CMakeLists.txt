
add_library(LogicLib STATIC main.cpp Headers/Game.h Sources/Game.cpp Headers/Player.h Sources/Player.cpp Headers/Computer.h Sources/Computer.cpp Headers/Board.h Sources/Board.cpp)

target_include_directories(LogicLib PUBLIC Headers)
