#include <stdio.h>

// 조합 구현하기
int nCr(int n, int r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }
    else
    {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}
int main(void)
{
    int n, r;
    scanf("%d %d", &n, &r);
    printf("결과 : %d", nCr(n, r));
    return 0;
}