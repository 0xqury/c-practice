#include <stdio.h>

int main() {
    int a = 1234;
    void *ptr = &a;

    // void *는 바로 역참조 불가능 → 타입캐스팅 필요
    printf("%d\n", *(int *)ptr);
}
