#include <stdio.h>
#include <stdlib.h>

#define maxsize 101
#define maxnum 65500
int graph[maxsize][maxsize];
int indegree[maxsize];
int ve[maxsize];

int maxve(int N)
{
    int max = -1;
    for (int i = 0; i < N; i++)
        if (ve[i] > max)
            max = ve[i];
    return max;
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = maxnum;
        }
        indegree[i] = ve[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int x, y, time;
        scanf("%d %d %d", &x, &y, &time);
        graph[x][y] = time;
        indegree[y]++;
    }

    int stack[maxsize];
    int top = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
            stack[top++] = i;
    }
    while (top > 0)
    {
        int v = stack[--top];
        cnt++;
        for (int w = 0; w < N; w++)
        {
            if (graph[v][w] != maxnum)
            {
                indegree[w]--;
                if (indegree[w] == 0)
                    stack[top++] = w;
                if (ve[v] + graph[v][w] > ve[w])
                    ve[w] = ve[v] + graph[v][w];
            }
        }
    }
    if (cnt == N)
        printf("%d\n", maxve(N));
    else
        printf("Impossible\n");
    system("pause");
    return 0;
}