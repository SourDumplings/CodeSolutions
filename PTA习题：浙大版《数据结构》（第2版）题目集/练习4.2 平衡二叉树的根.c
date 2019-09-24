/*
 @Date    : 2017-11-17 20:42:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6103
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLTNode *AVLTree;
struct AVLTNode
{
    int Data;
    AVLTree Left;
    AVLTree Right;
};

int MAX(int a, int b)
{
    return a > b ? a : b;
}

int GetHeight(AVLTree T)
{
    int HL, HR, H_MAX;
    if (T)
    {
        HL = GetHeight(T->Left);
        HR = GetHeight(T->Right);
        H_MAX = MAX(HL, HR);
        return H_MAX + 1;
    }
    else
    {
        // 空树的树高为0
        return 0;
    }
}

AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

AVLTree InSert(AVLTree T, int X)
{
    if (!T)
    {
        T = (AVLTree)malloc(sizeof(struct AVLTNode));
        T->Data = X;
        T->Left = T->Right = NULL;
        return T;
    }
    else if (X < T->Data)
    {
        // 插入左子树
        T->Left = InSert(T->Left, X);
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
        {
            // 左右不平衡，需要调整
            if (X < T->Left->Data)
            {
                // 左单旋
                T = SingleLeftRotation(T);
            }
            else
            {
                // 左右双旋
                T = DoubleLeftRightRotation(T);
            }
        }
    }
    else if (X > T->Data)
    {
        // 插入右子树
        T->Right = InSert(T->Right, X);
        if (GetHeight(T->Right) - GetHeight(T->Left) == 2)
        {
            if (X > T->Right->Data)
            {
                // 右单旋
                T = SingleRightRotation(T);
            }
            else
            {
                // 右左双旋
                T = DoubleRightLeftRotation(T);
            }
        }
    }
    return T;
}

int main()
{
    int N;
    scanf("%d", &N);
    int i, X;
    AVLTree T;
    T = NULL;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        T = InSert(T, X);
        // printf("$$%d has been inserted$$\n", X);
    }
    printf("%d\n", T->Data);
    return 0;
}

