# include <stdio.h>
# include "add.h"
int add(int x, int y){
    return x % y;
}


int main(){
    int sum = 0;
    for(int i = 0; i < 1001; i++)
        sum += i;
    printf("Hello, World!");
    printf("%d\n", add(1, 2));
}