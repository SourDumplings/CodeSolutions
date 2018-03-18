/*
 @Date    : 2017-12-07 08:47:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1042
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct CARD *Card;
struct CARD
{
    char name;
    int order;
};

void Shuffle(Card C[], int list[])
{
    Card temp[55];
    int i;
    int p;
    for (i = 0; i < 54; i++)
    {
        p = list[i];
        temp[p] = C[i+1];
    }
    for (i = 1; i <= 54; i++)
    {
        C[i] = temp[i];
    }
    return;
}

int main()
{
    Card C[55];
    int i;
    for (i = 1; i <= 13; i++)
    {
        C[i] = (Card)malloc(sizeof(struct CARD));
        C[i]->name = 'S';
        C[i]->order = i;
    }
    for (i = 14; i <= 26; i++)
    {
        C[i] = (Card)malloc(sizeof(struct CARD));
        C[i]->name = 'H';
        C[i]->order = i - 13;
    }
    for (i = 27; i <= 39; i++)
    {
        C[i] = (Card)malloc(sizeof(struct CARD));
        C[i]->name = 'C';
        C[i]->order = i - 26;
    }
    for (i = 40; i <= 52; i++)
    {
        C[i] = (Card)malloc(sizeof(struct CARD));
        C[i]->name = 'D';
        C[i]->order = i - 39;
    }
    for (i = 53; i <= 54; i++)
    {
        C[i] = (Card)malloc(sizeof(struct CARD));
        C[i]->name = 'J';
        C[i]->order = i - 52;
    }

    int K;
    int list[54];
    scanf("%d", &K);
    for (i = 0; i < 54; i++)
    {
        scanf("%d", &list[i]);
    }

    for (i = 0; i < K; i++)
    {
        Shuffle(C, list);
    }

    int output = 0;
    for (i = 1; i <= 54; i++)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%c%d", C[i]->name, C[i]->order);
    }
    putchar('\n');
    return 0;
}

