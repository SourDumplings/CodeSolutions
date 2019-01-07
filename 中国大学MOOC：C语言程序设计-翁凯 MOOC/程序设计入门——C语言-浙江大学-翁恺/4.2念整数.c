#include <stdio.h>

int main()
{
    char p[10][5] = {"ling", "yi", "er", "san",
                    "si", "wu", "liu", "qi", "ba", "jiu"};
    int num;

    scanf("%d", &num);

    if (num < 0)
    {
        printf("fu ");
        num *= -1;
    }

    int d, mark = 1, n = num;

    while (n > 9)
    {
        // 得到mark为与num相同位的最小数
        mark *= 10;
        n /= 10;
    }

    while (mark)
    {
        d = num / mark;
        num %= mark;
        mark /= 10;
        printf("%s", p[d]);
        if (mark)
        {
            putchar(' ');
        }
        else
        {
            putchar('\n');
        }
    }


    return 0;
}
