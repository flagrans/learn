#include <iostream>
#include <vector>

class Card {
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int GetValue() const;
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetValue() const {
    int value = 0;
    if (m_IsFaceUp) {
        value = m_Rank;
        if (value > 10) {
            value = 10;
        }
    }
    return value;
}

void Card::Flip() {
    m_IsFaceUp = !(m_IsFaceUp);
}

class Hand {
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard);
    void Clear();
    int GetTotal() const;

protected:
    std::vector<Card*> m_Cards;
};

Hand::Hand() {
    m_Cards.reserve(7);
}
Hand::~Hand() {
    Clear();
}

void Hand::Add(Card* pCard) {
    m_Cards.push_back(pCard);
}

void Hand::Clear() {
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();
}

int Hand::GetTotal() const {
    if (m_Cards.empty()) {
        return 0;
    }
    if (m_Cards[0]->GetValue() == 0) {
        return 0;
    }
    int total = 0;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        total += (*iter)->GetValue();
    }
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        if ((*iter)->GetValue() == Card::ACE) {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) {
        total += 10;
    }
    return total;
}

class GenericPlayer : public Hand {
public:
    GenericPlayer(std::string _name = "Vasya") : name(_name) {}
    virtual bool IsHitting() = 0;
    bool IsBoosted() const;
    void Bust() const;
private:
    std::string name;
};

bool GenericPlayer::IsBoosted() const {
    if (GetTotal() > 21) {
        return true;
    }
   return false;
}

void GenericPlayer::Bust() const {
    std::cout << "Player " << name << " has bust." << std::endl;

}


int main() {
    std::cout << "Test" << std::endl;
    return 0;
}
