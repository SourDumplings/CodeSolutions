#include <stdio.h>

int main()
{
    int A, N;
    scanf("%d %d", &A, &N);

    if (!N)
    {
        printf("0\n");
        return 0;
    }

    int n[N]; // 用来存放最终结果（可能不包含最后一次进位的数值，即最高位）
    int j = 0, last = 0; // j是数组n的指针
    int i;

    for (i = N; i >= 1; i--)
    {
        n[j++] = (i * A + last) % 10;
        last = (i * A + last) / 10; // 要进位的数，要么是0要么是1
    }

    if (last)
    {
        printf("%d", last); // 将最后一次进位输出
    }

    for (j = j - 1; j >= 0; j--)
    {
        printf("%d", n[j]);
    }
    putchar('\n');

    return 0;
}
