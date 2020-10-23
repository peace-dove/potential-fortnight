//learn && pta
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 11
typedef int Vertex;   
typedef int WeightType;

int visit[11] = {0};
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2; 
    //WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;                       
    int Ne;                       
    int G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph creat(int vnum)
{
    MGraph graph;
    graph = (MGraph)malloc(sizeof(struct GNode));
    graph->Ne = 0;
    graph->Nv = vnum;
    for (Vertex v = 0; v < vnum; v++)
        for (Vertex w = 0; w < vnum; w++)
        {
            graph->G[v][w] = 0;
        }
    return graph;
}
void insert(MGraph graph, Edge e)
{
    graph->G[e->V1][e->V2] = 1;
    graph->G[e->V2][e->V1] = 1;
}
MGraph build()
{
    MGraph graph;
    int nv, ne;
    scanf("%d", &nv);
    graph = creat(nv);
    scanf("%d", &ne);
    if (ne != 0)
    {
        for (int i = 0; i < ne; i++)
        {
            Edge edge;
            edge = (Edge)malloc(sizeof(struct ENode));
            scanf("%d %d", &edge->V1, &edge->V2);
            insert(graph, edge);
        }
    }
    return graph;
}
void dfs(MGraph g, int cur)
{
    visit[cur] = 1;
    printf("%d ", cur);
    for (int i = 0; i < g->Nv; i++)
    {
        if ((g->G[cur][i] == 1) && (visit[i] == 0))
        {
            dfs(g, i);
        }
    }
}

void bfs(MGraph g, int cur)
{
    visit[cur] = 1;

    int queue[22]={0};
    int top = 0;
    int head = 0;

    queue[top]=cur;
    top++;

    while (top > head)
    {
        int tmp = queue[head];
        head++;
        printf("%d ", tmp);
        for (int i = 0; i < g->Nv; i++)
        {
            if ((visit[i] == 0)&&(g->G[tmp][i] == 1))
            {
                visit[i] = 1;
                queue[top++] = i;
            }
        }
    }
}
int main()
{
    MGraph g;
    g = build();

    for (int i = 0; i < g->Nv; i++)
    {
        if (visit[i] == 1)
            continue;
        printf("{ ");
        dfs(g, i);
        printf("}\n");
    }

    for (int i = 0; i < 11; i++)
        visit[i] = 0;

    for (int i = 0; i < g->Nv; i++)
    {
        if (visit[i] == 1)
            continue;
        printf("{ ");
        bfs(g, i);
        printf("}\n");
    }

    system("pause");
    return 0;
}
