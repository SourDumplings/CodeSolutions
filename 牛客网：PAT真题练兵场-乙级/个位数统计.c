#include <stdio.h>
#include <string.h>

int main()
{
    char n[1000];
    int i;
    int l;
    int num[10];
    gets(n);
    l = strlen(n);

    for (i = 0; i < 10; i++)
    {
        num[i] = 0;
    }

    for (i = 0; i < l; i++)
    {
        num[n[i] - '0']++;
    }

    for (i = 0; i < 10; i++)
    {
        if (num[i])
        {
            printf("%d:%d\n", i, num[i]);
        }
    }
    return 0;
}
