#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node{
    struct Node* leftChild;
    struct Node* rightChild;

    ElementType data;
} Node;

Node* createNode(ElementType newData);
void deleteNode(Node* node);
void deleteTree(Node* root);
void addChildNode(Node* parantNode, Node* childNode);
void printTree(Node* node, int depth);

#endif
