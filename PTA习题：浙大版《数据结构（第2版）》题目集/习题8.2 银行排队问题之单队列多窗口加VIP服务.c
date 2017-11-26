/*
 @Date    : 2017-11-24 16:08:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6516
注意题目的意思：有些银行会给VIP客户以各种优惠服务，例如专门开辟VIP窗口。
为了最大限度地利用资源，VIP窗口的服务机制定义为：
当队列中没有VIP客户时，该窗口为普通顾客服务；当该窗口空闲并且队列中有VIP客户在等待时，排在最前面的VIP客户享受该窗口的服务。
同时，当轮到某VIP客户出列时，若VIP窗口非空，该客户可以选择空闲的普通窗口；
否则一定选择VIP窗口！这个和课本上是不一样的！
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
#define MAXK 10
#define MAXP 60
#define EMPTYQ -1

typedef struct
{
    int T;
    int P;
    int VIP;
} People;

typedef struct QNODE *Queue;
struct QNODE
{
    People *data;
    int front, rear;
    int maxsize;
    int VIPfront, VIPrear;
    int *VIPcustomer; // 记录VIP在队列中的位置的队列
    int VIPsize;
};

Queue CreateQueue(int N)
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNODE));
    Q->maxsize = N;
    Q->VIPrear = Q->VIPfront = Q->front = Q->rear = -1;
    Q->data = (People *)malloc(N * sizeof(People));
    Q->VIPcustomer = (int *)malloc(N * sizeof(People));
    return Q;
}

int IsFull(Queue Q)
{
    return Q->front == (Q->rear + 1) % Q->maxsize;
}

int IsEmpty(Queue Q)
{
    // 无法判断是否存在懒惰删除的元素，在DeleteQ的时候才能判断出来
    return Q->front == Q->rear;
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


int VIPIsEmpty(Queue Q)
{
    return !Q->VIPsize;
}

int VIPIsFull(Queue Q)
{
    return Q->VIPsize == Q->maxsize;
}

void AddVIP(Queue Q, People P)
{
    if (!VIPIsFull(Q))
    {
        Q->data[++Q->rear] = P;
        Q->VIPcustomer[++Q->VIPrear] = Q->rear;
        Q->VIPsize++;
    }
    else
    {
        printf("Queue is full!\n");
    }
    return;
}

People DeleteVIP(Queue Q)
{
    People tempP;
    if (!VIPIsEmpty(Q))
    {
        int VIPposition;
        VIPposition = Q->VIPcustomer[++Q->VIPfront];
        Q->VIPsize--;
        tempP = Q->data[VIPposition];
        Q->data[VIPposition].VIP = -1; // 懒惰删除
        // printf("VIP customer has been lazily deleted!\n");
    }
    else
    {
        printf("No VIP\n");
    }
    return tempP;
}

People DeleteQ(Queue Q)
{
    People tempP;
    while (Q->data[Q->front+1].VIP == -1)
    {
     // 将位于队首的被懒惰删除的元素真正删除
        Q->front++;
        // printf("$$Lazily deleted VIP has been deleted!&&\n");
    }
    if (IsEmpty(Q))
    {
        tempP.T = EMPTYQ; // 如果队列空则返回空信号
        // printf("Queue is Empty!\n");
    }
    else
    {
        tempP = Q->data[++Q->front];
        if (tempP.VIP)
        {
            tempP = DeleteVIP(Q);
        }
    }
    return tempP;
}


void DestroyQueue(Queue Q)
{
    free(Q->data);
    free(Q->VIPcustomer);
    free(Q);
    return;
}

int K; // 营业窗口个数
int window_t[MAXK] = {0}; // 营业窗口需要处理事务的剩余时间长度
int window_p[MAXK] = {0}; // 营业窗口处理的顾客数
int totaltime = 0; // 全体顾客等待总时间
int finishtime = 0; // 最后完成时间
int maxwaittime = 0; // 最长等待时间
int VIPwindow; // VIP窗口编号
int winavail; // 空闲窗口的位置


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

int IsVIPHere(Queue Q, int currenttime)
{
    int flag = 0;
    if (Q->VIPsize && Q->data[Q->VIPcustomer[Q->VIPfront+1]].T <= currenttime)
    {
        flag = 1;
    }
    return flag;
}

int IsVIPWindowAvail()
{
    if (window_t[VIPwindow] == 0)
    {
        // printf("VIPwindow is available\n");
        return 1;
    }
    return 0;
}

double QueueingAtBank(Queue Q, int N)
{
    People next; // 下一位顾客
    int currenttime = 0; // 当前时间，开门营业时间为0
    int waittime; // 相邻两次窗口空闲状态之间的等待时间
    int i, j;
    double meant;

    while (!IsEmpty(Q))
    {
        // 当队列非空时，持续处理
        // 处理掉当前最短的事务，得到下一个空闲窗口
        winavail = FindNextWindow(&waittime);
        currenttime += waittime;
        // 下一位顾客出列
        if (IsVIPWindowAvail() && IsVIPHere(Q, currenttime))
        {
            // 如果VIP窗口空闲且有VIP在队中等待则VIP出列
            next = DeleteVIP(Q);
            winavail = VIPwindow;
        }
        else
        {
            next = DeleteQ(Q);
        }
        if (next.T == EMPTYQ)
        {
            // 如果收到队列已空的信号则退出循环
            break;
        }

        // printf("$$Next customer: T=%d, P=%d, VIP=%d.$$\n", next.T, next.P, next.VIP);

        if (currenttime >= next.T)
        {
            // 如果顾客已经到达

            if (currenttime - next.T)
            {
                // printf("$$This customer has waited for %d time.$$\n", currenttime - next.T);
            }
            else
            {
                // printf("$$This customer doesn't need to wait.$$\n");
            }

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
            if (IsVIPWindowAvail() && next.VIP)
            {
                // 如果VIP窗口空出来了而等到的是VIP，则VIP用VIP窗口
                winavail = VIPwindow;
            }
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
        scanf("%d %d %d", &X.T, &X.P, &X.VIP);
        if (X.P > MAXP)
        {
            X.P = MAXP;
        }
        if (X.VIP)
        {
            AddVIP(Q, X);
        }
        else
        {
            AddQ(Q, X);
        }
    }

    // for (i = Q->front+1;;i++)
    // {
    //     printf("$$Customer %d is in Queue. T = %d, P = %d, VIP = %d.$$\n",
    //         i, Q->data[i].T, Q->data[i].P, Q->data[i].VIP);
    //     if (i == Q->rear)
    //     {
    //         break;
    //     }
    // }

    scanf("%d %d", &K, &VIPwindow);

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


