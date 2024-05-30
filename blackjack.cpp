#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

class Card{
    public:
    
    enum rank {
        ACE = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king
    };
    enum suit {
        hearts, diamonds, clubs, spades
    };

    friend ostream& operator << (ostream& os, const Card& aCard);
    Card(rank r = ACE, suit s = spades, bool ifu = true);

    int GetValue() const;
    void Flip();
    private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
    
};
