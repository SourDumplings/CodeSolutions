/*
 @Date    : 2018-12-27 13:13:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928
 */

// 如果用int 类型变量读取输入的指令中的考场编号或日期信息时，输出时考场编号和日期分别要输出3位和6位，不够要在高位补0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 10005;
int N, M;

struct Student
{
    string cardName;
    char type;
    int site, date, grade;
};

vector<Student> data;
unordered_map<char, vector<int>> types;
unordered_map<int, pair<int, int>> sites;
unordered_map<int, unordered_map<int, int>> dates;
unordered_map<int, vector<pair<int, int>>> datesResults;

void process(const string &cardName, int i)
{
    data[i].type = cardName[0];
    data[i].site = stoi(cardName.substr(1, 3));
    data[i].date = stoi(cardName.substr(4, 6));
    return;
}

bool cmpSitePair(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

bool cmpGrade(const int i1, const int i2)
{
    if (data[i1].grade == data[i2].grade)
        return data[i1].cardName < data[i2].cardName;
    return data[i1].grade > data[i2].grade;
}

void output1(int seq)
{
    char test;
    cin >> test;
    cout << "Case " << seq << ": 1 "<< test << endl;
    if (types.find(test) == types.end())
    {
        cout << "NA" << endl;
        return;
    }
    for (int i : types[test])
    {
        cout << data[i].cardName << " " << data[i].grade << endl;
    }
    return;
}

void output2(int seq)
{
    int term;
    cin >> term;
    cout << "Case " << seq << ": 2 ";
    printf("%03d\n", term);
    if (sites.find(term) == sites.end())
    {
        cout << "NA" << endl;
        return;
    }
    cout << sites[term].first << " " << sites[term].second << endl;
    return;
}

void output3(int seq)
{
    int term;
    cin >> term;
    cout << "Case " << seq << ": 3 ";
    printf("%06d\n", term);
    if (datesResults.find(term) == datesResults.end())
    {
        cout << "NA" << endl;
        return;
    }
    for (auto &p : datesResults[term])
    {
        cout << p.first << " " << p.second << endl;
    }
    return;
}

int main()
{
    cin >> N >> M;
    data.resize(N);
    for (int i = 0; i != N; ++i)
    {
        cin >> data[i].cardName >> data[i].grade;
        process(data[i].cardName, i);
    }
    for (int i = 0; i != N; ++i)
    {
        types[data[i].type].push_back(i);
        ++sites[data[i].site].first;
        sites[data[i].site].second += data[i].grade;
        ++dates[data[i].date][data[i].site];
    }
    for (auto &eachType : types)
        sort(eachType.second.begin(), eachType.second.end(), cmpGrade);
    for (auto &eachDate : dates)
    {
        for (auto &p : eachDate.second)
            datesResults[eachDate.first].push_back(make_pair(p.first, p.second));
        sort(datesResults[eachDate.first].begin(), datesResults[eachDate.first].end(), cmpSitePair);
    }
    for (int i = 0; i != M; ++i)
    {
        int type;
        cin >> type;
        switch (type)
        {
            case 1: output1(i + 1); break;
            case 2: output2(i + 1); break;
            case 3: output3(i + 1); break;
        }
    }
    return 0;
}
