#include <stdio.h>

int main(){
    int i = 2;
    printf("=================\n");

    while(i <= 9){
        int j = 1;
        printf("%d 단 \n", i);
        while(j <= 9){
            printf("%d * %d = %d\n", i, j, i * j);
            j++;
        }
        printf("=================\n");
        i++;
    }
}