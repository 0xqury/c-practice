#include <stdio.h>
// 문제 1. my_strlen — 문자열 길이 직접 구현

int my_strlen(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main(){
    char str[] = "hello my name is jjh";
    printf("문자열의 길이 : %d\n",my_strlen(str));

}