// 멤버 변수로 포인터 사용
// 선언된 구조체 안의 포인터들은 변수의 주소 저장
// 포인터는 해당 변수의 주소값을 가리키므로, 값이 바뀔때 유동적으로 값이 바뀌는 객체 생성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Score
{
    int *kor;
    int *eng;
};

int Score1()
{
    struct Score s = {100, 90};
    struct Score *p = NULL;

    p = &s;
    printf("구조체 s 주소값 : %p\n", s);
    printf("국어 : %d 영어 : %d \n", s.kor, s.eng);
    printf("국어 : %d 영어 : %d \n", (*p).kor, (*p).eng);
    // -> 연산은 구조체 포인터가 가리키는 주소에 데이터를 할당한다.
    printf("국어 : %d 영어 : %d \n", p->kor, p->eng);

    return 0;
}

typedef struct
{
    int age;
    char name[];
} Student;

int main()
{
    Student *pointer = malloc(sizeof(Student));

    pointer->age = 25;
    strcpy(pointer->name, "augusstt");

    printf("이름 : %s\n", pointer->name);
    printf("나이 : %d\n", pointer->age);

    free(pointer);
    return 0;
}