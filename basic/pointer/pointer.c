#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4};

    int *pointer = arr;

    printf("%010x", pointer + 0);
    printf("%010x", pointer + 1);
    printf("%010x", pointer + 2);
    printf("%010x", pointer + 3);

    return 0;
}

// pointer + 정수
// 현재 pointer변수가 가리키는 주소값에 n*4 byte를 더한 주소를 나타낸다.
// pointer 변수가 할당된 데이터 타입이 integer하면 n*4씩 증가
