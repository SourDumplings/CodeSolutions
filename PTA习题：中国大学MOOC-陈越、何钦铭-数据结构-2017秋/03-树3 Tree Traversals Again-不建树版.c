#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 30

typedef struct STACK *Stack;
struct STACK
{
    int top;
    int maxsize;
    int data[MAXN];
};

void Push(Stack S, int X)
{
    if (S->top == S->maxsize - 1)
    {
        return;
    }
    S->data[++(S->top)] = X;
    return;
}

int Pop(Stack S)
{
    if (S->top == -1)
    {
        return -1;
    }
    return S->data[(S->top)--];
}

int post[MAXN], pre[MAXN], in[MAXN];

void solve(int preL, int inL, int postL, int n)
{
    int i;
    int root, L, R;
    if (!n)
    {
        return;
    }
    if (n == 1)
    {
        post[postL] = pre[preL];
        return;
    }
    root = pre[preL];
    post[postL+n-1] = root;
    for (i = 0; i < n; i++)
    {
        if (in[inL+i] == root)
        {
            break;
        }
    }
    L = i;
    R = n - i - 1;
    solve(preL+1, inL, postL, L);
    solve(preL+L+1, inL+L+1, postL+L, R);
    return;
}

int main()
{
    Stack S;
    int i;
    S = (Stack)malloc(sizeof(struct STACK));
    int N;

    scanf("%d", &N);
    S->maxsize = N;
    S->top = -1;
    char order[5];
    int x;
    int pre_i = 0, in_i = 0;
    for (i = 0; i < 2 * N; i++)
    {
        scanf("%s", order);
        if (!strcmp(order, "Push"))
        {
            scanf("%d", &x);
            pre[pre_i++] = x;
            Push(S, x);
        }
        else if (!strcmp(order, "Pop"))
        {
            in[in_i++] = Pop(S);
        }
    }
    solve(0, 0, 0, N);
    for (i = 0; i < N; i++)
    {
        printf("%d", post[i]);
        if (i < N - 1)
        {
            putchar(' ');
        }
        else
        {
            putchar('\n');
        }
    }
    return 0;
}
