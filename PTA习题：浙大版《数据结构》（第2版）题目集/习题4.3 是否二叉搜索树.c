/*
 @Date    : 2017-11-18 10:07:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6178
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}


/* 你的代码将被嵌在这里 */
int FindMax(BinTree T)
{
    if (T->Right)
    {
        return FindMax(T->Right);
    }
    else
    {
        return T->Data;
    }
}

int FindMin(BinTree T)
{
    if (T->Left)
    {
        return FindMin(T->Left);
    }
    else
    {
        return T->Data;
    }
}

bool IsBST ( BinTree T )
{
    if (!T || (!T->Left && !T->Right))
    {
        return true;
    }
    if (T->Left && T->Right)
    {
        if (T->Data > FindMax(T->Left) && T->Data < FindMin(T->Right))
        {
            return IsBST(T->Left) && IsBST(T->Right);
        }
        else
        {
            return false;
        }
    }
    if (T->Left)
    {
        if (T->Data > FindMax(T->Left))
        {
            return IsBST(T->Left);
        }
        else
        {
            return false;
        }
    }
    if (T->Right)
    {
        if (T->Data < FindMin(T->Right))
        {
            return IsBST(T->Right);
        }
        else
        {
            return false;
        }
    }
}
