#include <stdio.h>
#include <string.h>

int main()
{
    char str[102];
    int N, l, i;

    gets(str);
    l = strlen(str);
    // printf("%d\n", l);
    scanf("%d", &N);

    for (; N; N--)
    {
        str[l+1] = str[l];
        str[l] = str[0];
        for (i = 0; i <= l; i++)
        {
            str[i] = str[i+1];
        }
    }

    puts(str);

    return 0;
}
