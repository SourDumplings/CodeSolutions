#include <stdio.h>

#define MAX 99999

int main()
{
    char s[MAX];
    gets(s);
    int i;
    int l = 0;
    int output = -1;
    int first = 1;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '.')
        {
            output = 0;
            l++;
        }
        else if ((s[i] == ' ' || s[i] == '.') && !output)
        {
            if (!first)
            {
                putchar(' ');
            }
            printf("%d", l);
            first = 0;
            output = 1;
            l = 0;
        }
    }
    putchar('\n');
    return 0;
}

