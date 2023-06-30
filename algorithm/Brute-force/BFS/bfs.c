// 너비 우선 탐색
// 장점
// 1. 노드가 적고 깊이가 얕은 경우 빠르게 탐색
// 2. 최단경로 보장
// 단점
// 1. 큐에 탐색할 노드들을 저장해야 하므로 저장공간 소요

#include <stdio.h>

int n;
int rear, front;
int map[30][30], queue[30], visit[30];

void bfs(int v)
{
    int i;

    // 방문표시
    visit[v] = 1;
    printf("%d 시작\n", v);
    // 큐에 v를 삽입하고, 후단 1 증가
    queue[rear++] = v;
    // 큐의 후단과 전단이 같거나 작으면 반복 종료
    while (front < rear)
    {
        v = queue[front++];
        for (i = 1; i <= n; i++)
        {
            // 노드 v,i가 만나고, i를 방문하지 않았다면
            if (map[v][i] == 1 && !visit[i])
            {
                // 노드 i 방문 표시
                visit[i] = 1;
                printf("%d에서 %d로 이동\n", v, i);
                // 큐에 i를 삽입하고 후단 증가
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int start;
    int v1, v2;

    scanf("%d%d", &n, &start);

    while (1)
    {
        scanf("%d%d", &v1, &v2);
        if (v1 == -1 && v2 == -1)
            break;
        map[v1][v2] = map[v2][v1] = 1;
    }
    bfs(start);
    return 0;
}
