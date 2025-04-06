#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    Person *p = (Person *)malloc(sizeof(Person));

    printf("이름을 입력하세요 : ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';

    printf("나이를 입력하세요 : ");
    scanf("%d", &(p->age));

    printf("이름 : %s\n", p->name);
    printf("나이 : %d\n", p->age);

    free(p);
    p = NULL;
    return 0;
}
