#include <stdio.h>
// 문제 3. my_strcmp — 문자열 비교 함수

int my_strcmp(const char *s1, const char *s2){
    while(*s1 && *s2){
        if(*s1 != *s2) break;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main(){
    char str1[] = "this is test txt";
    char str2[] = "this is test txt";
    char str3[] = "ddong ojoom";

    if(my_strcmp(str1, str2) == 0) printf("1이랑 2랑 같당\n");
    else printf("1이랑 2랑 다르당\n");
    
    if(my_strcmp(str1, str3) == 0) printf("1이랑 3이랑 같당\n");
    else printf("1이랑 3이랑 다르당\n");
}