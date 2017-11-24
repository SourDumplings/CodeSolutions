#include <stdio.h>
#include <time.h>

int main()
{
    double C1, C2;
    scanf("%lf %lf", &C1, &C2);
    int t = (int) ((C2 - C1) / 100 + 0.5);
    int h = t / 3600, m = (t % 3600) / 60, s =t % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}
