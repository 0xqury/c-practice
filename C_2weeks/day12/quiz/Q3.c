#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    void (*doing)();
} Action;

void hello() { printf("Hello!\n"); }
void bye()   { printf("Bye..\n"); }
void jump()  { printf("Jump!!\n"); }

int main() {
    int choice;
    Action *A = (Action *)malloc(3 * sizeof(Action));

    strcpy(A[0].name, "hello");
    strcpy(A[1].name, "bye");
    strcpy(A[2].name, "jump");

    A[0].doing = hello;
    A[1].doing = bye;
    A[2].doing = jump;

    printf("번호를 입력하세요 (0: hello, 1: bye, 2: jump): ");
    scanf("%d", &choice);

    printf("선택한 동작: %s\n", A[choice].name);
    A[choice].doing();

    free(A);
    A = NULL;
    return 0;
}
