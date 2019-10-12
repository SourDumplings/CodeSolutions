/*
 @Date    : 2017-11-26 14:46:22
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6542
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define IMPOSSIBLE -1
#define INFINITY 99999

typedef struct EDGE *Edge;
struct EDGE
{
    int V, W;
    int c;
};

int N, M;
int unbuilt = 0;
int Vset[MAXN];
int built = 0;

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

int CheckCycle(int V, int W)
{
    int r1 = Find(V);
    int r2 = Find(W);
    if (r1 == r2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void InsertVset(int V, int W)
{
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

void BuildGraph(Edge E[])
{
    int V, W;
    int i, c, status;
    Edge temp;
    for (i = 0; i < N; i++)
    {
        // 初始化边集
        Vset[i] = -1;
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &V, &W, &c, &status);
        if (status == 1)
        {
            if (CheckCycle(V-1, W-1))
            {
                // 对于已经建好的边，只将不构成回路的边加入点集，舍弃掉会构成回路的边
                InsertVset(V-1, W-1);
                built++;
            }
        }
        else
        {
            temp = (Edge)malloc(sizeof(struct EDGE));
            temp->V = V - 1;
            temp->W = W - 1;
            temp->c = c;
            E[unbuilt++] = temp;
        }
    }
    qsort(E, unbuilt, sizeof(E[0]), compare);
    return;
}

int Kruskal(Edge E[])
{
    int totalcost = 0;
    Edge nextedge;
    int e = 0;
    while (built < N - 1)
    {
        if (unbuilt == 0)
        {
            break;
        }
        nextedge = E[e++];
        unbuilt--;
        if (CheckCycle(nextedge->V, nextedge->W))
        {
            InsertVset(nextedge->V, nextedge->W);
            built++;
            totalcost += nextedge->c;
            // printf("$$Edge (%d, %d) has been built.$$\n", nextedge->V+1, nextedge->W+1);
            // printf("$$Now the totalcost is %d$$\n\n", totalcost);
        }
    }
    if (built < N - 1)
    {
        totalcost = IMPOSSIBLE;
    }
    return totalcost;
}

int main()
{
    scanf("%d", &N);
    M = (N - 1) * N / 2;
    Edge E[M];
    // 读入数据，建立边集和顶点集
    BuildGraph(E);
    int minicost;
    minicost = Kruskal(E);
    printf("%d\n", minicost);
    return 0;
}

