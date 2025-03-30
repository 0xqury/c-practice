#include <stdio.h>
#include <string.h>

int main(){
    char* fruits[3] = {"apple", "banana", "cherry"};
    int i = sizeof(fruits)/sizeof(fruits[0]);
    while(i != 0){
        printf("%s\n",fruits[i-1]);
        i--;
    }
}