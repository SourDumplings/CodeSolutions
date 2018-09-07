/*
 @Date    : 2018-03-10 13:59:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/724
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    List L = (List)malloc(sizeof(struct Node));
    PtrToNode rear = L;
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
    {
        PtrToNode temp = (PtrToNode)malloc(sizeof(struct Node));
        temp->Next = NULL;
        scanf("%d", &temp->Data);
        rear->Next = temp;
        rear = temp;
    }
    return L->Next;
}

void Print(List L)
{
    int output = 0;
    for (PtrToNode p = L; p; p = p->Next)
    {
        if (output++) putchar(' ');
        printf("%d", p->Data);
    }
    putchar('\n');
    return;
}

/* 你的代码将被嵌在这里 */
List Reverse( List L )
{
    if (!L) return NULL;
    PtrToNode temp = NULL;
    List L2 = L;
    for (PtrToNode p = L2->Next; p; p = temp)
    {
        temp = p->Next;
        p->Next = L2;
        L2 = p;
    }
    L->Next = NULL;
    return L2;
}
