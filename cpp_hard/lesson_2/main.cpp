#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <fstream>

class Timer
{
private:
      using clock_t = std::chrono::high_resolution_clock;
      using second_t = std::chrono::duration<double, std::ratio<1> >;

      std::string m_name;
      std::chrono::time_point<clock_t> m_beg;
      double elapsed() const
      {
            return std::chrono::duration_cast<second_t>(clock_t::now() -m_beg).count();
      }

public:
      Timer() : m_beg(clock_t::now()) { }
      Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

      void start(std::string name) {
            m_name = name;
            m_beg = clock_t::now();
      }
      void print() const {
            std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
      }
};

//Timer timer("SortPointers");
//timer.print();

// Task 1
template <typename T>
void Swap(T* &p1, T* &p2) {
    T* temp = p1;
    p1 = p2;
    p2 = temp;
}

// Task 2

template <typename T>
void SortPointers(std::vector<T*> &v) {
    std::sort(v.begin(), v.end(), [](const T* lhs, const T* rhs){
        return *lhs < *rhs;
    });
}

int main() {
// Task 1
{
    std::cout << "Task 1" << std::endl;
    int a = 1;
    int b = 2;
    int* p1 = &a;
    int* p2 = &b;

    std::cout << "address a: " << &a << std::endl;
    std::cout << "address pointer p1: " << p1 << std::endl;
    std::cout << "value pointer p1: " << *p1 << std::endl;

    std::cout << "address b: " << &b << std::endl;
    std::cout << "address pointer p2: " << p2 << std::endl;
    std::cout << "value pointer p2: " << *p2 << std::endl;

    Swap(p1, p2);

    std::cout << "*********************************" << std::endl;

    std::cout << "address a: " << &a << std::endl;
    std::cout << "address pointer p1: " << p1 << std::endl;
    std::cout << "value pointer p1: " << *p1 << std::endl;

    std::cout << "address b: " << &b << std::endl;
    std::cout << "address pointer p2: " << p2 << std::endl;
    std::cout << "value pointer p2: " << *p2 << std::endl;


    double k = 1.1;
    double l = 2.2;
    double* pd1 = &k;
    double* pd2 = &l;

    std::cout << "address k: " << &k << std::endl;
    std::cout << "address pointer pd1: " << pd1 << std::endl;
    std::cout << "value pointer pd1: " << *pd1 << std::endl;

    std::cout << "address l: " << &l << std::endl;
    std::cout << "address pointer pd2: " << pd2 << std::endl;
    std::cout << "value pointer pd2: " << *pd2 << std::endl;

    Swap(pd1, pd2);

    std::cout << "*********************************" << std::endl;

    std::cout << "address k: " << &k << std::endl;
    std::cout << "address pointer pd1: " << pd1 << std::endl;
    std::cout << "value pointer pd1: " << *pd1 << std::endl;

    std::cout << "address l: " << &l << std::endl;
    std::cout << "address pointer pd2: " << pd2 << std::endl;
    std::cout << "value pointer pd2: " << *pd2 << std::endl;
    std::cout << std::endl << std::endl;
}

// Task 2
{
    std::cout << "Task 2" << std::endl;
    std::vector<int*> v;
    int a = 7;
    int b = 3;
    int c = 5;
    int* p = &a;
    v.push_back(p);
    p = &b;
    v.push_back(p);
    p = &c;
    v.push_back(p);

    for (auto x:v) {
        std::cout << x << " ";
    }
    std::cout << std::endl << "************" << std::endl;

    SortPointers(v);

    for (auto x:v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl << std::endl;
}

// Task 3
{
    std::cout << "Task 3" << std::endl;

    char ch;
    int count = 0;
    const std::vector<char> v = {'A','a','E','e','I','i','O','o','U','u','Y','y'};
    std::ifstream in("./wap.txt", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "File not open!" << std::endl;
    } else {
        // Method #1
        std::cout << "Method #1" << std::endl;

        in.clear(std::ios_base::eofbit);
        in.seekg(0, std::ios::beg);

        Timer timer1("Time");

        count = std::count_if(
            std::istreambuf_iterator<char>(in),
            std::istreambuf_iterator<char>(),
            [v](const char &x) {
            if (std::find(v.begin(), v.end(), x) != v.end()) {return true;}
            else {return false;}
        }
        );
        timer1.print();

        std::cout << "Total: " << count << std::endl;
        //End method #1

        // Method #2
        std::cout << "Method #2" << std::endl;
        in.clear(std::ios_base::eofbit);
        in.seekg(0, std::ios::beg);

        Timer timer2("Time");

        count = std::count_if(
            std::istreambuf_iterator<char>(in),
            std::istreambuf_iterator<char>(),
            [v](const char &x) {
            for(auto i:v) {
                if(x == i) return true;
            }
            return false;
        }
        );

        timer2.print();

        std::cout << "Total: " << count << std::endl;
        //End method #2

        // Method #3
        std::cout << "Method #3" << std::endl;
        count = 0;
        in.clear(std::ios_base::eofbit);
        in.seekg(0, std::ios::beg);

        Timer timer3("Time");

        while (!in.eof()) {
            ch = in.get();
            auto result = std::find(v.begin(), v.end(), ch);
            if (result != v.end()) ++count;
        }
        timer3.print();

        std::cout << "Total: " << count << std::endl;
        //End method #3

        // Method #4
        std::cout << "Method #4" << std::endl;
        count = 0;
        in.clear(std::ios_base::eofbit);
        in.seekg(0, std::ios::beg);

        Timer timer4("Time");

        while (!in.eof()) {
            ch = in.get();
            for(auto i:v) {
                if(ch == i) ++count;
            }
        }
        timer4.print();

        std::cout << "Total: " << count << std::endl;
        //End method #4
    }
    in.close();
}
    return 0;
}
