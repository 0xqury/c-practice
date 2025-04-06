#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main(){
    int n = 0;
    printf("사람이 몇명인가요 : ");
    scanf("%d", &n);
    getchar();

    Person *p = (Person *)malloc(n * sizeof(Person)); 

    for(int i = 0; i < n; i++){
        printf("%d번째 사람의 이름 : ", i + 1);
        fgets(p[i].name, sizeof(p[i].name), stdin);
        p[i].name[strcspn(p[i].name, "\n")] = '\0';

        printf("%d번째 사람의 나이 : ", i + 1);
        scanf("%d", &p[i].age);
        getchar();
    }

    printf("#######################################\n");

    for(int i = 0; i < n; i++){
        printf("%d번째 사람의 이름 : %s\n", i + 1, p[i].name);
        printf("%d번째 사람의 나이 : %d\n", i + 1, p[i].age);
        printf("#######################################\n");
    }

    free(p);
    p = NULL;

    return 0;
}
