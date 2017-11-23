#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define Tree int
#define Null -1

struct TreeNode
{
    Tree Left;
    Tree Right;
} T[MaxTree];

struct QUEUE
{
    Tree data[MaxTree];
    int rear;
    int front;
};

typedef struct QUEUE Queue;

Tree BuildTree(struct TreeNode T[])
{
    int i, N;
    int check[100];
    int Root;
    scanf("%d", &N);
    getchar();
    char cl, cr;

    if (N)
    {
        for (i = 0; i < N; i++)
            check[i] = 0; // 用来找出根节点
        for (i = 0; i < N; i++)
        {
            scanf("%c %c", &cl, &cr);
            getchar();
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

void AddQ(Queue *Q, Tree item)
{
    if (((*Q).rear + 1) % MaxTree == (*Q).front)
    {
        printf("队列满\n");
        return;
    }
    (*Q).rear = ((*Q).rear + 1) % MaxTree;
    (*Q).data[(*Q).rear] = item;
}

int IsEmpty(Queue Q)
{
    if (Q.rear == Q.front)
    {
        return 1;
    }
    else
        return 0;
}

Tree DeleteQ(Queue *Q)
{
    if ((*Q).front == (*Q).rear)
    {
        printf("队列空\n");
        return -1;
    }
    else
    {
        (*Q).front = ((*Q).front + 1) % MaxTree;
        return (*Q).data[(*Q).front];
    }
}

void LevelOrderTraversal(Tree R)
{
    Tree t;
    Queue Q;
    int i;
    int count = 0; // 记录打印了几个叶节点了
    Tree result[MaxTree];

    // 建立队列来进行层序遍历
    Q.front = -1;
    Q.rear = -1;
    for (i = 0; i < MaxTree; i++)
    {
        Q.data[i] = Null;
        result[i] = Null;
    }

    // 层序遍历，将结果保存在result中
    if (R == Null)
    {
        printf("\n");
        return;
    }
    else
    {
        AddQ(&Q, R);
        i = 0;
        while (!IsEmpty(Q))
        {
            t = DeleteQ(&Q);
            result[i++] = t;
            if (T[t].Left != Null)
                AddQ(&Q, T[t].Left);
            if (T[t].Right != Null)
                AddQ(&Q, T[t].Right);
        }
    }

    // 将叶节点打印
    for (i = 0; i < MaxTree; i++)
    {
        if (result[i] == Null)
        {
            printf("\n");
            return;
        }
        else if(T[result[i]].Left == Null && T[result[i]].Right == Null)
        {
            if (count)
            {
                putchar(' ');
            }
            printf("%d", result[i]);
            count++;
        }
    }
}

int main()
{
    Tree R;
    // 建立一棵树
    R = BuildTree(T);
    // 先序遍历树并打印叶节点
    LevelOrderTraversal(R);
    return 0;
}
