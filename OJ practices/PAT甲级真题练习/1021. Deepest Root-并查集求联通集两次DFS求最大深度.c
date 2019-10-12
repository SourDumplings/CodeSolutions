/*
 @Date    : 2017-12-01 17:08:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1021
思路来自：https://www.2cto.com/px/201707/660235.html
题意：无环连通图也可以视为一棵树，选定图中任意一点作为根，如果这时候整个树的深度最大，则称其为 deepest root。
 给定一个图，按升序输出所有 deepest root。如果给定的图有多个连通分量，则输出连通分量的数量
解题思路：先用并查集判断是不是一个联通分量，若是则后面的问题就是求树的直径，可以通过两次dfs求出树的直径。
首先从任意一点进行深搜，把其中距离最远的点记录下来，这些点是最长根，然后从这些最远点中任选一点再进行深度搜索，这个时候的所有最远点都是最长根。关键是第一遍dfs保存的最远点也是最长根。
首先，若第一遍dfs后的最远根不在从1开始的同一条支路上（他们的最近公共祖先是1），这是这些点必定都会是将来的最长根这很明显。
若第一遍dfs后的最远根在从1开始的同一条支路上，那么第二次dfs时就会漏掉同一支路上的最远根。
所以第一次与第二次dfs的合集才是最终结果
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000

int visited[MAXN];
int N;
int set[MAXN];


typedef struct AdjVNode *PtrtoAdjVNode;
struct AdjVNode
{
    int V;
    PtrtoAdjVNode next;
};

typedef struct VNode *AdjList;
struct VNode
{
    PtrtoAdjVNode FirstNode;
};

typedef struct LGNODE *LGraph;
struct LGNODE
{
    AdjList G;
};

LGraph Graph;
int dist[MAXN];

void InitializeVisitAndDist(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        visited[i] = 0;
        dist[i] = 0;
    }
    return;
}

int Find(int V)
{
    if (set[V] < 0)
    {
        return V;
    }
    else
    {
        return Find(set[V]);
    }
}

void Union(int V, int W)
{
    int r1 = Find(V);
    int r2 = Find(W);
    if (r1 != r2 && set[r1] <= set[r2])
    {
        set[r1] += set[r2];
        set[r2] = r1;
    }
    else if (r1 != r2 && set[r1] > set[r2])
    {
        set[r2] += set[r1];
        set[r1] = r2;
    }
    return;
}

void DFS(int S)
{
    visited[S] = 1;
    int D;
    PtrtoAdjVNode Ssub;
    for (Ssub = Graph->G[S].FirstNode->next; Ssub; Ssub = Ssub->next)
    {
        D = Ssub->V;
        if (!visited[D])
        {
            dist[D] = dist[S] + 1;
            DFS(D);
        }
    }
    return;
}

int AreadyConnected(int V, int W)
{
    PtrtoAdjVNode temp;
    int flag = 0;
    for (temp = Graph->G[V].FirstNode->next; temp; temp = temp->next)
    {
        if (temp->V == W)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    scanf("%d", &N);
    int i;
    Graph = (LGraph)malloc(sizeof(struct LGNODE));
    Graph->G = (AdjList)malloc(N*sizeof(struct VNode));
    for (i = 0; i < N; i++)
    {
        Graph->G[i].FirstNode = (PtrtoAdjVNode)malloc(sizeof(struct AdjVNode));
        Graph->G[i].FirstNode->next = NULL;
        set[i] = -1;
    }
    int V, W;
    PtrtoAdjVNode temp;
    for (i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &V, &W);
        if (AreadyConnected(V-1, W-1) || V == W)
        {
            continue;
        }
        temp = (PtrtoAdjVNode)malloc(sizeof(struct AdjVNode));
        temp->next = NULL;
        temp->V = W - 1;
        temp->next = Graph->G[V-1].FirstNode->next;
        Graph->G[V-1].FirstNode->next = temp;
        temp = (PtrtoAdjVNode)malloc(sizeof(struct AdjVNode));
        temp->next = NULL;
        temp->V = V - 1;
        temp->next = Graph->G[W-1].FirstNode->next;
        Graph->G[W-1].FirstNode->next = temp;
        Union(V-1, W-1);
    }
    int count = 0;
    InitializeVisitAndDist();
    for (V = 0; V < N; V++)
    {
        if (set[V] < 0)
        {
            count++;
        }
    }
    if (count > 1)
    {
        printf("Error: %d components\n", count);
    }
    else
    {
        int maxh = 0;
        InitializeVisitAndDist();
        DFS(0);
        for (i = 0; i < N; i++)
        {
            if (dist[i] > maxh)
            {
                maxh = dist[i];
            }
        }
        int farthestVset[N], f = 0;
        for (i = 0; i < N; i++)
        {
            if (dist[i] == maxh)
            {
                farthestVset[f++] = i;
            }
        }
        InitializeVisitAndDist();
        DFS(farthestVset[0]);
        maxh = 0;
        for (i = 0; i < N; i++)
        {
            if (dist[i] > maxh)
            {
                maxh = dist[i];
            }
        }
        for (i = 0; i < f; i++)
        {
            // 将两次DFS的结果合并
            dist[farthestVset[i]] = maxh;
        }
        for (i = 0; i < N; i++)
        {
            if (dist[i] == maxh)
            {
                printf("%d\n", i+1);
            }
        }
    }
    return 0;
}
