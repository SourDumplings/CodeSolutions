/*
 @Date    : 2017-11-21 12:09:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6476
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXV 10000

int Graph[MAXV][MAXV];
int Nv, Ne;
int Q[MAXV];
int front = -1;
int rear = -1;
int size = 0;

int Visited[MAXV] = {0};

int OneLevelBFS(void)
{
    int V, W;
    int thislevelnum = 0;
    int read= 0;
    while (front != rear && read < size)
    {
        front = (front + 1) % MAXV;
        V = Q[front];
        // printf("$$%d$$", V+1);
        read++;
        for (W = 0; W < Nv; W++)
        {
            if (!Visited[W] && Graph[V][W])
            {
                Visited[W] = 1;
                thislevelnum++;
                if ((rear + 1) % MAXV != front)
                {
                    rear = (rear + 1) % MAXV;
                    Q[rear] = W;
                }
            }
        }
    }
    size = thislevelnum;
    return thislevelnum;
}

int SixDegreeSpace(int S)
{
    int num = 0; // 代表与S相距6以内的结点数
    Visited[S] = 1;
    int i;
    Q[0] = S;
    rear = 0;
    front = -1;
    size = 1;
    for (i = 0; i < 6; i++)
    {
        num += OneLevelBFS();
    }
    return num+1;
}

int main()
{
    scanf("%d %d", &Nv, &Ne);
    int V, W;
    for (V = 0; V < Nv; V++)
    {
        for (W = 0; W < Nv; W++)
        {
            Graph[V][W] = 0;
        }
    }
    int i;
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d", &V, &W);
        Graph[V-1][W-1] = 1;
        Graph[W-1][V-1] = 1;
    }

    int num; // 统计与每个结点的距离不超过6的结点数
    for (V = 0; V < Nv; V++)
    {
        num = SixDegreeSpace(V);
        // printf("##num = %d##", num);
        printf("%d: %.2f%%\n", V+1, (double)num/Nv * 100);
        for (W = 0; W < Nv; W++)
        {
            Visited[W] = 0;
        }
    }

    return 0;
}


