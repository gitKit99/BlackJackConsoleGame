#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <array>

class Deck
{
    std::array<Card, 52> m_deck;
    int m_cardIndex = 0;

    static int getRandomNumber(int min, int max);
    static void swapCard(Card& card1, Card& card2);

public:
    static const int DECK_COUNT = 52;

    Deck();

    void printDeck() const;

    void shuffleDeck();

    const Card& dealCard();
};

#endif // DECK_H
