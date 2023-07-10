#include "stack.h"

void createStack(arrayStack **stack, int capacity)
{
    (*stack) = (arrayStack *)malloc(sizeof(stack));
    (*stack)->nodes = (Node *)malloc(sizeof(Node) * capacity);
    (*stack)->capacity = capacity;
    (*stack)->top = -1;
}

void deleteStack(arrayStack *stack)
{
    free(stack->nodes);
    free(stack);
}

void push_stack(arrayStack *stack, ElementType data)
{
    stack->top++;
    stack->nodes[stack->top].data = data;
}

ElementType pop_stack(arrayStack *stack)
{
    int position = stack->top--;
    return stack->nodes[position].data;
}

ElementType top_stack(arrayStack *stack)
{
    return stack->nodes[stack->top].data;
}

int getSize(arrayStack *stack)
{
    return stack->top + 1;
}
int isEmpty(arrayStack *stack)
{
    return stack->top == -1;
}

int main(void)
{
    int i = 0;
    arrayStack *stack = NULL;
    createStack(&stack, 10);
    push_stack(stack, 5);
    push_stack(stack, 23);
    push_stack(stack, 16);

    printf("Capacity : %d, Size : %d, Top : %d\n\n", stack->capacity, getSize(stack), top_stack(stack));

    for (i = 0; i < 4; i++)
    {
        if (isEmpty(stack))
            break;
        printf("Pop : %d", pop_stack(stack));

        if (!isEmpty(stack))
            printf("Current Top : %d\n", top_stack(stack));
        else
            printf("Empty Stack\n");
    }

    deleteStack(stack);
    return 0;
}