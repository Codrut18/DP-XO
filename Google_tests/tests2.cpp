#include <gtest/gtest.h>
#include "../Logic/Headers/IGame.h"

TEST(ExampleTest2, Add) {
    EXPECT_EQ(2+2, 4);
    IGame *game = IGame::Produce('X','0');

    bool res = game->isGameActive();
    EXPECT_TRUE(res);
}

TEST(GameTest, PlayerTurnInConstructor) {
    IGame *game = IGame::Produce('X','0');
    EXPECT_TRUE(game->isPlayerTurn());
}

TEST(GameTest, ComputerTurnInConstructor) {
    IGame *game = IGame::Produce('X','0');
    EXPECT_FALSE(game->isPlayerTurn());
}

TEST(GameTest, PlayerMakeValidMove) {
    IGame* game = IGame::Produce('X','0');
    game->start();
    game->getPlayer()->makeMove(game->getBoard(), 0, 0);
    EXPECT_EQ(game->getBoard().getSign(0, 0), 'X');
}

TEST(GameTest, GameEndsInDraw) {
    IGame *game = IGame::Produce('X','0');
    game->start();
    std::vector<std::vector<int>> board = game->getBoard();
    game->getPlayer()->makeMove(0, 0, board);
    game->getComputer()->makeMove(board);
    game->getPlayer()->makeMove(1, 1, board);
    game->getComputer()->makeMove(board);
    game->getPlayer()->makeMove(1, 0, board);
    game->getComputer()->makeMove(board);
    game->getPlayer()->makeMove(0, 2, board);
    game->getComputer()->makeMove(board);
    game->getPlayer()->makeMove(2, 1, board);
    game->getComputer()->makeMove(board);
    game->getPlayer()->makeMove(2, 0, board);
    int winner = game->checkWinner(board);
    EXPECT_EQ(winner, 2);
}

TEST(GameTest, PlayerWinsGame) {
    IGame *game = IGame::Produce('X','0');
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
    IGame *game = IGame::Produce('X','0');
    game.start();
    game.getPlayer()->setMove(0, 0);
    EXPECT_EQ(game.getBoard()->getSign(0, 0), 1);
}

TEST(GameTest, testComputerMove) {
    IGame *game = IGame::Produce('X','0');
    game.start();
    game.getComputer()->makeMove(game.getBoard());
    EXPECT_EQ(game.getBoard()->countMarks(), 1);
}

TEST(GameTest, testPlayerWin) {
    IGame *game = IGame::Produce('X','0');
    game.start();
    game.getBoard()->setSign(0, 0, 1);
    game.getBoard()->setSign(0, 1, 1);
    game.getBoard()->setSign(0, 2, 1);
    EXPECT_EQ(game.checkWinner(), 1);
}

TEST(GameTest, testComputerWin) {
    IGame *game = IGame::Produce('X','0');
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