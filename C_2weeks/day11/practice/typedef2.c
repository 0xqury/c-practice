#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*sayHello)();
} FuncHolder;

void hello() {
    printf("Hello!\n");
}

int main() {
    FuncHolder f;
    f.sayHello = hello;
    f.sayHello();  // 함수 호출됨!
    
    return 0;
}
