/*
 @Date    : 2017-11-24 20:47:36
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
#define MAXT 60

typedef struct PEOPLE *People;
struct PEOPLE
{
    char name[4];
    int T;
    int P;
    People friend; // 采用一个环来存储朋友圈
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
People F[MAXM+1]; // 存储朋友圈的数组

void CreateFriendsCirles(void)
{
    int i, j, p;
    People P, lastP;

    // 读取并创建朋友圈
    for (i = 0; i < M; i++)
    {
        scanf("%d", &p);
        F[i] = (People)malloc(sizeof(struct PEOPLE));
        scanf("%s", F[i]->name);
        F[i]->friend = NULL;

        lastP = F[i];
        for (j = 1; j < p; j++)
        {
            P = (People)malloc(sizeof(struct PEOPLE));
            scanf("%s", P->name);
            P->friend = F[i];
            lastP->friend = P;
            lastP = P;
            // printf("$$This person is %s, has a friend %s\n", P->name, P->friend->name);
        }

        // printf("$$%s has a friend: %s$$\n", F[i]->name, F[i]->friend->name);

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

People FindThisPersonInCircles(char name[])
{
    int i;
    People temp;
    int flag = 0;
    for (i = 0; i < M; i++)
    {
        temp = F[i];
        if (strcmp(temp->name, name) == 0)
        {
            flag = 1;
            break;
        }
        for (temp = F[i]->friend; temp != F[i]; temp = temp->friend)
        {
            if (strcmp(temp->name, name) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        // 没在朋友圈里找到这个人
        temp = (People)malloc(sizeof(struct PEOPLE));
        strcpy(temp->name, name);
        temp->friend = NULL;
    }
    return temp;
}

Queue CustomerIntoQueue(Queue Q)
{
    int i;
    char name[4];
    int T, P;
    People customer;
    for (i = 0; i < N; i++)
    {
        scanf("%s %d %d", name, &T, &P);
        if (P > MAXT)
        {
            P = MAXT;
        }
        customer = FindThisPersonInCircles(name);
        customer->T = T;
        customer->P = P;
        // printf("$$%s has friend %s$$\n", name, customer->friend->name);
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
    People f;
    int flag = 0;
    if (datui->friend)
    {
        for (f = datui->friend; f != datui; f = f->friend)
        {
            if (hunzi == f)
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
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
            if (inservice->friend && IsFriend(inservice, this->data))
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

void FreeFriendCircle(void)
{
    int i;
    People P, temp;
    for (i = 0; i < M; i++)
    {
        P = F[i]->friend;
        while (P != F[i])
        {
            temp = P;
            P = P->friend;
            // printf("$$%s has been free$$\n", temp->name);
            free(temp);
        }
        free(F[i]);
    }
    return;
}


int main()
{
    Queue Q;
    scanf("%d %d", &N, &M);
    double meant;
    // 创建朋友圈
    CreateFriendsCirles();

    // // 输出朋友圈
    // int i;
    // People firstP, friend;
    // for (i = 0; i < M; i++)
    // {
    //     firstP = F[i];
    //     printf("$$%s's friend circle: &&", firstP->name);
    //     for (friend = firstP->friend; friend != firstP; friend = friend->friend)
    //     {
    //         printf("$$%s &&", friend->name);
    //     }
    //     printf("\n");
    // }

    // 创建队列
    Q = CreateQueue();
    // 顾客入队
    Q = CustomerIntoQueue(Q);

    // // 输出队列及队列中人的朋友
    // People P, f;
    // printf("$$Queue is:\n");
    // while (Q->next)
    // {
    //     P = DeleteQ(Q);
    //     printf("%s, friends: ", P->name);
    //     f = P->friend;
    //     while (f != P)
    //     {
    //         printf("%s ", f->name);
    //         f = f->friend;
    //     }
    //     printf("\n");
    // }
    // printf("$$\n");

    // 队列在银行接受服务并输出结果
    meant = QueueInBank(Q);
    printf("%.1f\n", meant);

    FreeFriendCircle();

    return 0;
}

