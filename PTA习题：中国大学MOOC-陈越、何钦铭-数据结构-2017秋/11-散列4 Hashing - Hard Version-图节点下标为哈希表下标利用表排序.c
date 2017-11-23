/*
 @Date    : 2017-11-22 10:56:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/900290821590183936/problems/928950227070988288
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001

int G[MAXN][MAXN]; // 图结点的下标记录的是在哈希表中的下标
int Indegree[MAXN]; // 每个图结点的入度，即每个哈希表中的元素之前输入的元素个数
int HashTable[MAXN];
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
        W = i;
        Indegree[W] = 0;
        h = Hash(HashTable[i]);
        for (j = h; j < MAXN && HashTable[j] != HashTable[i]; j = (j + 1) % TableSize)
        {
            V = j;
            G[V][W] = 1;
            Indegree[W]++;
        }
    }

    // printf("Indegree:$$");
    // for (i = 0; i < TableSize; i++)
    // {
    //     printf(" %d", Indegree[i]);
    // }
    // printf("$$\n");

    return;
}

int compare(const void *a, const void *b)
{
    return HashTable[*(int *)a] - HashTable[*(int *)b];
}

void TopSortAndOutPut(void)
{
    int V, W;
    int sorted_hashtable[MAXN]; // 存储哈希表中元素的非递减顺序的排序表
    int effective_num = 0;
    int i;
    // 先将sorted_hashtable中的有效元素的下标录入
    for (i = 0; effective_num < Nv; i++)
    {
            if (HashTable[i] >= 0)
            {
                sorted_hashtable[effective_num++] = i;
            }
    }

    // printf("$$Before sorting: ");
    // for (i = 0; i < effective_num; i++)
    // {
    //     printf(" %d", sorted_hashtable[i]);
    // }
    // printf("$$\n");

    // 对哈希表做一次表排序
    qsort(sorted_hashtable, effective_num, sizeof(sorted_hashtable[0]), compare);

    // printf("$$After sorting: ");
    // for (i = 0; i < effective_num; i++)
    // {
    //     printf(" %d", sorted_hashtable[i]);
    // }
    // printf("$$\n");

    while (output < Nv)
    {
        for (i = 0; i < MAXN; i++)
        {
            V = sorted_hashtable[i];
            if (Indegree[V] == 0)
            {
                if (output++)
                {
                    putchar(' ');
                }
                printf("%d", HashTable[sorted_hashtable[i]]);
                Indegree[V]--; // 代表该元素输出过了
                break;
            }
        }
        for (W = 0; W < MAXN; W++)
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

    for (V = 0; V < MAXN; V++)
    {
        for (W = 0; W < MAXN; W++)
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



