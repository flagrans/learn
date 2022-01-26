#include <iostream>

using namespace std;

class ChocolateBoiler{ // Делал по аналогии с паттерном
// в методичке (синглтон Майерса) и почему, то в нем используются ссылки,
// а не указатели, подскажите есть ли принципиальная
// разница и вообще в чем заключается разница использования Майерса и описанного на уроке?
// Так же в методичке написано "Впрочем, в C++11 «синглтон Майерса» потокобезопасен
// безо всяких блокировок."

private:
    bool _empty;
    bool _boiled;
    ChocolateBoiler(){
        _empty = true;
        _boiled = false;
    }
    ChocolateBoiler(const ChocolateBoiler& root) = delete;
    ChocolateBoiler& operator=(const ChocolateBoiler&) = delete;
public:
    static ChocolateBoiler& getInstance() {
        static ChocolateBoiler oneInstance;
        return oneInstance;
    }
    bool isEmpty() const {
        return _empty;
    }
    bool isBoiled() const {
        return _boiled;
    }
    void fill() {
        if (isEmpty()) {
            _empty = false;
            _boiled = false;
        }
    }
    void drain() {
        if (!isEmpty() && isBoiled()) {
            _empty = true;
        }
    }
    void boil() {
        if (!isEmpty() && !isBoiled()) {
            _boiled = true;
        }
    }
};

int main()
{
    ChocolateBoiler& b1 = ChocolateBoiler::getInstance();
    cout << "Is Boiled b1: " << b1.isBoiled() << endl;
    cout << "Is Empty b1: " << b1.isEmpty() << endl;
    b1.fill();
    b1.boil();
    ChocolateBoiler& b2 = ChocolateBoiler::getInstance();;
    cout << "*******" << endl;
    cout << "Is Boiled b2: " << b2.isBoiled() << endl;
    cout << "Is Empty b2: " << b2.isEmpty() << endl;

    return 0;
}
