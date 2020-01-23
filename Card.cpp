#include "Card.h"

#include <iostream>

Card::Card(const CardRank rank, const CardSuit suit)
    : m_rank(rank), m_suit(suit)
{

}

int Card::getCardValue() const
{
    switch(m_rank)
    {
    case TWO:
        return 2;
    case THREE:
        return 3;
    case FOUR:
        return 4;
    case FIVE:
        return 5;
    case SIX:
        return 6;
    case SEVEN:
        return 7;
    case EIGHT:
        return 8;
    case NINE:
        return 9;
    case TEN:
        return 10;
    case JACK:
        return 10;
    case QUEEN:
        return 10;
    case KING:
        return 10;
    case ACE:
        return 11;
    default:
        return 0;
    }
}

void Card::printCard() const
{
    switch(m_rank)
    {
    case TWO:
        std::cout << 2;
        break;
    case THREE:
        std::cout << 3;
        break;
    case FOUR:
        std::cout << 4;
        break;
    case FIVE:
        std::cout << 5;
        break;
    case SIX:
        std::cout << 6;
        break;
    case SEVEN:
        std::cout << 7;
        break;
    case EIGHT:
        std::cout << 8;
        break;
    case NINE:
        std::cout << 9;
        break;
    case TEN:
        std::cout << 10;
        break;
    case JACK:
        std::cout << 'J';
        break;
    case QUEEN:
        std::cout << 'Q';
        break;
    case KING:
        std::cout << 'K';
        break;
    case ACE:
        std::cout << 'A';
        break;
    default:
        break;
    }

    switch (m_suit)
    {
    case CLUBS:
        std::cout << "TR";
        break;
    case TAMBOURINES:
        std::cout << 'B';
        break;
    case HEARTS:
        std::cout << "CH";
        break;
    case PEAKS:
        std::cout << 'P';
        break;
    default:
        break;
    }
}
