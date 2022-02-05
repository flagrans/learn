#include <iostream>

class Pizza{
public:
    virtual void prepare()  = 0;
    virtual void bake() {};
    virtual void cut() {};
    virtual void box() {};
    virtual ~Pizza(){};
};

class CheesePizza:public Pizza{
public:
    void prepare() {
        std::cout << "CheesePizza" << std::endl;
    }
};
class GreekPizza:public Pizza{
public:
    void prepare() {
        std::cout << "GreekPizza" << std::endl;
    }
};
class PepperoniPizza:public Pizza{
public:
    void prepare() {
        std::cout << "PepperoniPizza" << std::endl;
    }
};
class PizzaFactory{
public:
    virtual Pizza* createPizza() = 0;
    virtual ~PizzaFactory() {}
};
class CheesePizzaFactory : public PizzaFactory{
public:
    Pizza* createPizza() override {
        return new CheesePizza;
    }
};
class GreekPizzaFactory : public PizzaFactory{
public:
    Pizza* createPizza() override {
        return new GreekPizza;
    }
};
class PepperoniPizzaFactory : public PizzaFactory{
public:
    Pizza* createPizza() override {
        return new PepperoniPizza;
    }
};

Pizza* addPizza(PizzaFactory* pf) {
    return pf->createPizza();
}

int main() {
    CheesePizzaFactory* cheesePizzaFactory = new CheesePizzaFactory();
    GreekPizzaFactory* greekPizzaFactory = new GreekPizzaFactory();
    PepperoniPizzaFactory* pepperoniPizzaFactory = new PepperoniPizzaFactory();

    Pizza* a = addPizza(cheesePizzaFactory);
    a->prepare();
    Pizza* b = addPizza(greekPizzaFactory);
    b->prepare();
    Pizza* c = addPizza(pepperoniPizzaFactory);
    c->prepare();




    delete a;
    delete b;
    delete c;
    delete pepperoniPizzaFactory;
    delete greekPizzaFactory;
    delete cheesePizzaFactory;

    return 0;
}
