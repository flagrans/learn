#include <iostream>
#include <cmath>


enum vCard {
    ACE = 1,
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

// 1 task
class Figure {
protected:
    double a;
public:
    Figure (double m_a = 0) : a(m_a) {}
    virtual double area() = 0;
};

class Parallelogram : public Figure {
protected:
    double b; // второй параметр инициализации считаем высотой, первый длинОй длИной стороны
public:
    Parallelogram (double m_a = 0.0, double m_b = 0.0) : Figure(m_a),  b(m_b) {}
    double area () override {
        return a * b;
    }
};
class Circle : public Figure {
public:
    Circle (double m_a = 0.0) : Figure(m_a) {}
    double area () override {
        return 3.14 * pow(a, 2);
    }
};
class Rectangle : public Parallelogram {
public:
    Rectangle (double m_a = 0.0, double m_b = 0.0) : Parallelogram(m_a, m_b) {}
    double area () override {
        return a * b;
    }
};
class Square : public Parallelogram {
public:
    Square (double m_a = 0.0, double m_b = 0.0) : Parallelogram(m_a, m_b) {}
    double area () override {
        return a * a;
    }
};
class Rhombus : public Parallelogram { // второй параметр инициализации считаем высотой, первый длиной стороны
public:
    Rhombus (double m_a = 0.0, double m_b = 0.0) : Parallelogram(m_a, m_b) {}
    double area () override {
        return a * b;
    }
};
// 2 task
class Car {
  std::string company;
  std::string model;
public:
  Car () {
      std::cout << "Car()" << std::endl;
  }
};
class PassengerCar : virtual public Car {
public:
    PassengerCar () {
        std::cout << "PassengerCar()" << std::endl;
    }
};
class Bus : virtual public Car {
public:
    Bus () {
        std::cout << "Bus()" << std::endl;
    }
};
class Minivan : public PassengerCar, public Bus {
public:
    Minivan () {
        std::cout << "Minivan()" << std::endl;
    }
};

// 3 task
//struct Frac {
//    int nominator;
//    int denominator;
//};
class Fraction {
    int nominator;
    int denominator;
public:
    //Fraction (int m_nominator = 0, int m_denominator = 1) : i.nominator(m_nominator), i.denominator(m_denominator) {}
    // Почему с объединением или структурой Frac код выше не работает, а ниже работает?
    Fraction (int m_nominator = 0, int m_denominator = 1) {
        if (m_denominator == 0) {
            std::cout << "Fail. The denominator cannot be equal to 0" << std::endl;
            std::cout << "Default fraction created = 0/1" << std::endl;
            return;
        } else {
            nominator = m_nominator;
            denominator = m_denominator;
        }
    }
    void set (int m_nominator, int m_denominator) {
        if (m_denominator == 0) {
            std::cout << "Fail. The denominator cannot be equal to 0" << std::endl;
            return;
        } else {
            nominator = m_nominator;
            denominator = m_denominator;
        }
    }

    friend std::ostream& operator<< (std::ostream &out, const Fraction &f);
    friend Fraction operator+(const Fraction &f1, const Fraction  &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction  &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction  &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction  &f2);
    Fraction operator-() const;
    friend bool operator==(const Fraction &f1, const Fraction  &f2);
    friend bool operator!=(const Fraction &f1, const Fraction  &f2);
    friend bool operator>(const Fraction &f1, const Fraction  &f2);
    friend bool operator<(const Fraction &f1, const Fraction  &f2);
    friend bool operator>=(const Fraction &f1, const Fraction  &f2);
    friend bool operator<=(const Fraction &f1, const Fraction  &f2);
};
std::ostream& operator<< (std::ostream &out, const Fraction &f){
    out << f.nominator << "/" << f.denominator;
    return out;
}

Fraction Fraction::operator-() const{
    return -nominator;
}

Fraction operator+(const Fraction &f1, const Fraction  &f2){
    Fraction temp;
    temp.nominator = f1.nominator * f2.denominator + f2.nominator * f1.denominator;
    temp.denominator = f1.denominator * f2.denominator;
    return temp;
}

Fraction operator-(const Fraction &f1, const Fraction  &f2){
    Fraction temp;
    temp.nominator = f1.nominator * f2.denominator - f2.nominator * f1.denominator;
    temp.denominator = f1.denominator * f2.denominator;
    return temp;
}

Fraction operator*(const Fraction &f1, const Fraction  &f2){
    Fraction temp;
    temp.nominator = f1.nominator * f2.nominator;
    temp.denominator = f1.denominator * f2.denominator;
    return temp;
}

Fraction operator/(const Fraction &f1, const Fraction  &f2){
    Fraction temp;
    temp.nominator = f1.nominator * f2.denominator;
    temp.denominator = f1.denominator * f2.nominator;
    return temp;
}

bool operator==(const Fraction &f1, const Fraction  &f2){
    return (f1.nominator == f2.nominator && f1.denominator == f2.denominator);
}

bool operator!=(const Fraction &f1, const Fraction  &f2){
    return !(f1 == f2);
}

bool operator>(const Fraction &f1, const Fraction  &f2){
    return ((f1.nominator*f2.denominator) > (f2.nominator*f1.denominator));
}

bool operator<(const Fraction &f1, const Fraction  &f2){
    return !(f1 > f2);
}

bool operator>=(const Fraction &f1, const Fraction  &f2){
    return ((f1 > f2) || (f1 == f2));
}

bool operator<=(const Fraction &f1, const Fraction  &f2){
    return ((f1 < f2) || (f1 == f2));
}

// 4 task

int main(){
// 1 task
    std::cout << "Task 1:" << std::endl;
    Parallelogram p(3, 5);
    std::cout << p.area() << std::endl;
    Rectangle r(2, 4);
    std::cout << r.area() << std::endl;
    Square s(2, 2);
    std::cout << s.area() << std::endl;
    Rhombus ro(2, 5);
    std::cout << ro.area() << std::endl;
    Circle c(2);
    std::cout << c.area() << std::endl;
    std::cout << "********" << std::endl;
// 2 task
    std::cout << "Task 2:" << std::endl;
    Car car;
    std::cout << "---" << std::endl;
    Bus bus;
    std::cout << "---" << std::endl;
    PassengerCar pcar;
    std::cout << "---" << std::endl;
    Minivan mini;
    std::cout << "********" << std::endl;
// 3 task
    Fraction f1(1, 0);
    f1.set(3, 5);
    Fraction f2(1, 2);
    f2.set(5, 0);
    f2.set(1, 2);
    std::cout << f1 <<std::endl;
    std::cout << f2 <<std::endl;
    Fraction f;
    f = f1 + f2; // Сложение
    std::cout << f1 << " + " << f2 << " = " << f << std::endl;
    f = f1 - f2; // Вычитание
    std::cout << f1 << " - " << f2 << " = " << f << std::endl;
    f = f1 * f2; // Умножение
    std::cout << f1 << " * " << f2 << " = " << f << std::endl;
    f = f1 / f2; // Деление
    std::cout << f1 << " / " << f2 << " = " << f << std::endl;
    std::cout << -f << std::endl; // Унарный минус
    std::cout << f1 << " == " << f2 << " - " << (f1 == f2) << std::endl; // Равно
    std::cout << f1 << " != " << f2 << " - " << (f1 != f2) << std::endl; // Не равно
    f2.set(3, 5);
    std::cout << f1 << " == " << f2 << " - " << (f1 == f2) << std::endl; // Равно
    std::cout << f1 << " != " << f2 << " - " << (f1 != f2) << std::endl; // Не равно
    f2.set(1, 2);
    std::cout << f1 << " > " << f2 << " - " << (f1 > f2) << std::endl; // Больше
    std::cout << f1 << " < " << f2 << " - " << (f1 < f2) << std::endl; // Меньше
    std::cout << f1 << " >= " << f2 << " - " << (f1 >= f2) << std::endl; // Больше либо равно
    std::cout << f1 << " <= " << f2 << " - " << (f1 <= f2) << std::endl; // Меньше либо равно
    f2.set(3, 5);
    std::cout << f1 << " >= " << f2 << " - " << (f1 >= f2) << std::endl; // Больше либо равно
    std::cout << f1 << " <= " << f2 << " - " << (f1 <= f2) << std::endl; // Меньше либо равно
// 4 task
    Card card;
    std::cout << card.getFlip() << std::endl;
    card.Flip();
    std::cout << card.getFlip() << std::endl;
    card.Flip();
    std::cout << card.getFlip() << std::endl;

    Card card2 (sCard::DIAMONDS, vCard::NINE, false);

    std::cout << card2.getValue() << std::endl;

    return 0;
}
