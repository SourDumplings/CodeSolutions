/*
 @Date    : 2018-03-15 13:07:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/864
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Student
{
    int id, grade;
    string name;
};

static const int MAXN = 10001;
static vector<shared_ptr<Student>> data;
static int N, C;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &C);
    data.resize(N);
    for (unsigned i = 0; i < N; ++i)
    {
        data[i] = make_shared<Student>();
        cin >> data[i]->id >> data[i]->name >> data[i]->grade;
    }
    switch (C)
    {
    case 1:
    {
        sort(data.begin(), data.end(),
             [] (const shared_ptr<Student> &p1, const shared_ptr<Student> &p2)
        { return p1->id < p2->id; });
        break;
    }
    case 2:
    {
        sort(data.begin(), data.end(),
             [] (const shared_ptr<Student> &p1, const shared_ptr<Student> &p2)
        {
            if (p1->name == p2->name)
                return p1->id < p2->id;
            return p1->name < p2->name;
        });
        break;
    }
    case 3:
    {
        sort(data.begin(), data.end(),
             [] (const shared_ptr<Student> &p1, const shared_ptr<Student> &p2)
        {
            if (p1->grade == p2->grade)
                return p1->id < p2->id;
            return p1->grade < p2->grade;
        });
        break;
    }
    }
    for (auto &p : data)
    {
        printf("%06d %s %d\n", p->id, p->name.c_str(), p->grade);
    }
    return 0;
}

