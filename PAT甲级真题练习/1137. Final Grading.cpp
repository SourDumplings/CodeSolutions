/*
 @Date    : 2018-03-07 14:46:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1137
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Student
{
    int Gp = -1, Gm = -1, Gf = -1;
    string id;
    int grade = -1;
};

bool cmp(Student * const pS1, Student * const pS2)
{
    if (pS1->grade == pS2->grade)
        return pS1->id < pS2->id;
    return pS1->grade > pS2->grade;
}

int main(int argc, char const *argv[])
{
    int P, M, N;
    scanf("%d %d %d", &P, &M, &N);
    Student data[P];
    map<string, Student*> nameData;
    set<string> validName;
    for (int i = 0; i != P; ++i)
    {
        cin >> data[i].id >> data[i].Gp;
        nameData[data[i].id] = &data[i];
        validName.insert(data[i].id);
    }
    string id;
    int Gm, Gf;
    for (int i = 0; i != M; ++i)
    {
        cin >> id >> Gm;
        if (validName.find(id) != validName.end())
            nameData[id]->Gm = Gm;
    }
    for (int i = 0; i != N; ++i)
    {
        cin >> id >> Gf;
        if (validName.find(id) != validName.end())
            nameData[id]->Gf = Gf;
    }
    vector<Student*> certificates;
    for (auto &S : data)
    {
        if (S.Gp >= 200)
        {
            S.grade = S.Gf < S.Gm ?
            (0.6 * static_cast<double>(S.Gf) + 0.4 * static_cast<double>(S.Gm) + 0.5) : S.Gf;
            if (S.grade >= 60)
                certificates.push_back(nameData[S.id]);
        }
    }
    sort(certificates.begin(), certificates.end(), cmp);
    for (auto pS : certificates)
        cout << pS->id << ' ' << pS->Gp << ' ' << pS->Gm << ' ' << pS->Gf <<
        ' ' << pS->grade << endl;
    return 0;
}

