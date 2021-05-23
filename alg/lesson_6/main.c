#include <stdio.h>
#include <math.h>

int sch = 0;

int** init2Array(int** arr, int row, int col) {               // Инициализация двумерного массива
    arr = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; i++){
        *(arr + i) = (int*) calloc(sizeof(int), col);
    }
    return arr;

}

void print2Array(int ** arr, int row, int col) {              // Вывод двумерного массива
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
            printf("%4d", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void fill2Array(int ** arr, int row, int col) {              // Заполнение двумерного массива
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            *((*(arr + i)) + j) = 8;
        }
    }
}

void fill2Random(int ** arr, int row, int col, int border) { // Заполнение двумерного массива рандомом
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            *((*(arr + i)) + j) = rand() % border;
        }
    }
}

void swap(int *a, int *b){ // swap 2-х int
    int t = *a;
    *a = *b;
    *b = t;
}
void sortBuble(int* arr, int len) {                         // Сортировка пузырьком одномерного массива
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - 1; j++){
            sch++;                                          // учитываем операции при sort2Array1
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}


void sort2Array1(int ** arr, const int row, const int col){ // Сортировка двумерного массива (сливаем в одномерный, соритруем,
    int size = col * row;                                   // сливаем обратно). Количество операций ненамного больше получается.
    int tmp[size];
    int st = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
            sch++;                                          // учитываем операции
            tmp[st] = *(*(arr + i) + j);
            st++;
        }
    }
    sortBuble(tmp, size);
    st = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
            sch++;                                         // учитываем операции
            *((*(arr + i)) + j) = tmp[st];
            st++;
        }
    }
}

void sort2Array2(int ** arr, const int row, const int col){
    sch = 0;                                               // Счетчик для замера "кол-ва операций"
    int sk = row * col -1;
    for (int k = 0; k < sk; k++){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) {
                sch++;                                     // учитываем операции
                if (j + 1 == col && i + 1 == col) {        // Чую что здесь должно быть проще, но не могу понять как...(почему )
                    continue;
                } else if (j + 1 == col) {
                    if (arr[i][j] > arr[i + 1][0])
                        swap(&arr[i][j], &arr[i + 1][0]);
                } else {
                    if (arr[i][j] > arr[i][j + 1])
                        swap(&arr[i][j], &arr[i][j + 1]);
                }
            }
        }
    }
}

void sort2Array3(int ** arr, const int row, const int col){ // Попытка оптимизации sort2Array2 - избавляемся от лишних операций
    sch = 0;                                                // Насколько вообще это применимо? И есть ли смысл таких оптимизаций?
    int sk = row * col -1;
    for (int k = 0; k < sk; k++){
        int f = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) {
                if (f > sk -k) continue;                   // Если условие выполняется, то дальше идти незачем, там все отсортировано.
                f++;
                sch++;                                     // учитываем операции
                if (j + 1 == col && i + 1 == col) {
                    continue;
                } else if (j + 1 == col) {
                    if (arr[i][j] > arr[i + 1][0])
                        swap(&arr[i][j], &arr[i + 1][0]);
                } else {
                    if (arr[i][j] > arr[i][j + 1])
                        swap(&arr[i][j], &arr[i][j + 1]);
                }
            }
        }
    }
}

void TPK(){
    float p[11];
    printf("Enter 11 numbers: ");
    for (int i = 0; i < 11; i++)
        scanf("%f", &p[i]);

    float p2[11];
    for (int i = 0; i < 11; i++)
        p2[i] = p[10 - i];

    for (int i = 0; i < 11; i++){
        if((sqrt(fabs(p2[i])) + 5 * pow(p2[i], 3)) > 400)
            printf("Index %d > 400\n", i);}
}

void TPK2(){ // Здесь записываем в массив сразу в инвертированном порядке
    float p[11];
    printf("Enter 11 numbers: ");
    for (int i = 0; i < 11; i++)
        scanf("%f", &p[10-i]);

    for (int i = 0; i < 11; i++)
        if((sqrt(fabs(p[i])) + 5 * pow(p[i], 3)) > 400)
            printf("Index %d > 400\n", i);
}

int main() {
    // Первое задание
    const int sizeX = 10;
    const int sizeY = 10;
    int** arr = init2Array(arr, sizeX, sizeY);

    fill2Random(arr, sizeX, sizeY, 100);
    print2Array(arr, sizeX, sizeY);
    printf("\n");
    sort2Array1(arr, sizeX, sizeY);
    print2Array(arr, sizeX, sizeY);
    printf("\nСчетчик операций = %d\n\n\n", sch);


    fill2Random(arr, sizeX, sizeY, 100);
    print2Array(arr, sizeX, sizeY);
    printf("\n");
    sort2Array2(arr, sizeX, sizeY);
    print2Array(arr, sizeX, sizeY);
    printf("\nСчетчик операций = %d\n\n\n", sch);

    fill2Random(arr, sizeX, sizeY, 100);
    print2Array(arr, sizeX, sizeY);
    printf("\n");
    sort2Array3(arr, sizeX, sizeY);
    print2Array(arr, sizeX, sizeY);
    printf("\nСчетчик операций = %d\n\n\n", sch);

    // Второе задаине
    TPK();

    return 0;
}
