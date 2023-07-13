// 배열이 아닌 구조에도 사용이 가능하다.

#include "binaryTreeSearch.h"

Node *createNode(ElementType newData)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;

    return newNode;
}

void deleteNode(Node *node)
{
    free(node);
}

void deleteTree(Node *tree)
{
    if (tree->right != NULL)
        deleteTree(tree->right);
    if (tree->left != NULL)
        deleteTree(tree->left);

    tree->left = NULL;
    tree->right = NULL;

    deleteNode(tree);
}

Node *searchNode(Node *tree, ElementType target)
{
    if (tree == NULL)
        return NULL;
    if (tree->data == target)
        return tree;

    else if (tree->data > target)
        return searchNode(tree->left, target);
    else
        return searchNode(tree->right, target);
}

Node *searchMinNode(Node *tree)
{
    if (tree == NULL)
        return NULL;
    if (tree->left == NULL)
        return tree;
    else
        return searchMinNode(tree->left);
}

void insertNode(Node *tree, Node *child)
{
    if (tree->data < child->data)
    {
        if (tree->right == NULL)
            tree->right = child;
        else
            insertNode(tree->right, child);
    }
    else if (tree->data > child->data)
    {
        if (tree->left == NULL)
            tree->left = child;
        else
            insertNode(tree->left, child);
    }
}

Node *removeNode(Node *tree, Node *parent, ElementType target)
{
    Node *removed = NULL;

    if (tree == NULL)
        return NULL;

    if (tree->data > target)
        removed = removeNode(tree->left, tree, target);
    else if (tree->data < target)
        removed = removeNode(tree->right, tree, target);
    else
    {
        removed = tree;
        if (tree->left == NULL && tree->right == NULL)
        {
            if (parent->left == tree)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
        {
            if (tree->left != NULL && tree->right != NULL)
            {
                Node *minNode = searchMinNode(tree->right);
                minNode = removeNode(tree, NULL, minNode->data);
                tree->data = minNode->data;
            }
            else
            {
                Node *temp = NULL;
                if (tree->left != NULL)
                    temp = tree->left;
                else
                    temp = tree->right;
                if (parent->left == temp)
                    parent->left = temp;
                else
                    parent->right = temp;
            }
        }
    }
    return removed;
}

void inorderPrint(Node *node)
{
    if (node == NULL)
        return;

    inorderPrint(node->left);
    printf("%d", node->data);

    inorderPrint(node->right);
}

void printResult(int searchTarget, Node *result)
{
    if (result != NULL)
        printf("Found : %d\n", result->data);
    else
        printf("Not Found : %d\n", searchTarget);
}

int main(void)
{
    Node *tree = createNode(123);
    Node *node = NULL;

    insertNode(tree, createNode(22));
    insertNode(tree, createNode(9918));
    insertNode(tree, createNode(424));
    insertNode(tree, createNode(17));
    insertNode(tree, createNode(3));

    insertNode(tree, createNode(98));
    insertNode(tree, createNode(34));

    insertNode(tree, createNode(760));
    insertNode(tree, createNode(317));
    insertNode(tree, createNode(1));

    int searchTarget = 17;

    node = searchNode(tree, searchTarget);
    printResult(searchTarget, node);

    searchTarget = 117;
    node = searchNode(tree, searchTarget);
    printResult(searchTarget, node);

    inorderPrint(tree);
    printf("\n");

    printf("Removing 98 \n");
    node = removeNode(tree, NULL, 98);
    deleteNode(node);
    inorderPrint(tree);
    printf("\n");

    printf("Inserting 111 \n");
    insertNode(tree, createNode(111));
    inorderPrint(tree);
    printf("\n");

    deleteTree(tree);
    return 0;
}