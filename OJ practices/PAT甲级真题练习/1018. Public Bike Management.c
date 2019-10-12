/*
 @Date    : 2017-11-30 11:48:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1018
注意自行车只能从前一个站点送到下一个或者直接送回PBMC，而不能往上一个站点输送。
不能采用贪心法求解，要用DFS来求解，比较出每一条路径的参数才行。
注意对于共同祖先的结点的搜索容易被忽视，因此每次搜索完后要初始化收集序列。
首先选择send最少的，send相同时选择take back最少的。
测试数据：
10 4 4 5
5 6 7 2
0 1 1
1 2 1
1 3 1
2 4 1
3 4 1
1 0->1->3->4 0

10 6 6 8
8 9 4 6 7 2
0 1 1
0 2 1
1 3 1
2 3 1
3 4 1
3 5 2
4 6 1
5 6 1
0 0->1->3->4->6 0

 */

#include <stdio.h>

#define MAXN 501
#define ERROR -1
#define BIGNUM 99999

int G[MAXN][MAXN];
int Cmax, N, Sp, M;
int C[MAXN];
int time[MAXN];
int collected[MAXN];
int path[MAXN];
int temppath[MAXN];
int sendbikes = 0, rebikes = 0;
int minsendbikes = 0, minrebikes = 0;
int isfirstS = 1;

void InitializeCollected(void)
{
    int i;
    for (i = 0; i <= N; i++)
    {
        collected[i] = 0;
    }
    return;
}

int FindMinTime(void)
{
    int V;
    int mintime = BIGNUM, min_V;
    for (V = 1; V <= N; V++)
    {
        if (!collected[V] && time[V] < mintime)
        {
            mintime = time[V];
            min_V = V;
        }
    }
    if (mintime == BIGNUM)
    {
        min_V = ERROR;
    }
    return min_V;
}

void Dijkstra(int S)
{
    int i;
    time[0] = 0;
    for (i = 1; i <= N; i++)
    {
        time[i] = G[S][i];
    }
    collected[S] = 1;
    int V, W;
    while (1)
    {
        V = FindMinTime();
        if (V == ERROR)
        {
            break;
        }
        collected[V] = 1;
        for (W = 1; W <= N; W++)
        {
            if (!collected[W] && W != V && time[V] + G[V][W] < time[W])
            {
                time[W] = time[V] + G[V][W];
            }
        }
    }
    return;
}

void RecordPath(void)
{
    int i;
    for (i = 0; i <= N; i++)
    {
        path[i] = temppath[i];
    }
    return;
}

void DFS(int D, int needbikes)
{
    int S;
    int Scanoffer = 0, Sneedre = 0, Sneedbikes;
    int temps = sendbikes, tempr = rebikes;
    if (D == 0)
    {
        sendbikes = needbikes;
        collected[0] = 0;
        if (isfirstS || sendbikes < minsendbikes ||
            (sendbikes == minsendbikes && rebikes < minrebikes))
        {
            isfirstS = 0;
            minrebikes = rebikes;
            minsendbikes = sendbikes;
            RecordPath();
        }
        return;
    }
    for (S = 0; S <= N; S++)
    {
        if (!collected[S] && S != D && G[S][D] + time[S] == time[D])
        {
            Sneedre = 0;
            collected[S] = 1;
            if (S == 0)
            {
                Scanoffer = 0;
            }
            else
            {
                Scanoffer = C[S] - Cmax / 2;
            }
            if (Scanoffer > needbikes)
            {
                Sneedre = Scanoffer - needbikes;
                Scanoffer = needbikes;
                Sneedbikes = 0;
            }
            else if (Scanoffer < 0)
            {
                Sneedbikes = Cmax / 2 - C[S] + needbikes;
                Scanoffer = 0;
            }
            else
            {
                Sneedbikes = needbikes - Scanoffer;
            }
            rebikes += Sneedre;
            temppath[S] = D;
            DFS(S, Sneedbikes);
            InitializeCollected();
            collected[S] = collected[D] = 1;
            sendbikes = temps;
            rebikes = tempr;
        }
    }
    rebikes = minrebikes;
    sendbikes = minsendbikes;
    return;
}

int main()
{
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    int i, j;
    int V, W, t;
    for (i = 0; i <= N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            if (i != j)
            {
                G[i][j] = BIGNUM;
            }
            else
            {
                G[i][j] = 0;
            }
        }
    }
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &C[i]);
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &V, &W, &t);
        G[V][W] = G[W][V] = t;
    }

    InitializeCollected();
    Dijkstra(0);

    InitializeCollected();
    if (Cmax/2 - C[Sp] < 0)
    {
        rebikes += C[Sp] - Cmax/2;
        C[Sp] = Cmax / 2;
    }
    int needbikes = Cmax / 2 - C[Sp];
    collected[Sp] = 1;
    DFS(Sp, needbikes);

    printf("%d ", sendbikes);
    int S = 0;
    while (1)
    {
        printf("%d->", S);
        S = path[S];
        if (S == Sp)
        {
            break;
        }
    }
    printf("%d %d\n", Sp, rebikes);
    return 0;
}
