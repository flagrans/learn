#include <iostream>
#include <cstdarg>

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


/****************** Задание №1 **********************/
void invert(bool* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = !arr[i];
    }
}
/****************** Задание №2 **********************/
void initial(int* arr, int size) {
    int init_num = 1;
    for(int i = 0; i < size; ++i) {
        arr[i] = init_num;
        init_num += 3;
    }
}
/****************** Задание №3 **********************/
bool checkBalance(int* arr, int size) {
    if (size == 1) return false;        // Предположим что при одном элементе в массиве необходимо возвращать false
    for (int i = 0; i < (size-1); ++i) {
        int lv = 0, rv = 0;
        for (int k = 0; k <= i; ++k) {
            lv += arr[k];
        }
        for (int k = i + 1; k < size; ++k) {
            rv += arr[k];
        }
        if ( lv == rv) return true;
    }
    return false;
}
/****************** Задание №4 **********************/
void shiftArray(int* arr, int size, int shift) {
    int temp[size];
    for(int i = 0; i < size; ++i) { // Здесь копируется исходный массив во временный
        temp[i] = arr[i];           // по другому не придумал как скопировать
    }
    int t;

    if(shift > 0) {
        if (shift
                > size) shift -= size; // Если введен сдвиг больше размера массива
        t = size - shift;
    } else if(shift < 0) {
        if (std::abs(shift) > size) shift += size; // Если введен сдвиг больше размера массива
        t = std::abs(shift);
    } else {
        return;
    }

    for(int i = 0; i < size; ++i) {
        if(t == size) t = 0;
        arr[i] = temp[t];
        t++;
    }
}

/****************** Задание №5 **********************/
void invert(int size, ...) { // Перегруженная функция invert, для 5-го задания
    va_list vl;
    va_start(vl, size);
    for (int i = 0; i < size; ++i) {
        std::cout << !va_arg(vl, int) << " "; // Тут если в va_arg(vl, int) передать bool то компилятор ругается, вопрос почему?
    }                                         // А с int хоть и работает трюк с отрицанием (!), но как-то не правильно получается
    std::cout << std::endl;                   // Хотелось бы прояснить этот момент
    va_end(vl);
}

int main() {
/****************** Задание №1 **********************/
    bool arr[] = {0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1};
    int size = 12;
    printArr(arr, size);    // Выводим изначальный массив
    invert(arr, size);      // Вызываем функцию инверсии
    printArr(arr, size);    // Выводим измененный массив
    std::cout << "*************************************************************" << std::endl;
/****************** Задание №2 **********************/
    int ar[8];
    initial(ar, 8);  // Вызываем функцию заполнения массива
    printArr(ar, 8); // Выводим заполненный массив
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
    std::cout << checkBalance(arr1, sz1) << " | ";
    std::cout << checkBalance(arr2, sz2) << " | ";
    std::cout << checkBalance(arr3, sz3) << " | ";
    std::cout << checkBalance(arr4, sz4) << " | ";
    std::cout << checkBalance(arr5, sz5) << " | ";
    std::cout << checkBalance(arr6, sz6) << " | ";
    std::cout << checkBalance(arr7, sz7) << " | ";
    std::cout << checkBalance(arr8, sz8) << std::endl;
    std::cout << "*************************************************************" << std::endl;
/****************** Задание №4 **********************/
    int size5 = 6;                  // Размер массива
    int ar5[] = {1, 7, 8, 9, 1, 0};
    int shift = -10;                // Сдвиг массива
    printArr(ar5, size5);           // Вывод исходного массива
    shiftArray(ar5, size5, shift);
    printArr(ar5, size5);           // Вывод сдвинутого массива
    std::cout << "*************************************************************" << std::endl;
/****************** Задание №5 **********************/
    std::cout << "0 1 1 0 1 1 0 0 0 1 1 1" << std::endl;
    invert(12, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1);
    std::cout << "*************************************************************" << std::endl;
/****************** Задание №6 **********************/

    return 0;
}
