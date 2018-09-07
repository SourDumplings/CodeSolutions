/*
 @Date    : 2018-03-15 15:39:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/888
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <memory>

using namespace std;

struct Student
{
    string id;
    int grade;
    int zone, r[2];
};

struct cmp
{
    bool operator()(const shared_ptr<Student> &p1, const shared_ptr<Student> &p2)
    {
        if (p1->grade == p2->grade)
            return p1->id < p2->id;
        return p1->grade > p2->grade;
    }
};

static set<shared_ptr<Student>, cmp> data;
static const int INF = 999999;

void get_rank(set<shared_ptr<Student>, cmp> &data, int r_i)
{
    int lastG = INF, lastR = 0, sameR = 1;
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        if ((*it)->grade < lastG)
        {
            lastR += sameR;
            sameR = 1;
            lastG = (*it)->grade;
        }
        else
            ++sameR;
        (*it)->r[r_i] = lastR;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int z = 0; z != N; ++z)
    {
        int K;
        scanf("%d", &K);
        set<shared_ptr<Student>, cmp> thisZone;
        for (unsigned i = 0; i < K; ++i)
        {
            shared_ptr<Student> p(new Student);
            cin >> p->id >> p->grade;
            p->zone = z + 1;
            thisZone.insert(p);
        }
        get_rank(thisZone, 1);
        data.insert(thisZone.begin(), thisZone.end());
    }
    get_rank(data, 0);
    printf("%d\n", data.size());
    for (auto &p : data)
    {
        printf("%s %d %d %d\n", p->id.c_str(), p->r[0], p->zone, p->r[1]);
    }
    return 0;
}

