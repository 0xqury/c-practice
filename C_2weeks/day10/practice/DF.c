/*
- 최신 glibc는 abort() 발생 -> double free 방지.
- 구버전/우회상황에서는 힙 free list가 망가짐.
- 공격자는 이걸로 임의 malloc -> 특정 주소 유도 가능.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* p = malloc(32);
    free(p);
    free(p);    // 두 번 해제 -> double free
    return 0;
}