/*
 @Date    : 2018-03-15 13:50:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/867
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>
#include <functional>

using namespace std;
using namespace placeholders;

static const int MAXN = 225, INF = 999999;

struct Country
{
    int id;
    double v[5];
    int r[5];
    int p;
    int best, best_r = INF;
};

static shared_ptr<Country> data[MAXN];
static shared_ptr<Country> idMap[MAXN];
static int N, M;

bool cmp(const shared_ptr<Country> &p1, const shared_ptr<Country> &p2, int v_i)
{
    return p1->v[v_i] > p2->v[v_i];
}

void get_rank(int r_i)
{
    sort(data, data+N, bind(cmp, _1, _2, r_i));
    int lastRank = 0, sameVNum = 1;
    double lastV = static_cast<double>(INF);
    for (int i = 0; i != N; ++i)
    {
        if (data[i]->v[r_i] < lastV)
        {
            // printf("data[%d]->v[%d] = %f\n", i, r_i, data[i]->v[r_i]);
            lastRank += sameVNum;
            // printf("data[%d]->r[%d] = %d\n", i, r_i, data[i]->r[r_i]);
            sameVNum = 1;
            lastV = data[i]->v[r_i];
        }
        else
            ++sameVNum;
        data[i]->r[r_i] = lastRank;
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (unsigned i = 0; i < N; ++i)
    {
        data[i] = make_shared<Country>();
        scanf("%lf %lf %d", &data[i]->v[1], &data[i]->v[2], &data[i]->p);
        data[i]->v[3] = data[i]->v[1] / data[i]->p;
        data[i]->v[4] = data[i]->v[2] / data[i]->p;
        idMap[i] = data[i];
        idMap[i]->id = i;
    }
    get_rank(1);
    get_rank(2);
    get_rank(3);
    get_rank(4);
    int output = 0;
    for (int i = 0; i != M && i != N; ++i)
    {
        int c;
        scanf("%d", &c);
        for (unsigned j = 1; j < 5; ++j)
        {
            // printf("\nidMap[%d]->r[%d] = %d\n", c, i, idMap[c]->r[i]);
            if (idMap[c]->r[j] < idMap[c]->best_r)
            {
                idMap[c]->best_r = idMap[c]->r[j];
                idMap[c]->best = j;
            }
        }
        if (output++)
        {
            putchar(' ');
        }
        printf("%d:%d", idMap[c]->best_r, idMap[c]->best);
    }
    putchar('\n');
    return 0;
}

