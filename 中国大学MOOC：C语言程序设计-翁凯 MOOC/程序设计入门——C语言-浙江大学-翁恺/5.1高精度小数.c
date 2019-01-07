#include <stdio.h>

int main()
{
    int a, b, d;
    int count = 0;
    scanf("%d/%d", &a, &b);
    printf("0.");
    do
    {
        a *= 10;
        d = a / b;
        a %= b;
        printf("%d", d);
        count++;
    } while (a && count < 200);
    putchar('\n');
    return 0;
}
