// 1. 문자열 포인터 배열을 선언하고, 각 문자열을 출력하세요.
// 전체 문자열 & 각 문자열의 주소 & 문자열 길이 출력
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *langs[] = {"C", "Python", "Go", "Rust"};
    for(int i = 0; i < sizeof(langs)/sizeof(langs[i]); i++){
        printf("%s\n",langs[i]);
        printf("%p\n", langs[i]);
        printf("%ld\n",strlen(langs[i]));
    }
    return 0;
}