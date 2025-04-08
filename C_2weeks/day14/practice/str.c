// 구조체 안 배열 오염 실습 
#include <stdio.h>
#include <string.h>

struct Info {
    char name[8];
    int grade;
};

int main() {
    struct Info s;

    strcpy(s.name, "ABCDEFGHIJK");  // name[8]을 넘는 입력

    printf("name: %s\n", s.name);
    printf("grade: %d\n", s.grade);  // 예기치 않은 값 출력 가능
    return 0;
}
