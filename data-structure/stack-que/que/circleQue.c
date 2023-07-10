#include "circleQue.h"

void createQue(cirQue **que, int capacity)
{
    (*que) = (cirQue *)malloc(sizeof(cirQue));
    (*que)->nodes = (Node *)malloc(sizeof(Node) * (capacity + 1));
    (*que)->capacity = capacity;
    (*que)->front = 0;
    (*que)->rear = 0;
}

void deleteQue(cirQue *que)
{
    free(que->nodes);
    free(que);
}

void enque(cirQue *que, ElementType data)
{
    int position = 0;
    if (que->rear == que->capacity)
    {
        position = que->rear;
        que->rear = 0;
    }
    else
    {
        position = que->rear++;
    }
    que->nodes[position].data = data;
}

ElementType deque(cirQue *que)
{
    int position = que->front;
    if (que->front == que->capacity)
        que->front = 0;
    else
        que->front++;
    return que->nodes[position].data;
}

int getSize(cirQue *que)
{
    if (que->front <= que->rear)
        return que->rear - que->front;
    else
        return que->rear + (que->capacity - que->front) + 1;
}

int isEmpty(cirQue *que)
{
    return (que->front == que->rear);
}
int isFull(cirQue *que)
{
    if (que->front < que->rear)
        return (que->rear - que->front) == que->capacity;
    else
        return (que->rear + 1) == que->front;
}

int main(void)
{
    int i;
    cirQue *que;
    createQue(&que, 10);
    enque(que, 1);
    enque(que, 2);
    enque(que, 3);

    for (i = 0; i < 3; i++)
    {
        printf("Dequeue : %d, ", deque(que));
        printf("Front : %d, Rear : %d\n", que->front, que->rear);
    }

    i = 100;
    while (isFull(que) == 0)
    {
        enque(que, i++);
    }
    printf("Capacity : %d, Size : %d\n\n", que->capacity, getSize(que));

    while (isEmpty(que) == 0)
    {
        printf("Deque : %d, ", deque(que));
        printf("Front : %d, Rear : %d\n", que->front, que->rear);
    }

    deleteQue(que);
    return 0;
}