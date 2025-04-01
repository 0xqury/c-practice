#include <stdio.h>     // 표준 입출력 함수
#include <stdlib.h>    // malloc, calloc, free 함수 사용

/*
 * [초기화 실험] malloc과 calloc 비교
 * - malloc: 메모리만 할당하고 값을 초기화하지 않음 (쓰레기값 출력)
 * - calloc: 메모리를 0으로 초기화하면서 할당 (전부 0 출력)
 */

int main() {
    // malloc: 초기화되지 않은 힙 메모리 5개 할당
    int* mal = (int *)malloc(5 * sizeof(int));

    // calloc: 0으로 초기화된 힙 메모리 5개 할당
    int* cal = (int *)calloc(5, sizeof(int));

    // malloc 결과 출력 (초기화되지 않았기 때문에 쓰레기값일 가능성 높음)
    printf("[malloc 할당 영역 값 출력]\n");
    for (int i = 0; i < 5; i++) {
        printf("mal[%d] = %d\n", i, mal[i]);
    }

    // calloc 결과 출력 (모든 값이 0이어야 정상)
    printf("\n[calloc 할당 영역 값 출력]\n");
    for (int i = 0; i < 5; i++) {
        printf("cal[%d] = %d\n", i, cal[i]);
    }

    // 메모리 해제 (보안/안정성 측면에서 매우 중요)
    free(mal);
    free(cal);

    mal = NULL;
    cal = NULL;

    return 0;
}
