#include <stdio.h>

void isNatural (int n) {
    if (n <= 0) {
        printf("%d меньше либо равно 0\n", n);
        return;
    }
    int count = 0;
    for (int i = 1; i <= n; i++){
        if (n%i == 0)
            count++;
        if (count > 2) {
            printf("Число %d не является простым\n", n);
            return;
        }
    }
    printf("Число %d является простым\n", n);
}

int main() {
    int a;
    printf("%s", "Введите число: ");
    scanf("%d", &a);
    isNatural(a);
    return 0;
}
