#include <stdio.h>

int main()
{
    // int형 배열 arr을 선언하고 초기화 한다.
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //이 배열의 첫번째 요소를 가리키는 포인터 변수 ptr을 선언한다.
    int *ptr = arr;
    //이 표현과 같음 : int* ptr = &arr[0];

    //배열의 이름이 첫 요소를 가리키고 있으므로
    //포인터로 첫 요소의 주소값을 가리키면 배열과 동일하게 사용 가능하다.

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }

    return 0;
}