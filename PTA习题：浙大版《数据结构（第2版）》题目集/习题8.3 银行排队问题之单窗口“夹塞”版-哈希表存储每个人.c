/*
 @Date    : 2017-11-26 10:03:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6541
注意只有一个窗口，这个和课本上的习题不同
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXM 100
#define MAXP 60
#define MAXPEOPLE 17576 // 即26的立方
#define NOFRIENDS -1 // 没有朋友

typedef struct PEOPLE *People;
struct PEOPLE
{
    char name[4];
    int T;
    int P;
    int f; // 所在的朋友圈编号
};

typedef struct QNODE *Queue;
typedef struct QNODE *QNode;
struct QNODE
{
    // 由于要设计各种插队操作，故采用链表来存储队列
    People data;
    QNode next;
    QNode rear;
    int size; // 记录队列里有多少人
};

void AddQ(Queue Q, People P)
{
    QNode temp;
    temp = (QNode)malloc(sizeof(struct QNODE));
    temp->data = P;
    temp->next = NULL;
    Q->rear->next = temp;
    Q->rear = temp;
    return;
}

People DeleteQ(Queue Q)
{
    People P;
    QNode front = Q->next;
    Q->next = front->next;
    P = front->data;
    Q->size--;
    return P;
}

int N, M;
People HashTable[MAXPEOPLE]; // 每个人的名字都是三个大写的英文字母，则说明最多有MAXPEOPLE种可能，
// 该哈希表存储的是每个人的指针

int Hash(char name[])
{
    int h;
    h = (name[0] - 'A') * 676 + (name[1] - 'A') * 26 + (name[2] - 'A');
    return h;
}

void CreateFriendsCirles(void)
{
    int i, j, p, h;
    People P;

    // 读取并创建朋友圈
    for (i = 0; i < M; i++)
    {
        scanf("%d", &p);
        for (j = 0; j < p; j++)
        {
            P = (People)malloc(sizeof(struct PEOPLE));
            scanf("%s", P->name);
            P->f = i;
            h = Hash(P->name);
            HashTable[h] = P;
        }
    }
    return;
}

Queue CreateQueue(void)
{
    Queue Q;
    // 创建队列，带着头空结点
    Q = (Queue)malloc(sizeof(struct QNODE));
    Q->next = NULL;
    Q->rear = Q;
    Q->size = N;
    return Q;
}

Queue CustomerIntoQueue(Queue Q)
{
    int i;
    char name[4];
    int T, P;
    int h;
    People customer;
    for (i = 0; i < N; i++)
    {
        scanf("%s %d %d", name, &T, &P);
        if (P > MAXP)
        {
            P = MAXP;
        }
        h = Hash(name);
        customer = HashTable[h];
        if (!customer)
        {
            customer = (People)malloc(sizeof(struct PEOPLE));
            customer->f = NOFRIENDS;
            strcpy(customer->name, name);
            HashTable[h] = customer;
        }
        customer->T = T;
        customer->P = P;
        AddQ(Q, customer);
    }
    return Q;
}

int currenttime = 0; // 当前时间
int totalwaittime = 0; // 顾客的总等待时间
int windowretime = 0; // 窗口的剩余事务的处理时间
People inservice = NULL; // 窗口正在服务的人

int IsFriend(People datui, People hunzi)
{
    return datui->f != NOFRIENDS && datui->f == hunzi->f;
}

double QueueInBank(Queue Q)
{
    inservice = DeleteQ(Q);
    currenttime = inservice->T + inservice->P;
    QNode front, this;
    double meant;
    int count;
    QNode cutinposition = Q; // 记录插队的位置，每次夹塞都插在cutinposition的下一个

    while (1)
    {
        // 持续处理，直到队列为空

        printf("%s\n", inservice->name);

        if (Q->size == 0)
        {
            break;
        }

        // 扫描队列找出当前时间下有无inservice的人的朋友
        count = 0;
        for (front = Q; count < Q->size; front = front->next)
        {
            if (front->next)
            {
                this = front->next;
            }
            else
            {
                this = front;
            }

            if (this->data->T > currenttime)
            {
                break;
            }
            if (inservice->f != NOFRIENDS && IsFriend(inservice, this->data))
            {
                // 把this提到队列的最前面
                front->next = this->next;
                this->next = cutinposition->next;
                cutinposition->next = this;
                cutinposition = this;
            }
            count++;
        }

        cutinposition = Q;

        // 下一个人去窗口办公
        inservice = DeleteQ(Q);

        // 如果该顾客还未到达
        if (currenttime < inservice->T)
        {
            currenttime = inservice->T;
        }

        // 累计等待时间
        totalwaittime += currenttime - inservice->T;
        // 更新时间
        currenttime += inservice->P;
    }
    meant = (double)totalwaittime / N;
    return meant;
}

int main()
{
    Queue Q;
    scanf("%d %d", &N, &M);
    double meant;

    // 初始化哈希表
    int i;
    for (i = 0; i < MAXPEOPLE; i++)
    {
        HashTable[i] = NULL;
    }

    // 创建朋友圈
    CreateFriendsCirles();

    // 创建队列
    Q = CreateQueue();
    // 顾客入队
    Q = CustomerIntoQueue(Q);

    // 队列在银行接受服务并输出结果
    meant = QueueInBank(Q);
    printf("%.1f\n", meant);

    // 释放哈希表内存
    for (i = 0; i < MAXPEOPLE; i++)
    {
        if (HashTable[i])
        {
            free(HashTable[i]);
        }
    }

    return 0;
}



