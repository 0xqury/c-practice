/*
- data에 접근 시, 아직 값이 남아있을 수도 있음 -> 위험한 착각임.
- free() 이후엔 반드시 data = NULL; 습관화!

# gdb 참고
- x/4x data       # 4개의 정수(hex)로 출력
- x/4d data       # 4개의 정수(decimal)
- x/1i data       # 1개의 instruction (코드 영역일 때)
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = malloc(sizeof(int));
    *data = 777;

    free(data);                     // 메모리 해제
    printf("%d\n", *data);          // 이미 해제된 메모리 접근 (UAF 발생)
    printf("주소 : %p\n", data);    // 여전히 주소는 출력됨

    return 0;
}