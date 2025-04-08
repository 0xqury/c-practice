// 포인터 연산 실습
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    
    // (p + 2) = p[2] -> 배열 요소 접근과 포인터 연산은 같은 효과 
    *(p + 2) = 999;

    // 정의되지 않은 영역을 건드리는 위험한 연산
    *(p + 7) = 777;
    printf("%d\n", arr[2]);
    printf("%d\n", arr[7]);
}
