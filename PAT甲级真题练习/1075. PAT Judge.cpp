/*
 @Date    : 2018-02-14 12:08:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1075
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <array>
#include <memory>

using namespace std;

static const int MAXN = 10001, MAXK = 6, MAXM = 100001;
static int N, K, M;
static int p[MAXK];
enum {NOSUBMISSION = -2, NOTCOMPILED = -1};

struct Student
{
    int id, rank, totalScore = 0, perfectSolve = 0;
    int score[MAXK];
    bool valid;
    Student() { fill(score, score + MAXK, NOSUBMISSION); valid = false; }
};

static array<shared_ptr<Student>, MAXN> data;

void read_submission()
{
    int id, problem, score;
    while (M--)
    {
        scanf("%d %d %d", &id, &problem, &score);
        if (data[id] == nullptr)
        {
            data[id] = make_shared<Student>();
            data[id]->id = id;
        }
        if (score > NOTCOMPILED)
            data[id]->valid = true;
        else if (score == NOTCOMPILED)
            score = 0;
        if (score > data[id]->score[problem-1])
            data[id]->score[problem-1] = score;
    }
    return;
}

void process(shared_ptr<Student> &ps)
{
    if (!ps->valid)
        return;
    for (int i = 0; i != K; ++i)
    {
        if (ps->score[i] > NOTCOMPILED)
        {
            if (ps->score[i] == p[i])
                ++ps->perfectSolve;
            ps->totalScore += ps->score[i];
        }
    }
    return;
}

bool cmp(const shared_ptr<Student> &ps1, const shared_ptr<Student> &ps2)
{
    if (ps1->totalScore == ps2->totalScore)
    {
        if (ps1->perfectSolve == ps2->perfectSolve)
            return ps1->id < ps2->id;
        else
            return ps1->perfectSolve > ps2->perfectSolve;
    }
    else
        return ps1->totalScore > ps2->totalScore;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &N, &K, &M);
    for (int i = 0; i != K; ++i)
        scanf("%d", &p[i]);
    fill(data.begin(), data.end(), nullptr);
    read_submission();
    auto last = partition(data.begin(), data.end(),
        [] (shared_ptr<Student> &ps)
        { return ps != nullptr && ps->valid; } );
    for_each(data.begin(), last, process);
    sort(data.begin(), last, cmp);
    int rank = 1;
    int sameRank = 0, lastTotalScore = data[0]->totalScore;
    for (auto it = data.begin(); it != last; ++it)
    {
        if ((*it)->totalScore == lastTotalScore)
            ++sameRank;
        else
        {
            rank += sameRank;
            sameRank = 1;
            lastTotalScore = (*it)->totalScore;
        }
        (*it)->rank = rank;
    }
    for (auto it = data.begin(); it != last; ++it)
    {
        printf("%d %05d %d", (*it)->rank, (*it)->id, (*it)->totalScore);
        for (int i = 0; i != K; ++i)
        {
            if ((*it)->score[i] != NOSUBMISSION)
                printf(" %d", (*it)->score[i]);
            else
                printf(" -");
        }
        putchar('\n');
    }
    return 0;
}
