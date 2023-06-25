#include <stdio.h>

int main(void)
{
    // 윤년을 판독해보자
    int year = 2022;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        printf("%d는 윤년입니다. \n", year);
    }
    else
    {
        printf("%d는 윤년이 아닙니다. \n", year);
    }
    return 0;
}