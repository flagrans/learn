#include <iostream>

class CoffeeMachine;

class State {
private:
    std::string name;

public:
    State(const std::string &name) : name(name) {}

    const std::string &getName() const { return name; }

    // Здесь если методы не объявлять абстрактыми, то можно будет не обязательно
    // их переопределять в каждом классе состояния, такой вариант
    // закомментировал в коде здесь и ниже по тексту
    //    virtual void dropCoin(CoffeeMachine *){};
    //    virtual void returnCoin(CoffeeMachine *){};
    //    virtual void pressBuyCoffee(CoffeeMachine *){};
    //    virtual void checkCoffee(CoffeeMachine *){};

    virtual void dropCoin(CoffeeMachine *) = 0;
    virtual void returnCoin(CoffeeMachine *) = 0;
    virtual void pressBuyCoffee(CoffeeMachine *) = 0;
    virtual void checkCoffee(CoffeeMachine *) = 0;

    virtual ~State() {}
};

class CoffeeMachine {
private:
    State *state;
    int coffee = 100; // Вводим переменную для хранения текущего количества кофе
                      // в автомате
    bool isCheck =
        false; // Переменная, чтобы реализовать метод автоматическую проверку
               // наличия кофе в автомате после приготовления очередной порции

public:
    CoffeeMachine(State *state) : state(state) {}

    void dropCoin() {
        std::cout << "Drop a coin" << std::endl;
        state->dropCoin(this);
    }

    void returnCoin() {
        std::cout << "Return coin" << std::endl;
        state->returnCoin(this);
    }

    void pressBuyCoffee() {
        std::cout << "Press buy coffee" << std::endl;
        coffee -= 50;
        state->pressBuyCoffee(this);
    }

    void checkCoffee() { // Проверка наличия кофе в автомате
        std::cout << "Check coffee" << std::endl;
        state->checkCoffee(this);
    }

    void falseIsCheck() { isCheck = false; }

    State *GetState() { return state; }
    int GetCoffee() { return coffee; }

    void setState(State *newState) {
        std::cout << "Chaging newState from <<" << state->getName()
                  << ">> to <<" << newState->getName() << ">>..." << std::endl;
        if (newState->getName() == "Coffee is ready.")
            isCheck =
                true; // Если перешли в необходимое состояние - меняем
                      // переменную, чтобы сделать дальше проверку автоматом
        delete state;
        state = newState;
        if (isCheck)
            checkCoffee(); // А здесь уже вызываем проверку после всех
                           // необходимых действий
    }

    virtual ~CoffeeMachine() { delete state; }
};
/*
class NoCoin : public State {
public:
    NoCoin() : State("No coin.") {}
    void dropCoin(CoffeeMachine *);
};

class HaveCoin : public State {
public:
    HaveCoin() : State("Have a coin.") {}
    void returnCoin(CoffeeMachine *);
    void pressBuyCoffee(CoffeeMachine *);
};

class CoffeeReady : public State {
public:
    CoffeeReady() : State("Coffee is ready.") {}
    void checkCoffee(CoffeeMachine *);
};

class NoCoffee : public State {
public:
    NoCoffee() : State("No Coffee.") {}
};

void NoCoin::dropCoin(CoffeeMachine *state) { state->setState(new HaveCoin); }

void HaveCoin::returnCoin(CoffeeMachine *state) { state->setState(new NoCoin); }

void HaveCoin::pressBuyCoffee(CoffeeMachine *state) {
    state->setState(new CoffeeReady);
}

void CoffeeReady::checkCoffee(CoffeeMachine *state) {
    state->falseIsCheck();
    if (state->GetCoffee() <= 0)
        state->setState(new NoCoffee);
    else
        state->setState(new NoCoin);
}
*/
// Вариант выше короче и рабочий, но он не извещает о том, что состояние не
// возможно изменить при попытке вызвать недопустимый метод из текущего
// состояния, но при этом сохранят текущее состояние
class NoCoin : public State {
public:
    NoCoin() : State("No coin.") {}
    void dropCoin(CoffeeMachine *) override;
    void returnCoin(CoffeeMachine *) override;
    void pressBuyCoffee(CoffeeMachine *) override;
    void checkCoffee(CoffeeMachine *) override;
};

class HaveCoin : public State {
public:
    HaveCoin() : State("Have a coin.") {}
    void dropCoin(CoffeeMachine *) override;
    void returnCoin(CoffeeMachine *) override;
    void pressBuyCoffee(CoffeeMachine *) override;
    void checkCoffee(CoffeeMachine *) override;
};

class CoffeeReady : public State {
public:
    CoffeeReady() : State("Coffee is ready.") {}
    void dropCoin(CoffeeMachine *) override;
    void returnCoin(CoffeeMachine *) override;
    void pressBuyCoffee(CoffeeMachine *) override;
    void checkCoffee(CoffeeMachine *) override;
};

class NoCoffee : public State {
public:
    NoCoffee() : State("No Coffee.") {}
    void dropCoin(CoffeeMachine *) override;
    void returnCoin(CoffeeMachine *) override;
    void pressBuyCoffee(CoffeeMachine *) override;
    void checkCoffee(CoffeeMachine *) override;
};

void NoCoin::dropCoin(CoffeeMachine *state) { state->setState(new HaveCoin); }
void NoCoin::returnCoin(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void NoCoin::pressBuyCoffee(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void NoCoin::checkCoffee(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}

void HaveCoin::returnCoin(CoffeeMachine *state) { state->setState(new NoCoin); }
void HaveCoin::pressBuyCoffee(CoffeeMachine *state) {
    state->setState(new CoffeeReady);
}
void HaveCoin::dropCoin(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void HaveCoin::checkCoffee(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}

void CoffeeReady::checkCoffee(CoffeeMachine *state) {
    state->falseIsCheck();
    if (state->GetCoffee() <= 0)
        state->setState(new NoCoffee);
    else
        state->setState(new NoCoin);
}
void CoffeeReady::dropCoin(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void CoffeeReady::returnCoin(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void CoffeeReady::pressBuyCoffee(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}

void NoCoffee::dropCoin(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void NoCoffee::returnCoin(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void NoCoffee::pressBuyCoffee(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}
void NoCoffee::checkCoffee(CoffeeMachine *state) {
    std::cout << "The method is not available in this state." << std::endl;
}

int main() {
    CoffeeMachine *pCoffeeMachine = new CoffeeMachine(new NoCoin());
    if (pCoffeeMachine != nullptr) {
        std::cout << "Current state: " << pCoffeeMachine->GetState()->getName()
                  << std::endl;
        pCoffeeMachine->dropCoin();
        pCoffeeMachine->pressBuyCoffee();
        pCoffeeMachine
            ->returnCoin(); // В качестве проверки - метод вызывается, но
                            // состояние при этом не меняется, т.к. из текущего
                            // состояния, туда невозможно перейти

        std::cout << std::endl << std::endl;

        std::cout << "Current state: " << pCoffeeMachine->GetState()->getName()
                  << std::endl;
        pCoffeeMachine->dropCoin();
        pCoffeeMachine->returnCoin();

        std::cout << std::endl << std::endl;

        std::cout << "Current state: " << pCoffeeMachine->GetState()->getName()
                  << std::endl;
        pCoffeeMachine->dropCoin();
        pCoffeeMachine->pressBuyCoffee();
    }
    delete pCoffeeMachine;
    std::cout << std::endl;
    return 0;
}
