#ifndef CARD_H
#define CARD_H


class Card
{
public:
    enum CardRank {
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
        MAX_RANKS
    };
    enum CardSuit
    {
        CLUBS,
        TAMBOURINES,
        HEARTS,
        PEAKS,
        MAX_SUITES
    };

private:
    CardRank m_rank;
    CardSuit m_suit;

public:
    Card(const CardRank rank = MAX_RANKS, const CardSuit suit = MAX_SUITES);
    int getCardValue() const;
    void printCard() const;
};
#endif // CARD_H
