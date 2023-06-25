#include <stdio.h>

int main(void)
{
    int i, j;
    int gugu[10][10];

    for (i = 1; i <= 9; i++)
    {
        printf("\n [%d단]\n\n", i);
        for (j = 1; j <= 9; j++)
        {
            gugu[i][j] = i * j;
            printf("%d X %d = %d\n", i, j, gugu[i][j]);
        }
    }
    return 0;
}