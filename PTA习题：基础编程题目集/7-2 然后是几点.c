# include <stdio.h>

int main()
{
    int time_now, min_flow, time_future;
    int h_now, min_now, h_past, min_past, h_future, min_future;

    scanf("%d %d", &time_now, &min_flow);

    h_now = time_now / 100;
    min_now = time_now % 100;

    min_past = min_flow % 60;
    h_past = min_flow / 60;

    min_future = min_now + min_past;
    if (min_future >= 60)
    {
        h_past += 1;
        min_future -= 60;
    }
    if (min_future < 0)
    {
        h_past -= 1;
        min_future += 60;
    }
    h_future = h_now + h_past;

    time_future = h_future * 100 + min_future;

    printf("%d", time_future);

    return 0;
}
