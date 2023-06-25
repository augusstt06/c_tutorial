#include <stdio.h>

void print_re(int count)
{
    if (count == 0)
    {
        return;
    }
    else
    {
        printf("문자열을 출력합니다 \n");
        print_re(count - 1);
    }
}
int main(void)
{
    int number;
    printf("문자열을 몇개 출력할까요");
    scanf("%d", &number);
    print_re(number);
    return 0;
}