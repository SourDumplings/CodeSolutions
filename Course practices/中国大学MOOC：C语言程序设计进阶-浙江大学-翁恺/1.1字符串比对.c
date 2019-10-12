#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main()
{
    char src[MAX], tar[MAX];
    gets(tar);
    gets(src);
    char *p = src;
    int output = 0;
    while (*p != '\0')
    {
        p = strstr(p, tar);
        if (!p)
        {
            break;
        }
        printf("%d ", p - src);
        output = 1;
        p++;
    }
    if (!output)
    {
        printf("-1");
    }
    putchar('\n');
    return 0;
}
