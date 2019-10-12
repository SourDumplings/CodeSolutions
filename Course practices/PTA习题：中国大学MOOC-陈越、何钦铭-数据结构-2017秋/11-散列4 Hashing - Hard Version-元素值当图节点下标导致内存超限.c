/*
 @Date    : 2017-11-21 19:12:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/900290821590183936/problems/928950227070988288
 */

#include <stdio.h>

#define MAXV 4000

int G[MAXV][MAXV];
int Indegree[MAXV]; // 每个图结点的入度，即每个哈希表中的元素之前输入的元素个数
int HashTable[MAXV];
int TableSize;
int output = 0;
int Nv = 0;

int Hash(int key)
{
    return key % TableSize;
}

void ReadDataAndBuildEdge(void)
{
    int i, h, j;
    int V, W;
    for (i = 0; i < TableSize; i++)
    {
        if (HashTable[i] < 0)
        {
            continue;
        }
        Nv++;
        W = HashTable[i];
        Indegree[W] = 0;
        h = Hash(W);
        for (j = h; j < MAXV && HashTable[j] != W; j = (j + 1) % TableSize)
        {
            V = HashTable[j];
            G[V][W] = 1;
            Indegree[W]++;
        }
    }
    return;
}

void TopSortAndOutPut(void)
{
    int V, W;
    while (output < Nv)
    {
        for (V = 0; V < MAXV; V++)
        {
            if (Indegree[V] == 0)
            {
                if (output++)
                {
                    putchar(' ');
                }
                printf("%d", V);
                Indegree[V]--; // 代表该元素输出过了
                break;
            }
        }
        for (W = 0; W < MAXV; W++)
        {
            if (G[V][W])
            {
                Indegree[W]--;
            }
        }
    }
    return;
}

int main()
{
    scanf("%d", &TableSize);
    int V, W;
    int i;

    for (i = 0; i < TableSize; i++)
    {
        scanf("%d", &HashTable[i]);
    }

    for (V = 0; V < MAXV; V++)
    {
        for (W = 0; W < MAXV; W++)
        {
            G[V][W] = 0;
        }
        Indegree[V] = -1;
    }

    ReadDataAndBuildEdge();
    TopSortAndOutPut();
    putchar('\n');
    return 0;
}

