#include "redBlack.h"
#include <string.h>

extern Node *NIL;

Node *createNode(ElementType newData)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    newNode->Color = BLACK;

    return newNode;
}

void deleteNode(Node *node)
{
    free(node);
}

void deleteTree(Node *tree)
{
    if (tree->right != NIL)
        deleteTree(tree->right);
    if (tree->left != NIL)
        deleteTree(tree->left);

    tree->right = NIL;
    tree->left = NIL;

    deleteNode(tree);
}

Node *searchNode(Node *tree, ElementType target)
{
    if (tree == NIL)
        return NULL;

    if (tree->data > target)
        return searchNode(tree->left, target);
    else if (tree->data < target)
        return searchNode(tree->right, target);
    else
        return tree;
}

Node *searchMinNode(Node *tree)
{
    if (tree == NIL)
        return NIL;
    if (tree->left == NIL)
        return tree;
    else
        return searchMinNode(tree->left);
}

void insertNode(Node **tree, Node *newNode)
{
    insertNodeHelper(tree, newNode);

    newNode->Color = RED;
    newNode->left = NIL;
    newNode->right = NIL;

    rebuildAfterInsert(tree, newNode);
}

void insertNodeHelper(Node **tree, Node *newNode)
{
    if ((*tree) == NULL)
        (*tree) = newNode;
    if ((*tree)->data < newNode->data)
    {
        if ((*tree)->right == NIL)
        {
            (*tree)->right = newNode;
            newNode->parent = (*tree);
        }
        else
        {
            insertNodeHelper(&(*tree)->right, newNode);
        }
    }
    else if ((*tree)->data > newNode->data)
    {
        if ((*tree)->left == NIL)
        {
            (*tree)->left = newNode;
            newNode->parent = (*tree);
        }
        else
        {
            insertNodeHelper(&(*tree)->left, newNode);
        }
    }
}

void rotateRight(Node **root, Node *parent)
{
    Node *leftChild = parent->left;

    parent->left = leftChild->right;

    if (leftChild->right != NIL)
        leftChild->right->parent = parent;

    leftChild->parent = parent->parent;

    if (parent->parent == NULL)
        (*root) = leftChild;
    else
    {
        if (parent == parent->parent->left)
            parent->parent->left = leftChild;
        else
            parent->parent->right = leftChild;
    }
    leftChild->right = parent;
    parent->parent = leftChild;
}

void rotateLeft(Node **root, Node *parent)
{
    Node *rightChild = parent->right;

    parent->right = rightChild->left;

    if (rightChild->left != NIL)
        rightChild->left->parent = parent;

    rightChild->parent = parent->parent;

    if (parnet->parent == NULL)
        (*root) = rightChild;
    else
    {
        if (parent == parent->parent->left)
            parent->parent->left = rightChild;
        else
            parent->parent->right = rightChild;
    }

    rightChild->left = parent;
    parent->parent = rightChild;
}

void rebuildAfterInsert(Node **root, Node *x)
{
    while (x != (*root) && x->parent->Color == RED)
    {
        if (x->parent == x->parent->parent->left)
        {
            Node *uncle = x->parent->parent->right;
            if (uncle->Color == RED)
            {
                x->parent->Color = BLACK;
                uncle->Color = BLACK;
                x->parent->parent->Color = RED;

                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->right)
                {
                    x = x->parent;
                    rotateLeft(root, x);
                }
                x->parent->Color = BLACK;
                x->parent->parent->Color = RED;

                rotateRight(root, x->parent->parent);
            }
        }
        else
        {
            Node *uncle = x->parent->parent->left;
            if (uncle->Color == RED)
            {
                x->parent->Color = BLACK;
                uncle->Color = BLACK;
                x->parent->parent->Color = RED;

                x = x->parent->parent;
            }
            else
            {
                if (x = x->parent->left)
                {
                    x = x->parent;
                    rotateRight(root, x);
                }

                x->parent->Color = BLACK;
                x->parent->parent->Color = RED;
                rotateLeft(root, x->parent->parent);
            }
        }
    }

    (*root)->Color = BLACK;
}

Node *removeNode(Node **root, ElementType data)
{

    Node *removed = NULL;
    Node *successor = NULL;
    Node *target = searchNode((*root), data);

    if (target == NULL)
        return NULL;

    if (target->left == NIL || target->right == NIL)
    {
        removed = target;
    }
    else
    {
        removed = searchMinNode(target->right);
        target->data = removed->data;
    }

    if (removed->left != NIL)
        successor = removed->left;
    else
        successor = removed->right;

    successor->parent = removed->parent;

    if (removed->parent == NULL)
        (*root) = successor;
    else
    {
        if (removed == removed->parent->left)
            removed->parent->left = successor;
        else
            removed->parent->right = successor;
    }

    if (removed->Color == BLACK)
        rebuildAfterRemove(root, successor);

    return removed;
}

void rebuildAfterRemove(Node **root, Node *successor)
{
    Node *sibling = NULL;
    while (successor->parent != NULL && successor->Color == BLACK)
    {
        if (successor == successor->parent->left)
        {
            sibling = successor->parent->right;

            if (sibling->Color == RED)
            {
                sibling->Color = BLACK;
                successor->parent->Color = RED;
                rotateLeft(root, successor->parent);
            }
            else
            {
                if (sibling->left->Color == BLACK && sibling->right->Color == BLACK)
                {
                    sibling->Color = RED;
                    successor = successor->parent;
                }
                else
                {
                    if (sibling->left->Color == RED)
                    {
                        sibling->left->Color = BLACK;
                        sibling->Color = RED;

                        rotateRight(root, sibling);
                        sibling = successor->parent->right;
                    }
                    sibling->Color = successor->parent->Color;
                    successor->parent->Color = BLACK;
                    sibling->right->Color = BLACK;
                    rotateRight(root, successor->parent);
                    successor = (*root);
                }
            }
        }
        else
        {
            sibling = successor->parent->left;

            if (sibling->Color == RED)
            {
                sibling->Color = BLACK;
                successor->parent->Color = RED;
                rotateRight(root, successor->parent);
            }
            else
            {
                if (sibling->right->Color == BLACK && sibling->left->Color == BLACK)
                {

                    sibling->Color = RED;
                    successor = successor->parent;
                }
                else
                {
                    if (sibling->right->Color == RED)
                    {
                        sibling->right->Color = BLACK;
                        sibling->Color = RED;

                        rotateLeft(root, sibling);
                        sibling = successor->parent->left;
                    }
                    sibling->Color = successor->parent->Color;
                    successor->parent->Color = BLACK;
                    sibling->left->Color = BLACK;
                    rotateRight(root, successor->parent);
                    successor = (*root);
                }
            }
        }
    }
    successor->Color = BLACK;
}

void printTree(Node *node, int depth, int blackcount)
{
    int i = 0;
    char c = "X";
    int v = -1;
    char cnt[100];

    if (node == NULL || node == NIL)
        return;
    if (node->Color == BLACK)
        blackcount++;
    if (node->parent != NULL)
    {
        v = node->parent->data;

        if (node->parent->left == node)
            c = "L";
        else
            c = "R";
    }

    if (node->left == NIL && node->right == NIL)
        sprintf(cnt, "--------- %d", blackcount);
    else
        strncpy(cnt, "", sizeof(cnt));

    for (i = 0; i < depth; i++)
        printf(" ");
    printf("%d %s [%c, %d] %s\n", node->data, (node->Color = RED) ? "RED" : "BLACK", c, v, cnt);

    printTree(node->left depth + 1, blackcount);
    printTree(node->right, depth + 1, blackcount);
}