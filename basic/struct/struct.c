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
// typedef 사용
typedef struct
{
    char name[3];
    int age;
} Student;

int main(void)
{
    // 선언한 구조체 변수 선언
    struct Man Kim;
    Kim.age = 18;
    Kim.weight = 63.3;
    printf("%d - %f", Kim.age, Kim.weight);

    Student kim = {"김충연", "18"};

    return 0;
}
