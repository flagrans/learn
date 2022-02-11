#include <iostream>
#include <vector>
int i = 0;
class Dish {
public:
    virtual ~Dish() {}
    virtual float getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual void printDish() const = 0;
};

class Pancake : public Dish {
private:
    std::string _name;
    float _price;

public:
    Pancake(const std::string &name, float price)
        : _name(name), _price(price) {}
    float getPrice() const override { return _price; }
    std::string getName() const override { return _name; }
    void printDish() const override {
        for (int j = 0; j < i; j++)
            std::cout << "\t";
        std::cout << this->getName() << ": " << this->getPrice() << std::endl;
    }
};

class Icecream : public Dish {
private:
    std::string _name;
    float _price;

public:
    Icecream(const std::string &name, float price)
        : _name(name), _price(price) {}
    float getPrice() const override { return _price; }
    std::string getName() const override { return _name; }
    void printDish() const override {
        for (int j = 0; j < i; j++)
            std::cout << "\t";
        std::cout << this->getName() << ": " << this->getPrice() << std::endl;
    }
};

class Beverage : public Dish {
private:
    std::string _name;
    float _price;

public:
    Beverage(const std::string &name, float price)
        : _name(name), _price(price) {}
    float getPrice() const override { return _price; }
    std::string getName() const override { return _name; }
    void printDish() const override {
        for (int j = 0; j < i; j++)
            std::cout << "\t";
        std::cout << this->getName() << ": " << this->getPrice() << std::endl;
    }
};

class CompositeDish : public Dish {
private:
    std::string _name;
    std::vector<Dish *> _dishs;

public:
    CompositeDish(const std::string &name) : _name(name) {}

    float getPrice() const override {
        float total = 0;
        for (const auto &dish : _dishs) {
            total += dish->getPrice();
        }
        return total;
    }

    std::string getName() const override { return _name; };

    void printDish() const override {
        for (int j = 0; j < i; j++)
            std::cout << "\t";
        std::cout << _name << ":" << std::endl;
        i++;
        for (const auto &dish : _dishs) {
            dish->printDish();
        }
        i--;
        for (int j = 0; j < i; j++)
            std::cout << "\t";
        std::cout << "Total price: " << getPrice() << std::endl;
    }

    void addDish(Dish *pDish) { _dishs.push_back(pDish); }

    virtual ~CompositeDish() {
        for (const auto &dish : _dishs) {
            delete dish;
        }
    }
};

CompositeDish *createCombo1() {
    CompositeDish *dish = new CompositeDish("SubCombo #1");
    dish->addDish(new Pancake("Morning pancake", 240.0f));
    dish->addDish(new Icecream("Banana Split", 260));
    dish->addDish(new Beverage("Coffee", 80));
    return dish;
}

CompositeDish *createCombo2() {
    CompositeDish *dish = new CompositeDish("SubCombo #2");
    dish->addDish(new Pancake("Mexican pancake", 270.0f));
    dish->addDish(new Pancake("Jam pancake", 190.0f));
    dish->addDish(new Icecream("Hot Brauni", 310));
    dish->addDish(new Icecream("Tutti Fruity", 240));
    dish->addDish(new Beverage("Coffee", 80));
    dish->addDish(new Beverage("Pepsi", 120));
    return dish;
}

int main() {
    Icecream *vanilla = new Icecream("Vanilla ice cream", 180);
    Beverage *tea = new Beverage("Tea", 50);

    CompositeDish *combo1 = new CompositeDish("Combo #1");
    combo1->addDish(createCombo1());
    combo1->addDish(vanilla);
    combo1->printDish();

    std::cout << std::endl;

    CompositeDish *combo2 = new CompositeDish("Combo #2");
    combo2->addDish(createCombo2());
    combo2->addDish(tea);
    combo2->printDish();

    delete tea;
    delete vanilla;
    return 0;
}
