#include <stdio.h>
#include <math.h>

void fillRandom(int * arr, int len, int border) { // Заполнение одномерного массива рандомом
    for (int i = 0; i < len; i++){
        *(arr + i) = rand() % border;
    }
}

void printArray(int * arr, const int len) {       // Вывод одномерного массива
    for (int i = 0; i < len; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void swap(int *a, int *b){                        // swap 2-х int
    int t = *a;
    *a = *b;
    *b = t;
}

void medQBS (int * arr, int first, int last) {    // Функция нахождения медианы и перестановки с центр. эл-ом
    int med = (first + last) / 2;
    int a = arr[first];
    int b = arr[med];
    int c = arr[last];
    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        swap(&arr[first], &arr[med]);
    } else if ((c >= a && c <= b) || (c <= a && c >= b)) {
        swap(&arr[last], &arr[med]);
    }
}

void sortInsert(int * arr, int first, int last){  // Сортировка вставками
    int temp, pos;
    for (int i = first; i < last+1; i++) {
        temp = arr[i];
        pos = i -1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void qBestSort (int * arr, int first, int last) { // Улучшенная сортировка
    int len = last - first + 1;
    if (len <= 10) {
        sortInsert(arr, first, last);
    } else {
        int i = first;
        int j = last;
        int x = arr[(first + last) / 2];
        medQBS(arr, first, last);
        do {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (i < last) qBestSort(arr, i, last);
        if (first < j) qBestSort(arr, first, j);
    }
}

void bucketSort(int * arr, int len) {             // Блочная сортировка
    const int max = len;
    const int b = 10;

    int buckets[b][max+1];
    for (int i = 0; i < b; i++){
        buckets[i][max] = 0;
    }
    for (int digit = 1; digit < 1000000000; digit *= 10){
        for (int i = 0; i < max; i++){
            int d = (arr[i] / digit) % b;
            buckets[d][buckets[d][max]++] = arr[i];
        }
        int index = 0;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < buckets[i][max]; j++){
                arr[index++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

void bucketSortEven (int *arr, int len){          // Сортировка четных элементов
    int temp[len/2];
    int s = 0;
    for (int i = 1; i < len; i += 2){
        temp[s] = arr[i];
        s++;
    }
    bucketSort(temp, len/2);
    s = 0;
    for (int i = 1; i < len; i += 2){
        arr[i] = temp[s];
        s++;
    }
}


int main() {
    //Первое задание
    printf("Lesson 7.1:\n");
    const int SZ = 21;
    int arr[SZ];
    fillRandom(arr, SZ, 100);
    printArray(arr, SZ);
    qBestSort(arr, 0, SZ - 1);
    printArray(arr, SZ);

    //Второе задание
    printf("\nLesson 7.2:\n");
    int arr2[SZ];
    fillRandom(arr2, SZ, 100);
    printArray(arr2, SZ);
    bucketSortEven(arr2, SZ);
    printArray(arr2, SZ);

    return 0;
}
