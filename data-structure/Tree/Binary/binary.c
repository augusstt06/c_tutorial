// 이진트리 구현

#include "binary.h"

Node *createNode(ElementType newData)
{
    Node *newNode = (Node *)(malloc(sizeof(Node)));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;

    return newNode;
}

void deleteNode(Node *node)
{
    free(node);
}

void deleteTree(Node *node)
{
    if (node == NULL)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    deleteNode(node);
}

void preorderTree_Print(Node *node)
{
    if (node == NULL)
        return;

    printf("%c", node->data);

    preorderTree_Print(node->left);
    preorderTree_Print(node->right);
}

void inorderTree_Print(Node *node)
{
    if (node == NULL)
        return;
    inorderTree_Print(node->left);
    printf("%c", node->data);
    inorderTree_Print(node->right);
}

void postorderTree_Print(Node *node)
{
    if (node == NULL)
        return;

    postorderTree_Print(node->left);
    postorderTree_Print(node->right);
    printf("%c", node->data);
}

int main(void)
{
    Node *A = createNode('A');
    Node *B = createNode('B');
    Node *C = createNode('C');
    Node *D = createNode('D');
    Node *E = createNode('E');
    Node *F = createNode('F');
    Node *G = createNode('G');

    A->left = B;
    B->left = C;
    B->right = D;

    A->right = E;
    E->left = F;
    E->right = G;

    printf("Preorder \n");
    preorderTree_Print(A);
    printf("\n\n");

    printf("Inorder \n");
    inorderTree_Print(A);
    printf("\n\n");

    printf("Postorder \n");
    postorderTree_Print(A);
    printf("\n\n");

    deleteTree(A);

    return 0;
}