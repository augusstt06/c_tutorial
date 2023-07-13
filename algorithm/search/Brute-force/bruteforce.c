// 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
// 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다
// N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 100)
        printf("%d", n);
    else if (n == 1000)
        printf("144");
    else
    {
        int count = 0;
        for (int i = 100; i < n + 1; i++)
        {
            int temp = i / 100;
            int temp1 = (i / 10) % 10;
            int temp2 = i & 10;

            if (temp1 - temp == temp2 - temp2)
                count += 1;
        }
        printf("d", 99 + count);
    }
}