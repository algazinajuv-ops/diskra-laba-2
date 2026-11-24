#include <stdlib.h>
#include <math.h>
#include "simple_dev.h"
#include "gcd_lcm.h"
#include "15.h"


int Mebius(int n){
    if (n==1){return 1;}
    
    int count = 0;
    int *divs = simpleDev(n, &count);
    
    if (divs==NULL){return -2;}
    
    for (int i =1; i<count; i++){
        if (divs[i] == divs[i-1]){
            free (divs);

            return 0;
        }
    }
    free(divs);
    if (count%2==0){
        return 1;
    }
    return -1;
}


int Tau(int n){
    if (n==1){return 1;}
    
    int count = 0;
    int *divs = simpleDev(n, &count);
    
    if (divs==NULL){return -2;}
    
    int result = 1;
    int power = 1;

    for (int i=1; i<count; i++){
        if (divs[i]==divs[i-1]){power++;}
        else{
            result *= (power+1);
            power = 1;
        }
    }

    result*=(power+1);

    free(divs);
    return result;
}


int Euler(int n){
    if (n==1){return 1;}

    int count = 0;
    int *divs = simpleDev(n, &count);

    if (divs==NULL){return -2;}
    
    int result = n;

    for (int i=0; i<count; i++){
        if (i ==0 || divs[i]!= divs[i-1]){
            result -= (result/divs[i]);
        }
    }

    free(divs);
    return result;
}


long long sumDel(int n){
    if (n==1){return 1;}

    int count = 0;
    int *divs = simpleDev(n, &count);

    if (divs==NULL){return -2;}

    long long result = 1;
    long long power = divs[0];
    long long sum = 1 + power;

    for (int i=1; i<count; i++){
        if (divs[i]==divs[i-1]){
            power *= divs[i];
            sum += power;
        }
        else{
            result *= sum;
            power = divs[i];
            sum = 1+ power;
        }
    }

    result *= sum;

    free(divs);
    return result;
}


int numSimpleDev(int n){
    if (n==1){return 0;}

    int count = 0;
    int *divs = simpleDev(n, &count);

    if (divs==NULL){return -2;}

    int result = 0;

    for (int i=0; i<count; i++){
        if (i == 0 || divs[i]!= divs[i-1]){
            result ++;
        }
    }

    free(divs);
    return result;
}


int CarmichaelHelper(int p, int q){
    if(p == 2 && q >= 8){return q/4;}
    return q - (q/p);
}


int Carmichael(int n){
    if (n==1){return 1;}

    int count = 0;
    int *divs = simpleDev(n, &count);

    if (divs==NULL){return -2;}

    int result = 1;
    int power = divs[0];

    for (int i=1; i<count; i++){
        if (divs[i]==divs[i-1]){
            power *= divs[i];
        }
        else{
            result = lcm(result, CarmichaelHelper(divs[i-1], power));
            power = divs[i];
        }
    }

    result = lcm(result, CarmichaelHelper(divs[count-1], power));

    free(divs);
    return result;
}


double Mangolt(int n){
    if (n==1){return 0;}

    int count;
    int *divs = simpleDev(n, &count);

    if (divs==NULL){return -2;}

    double result = 0;
    if (divs[0]== divs[count-1]){
        result = log(divs[0]);
    }
    free(divs);
    return result;

}