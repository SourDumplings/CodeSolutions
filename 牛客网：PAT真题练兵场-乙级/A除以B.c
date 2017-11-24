#include <stdio.h>
#include <string.h>

int main()
{
    char A[1100];
    int Q[1100];
    int B, R;
    scanf("%s %d", A, &B);
    int i;
    int temp_r = 0;
    int temp_b;
    int la, lq = 0;
    la = strlen(A);
    int flag = 0;
    for (i = 0; i < la; i++)
    {
        temp_b = temp_r * 10 + (A[i] - '0');
        if (temp_b < B && i < la - 1)
        {
            i++;
            temp_b = 10 * temp_b + (A[i] - '0');
            Q[i-1] = 0;
            Q[i] = temp_b / B;
            lq += 2;
        }
        else
        {
            Q[i] = temp_b / B;
            lq++;
        }
        temp_r = temp_b % B;
    }
    R = temp_r;
    for (i = 0; i < lq; i++)
    {
        if (!flag && Q[i])
        {
            flag = 1;
        }
        if (flag)
        {
            printf("%d", Q[i]);
        }
    }
    putchar(' ');
    printf("%d\n", R);
    return 0;
}
