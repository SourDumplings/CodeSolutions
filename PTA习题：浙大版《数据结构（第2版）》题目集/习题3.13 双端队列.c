/*
 @Date    : 2017-11-17 15:36:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6096
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, inject, eject, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /* 存储元素的数组   */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量     */
};
typedef PtrToQNode Deque;

Deque CreateDeque( int MaxSize )
{   /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}

bool Push( ElementType X, Deque D );
ElementType Pop( Deque D );
bool Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* 裁判实现，细节不表 */
void PrintDeque( Deque D ); /* 裁判实现，细节不表 */

int main()
{
    ElementType X;
    Deque D;
    int N, done = 0;

    scanf("%d", &N);
    D = CreateDeque(N);
    while (!done) {
        switch(GetOp()) {
        case push:
            scanf("%d", &X);
            if (!Push(X, D)) printf("Deque is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            else printf("%d is out\n", X);
            break;
        case inject:
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Deque is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            else printf("%d is out\n", X);
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

#include <string.h>

Operation GetOp()
{
    Operation O;
    char s[10];
    scanf("%s", s);
    if (strcmp(s, "Pop") == 0)
    {
        O = pop;
    }
    else if (strcmp(s, "Inject") == 0)
    {
        O = inject;
    }
    else if (strcmp(s, "Eject") == 0)
    {
        O = eject;
    }
    else if (strcmp(s, "Push") == 0)
    {
        O = push;
    }
    else if (strcmp(s, "End") == 0)
    {
        O = end;
    }
    return O;
}

void PrintDeque( Deque D )
{
    if (D->Rear == D->Front)
    {
        printf("Deque is Empty!\n");
    }
    else
    {
        printf("Inside Deque:");
        int i;
        for (i = D->Front; i < D->Rear; i++)
        {
            printf(" %d", D->Data[i]);
        }
    }
    putchar('\n');
    return;
}

/* 你的代码将被嵌在这里 */

// 认为头元素的位置始终在0处
// 将元素X插入到双端队列D的头

bool Push( ElementType X, Deque D )
{
    if (D->Rear == D->MaxSize - 1)
    {
        return false;
    }
    else
    {
        int i;
        for (i = D->Rear+1; i > 0; i--)
        {
            D->Data[i] = D->Data[i-1];
        }
        D->Data[0] = X;
        D->Rear++;
        return true;
    }
}
// 删除双端队列D的头元素，并返回
ElementType Pop( Deque D )
{
    if (D->Rear == 0)
    {
        return ERROR;
    }
    else
    {
        int temp = D->Data[0];
        int i;
        for (i = 0; i < D->Rear; i++)
        {
            D->Data[i] = D->Data[i+1];
        }
        D->Rear--;
        return temp;
    }
}
// 将元素X插入到双端队列D的尾部
bool Inject( ElementType X, Deque D )
{
    if (D->Rear == D->MaxSize - 1)
    {
        return false;
    }
    else
    {
        D->Data[D->Rear++] = X;
        return true;
    }
}
// 删除双端队列D的尾部元素，并返回
ElementType Eject( Deque D )
{
    if (D->Rear == 0)
    {
        return ERROR;
    }
    else
    {
        return D->Data[--D->Rear];
    }
}
