#include <stdio.h>

void Shell_Sort(int num[], int N)
{
    int si, d, p, i;
    int temp;
    int Sedgwick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
    // 初始增量不能超过序列的长度
    for (si = 0; Sedgwick[si] >= N; si++);
    for (d = Sedgwick[si]; d > 0; d = Sedgwick[++si])
    {
        for (p = d; p < N; p++)
        {
            // 插入排序
            temp = num[p];
            for (i = p; i >= d && num[i-d] > temp; i -= d)
            {
                num[i] = num[i-d];
            }
            num[i] = temp;
        }
    }
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    Shell_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
