// Tree : 계층적인 구조를 나타내는 비선형 자료구조

#include <stdio.h>
#include <stdlib.h>

// 트리의 노드 구조체 생성
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *addNode(Node *node, int data)
{
    if (node == NULL)
    {
        Node *new = (Node *)(malloc(sizeof(Node)));
        new->right = NULL;
        new->left = NULL;
        new->data = data;
        return new;
    }
    else
    {
        if (node->data > data)
        {
            node->left = addNode(node->left, data);
        }
        else if (node->data < data)
        {
            node->right = addNode(node->right, data);
        }
    }
    return node;
}

void modifyData(Node *node, int data, int newData)
{
    if (node == NULL)
        return;
    // 찾으려는 데이터가 현재 노드 데이터와 일치한다면
    if (node->data == data)
    {
        node->data = newData;
    }
    // 찾으려는 데이터가 현재 노드 데이터와 다르다면
    else
    {
        // 찾는 데이터가 현재 데이터 보다 크면 왼쪽에
        if (node->data > data)
        {
            modifyData(node->left, data, newData);
        }
        // 찾는 데이터가 현재 데이터 보다 작으면 오른쪽에
        else
        {
            modifyData(node->right, data, newData);
        }
    }
}

// 데이터 찾기
Node *serachData(Node *node, int data)
{
    if (node == NULL)
        return NULL;

    if (node->data == data)
    {
        return node;
    }
    else
    {
        if (node->data > data)
        {
            return serachData(node->left, data);
        }
        else
        {
            return serachData(node->right, data);
        }
    }
}

// 데이터 삭제
Node *findMinimumNode(Node *node, Node **minNode)
{
    if (node->left == NULL)
    {
        *minNode = node;
        node = node->right;
        return node;
    }
    else
    {
        node->left = findMinimumNode(node->left, minNode);
        return node;
    }
}

Node *deleteNode(Node *node, int data)
{
    if (node == NULL)
        return NULL;

    if (node->data == data)
    {
        Node *deleteNode = node;
        if ((node->left == NULL) && node->right == NULL)
        {
            node = NULL;
        }
        else if ((node->left != NULL) && (node->right != NULL))
        {
            node = node->left;
        }
        else if ((node->left == NULL) && (node->right == NULL))
        {
            node = node->right;
        }
        else
        {
            Node *minNode = NULL;
            node->right = findMinimumNode(node->right, &minNode);
            minNode->left = deleteNode->left;
            minNode->right = deleteNode->right;
            node = minNode;
        }

        free(deleteNode);
        return node;
    }

    else
    {
        if (node->data > data)
        {
            node->left = deleteNode(node->left, data);
        }
        else
        {
            node->right = deleteNode(node->right, data);
        }
        return node;
    }
}

void ShowInOrder(Node *node)
{
    if (node == NULL)
        return;
    ShowInOrder(node->left);
    printf("%d", node->data);
    ShowInOrder(node->right);
}

int main()
{
    Node *root = NULL;

    root = addNode(root, 1);
    root = addNode(root, 2);
    root = addNode(root, 3);
    root = addNode(root, 4);

    ShowInOrder(root);
    return 0;
}