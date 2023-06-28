#include <stdio.h>
#include <stdlib.h>
#define MAX 3

// 선형큐
typedef struct Queue
{
    int front;
    int rear;
    int data[MAX];
} Queue;

// 큐 초기화
void init(Queue *q)
{
    q->front = q->rear = 0;
}
int isFull(Queue *q)
{

    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("이미 큐가 가득 차있습니다.\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("큐에 %d가 삽입 되었습니다.\n", value);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("큐가 이미 비어있습니다.\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 3);
    enqueue(&q, 2);

    printf("%d", dequeue(&q));
    printf("%d", dequeue(&q));

    enqueue(&q, 3);
    printf("%d", dequeue(&q));

    return 0;
}