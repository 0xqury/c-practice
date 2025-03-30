#include <stdio.h>

int main(){
    int arr[3] = {1,5,9};
    int* p = arr;
    int* k = &arr[1];
    
    printf("%d\n", p[0]);
    printf("%d\n", *(p + 2));
    printf("%p\n", k);



}

// change(int* ptr)
// change(&num)

// int* ptr = &num;