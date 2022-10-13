#include <stdio.h>

int getDay(int month, int day)
{
    int i, sum = 0;
    for (i = 1; i < month; i++)
    {
        // 윤년 감안 X
        if (i == 2)
        {
            sum += 28;
        }
        else if (i % 2 == 0)
        {
            sum += 30;
        }
        else
        {
            sum += 31;
        }
    }
    return sum + day;
}
int main(void)
{
    int month, day;
    scanf("%d %d", &month, &day);
    printf("1월 1일 부터 해당 날짜 까지의 거리는 %d일 입니다.", getDay(month, day));

    return 0;
}