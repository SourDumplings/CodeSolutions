/*
 @Date    : 2018-09-01 22:47:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 40005, MAXM = 105;
int N, M, K;

struct School
{
    int quota;
    vector<int> ads;
};

struct Applicants
{
    int GE, GI, id;
    vector<int> wants;
};

School S[MAXM];
Applicants A[MAXN];

bool cmp(const Applicants &a1, const Applicants &a2)
{
    if (a1.GE + a1.GI == a2.GE + a2.GI)
    {
        return a1.GE > a2.GE;
    }
    return a1.GE + a1.GI > a2.GE + a2.GI;
}

int pick_school(int ai)
{
    if (ai == 0)
        return A[ai].wants[0];

    int ret = -1;
    for (int w : A[ai].wants)
    {
        if (S[w].ads.size() < S[w].quota ||
            (S[w].ads.size() >= S[w].quota &&
                A[S[w].ads.back()].GE + A[S[w].ads.back()].GI == A[ai].GE + A[ai].GI &&
                 A[S[w].ads.back()].GE == A[ai].GE))
        {
            ret = w;
            break;
        }
    }
    return ret;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i != M; ++i)
        scanf("%d", &S[i].quota);
    for (int i = 0; i != N; ++i)
    {
        scanf("%d %d", &A[i].GE, &A[i].GI);
        A[i].id = i;
        A[i].wants.resize(K);
        for (int j = 0; j != K; ++j)
        {
            scanf("%d", &A[i].wants[j]);
        }
    }
    sort(A, A+N, cmp);
    for (int i = 0; i != N; ++i)
    {
        int s = pick_school(i);
        if (s != -1)
        {
            S[s].ads.push_back(i);
        }
    }
    for (int i = 0; i != M; ++i)
    {
        int output = 0;
        sort(S[i].ads.begin(), S[i].ads.end(), [] (const int i1, const int i2)
             {
                 return A[i1].id < A[i2].id;
             });
        for (int ai : S[i].ads)
        {
            if (output++)
                putchar(' ');
            printf("%d", A[ai].id);
        }
        putchar('\n');
    }
    return 0;
}

