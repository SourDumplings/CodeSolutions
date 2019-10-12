/*
 @Date    : 2017-11-12 16:15:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5726
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
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Read(void)
{
    int n;
    scanf("%d", &n);
    List L;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List temp, rear = L;
    int i;
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
    while (p->Next)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("%d\n", p->Data);
    return;
}

/* 你的代码将被嵌在这里 */
List Insert(List L, int X)
{
    List p, temp;
    for (p = L; p->Next && p->Next->Data < X; p = p->Next);
    temp = (List)malloc(sizeof(struct Node));
    temp->Data = X;
    temp->Next = p->Next;
    p->Next = temp;
    return L;
}
