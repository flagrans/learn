#include <iostream>
#include <array.h>
#include <vector>
#include <set>

// 3 task
enum vCard {
    ACE = 11,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 10,
    QUEEN = 10,
    KING = 10
};

enum sCard {
    CLUBS = 1,
    DIAMONDS = 2,
    HEARTS = 3,
    SPADES = 4
};

class Card {
    sCard suitCard;
    vCard valueCard;
    bool flipCard;
public:
    Card (sCard m_suitCard = sCard::CLUBS, vCard m_valueCard = vCard::TWO, bool m_flipCard = false)
        : suitCard(m_suitCard), valueCard(m_valueCard), flipCard(m_flipCard) {}
    void Flip() { flipCard = !flipCard; }
    bool getFlip() const { return flipCard; }
    vCard getValue() const {
        return valueCard;
    }
    sCard getSuit() const {
        return suitCard;
    }


};

class Hand {
    std::vector<Card*> m_Cards;
public:
    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    }
    void Clear() {
        for (auto i : m_Cards) {
            delete i;
        }
        m_Cards.clear();
    }
    int GetTotal() {
        int t = 0;
        for (auto i : m_Cards) {
            t += i->getValue();
        }
        if (t > 21)
            t -= 10;
        return t;
    }
};

int main() {
// 1 task
    ArrayInt a;
    a.push_back(2);
    a.push_back(5);
    a.push_back(1);
    a.push_back(77);
    a.push_back(12);
    a.push_back(236);
    a.push_back(3);
    a.push_back(2);
    std::cout << a << std::endl;
    a.print();
    a.sort();
    a.print();
    a.pop_back();
    a.print();
    a.pop_front();
    a.print();
    ArrayInt b;
    b.push_back(1);
    int t = b.pop_back();
    std::cout << t << std::endl;
    t = b.pop_back();
    std::cout << t << std::endl;
    t = b.pop_back();
    std::cout << t << std::endl;

// 2 task
    std::vector<int> v = {2, 45, 6, 3, 2, 6, 7, 566, 43};
    std::set<int> s;
    for (auto i : v)
        s.insert(i);
    std::cout << s.size() << std::endl;
// 3 task
    Hand h;
    //Card *c1 = new Card();
    h.Add(new Card());
    h.Add(new Card(sCard::HEARTS, vCard::FIVE, false));
    h.Add(new Card(sCard::HEARTS, vCard::KING, false));
    h.Add(new Card(sCard::HEARTS, vCard::ACE, false));
    std::cout << h.GetTotal() << std::endl;
    h.Clear();
    std::cout << h.GetTotal() << std::endl;

    return 0;
}
