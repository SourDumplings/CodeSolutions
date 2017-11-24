#include <stdio.h>

struct PS
{
    float pu;
    int storage;
};

void QuickSort(struct PS p_u[], int left, int right)
{
    int i = left;
    int j = right;
    float key = p_u[(i+j)/2].pu;
    struct PS temp;
    while (i <= j)
    {
        for (; p_u[i].pu > key; i++);
        for (; p_u[j].pu < key; j--);
        if (i <= j)
        {
            temp = p_u[i];
            p_u[i] = p_u[j];
            p_u[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right)
    {
        QuickSort(p_u, i, right);
    }
    if (j > left)
    {
        QuickSort(p_u, left, j);
    }
    return;
}

// void BubbleSort(struct PS p_u[], int N)
// {
//     int i;
//     int j;
//     struct PS temp;
//     for (i = 0; i < N; i++)
//     {
//         for (j = i; j < N - 1; j++)
//         {
//             if (p_u[j].pu < p_u[j+1].pu)
//             {
//                 temp = p_u[j];
//                 p_u[j] = p_u[j+1];
//                 p_u[j+1] = temp;
//             }
//         }
//     }
//     return;
// }

int main()
{
    int N, D;
    scanf("%d %d", &N, &D);
    float p[N];
    int i;
    struct PS p_u[N];
    int amount = 0;
    float sump = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &p_u[i].storage);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%f", &p[i]);
    }
    for (i = 0; i < N; i++)
    {
        p_u[i].pu = p[i] / p_u[i].storage;
    }
    QuickSort(p_u, 0, N-1);
    // BubbleSort(p_u, N);
    for (i = 0; i < N; i++)
    {
        amount += p_u[i].storage;
        if (amount > D)
        {
            sump += p_u[i].pu * (D-(amount - p_u[i].storage));
            printf("%.2f\n", sump);
            return 0;
        }
        else
        {
            sump += p_u[i].pu * p_u[i].storage;
        }
    }
    printf("%.2f\n", sump);

    return 0;
}
