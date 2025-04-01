#include <stdio.h>
#include <stdlib.h>  // malloc, free

int main(){
    int *arr = (int *)calloc(10, sizeof(int));
    // 영역만 할당하는것이 아닌, 값을 0으로 초기화까지 하는 함수.
    // int *a = (int *)malloc(5 * sizeof(int));   // 값: ?? ?? ?? ?? ??
    // int *b = (int *)calloc(5, sizeof(int));    // 값: 0  0  0  0  0

}
