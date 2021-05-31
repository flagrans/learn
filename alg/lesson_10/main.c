#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    T dat;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

typedef struct NodeList {
    int dat;
    struct NodeList *next;
} NodeList;

typedef struct {
    NodeList *head;
    int size;
} List;

void init(Stack *stack) {
    stack->head = NULL;
    stack->size = 0;
}

void initList(List *lst) {
    lst->head = NULL;
    lst->size = 0;
}

boolean push(Stack *stack, T value) {
    Node *tmp = (Node*) malloc(sizeof (Node));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

boolean sk(char *str) {                          // Проверка валидности скобок
    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(st, str[i]);
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (st->size == 0) {
                printf("NO \n");
                return false;
            }
            char t = pop(st);
            if ((t == '(' && str[i] != ')') || (t == '[' && str[i] != ']') || (t == '{' && str[i] != '}')) {
                printf("NO \n");
                return false;
            }
        }
    }
    if (st->size != 0) {
        printf("NO \n");
        return false;
    }
    printf("YES \n");
    return true;
}

void ins(List *lst, int data) {
    NodeList *new = (NodeList*) malloc(sizeof (NodeList));
    new->dat = data;
    new->next = NULL;

    NodeList *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

void printNodeList(NodeList *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printList(List *lst) {
    NodeList *current = lst->head;
    if (current == NULL) {
        printNodeList(current);
    } else {
        do {
            printNodeList(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

void copyList (List *lst, List *lst2) {          // Копирование списка
    NodeList *current = lst->head;
    if (current == NULL) {
        return;
    } else {
        for (int i = 0; i < lst->size; i++) {
            ins(lst2, current->dat);
            current = current->next;
        }
    }
}

boolean isSortA (List *lst) {                    // Проверка сортировки по возрастанию
    NodeList *current = lst->head;
    if (current == NULL) {
        return true;
    } else {
        for (int i = 0; i < lst->size - 1; i++) {
            if (current->dat <= current->next->dat)
                current = current->next;
            else return false;
        }
    }
    return true;
}

boolean isSortV (List *lst) {                    // Проверка сортировки по убыванию
    NodeList *current = lst->head;
    if (current == NULL) {
        return true;
    } else {
        for (int i = 0; i < lst->size - 1; i++) {
            if (current->dat >= current->next->dat)
                current = current->next;
            else return false;
        }
    }
    return true;
}

boolean isSort (List *lst) {                     // Результирующая основная проверка сортировки
    if (isSortA(lst) || isSortV(lst))
        return true;
    return false;
}

int main() {
    // Первое задание
    sk("((2+[2])*{(3+4)})");
    sk("(2+[2])*({(3+4)}");
    sk(")(");

    printf("\n\n");
    // Второе задание
    List *lst = (List*) malloc(sizeof (List));
    List *lst2 = (List*) malloc(sizeof (List));
    initList(lst);
    initList(lst2);
    ins(lst, 44);
    ins(lst, 2);
    ins(lst, 3);
    ins(lst, 66);
    printf("List #1:");
    printList(lst);
    printf("List #2:");
    printList(lst2);
    copyList(lst, lst2);
    printf("List #2 after copy:");
    printList(lst2);

    printf("\n\n");
    // Третье задание
    printf("List is %ssorted\n", isSort(lst2) ? "" : "NOT ");


    return 0;
}
