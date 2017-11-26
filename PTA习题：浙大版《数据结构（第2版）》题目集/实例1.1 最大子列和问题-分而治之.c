#include <stdio.h>

int Max3(int a, int b, int c)
{
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

int DivideAndConquer(int List[], int left, int right)
{
    int maxleftsum, maxrightsum;
    int maxleftbordersum, maxrightbordersum; // 存放跨界分界线的结果

    int leftbordersum, rightbordersum;
    int center, i;

    if (left == right)
    {
        // 递归终止条件，子列只有一个数字
        if (List[left] > 0)
        {
            return List[left];
        }
        else
        {
            return 0;
        }
    }

    // 下面是分的过程
    center = (left + right) / 2;
    maxleftsum = DivideAndConquer(List, left, center);
    maxrightsum = DivideAndConquer(List, center+1, right);

    // 下面求跨界的最大子列和
    maxleftbordersum = leftbordersum = 0;
    for (i = center; i >= left; i--)
    {
        leftbordersum += List[i];
        if (leftbordersum > maxleftbordersum)
        {
            maxleftbordersum = leftbordersum;
        }
    }
    maxrightbordersum = rightbordersum = 0;
    for (i = center+1; i <= right; i++)
    {
        rightbordersum += List[i];
        if (rightbordersum > maxrightbordersum)
        {
            maxrightbordersum = rightbordersum;
        }
    }

    // 下面返回“治”的结果
    return Max3(maxleftsum, maxrightsum, maxleftbordersum+maxrightbordersum);
}

int MaxSubseqSum(int List[], int N)
{
    return DivideAndConquer(List, 0, N-1);
}

int main()
{
    int N;
    scanf("%d", &N);
    int List[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &List[i]);
    }
    printf("%d\n", MaxSubseqSum(List, N));
    return 0;
}
