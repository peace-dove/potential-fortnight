#include <stdio.h>
#include <stdlib.h>
#define maxnum 100001
long long int num[maxnum];
void precdown(int p, int n)
{
    int parent, child;
    long long int tmp;
    tmp = num[p];
    for (parent = p; (parent * 2 + 1) < n; parent = child)
    {
        child = 2 * parent + 1;
        if (child != n - 1 && num[child] < num[child + 1])
            child++;
        if (tmp >= num[child])
            break;
        else
        {
            num[parent] = num[child];
        }
    }
    num[parent]=tmp;
}
void swap(int a, int b)
{
    long long int tmp;
    tmp = num[a];
    num[a] = num[b];
    num[b] = tmp;
}
void heapsort(int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        precdown(i, n);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(0, i);
        precdown(0, i);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &num[i]);
    }
    heapsort(N);
    for (int i = 0; i < N; i++)
    {
        printf("%lld", num[i]);
        if (i != N - 1)
            printf(" ");
    }
    printf("\n");
    system("pause");
    return 0;
}
