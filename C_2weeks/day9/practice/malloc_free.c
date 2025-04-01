#include <stdio.h>
#include <stdlib.h>  // malloc, free

int main(){
    int *arr = (int *)malloc(10 * sizeof(int));  // heap 영역에 int 크기의 영역 10개 확보 = int[10]
    free(arr);                                   // 메모리 해제
    arr = NULL;                                  // ptr NULL값으로 만들기 (사용 금지 및 오류 감지)
}
