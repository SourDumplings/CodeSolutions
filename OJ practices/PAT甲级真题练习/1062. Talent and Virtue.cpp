/*
 @Date    : 2018-02-02 15:19:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1062
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    Person(int &Id, int virtue, int talent): id(Id), v(virtue), t(talent) {}
    int id;
    int v, t;
};

bool cmp(const Person &p1, const Person &p2)
{
    bool result;
    if (p1.v + p1.t == p2.v + p2.t)
    {
        if (p1.v == p2.v)
            result = p1.id < p2.id;
        else
            result = p1.v > p2.v;
    }
    else
        result = p1.v + p1.t > p2.v + p2.t;
    return result;
}

void Output(vector<Person> &vp)
{
    sort(vp.begin(), vp.end(), cmp);
    for_each(vp.begin(), vp.end(),
        [] (const Person &p) { printf("%d %d %d\n", p.id, p.v, p.t);});
    return;
}

int main(int argc, char const *argv[])
{
    vector<Person> sages, noblemen, foolmen, smallmen;
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    int id;
    int v, t;
    while (N--)
    {
        scanf("%d %d %d", &id, &v, &t);
        if (v >= L && t >= L)
        {
            Person p(id, v, t);
            if (v >= H)
            {
                if (t >= H)
                    sages.push_back(p);
                else
                    noblemen.push_back(p);
            }
            else
            {
                if (v >= t)
                    foolmen.push_back(p);
                else
                    smallmen.push_back(p);
            }
        }
    }
    printf("%d\n", sages.size() + noblemen.size() + foolmen.size() + smallmen.size());
    Output(sages);
    Output(noblemen);
    Output(foolmen);
    Output(smallmen);
    return 0;
}
