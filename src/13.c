#include <stdint.h>
#include <stdio.h>
#include "13.h"


uint8_t polyAdd(uint8_t a, uint8_t b){
    return a^b;
}

void printPoly(uint16_t a){
    if ( a == 0){
        printf("0");
        return;
    }
    int first = 1;
    for (int i = 15; i>=0; i--){
        if ((a>>i)&1){
            if (first != 1){printf(" + ");}
            if (i==0){printf("1 ");}
            else if (i == 1){printf("x");}
            else{printf("x^%d", i);}
            first = 0;
        }
    }
}


uint8_t polyMulty(uint8_t a, uint8_t b, uint16_t mod){
    uint16_t result = 0;
    uint16_t temp = a;

    while (b!=0){
        if (b&1){
            result ^= temp;
        }
        temp = temp<<1;
        if (temp & 0x100){
            temp ^= mod;
        }
        b = b>>1;
    }
    return result;
}

uint8_t polyPower(uint8_t a, unsigned int n, uint16_t mod){
    uint8_t result = 1;

    while(n!=0){}
}