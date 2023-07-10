#include "tree.h"

Node *createNode(ElementType newData)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->data = newData;

    return newNode;
}

void deleteNode(Node *node)
{
    free(node);
}

void deleteTree(Node *root)
{
    if (root->rightChild != NULL)
    {
        deleteTree(root->rightChild);
    }
    if (root->leftChild != NULL)
    {
        deleteTree(root->leftChild);
    }
    root->leftChild = NULL;
    root->rightChild = NULL;
    deleteNode(root);
}

void addChildNode(Node *parentNode, Node *childNode)
{
    if (parentNode->leftChild == NULL)
    {
        parentNode->leftChild = childNode;
    }
    else
    {
        Node *tempNode = parentNode->leftChild;
        while (tempNode->rightChild != NULL)
        {
            tempNode = tempNode->rightChild;
        }

        tempNode->rightChild = childNode;
    }
}

void printTree(Node *node, int depth)
{
    int i = 0;
    for (i = 0; i < depth - 1; i++)
        printf("   ");

    if (depth > 0)
        printf("+--");

    printf("%c\n", node->data);

    if (node->leftChild != NULL)
        printTree(node->leftChild, depth + 1);
    if (node->rightChild != NULL)
        printTree(node->rightChild, depth);
}

int main(void)
{
    Node *root = createNode('A');
    Node *b = createNode('B');
    Node *c = createNode('C');
    Node *d = createNode('D');
    Node *e = createNode('E');
    Node *f = createNode('F');

    addChildNode(root, b);
    addChildNode(b, c);
    addChildNode(b, d);
    addChildNode(d, e);
    addChildNode(d, f);

    printTree(root, 0);
    deleteTree(root);

    return 0;
}