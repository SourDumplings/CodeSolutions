/*
 @Date    : 2018-02-28 10:11:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1114
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>
#include <set>

using namespace std;

static const int MAXN = 10001;
struct Person
{
    int id;
    int father, mother;
    set<int> children;
    double m_estate, area;
    Person(int id_, int f_, int m_): id(id_), father(f_), mother(m_),
        m_estate(0.0), area(0.0) {}
};
static shared_ptr<Person> data[MAXN];
static int N;
struct Family
{
    set<int> members;
    int smallest_id;
    Family(): area(0.0), sets(0.0) {}
    double area;
    double sets;
    double get_avg_area() const { return area / members.size(); }
    double get_avg_sets() const { return sets / members.size(); }
};
static vector<Family> families;
static bool checked[MAXN];

void add_members(Family &family, int ancestor)
{
    queue<int> Q;
    Q.push(ancestor);
    checked[ancestor] = true;
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        family.area += data[p]->area;
        family.sets += data[p]->m_estate;
        family.members.insert(p);
        if (data[p]->father != -1 && !checked[data[p]->father])
        {
            checked[data[p]->father] = true;
            Q.push(data[p]->father);
        }
        if (data[p]->mother != -1 && !checked[data[p]->mother])
        {
            checked[data[p]->mother] = true;
            Q.push(data[p]->mother);
        }
        if (!data[p]->children.empty())
        {
            for (auto c : data[p]->children)
            {
                if (!checked[c])
                {
                    Q.push(c);
                    checked[c] = true;
                }
            }
        }
    }
    family.smallest_id = *family.members.begin();
    return;
}

bool cmp(const Family &f1, const Family &f2)
{
    if (f1.get_avg_area() == f2.get_avg_area())
        return f1.smallest_id < f2.smallest_id;
    return f1.get_avg_area() > f2.get_avg_area();
}

void read_person_data(int id)
{
    int f, m, k, c;
    scanf("%d %d", &f, &m);
    if (data[id] == nullptr) data[id] = make_shared<Person>(id, f, m);
    else
    {
        data[id]->father = f;
        data[id]->mother = m;
    }
    if (f != -1)
    {
        if (data[f] == nullptr) data[f] = make_shared<Person>(f, -1, -1);
        data[f]->children.insert(id);
    }
    if (m != -1)
    {
        if (data[m] == nullptr) data[m] = make_shared<Person>(m, -1, -1);
        data[m]->children.insert(id);
    }
    scanf("%d", &k);
    for (int i = 0; i != k; ++i)
    {
        scanf("%d", &c);
        data[id]->children.insert(c);
        if (data[c] == nullptr) data[c] = make_shared<Person>(c, id, -1);
        else if (data[c]->father == -1 && data[c]->mother != id)
            data[c]->father = id;
        else if (data[c]->mother == -1 && data[c]->father != id)
            data[c]->mother = id;
    }
    scanf("%lf %lf", &data[id]->m_estate, &data[id]->area);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    fill(data, data + MAXN, nullptr);
    int id;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &id);
        read_person_data(id);
    }
    fill(checked, checked + MAXN, false);
    for (int i = 0; i != MAXN; ++i)
    {
        if (!checked[i] && data[i] != nullptr)
        {
            families.push_back(Family());
            add_members(families.back(), i);
        }
    }
    sort(families.begin(), families.end(), cmp);
    printf("%d\n", families.size());
    for (auto &f : families)
        printf("%04d %d %.3f %.3f\n", f.smallest_id, f.members.size(),
               f.get_avg_sets(), f.get_avg_area());
    return 0;
}
