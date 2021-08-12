#include <iostream>
#include <memory>
#include <cstdlib>
#include <string>

using namespace std;

// 1 task
template<typename T>
T div (T a, T b) {
    if (b == 0.0) throw "DivisionByZero";
    return a / b;
}

// 2 task
class Ex {
    double x;
public:
    Ex(double mx);
    double get() const;
};

Ex::Ex(double mx) : x(mx) {}
double Ex::get() const { return x; }

class Bar {
    double y;
public:
    Bar();
    double get() const;
    void set(double a);
};

Bar::Bar() : y(0.0) {}
double Bar::get() const { return y; }
void Bar::set(double a) {
    if ((y + a) > 100) throw Ex(a * y);
    y = a;
}

// 2 task
void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system ("clear");
#endif
}

class OffTheField {
private:
    string m_error, d;
    int x, y;
public:
    OffTheField(string error, string md, int mx, int my) : m_error(error), d(md), x(mx), y(my) { }
    const char* getError() {
        m_error += " Coords: (" + std::to_string(x) + ", " + std::to_string(y) + "). Direction - " + d;
        return m_error.c_str();
    }
};

class IllegalCommand {
private:
    string m_error;
    char d;
public:
    IllegalCommand(string error, char md) : m_error(error), d(md) { }
    const char* getError() {
        std::string s1{d};
        m_error += "You entered direction - " + s1;
        return m_error.c_str();
    }
};

class Robot {
    int fX = 10;
    int fY = 10;
    int x = 0;
    int y = 0;
public:
    Robot();
    Robot(int mx, int my);
    void print() const;
    void printPole () const;
    void move(char d);
};
Robot::Robot(int mx, int my) : x(mx), y(my) {};
Robot::Robot() : x(0), y(0) {};
void Robot::print() const{
    std::cout << "Coords: (" << x << ", " << y << ")" << std::endl;
}
void Robot::printPole() const{
    clear_screen();
    print();
    for (int i = 0; i < fY; ++i) {
        for (int k = 0; k < fX; ++k) {
            if (i == y && k == x) {
                std::cout << "R ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
}
void Robot::move(char d) {
    switch (d) {
    case 'a':
        if (x == 0) throw OffTheField("Out of field.", "LEFT", x, y);
        --x;
        break;
    case 'd':
        if (x == (fX - 1)) throw OffTheField("Out of field.", "RIGHT", x, y);
        ++x;
        break;
    case 'w':
        if (y == 0) throw OffTheField("Out of field.", "UP", x, y);
        --y;
        break;
    case 's':
        if (y == (fY - 1)) throw OffTheField("Out of field.", "DOWN", x, y);
        ++y;
        break;
    default:
        throw IllegalCommand("IllegalCommand. " , d);
        break;
    }
}

int main(){
    std::cout << "***************" << std::endl;
// 1 task
    std::cout << "Task 1:" << std::endl << "--------" << std::endl;
    double a, b;
    std::cout << "Enter two number: ";
    std::cin >> a >> b;
    try {
        std::cout << a << " / " << b << " = " << div(a, b) << std::endl;
    }
    catch (const char* exception) {
        cerr << "Error: " << exception << endl;
    }
    std::cout << "***************" << std::endl;
// 2 task
    std::cout << "Task 2:" << std::endl << "--------" << std::endl;
    Bar y;
    double n;
    while (true) {
        try {
            std::cout << "Enter number: ";
            std::cin >> n;
            if (n == 0) break;
            y.set(n);
            std::cout << "** " << y.get() << " **" << std::endl;
        }
        catch (Ex &b) {
            cerr << "Error 2: " << b.get() << endl;
        }
    }
    std::cout << y.get() << std::endl;
    std::cout << "***************" << std::endl;
// 3 task
    char vD;
    Robot r(1, 2);
    r.printPole();
    while (true) {
        try {
            std::cout << "Enter direction (w-up, s-down, a-left, d-rigth, e - exit): ";
            std::cin >> vD;
            if (vD == 'e') break;
            r.move(vD);
            r.printPole();
        }
        catch (IllegalCommand &IC) {
            cerr << "Error: " << IC.getError() << endl;
        }
        catch (OffTheField &OTF) {
            cerr << "Error: " << OTF.getError() << endl;
        }
    }

    return 0;
}
