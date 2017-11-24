#include <stdio.h>

#define MAX 100000

int main()
{
    int N;
    scanf("%d", &N);
    int i;
    int total_score[MAX] = {0};
    int num, score;
    int max = 0;

    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &num, &score);
        total_score[num-1] += score;
    }
    for (i = 0; i < MAX; i++)
    {
        if (total_score[i] > total_score[max])
        {
            max = i;
        }
    }
    printf("%d %d\n", max+1, total_score[max]);
    return 0;
}
