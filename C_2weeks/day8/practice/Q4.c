#include <stdio.h>
#include <string.h>
// 문제 4. 문자열을 입력받고, 복사하여 비교한 뒤
// 두 문자열이 같으면 "같음", 다르면 "다름" 출력

int my_strlen(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void my_strcpy(char *dst, const char *src){
    while(*src != '\0'){
        *dst++ = *src++;
    }
    *dst = '\0';
}

int my_strcmp(const char *s1, const char *s2){
    while(*s1 && *s2){
        if(*s1 != *s2) break;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main(){
    char str[50];
    char dump[50];

    printf("문자열을 입력하세요 : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    my_strcpy(dump, str);
    if(my_strcmp(str, dump) == 0) printf("두 문자열은 같다.\n");
    else printf("두 문자열은 다르다.\n");
}