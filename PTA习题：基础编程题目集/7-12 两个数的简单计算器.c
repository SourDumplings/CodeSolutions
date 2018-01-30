#include <stdio.h>

int main()
{
    int num1, num2, result, j = 1;
    char i;

    scanf("%d %c %d", &num1, &i, &num2);

    if (i == '+')
    {
        result = num1 + num2;
    }
    else if (i == '-')
    {
        result = num1 - num2;
    }
    else if (i == '*')
    {
        result = num1 * num2;
    }
    else if (i == '/')
    {
        result = num1 / num2;
    }
    else if (i == '%')
    {
        result = num1 % num2;
    }
    else
    {
        j = 0;
    }

    if (j == 0)
    {
        printf("ERROR");
    }
    else
    {
        printf("%d", result);
    }

    return 0;
}
