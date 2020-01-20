#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>

enum class CardRate {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    COUNT_DIGINITIES
};

enum class CardSuit
{
    CLUBS,
    TAMBOURINES,
    HEARTS,
    PEAKS,
    COUNT_SUITES
};

struct Card
{
    CardRate rate;
    CardSuit suit;
};

void printCard(const Card& card)
{
    switch(card.rate)
    {
    case CardRate::TWO:
        std::cout << 2;
        break;
    case CardRate::THREE:
        std::cout << 3;
        break;
    case CardRate::FOUR:
        std::cout << 4;
        break;
    case CardRate::FIVE:
        std::cout << 5;
        break;
    case CardRate::SIX:
        std::cout << 6;
        break;
    case CardRate::SEVEN:
        std::cout << 7;
        break;
    case CardRate::EIGHT:
        std::cout << 8;
        break;
    case CardRate::NINE:
        std::cout << 9;
        break;
    case CardRate::TEN:
        std::cout << 10;
        break;
    case CardRate::JACK:
        std::cout << 'J';
        break;
    case CardRate::QUEEN:
        std::cout << 'Q';
        break;
    case CardRate::KING:
        std::cout << 'K';
        break;
    case CardRate::ACE:
        std::cout << 'A';
        break;
    default:
        break;
    }

    switch (card.suit)
    {
    case CardSuit::CLUBS:
        std::cout << "TR";
        break;
    case CardSuit::TAMBOURINES:
        std::cout << 'B';
        break;
    case CardSuit::HEARTS:
        std::cout << "CH";
        break;
    case CardSuit::PEAKS:
        std::cout << 'P';
        break;
    default:
        break;
    }
}

void printDeck(const std::array<Card, 52>& deck)
{
    for (const Card& card : deck)
    {
        printCard(card);
        std::cout << std::endl;
    }
}

void swapCard(Card& card1, Card& card2)
{
    Card tempCard = card1;
    card1 = card2;
    card2 = tempCard;
}

void shuffleDeck(std::array<Card, 52>& deck)
{
    srand(static_cast<unsigned int>(time(0)));

    for (Card& card : deck)
    {
        int cardTwinIndex = rand() % 51;
        swapCard(card, deck.at(cardTwinIndex));
    }
}

int getCardValue(const Card& card)
{
    switch(card.rate)
    {
    case CardRate::TWO:
        return 2;
    case CardRate::THREE:
        return 3;
    case CardRate::FOUR:
        return 4;
    case CardRate::FIVE:
        return 5;
    case CardRate::SIX:
        return 6;
    case CardRate::SEVEN:
        return 7;
    case CardRate::EIGHT:
        return 8;
    case CardRate::NINE:
        return 9;
    case CardRate::TEN:
        return 10;
    case CardRate::JACK:
        return 10;
    case CardRate::QUEEN:
        return 10;
    case CardRate::KING:
        return 10;
    case CardRate::ACE:
        return 11;
    default:
        return 0;
    }
}

char getPlayerChoice()
{
    char choice;

    do
    {
      std::cout << "Make your choice. (h) for hit, (s) for stand\n";
      std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

bool playBlackJack(std::array<Card, 52>& deck)
{
    Card *cardPtr = &deck.at(0);
    int playerScore = 0, dealerScore = 0;

    std::cout << "Let's play Black Jack card game!\n";

    dealerScore += getCardValue(*cardPtr++);

    std::cout << "Dealer's score = " << dealerScore << std::endl;

    playerScore += getCardValue(*cardPtr++);
    playerScore += getCardValue(*cardPtr++);

    while (true)
    {
        std::cout << "Player score = " << playerScore << std::endl;

        if (playerScore > 21)
            return false;

        if (getPlayerChoice() == 's')
            break;

        playerScore += getCardValue(*cardPtr++);
    }

    while (dealerScore < 17)
    {
        dealerScore += getCardValue(*cardPtr++);
        std::cout << "Dealer score now = " << dealerScore << std::endl;
    }

    if (dealerScore > 21)
        return true;
    else return (playerScore > dealerScore);
}

int main()
{
    std::array<Card, 52> deck;

    for (int suit = 0; suit < static_cast<int>(CardSuit::COUNT_SUITES); suit++)
    {
        for (int dignity = 0;
             dignity < static_cast<int>(CardRate::COUNT_DIGINITIES);
             dignity++)
        {
            int cardIndex = suit * static_cast<int>(CardRate::COUNT_DIGINITIES)
                    + dignity;

            deck.at(cardIndex).rate = static_cast<CardRate>(dignity);
            deck.at(cardIndex).suit = static_cast<CardSuit>(suit);
        }
    }

    shuffleDeck(deck);
    if (playBlackJack(deck))
        std::cout << "\nPlayer win!\n";
    else std::cout << "\nDealer win!\n";

    return 0;
}
