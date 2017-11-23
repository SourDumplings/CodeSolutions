#include <stdio.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    int i, N;
    int check[100];
    int Root;
    scanf("%d\n", &N);
    char cl, cr;

    if (N)
    {
        for (i = 0; i < N; i++)
            check[i] = 0; // 用来找出根节点
        for (i = 0; i < N; i++)
        {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
            if (cl != '-')
            {
                T[i].Left = cl - '0'; // 得到数字字符对应的整数，比如字符‘2’-‘0’ = 2
                check[T[i].Left] = 1;
            }
            else
            {
                T[i].Left = Null;
            }

            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
            {
                T[i].Right = Null;
            }
        }
        for (i = 0; i < N; i++)
        {
            if (!check[i])
                break;
        }
        Root = i;
    }
    else
        Root = Null;
    return Root;
}

int Isomorphic(Tree R1, Tree R2)
{
    // both empty
    if ((R1 == Null) && (R2 == Null))
    {
        return 1;
    }
    // one of them is empty
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
    {
        return 0;
    }
    // roots are different
    if (T1[R1].Element != T2[R2].Element)
    {
        return 0;
    }
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
    {
        // both have no left subtree
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }
    if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && \
        ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
    {
        // no need to swap the left and right
        return (Isomorphic(T1[R1].Left, T2[R2].Left) && \
            Isomorphic(T1[R1].Right, T2[R2].Right));
    }
    else
    {
        // need to swap the left and the right
        return (Isomorphic(T1[R1].Left, T2[R2].Right) && \
            Isomorphic(T1[R1].Right, T2[R2].Left));
    }
}

int main()
{
    Tree R1, R2;

    // 建二叉树1
    R1 = BuildTree(T1);
    // 建二叉树2
    R2 = BuildTree(T2);
    // 判断是否同构并输出
    if (Isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
