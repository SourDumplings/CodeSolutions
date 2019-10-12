# include <stdio.h>

int main()
{
    float open, high, low, close, max, min;

    scanf("%f %f %f %f", &open, &high, &low, &close);

    max = open;
    min = close;

    if (close < open)
    {
        printf("BW-Solid");
    }
    else if (close == open)
    {
        printf("R-Cross");
    }
    else
    {
        printf("R-Hollow");
        max = close;
        min = open;
    }

    if (high > max && low < min)
    {
        printf(" with Lower Shadow and Upper Shadow");
    }
    else if (high > max && low >= min)
    {
        printf(" with Upper Shadow");
    }
    else if (high < max && low < min)
    {
        printf(" with Lower Shadow");
    }


    return 0;
}
