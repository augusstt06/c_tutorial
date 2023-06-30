// 구조체
// 여러가지의 자료형을 묶어서 사용자가 편리하게 접근/사용하게 만든다.

#include <stdio.h>
// 간단한 구조체 정의
struct test
{
    int x;
    int y;
};

// p1,p2라는 구조체 변수 선언
struct test2
{
    int x;
    int y;
} t1, t2;

// 변수에 접근하기
struct point
{
    int x;
    int y;
};

int main()
{
    struct point pos;
    pos.x = 10;
    pos.y = 20;

    printf("현재 좌표 : (%d, %d)", pos.x, pos.y);
    return 0;
}

// typedef
// 구조체의 별칭 선언
typedef struct Score
{
    char name[20];
    int kor;
    int eng
} S;

int Example()
{
    S s1 = {"typedef 사용", 50, 20};
    return 0;
}