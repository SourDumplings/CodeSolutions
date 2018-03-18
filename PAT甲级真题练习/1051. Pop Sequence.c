/*
 @Date    : 2017-12-08 20:10:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1051
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct STACK *Stack;
struct STACK
{
    int top;
    int *data;
    int maxsize;
};

int M, N, K;

int IsFull(Stack S)
{
    return S->top == S->maxsize - 1;
}

int IsEmpty(Stack S)
{
    return S->top == -1;
}

int Push(Stack S, int X)
{
    int flag;
    if (!IsFull(S))
    {
        flag = 1;
        S->data[++S->top] = X;
    }
    else
    {
        flag = 0;
    }
    return flag;
}

int Pop(Stack S)
{
    if (!IsEmpty(S))
    {
        return S->data[S->top--];
    }
    else
    {
        return 0;
    }
}

int Check(int seq[])
{
    Stack S;
    S = (Stack)malloc(sizeof(struct STACK));
    S->maxsize = M;
    S->top = -1;
    S->data = (int *)malloc(N * sizeof(int));
    int flag = 1;
    int i;
    int n = 1;
    for (i = 0; i < N; i++)
    {
        if (!flag)
        {
            break;
        }
        if (S->data[S->top] != seq[i])
        {
            for (; n <= N && n <= seq[i]; n++)
            {
                flag = Push(S, n);
                if (!flag)
                {
                    break;
                }
            }
        }
        flag = Pop(S);
        if (flag != seq[i])
        {
            flag = 0;
        }
    }
    free(S->data);
    free(S);
    return flag;
}

int main()
{
    scanf("%d %d %d", &M, &N, &K);
    int i, j;
    int seq[N];
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &seq[j]);
        }
        if (Check(seq))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

