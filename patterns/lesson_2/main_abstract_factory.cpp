#include <iostream>
#include <string>
#include <vector>

class IPizza{
public:
    virtual void prepare(std::string &) = 0;
    virtual void bake(){};
    virtual void cut(){};
    virtual void box(){};
    virtual ~IPizza() {};
};

class CheesePizza:public IPizza{
public:
    void prepare(std::string &s) override {
        std::cout << "CheesePizza" << std::endl;
    }
};
class GreekPizza:public IPizza{
public:
    void prepare(std::string &s) override {
        std::cout << "GreekPizza" << std::endl;
    }
};
class PepperoniPizza:public IPizza{
public:
    void prepare(std::string &s) override {
        std::cout << "PepperoniPizza" << std::endl;
    }
};

class IPizzaFactory {
public:
    virtual IPizza* createPizza() = 0;
    virtual ~IPizzaFactory() {};
};

class FactoryCheesePizza:public IPizzaFactory {
public:
    CheesePizza* createPizza() override {
        return new CheesePizza;
    }
};
class FactoryGreekPizza:public IPizzaFactory {
public:
    GreekPizza* createPizza() override {
        return new GreekPizza;
    }
};
class FactoryPepperoniPizza:public IPizzaFactory {
public:
    PepperoniPizza* createPizza() override {
        return new PepperoniPizza;
    }
};

IPizza* orderPizza(IPizzaFactory &type){
   IPizza* pizza = nullptr;
   pizza = type.createPizza();
   return pizza;
}

int main() {
    FactoryCheesePizza cp;
    FactoryGreekPizza gp;
    FactoryPepperoniPizza pp;

    std::string s = "111";
    IPizza* test = orderPizza(pp);

    test->prepare(s);
    delete test;
    test = orderPizza(gp);
    test->prepare(s);
    delete test;
    test = orderPizza(cp);
    test->prepare(s);
    delete test;
    return 0;
}
