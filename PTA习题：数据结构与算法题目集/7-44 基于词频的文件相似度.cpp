/*
 @Date    : 2018-03-16 08:49:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/891
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    unordered_set<string> data[N];
    for (unsigned i = 0; i < N; ++i)
    {
        while (true)
        {
            string temp, word;
            getline(cin, temp);
            if (temp == "#")
            {
                break;
            }
            for (auto &c : temp)
            {
                if (isalpha(c))
                {
                    if (word.length() < 10)
                        word += tolower(c);
                }
                else
                {
                    if (!word.empty() && word.length() >= 3)
                    {
                        data[i].insert(word);
                    }
                    word.clear();
                }
            }
            if (!word.empty() && word.length() >= 3)
                data[i].insert(word);
        }
        // printf("for file %d: ", i+1);
        // for (auto &word : data[i])
        // {
        //     cout << word << ' ';
        // }
        // cout << endl;
    }
    int M;
    scanf("%d", &M);
    for (unsigned i = 0; i < M; ++i)
    {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        int commonNum = data[f1-1].size(), allNum = data[f2-1].size();
        for (auto &word : data[f1-1])
        {
            if (data[f2-1].find(word) == data[f2-1].end())
            {
                ++allNum;
                --commonNum;
            }
        }
        printf("%.1lf%%\n", static_cast<double>(commonNum) * 100 / allNum);
    }
    return 0;
}

