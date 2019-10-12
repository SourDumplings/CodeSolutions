#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, i, count = 0, sum = 0;

    scanf("%d %d", &A, &B);

    for (i = A; i <= B; i++)
    {
        printf("%5d", i);
        count++;
        if (!(count % 5) && i < B) // 添加i小于B是为了防止A~B刚好是5的整数倍个数从而多输出一个回车
        {
            putchar('\n');
        }
        sum += i;
    }
    putchar('\n');
    printf("Sum = %d\n", sum);
    return 0;
}
