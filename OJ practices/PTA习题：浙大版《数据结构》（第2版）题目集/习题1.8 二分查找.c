/*
 @Date    : 2018-03-11 12:08:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/965458856133562368
此题有误，Last应为最后一个元素的后一个位置
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput()
{
    int N;
    scanf("%d", &N);
    List L = (List)malloc(sizeof(struct LNode));
    for (int i = 1; i != N + 1; ++i)
        scanf("%d", &L->Data[i]);
    L->Last = N + 1;
    return L;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X )
{
    Position lo = 1, hi =L->Last;
    while (lo < hi - 1)
    {
        Position mi = (lo + hi) >> 1;
        (X < L->Data[mi]) ? (hi = mi) : (lo = mi);
    }
    return (L->Data[lo] == X) ? lo : NotFound;
}
