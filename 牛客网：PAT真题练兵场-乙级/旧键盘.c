#include <stdio.h>
#include <string.h>
#include <ctype.h>

int k = 0;
char broken[81];

int Inside(char c)
{
    int i;
    for (i = 0; i < k; i++)
    {
        if (broken[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

void AddBroken(char c)
{
    c = toupper(c);
    if (!Inside(c))
    {
        broken[k++] = c;
    }
    return;
}

int main()
{
    char right[81];
    char act[81];
    int i;
    gets(right);
    gets(act);
    int l_r = strlen(right);
    int j = 0;

    for (i = 0; i < l_r; i++)
    {
        if (right[i] != act[j])
        {
            AddBroken(right[i]);
        }
        else
        {
            j++;
        }
    }

    printf("%s\n", broken);

    return 0;
}
