#include <iostream>

// 1 task
template <typename T>
class Pair1 {
    T _first{};
    T _second{};
public:
    Pair1 (T f_first, T f_second) : _first(f_first), _second(f_second) { }
    T first () const { return _first; }
    T second () const { return _second; }
};

// 2 task
template <typename T1, typename T2>
class Pair {
    T1 _first{};
    T2 _second{};
public:
    Pair(T1 f_first, T2 f_second) : _first(f_first), _second(f_second) { }
    T1 first() const { return _first; }
    T2 second() const { return _second; }
};

// 3 task
template <typename T2>
class Pair<std::string, T2> {
    std::string _first{};
    T2 _second{};
public:
    Pair(std::string f_first, T2 f_second) : _first(f_first), _second(f_second) { }
    std::string first() const { return _first; }
    T2 second() const { return _second; }
};

template <typename T2>
class StringValuePair : public Pair<std::string, T2> {
public:
    StringValuePair(std::string f_first, T2 f_second) : Pair<std::string, T2>(f_first, f_second) { }
};
int main(){
    std::cout << "***************" << std::endl;
// 1 task
    std::cout << "Task 1:" << std::endl << "-------" << std::endl;

    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    std::cout << "***************" << std::endl;
// 2 task
    std::cout << "Task 2:" << std::endl << "-------" << std::endl;

    Pair<int, double> p1_1(6, 7.8);
    std::cout << "Pair: " << p1_1.first() << ' ' << p1_1.second() << '\n';
    const Pair<double, int> p2_1(3.4, 5);
    std::cout << "Pair: " << p2_1.first() << ' ' << p2_1.second() << '\n';

    std::cout << "***************" << std::endl;
// 3 task
    std::cout << "Task 3:" << std::endl << "-------" << std::endl;

    Pair<std::string, int> p3_1("Test", 5);
    std::cout << "Pair: " << p3_1.first() << ' ' << p3_1.second() << '\n';
    Pair<std::string, double> p3_2("Test", 3.5);
    std::cout << "Pair: " << p3_2.first() << ' ' << p3_2.second() << '\n';

    std::cout << "-------" << std::endl;

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    std::cout << "***************" << std::endl;

    return 0;
}
