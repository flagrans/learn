#include <iostream>
#include <cstdarg>
#include "invert.h"
#include "initial.h"
#include "checkbalance.h"
#include "shiftarray.h"
#include "invert2.h"

using namespace mySpace;
// Здесь мы использовали пространство имен mySpace, чтобы  вместо fn1 = mySpace::invert; указывать просто - fn1 = invert;

void printArr(int* arr, int size) { // Функция вывода массива в стандартный поток
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void printArr(bool* arr, int size) { // Перегруженная функция вывода массива в стандартный поток
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void (*fn1)(bool* arr, int size);
void (*fn2)(int* arr, int size);
bool (*fn3)(int* arr, int size);
// Здесь мы часть указателй объявили вне функции main(), а часть внутри нее
// и как мы видим работает в обоих вариантах, как будет правильнее?

int main() {
        fn1 = invert;
        fn2 = mySpace::initial; // здесь mySpace:: излишне т.к. мы объявили об использовании пространства имен mySpace выше
        fn3 = checkBalance;
        void (*fn4)(int* arr, int size, int shift);
        fn4 = shiftArray;
        void (*fn5)(int size, ...); // нельзя использовать один и тот же указатель на перегруженные функции...
        fn5 = invert;
        // так же как я понял что массив указателей можно использовать на функции только
        //  с одинаковыми типами параметров и возвращаемых значений, что при данных функциях невозможно

/****************** Задание №1 **********************/
        bool arr[] = {0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1};
        int size = 12;
        printArr(arr, size);
        fn1(arr, size);
        printArr(arr, size);
        std::cout << "*************************************************************" << std::endl;
/****************** Задание №2 **********************/
        int ar[8];
        fn2(ar, 8);
        printArr(ar, 8);
        std::cout << "*************************************************************" << std::endl;
/****************** Задание №3 **********************/
            int arr1[] = {1, 5, 8, 4, 0, 10};
            int sz1 = 6;
            int arr2[] = {1, 5, 8, 4, 2, 10};
            int sz2 = 6;
            int arr3[] = {1, 5, 8, 2, 10};
            int sz3 = 5;
            int arr4[] = {1, 8, 3, 2, 4};
            int sz4 = 5;
            int arr5[] = {1};
            int sz5 = 1;
            int arr6[] = {1, 5};
            int sz6 = 2;
            int arr7[] = {3, 3};
            int sz7 = 2;
            int arr8[] = {2, 8, 6, 6, 22};
            int sz8 = 5;
            std::cout << fn3(arr1, sz1) << " | ";
            std::cout << fn3(arr2, sz2) << " | ";
            std::cout << fn3(arr3, sz3) << " | ";
            std::cout << fn3(arr4, sz4) << " | ";
            std::cout << fn3(arr5, sz5) << " | ";
            std::cout << fn3(arr6, sz6) << " | ";
            std::cout << fn3(arr7, sz7) << " | ";
            std::cout << fn3(arr8, sz8) << std::endl;
            std::cout << "*************************************************************" << std::endl;
/****************** Задание №4 **********************/
            int size5 = 6;
            int ar5[] = {1, 7, 8, 9, 1, 0};
            int shift = -10;
            printArr(ar5, size5);
            fn4(ar5, size5, shift);
            printArr(ar5, size5);
            std::cout << "*************************************************************" << std::endl;
/****************** Задание №5 **********************/
            std::cout << "0 1 1 0 1 1 0 0 0 1 1 1" << std::endl;
            fn5(12, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1);
            std::cout << "*************************************************************" << std::endl;
    return 0;
}
