// 메모리의 주소를 저장하려면 포인터 사용 (주소 저장하는 변수)
// 포인터 변수 선언 : int *psx
// 포인터 변수는 4byte (32비트 플랫폼)
// 포인터에 주소 대입 : y = *px

// 선언 예제
#include <stdio.h>

int main(void)
{
    int x = 10, y;
    // 포인터 px 선언
    int *px;

    // 포인터 px에 x의 주소 대입
    px = &x;
    y = *px;
    return 0;
}