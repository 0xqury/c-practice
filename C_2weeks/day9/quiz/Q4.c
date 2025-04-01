#include <stdio.h>     // 표준 입출력 함수
#include <stdlib.h>

int main(){
    int *data = malloc(sizeof(int));  // 힙 메모리 4바이트 할당
    *data = 123;                      // 그 위치에 123 저장
    free(data);                       // 메모리 해제 (하지만 주소는 아직 data에 남아있음)
    printf("%d\n", *data);           // ⛔️ 이미 해제된 메모리 접근

    return 0;
}