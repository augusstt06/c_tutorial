// Linked List 구현하기

// 기본적인 노드 구조
// NODE : [ID, value, next(pointer)]
// 최초의 노드의 next(pointer)값 : head
// 마지막 노드의 next(pointer)값 : tail

#include <stdio.h>
#include <stdlib.h>

// NODE 구조체 생성
struct NODE
{
    int ID;
    int value;
    // 다음 노드를 가리키는 포인터
    // 자료형 : NODE 구조체 (다음에 연결될 새로운 노드이므로)
    // Pointer (NODE)
    struct NODE *next;
    // Pointer(NODE) : head, tail, ptr
} *head, *tail, *ptr;

// 노드안의 밸류들을 출력해주는 함수
void ll_print()
{
    // 처음시작은 최초 노드를 가리키는 head pointer로 할당
    ptr = head;
    printf("(ID, Values) : ");
    // ptr이 NULL이 된다는 의미는 마지막 노드를 의미한다.
    while (ptr != NULL)
    {
        printf("(%d, %d)", ptr->ID, ptr->value);
        // 노드의 밸류들의 출력이 끝났다면, 다음 노드의 pointer로 ptr변수를 재할당한다.
        ptr = ptr->next;
    }
    printf("\n");
}

// 새로운 노드를 생성하는 함수
void ll_input()
{
    // NODE 안에 들어갈 ID, value 입력받음
    int in_ID, in_value;
    printf("\tID, value : ");
    scanf("%d %d", &in_ID, &in_value);
    // NODE의 크기 : ID(int)- 4pyte, value(int) - 4byte, next(pointer) - 8byte = 16pyte
    // struct NODE = 16byte
    // 메모리에 16바이트를 할당한 후, 그것에 대한 포인터(주소)를 ptr 변수에 할당
    // 즉, ptr은 새로 생기는 노드의 주소를 가리키는 변수이다. (항상 마지막 노드주소를 가리킨다.)
    ptr = (struct NODE *)malloc(sizeof(struct NODE));
    // 리스트가 비어있다면(아무런 노드가 없다면) ptr값을 head에 할당
    if (head == NULL)
        head = ptr;
    // 이전 노드가 있다면, 생성한 노드의 ptr값을 이전노드의 tail에 할당 (노드와 노드 연결)
    else
        tail->next = ptr;
    // 입력받은 ID값과 value값을 생성되는 NODE에 각각 할당
    ptr->ID = in_ID;
    ptr->value = in_value;
    // 생성되는 노드의 다음 노드가 아직 없으므로 NULL로 초기화 (다음 노드는 없다)
    ptr->next = NULL;

    // 최초 노드 생성시, 노드가 1개 뿐이므로 head, tail 모두 해당 노드를 가리킨다.
    tail = ptr;
    // 현재 노드에 무엇이 있는지 출력
    ll_print();
}

// 생성된 노드의 value값을 업데이트 하는 함수
void ll_update()
{
    // 업데이트 하고자 하는 노드의 ID값 입력
    int update_ID, update_value;
    printf("\tID for Update :");
    scanf("%d", &update_ID);
    // 최초 노드부터 시작하여 입력한 ID값을 찾아야 하므로 ptr을 hear로 설정
    ptr = head;
    while (ptr != NULL)
    {
        // 만약에 현재 ptr의 ID값이 입력한 ID값과 일치하다면
        if (ptr->ID == update_ID)
        {
            // 업데이트할 밸류값을 입력하고
            printf("\tEnter the value for this ID : ");
            scanf("%d", &update_value);
            // 현재 ptr이 가리키는 value값을 입력값으로 재할당한다.
            ptr->value = update_value;
            // 현재 노드를 출력하여 확인
            ll_print();
            // 함수 종료
            return;
        }
        // 일치하지 않는다면 다음 노드로 이동한다.
        ptr = ptr->next;
    }
}

// 노드를 삭제하는 함수
// 만약 최초 노드가 삭제된다면, head pointer를 두번째 노드로 이동시키고, 최초 노드의 메모리를 반환
// 마지막 노드 삭제시, tail pointer를 이전 노드로 옮기고 메모리 반환
// n번째 노드 삭제시, n-1노드의 next를 n+1로 변경하고 메모리 반환
void ll_delete()
{
    // 삭제하고자 하는 노드의 ID값 입력받기
    int delete_ID;
    printf("\tID for delete : ");
    scanf("%d", &delete_ID);
    // 노드를 돌면서 입력값과 일치하는 ID값을 찾기위해 최초 노드 설정
    ptr = head;
    // 최초 노드를 삭제하는 경우
    if (ptr->ID == delete_ID)
    {
        // head를 최초다음 노드로 재할당
        head = ptr->next;
        // 메모리 반환
        free(ptr);
        ll_print();
        return;
    }

    // n번째 노드를 삭제하는 경우
    // temp라는 변수 생성 (노드주소를 가리키는 temp라는 변수)
    struct NODE *temp;
    // 현재 노드가 마지막이 아닐때까지 반복
    while (ptr != NULL)
    {
        // 만약 포인터가 마지막을 가리킨다면, tail값은 이전 노드를 가리켜야 하기 때문에 tail값을 현재 ptr(노드)로 설정, ptr값은 다음 노드로 설정
        // tail과 ptr은 [tail, pointer]의 묶음으로 마지막 노드까지 반복되어 한칸씩 이동한다.
        // ptr이 마지막 도착시, tail, 즉 이전노드를 쉽게 알수 있음.
        tail = ptr;
        ptr = ptr->next;

        // 만약 현재 노드가 입력한 ID와 일치하다면
        if (ptr->ID == delete_ID)
        {
            // 현재 노드 바로 이전에 있는 tail의 next(다음 노드주소)를 현재 노드의 next값으로 재할당
            tail->next = ptr->next;
            // tail값을 temp값으로 할당
            temp = tail;
            // 메모리 반환
            free(ptr);
            // while문이 마지막 노드일때까지 반복시켜 tail이 링크드 리스트의 마지막을 가리키게끔 한다.
            // 현재 tail이 마지막이 아니라면 (즉, 중간에 있는 노드라면)
            // 현재 tail이 마지막이라면 while문을 실행하지 않고 바로 ll_print행으로 넘어간다.
            while (tail->next != NULL)
            {
                // 현재 temp값을 tail로 할당
                tail = temp;
                // temp는 한칸 뒤로 이동
                temp = temp->next;
            }
            ll_print();
            return;
        }
    }
}

int main()
{
    // 최초 링크드 리스트 헤드에는 아무것도 없으므로 NULL
    head = NULL;
    int index, flag = 0;

    while (flag == 0)
    {
        printf("Enter [(1) Input, (2) Print (3) Update (4) Delete (5) Exit]");
        scanf("%d", &index);
        if (index == 1)
            ll_input();
        else if (index == 2)
            ll_print();
        else if (index == 3)
            ll_update();
        else if (index == 4)
            ll_delete();
        else if (index == 5)
        {
            printf("Exit this Program\n");
            flag = 1;
            return 0;
        }
        printf("Enter Again (between 1 and 5)\n");
    }
    return 0;
}