#include <stdio.h>
int sum(int x, int y){
    return x + y;
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("The sum of a and b is :%d", sum(a, b));
    return 0;
}
