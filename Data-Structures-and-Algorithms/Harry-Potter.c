#include <stdio.h>
#include <stdlib.h>

#define maxsize 101
#define maxnum 60000
int graph[maxsize][maxsize];

int d[maxsize][maxsize];
//int path[maxsize][maxsize];

int N, M;
void Floyd()
{
    int i, j, k;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
        {
            d[i][j] = graph[i][j];
        }
    for (k = 1; k <= N; k++)
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
}
/*void print()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}*/
int visited[maxsize] = {0};
int cnt = 0;
void dfs(int cur)
{
    visited[cur] = 1;
    cnt++;
    for (int k = 1; k <= N; k++)
    {
        if (cur != k && visited[k] == 0 && graph[cur][k] != maxnum)
        {
            dfs(k);
        }
    }
}
int main()
{
    int x, y, mz;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            graph[i][j] = maxnum;
    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d %d", &x, &y, &mz);
        graph[x][y] = mz;
        graph[y][x] = mz;
    }
    dfs(1);
    if (cnt < N)
        printf("0");
    else
    {
        Floyd();
        int tmp = 0, min = 60000, rowmax = -1;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if ((i != j) && d[i][j] > rowmax)
                {
                    rowmax = d[i][j];
                }
            }
            if (rowmax < min)
            {
                min = rowmax;
                tmp = i;
            }
            rowmax = -1;
        }
        //print();
        printf("%d %d\n", tmp, min);
    }
    system("pause");
    return 0;
}