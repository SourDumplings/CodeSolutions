#include <stdio.h>

int main()
{
    int year, week, salary_h = 30, extra;
    float salary_sum;

    scanf("%d %d", &year, &week);

    extra = week - 40;

    if (year >= 5)
    {
        salary_h = 50;
    }

    if (extra > 0)
    {
        salary_sum = salary_h * (40 + extra * 1.5);
    }
    else
    {
        salary_sum = salary_h * week;
    }

    printf("%.2f", salary_sum);


    return 0;
}
