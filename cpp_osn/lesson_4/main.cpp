#include <iostream>

using namespace std;

int main()
{
/* --------------- Задание №1 --------------- */
    int a = 11, b = 9;
    if ((a + b) >= 10 && (a + b <= 20)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    if ((a + b) >= 10 && (a + b <= 20)) cout << "true" << endl; // вот тут не знаю будет так правильно или нет? (правильно так записывать?)
    else cout << "false" << endl;                               //

    cout << ((a + b) >= 10 && (a + b <= 20)) << endl; // либо так

    bool p = ((a + b) >= 10 && (a + b <= 20)); // либо чуть "красивее" так
    cout << p << endl;

/* --------------- Задание №2 --------------- */

   int num = 4;
   bool pr = true;
   for (int i = 2; i < num; i++) if (!(num % i)) pr = false;

   cout << pr << endl;

/* --------------- Задание №3 --------------- */
    // Не совсем понял условие, если обе переменные должны быть одновременно равны сами по себе 10, то так:
    const int x = 10, y = 8;
    if ((x == 10 && y == 10) || ((x + y) == 10)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    // Если только одна из них, либо их сумма то так:
    if (x == 10 || y == 10 || (x + y) == 10) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

/* --------------- Задание №4 --------------- */

    int year = 2000;
    if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }


   return 0;
}
