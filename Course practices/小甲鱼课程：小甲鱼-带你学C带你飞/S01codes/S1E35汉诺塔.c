#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char x, char y, char z);

void hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("%c ------> %c\n", x, z);
    }
    else
    {
        hanoi(n-1, x, z, y);
        printf("%c ------> %c\n", x, z);
        hanoi(n-1, y, x, z);
    }
}

int main(void)
{
    int n;

    printf("ÇëÊäÈëººÅµËşµÄ²ãÊı£º");
    scanf("%d", &n);

    hanoi(n, 'X', 'Y', 'Z');

    return 0;
}
