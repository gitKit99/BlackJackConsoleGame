#include "Game.h"

#include <iostream>

char Game::getPlayerChoice()
{
    char choice;

    do
    {
      std::cout << "Make your choice. (h) for hit, (s) for stand\n";
      std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

void Game::init()
{
    m_playerScore = 0;
    m_dealerScore = 0;
    m_playerWin = true;

    m_deck.shuffleDeck();

    std::cout << "Let's play Black Jack card game!\n";
}

void Game::gameCycle()
{
    while (true)
    {
        std::cout << "Player score = " << m_playerScore << std::endl;

        if (m_playerScore > 21)
        {
            m_playerWin = false;
            return;
        }

        if (getPlayerChoice() == 's')
            return;

        m_playerScore += m_deck.dealCard().getCardValue();
    }
}

void Game::showResult()
{
    if (m_playerWin)
    {
        std::cout << "You win!" << std::endl;
    }
    else {
        std::cout << "You lose." << std::endl;
    }
}

void Game::final()
{
    if (m_playerWin)
    {
        while (m_dealerScore < 17)
        {
            m_dealerScore += m_deck.dealCard().getCardValue();
            std::cout << "Dealer score now = " << m_dealerScore << std::endl;
        }

        m_playerWin = (m_playerScore > m_dealerScore) || (m_dealerScore > 21);
    }

    showResult();
}

bool Game::start()
{
    init();

    m_dealerScore += m_deck.dealCard().getCardValue();
    std::cout << "Dealer's score = " << m_dealerScore << std::endl;

    m_playerScore += m_deck.dealCard().getCardValue();
    m_playerScore += m_deck.dealCard().getCardValue();

    gameCycle();

    final();

    return m_playerWin;
}

