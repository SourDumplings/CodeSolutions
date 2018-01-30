#include <stdio.h>

int main()
{
    float num1, num2;
    int i;
    char c;

    scanf("%f %d %c %f", &num1, &i, &c, &num2);
    printf("%c %d %.2f %.2f", c, i, num1, num2);

    return 0;
}
