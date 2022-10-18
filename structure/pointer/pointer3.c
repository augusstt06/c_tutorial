#include <stdio.h>

int main(void)
{
    int *p = NULL;
    int num = 15;

    p = &num;

    // pointer 변수(또는 변수의 주소값)를 printf 할때 %p
    printf("포인터 p : %p\n", p);
    printf("num의 주소 : %p\n", &num);
    printf("포인터 변수가 가르키는 값(num 사용) : %d", *&num);
    printf("포인터 변수가 가르기는 값 : %d", *p);
    return 0;
}
