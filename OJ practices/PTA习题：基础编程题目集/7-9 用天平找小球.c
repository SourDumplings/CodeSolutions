#include <stdio.h>

int main()
{
    int A, B, C;
    char ball;

    scanf("%d %d %d", &A, &B, &C);

    if (A - B)
    {
        if (A - C)
        {
            ball = 'A';
        }
        else
        {
            ball = 'B';
        }
    }
    else
    {
        ball = 'C';
    }

    printf("%c", ball);
    return 0;
}
