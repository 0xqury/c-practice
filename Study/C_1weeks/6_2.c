#include <stdio.h>

void swap(int* a, int* b){
    *a = 999;
    *b = 69696969;
}

int main(){
    int a = 7;
    int b = 10;

    swap(&a,&b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

}