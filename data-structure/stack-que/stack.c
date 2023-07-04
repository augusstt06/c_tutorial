#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
// stack을 사용하는 경우
// 1. 자료의 순서를 뒤집을때
// 2. 재귀함수 제거

typedef struct StackType
{
    int arr[100];
    int top;
} StackType;

// Stack 생성시 초기화 시켜주는 함수
void init(StackType *s)
{
    s->top = -1;
}

// 스택이 비어있다면 1을 리턴, 비어있지 않다면 0 리턴
int isEmpty(StackType *s)
{
    // stack이 가리키는 top이 -1 즉, 비어있다면 -1 반환
    if (s->top == -1)
        return 1;
    return 0;
}

// 스택이 차있다면 1을 리턴, 비어있다면 0 리턴
int isFull(StackType *s)
{
    if (s->top == SIZE - 1)
        return 1;
    return 0;
}

void pushStack(StackType *s, int value)
{
    if (isFull(s))
    {
        printf("스택이 가득 차있습니다\n");
        exit(1);
    }

    s->arr[++(s->top)] = value;
    printf("스택에 %d요소가 추가되었습니다.\n", value);
}

int popStack(StackType *s)
{
    if (isEmpty(s))
    {
        printf("스택이 이미 비어있습니다.\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

// 스택 최상단 요소 리턴
int peek(StackType *s)
{
    if (isEmpty(s))
    {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    return s->arr[(s->top)];
}
int main()
{
    StackType s;
    // 스택 초기화
    init(&s);

    pushStack(&s, 8);
    pushStack(&s, 2);
    pushStack(&s, 7);

    printf("peek : %d\n", peek(&s));
    printf("pop : %d\n", popStack(&s));
    printf("pop : %d\n", popStack(&s));
    return 0;
}