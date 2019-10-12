#include <stdio.h>

int Judge(char j, char y, int count[])
{
    if (j == 'C')
    {
        switch (y)
        {
            case 'C': return 1;
            case 'J': count[1]++; return 0;
            case 'B': count[3]++; return 2;
        }

    }
    else if (j == 'J')
    {
        switch (y)
        {
            case 'C': count[4]++; return 2;
            case 'J': return 1;
            case 'B': count[2]++; return 0;
        }

    }
    else if (j == 'B')
    {
        switch (y)
        {
            case 'C': count[0]++; return 0;
            case 'J': count[5]++; return 2;
            case 'B': return 1;
        }
    }
    return 3;
}

int main()
{
    int N;
    scanf("%d\n", &N);
    char j, y;
    int i;
    int data[2] = {0};
    int result;
    int count[6] = {0};
    int win_j, win_y;
    int n_j = 0, n_y = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%c %c", &j, &y);
        if (i < N - 1)
        {
            getchar();
        }
        result = Judge(j, y, count);
        switch(result)
        {
            case 0: data[0]++; break;
            case 2: data[1]++; break;
        }
    }
    printf("%d %d %d\n", data[0], N-data[0]-data[1], data[1]);
    printf("%d %d %d\n", data[1], N-data[0]-data[1], data[0]);

    for (i = 0; i < 3; i++)
    {
        if (count[i] > n_j)
        {
            win_j = i;
            n_j = count[i];
        }
    }
    for (i = 3; i < 6; i++)
    {
        if (count[i] > n_y)
        {
            win_y = i;
            n_y = count[i];
        }
    }
    switch(win_j)
    {
        case 0: printf("%c ", 'B'); break;
        case 1: printf("%c ", 'C'); break;
        case 2: printf("%c ", 'J'); break;
    }
    switch(win_y)
    {
        case 3: printf("%c\n", 'B'); break;
        case 4: printf("%c\n", 'C'); break;
        case 5: printf("%c\n", 'J'); break;
    }

    return 0;
}
