#include <stdio.h>     // 표준 입출력 함수
#include <stdlib.h>    // malloc, realloc, free 함수 사용

/*
 * [realloc 실습]
 * - malloc으로 3개짜리 배열을 생성하고, 데이터를 저장
 * - realloc을 사용해 크기를 6개로 확장
 * - 기존 데이터(0, 1, 2)가 유지되는지 확인
 * - 새로 늘어난 부분은 초기화되지 않아 쓰레기값일 수 있음
 */

int main() {
    // 3개의 int 크기만큼 힙에 메모리 할당
    int* arr = (int *)malloc(3 * sizeof(int));

    // 초기값 설정 (0, 1, 2)
    for (int i = 0; i < 3; i++) {
        arr[i] = i;
    }

    // 메모리 크기 확장 (6개의 int 크기)
    // 정상 확장 검증
    int* temp = realloc(arr, 6 * sizeof(int));
    if (temp == NULL) {
        free(arr); // 기존 메모리 해제 (메모리 릭 방지)
        fprintf(stderr, "메모리 재할당 실패\n");
        return 1;
    }
    arr = temp;

    // 전체 6개 요소 출력 → 앞의 3개는 유지, 뒤의 3개는 쓰레기값일 가능성 있음
    for (int i = 0; i < 6; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 메모리 해제 및 포인터 초기화
    free(arr);
    arr = NULL;

    return 0;
}
