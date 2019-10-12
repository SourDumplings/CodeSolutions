/*
 @Date    : 2017-11-29 11:26:22
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1014
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXK 1000
#define MAXN 20
#define ERROR -1
#define INFINITY 99999

int N, M, K, Q_q;

typedef struct QUEUE *Queue;
struct QUEUE
{
    int maxsize;
    int front, rear;
    int *data; // 存储的是每个人的下标
    int size;
};

int IsFull(Queue Q)
{
    return Q->front == (Q->rear + 1) % Q->maxsize;
}

int IsEmpty(Queue Q)
{
    return Q->rear == Q->front;
}

void AddQ(Queue Q, int X)
{
    if (!IsFull(Q))
    {
        Q->rear = (Q->rear + 1) % Q->maxsize;
        Q->data[Q->rear] = X;
        Q->size++;
    }
    return;
}

int DeleteQ(Queue Q)
{
    if (!IsEmpty(Q))
    {
        Q->front = (Q->front + 1) % Q->maxsize;
        Q->size--;
        return Q->data[Q->front];
    }
    else
    {
        return ERROR;
    }
}

void OutPutTime(int min)
{
    int hour = min / 60 + 8;
    min %= 60;
    printf("%02d:%02d\n", hour, min);
    return;
}

int processtime[MAXK];
int queries[MAXK];
int w[MAXN]; // 记录该窗口还有几分钟完事
int nowtime = 0;
int finishtime[MAXK];

int FindAvailWin(void)
{
    int i, minretime = INFINITY, min_i;
    for (i = 0; i < N; i++)
    {
        if (w[i] < minretime)
        {
            minretime = w[i];
            min_i = i;
        }
    }
    if (minretime == INFINITY)
    {
        // 证明所有窗口前的队伍都空，服务结束了
        min_i = ERROR;
    }
    else
    {
        nowtime += minretime;
        for (i = 0; i < N; i++)
        {
            if (w[i] != INFINITY)
            {
                w[i] -= minretime;
                if (w[i] < 0)
                {
                    w[i] = 0;
                }
            }
        }
    }
    return min_i;
}

void WaitInBank(Queue Q, Queue WQ[])
{
    int i;
    int winavail;
    int nextcustomer;
    int leavecustomer;
    int qavail = 0;
    int count = 0;
    for (i = 0; i < N && !IsEmpty(Q); i++)
    {
        // 初始化先让前N个人到窗口办事
        nextcustomer = DeleteQ(Q);
        w[i] = processtime[nextcustomer];
        AddQ(WQ[i], nextcustomer);
    }
    while (!IsEmpty(Q))
    {
        // 再把每个窗口的队伍填满，最多填N*M - N个
        if (count == N * M - N)
        {
            break;
        }
        nextcustomer = DeleteQ(Q);
        AddQ(WQ[qavail], nextcustomer);
        qavail = (qavail + 1) % N;
        count++;
    }
    while (1)
    {
        // 找到最早办完事的窗口
        winavail = FindAvailWin();
        if (winavail == ERROR)
        {
            // 服务结束了
            break;
        }
        else if (IsEmpty(WQ[winavail]))
        {
            w[winavail] = INFINITY; // 代表该窗口前的队伍空了，需要换下一个窗口
            continue;
        }
        leavecustomer = DeleteQ(WQ[winavail]);
        finishtime[leavecustomer] = nowtime;
        if (!IsEmpty(Q))
        {
            // 在黄线外的下一个顾客入黄线内的队伍
            nextcustomer = DeleteQ(Q);
            AddQ(WQ[winavail], nextcustomer);
        }
        // 最早办完事的窗口的最前面的人接受服务
        int f;
        f = (WQ[winavail]->front + 1) % WQ[winavail]->maxsize;
        nextcustomer = WQ[winavail]->data[f];
        w[winavail] = processtime[nextcustomer];
    }
    return;
}

int main()
{
    scanf("%d %d %d %d", &N, &M, &K, &Q_q);
    int i;
    for (i = 0; i < K; i++)
    {
        scanf("%d", &processtime[i]);
    }
    int q;
    for (i = 0; i < Q_q; i++)
    {
        scanf("%d", &q);
        queries[i] = q - 1;
    }

    Queue Q, WQ[N]; // 在黄线外的人的队列和在各个窗口黄线里的人的队列
    Q = (Queue)malloc(sizeof(struct QUEUE));
    Q->data = (int *)malloc((K+1) * sizeof(int));
    Q->maxsize = K + 1;
    Q->front = Q->rear = 0;
    for (i = 0; i < K; i++)
    {
        AddQ(Q, i);
    }
    for (i = 0; i < N; i++)
    {
        WQ[i] = (Queue)malloc(sizeof(struct QUEUE));
        WQ[i]->maxsize = M + 1;
        WQ[i]->front = WQ[i]->rear = 0;
        WQ[i]->size = 0;
        WQ[i]->data = (int *)malloc((M+1) * sizeof(int));
    }

    WaitInBank(Q, WQ);

    for (i = 0; i < Q_q; i++)
    {
        if (finishtime[queries[i]] - processtime[queries[i]] < 540)
        {
            OutPutTime(finishtime[queries[i]]);
        }
        else
        {
            printf("Sorry\n");
        }
    }
    return 0;
}

