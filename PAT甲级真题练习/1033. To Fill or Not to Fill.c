/*
 @Date    : 2017-12-03 16:59:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1033
运用贪心法，思路见：
http://www.cnblogs.com/XBWer/p/3866486.html
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 500
#define INFINITY 9999999999

double spend = 0, cheapestspend = INFINITY, maxtravel = 0;
int canreach = 0;


typedef struct STATION *Station;
struct STATION
{
    double dist;
    double price;
};

int compare(const void *a, const void *b)
{
    return (*(Station *)a)->dist - (*(Station *)b)->dist;
}

void Go(Station S[], int thisstation, double c_res, double Cmax, int N, double Davg)
{
    int next;
    double c_add;
    double maxreach = Cmax * Davg;

    // printf("$$We arrived at station %d, dist %f, c_res %f$$\n", thisstation, S[thisstation]->dist, c_res);

    if (S[thisstation]->dist + maxreach > maxtravel)
    {
        maxtravel = S[thisstation]->dist + maxreach;
    }

    double cheapestprice = S[thisstation]->price;
    int cheapeststation = thisstation;
    for (next = thisstation + 1; next < N; next++)
    {
        // 找找前方有没有更便宜的站点，找到更便宜的第一个站点开过去加油，在本站将又加够到那个站即可
        if (S[next]->dist <= maxreach + S[thisstation]->dist)
        {
            if (S[next]->price < cheapestprice)
            {
                cheapestprice = S[next]->price;
                cheapeststation = next;
                c_add = (S[next]->dist - S[thisstation]->dist) / Davg - c_res;
                if (c_add < 0)
                {
                    c_add = 0;
                }
                spend += c_add * S[thisstation]->price;
                if (next == N - 1)
                {
                    if (spend < cheapestspend)
                    {
                        cheapestspend = spend;
                        canreach = 1;
                        return;
                    }
                }
                break;
            }
        }
        else
        {
            break;
        }
    }

    if (cheapeststation == thisstation)
    {
        // 说明前方没有更便宜的加油站，则在本站将油加满，开到下一个最便宜的加油站去加油
        cheapestprice = INFINITY;
        cheapeststation = -1;
        c_add = Cmax - c_res;
        spend += c_add * S[thisstation]->price;
        for (next = thisstation + 1; next < N; next++)
        {
            if (S[next]->dist <= maxreach + S[thisstation]->dist)
            {
                if (next == N - 1)
                {
                    if (spend < cheapestspend)
                    {
                        cheapestspend = spend;
                        canreach = 1;
                        return;
                    }
                }
                else if (S[next]->price < cheapestprice)
                {
                    cheapeststation = next;
                    cheapestprice = S[next]->price;
                }
            }
            else
            {
                break;
            }
        }
    }

    if (cheapeststation == -1)
    {
        // 说明到不了下一站了
        return;
    }

    c_res = c_res + c_add - (S[cheapeststation]->dist - S[thisstation]->dist) / Davg;
    // printf("$$Next station %d, dist %f, c_res %f when arrived$$\n", cheapeststation, S[cheapeststation]->dist, c_res);
    Go(S, cheapeststation, c_res, Cmax, N, Davg);
}

int main()
{
    double Cmax, D, Davg;
    int N;
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &N);
    // printf("$$Cmax = %f, D = %f, Davg = %f, N = %d$$\n", Cmax, D, Davg, N);
    int i;
    Station S[N+1];
    for (i = 0; i < N; i++)
    {
        S[i] = (Station)malloc(sizeof(struct STATION));
        scanf("%lf %lf", &S[i]->price, &S[i]->dist);
    }

    // 将N个加油站按照距离从近到远排序
    qsort(S, N, sizeof(S[0]), compare);

    // 目的地
    S[N] = (Station)malloc(sizeof(struct STATION));
    S[N]->dist = D;
    S[N]->price = 0;
    // printf("$$Cmax = %f, D = %f, Davg = %f, N = %d$$\n", Cmax, D, Davg, N);


    // printf("$$Cmax = %f, D = %f, Davg = %f, N = %d$$\n", Cmax, D, Davg, N);

    // 在起点中找到最便宜的加油站
    double cheapestprice = INFINITY;
    int cheapeststation = -1;
    for (i = 0; i <= N; i++)
    {
        if (S[i]->dist == 0 && S[i]->price < cheapestprice)
        {
            cheapestprice = S[i]->price;
            cheapeststation = i;
        }
    }
    if (cheapeststation != -1)
    {
        Go(S, cheapeststation, 0, Cmax, N+1, Davg);
    }

    if (canreach)
    {
        printf("%.2f\n", cheapestspend);
    }
    else
    {
        printf("The maximum travel distance = %.2f\n", maxtravel);
    }

    return 0;
}
