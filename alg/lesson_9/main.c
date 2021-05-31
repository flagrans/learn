#include <stdio.h>
#include <math.h>
#include <string.h>

#define SZ 10

typedef struct {
    int pr;
    int dat;
} Node;

Node * arr[SZ];
int items;

void init() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    items = 0;
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof (Node));
    node->dat = dat;
    node->pr = pr;

    if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    } else {
        arr[items++] = node;
    }
}

Node* rem() {
    if (items == 0) {
        printf("%s \n", "Queue is empty");
        return NULL;
    } else {
        int idx = 0;
        for (int i = 1; i < items; ++i) {
            if (arr[i]->pr < arr[idx]->pr)
                idx = i;
        }
        Node *tmp = arr[idx];
        for (int i = idx + 1; i < items; ++i) {
            arr[i - 1] = arr[i];
        }
        arr[items - 1] = NULL;
        items--;
        return tmp;
    }
}

void printQ () {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}


#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

int cursor = -1;
T Stack[SIZE];

boolean push(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void binary(int n, char *rst) {
    while (n > 0) {
        push((n % 2 == 0) ? '0' : '1');
        n /= 2;
    }
    char t[2] = "";
    while (cursor != -1) {
        t[0] = pop();
        strcat(rst, t);
    }
}

int main() {
    // Первое задание
    init();

    ins (1, 11);
    ins (3, 22);
    ins (4, 33);
    ins (2, 44);
    ins (3, 55);

    printQ();

    rem();
    rem();

    printQ();

    ins (1, 66);

    printQ();

    rem();

    printQ();

    rem();
    rem();
    rem();

    printQ();

    ins (2, 77);

    printQ();

    // Второе задание
    char bin[] = "b'";
    binary(111, bin);
    printf("\n\n%s \n\n", bin);

    return 0;
}
