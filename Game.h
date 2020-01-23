#ifndef GAME_H
#define GAME_H

#include "Deck.h"

class Game
{
    Deck m_deck;
    int m_playerScore;
    int m_dealerScore;
    int m_playerWin;

    static char getPlayerChoice();

    void init();

    void gameCycle();

    void showResult();

    void final();

public:
    bool start();
};

#endif // GAME_H
