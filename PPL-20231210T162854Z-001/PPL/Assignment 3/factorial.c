#include <stdio.h>
#include <limits.h>
unsigned long long int factorial(short n){
    if(n  ==  0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(){
    short k ;
    scanf("%hd", &k);
    unsigned long long fact = factorial(k);
    printf("The factorial of %hd is %llu",k,fact);
    return 0;
}