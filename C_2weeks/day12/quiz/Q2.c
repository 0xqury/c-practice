#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;

typedef struct {
    char name[20];
    void (*doing)();
} Action;

void hello() { printf("Hello!\n"); }
void bye()   { printf("Bye..\n"); }
void jump()  { printf("Jump!!\n"); }

void hack(){
    fp = fopen("script.sh", "w");
    fputs("date\necho \"my name is $(whoami)\"\nchmod 0755 script.sh", fp);
    fclose(fp);
    system("bash script.sh");
}

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

    if (choice >= 0 && choice <= 2) {
        printf("선택한 동작: %s\n", A[choice].name);
        A[choice].doing = hack;
        A[choice].doing();
    } else {
        printf("잘못 입력하셨습니다.\n");
    }

    free(A);
    A = NULL;
    return 0;
}
