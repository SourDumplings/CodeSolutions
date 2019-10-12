#include <stdio.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN], size = 0;

void Create()
{
    size = 0;
    H[0] = MINH;
    // 设置岗哨
    return;
}

void Insert(int X)
{
    int i;

    if (size == MAXN - 1)
    {
        return;
    }


    for (i = ++size; H[i/2] > X; i/=2)
    {
        H[i] = H[i/2];
    }
    H[i] = X;
    return;
}

int main()
{
    int n, m, x, i, j;

    // 读入n，m
    scanf("%d %d", &n, &m);
    // 根据输入序列建堆
    Create();
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Insert(x);
    }
    // 对m个要求：打印到根的路径
    for (i = 0; i < m; i++)
    {
        scanf("%d", &j);
        printf("%d", H[j]);
        while(j > 1)
        {
            j /= 2;
            printf(" %d", H[j]);
        }
        printf("\n");
    }
    return 0;
}
