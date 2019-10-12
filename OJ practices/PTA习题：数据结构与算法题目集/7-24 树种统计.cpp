/*
 @Date    : 2018-03-13 21:06:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/839
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    getchar();
    map<string, int> data;
    for (int i = 0; i != N; ++i)
    {
        string name;
        getline(cin, name);
        ++data[name];
    }
    for (auto &p : data)
        printf("%s %.4lf%%\n", p.first.c_str(), static_cast<double>(p.second) * 100 / N);
    return 0;
}

