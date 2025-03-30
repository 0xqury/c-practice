#include <stdio.h>

int main(){
    
    char* str = "Hello, Pointer";
    printf("%s\n", str);
    printf("%d\n", str[0]);
    printf("%d\n", *(str+1));
}