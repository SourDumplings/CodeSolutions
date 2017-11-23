#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct STACK *Stack;
struct STACK
{
    int top;
    int maxsize;
    int data[MAX];
};

typedef struct TREENODE *Tree;
struct TREENODE
{
    int data;
    Tree left;
    Tree right;
};

Stack CreateStack(int N)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct STACK));
    S->top = -1;
    S->maxsize = N;
    return S;
}

void Push(Stack S, int item)
{
    if (S->top == S->maxsize - 1)
        // 堆栈满
    {
        return;
    }
    else
    {
        S->data[(++S->top)] = item;
        return;
    }
}

int Pop(Stack S)
{
    if (S->top == -1)
    {
        // 堆栈空
        return 0;
    }
    else
    {
        return S->data[(S->top)--];
    }
}

Tree ObtainTree(int pre_seq[], int mid_seq[], int N)
{
    Tree T = NULL;
    int i = 0, j = 0, k = 0, h = 0;
    int new_pre_left[MAX] = {0}, new_mid_left[MAX] = {0};
    int new_pre_right[MAX] = {0}, new_mid_right[MAX] = {0};
    int N_left = 0, N_right = 0; // 记录左右子树的节点数

    if (!N)
    {
        return NULL;
    }

    T = (Tree)malloc(sizeof(struct TREENODE));
    T->data = pre_seq[0];
    T->left = T->right = NULL;

    if (N == 1)
    {
        return T;
    }

    // 以根节点为分界，对中序遍历序列扫描，得到左右子树的中序遍历序列
    for (i = 0; i < N; i++)
    {
        if (mid_seq[i] == pre_seq[0])
        {
            i++;
            for (; i < N; i++)
            {
                new_mid_right[j++] = mid_seq[i];
            }
            N_right = j;
            break;
        }
        else
        {
            new_mid_left[i] = mid_seq[i];
            N_left = i + 1;
        }
    }

    // 对先序遍历序列扫描，得到左右子树的先序遍历序列
    for (i = 1; i < N; i++)
    {
        for (j = 0; new_mid_left[j] || new_mid_right[j]; j++)
        {
            if (new_mid_left[j] == pre_seq[i])
            {
                new_pre_left[k++] = pre_seq[i];
                break;
            }
            else if (new_mid_right[j] == pre_seq[i])
            {
                new_pre_right[h++] = pre_seq[i];
                break;
            }
        }
    }

    T->left = ObtainTree(new_pre_left, new_mid_left, N_left);
    T->right = ObtainTree(new_pre_right, new_mid_right, N_right);


    return T;
}

void PostOrderTraversal(Tree T, int rootdata)
{
    if (T)
    {
        PostOrderTraversal(T->left, rootdata);
        PostOrderTraversal(T->right, rootdata);
        printf("%d", T->data);
        if (T->data != rootdata)
        {
            putchar(' ');
        }
    }
    return;
}

int main()
{
    int N;
    Stack S = NULL;
    int i, j = 0, k = 0;
    char order[5];
    int item;
    Tree T = NULL;
    int mid_seq[MAX] = {0};
    int pre_seq[MAX] = {0};
    int rootdata;


    scanf("%d", &N);

    S = CreateStack(N);

    // 得到该树的中序和先序遍历序列
    for (i = 0; i < 2*N; i++)
    {
        scanf("%s", order);
        if (!strcmp(order, "Pop"))
        {
            mid_seq[j++] = Pop(S);
        }
        else
        {
            scanf("%d", &item);
            Push(S, item);
            pre_seq[k++] = item;
        }
    }

    rootdata = pre_seq[0];

    // // 打印下通过堆栈实现的中序序列
    // for (i = 0; i < N; i++)
    // {
    //     printf("%d", mid_seq[i]);
    // }
    // putchar('\n');

    // 根据中序和先序遍历还原该树的结构
    T = ObtainTree(pre_seq, mid_seq, N);

    // 后续遍历T并输出结果
    PostOrderTraversal(T, rootdata);
    putchar('\n');

    return 0;
}
