#include <stdio.h>
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

void secret() {
    printf("🎉 Exploit Success! You called secret()\n");
}

void vulnerable() {
    char buffer[64];  // 스택에 할당된 공간 (64바이트)

    printf("Input: ");
    gets(buffer);     // ⚠️ 길이 제한 없음! 오버플로우 발생 지점

    printf("Done. buffer = %s\n", buffer);
}

int main() {
    vulnerable();
    return 0;
}
