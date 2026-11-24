#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "15.h"


int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;

    printf("введите число: ");
    if (scanf("%d", &n) !=1 || n<1){
        printf("введено ненатуральное число");
        return 1;
    }
    printf("значение функции Мёбиуса: %d\n", Mebius(n));
    printf("количество делителей: %d\n", Tau(n));
    printf("значение функции Эйлера: %d\n", Euler(n));
    printf("сумма делителей: %lld\n", sumDel(n));
    printf("количество разных простых делителей: %d\n", numSimpleDev(n));
    printf("значение функции Кармайкла: %d\n", Carmichael(n));
    printf("значение функции Мангольдта: %.6f\n", Mangolt(n));
    return 0;
}