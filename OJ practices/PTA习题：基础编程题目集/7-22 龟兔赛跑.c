#include <stdio.h>

int main()
{
    int T, t, t_startrest = -1;
    int s_t = 0, s_w =0;
    int rest = 0;
    char w_t[] = "^_^", w_w[] = "@_@", w_p[] = "-_-";

    scanf("%d", &T);

    for (t = 0; t < T; t++)
    {
        if ((!(t % 10)) && (s_t > s_w) && (!rest))
        {
            rest = 1;
            t_startrest = t;
        }
        if (rest && ((t - t_startrest) == 30))
        {
            rest = 0;
        }
        if (!rest)
        {
            s_t += 9;
        }
        s_w += 3;
    }

    if (s_t > s_w)
    {
        printf("%s %d\n", w_t, s_t);
    }
    else if (s_t < s_w)
    {
        printf("%s %d\n", w_w, s_w);
    }
    else
    {
        printf("%s %d\n", w_p, s_w);
    }


    return 0;
}
