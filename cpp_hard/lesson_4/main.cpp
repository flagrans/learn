#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

std::random_device rd;
std::mt19937_64 random2(rd());

void printVecInt(const std::vector<int> &v) {
    for (const auto &i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

template<typename Container>
void printContainer(const Container &v) {
    for (const auto &i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

// Task 1

bool insert_sorted(std::vector<int> &v, int n) {
    if (*v.begin() < *(v.end()-1)) {
        auto it = std::lower_bound(v.begin(), v.end(), n);
        v.insert(it, n);
        return true;
    } else {
        auto it = std::lower_bound(v.rbegin(), v.rend(), n);
        v.insert(it.base(), n);
    }
    return true;
}

// не поддерживает array - т.к. у array мы не можем увеличить размер.
template<typename Container, typename T>
bool insert_sorted(Container &v, T n) {
    std::vector<T> temp; // используем временный контейнер для осуществления операции вставки
    // (т.к. у forward_list, list, deque, vector разные методы и некоторые отсутствуют)
    for (const auto &i: v) { // копируем то же через range base для универсальности (т.к. у forward_list отсутствует метод size)
        temp.push_back(i);
    }

    if (*temp.begin() < *(temp.end()-1)) {
        auto it = std::lower_bound(temp.begin(), temp.end(), n);
        temp.insert(it, n);
    } else {
        auto it = std::lower_bound(temp.rbegin(), temp.rend(), n);
        temp.insert(it.base(), n);
    }

    v.clear();
    v.resize(temp.size());
    std::copy(temp.begin(), temp.end(), v.begin());

    return true;
}
// Если работаем только с vector, deque и list, то все немного упрощается
template<typename Container, typename T>
bool insert_sorted2(Container &v, T n) {
     if (v.front() < v.back()) {
        auto it = std::lower_bound(v.begin(), v.end(), n);
        v.insert(it, n);
    } else {
        auto it = std::lower_bound(v.rbegin(), v.rend(), n);
        v.insert(it.base(), n);
    }
    return true;
}

// Task 2



int main() {
// Task 1
    {
        std::cout << "********** Task 1 **********" << std::endl;
        std::cout << "vector<int> func:" << std::endl;

        std::vector<int> v(20);
        std::generate(v.begin(), v.end(), [](){return ((random2()%10000)/300);});
        std::sort(v.begin(), v.end());

        printVecInt(v);
        std::cout << "Insert 15:" << std::endl;
        insert_sorted(v, 15);
        printVecInt(v);
        std::cout << "Reverse:" << std::endl;
        std::sort(v.rbegin(), v.rend());
        printVecInt(v);
        std::cout << "Insert 27:" << std::endl;
        insert_sorted(v, 27);
        printVecInt(v);
        std::cout << "--------------------------" << std::endl;

        std::list<int> ll = {2, 33, 66, 77, 99};
        std::forward_list<double> fl = {1.1, 5.5, 9.3, 16.9, 24.3};
        std::deque<int> de = {1, 5, 8, 12, 14};
        std::vector<double> vv = {1.1, 5.5, 9.3, 16.9, 24.3};

        std::cout << "Template func:" << std::endl;
        std::cout << "list<int>:" << std::endl;
        printContainer(ll);
        std::cout << "Insert 44:" << std::endl;
        insert_sorted(ll, 44);
        printContainer(ll);
        std::cout << "Reverse:" << std::endl;
        ll.reverse();
        printContainer(ll);
        std::cout << "Insert 68:" << std::endl;
        insert_sorted(ll, 68);
        printContainer(ll);
        std::cout << "--------------------------" << std::endl;

        std::cout << "forward_list<double>:" << std::endl;
        printContainer(fl);
        std::cout << "Insert 6.7:" << std::endl;
        insert_sorted(fl, 6.7);
        printContainer(fl);
        std::cout << "Reverse:" << std::endl;
        fl.reverse();
        printContainer(fl);
        std::cout << "Insert 11.3:" << std::endl;
        insert_sorted(fl, 11.3);
        printContainer(fl);
        std::cout << "--------------------------" << std::endl;

        std::cout << "deque<int>:" << std::endl;
        printContainer(de);
        std::cout << "Insert 6:" << std::endl;
        insert_sorted(de, 6);
        printContainer(de);
        std::cout << "Reverse:" << std::endl;
        std::sort(de.rbegin(), de.rend());
        printContainer(de);
        std::cout << "Insert 15:" << std::endl;
        insert_sorted(de, 15);
        printContainer(de);
        std::cout << "--------------------------" << std::endl;

        std::cout << "vector<double>:" << std::endl;
        printContainer(vv);
        std::cout << "Insert 0.5:" << std::endl;
        insert_sorted(vv, 0.5);
        printContainer(vv);
        std::cout << "Reverse:" << std::endl;
        std::sort(vv.rbegin(), vv.rend());
        printContainer(vv);
        std::cout << "Insert 15.3:" << std::endl;
        insert_sorted(vv, 15.3);
        printContainer(vv);
        std::cout << "--------------------------" << std::endl;

        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }
// Task 2
    {
        std::cout << "********** Task 2 **********" << std::endl;

        std::vector<double> a(100);
        std::generate(a.begin(), a.end(), [](){return ((double)(random2()%10000)/300);});
        std::cout << "vector<double> a:" << std::endl;
        printContainer(a);
        std::cout << std::endl;
        std::vector<int> b(100);
        std::copy(a.begin(), a.end(), b.begin());
        std::cout << "vector<int> b:" << std::endl;
        printContainer(b);

        // Подсчет ошибки с использованием одного вектора
        double sum = std::accumulate(a.begin(), a.end(), 0.0,
                        [](double x, double y){double t; return x + pow(modf(y, &t), 2.0);});

        std::cout << std::endl << "Error 1 vector: " << sum << std::endl;

        // Подсчет ошибки с использованием 2-х векторов
        double sum2 = std::inner_product(a.begin(), a.end(), b.begin(), 0.0,
                                       std::plus<double>(), [](double x, int y){return pow((x-y), 2);});
        std::cout << std::endl << "Error 2 vector: " << sum2 << std::endl;

        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }
    return 0;
}
