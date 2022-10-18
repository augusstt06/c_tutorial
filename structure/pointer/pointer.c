// Pointer : 특정 데이터가 저장된 메모리의 주소를 저장하는 변수

#include <stdio.h>

// 두 변수의 값을 서로 변환하는 포인터 함수
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int x = 1;
    int y = 2;
    swap(&x, &y);
    printf("x = %d\ny = %d\n", x, y);
    return 0;
}