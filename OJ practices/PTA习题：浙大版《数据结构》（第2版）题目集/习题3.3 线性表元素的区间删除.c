/*
 @Date    : 2018-09-06 16:18:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/966247795744329728
 */

#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */
List Delete( List L, ElementType minD, ElementType maxD )
{
    int deleted[MAXSIZE];
    ElementType temp[MAXSIZE];
    for (int i = 0; i != L->Last + 1; ++i)
    {
        ElementType value = (L->Data)[i];
        if (value < maxD && minD < value)
        {
            deleted[i] = 1;
        }
        else
        {
            deleted[i] = 0;
            temp[i] = value;
        }
    }
    int l = 0;
    for (int i = 0; i != L->Last + 1; ++i)
    {
        if (deleted[i] == 0)
        {
            (L->Data)[l++] = temp[i];
        }
    }
    L->Last = l - 1;
    return L;
}

