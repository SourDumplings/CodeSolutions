#include <stdio.h>

#define MAXN 100

#define INFINITY 999999999

int G[MAXN][MAXN], N, M;

void BuildGraph()
{
    int i, j, v1, v2, w;
    scanf("%d", &N);
    // CreateGraph
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            G[i][j] = INFINITY;
        }
    }
    // InsertEdge
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        G[v1-1][v2-1] = w;
        G[v2-1][v1-1] = w;
    }
    return;
}

int FindMaxDist(int D[][MAXN], int i)
{
    int MaxDist;
    int j;
    MaxDist = 0;

    // 找出i到其他动物j的最长距离
    for (j = 0; j < N; j++)
    {
        if (i != j && D[i][j] > MaxDist)
        {
            MaxDist = D[i][j];
        }
    }
    return MaxDist;
}

void Floyd(int D[][MAXN])
{
    int i, j, k;

    // 初始化
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            D[i][j] = G[i][j];
        }
    }

    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (i != j && D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    return;
}

void FindAnimal()
{
    int D[MAXN][MAXN], MaxDist, MinDist;
    int Animal, i;

    Floyd(D);

    MinDist = INFINITY;
    for (i = 0; i < N; i++)
    {
        MaxDist = FindMaxDist(D, i);
        if (MaxDist == INFINITY)
        {
            // 说明有从i无法变出的动物
            printf("0\n");
            return;
        }
        if (MinDist > MaxDist)
        {
            // 找到最长距离更小的动物
            MinDist = MaxDist;
            Animal = i + 1;
        }
    }
    printf("%d %d\n", Animal, MinDist);
    return;
}

int main()
{
    // 读入图
    BuildGraph();
    // 分析图
    FindAnimal();
    return 0;
}
