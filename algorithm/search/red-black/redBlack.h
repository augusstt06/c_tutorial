#ifndef redBLack_h
#define redBlack_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node{
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    
    enum {RED, BLACK} Color;

    ElementType data;
}Node;

void deleteTree(Node* tree);

Node* createNode(ElementType newData);
void deleteNode(Node* node);

Node* searchNode(Node* tree, ElementType target);
Node* searchMinNode(Node* tree);
void insertNode(Node** tree, Node* newNode);
void insertNodeHelper(Node** tree, Node* newNode);
Node* removeNode(Node** root, ElementType target);
void rebuildAfterInsert(Node** tree, Node* newNode);
void rebuildAfterRemove(Node** root, Node* x);

void printTree(Node* node, int depth, int blackcount);
void rotateLeft(Node** root, Node* parent);
void rotateRight(Node** root, Node* parent);

#endif
