#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 컴파일 과정 에러 회피를 위한 직접 구현 
char *gets(char *s) {
    int c;
    char *p = s;
    while ((c = getchar()) != '\n' && c != EOF) {
        *p++ = c;
    }
    *p = '\0';
    return s;
}

void vulnerable() {
    char buffer[64];
    

    printf("Input: ");
    gets(buffer);  // ⚠️ BOF 발생 가능
}

int main() {
    vulnerable();
    return 0;
}
