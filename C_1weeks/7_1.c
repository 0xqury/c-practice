#include <stdio.h>

void modify(int **ptr) {
    **ptr = 999;
}

int main(){
    int a = 10;
    int* p = &a;
    modify(&p);
    printf("%d\n",*p);
    printf("%p\n",p);
}