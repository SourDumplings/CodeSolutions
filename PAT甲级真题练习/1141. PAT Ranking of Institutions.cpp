/*
 @Date    : 2018-08-02 22:24:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805344222429184
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <cctype>

using namespace std;

struct School
{
    char code[7];
    int tws, ns;
    int tb, ta, tt;
};

bool cmp(const School &s1, const School &s2)
{
    if (s1.tws == s2.tws)
    {
        if (s1.ns == s2.ns)
        {
            return string(s1.code) < string(s2.code);
        }
        else
            return s1.ns < s2.ns;
    }
    else
        return s1.tws > s2.tws;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    map<string, School> data;
    for (int i = 0; i < n; ++i)
    {
        char id[7], code[7];
        int score;
        scanf("%s %d %s", id, &score, code);
        for (auto &c : code)
        {
            c = tolower(c);
        }
        string scode(code);
        if (data.find(scode) == data.end())
        {
            strcpy(data[scode].code, code);
            data[scode].tws = data[scode].ns = data[scode].tb = data[scode].ta = data[scode].tt = 0;
        }
        switch (id[0])
        {
            case 'A': data[scode].ta += score; break;
            case 'B': data[scode].tb += score; break;
            case 'T': data[scode].tt += score; break;
        }
        ++data[scode].ns;
    }
    printf("%d\n", data.size());

    vector<School> v;
    for (auto &s : data)
    {
        s.second.tws = s.second.ta + s.second.tb / 1.5 + s.second.tt * 1.5;
        v.push_back(s.second);
    }

    sort(v.begin(), v.end(), cmp);

    int rank = 1;
    int lastScore = v.front().tws, sameScoreNum = 0;
    for (auto &s : v)
    {
        if (s.tws == lastScore)
        {
            ++sameScoreNum;
        }
        else
        {
            rank += sameScoreNum;
            sameScoreNum = 1;
            lastScore = s.tws;
        }
        printf("%d %s %d %d\n", rank, s.code, s.tws, s.ns);
    }
    return 0;
}

