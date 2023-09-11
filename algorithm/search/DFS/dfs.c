// DFS 깊이 우선 탐색
#include <stdio.h>
#include <stdlib.h>

int matrix[10][10];
int visited[9];

void dfs(int v)
{
    visited[v] = 1;
    printf("현재 방문한 곳 : %d", v);
    // 방문하지 않은 인접행렬일 경우
    for (int i = 0; i < 10; i++)
    {
        if (!visited[i] && matrix[v][i])
        {
            dfs(i)
        }
    }
}
int main(void)
{
    int i, x, y;
    for (i = 0; i < 10; i++)
    {
        scanf("%d %d", &x, &y);
        matrix[x][y] = matrix[y][x] = 1;
    }
    dfs(0);
    return;
}