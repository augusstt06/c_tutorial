// 동적할당이 이루어지는 영역 : 힙 영역
// 힙 영역에서 메모리를 할당받아 사용. 사용이 완료되면 해제. => 수동으로 처리
// 배열같은 자료구조를 필요한 시전에 필요한 크기만큼 사용이 가능하여 효율적인 메모리 사용이 가능해진다.

// 메모리 할당/해제를 위한 표준함수
// malloc() : 할당
// => 반환형이 void / 반환값은 사용자가 원하는 자료형으로 형변환하여 사용
// free() : 반환

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;

    // int형을 원소 4개를 가지는 배열 동적할당
    arr = (int *)malloc(sizeof(int) * 4);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
    // 마지막엔 반드시 동적할당을 해제시켜야 한다.
    free(arr);

    return 0;
}
