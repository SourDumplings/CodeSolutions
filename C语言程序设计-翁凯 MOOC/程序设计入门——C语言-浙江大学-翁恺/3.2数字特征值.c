#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int digit;
    int wei = 0;
    int bi = 0;
    scanf("%d", &n);
    while (n)
    {
        digit = n % 10;
        wei++;
        if (digit % 2 == wei % 2)
        {
            bi += (int)pow(2, wei - 1);
        }
        n /= 10;
    }
    printf("%d\n", bi);
    return 0;
}
