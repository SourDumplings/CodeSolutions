/*
 @Date    : 2017-11-29 19:41:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1016
分析：
    来自：http://www.th7.cn/Program/cp/201402/174424.shtml

　　模拟题，提交无数次WA，注意几点：

　　1.如果某人没有有效通话记录，则不输出该人的信息，在此WA15次，题目看了N遍也没出现啊。

　　2.通话时间钱的计算：假设我们计算time1到time2的账单；

　　(1)我们可以采用从起点（即00：00：00）开始计算，结果就是get_money(time2) - get_money(time1), 这样计算方便。

　　(2)我们也可以采用从time1开始递增直到time2， 这样比较烦。

　　3.有效的通话记录是指：如果某人的通话记录为1.on;2.on;3.off;，则其中1.on将被抛弃，匹配到2.on;3.off;。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double rate[24];
int N;

typedef struct RECORD *Record;
struct RECORD
{
    char name[21];
    int m, d, h, min;
    int status; // 0表示on-line, 1表示off-line;
};

int compare(const void *a, const void *b)
{
    a = (Record *)a;
    b = (Record *)b;
    int k;
    if (strcmp((*(Record *)a)->name, (*(Record *)b)->name) == 0)
    {
        if ((*(Record *)a)->m - (*(Record *)b)->m == 0)
        {
            if ((*(Record *)a)->d - (*(Record *)b)->d == 0)
            {
                if ((*(Record *)a)->h - (*(Record *)b)->h == 0)
                {
                    k = (*(Record *)a)->min - (*(Record *)b)->min;
                }
                else
                {
                    k = (*(Record *)a)->h - (*(Record *)b)->h;
                }
            }
            else
            {
                k = (*(Record *)a)->d - (*(Record *)b)->d;
            }
        }
        else
        {
            k = (*(Record *)a)->m - (*(Record *)b)->m;
        }
    }
    else
    {
        k = strcmp((*(Record *)a)->name, (*(Record *)b)->name);
    }
    return k;
}

double GetMoney(Record stop)
{
    double charge = 0;
    double d_money = 0;
    double h_money = 0;
    int i;
    for (i = 0; i < 24; i++)
    {
        d_money += rate[i] * 60;
    }
    for (i = 0; i < stop->h; i++)
    {
        h_money += rate[i] * 60;
    }
    charge = d_money * stop->d + h_money + stop->min * rate[stop->h];
    return charge;
}

double CalcEachCom(Record start, Record end, int *ptotalmin)
{
    *ptotalmin = (end->d - start->d) * 24 * 60 + (end->h - start->h) * 60 + end->min - start->min;
    double charge = 0;
    charge = GetMoney(end) - GetMoney(start);
    return charge;
}

void OutPut(Record data[])
{
    int i;
    Record temp = NULL;
    double charge = 0, amount = 0;
    char nowoutputingname[21];
    char lastoutputname[21];
    int eachmin;
    int isoutput = 0;
    for (i = 0; i < N; i++)
    {
        if (data[i]->status == 0)
        {
            // 遇到一条on-line的记录
            temp = data[i];
            strcpy(nowoutputingname, temp->name);
        }
        else
        {
            // 一条off-line的记录
            if (temp && strcmp(nowoutputingname, data[i]->name) == 0)
            {
                // 如果前面对应着同一个人的一条on-line记录
                if (strcmp(nowoutputingname, lastoutputname))
                {
                    // 如果和上一条输出的记录的人的名字不同，即代表这是一个新的人的
                    if (isoutput)
                    {
                        // 只有输出过通话记录了才可能要输出总额
                        printf("Total amount: $%.2f\n", amount);
                    }
                    amount = 0;
                    charge = 0;
                    strcpy(lastoutputname, nowoutputingname);
                    printf("%s %02d\n", nowoutputingname, data[i]->m);
                }
                charge = CalcEachCom(temp, data[i], &eachmin);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                    temp->d, temp->h, temp->min, data[i]->d, data[i]->h, data[i]->min,
                    eachmin, charge);
                temp = NULL; // on-line的记录一旦输出了就废掉
                isoutput = 1;
                amount += charge;
            }
        }
    }
    // 如果前面输出过记录，则输出最后一个人的总额
    if (isoutput)
    {
        printf("Total amount: $%.2f\n", amount);
    }
    return;
}

int main()
{
    int i;
    int r;
    for (i = 0; i < 24; i++)
    {
        scanf("%d", &r);
        rate[i] = (double)r / 100;
    }
    scanf("%d", &N);
    Record data[N];
    char status[10];
    for (i = 0; i < N; i++)
    {
        data[i] = (Record)malloc(sizeof(struct RECORD));
        scanf("%s %d:%d:%d:%d", data[i]->name, &data[i]->m, &data[i]->d, &data[i]->h, &data[i]->min);
        scanf("%s", status);
        if (strcmp(status, "on-line") == 0)
        {
            data[i]->status = 0;
        }
        else
        {
            data[i]->status = 1;
        }
    }
    qsort(data, N, sizeof(data[0]), compare);
    OutPut(data);

    return 0;
}

