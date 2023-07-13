#ifndef binaryTreeSearch_h
#define binaryTreeSearch_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
    struct Node *left;
    struct Node *right;

    ElementType data;
} Node;

Node *createNode(ElementType newData);
void deleteNode(Node *node);
void deleteTree(Node *node);

Node *searchNode(Node *tree, ElementType target);
Node *searchMinNode(Node *tree);
void insertNode(Node *tree, Node *child);
Node *removeNode(Node *Tree, Node *parent, ElementType target);
void inorderPrint(Node *node);

#endif