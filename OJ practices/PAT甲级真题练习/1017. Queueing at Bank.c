/*
 @Date    : 2017-11-30 09:51:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1017
这个题的数据不是按照先来后到的顺序给的，因此要先排个序，队列还是直接用数组好些
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct PERSON *Person;
struct PERSON
{
    // 时间单位为秒
    int T;
    int P;
};

typedef struct QNODE *Qnode;
struct QNODE
{
    Person data;
    Qnode next;
};

typedef struct QUEUE *Queue;
struct QUEUE
{
    Qnode front, rear;
    int size;
};

typedef struct TIME Time;
struct TIME
{
    int h, m, s;
};

int N, K;

int IsEmpty(Queue Q)
{
    return Q->size == 0;
}

void AddQ(Queue Q, Qnode newqnode)
{
    Q->rear->next = newqnode;
    Q->rear = newqnode;
    Q->size++;
    return;
}

Qnode DeleleQ(Queue Q)
{
    if (!IsEmpty(Q))
    {
        Q->front = Q->front->next;
        Q->size--;
        return Q->front;
    }
    else
    {
        printf("Queue is empty!\n");
        return Q->front;
    }
}

int GetTime(Time T)
{
    // 以00:00:00为起点计算时间，单位为秒
    int result;
    result = (T.h) * 3600 + (T.m) * 60 + T.s;
    return result;
}

int FindAvailWindow(int restime[], int *pnowtime)
{
    int availwindow = 0;
    int i;
    int min_res = restime[0];
    for (i = 1; i < K; i++)
    {
        if (restime[i] < min_res)
        {
            min_res = restime[i];
            availwindow = i;
        }
    }
    *pnowtime += min_res;
    for (i = 0; i < K; i++)
    {
        restime[i] -= min_res;
    }
    return availwindow;
}

double WaiteInBank(Queue Q)
{
    int restime[K]; // 记录每个窗口还剩多久完事，单位为秒
    int totalwaittime = 0; // 记录总等待时间，单位为秒
    int availwindow; // 记录可供使用的窗口
    int nowtime; // 记录现在时刻
    int i;
    int N_served = 0; // 记录实际服务的顾客数
    Time open, close;
    int opentime, closetime;
    Person nextcustomer;
    int waittime = 0;
    for (i = 0; i < K; i++)
    {
        restime[i] = 0;
    }
    close.h = 17;
    open.h = 8;
    close.m = open.m = 0;
    close.s = open.s = 0;
    opentime = GetTime(open);
    // printf("$$Opentime is %ds.$$\n", opentime);
    closetime = GetTime(close);
    // printf("$$Closetime is %ds.$$\n", closetime);
    nowtime = opentime;
    while (!IsEmpty(Q))
    {
        availwindow = FindAvailWindow(restime, &nowtime);
        nextcustomer = DeleleQ(Q)->data;
        // printf("$$This customer arrived at %ds.$$\n", nextcustomer->T);
        waittime = 0;
        if (nextcustomer->T > closetime)
        {
            // 顾客来晚了，说明银行已经关门了
            // printf("$$This customer arrived too late.$$\n");
            break;
        }
        if (nextcustomer->T < opentime)
        {
            // 顾客来早了，先等到开门的时间
            waittime += opentime - nextcustomer->T;
            nextcustomer->T = opentime;
        }
        else if (nextcustomer->T > nowtime)
        {
            // 窗口需要等顾客了
            for (i = 0; i < K; i++)
            {
                restime[i] -= nextcustomer->T - nowtime;
                if (restime[i] < 0)
                {
                    restime[i] = 0;
                }
            }
            nowtime = nextcustomer->T;
            // 有可能出现小序号的窗口空闲出来了，因此再次寻找一遍可服务的窗口
            availwindow = FindAvailWindow(restime, &nowtime);
        }
        // 顾客到availwindow接受服务
        restime[availwindow] = nextcustomer->P;
        waittime += nowtime - nextcustomer->T;
        // printf("$$Now time is %d.$$\n", nowtime);
        // printf("$$This customer is served at window %d.$$\n", availwindow);
        // printf("$$This customer will occupied the window for %d.\n", nextcustomer->P);
        // printf("$$This customer waited for %ds.$$\n\n", waittime);
        totalwaittime += waittime;
        N_served++;
    }
    // printf("$$Totalwaittime is %ds.$$\n", totalwaittime);
    // printf("$$The bank has served %d customers.$$\n", N_served);
    return ((double)totalwaittime / 60) / N_served;
}

int compare(const void *a, const void *b)
{
    return (*(Person *)a)->T - (*(Person *)b)->T;
}

int main()
{
    scanf("%d %d", &N, &K);
    int i;
    Time A;
    int tp;
    Person p;
    Person personqueue[N];
    Qnode newqnode, Qhead;
    Queue Q;

    Qhead = (Qnode)malloc(sizeof(struct QNODE));
    Qhead->next = NULL;
    Q = (Queue)malloc(sizeof(struct QUEUE));
    Q->size = 0;
    Q->front = Q->rear = Qhead;
    for (i = 0; i < N; i++)
    {
        p = (Person)malloc(sizeof(struct PERSON));
        scanf("%d:%d:%d %d", &A.h, &A.m, &A.s, &tp);
        p->T = GetTime(A);
        p->P = tp * 60;
        if (p->P > 3600)
        {
            p->P = 3600;
        }
        personqueue[i] = p;
    }
    // 对输入的数据进行排序，按照先来后到的顺序入队
    qsort(personqueue, N, sizeof(personqueue[0]), compare);
    for (i = 0; i < N; i++)
    {
        newqnode = (Qnode)malloc(sizeof(struct QNODE));
        newqnode->data = personqueue[i];
        newqnode->next = NULL;
        AddQ(Q, newqnode);
    }
    double atime;
    atime = WaiteInBank(Q);
    printf("%.1f\n", atime);
    return 0;
}

