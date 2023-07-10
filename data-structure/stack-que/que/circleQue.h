#ifndef circleQue_h
#define circleQue_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
    ElementType data;
}Node;

typedef struct cirQue{
    int capacity;
    int front;
    int rear;
    Node* nodes;
}cirQue;

void createQue(cirQue** que, int capacity);
void deleteQue(cirQue* que);
void enque(cirQue* que, ElementType data);
ElementType deque(cirQue* que);
int getSize(cirQue* que);
int isEmpty(cirQue* que);
int isFull(cirQue* que);

#endif
