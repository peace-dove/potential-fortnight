//Read and check the pre-statement carefully.

#include <stdio.h>
#include <stdlib.h>
#define maxsize 101
typedef struct node
{
    int x;
    int y;
    int flag;
} lake;
lake a[maxsize];
int N, D;
int canreach(int x, int y)
{
    if (50 - x <= D || x + 50 <= D || 50 - y <= D || y + 50 <= D)
        return 1;
    return 0;
}

int dfs(int x, int y)
{
    if (canreach(x, y))
    {
        return 1;
    }
    for (int i = 1; i <= N; i++)
    {
        if (a[i].flag == 0 && ((a[i].x - x) * (a[i].x - x) + (a[i].y - y) * (a[i].y - y) <= D * D))
        {
            a[i].flag = 1;
            if (dfs(a[i].x, a[i].y))
                return 1;
            a[i].flag = 0;
        }
    }
    return 0;
}
int firstjump(i)
{
    if (a[i].flag == 0 && ((a[i].x) * (a[i].x) + (a[i].y) * (a[i].y) <= (D + 7.5) * (D + 7.5)))
        return 1;
    return 0;
}
int main()
{
    scanf("%d %d", &N, &D);
    a[0].x = 0;
    a[0].y = 0;
    a[0].flag = 1;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &a[i].x, &a[i].y);
        a[i].flag = 0;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (firstjump(i) && a[i].flag == 0)
        {
            if (dfs(a[i].x, a[i].y))
            {
                ans = 1;
                break;
            }
        }
    }
    if (ans)
        printf("Yes\n");
    else
        printf("No\n");
    system("pause");
    return 0;
}
