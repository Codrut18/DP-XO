#include <iostream>
#include "../Logic/Headers/Game.h"

int main(){
    Game game('X','O');

    std::cout<<game.isGameActive();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}