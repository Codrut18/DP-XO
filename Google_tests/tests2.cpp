#include <gtest/gtest.h>
#include "../Logic/Headers/Game.h"

TEST(ExampleTest2, Add) {
    EXPECT_EQ(2+2, 4);
    Game *game;
    game = new Game();

    bool res = game->isGameActive();
    EXPECT_TRUE(res);
}

//TEST(GameTest, SwitchTurns) {
//    Game *game;
//    game = new Game('X','0');
//    game->start();
//    EXPECT_TRUE(game->isPlayerTurn()); // Player goes first
//    game->setIsPlayerTurn(false);
//    EXPECT_FALSE(game->isPlayerTurn()); // Now it's the computer's turn
//    game->setIsPlayerTurn(true);
//    EXPECT_TRUE(game->isPlayerTurn()); // And now it's the player's turn again
//}