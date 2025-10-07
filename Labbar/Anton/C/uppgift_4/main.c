#include <stdio.h>
#include <assert.h>

#define TERM_PADDING 4
#define VALUE_PADDING 12

int fac(int n){
    assert(n > -1);
    int sum=1;
    for(int i=n; i>0; i--){ sum *= i; }
    return sum;
}

/*
    b = base
    e = exponent
*/
int power(int b, int e){
    int sum = 1;
    for(int i=0; i<e; i++){
        sum *= b;
    }
    return sum;
}

double taylor_estm(int x, int n){
    double sum=1.0;
    for(int i=0; i<n; i++){
        // printf("x*i = %d || fac(i) = %d || sum = %f\n", x*i, fac(i), sum); //debug
        sum += power(x,i+1) / (double)fac(i+1);
    }
    return sum;
}

void print_taylor(int x, int n){
    for(int i=0; i<n; i++){
        printf("%-*d %*.7f\n", TERM_PADDING, i+1, VALUE_PADDING, taylor_estm(x, i));
    }
}

int main(void){
    int ipt;
    printf("Enter the value of x: ");
    scanf("%d", &ipt);
    print_taylor(ipt, 11);
    return 0;
}