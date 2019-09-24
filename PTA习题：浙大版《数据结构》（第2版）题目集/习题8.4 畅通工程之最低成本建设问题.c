/*
 @Date    : 2017-11-26 10:29:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6544
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
#define INFINITY 99999
#define IMPOSSIBLE -1
#define MAXM 3000
#define MASTROOT -1

int Graph[MAXN][MAXN];
int M, N;

typedef struct EDGE *Edge;
struct EDGE
{
    int V, W;
    int c;
};

Edge E[MAXM]; // 存储边的数组，按照权值非降序排列
int e = 0;
int Vset[MAXN]; // 顶点数组，存储每个结点的父结点


void BuildEdge(void)
{
    int i;
    int V, W, c;
    Edge temp;
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &V, &W, &c);
        Graph[V-1][W-1] = c;
        Graph[W-1][V-1] = c;
        temp = (Edge)malloc(sizeof(struct EDGE));
        temp->V = V-1;
        temp->W = W-1;
        temp->c = c;
        E[e++] = temp;
    }
    e = 0;
    return;
}

int compare(const void *a, const void *b)
{
    return (*(Edge *)a)->c - (*(Edge *)b)->c;
}

int Find(int V)
{
    if (Vset[V] < 0)
    {
        return V;
    }
    else
    {
        return Find(Vset[V]);
    }
}

int CheckCycle(int nextedge)
{
    int r1, r2;
    r1 = Find(E[nextedge]->V);
    r2 = Find(E[nextedge]->W);
    // printf("For edge (%d, %d), r1 = %d, r2 = %d\n", E[nextedge]->V, E[nextedge]->W, r1, r2);
    if (r1 == r2)
    {
        // printf("$$ This edge (%d, %d) is Bad!$$\n", E[nextedge]->V, E[nextedge]->W);
        return 0;
    }
    else
    {
        // printf("$$ This edge (%d, %d) is OK!$$\n", E[nextedge]->V, E[nextedge]->W);
        return 1;
    }
}

void InitializeVset(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        Vset[i] = -1; // 每个顶点在初始时都是一个单独的联通集，父结点定义为-1
    }
    return;
}

void InSertVset(int nextedge)
{
    int V = E[nextedge]->V;
    int W = E[nextedge]->W;
    int r1 = Find(V);
    int r2 = Find(W);
    if (Vset[r1] <= Vset[r2])
    {
        Vset[r1] += Vset[r2];
        Vset[r2] = r1;
    }
    else
    {
        Vset[r2] += Vset[r1];
        Vset[r1] = r2;
    }
    return;
}

int Kruskal(void)
{
    int totalweight = 0;
    int ecount = 0;
    int nextedge;
    InitializeVset();
    while (ecount < N - 1)
    {
        if (e < M)
        {
            nextedge = e++;
        }
        else
        {
            // 边集已空
            break;
        }
        if (CheckCycle(nextedge))
        {
            // 如果nextedge边的加入不构成回路，则将边插入
            // printf("$$Edge (%d, %d) c = %d has been inserted into minitree.$$\n",
                // E[nextedge]->V, E[nextedge]->W, E[nextedge]->c);
            totalweight += E[nextedge]->c;
            // printf("$$Now the totalweight = %d$$\n\n", totalweight);
            ecount++;
            InSertVset(nextedge); // 将这个边的两个顶点加到并查集里面去
        }
    }
    if (ecount < N - 1)
    {
        // 生成树不存在
        totalweight = IMPOSSIBLE;
    }
    return totalweight;
}

int main()
{
    int i, j;
    scanf("%d %d", &N, &M);
    // 图和边数组的初始化
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            Graph[i][j] = INFINITY;
        }
    }
    for (i = 0; i < M; i++)
    {
        E[i] = NULL;
    }
    BuildEdge();
    // 将边数组按照权重非降序排序
    qsort(E, M, sizeof(E[0]), compare);
    int minicost;
    minicost = Kruskal();
    if (minicost != IMPOSSIBLE)
    {
        printf("%d\n", minicost);
    }
    else
    {
        printf("Impossible\n");
    }
    return 0;
}

