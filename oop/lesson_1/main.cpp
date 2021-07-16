#include <iostream>
#include <cmath>
#include <cstdint>
// 1 task
class Power {
    double ma = 0;
    double mb = 0;
public:
    Power(){}
    Power(double a, double b) : ma(a), mb(b) {}
    void set(double a, double b) {
        ma = a;
        mb = b;
    }
    void calculate () {
        std::cout << "a^b = " << pow(ma, mb) << std::endl;
    }
};
//2 task
class RGBA {
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
public:
    RGBA(){}
    RGBA (std::uint8_t red, std::uint8_t green,
          std::uint8_t blue, std::uint8_t alpha) :
        m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){}
    void print () {
        std::cout << "rgba: " << unsigned(m_red) << "," << unsigned(m_green)
                  << "," << unsigned(m_blue) << "," << unsigned(m_alpha)
                  << std::endl;
    }
};
//3 task
class Stack {
    int st[10] = {};
    int size = 0;
public:
    void reset() {
        for (int i = 0; i < size; i++) { // т.к. стек по-умолчанию инициализируется 0 то нет смысла проберать по всему стеку, обнуляем только занятые элементы.
            st[i] = 0;
        }
        size = 0;
    }
    bool push(int a){
        if (size == 10) return false;
        st[size] = a;
        size++;
        return true;
    }
    int pop(){
        if (size == 0) {
            std::cout << "Stack is empty. Return 0 !" << std::endl;
            return 0; // не придумал что можно вывести, т.к. функция должна в любом случае что-то вернуть поэтому вернул 0 и вывел об этом предупреждение
        }
        size--; // сначала уменьшаем size и теперь size стал равен индексу извлекаемого элемента
        int tmp = st[size];
        st[size] = 0;
        return tmp;
    }
    void print(){
        if (size == 0) {
            std::cout << "()" << std::endl;
            return;
        }
        std::cout << "(";
        for (int i = 0; i < size; i++) {
            std::cout << " " << st[i];
        }
        std::cout << " )" << std::endl;
    }
};

int main(){
// 1 task
    std::cout << "1 Task:" << std::endl;
    Power test;
    test.calculate();
    test.set(2, 3);
    test.calculate();
    std::cout << std::endl;
    Power test2(4, 2);
    test2.calculate();
    test2.set(5, 2);
    test2.calculate();
    std::cout << std::endl;
// 2 task
    std::cout << "2 Task:" << std::endl;
    RGBA rt;
    rt.print();
    RGBA rt2(2, 4, 6, 8);
    rt2.print();
    std::cout << std::endl;
//3 task
    std::cout << "3 Task:" << std::endl;
    Stack stack;
    stack.reset();
    stack.print();
    stack.pop();
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    std::cout << std::endl;
    return 0;
}
