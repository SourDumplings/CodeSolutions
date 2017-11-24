#include <stdio.h>

typedef struct STUDENT student;
struct STUDENT
{
    int id;
    int d;
    int c;
    int a; // 0为不录取，1为德才兼备，2为第二类德胜才，3为第三类德胜才，4为其他
};

int Judge(student stu, int L, int H)
{
    if (stu.d < L || stu.c < L)
    {
        return 0;
    }
    if (stu.d >= H && stu.c >= H)
    {
        return 1;
    }
    else
    {
        if (stu.c >= H)
        {
            return 4;
        }
        else if (stu.d >= H)
        {
            return 2;
        }
        else
        {
            if (stu.d >= stu.c)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
    }
}

void Swap(student stu[], int a, int b)
{
    student temp;
    temp = stu[a];
    stu[a] = stu[b];
    stu[b] = temp;
    return;
}

void Sort(student stu[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (stu[j].c + stu[j].d < stu[j+1].c + stu[j+1].d)
            {
                Swap(stu, j, j+1);
            }
            else if (stu[j].c + stu[j].d == stu[j+1].c + stu[j+1].d)
            {
                if (stu[j].d < stu[j+1].d)
                {
                    Swap(stu, j, j+1);
                }
                else if (stu[j].d == stu[j+1].d && stu[j].id > stu[j+1].id)
                {
                    Swap(stu, j, j+1);
                }
            }
        }
    }
    return;
}

void PrintS(student stu[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d %d %d\n", stu[i].id, stu[i].d, stu[i].c);
    }
}

void Output(student s[], int N)
{
    int i;
    int n[4] = {0};
    student stu[4][N];
    for (i = 0; i < N; i++)
    {
        switch (s[i].a)
        {
            case 1: stu[0][n[0]++] = s[i]; break;
            case 2: stu[1][n[1]++] = s[i]; break;
            case 3: stu[2][n[2]++] = s[i]; break;
            case 4: stu[3][n[3]++] = s[i]; break;
            default: break;
        }
    }
    printf("%d\n", n[0]+n[1]+n[2]+n[3]);
    for (i = 0; i < 4; i++)
    {
        Sort(stu[i], n[i]);
        PrintS(stu[i], n[i]);
    }
    return;
}

int main()
{
    int N, L, H;
    int i;
    scanf("%d %d %d", &N, &L, &H);
    student s[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &s[i].id, &s[i].d, &s[i].c);
        s[i].a = Judge(s[i], L, H);
    }

    Output(s, N);

    return 0;
}
