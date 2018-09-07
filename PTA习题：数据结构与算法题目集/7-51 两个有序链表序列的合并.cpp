/*
 @Date    : 2018-03-17 10:37:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/2992
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    while (true)
    {
        int num;
        scanf("%d", &num);
        if (num != -1)
        {
            v.push_back(num);
        }
        else
            break;
    }
    while (true)
    {
        int num;
        scanf("%d", &num);
        if (num != -1)
        {
            v.push_back(num);
        }
        else
            break;
    }
    if (v.empty())
    {
        printf("NULL\n");
    }
    else
    {
        sort(v.begin(), v.end());
        int output = 0;
        for (auto &i : v)
        {
            if (output++)
            {
                putchar(' ');
            }
            printf("%d", i);
        }
        putchar('\n');
    }
    return 0;
}

