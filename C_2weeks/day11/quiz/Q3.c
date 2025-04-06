#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void (*select)();
} Select;

void hello(){
    printf("Hello!\n");
}

void bye(){
    printf("Bye..\n");
}

int main(){
    Select s;
    s.select = hello;
    s.select();
    s.select = bye;
    s.select();

    return 0;
}