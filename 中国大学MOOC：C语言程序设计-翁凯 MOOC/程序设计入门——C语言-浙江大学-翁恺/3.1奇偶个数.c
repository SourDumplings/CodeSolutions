#include <stdio.h>

int main()
{
    int odd = 0, even = 0;
    int n;
    do
    {
        scanf("%d", &n);
        if (n >= 0)
        {
            if (n % 2)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
    } while (n != -1);
    printf("%d %d\n", odd, even);
    return 0;
}
