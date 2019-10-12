#include <stdio.h>

typedef struct PERSON Person;
struct PERSON
{
    char name[6];
    int year;
    int month;
    int day;
};

int IsOk(Person one)
{
    if (one.year > 2014 || one.year < 1814)
    {
        return 0;
    }
    else if (one.year == 2014)
    {
        if (one.month > 9)
        {
            return 0;
        }
        else if (one.month == 9)
        {
            if (one.day > 6)
            {
                return 0;
            }
        }
    }
    else if (one.year == 1814)
    {
        if (one.month < 9)
        {
            return 0;
        }
        else if (one.month == 9)
        {
            if (one.day < 6)
            {
                return 0;
            }
        }
    }
    return 1;
}

int FindOld(Person p[], int n)
{
    int i;
    int j = 0;
    for (i = 1; i < n; i++)
    {
        if (p[i].year < p[j].year)
        {
            j = i;
        }
        else if (p[i].year == p[j].year)
        {
            if (p[i].month < p[j].month)
            {
                j = i;
            }
            else if (p[i].month == p[j].month)
            {
                if (p[i].day < p[j].day)
                {
                    j = i;
                }
            }
        }
    }
    return j;
}

int FindYoung(Person p[], int n)
{
    int i;
    int j = 0;
    for (i = 1; i < n; i++)
    {
        if (p[i].year > p[j].year)
        {
            j = i;
        }
        else if (p[i].year == p[j].year)
        {
            if (p[i].month > p[j].month)
            {
                j = i;
            }
            else if (p[i].month == p[j].month)
            {
                if (p[i].day > p[j].day)
                {
                    j = i;
                }
            }
        }
    }
    return j;
}

int main()
{
    int N;
    scanf("%d", &N);
    Person p[N];
    Person temp;
    int i, j = 0;
    for (i = 0; i < N; i++)
    {
        getchar();
        scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
        if (IsOk(temp))
        {
            p[j++] = temp;
        }
    }

    printf("%d %s %s\n", j, p[FindOld(p, j)].name, p[FindYoung(p, j)].name);

    return 0;
}
