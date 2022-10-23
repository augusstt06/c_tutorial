#include <stdio.h>

void pointerPlus(int *num)
{
    *num += 5;
}

void numPlus(int num)
{
    num += 5;
}

int main(void)
{
    int num = 15;
    printf("num : %d\n", num);

    numPlus(num);
    printf("numPlus 함수 호출/실행 후 : %d\n", num);

    // pointer는 직접적으로 메모리에 접근하여 값을 변경한다.
    pointerPlus(&num);
    printf("pointerPlus 함수 호출/실행 후 : %d\n", num);
    return 0;
}