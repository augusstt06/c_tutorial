// DFS : Depth First Search
// 장점
// 1. 경로상의 노드들만 기억하므로, 저장공간을 적게 차지
// 2. BFS보다 구현이 간단.

// 단점
// 1. 단순 검색 속도는 BFS보다 느림
// 2. 해를 구하면 탐색이 종료되므로 최적의 해가 아닐 수 있음

// Stack 자료구조 or 재귀를 통하여 구현한다.

#include <stdio.h>

// 인접행렬그래프
int graph[11][11];
// 방문 여부 체크
int visited[11];

void DFS(int current, int n)
{
    int i;
    // 현재 노드 방문확인
    visited[current] = 1;
    for (i = 1; i <= n; i++)
    { // 모든 인접한 노드 체크
        if (graph[current][i] == 1 && visited[i] == 0)
        { // 인접하고 방문하지 않은 노드라면
            printf("%d ", i);
            DFS(i, n);
        }
    }
}

int main()
{
    int start = 1;
    graph[1][3] = 1;
    graph[3][5] = 1;
    graph[5][7] = 1;
    graph[3][1] = 1;
    graph[5][3] = 1;
    graph[7][5] = 1;

    graph[1][2] = 1;
    graph[2][4] = 1;
    graph[4][8] = 1;
    graph[2][1] = 1;
    graph[4][2] = 1;
    graph[8][4] = 1;

    printf("%d ", start);
    DFS(start, 10);

    return 0;
}