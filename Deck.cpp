#include "Deck.h"

#include <iostream>
#include <cstdlib>

Deck::Deck()
{
    srand(static_cast<unsigned int>(time(0)));

    for (int suit = 0; suit < static_cast<int>(Card::MAX_SUITES); suit++)
    {
        for (int rank = 0;
             rank < static_cast<int>(Card::MAX_RANKS);
             rank++)
        {
            int cardIndex = suit * static_cast<int>(Card::MAX_RANKS) + rank;

            m_deck.at(cardIndex) = Card(static_cast<Card::CardRank>(rank),
                                        static_cast<Card::CardSuit>(suit));
        }
    }
}

int Deck::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::swapCard(Card& card1, Card& card2)
{
    Card tempCard = card1;
    card1 = card2;
    card2 = tempCard;
}

void Deck::printDeck() const
{
    for (const Card& card : m_deck)
    {
        card.printCard();
        std::cout << std::endl;
    }
}

void Deck::shuffleDeck()
{
    for (Card& card : m_deck)
    {
        int cardTwinIndex = getRandomNumber(0, DECK_COUNT - 1);
        swapCard(card, m_deck.at(cardTwinIndex));
    }

    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    return m_deck.at(m_cardIndex++);
}
