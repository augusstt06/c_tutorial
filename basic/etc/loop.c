#include <stdio.h>
#define N 10
#define M 20

int main(void)
{
    int x = 1, sum = 0;

    while (x <= 1000)
    {
        sum = sum + x;
        x++;
    }
    printf("1부터 1000끼지의 합은 %d입니다.\n", sum);

    // 사각형 만들기
    // for문, while문도 JS랑 같다.
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    // 피라미드
    int n, m;
    for (n = 0; n < M; n++)
    {
        for (m = M - n - 1; m > 0; m--)
        {
            printf("  ");
        }
        for (m = 0; m < n; m++)
        {
            printf("* ");
        }
        for (m = 0; m < n - 1; m++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}