#include <stdio.h>
#include <math.h>

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

    int a[5] = {0};
    int count[5] = {0};
    float mean_a4 = 0;
    for (i = 0; i < N; i++)
    {
        if (num[i] % 5 == 0 && num[i] % 2 == 0)
        {
            count[0]++;
            a[0] += num[i];
        }
        else if (num[i] % 5 == 1)
        {
            count[1]++;
            a[1] += num[i] * pow(-1, count[1]+1);
        }
        else if (num[i] % 5 == 2)
        {
            a[2]++;
            count[2]++;
        }
        else if (num[i] % 5 == 3)
        {
            count[3]++;
            a[3] += num[i];
        }
        else
        {
            count[4]++;
            if (num[i] > a[4])
            {
                a[4] = num[i];
            }
        }
    }
    mean_a4 = (float)a[3] / count[3];

    for (i = 0; i < 5; i++)
    {
        if (!count[i])
        {
            printf("N");
        }
        else
        {
            if (i != 3)
            {
                printf("%d", a[i]);
            }
            else
            {
                printf("%.1f", mean_a4);
            }
        }
        if (i < 4)
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
