/*
 @Date    : 2018-02-07 15:45:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1071
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cctype>

using namespace std;

void find_max_output(const map<string, int> &data)
{
    int max = 0;
    string maxWord;
    for (const auto &p : data)
    {
        if (p.second > max)
        {
            max = p.second;
            maxWord = p.first;
        }
    }
    printf("%s %d\n", maxWord.c_str(), max);
    return;
}

int main(int argc, char const *argv[])
{
    map<string, int> data;
    while (true)
    {
        char c;
        scanf("%c", &c);
        string word;
        bool recorded = false;
        if (isalnum(c))
        {
            do
            {
                c = tolower(c);
                word += c;
                scanf("%c", &c);
            } while (isalnum(c));
        }
        if (!recorded && !word.empty())
        {
            ++data[word];
            recorded = true;
        }
        if (c == '\n')
            break;
    }
    find_max_output(data);
    return 0;
}
