# include <stdio.h>

int main()
{
    double m;
    int inch, foot;
    scanf("%lf", &m);
    m = m / 100;
    foot = (int)(m / 0.3048);
    inch = (int)((m / 0.3048 - foot) * 12);
    printf("%d %d", foot, inch);
    return 0;
}
