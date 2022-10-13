#include <stdio.h>

// int main(void)
// {
//     int number, x, i, sum = 0;
//     printf("정수의 갯수를 입력하세요 : ");
//     scanf("%d", &number);
//     for (i = 0; i < number; i++)
//     {
//         printf("정수의 값을 입력하세요 : ");
//         scanf("%d", &x);
//         sum += x;
//     }
//     printf("정수 전체의 값은 %d입니다\n", sum);
//     return 0;
// }

int main(void)
{
    int x, i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &x);
    for (i = 1; i <= 9; i++)
    {
        printf("%d X %d = %d\n", x, i, x * i);
    }
    return 0;
}