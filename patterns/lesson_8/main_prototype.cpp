#include <iostream>

class Monster {
protected:
    int hp_ = 0;
    int atk_ = 0;
    int def_ = 0;
    std::string type_ = "";

public:
    void changeHp(int change) { hp_ += change; }

    void changeAtk(int change) { atk_ += change; }

    void changeDef(int change) { def_ += change; }

    int getHp() const { return hp_; }

    int getAtk() const { return atk_; }

    int getDef() const { return def_; }

    virtual void print() const = 0;
    virtual Monster *clone() const = 0;

    virtual ~Monster() {}
};

class Necromancer : public Monster {
public:
    Necromancer() {}
    Necromancer(int hp, int atk, int def, const std::string &type) {
        hp_ = hp;
        atk_ = atk;
        def_ = def;
        type_ = type;
    }
    Necromancer(const Necromancer &other) {
        hp_ = other.hp_;
        atk_ = other.atk_;
        def_ = other.def_;
        type_ = other.type_;
    }
    Necromancer *clone() const override { return new Necromancer(*this); }
    void print() const override {
        std::cout << "Necromancer: type=" << type_ << ", hp=" << hp_
                  << ", attack=" << atk_ << ", defend=" << def_ << std::endl;
    }
};

class Horseman : public Monster {
public:
    Horseman() {}
    Horseman(int hp, int atk, int def, const std::string &type) {
        hp_ = hp;
        atk_ = atk;
        def_ = def;
        type_ = type;
    }
    Horseman(const Horseman &other) {
        hp_ = other.hp_;
        atk_ = other.atk_;
        def_ = other.def_;
        type_ = other.type_;
    }
    Horseman *clone() const override { return new Horseman(*this); }
    void print() const override {
        std::cout << "Horseman: type=" << type_ << ", hp=" << hp_
                  << ", attack=" << atk_ << ", defend=" << def_ << std::endl;
    }
};

int main() {
    Necromancer *unit1 = new Necromancer(1000, 50, 30, "undead");
    Necromancer *unit2 = unit1->clone();
    unit1->changeHp(200);
    unit2->changeDef(20);
    unit1->print();
    unit2->print();

    std::cout << std::endl;
    Horseman *unit3 = new Horseman(2000, 20, 60, "people");
    Horseman *unit4 = unit3->clone();
    unit3->changeHp(200);
    unit4->changeDef(20);
    unit3->print();
    unit4->print();

    delete unit4;
    delete unit3;
    delete unit2;
    delete unit1;

    std::cout << std::endl;
    return 0;
}
