#include <stdio.h>
#include <string.h>

int main()
{
    char pinyin[][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", \
    "qi", "ba", "jiu"};
    char result[100][5];
    int i, n, count = 0;

    // for (i = 0; i <= 9; i++)
    // {
    //     printf("%s\n", pinyin[i]);
    // }

    // printf("%s\n", pinyin[6]);

    scanf("%d", &n);

    if (n < 0)
    {
        printf("fu ");
        n = -n;
    }

    if (!n)
    {
        printf("ling\n");
        return 0;
    }

    for (i = 0; n; i++)
    {
        strcpy(result[i], pinyin[n % 10]);
        n /= 10;
        count++;
    }

    for (i = count - 1; i >= 0; i--)
    {
        printf("%s", result[i]);
        if (i)
        {
            putchar(' ');
        }
    }
    putchar('\n');

    return 0;
}
