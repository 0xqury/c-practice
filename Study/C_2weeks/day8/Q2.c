#include <stdio.h>
// 문제 2. my_strcpy — 문자열 복사 함수 만들기

void my_strcpy(char *dst, const char *src){
    while(*src != '\0'){
        *dst++ = *src++;
    }
    *dst = '\0';
}

int main(){
    char str1[20] = "test str";
    char str2[20];
    my_strcpy(str2,str1);

    printf("원본 : %s\n복사본 : %s\n", str1, str2);

}