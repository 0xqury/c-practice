#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LEN 100

int main() {
    char *str_list[MAX_STRINGS];  // 문자열을 가리킬 포인터 배열
    char buffer[MAX_LEN] = {0};   // 입력 받을 임시 공간
    int count = 0;

    while (1) {
        printf("추가할 문자열을 입력하세요 (종료 : stop) : ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // 개행 제거

        if (strcmp(buffer, "stop") == 0) break;

        // 입력 문자열 길이만큼 malloc해서 복사
        str_list[count] = (char *)malloc(strlen(buffer) + 1);
        strcpy(str_list[count], buffer);
        count++;
    }

    printf("\n입력한 문자열 목록:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", str_list[i]);
        free(str_list[i]);  // 메모리 해제
        str_list[i] = NULL;
    }
    
    return 0;
}
