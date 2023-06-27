#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Queue
{
    // 앞쪽 인덱스
    int front;
    // 뒤쪽 인덱스
    int rear;
    int data[MAX];
} Queue;

// 큐 초기화
void init(Queue *q)
{
    q->front = q->rear = -1;
}
int isFull(Queue *q)
{
    if (q->rear == MAX - 1)
        return 1;
    return 0;
}

int isEmpty(Queue *q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("이미 큐가 가득 차있습니다.\n");
        exit(1);
    }
    q->data[++(q->rear)] = value;
    printf("큐에 %d가 삽입 되었습니다.\n", value);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("큐가 이미 비어있습니다.\n");
        exit(1);
    }
    return q->data[++(q->front)];
}

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 3);
    enqueue(&q, 2);
    enqueue(&q, 1);

    printf("%d", dequeue(&q));
    printf("%d", dequeue(&q));
    printf("%d", dequeue(&q));
}