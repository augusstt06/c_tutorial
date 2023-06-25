#include <stdio.h>
#define MONTHS 12

int main(void)
{
    double monthSalary = 1000.5;
    printf("$ %.2f \n", monthSalary * MONTHS);

    // 알파벳은 ASCII 코드에 따라 작동하기 때문에 문자형과 숫자형을 이를 이용하여 바꿀수 있다.
    int x = 65;
    printf("%c\n", x);
    char y = 65;
    printf("%c\n", y);
    char z = 'B';
    printf("%c\n", z);

    // 숫자형을 다른 진수로 바꾸기
    int k = 100;
    printf("10진수인 수로 출력 : %d\n", k);
    printf("8진수인 수로 출력 : %o\n", k);
    printf("16진수인 수로 출력 : %x\n", k);
    return 0;
}