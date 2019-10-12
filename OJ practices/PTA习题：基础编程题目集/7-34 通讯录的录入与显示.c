#include <stdio.h>

struct CONTACTS
{
    char name[11];
    char birth[11];
    char sex;
    char landline[17];
    char cell[17];
};

int main()
{
    int N, i, K;
    int sort[10];
    struct CONTACTS contacts[10];

    scanf("%d", &N);

    // 录入每个人的信息
    for (i = 0; i < N; i++)
    {
        scanf("%s %s %c %s %s", contacts[i].name, contacts[i].birth, &contacts[i].sex, contacts[i].landline, contacts[i].cell);
    }

    scanf("%d", &K);

    for (i = 0; i < K; i++)
    {
        scanf("%d", &sort[i]);
    }

    for (i = 0; i < K; i++)
    {
        if (sort[i] < N && sort[i] >= 0)
            printf("%s %s %s %c %s\n", contacts[sort[i]].name, contacts[sort[i]].landline, contacts[sort[i]].cell, contacts[sort[i]].sex, contacts[sort[i]].birth);
        else
            printf("Not Found\n");
    }

    return 0;
}
