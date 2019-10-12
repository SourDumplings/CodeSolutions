/*
 @Date    : 2017-12-02 15:21:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1026
来自：http://www.cnblogs.com/huhuuu/p/3360207.html
题意自己理解了，主要是两个队列维护，一个VIP队列，一个普通队列
搜集了一些坑（有些坑转自别的网站用于广大同学的测试之用）

普通人也有VIP的权益！！！ 屌丝逆袭有木有！！！
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
10 10
1 2 3 4 5 6 7 8 9 10
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:10:00 08:10:00 0
08:12:00 08:12:00 0
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
20:53:00 20:53:00 0
2 2 2 2 1 0 0 0 0 0

1.当有多个乒乓球台空闲时，vip顾客到了会使用最小id的vip球台，而不是最小id的球台，测试以下用例：
2
10:00:00 30 1
12:00:00 30 1
5 1
3
输出正确结果应为：
10:00:00 10:00:00 0
12:00:00 12:00:00 0
0 0 2 0 0

2.题目要求每对顾客玩的时间不超过2小时，那么当顾客要求玩的时间>2小时的时候，应该截断控制，测试以下用例：
2
18:00:00 180 1
20:00:00 60 1
1 1
1
输出的正确结果应为：
18:00:00 18:00:00 0
20:00:00 20:00:00 0
2
3.虽然题目中保证客户到达时间在08:00:00到21:00:00之间，但是根据最后的8个case来看，里面还是有不在这个时间区间内到达的顾客，所以建议还是稍加控制，测试以下用例：
1
21:00:00 80 1
1 1
1
输出的正确结果应为：
0
4.题目中说的round up to an integer minutes是严格的四舍五入，需要如下做：
wtime = (stime - atime + 30) / 60
而不是：
wtime = (stime - atime + 59) / 60

 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000
#define MAXK 100
#define ERROR -1
#define INFINITY 99999

typedef struct PAIR *Pair;
struct PAIR
{
    int A, P; // 到达和玩的时间，单位是秒
    int isvip; // 1代表VIP，0代表非VIP，-1代表懒惰删除的VIP
    int waittime; // 等待时间，单位是秒
    int servingtime;
};

typedef struct QUEUE *Queue;
struct QUEUE
{
    int *data;
    int front, rear;
    int maxsize;
    int *vipdata;
    int vipfront, viprear;
};

typedef struct TABLE *Table;
struct TABLE
{
    int served;
    int isviptable;
};

Pair P[MAXN];
Table T[MAXK];
int servednum = 0;

int IsEmpty(Queue Q)
{
    return Q->front == Q->rear;
}

int IsFull(Queue Q)
{
    return Q->front == (Q->rear + 1) % Q->maxsize;
}

int IsVIPHere(Queue Q, int nowtime)
{
    if (Q->vipfront != Q->viprear && P[Q->data[Q->vipdata[Q->vipfront+1]]]->A <= nowtime)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void AddQ(Queue Q, int X)
{
    if (!IsFull(Q))
    {
        Q->rear = (Q->rear + 1) % Q->maxsize;
        Q->data[Q->rear]= X;
        if (P[X]->isvip)
        {
            Q->vipdata[++Q->viprear] = Q->rear;
        }
    }
    else
    {
        printf("Queue is full!\n");
    }
    return;
}

int DeleteQ(Queue Q)
{
    if (!IsEmpty(Q))
    {
        while (!IsEmpty(Q) && P[Q->data[Q->front+1]]->isvip == -1)
        {
            Q->front = (Q->front + 1) % Q->maxsize;
        }
        if (IsEmpty(Q))
        {
            return ERROR;
        }
        Q->front = (Q->front + 1) % Q->maxsize;
        if (P[Q->data[Q->front]]->isvip == 1)
        {
            Q->vipfront++;
        }
        return Q->data[Q->front];
    }
    else
    {
        return ERROR;
    }
}

int DeleteVIP(Queue Q, int nowtime)
{
    if (IsVIPHere(Q, nowtime))
    {
        Q->vipfront++;
        P[Q->data[Q->vipdata[Q->vipfront]]]->isvip = -1;
        return Q->data[Q->vipdata[Q->vipfront]];
    }
    else
    {
        return ERROR;
    }
}

int GetTime(int h, int m, int s)
{
    int time;
    time = (h - 8) * 3600 + m * 60 + s;
    return time;
}

int compare(const void *a, const void *b)
{
    return (*(Pair *)a)->A - (*(Pair *)b)->A;
}

void ReGetTime(int *ph, int *pm, int *ps, int time)
{
    *ps = time % 60;
    *ph = time / 3600 + 8;
    *pm = (time - ((*ph - 8) * 3600)) / 60;
    return;
}

void OutPut(int N, int K)
{
    int i;
    int h, m, s;
    for (i = 0; i < N; i++)
    {
        if (P[i]->waittime == ERROR)
        {
            // 这两人没有在闭馆前打上球
            break;
        }
        ReGetTime(&h, &m, &s, P[i]->A);
        printf("%02d:%02d:%02d ", h, m, s);
        ReGetTime(&h, &m, &s, P[i]->servingtime);
        printf("%02d:%02d:%02d ", h, m, s);
        printf("%d\n", (P[i]->waittime + 30)/60);
    }
    int output = 0;
    for (i = 0; i < K; i++)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", T[i]->served);
    }
    putchar('\n');
    return;
}

int FindAvailT(Queue Q, int trestime[], int K, int *pnowtime, int isnextvip)
{
    int tavail = 0, minrestime = trestime[0];
    int i;
    for (i = 0; i < K; i++)
    {
        if (trestime[i] < minrestime)
        {
            minrestime = trestime[i];
            tavail = i;
        }
    }
    *pnowtime += minrestime;
    for (i = 0; i < K; i++)
    {
        trestime[i] -= minrestime;
    }
    // 检查VIP状态，
    if (isnextvip)
    {
        // 如果告诉你下一对人就是VIP的话检查VIP桌子的状态返回编号最小的VIP桌
        for (i = 0; i < K; i++)
        {
            if (T[i]->isviptable && trestime[i] == 0)
            {
                tavail = i;
                break;
            }
        }
    }
    else
    {
        // 如果VIP桌空闲并且在这个时刻下队伍中有VIP桌则返回第一个VIP桌
        for (i = 0; i < K; i++)
        {
            if (T[i]->isviptable && trestime[i] == 0 && IsVIPHere(Q, *pnowtime))
            {
                tavail = i;
                break;
            }
        }
    }

    return tavail;
}

void WaitToPlay(Queue Q, int N, int K)
{
    int nowtime = 0;
    int tavail;
    int trestime[K];
    int next;
    int i;
    for (i = 0; i < K; i++)
    {
        trestime[i] = 0;
    }
    while (!IsEmpty(Q))
    {
        tavail = FindAvailT(Q, trestime, K, &nowtime, 0);
        if (IsVIPHere(Q, nowtime) && T[tavail]->isviptable)
        {
            next = DeleteVIP(Q, nowtime);
        }
        else
        {
            next = DeleteQ(Q);
        }
        if (next == ERROR)
        {
            break;
        }
        if (P[next]->A > nowtime)
        {
            for (i = 0; i < K; i++)
            {
                trestime[i] -= P[next]->A - nowtime;
                if (trestime[i] < 0)
                {
                    trestime[i] = 0;
                }
            }
            nowtime = P[next]->A;
            tavail = FindAvailT(Q, trestime, K, &nowtime, P[next]->isvip);
        }
        if (nowtime >= 46800)
        {
            // printf("$$This customer has arrived too late.$$\n");
            P[next]->waittime = ERROR;
            break;
        }
        // printf("$$next pair is arrived at %d, go to table %d. $$\n", P[next]->A, tavail);
        P[next]->waittime = nowtime - P[next]->A;
        P[next]->servingtime = nowtime;
        trestime[tavail] = P[next]->P;
        T[tavail]->served++;
        // printf("&&Table %d has served %d pairs.$$\n", tavail, T[tavail]->served);
    }
    return;
}

int compareservingtime(const void *a, const void *b)
{
    return (*(Pair *)a)->servingtime - (*(Pair *)b)->servingtime;
}

int main()
{
    int N;
    scanf("%d", &N);
    int i;
    int h, m, s, p;
    int time; // 距离8:00:00的秒数
    for (i = 0; i < N; i++)
    {
        P[i] = (Pair)malloc(sizeof(struct PAIR));
        scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &P[i]->isvip);
        p = p > 120 ? 120 : p;
        P[i]->P = p * 60;
        time = GetTime(h, m, s);
        P[i]->A = time;
        P[i]->servingtime = INFINITY;
    }
    qsort(P, N, sizeof(P[0]), compare);

    int K, M, vip;
    scanf("%d %d", &K, &M);
    for (i = 0; i < K; i++)
    {
        T[i] = (Table)malloc(sizeof(struct TABLE));
        T[i]->served = 0;
        T[i]->isviptable = 0;
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d", &vip);
        T[vip-1]->isviptable = 1;
    }
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QUEUE));
    Q->vipfront = Q->viprear = Q->front = Q->rear = 0;
    Q->maxsize = N + 1;
    Q->data = (int *)malloc((N + 1) * sizeof(int));
    Q->vipdata = (int *)malloc((N + 1) * sizeof(int));
    for (i = 0; i < N; i++)
    {
        AddQ(Q, i);
        // printf("$$%d arrived pair has enqueue, vip = %d.$$\n", P[i]->A, P[i]->isvip);
    }
    WaitToPlay(Q, N, K);
    qsort(P, N, sizeof(P[0]), compareservingtime);
    OutPut(N, K);

    free(Q->data);
    free(Q->vipdata);
    free(Q);
    for (i = 0; i < K; i++)
    {
        free(T[i]);
    }
    return 0;
}

