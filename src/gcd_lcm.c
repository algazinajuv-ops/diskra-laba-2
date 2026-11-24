int gcd(int a, int b){
    while(b!=0){
        int temp = a%b;
        a = b;
        b = temp;

    }
    return a;
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

int extendedGcd(int a, int b, int *x, int *y){
    int x1 = 1, y1 = 0;
    int x2 = 0, y2 = 1;

    while(b != 0){
        int q = a/b;
        int r = a%b;
        int newX = x1 - q*x2;
        int newY = y1-q*y2;
        a = b;
        b = r;
        x1 = x2;
        y1 = y2;
        x2 = newX;
        y2 = newY;
    }
    *x = x1;
    *y = y1;
    return a;
}