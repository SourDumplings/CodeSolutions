#include <stdio.h>
#include <ctype.h>

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int Judge(char id[])
{
    int i;
    int Z;
    int sum = 0;
    for (i = 0; i < 17; i++)
    {
        if (!isdigit(id[i]))
        {
            return 1;
        }
        sum += (id[i] - '0') * weight[i];
    }
    Z = sum % 11;
    if (id[17] == M[Z])
    {
        return 0;
    }
    return 1;
}

int main()
{
    int N;
    scanf("%d\n", &N);
    char id[N][19];
    int i;
    int output = 0;
    for (i = 0; i < N; i++)
    {
        gets(id[i]);
    }
    for (i = 0; i < N; i++)
    {
        if (Judge(id[i]))
        {
            puts(id[i]);
            output = 1;
        }
    }
    if (!output)
    {
        printf("All passed\n");
    }
    return 0;
}
