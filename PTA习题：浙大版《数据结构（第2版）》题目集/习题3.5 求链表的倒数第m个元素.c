/*
 @Date    : 2017-11-13 15:36:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5864
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

List Read()
{
    List L, rear, temp;
    int n;
    scanf("%d", &n);
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    rear = L;
    for (; n > 0; n--)
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
    List rear = L->Next;
    while (rear->Next)
    {
        printf("%d ", rear->Data);
        rear = rear->Next;
    }
    printf("%d\n", rear->Data);
    return;
}

/* 你的代码将被嵌在这里 */

#define MAX 99999

ElementType Find( List L, int m )
{
    List rear = L->Next;
    int count = 0;
    int D[MAX];
    while (rear)
    {
        D[count++] = rear->Data;
        rear = rear->Next;
    }
    if (m > count)
    {
        return ERROR;
    }
    int i = count - m;
    return D[i];
}


