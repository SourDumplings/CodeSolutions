/*
 @Date    : 2017-11-24 13:57:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6495
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
#define MAXK 10
#define MAXP 60

typedef struct
{
    int T;
    int P;
} People;

typedef struct QNODE *Queue;
struct QNODE
{
    People *data;
    int front, rear;
    int maxsize;
};

Queue CreateQueue(int N)
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNODE));
    Q->maxsize = N;
    Q->front = Q->rear = -1;
    Q->data = (People *)malloc(N * sizeof(People));
    return Q;
}

int IsEmpty(Queue Q)
{
    return Q->front == Q->rear;
}

int IsFull(Queue Q)
{
    return Q->front == (Q->rear + 1) % Q->maxsize;
}

void AddQ(Queue Q, People P)
{
    if (!IsFull(Q))
    {
        Q->data[++Q->rear] = P;
    }
    else
    {
        printf("Queue is full!\n");
    }
    return;
}

People DeleteQ(Queue Q)
{
    People tempP;
    if (!IsEmpty(Q))
    {
        tempP = Q->data[++Q->front];
    }
    else
    {
        printf("Queue is Empty!\n");
    }
    return tempP;
}

void DestroyQueue(Queue Q)
{
    free(Q->data);
    free(Q);
    return;
}

int K; // 营业窗口个数
int window_t[MAXK] = {0}; // 营业窗口需要处理事务的剩余时间长度
int window_p[MAXK] = {0}; // 营业窗口处理的顾客数
int totaltime = 0; // 全体顾客等待总时间
int finishtime = 0; // 最后完成时间
int maxwaittime = 0; // 最长等待时间

int FindNextWindow(int *pwaittime)
{
    int winavail;
    int min_time = MAXP + 1; // 最短事务处理时间，初始化超过最大值
    int i;

    for (i = 0; i < K; i++)
    {
        // 扫描所有窗口，找到最短事务
        if (window_t[i] < min_time)
        {
            min_time = window_t[i];
            winavail = i;
        }
    }
    *pwaittime = min_time;
    for (i = 0; i < K; i++)
    {
        // 刷新所有窗口的事务状态
        window_t[i] -= min_time;
    }
    return winavail;
}

double QueueingAtBank(Queue Q, int N)
{
    People next; // 下一位顾客
    int currenttime = 0; // 当前时间，开门营业时间为0
    int waittime; // 相邻两次窗口空闲状态之间的等待时间
    int winavail; // 空闲窗口的位置
    int i, j;
    double meant;

    while (!IsEmpty(Q))
    {
        // 当队列非空时，持续处理
        // 处理掉当前最短的事务，得到下一个空闲窗口
        winavail = FindNextWindow(&waittime);
        currenttime += waittime;
        // 下一位顾客出列
        next = DeleteQ(Q);

        // printf("$$Next customer is No. %d: T=%d, P=%d$$.\n", Q->front, next.T, next.P);

        if (currenttime >= next.T)
        {
            // 如果顾客已经到达

            // if (currenttime - next.T)
            // {
            //     printf("$$This customer has waited for %d time.$$\n", currenttime - next.T);
            // }
            // else
            // {
            //     printf("$$This customer doesn't need to wait.$$\n");
            // }

            totaltime += currenttime - next.T; // 累计等待时间
            if (currenttime - next.T > maxwaittime)
            {
                maxwaittime = currenttime - next.T;
            }
        }
        else
        {
            // 如果顾客还没到
            waittime = next.T - currenttime; // 空闲窗口等待顾客的时间

            // printf("$$This customer doesn't need to wait.$$\n");

            for (j = 0; j < K; j++) // 刷新所有窗口至有顾客到达的状态
            {
                window_t[j] -= waittime;
                if (window_t[j] < 0)
                {
                    window_t[j] = 0;
                }
            }
            currenttime = next.T; // 更新当前时间为顾客到达的时间
            // 可能出现多窗口空闲，由于空闲窗口按序号从小到大提供服务，因此重新找一个空闲窗口
            winavail = FindNextWindow(&waittime);
            currenttime += waittime;
        }
        // 顾客next到窗口winavail接受服务
        // printf("$$Currenttime is %d. Window %d is available$$\n\n", currenttime, winavail);
        window_t[winavail] = next.P;
        window_p[winavail]++;
    }
    meant = (double)totaltime / N;
    int max_re_time = 0; // 当前各个窗口的最大剩余处理时间
    for (i = 0; i < K; i++)
    {
        if (window_t[i] > max_re_time)
        {
            max_re_time = window_t[i];
        }
    }
    finishtime = currenttime + max_re_time;

    return meant;
}

int main()
{
    int N;
    Queue Q;
    int i;
    People X;

    scanf("%d", &N);
    Q = CreateQueue(N);

    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &X.T, &X.P);
        if (X.P > MAXP)
        {
            X.P = MAXP;
        }
        AddQ(Q, X);
    }

    scanf("%d", &K);

    double meant;
    meant = QueueingAtBank(Q, N);
    printf("%.1f %d %d\n", meant, maxwaittime, finishtime);
    int output = 0;
    for (i = 0; i < K; i++)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", window_p[i]);
    }
    putchar('\n');

    DestroyQueue(Q);

    return 0;
}

