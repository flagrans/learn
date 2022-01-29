#include <iostream>

class Beverage{            // Абстрактный класс
public:
    virtual std::string getDescription() const = 0; // что-то я тут подумал, что описание
    // не должно возвращать double и изменил на std::string, либо не понял задумки
    virtual double cost() const = 0;
    virtual ~Beverage() {};
};
                                                 // и в задании не проставлены public:
class HouseBlend: public Beverage{   // Молотый
public:
    double cost() const override {
        return 5.5;
    }
    virtual std::string getDescription() const override {
        return "HouseBlend";
    }
};

class DarkRoast: public Beverage{  // Темной обжарки
public:
    double cost() const override {
        return 6.0;
    }
    virtual std::string getDescription() const override {
        return "DarkRoast";
    }
};

class Decaf: public Beverage{    // Без кофеина
public:
    double cost() const override {
        return 7.3;
    }
    virtual std::string getDescription() const override {
        return "Decaf";
    }
};

class Espresso: public Beverage{  // Эспрессо
public:
    double cost() const override {
        return 3.5;
    }
    virtual std::string getDescription() const override {
        return "Espresso";
    }
};

class Decorator: public Beverage{
public:
    Decorator(Beverage* typeCoffe): _typeCoffe(typeCoffe){};

    virtual double cost() const override {
        return _typeCoffe->cost();
    }
    virtual std::string getDescription() const override {
        return _typeCoffe->getDescription();
    }

private:
    Beverage* _typeCoffe;
};

class withChocolate : public Decorator {
public:
    withChocolate(Beverage* typeCoffe) : Decorator(typeCoffe) {}
    virtual double cost() const override {
        return Decorator::cost() + 1.0;
    }
    virtual std::string getDescription() const override {
        return Decorator::getDescription() + " with Chocolate";
    }
};
class withCinnamon : public Decorator {
public:
    withCinnamon(Beverage* typeCoffe) : Decorator(typeCoffe) {}
    virtual double cost() const override {
        return Decorator::cost() + 0.3;
    }
    virtual std::string getDescription() const override {
        return Decorator::getDescription() + " with Cinnamon";
    }
};
class withCream : public Decorator {
public:
    withCream(Beverage* typeCoffe) : Decorator(typeCoffe) {}
    virtual double cost() const override {
        return Decorator::cost() + 0.7;
    }
    virtual std::string getDescription() const override {
        return Decorator::getDescription() + " with Cream";
    }
};
class withoutSugar : public Decorator {
public:
    withoutSugar(Beverage* typeCoffe) : Decorator(typeCoffe) {}
    virtual double cost() const override {
        return Decorator::cost() - 0.35;
    }
    virtual std::string getDescription() const override {
        return Decorator::getDescription() + " without Sugar";
    }
};


int main() {
    DarkRoast* c1 = new DarkRoast();
    std::cout << c1->getDescription() << " : " << c1->cost() << std::endl;

    Decorator* cream = new withCream(c1);
    std::cout << cream->getDescription() << " : " << cream->cost() << std::endl;

    Decorator* ws = new withoutSugar(cream);
    std::cout << ws->getDescription() << " : " << ws->cost() << std::endl;

    delete ws;
    delete cream;
    delete  c1;
    return 0;
}
