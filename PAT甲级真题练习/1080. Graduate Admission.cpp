/*
 @Date    : 2018-02-15 17:01:52
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1080
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    int id;
    int GE, GI, total_score, rank;
    vector<int> applied_schools;
};

static int N, M, K;

bool cmp(const Student &s1, const Student &s2)
{
    if (s1.total_score == s2.total_score)
        return s1.GE > s2.GE;
    else
        return s1.total_score > s2.total_score;
}

void give_rank(Student applicants[])
{
    int rank = 1, lastTotalScore = applicants[0].total_score;
    int lastGE = applicants[0].GE;
    int sameRank = 0;
    for (int i = 0; i != N; ++i)
    {
        if (applicants[i].total_score < lastTotalScore)
        {
            lastTotalScore = applicants[i].total_score;
            rank += sameRank;
            sameRank = 1;
            lastGE = applicants[i].GE;
        }
        else if (applicants[i].total_score == lastTotalScore)
        {
            if (applicants[i].GE < lastGE)
            {
                lastGE = applicants[i].GE;
                rank += sameRank;
                sameRank = 1;
            }
            else if (applicants[i].GE == lastGE)
                ++sameRank;
        }
        applicants[i].rank = rank;
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &N, &M, &K);
    unsigned quota[M];
    for (int i = 0; i != M; ++i)
        scanf("%d", &quota[i]);
    vector<vector<int>> admit(M);
    Student applicants[N];
    int applied_school;
    for (int i = 0; i != N; ++i)
    {
        applicants[i].id = i;
        scanf("%d %d", &applicants[i].GE, &applicants[i].GI);
        applicants[i].total_score = (applicants[i].GE + applicants[i].GI) / 2;
        for (int j = 0; j != K; ++j)
        {
            scanf("%d", &applied_school);
            applicants[i].applied_schools.push_back(applied_school);
        }
    }
    sort(applicants, applicants + N, cmp);
    give_rank(applicants);
    for (int i = 0; i != N; ++i)
    {
        for (auto school_it = applicants[i].applied_schools.begin();
            school_it != applicants[i].applied_schools.end(); ++school_it)
        {
            int school = *school_it;
            if ((admit[school].size() < quota[school]) ||
                (applicants[i].rank == applicants[admit[school].back()].rank))
            {
                admit[school].push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i != M; ++i)
    {
        int output = 0;
        sort(admit[i].begin(), admit[i].end(),
            [&applicants] (const int &s1, const int &s2)
            { return applicants[s1].id < applicants[s2].id; } );
        for (int j : admit[i])
        {
            if (output++)
                putchar(' ');
            printf("%d", applicants[j].id);
        }
        putchar('\n');
    }
    return 0;
}
