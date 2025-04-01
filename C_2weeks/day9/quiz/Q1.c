#include <stdio.h>     // 표준 입출력 함수 사용을 위한 헤더
#include <stdlib.h>    // malloc, free 함수 사용을 위한 헤더

/*  
 * 동적 메모리를 사용한 정수 배열 처리 프로그램
 * - 사용자로부터 배열의 크기를 입력받고
 * - 해당 크기만큼 메모리를 heap 영역에 동적 할당 (malloc 사용)
 * - 정수 데이터를 입력받아 평균값을 계산
 * - 마지막에 메모리 해제 (free) 후 포인터 NULL로 초기화
 */

int main() {
    int n;           // 사용자에게 입력받을 배열 크기
    int sum = 0;     // 평균 계산을 위한 합계 저장 변수

    // 배열 크기 입력 요청
    printf("배열의 갯수를 입력하세요 (정수) : ");
    scanf("%d", &n);

    // 입력값 검증: 0 이하의 크기는 허용하지 않음
    if (n <= 0) {
        fprintf(stderr, "배열 크기는 양수여야 합니다.\n");
        return 1;  // 프로그램 비정상 종료
    }

    // malloc을 사용하여 정수 배열을 heap에 동적 할당
    int *arr = (int *)malloc(n * sizeof(int));

    // malloc 실패 시 예외 처리
    if (arr == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    // 사용자로부터 배열 요소 입력받고, 동시에 합계 계산
    for (int i = 0; i < n; i++) {
        printf("%d번째 배열의 값을 입력하세요 : ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // 평균값 계산 및 출력 (실수형 출력 위해 float 형변환)
    printf("배열의 평균값은 %.2f 입니다.\n", (float)sum / n);

    // 동적으로 할당한 메모리를 반드시 해제
    free(arr);

    // 해제 후 포인터를 NULL로 초기화하여 재사용/이중 해제 방지
    arr = NULL;

    return 0;  // 프로그램 정상 종료
}