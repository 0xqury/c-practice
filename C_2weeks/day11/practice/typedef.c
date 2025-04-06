#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} User;

int main() {
    // 구조체 변수
    User a;
    a.id = 1;
    
    // 구조체 포인터
    User *b = malloc(sizeof(User));
    b->id = 2;
    (*b).id = 3;  // 같은 의미지만 less readable

    printf("a.id = %d\n", a.id);   // 1
    printf("b->id = %d\n", b->id); // 3

    free(b);
    return 0;
}
