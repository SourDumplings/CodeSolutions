/*
 @Date    : 2018-03-11 14:41:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6259
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int main(int argc, char const *argv[])
{
    string word;
    unordered_map<string, int> data;
    bool end = false;
    while (cin >> word)
    {
        if (end) continue;
        bool firstValid = false;
        string validWord;
        for (char c : word)
        {
            if (isalnum(c) || c == '_')
            {
                firstValid = true;
                validWord += tolower(c);
            }
            else if (firstValid)
            {
                if (validWord.length() <= 80)
                    ++data[validWord.substr(0, 15)];
                if (c == '#')
                {
                    end = true;
                    break;
                }
                validWord.clear();
                firstValid = false;
            }
            else if (c == '#')
            {
                end = true;
                break;
            }
        }
        if (firstValid && validWord.length() <= 80)
            ++data[validWord.substr(0, 15)];
    }
    vector<pair<string, int>> res(data.begin(), data.end());
    sort(res.begin(), res.end(), cmp);
    int N = res.size();
    printf("%d\n", N);
    for (int i = 0; i < static_cast<int>(0.1 * N); ++i)
        printf("%d:%s\n", res[i].second, res[i].first.c_str());
    return 0;
}

