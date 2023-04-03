#include <gtest/gtest.h>
#include "../Logic/Headers/Game.h"

TEST(ExampleTest2, Add) {
    EXPECT_EQ(2+2, 4);
    Game *game;
    game = new Game();

    bool res = game->isGameActive();
    EXPECT_TRUE(res);
}

TEST(GameTest, PlayerTurnInConstructor) {
    Game game('X', 'O');
    EXPECT_TRUE(game.isPlayerTurn());
}

TEST(GameTest, ComputerTurnInConstructor) {
    Game game('O', 'X');
    EXPECT_FALSE(game.isPlayerTurn());
}

TEST(GameTest, PlayerMakeValidMove) {
    Game game('X', 'O');
    game.start();
    game.getPlayer()->makeMove(game.getBoard(), 0, 0);
    EXPECT_EQ(game.getBoard()->getSign(0, 0), 'X');
}

TEST(GameTest, ComputerMakeValidMove) {
    Game game('O', 'X');
    game.start();
    game.getComputer()->makeMove(game.getBoard());
    EXPECT_TRUE(game.getBoard()->isCellOccupied());
}
TEST(GameTest, GameEndsInDraw) {
    Game game('X', 'O');
    game.start();
    game.getPlayer()->makeMove(game.getBoard(), 0, 0);
    game.getComputer()->makeMove(game.getBoard());
    game.getPlayer()->makeMove(game.getBoard(), 1, 1);
    game.getComputer()->makeMove(game.getBoard());
    game.getPlayer()->makeMove(game.getBoard(), 1, 0);
    game.getComputer()->makeMove(game.getBoard());
    game.getPlayer()->makeMove(game.getBoard(), 0, 2);
    game.getComputer()->makeMove(game.getBoard());
    game.getPlayer()->makeMove(game.getBoard(), 2, 1);
    game.getComputer()->makeMove(game.getBoard());
    game.getPlayer()->makeMove(game.getBoard(), 2, 0);
    int winner = game.checkWinner();
    EXPECT_EQ(winner, 2);
}

TEST(GameTest, PlayerWinsGame) {
    Game game('X', 'O');
    game.start();
    game.getPlayer()->makeMove(game.getBoard(), 0, 0);
    game.getComputer()->makeMove(game.getBoard());
    game.getPlayer()->makeMove(game.getBoard(), 1, 1);
    game.getComputer()->makeMove(game.getBoard());
    game.getPlayer()->makeMove(game.getBoard(), 2, 2);
    int winner = game.checkWinner();
    EXPECT_EQ(winner, 1);
}

TEST(GameTest, testPlayerMove) {
    Game game('X', 'O');
    game.start();
    game.getPlayer()->setMove(0, 0);
    EXPECT_EQ(game.getBoard()->getSign(0, 0), 1);
}

TEST(GameTest, testComputerMove) {
    Game game('X', 'O');
    game.start();
    game.getComputer()->makeMove(game.getBoard());
    EXPECT_EQ(game.getBoard()->countMarks(), 1);
}

TEST(GameTest, testPlayerWin) {
    Game game('X', 'O');
    game.start();
    game.getBoard()->setSign(0, 0, 1);
    game.getBoard()->setSign(0, 1, 1);
    game.getBoard()->setSign(0, 2, 1);
    EXPECT_EQ(game.checkWinner(), 1);
}

TEST(GameTest, testComputerWin) {
    Game game('X', 'O');
    game.start();
    game.getBoard()->setSign(0, 0, 0);
    game.getBoard()->setSign(0, 1, 0);
    game.getBoard()->setSign(0, 2, 0);
    game.getComputer()->makeMove(game.getBoard());
    EXPECT_EQ(game.checkWinner(), 0);
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