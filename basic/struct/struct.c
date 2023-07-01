// 주로 사용하는 자료형
// 정수 int, 실수 double, 문자 char, 문자열 char *, char[]
// 서로 다른 자료형들을 묶어 사용하는 것.

// 예시
#include <stdio.h>

// 구조체 선언
struct Man
{
    int age;
    double weight;
};
// typedef 구조체
typedef struct
{
    char name[3];
    int age;
} Student;

// typedef 사용하여 구조체 배열 선언
typedef Student s_arr[2];

int main(void)
{
    // 선언한 구조체 변수 선언
    struct Man Kim;
    Kim.age = 18;
    Kim.weight = 63.3;
    printf("%d - %f", Kim.age, Kim.weight);

    // typedef 이용한 구조체 변수 선언
    Student kim = {"김충연", "18"};

    // 구조체 배열
    struct Man Man_arr[2] =
        {
            {18, 72.3},
            {17, 80.2}};
    // typedef 사용한 구조체 배열
    s_arr students = {{"cnffjd", 18},
                      {"augg", 19}};

    return 0;
}
