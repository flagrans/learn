#include <iostream>
#include <iomanip>
#include <string>
#include <mutex>
#include <thread>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <algorithm>
#include <array>
#include <random>

using namespace std;

std::random_device rd;
std::mt19937_64 random2(rd());

void cls(){
    system("cls||clear");
}

//Task 1
//Не совсем понял задание, поэтому вариант №1 просто в лоб через функцию...
mutex m;

void v1cout(char const * const s, int n) {
    m.lock();
    cout << s << n << endl;
    m.unlock();
}
void funcV1(int n){
    v1cout("Start Thread - ", n);
    this_thread::sleep_for(1s);
    v1cout("Stop Thread - ", n);
}

// Вариант 2
static mutex _m;

class pcout : public ostringstream {
public:
    ~pcout() {
        lock_guard<mutex> guard(_m);
        cout << this->str();
    }
};

void f(int n){
    pcout() << "Start Thread - " << n << endl;
    this_thread::sleep_for(500ms);
    pcout() << "Stop Thread - " << n << endl;
}

// Task 2

void isPrimeV(vector<int> & v, int n) {
    if (n%2 == 0) return;
    for(int i = 3; i < n; i+=2) {
        if (n%i == 0) return;
    }
    v.push_back(n);
}

void nPrime(vector<int> & v, int in) {
    int i = 3;
    while(v.size() < (size_t)in) {
        isPrimeV(v, i);
        i +=2;
    }
}

// Task 3

mutex x;

void putV(vector<int> & v) {
    while(v.size()) {
        this_thread::sleep_for(700ms);
        lock_guard<mutex>{x};
        v.push_back((random2()%100000)/300);
    }
}

void takeV(vector<int> & v) {
    while(v.size()) {
        this_thread::sleep_for(500ms);
        lock_guard<mutex>{x};
        sort(v.begin(), v.end());
        v.pop_back();
    }
}

int main() {
// Task 1
    {
        std::cout << "********** Task 1 **********" << std::endl;

        std::cout << "Variant 1:" << std::endl;

        thread th1(funcV1, 1);
        thread th2(funcV1, 2);
        th1.join();
        th2.join();
        std::cout << "------------------" << std::endl;

        std::cout << "Variant 2:" << std::endl;

        thread th3(f, 3);
        thread th4(f, 4);
        th3.join();
        th4.join();

        for(int i = 1; i < 10; ++i) {
            thread th3(f, 3);
            thread th4(f, 4);
            thread th1(f, 4);
            thread th2(f, 4);
            thread th13(f, 3);
            thread th14(f, 4);
            thread th11(f, 4);
            thread th12(f, 4);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th11.join();
            th12.join();
            th13.join();
            th14.join();
        }

        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }

//Task 2
    {
        std::cout << "********** Task 2 **********" << std::endl;

        int n;
        cout << "Enter n int number (0 for stop): ";
        cin >> n;
        cls();
        while(n != 0) {
            vector<int> v = {2};
            thread th(nPrime, ref(v), n);
            th.detach();
// Закомментирован вывод прогресса в виде нахождения текущего числа от 1 до N
//            while(v.size() < (size_t)n) {
//                cout << "Progress: " << v.size();
//                cls();
//            }
//            cout << "Progress: " << v.size() << endl;
//            cout << "Prime number #" << n << " = " << v.back() << endl;
// Второй вид отображения в % отношении
            while(v.size() < (size_t)n) {
                int pr = 100*v.size()/n;
                int k = 0.26 * pr;
                array<char, 26> ach;
                for(int i = 0; i < 26; ++i) {
                    if(i < k) ach[i] = '=';
                    else ach[i] = ' ';
                }
                cout << "Progress: [";
                for(int i = 0; i < 13; ++i) cout << ach[i];
                cout << setw(3) << setfill('0') << pr << "%";
                for(int i = 13; i < 26; ++i) cout << ach[i];
                cout << "]";
                cls();
            }
            cout << "Progress: [=============100%=============]" << endl;
            cout << "Prime number #" << n << " = " << v.back() << endl;
            cout << endl << "Enter n int number (0 for stop): ";
            cin >> n;
            cls();
        }
    }

// Task 3
    {
        std::cout << "********** Task 3 **********" << std::endl;

        int i = 0;
        cout << "Enter start number in vector: ";
        cin >> i;
        std::vector<int> v(i);
        std::generate(v.begin(), v.end(), [](){return ((random2()%100000)/300);});

        thread hoz(putV, ref(v));
        thread vor(takeV, ref(v));
        hoz.detach();
        vor.detach();

        while(v.size()) {
            cout << "Numbers in vector: " << v.size() << endl;
            for(int i = 0; (size_t)i < v.size(); ++i) cout << "*";
            cout << endl;
            cls();
        }

        std::cout << "Vector is empty!" << std::endl;
        std::cout << std::endl << std::endl;
    }
    //cls();

    return 0;
}

