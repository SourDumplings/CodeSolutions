#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1001
#define min(a,b) ( ((a)>(b)) ? (b):(a) )

int A[MAXN];
int T[MAXN];

int GetLeftLength(int n)
{
    int H, X;
    int L;
    H = (log(n+1) / log(2));
    X = n + 1 - pow(2, H);
    X = min(X, pow(2, H - 1));
    L = pow(2, H - 1) - 1 + X;
    return L;
}

void solve(int Aleft, int Aright, int Troot, int N)
{
    if (Troot >= N)
    {
        return;
    }
    // 初始为solve(0, N-1, 0)
    int n = Aright - Aleft + 1;
    if (!n)
    {
        return;
    }
    int L = GetLeftLength(n); // 计算出n个节点的树其左子树有多少个结点
    T[Troot] = A[Aleft + L];
    int leftroot = Troot * 2 + 1;
    int rightroot = leftroot + 1;
    solve(Aleft, Aleft+L-1, leftroot, N);
    solve(Aleft+L+1, Aright, rightroot, N);
    return;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N;
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), compare);
    solve(0, N-1, 0, N);
    for (i = 0; i < N; i++)
    {
        printf("%d", T[i]);
        if (i < N - 1)
        {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}
