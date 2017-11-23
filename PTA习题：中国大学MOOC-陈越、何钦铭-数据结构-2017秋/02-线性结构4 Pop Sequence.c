#include <stdio.h>
#include <stdlib.h>

#define MAX 1000


typedef struct STACK *Stack;
struct STACK
{
    int data[MAX];
    int top;
    int M;
};

Stack CreateStack(int M)
{
    Stack S = (Stack)malloc(sizeof(struct STACK));
    S->top = -1;
    S->M = M;
    return S;
}

void Push(Stack S, int item)
{
    if (S->top == S->M - 1)
    {
        // 堆栈满
        return;
    }
    else
    {
        S->data[++(S->top)] = item;
        return;
    }
}

int Pop(Stack S)
{
    if (S->top == -1)
    {
        printf("堆栈空\n");
    }
    else
        return (S->data[(S->top)--]);
}

int Judge(int line[], int N, int M)
{
    Stack S = CreateStack(M);
    int i, j;
    int temp = 0; // 记录上一个入栈的元素

    for (i = 0; i < N; i++)
    {
        if (S->data[S->top] == line[i])
        {
            Pop(S);
        }
        // 堆栈满了或者是都已经到入栈序列最后一个了还是pop不出下一个元素
        else if (S->top == S->M - 1 || temp == N)
        {
            return 0;
        }
        else
        {
            for (j = temp + 1; j <= N; j++)
            {
                Push(S, j);
                if (S->data[S->top] == line[i])
                {
                    temp = Pop(S);
                    break;
                }
                // 堆栈满了或者是都已经到入栈序列最后一个了还是pop不出下一个元素
                if (S->top == S->M - 1 || temp == N)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int M, N, K;
    int i, j;

    scanf("%d %d %d", &M, &N, &K);
    int num[K][N];
    int result[K];

    // 录入待判断的序列
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &num[i][j]);
        }

        // 对第i+1行序列进行判断
         result[i] = Judge(num[i], N, M);
    }

     // 输出结果
     for (i = 0; i < K; i++)
     {
         if (result[i])
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
