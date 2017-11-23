#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000

int S[MAXSIZE];

int Find(int X)
{
    // 默认集合元素全部初始化为-1
    // 遍历父节点
    // for (; S[X] >= 0; X = S[X]);
    // return X;

    // 路径压缩
    if (S[X] < 0)
    {
        return X;
    }
    else
    {
        return S[X] = Find(S[X]);
    }
}

void Union(int Root1, int Root2)
{
    // 这里默认Root1和Root2是不同集合的根节点
    // // 按高度，矮树贴到高树上
    // if (S[Root2] < S[Root1])
    // {
    //     // Root2更高
    //     S[Root1] = S[Root2];
    // }
    // else
    // {
    //     if (S[Root2] == S[Root1])
    //     {
    //         // 两树等高，树高+1
    //         S[Root1]--;
    //     }
    //     S[Root2] = S[Root1];
    // }
    // 按规模， 小树贴到大树上
    if (S[Root2] < S[Root1])
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    else
    {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
    return;
}

void Initialize(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        S[i] = -1;
    }
    return;
}

void Input_connection()
{
    int u, v;
    int Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(u-1);
    Root2 = Find(v-1);
    if (Root1 != Root2)
    {
        Union(Root1, Root2);
    }

    return;
}

void Check_connection()
{
    int u, v;
    int Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(u-1);
    Root2 = Find(v-1);
    if (Root1 == Root2)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return;
}

void Check_network(int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (S[i] < 0)
        {
            count++;
        }
    }
    if (count == 1)
    {
        printf("The network is connected.\n");
    }
    else
    {
        printf("There are %d components.\n", count);
    }
    return;
}

int main()
{
    char order;
    int n;

    // 初始化集合
    scanf("%d\n", &n);
    Initialize(n);
    do
    {
        // 读入一条指令；
        scanf("%c", &order);
        // 处理指令；
        switch (order)
        {
            case 'I': Input_connection(); break;
            case 'C': Check_connection(); break;
            case 'S': Check_network(n); break;
        }
    } while (order != 'S');
    return 0;
}
