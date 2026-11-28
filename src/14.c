#include "14.h"
#include "gcd_lcm.h"
#include"15.h"
#include <stdlib.h>

double fastPower(double a, unsigned int n){
    double result = 1;
    while (n!=0){
        if(n%2!=0){
            result *= a;}
        a *= a;
        n /= 2;
        
    }
    return result;
}


int inverseGcd(int a, int n){
    int x, y;
    if(n<=1){return -1;}
    int d = extendedGcd(a,n,&x,&y);
    if(d!=1){return -1;}
    x %= n;
    if(x<0){x += n;}
    return x;
}

int fastPowerMod(int a, unsigned int n, int mod){
    long long result = 1;
    long long base = a % mod;

    while(n!=0){
        if(n%2!=0){
            result =(result*base)%mod;
        }
        base = (base*base)%mod;
        n /= 2;
    }
    return result;
}


int inversePower(int a, int n){
    if(n<=1){return -1;}
    if(gcd(a,n)!=1){return -1;}
    int power = Euler(n)-1;
    return fastPowerMod(a,power,n);
}