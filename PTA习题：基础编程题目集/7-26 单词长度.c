#include <stdio.h>

int main()
{
    char sentence[100];
    char a;
    int i, count = 0, flag = -1;
    // flag标记是否读到了单词

    for (i = 0; 1; i++)
    {
        scanf("%c", &sentence[i]);
        if (sentence[i] == '.')
            break;
    }

    for(i = 0; 1; i++)
    {
        a = sentence[i];
        if (a == ' ')
        {
            if (flag == 1)
            {
                printf("%d", count);
                count = 0;
                flag = 0;
            }
            else
            {
                continue;
            }
        }
        else if (a == '.')
        {
            if (flag == 1)
            {
                printf("%d", count);
            }
            putchar('\n');
            return 0;
        }
        else
        {
            if (!flag && i)
            {
                putchar(' ');
            }
            count++;
            flag = 1;
        }
    }
}
