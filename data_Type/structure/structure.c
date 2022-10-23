// 구조체 : 객체 지향 프로그래밍에서 말하는 클래스의 모체
// 여러개의 자료형을 묶어서 새로운 자료형을 만들수 있다.
// 서로 다른 자료형을 묶어서 다룰수 있다.
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
    s.number = 2015280104;
    strcpy(s.name, "김충연");
    s.grade = 4.5;
    printf("학번 : %d\n", s.number);
    printf("이름 : %s\n", s.name);
    printf("학점 : %.1f\n", s.grade);

    return 0;
}