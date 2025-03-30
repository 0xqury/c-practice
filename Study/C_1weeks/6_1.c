#include <stdio.h>

int main(){
    int a;
    int* p = &a;
    
    printf("%p\n", p);
    *p = 6974;
    printf("%d\n", *p);

    *p = 9;
    a = 1;

}