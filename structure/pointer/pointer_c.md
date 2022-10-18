## Pointer

- 메모리 주소 값을 가르키는 변수

- 기본 사용 예시

```
int *pointer ; // 포인터 변수 선언
int i = 10; // 일반 int 변수 선언

pointer = &i; // 포인터 변수에 int변수 메모리 주소 저장


// pointer(i의 주소)로 가서 *pointer(그 주소에 해당하는 값)의 값을 20으로 바꾼다.

*pointer = 20; // *pointer : pointer에 저장된 주소에 해당하는 값을 의미

printf("%d", i); // 20
```

- 포인터 연산

```
#include <stdio.h>

int main(void){
    int a = 10;
    int *pointer = &a;
    printf("%p\n", pointer); // 000000000062FE14

    pointer = pointer + 1;
    printf("%p", pointer); // 000000000062FE18
}
```

> 포인터에 +,-를 연산하면 포인터에 저장된 변수의 형태에 따라 다르게 바뀐다.

- 위의 수식의 pointer의 타입 = int
- int의 크기가 4 byte이므로 +-1 연산시 주소값에 +-4가 연산된다.
