/*
 @Date    : 2018-02-10 16:14:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/V/
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

static const int INF = 1000000000;

struct Person
{
    Person() = default;
    Person(int id_, int p_): id(id_), p(p_) {}
    int id, p;
};

int main(int argc, char const *argv[])
{
    vector<Person> old;
    old.push_back(Person(1, 1000000000));
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
    {
        Person temp;
        scanf("%d %d", &temp.id, &temp.p);
        old.push_back(temp);
    }
    sort(old.begin(), old.end(),
        [] (const Person &p1, const Person &p2) { return p1.id < p2.id; });
    for (int i = 1; i != n + 1; ++i)
    {
        int minPDiff = INF;
        bool isLower = false;
        int candidate;
        for (int j = 0; j != i; ++j)
        {
            if (abs(old[j].p - old[i].p) < minPDiff)
            {
                minPDiff = abs(old[j].p - old[i].p);
                candidate = j;
                if (old[i].p >= old[j].p)
                    isLower = true;
                else
                    isLower = false;
            }
            else if (old[i].p - old[j].p == minPDiff && !isLower)
            {
                isLower = true;
                candidate = j;
            }
        }
        printf("%d %d\n", old[i].id, old[candidate].id);
    }
    return 0;
}
