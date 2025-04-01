#include <stdio.h>

int main(){
    int input;
    int sum = 0;

    while(input != 0){
        printf("숫자를 입력하세요. (0 입력 시 종료) : ");
        scanf("%d", &input);
        sum += input;
    }

    printf("합계 : %d\n", sum);

}