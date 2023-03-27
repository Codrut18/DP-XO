//
// Created by Iusaq on 3/27/2023.
//

#ifndef UI_IGAMELISTENER_H
#define UI_IGAMELISTENER_H


#endif //UI_IGAMELISTENER_H


/**
 * @brief Interface for a game listener.
 *
 * This class defines an interface for a game listener. It provides methods that are called by the game class at different points during gameplay.
 */
class IGameListener {
public:
    virtual ~IGameListener() {}

    /**
     * @brief Called when the game starts.
     *
     * This method is called by the game class when the game starts.
     */
    virtual void onGameStart() = 0;

    /**
     * @brief Called when the player makes a move.
     *
     * This method is called by the game class when the player makes a move.
     */
    virtual void onPlayerMoved() = 0;

    /**
     * @brief Called when the computer makes a move.
     *
     * This method is called by the game class when the computer makes a move.
     */
    virtual void onComputerMoved() = 0;

    /**
     * @brief Called when the game ends.
     *
     * This method is called by the game class when the game ends.
     *
     * @param winner The winner of the game: -1 if there's no winner yet, 0 if O wins, 1 if X wins, 2 if it's a draw.
     */
    virtual void onGameEnd(int winner) = 0;
};

