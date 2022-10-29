#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    // malloc : 메모리를 할당
    pi = (int *)malloc(sizeof(int));
    if (pi == NULL)
    {
        printf("동적 메모리 할당에 실패하였습니다.\n");
        exit(1);
    }
    *pi = 100;
    printf("%d\n", *pi);
    // 동적 메모리를 사용한 이후에는 무조건 해당 메모리를 빈한해야 한다.
    free(pi);
    return 0;
}