#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

void Print_Factorial ( const int N )
{
    int result[2568] = {0}; // 不超过1000的阶乘最多有2568位
    int i, j;
    int temp;
    int flag = 0; //标记是否遇到了有效数字

    result[0] = 1;

    if (N < 0)
    {
        printf("Invalid input\n");
    }
    else if (!N)
    {
        printf("1\n");
    }
    else
    {
        for (i = 1; i <= N; i++)
        {
            for (j = 2568; j >= 0; j--)
            {
                if (flag)
                {
                    result[j] *= i;
                }
                else if (result[j-1])
                {
                    flag = 1;
                }
            }
            flag = 0;

            // 进位
            for (j = 0; j <= 2568; j++)
            {
                if (result[j] > 9)
                {
                    temp = result[j];
                    result[j] = temp % 10;
                    result[j + 1] += temp / 10;
                }
            }

        }

        // 打印
        for (i = 2568; i >= 0; i--)
        {
            if (flag)
            {
                printf("%d", result[i]);
            }
            else if (result[i-1])
            {
                flag = 1;
            }
        }
        putchar('\n');
    }
    return;
}
