#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 생성
struct student
{
    int number;
    char name[10];
    double grade;
};

int main(void)
{
    struct student s;

    printf("학번을 입력하세요 : ");
    scanf("%d", &s.number);

    printf("이름을 입력하세요 : ");
    // 배열은 그 자체로 포인터이기 떄문에 해당 주소 자체를 의미
    // 따라서 &를 붙일 필요가 없다.
    scanf("%s", s.name);

    printf("학점을 입력하세요 : ");
    scanf("%lf", &s.grade);

    printf("학번 : %d\n", s.number);
    printf("이름 : %s\n", s.name);
    printf("학점 : %.1f\n", s.grade);

    return 0;
}