#include <stdio.h>

double result = 1;
int pr = 1;
int res = 1;

void decToBinary(int n){
    if (n/2 <= 1) {
        printf("%d", n/2);
        printf("%d", n%2);
        return;
    }
    decToBinary(n/2);
    printf("%d", n%2);
}

double power (double osn, int st){
    if (st == 0) return 1;
    if (st < 0) {
        pr = 0;
        st *= -1;
    }
    result *= osn;
    if (st > 1) power(osn, st-1);
    if (pr == 0) return 1 / result;
    else return result;
}

int power2 (int osn, int st){
    if (st == 0) return 1;
    int t = 1;

    if (st > 1 && st%2 != 0) {
        t = osn;
        st = st -1;
    }

    if (st > 1 && st%2 == 0) {
        res = osn * osn;
        power2(res, st/2);
    }

    return res * t;
}

int re (const int sizeX, const int sizeY, int p[sizeX][sizeY], int x, int y){ //Вспомогательная вункция
    int pr = 0;
    if (x == 0) {
        for (int i = 0; i < y; i++) {
            if (p[i][0] == 1)
                pr = 1;
        }
    }
    if (y == 0) {
        for (int i = 0; i < x; i++) {
            if (p[0][i] == 1)
                pr = 1;
        }
    }
    return pr;
}

int routes (int x, int y, const int sizeX, const int sizeY, int p[sizeX][sizeY]) {
    if ((p[y][x] == 1) || ((p[y-1][x] == 1) && (p[y][x-1] == 1)))
        return 0;
    else if (x == 0 && re(sizeX, sizeY, p, 0, y) == 1)
        return 0;
    else if (y == 0 && re(sizeX, sizeY, p, x, 0) == 1)
        return 0;
    else if (x == 0 && y == 0)
        return 0;
    else if (x == 0 || y == 0)
        return 1;
    else
        return routes(x, y - 1, sizeX, sizeY, p) + routes(x -1, y, sizeX, sizeY, p);
}

void printPole(int *p, const int sizeX, const int sizeY) { //Функция вывода массива
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            printf("%5d", *(p + y*sizeY + x));
        }
        printf("\n");
    }
}

void initPole(int *p, const int sizeX, const int sizeY) { //Инициализируем массив 0
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            *(p + y*sizeY + x) = 0;
        }
    }
}


int main() {
    decToBinary(272);
    printf("\n");
    printf("%lf\n", power(3, 5));
    printf("%d\n", power2(3, 5));

    const int sizeX = 5;
    const int sizeY = 5;
    int p[sizeX][sizeY];
    initPole(*p, sizeX, sizeY);
    printf("Поле без препятствий:\n");
    printPole(*p, sizeX, sizeY);
    printf("\n");
    printf("Ходы короля:\n");
    for (int y = 0; y < sizeY; y++) { // При пустом поле
        for (int x = 0; x < sizeX; x++) {
            printf("%5d", routes(x, y, sizeX, sizeY, p));
        }
        printf("\n");
    }
    printf("\n");

    p[0][1] = 1; // выставляем препятствия
    p[1][1] = 1;
    p[3][3] = 1;
    p[2][4] = 1;
    printf("Поле с препятствиями:\n");
    printPole(*p, sizeX, sizeY);
    printf("\n");
    printf("Ходы короля:\n");
    for (int y = 0; y < sizeY; y++) { // А теперь попробуем с препятствиями
        for (int x = 0; x < sizeX; x++) {
            printf("%5d", routes(x, y, sizeX, sizeY, p));
        }
        printf("\n");
    }

    return 0;
}
