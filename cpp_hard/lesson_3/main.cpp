#include <iostream>
#include <chrono>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

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

void slist(std::list<double> &l) {
    double sum = 0;
    for(const auto i:l) sum += i;
    l.push_back(sum / l.size());
}

// Task 2

void printMatrix(const std::vector<std::vector<int>> &v) {
    for(const auto &i:v) {
        for (auto k:i) {
            std::cout << k << ' ';
        }
        std::cout << std::endl;
    }
}

//std::vector<std::vector<int>> minor(const std::vector<std::vector<int>> &v, int n) {
//    std::vector<std::vector<int>> result;
//    for(size_t i = 1; i < v.size(); ++i) {
//        std::vector<int> temp;
//        for(size_t k = 0; k < v.size(); ++k) {
//            if(k != (size_t)(n-1)) temp.push_back(v[i][k]);
//        }
//        result.push_back(temp);
//    }
//    //printMatrix(result);
//    return result;
//}


//int det(const std::vector<std::vector<int>> &v) {
//    int size = v.size();
//    int deter = 0;
//    if (v.size() == 1) return v[0][0];
//    for(int i = 0; i < size; ++i) {
//        int zn = 1;
//        if (i%2) zn *= -1;
//        //std::cout << v[0][i] * zn << std::endl;
//        deter += zn * v[0][i] * det(minor(v, (i + 1)));
//    }
//    return deter;
//}


// если делать функциями, то все понятно, разобрался c матрицами n-го порядка,
// но с классом сначала с инициализацией объекта проблемы были, а потом я так и не понял,
// как правильно сделать рекурсивный метод, чтобы в main не делать так m2.det(m2) (class matrix1), а просто m2.det()
// можете пролить свет на этот момент?

//class matrix {
//public:
//    matrix(){}
//    matrix(const std::initializer_list<std::vector<int>> &list) {
//        for(auto &i:list) {
//            std::vector<int> temp;
//            for (auto k:i) {
//                temp.push_back(k);
//            }
//            _v.push_back(temp);
//        }
//        _size = _v.size();
//    }
//    void print() {
//        for(const auto &i:_v) {
//            for (auto k:i) {
//                std::cout << k << ' ';
//            }
//            std::cout << std::endl;
//        }
//    }

//    int det(int j) {
//        int deter = 0;
//        if (j == 1) return _v[0][0];
//        for(int i = 0; i < j; ++i) {
//            std::vector<std::vector<int>> temp = minor(_v, i, j);
//            printMatrix(temp);
//            int zn = 1;
//            if (i%2) zn *= -1;
//            //std::cout << _v[0][i] * zn << std::endl;
//            //deter += zn * _v[_size - j][i] * det(j-1);
//        }
//        return deter;
//    }
//private:
//    std::vector<std::vector<int>> minor(std::vector<std::vector<int>> &_t, int m, int n) {
//        std::vector<std::vector<int>> result;
//        for(size_t i = 1; i < n; ++i) {
//            std::vector<int> temp;
//            for(size_t k = 0; k < n; ++k) {
//                if(k != (size_t)(m)) temp.push_back(_t[i][k]);
//            }
//            result.push_back(temp);
//        }
//        return result;
//    }
//    std::vector<std::vector<int>> _v;
//    int _size;
//};

class matrix1 {
public:
    matrix1(){}
    matrix1(const std::initializer_list<std::vector<int>> &list) {
        for(auto &i:list) {
            std::vector<int> temp;
            for (auto k:i) {
                temp.push_back(k);
            }
            _v.push_back(temp);
        }
        _size = _v.size();
    }
    void print() {
        for(const auto &i:_v) {
            for (auto k:i) {
                std::cout << k << ' ';
            }
            std::cout << std::endl;
        }
    }
    int det(matrix1 mv) {
        int deter = 0;
        if (mv._v.size() == 1) return mv._v[0][0];
        for(size_t i = 0; i < mv._v.size(); ++i) {
            int zn = 1;
            if (i%2) zn *= -1;
            deter += zn * mv._v[0][i] * det(_minor(mv, (i + 1)));
        }
        return deter;
    }
    matrix1 _minor(matrix1 mv, int n) {
        matrix1 result;
        for(size_t i = 1; i < mv._v.size(); ++i) {
            std::vector<int> temp;
            for(size_t k = 0; k < mv._v.size(); ++k) {
                if(k != (size_t)(n-1)) temp.push_back(mv._v[i][k]);
            }
            result._v.push_back(temp);
        }
        return result;
    }
private:
    std::vector<std::vector<int>> _v;
    int _size;
};


// Task 3

class myIter {
public:
    myIter(const std::vector<int> &v) : _v(v) {}
    auto begin() const {return _v.begin();}
    auto end() const {return _v.end();}
private:
    const std::vector<int> &_v;
};

int main() {
// Task 1
    {
        std::cout << "********** Task 1 **********" << std::endl;
        std::list<double> l = {1.2, 5.9, 4.7, 2.1, 9.9};

        std::cout << l.size() << std::endl;
        slist(l);
        std::cout << l.back() << std::endl;
        std::cout << l.size() << std::endl;

        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }

// Task 2
    {
        std::cout << "********** Task 2 **********" << std::endl;

        std::vector<std::vector<int>> vp1 = {{5}};
        std::vector<std::vector<int>> vp2 = {{1, 2}, {3, 4}};
        std::vector<std::vector<int>> vp3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        std::vector<std::vector<int>> vp4 = {{2, 2, 3, 3}, {5, 6, 7, 8}, {9, 1, 8, 3}, {2, 2, 6, 6}};
        std::vector<std::vector<int>> vp5 = {{15, 14, 13, 12, 11}, {22, 33, 44, 55, 66}, {23, 76, 23, 32, 76}, {44, 45, 76, 45, 35}, {21, 77, 44, 55, 52}};

        matrix1 m5 = {{15, 14, 13, 12, 11}, {22, 33, 44, 55, 66}, {23, 76, 23, 32, 76}, {44, 45, 76, 45, 35}, {21, 77, 44, 55, 52}};
        matrix1 m3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        m3.print();
        std::cout << "----------" << std::endl;
        int d = m3.det(m3);
        std::cout << d << std::endl;
        std::cout << "----------" << std::endl;
        m5.print();
        std::cout << "----------" << std::endl;
        d = m5.det(m5);
        //int d = det(vp5);
        std::cout << d << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }

// Task 3
    {
        std::cout << "********** Task 3 **********" << std::endl;

        std::vector<int> v = {1, 2, 3, 4, 5, 6};

        myIter mI(v);

        for(const auto &n : mI) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }

    return 0;
}
