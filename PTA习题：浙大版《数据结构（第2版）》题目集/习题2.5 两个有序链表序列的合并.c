/*
 @Date    : 2017-11-12 20:05:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5803
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read(void)
{
    List L, temp, rear;
    int i, n;
    scanf("%d", &n);
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    rear = L;
    for (i = 0; i < n; i++)
    {
        temp = (List)malloc(sizeof(struct Node));
        temp->Next = NULL;
        scanf("%d", &temp->Data);
        rear->Next = temp;
        rear = temp;
    }
    return L;
}

void Print(List L)
{
    List p = L->Next;
    if (!p)
    {
        printf("NULL\n");
        return;
    }
    for (; p->Next; p = p->Next)
    {
        printf("%d ", p->Data);
    }
    printf("%d\n", p->Data);
    return;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    List p1 = L1->Next, p2 = L2->Next;
    List L, rear;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    rear = L;
    while (p1 && p2)
    {
        if (p1->Data <= p2->Data)
        {
            rear->Next = p1;
            L1->Next = p1->Next;
            p1 = p1->Next;
        }
        else
        {
            rear->Next = p2;
            L2->Next = p2->Next;
            p2 = p2->Next;
        }
        rear = rear->Next;
    }
    while (p1)
    {
        rear->Next = p1;
        L1->Next = p1->Next;
        p1 = p1->Next;
        rear = rear->Next;
    }
    while (p2)
    {
        rear->Next = p2;
        L2->Next = p2->Next;
        p2 = p2->Next;
        rear = rear->Next;
    }
    return L;
}

