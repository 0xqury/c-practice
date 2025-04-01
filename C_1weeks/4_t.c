#include <stdio.h>

int is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;
    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    printf("%d 까지의 소수:\n", num);
    
    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

