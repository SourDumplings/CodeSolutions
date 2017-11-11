#include <stdio.h>

int main()
{
    int bjt, utc;
    scanf("%d", &bjt);
    int h, m;
    h = bjt / 100;
    m = bjt % 100;
    h -= 8;
    if (h < 0)
    {
        h += 24;
    }
    utc = h * 100 + m;
    printf("%d\n", utc);
    return 0;
}
