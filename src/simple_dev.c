#include "simple_dev.h"
#include <stdlib.h>

int *simpleDev(int n, int *count){
    *count = 0;
    int *dividers =NULL;
    for(int i =2; i<=n/i; i++){
        while (n%i ==0){
            int *temp = realloc(dividers, (*count+1)*sizeof(int));
            if (temp == NULL){
                free(dividers);
                *count = 0;
                return NULL;
            }

            dividers = temp;
            dividers[*count] = i;
            (*count)++;
            n /= i;   
        }
    }
    if (n>1){
        int *temp = realloc(dividers, (*count+1)*sizeof(int));
        if (temp == NULL){
                free(dividers);
                *count = 0;
                return NULL;}
        dividers = temp;
        dividers[*count] = n;
        (*count)++;}
    return dividers;
}