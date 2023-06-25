#include <stdio.h>

int main(void)
{
    // 간단한 조건문 사용법
    int x = -150;
    if (x < 0)
    {
        x = -x;
    }
    printf("x의 절대값은 %d입니다.\n", x);

    // JS랑 사용법이 같다.
    int score = 20;
    if (score >= 90)
    {
        printf("당신의 학점은 A입니다.\n");
    }
    else if (score >= 80)
    {
        printf("당신의 학점은 B입니다.\n");
    }
    else if (score >= 70)
    {
        printf("당신의 학점은 C입니다.\n");
    }
    else
    {
        printf("당신의 학점은 F입니다.\n");
    }

    return 0;
}