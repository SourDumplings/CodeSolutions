#include <stdio.h>

int main()
{
    int h, min;
    char i[] = "AM";

    scanf("%d:%d", &h, &min);

    if (h > 12)
    {
        h -= 12;
        i[0] = 'P';
    }
    else if (h == 12)
    {
        i[0] = 'P';
    }

    printf("%d:%d %s", h, min, i);
    return 0;
}
