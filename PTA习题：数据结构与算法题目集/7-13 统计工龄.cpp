/*
 @Date    : 2018-03-13 11:04:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/721
 */

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    map<int, int> data;
    while (N--)
    {
        int year;
        scanf("%d", &year);
        ++data[year];
    }
    for (auto &p : data)
        printf("%d:%d\n", p.first, p.second);
    return 0;
}

