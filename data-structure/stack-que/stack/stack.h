#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node
{
    ElementType data;
} Node;

typedef struct arrayStack
{
    int capacity;
    int top;
    Node *nodes;
} arrayStack;

void createStack(arrayStack **stack, int capaticy);
void deleteStack(arrayStack *stack);
void push_stack(arrayStack *stack, ElementType data);
ElementType pop_stack(arrayStack *stack);
ElementType top_stack(arrayStack *stack);
int getSize(arrayStack *stack);
int isEmpty(arrayStack *stack);
int isFull(arrayStack *stack);

#endif
