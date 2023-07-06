#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node{
    struct Node* left;
    struct Node* right;

    ElementType data;
} Node;

Node* createNode(ElementType newData);
void deleteNode(Node* Node);
void deleteTree(Node* Root);

void preorderTree_Print(Node* node);
void inorderTree_Print(Node* node);
void postorderTree_Print(Node* node);

#endif
