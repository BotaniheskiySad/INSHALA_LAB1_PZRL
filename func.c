#include "func.h"
int get_ans(int l, int r, char o){
    switch(o){
        case '+':
            return l + r;
        case '-':
            return l - r;
        case '*':
            return l * r;
        case '%':
            if (r == 0){
                printf("ERROR: division by zero");
                return INT_MIN;
            }
            return l % r;
        default:
            printf("ERROR: unknown operator");
                return INT_MIN;
    }
}
void print_ans(int* res, int size){
    for (int i = 0; i < size; i++){
        printf("Ответ №%d: %d\n", i+1, res[i]);
    }
}
void print_ans_str(int* res, int size, int k){
    for (int i = 0; i < size; i++){
        int symb = res[i] - k;
        if (symb > 255 || symb < 0){
            printf("ERROR: result %d is not in ASCII\n", i+1);
            return;
        }
    }
    printf("Результирующая строка: ");
    for (int i = 0; i < size; i++){
        int symb = res[i] - k;
        printf("%c", symb);
    }
    printf("\n");
}


