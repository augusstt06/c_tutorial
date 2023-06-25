#include <stdio.h>

int main(void)
{
    int x;
    x = 5;
    // %d : int형이 들어갈 자리, %.2f : 실수형(소수점 f앞의 숫자 만큼 출력)이 들어갈 자리
    // sizeof() : 매개변수의 메모리 크기를 알려주는 메서드
    printf("변수 x의 메모리 크기는 %lu입니다\n", sizeof(x));
    int y = 50;
    // float = 4byte에 해당하는 범위까지 밖에 출력하지 못함
    float z = 123456789.123456789;
    // double = 8byte에 해당하는 범위까지 출력한다
    double k = 123456789.123456789;
    printf("y = %d\n", y);
    printf("z = %.2f\n", z);
    printf("k = %.2f\n", k);

    return 0;
}