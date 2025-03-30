#include <stdio.h>

int my_strlen(char* str){
    int i = 0;
    while(1){
        if(str[i] == '\0') break;
        i++;
    }
    return i;
}

int main(){
    char str[20] = "박민성화이팅";

    printf("%d\n", my_strlen(str));
}