/*
 @Date    : 2018-03-11 13:45:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/965573204499779584
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

List ReadInput()
{
    List L = (List)malloc(sizeof(struct LNode));
    int N;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
        scanf("%d", &L->Data[i]);
    L->Last = N - 1;
    return L;
}

void PrintList(List L)
{
    int output = 0;
    for (int i = 0; i <= L->Last; ++i)
    {
        if (output++) putchar(' ');
        printf("%d", L->Data[i]);
    }
    putchar('\n');
    printf("Last = %d\n", L->Last);
    return;
}

/* 你的代码将被嵌在这里 */

Position binary_search(List L, ElementType X)
{
    Position lo = 0, hi = L->Last + 1;
    while (lo < hi)
    {
        int mi = (lo + hi) >> 1;
        // printf("L->Data[%d] = %d\n", mi, L->Data[mi]);
        (L->Data[mi] < X) ? (hi = mi) : (lo = mi + 1);
    }
    return --lo;
}

bool Insert( List L, ElementType X )
{
    if (L->Last == MAXSIZE - 1) return false;
    Position p = binary_search(L, X);
    if (L->Data[p] == X) return false;
    int i;
    for (i = L->Last + 1; i != p + 1; --i)
        L->Data[i] = L->Data[i-1];
    L->Data[i] = X;
    ++L->Last;
    return true;
}
