#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode
{
    int v;
    Tree Left, Right;
    int flag; // 标记该节点是否被访问过
};

Tree NewNode(int V)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->v = V;
    T->Left = T->Right = NULL;
    T->flag = 0;
    return T;
}

Tree Insert(Tree T, int V)
{
    if (!T)
    {
        T = NewNode(V);
    }
    else
    {
        if (V > T->v)
        {
            T->Right = Insert(T->Right, V);
        }
        else
        {
            T->Left = Insert(T->Left, V);
        }
    }
    return T;
}

int check(Tree T, int V)
{
    if (T->flag)
    {
        if (V < T->v)
        {
            return check(T->Left, V);
        }
        else if (V > T->v)
        {
            return check(T->Right, V);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (V == T->v)
        {
            T->flag = 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int Judge(Tree T, int N)
{
    int i, V;
    int flag = 1;
    // flag = 1代表目前还一致，0代表已经不一致

    scanf("%d", &V);
    // 先检查根节点
    if (V != T->v)
    {
        flag = 0;
    }
    else
    {
        T->flag = 1;
    }

    // 对后面N-1个数逐个的进行check
    for (i = 1; i < N; i++)
    {
        scanf("%d", &V);
        if ((!check(T, V)) && (flag))
        {
            flag = 0;
            // 当发现序列中的某个数与T不一致时，必须把序列后面的数都读完
            // 否则就会把这个序列后面的数当成是下个序列的数了
        }
    }

    return flag;
}

Tree MakeTree(int N)
{
    Tree T;
    int i, V;

    scanf("%d", &V);
    T = NewNode(V);
    for (i = 1; i < N; i++)
    {
        scanf("%d", &V);
        T = Insert(T, V);
    }
    return T;
}

void ResetT(Tree T)
{
    if (T->Left)
    {
        ResetT(T->Left);
    }
    if (T->Right)
    {
        ResetT(T->Right);
    }
    T->flag = 0;
}

void FreeTree(Tree T)
{
    if (T->Left)
    {
        FreeTree(T->Left);
    }
    if (T->Right)
    {
        FreeTree(T->Right);
    }
    free(T);
}

int main()
{
    int N, L, i;
    Tree T;
    int result[100];
    int j = 0;

    scanf("%d", &N);
    while (N)
    {
        scanf("%d", &L);
        T = MakeTree(N);
        for (i = 0; i < L; i++)
        {
            if (Judge(T, N))
            {
                result[j++] = 1;
            }
            else
            {
                result[j++] = 0;
            }
            ResetT(T); // 清零T中的标记flag
        }
        FreeTree(T);
        scanf("%d", &N);
    }
    result[j] = -1;

    for (i = 0; result[i] != -1; i++)
    {
        if (result[i])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
