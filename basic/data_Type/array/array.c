#include <stdio.h>
#include <limits.h>
#define NUMBER 5

// define과 global variables의 차이
// define : 기본적으로 전처리기 (컴파일러의 한 부분) => 숫자 상수에 naming이 가능하다.
// global variables : 말 그대로 전역변수로써 소스코드내의 여러 연산에 의해 변경이 가능하다.

int main(void)
{
    int i, max, min, index;
    max = 0;
    index = 0;

    // NUMBER크기를 가진 배열 선언
    int array[NUMBER];
    for (i = 0; i < NUMBER; i++)
    {
        scanf("%d", &array[i]);
        if (max < array[i])
        {
            max = array[i];
            index = i;
        }
    }
    printf("가장 큰 값은 %d이고, %d번째에 있습니다.", max, index + 1);
    min = INT_MAX;
    for (i = 0; i < NUMBER; i++)
    {
        scanf("%d", &array[i]);
        if (min > array[i])
        {
            min = array[i];
            index = i;
        }
    }
    printf("가장 작은 값은 %d이고, %d번째에 있습니다.", min, index + 1);
    return 0;
}