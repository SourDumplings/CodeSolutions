#include <stdio.h>

#define MAX 100001

int Calc(int result[], int i, int d)
{
    int j;
    for (j = 0; j <= i; j++)
    {
        result[j] += d;
    }

    // 进位
    for (j = 0; j <= i + 1; j++)
    {
        if (result[j] > 9)
        {
            result[j] %= 10;
            result[j+1]++;
        }
    }

    return j+1;
}

int main()
{
    int d;
    int N;
    scanf("%d %d", &d, &N);
    if (!N)
    {
        printf("0\n");
        return 0;
    }

    int result[MAX] = {0};
    int temp; // 标记结果最多是几位数
    int flag = 0; // 标记是否读到了有效数字

    int i;

    for (i = 0; i < N; i++)
    {
        temp = Calc(result, i, d);
    }

    for (i = temp; i >= 0; i--)
    {
        if (result[i])
        {
            flag = 1;
        }
        if (flag)
        {
            printf("%d", result[i]);
        }
    }
    putchar('\n');

    return 0;
}
