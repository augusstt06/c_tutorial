#include <stdio.h>
#include <math.h> // pow(), abs() 등등의 메서드 내포
#define SECOND_PER_MINUTE 60

int main(void)
{
    int input = 1000;
    int minute = input / SECOND_PER_MINUTE;
    int second = input % SECOND_PER_MINUTE;

    printf("%d초는 %d분 %d초 입니다", input, minute, second);
    // 선연산, 후연산 확실하게 확인하기
    int x = 0;
    printf("현재의 x는 %d입니다.\n", x);
    x++;
    printf("현재의 x는 %d입니다.\n", x);
    printf("현재의 x는 %d입니다.\n", x--);
    printf("현재의 x는 %d입니다.\n", x);

    // 복합 연산자
    int y = 100;
    printf("현재 y의 값은 %d입니다.\n", y);
    y += 50;
    printf("현재 y의 값은 %d입니다.\n", y);

    // 비교 연산자
    // true라면 1 반환, false라면 0 반환
    int z = 50, k = 30;
    printf("z와 k가 같은가? %d\n", z == k);
    printf("z와 k가 다른가? %d\n", z != k);
    printf("z에 k값을 넣으면? %d\n", z = k);

    // 논리 연산자
    printf("z가 k보다 크고 k는 20미만 입니까? %d\n", (z > k) && (k < 40));
    printf("z가 k보다 크거나 k는 20미만 입니까? %d\n", (z > k) || (k < 40));

    // 조건 연산자
    // JS의 삼항연산자를 생각하면 된다.
    int m = -50, n = 30;
    int absoluteM = (m > 0) ? m : -m;
    int max = (m > n) ? m : n;
    int min = (m < n) ? m : n;
    printf("m의 절대값은 %d입니다.\n", absoluteM);
    printf("m과 n중에서 최댓값은 %d입니다.\n", max);
    printf("m과 n중에서 최솟값은 %d입니다.\n", min);

    // pow 사용
    double j = pow(2.0, 4.0);
    printf("2의 4제곱은 %.0f입니다\n.", j);
    return 0;
}