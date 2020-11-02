#include <stdio.h>
#include <stdlib.h>

#define maxsize 1001
#define maxnum 65535
int graph[maxsize][maxsize];

struct
{
    int adjvex;
    int lowcost;
} closedge[maxsize];

int mini(int N)
{
    int min = maxnum;
    int res = -1;
    for (int i = 1; i <= N; i++)
    {
        if (closedge[i].lowcost != 0)
        {
            if (closedge[i].lowcost < min)
            {
                min = closedge[i].lowcost;
                res = i;
            }
        }
    }
    return res;
}
int main()
{
    int N, M;
    int sum = 0;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            graph[i][j] = maxnum;
        }

    for (int i = 0; i < M; i++)
    {
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);
        graph[x][y] = cost;
        graph[y][x] = cost;
    }
    closedge[1].lowcost = 0;
    for (int i = 2; i <= N; i++)
    {
        closedge[i].adjvex = 1;
        closedge[i].lowcost = graph[1][i];
    }

    for (int i = 1; i < N; i++)
    {
        int k = mini(N);
        if (k == -1)
        {
            sum = -1;
            break;
        }
        sum += closedge[k].lowcost;
        closedge[k].lowcost = 0;
        for (int j = 2; j <= N; j++)
        {
            if (closedge[j].lowcost != 0 && graph[k][j] < closedge[j].lowcost)
            {
                closedge[j].adjvex = k;
                closedge[j].lowcost = graph[j][k];
            }
        }
    }
    if (M < N - 1)
        sum = -1;
    for (int i = 1; i <= N; i++)
    {
        if (closedge[i].lowcost != 0)
        {
            sum = -1;
            break;
        }
    }
    printf("%d\n", sum);
    system("pause");
    return 0;
}
