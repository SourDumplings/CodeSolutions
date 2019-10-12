/*
 @Date    : 2018-03-17 10:41:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/2999
注意交集序列的有序性
 */

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> l1, l2;
    list<int> res;
    while (true)
    {
        int num;
        scanf("%d", &num);
        if (num != -1)
        {
            l1.push_back(num);
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
            l2.push_back(num);
        }
        else
            break;
    }
    auto nextIt1 = l1.begin();
    for (auto it = l2.begin(); it != l2.end(); ++it)
    {
        bool flag = false;
        for (auto it1 = nextIt1; it1 != l1.end(); ++it1)
        {
            if (*it1 == *it)
            {
                flag = true;
                nextIt1 = it1;
                ++nextIt1;
                break;
            }
        }
        if (flag)
        {
            res.push_back(*it);
        }
        if (nextIt1 == l1.end())
        {
            break;
        }
    }
    if (res.empty())
    {
        printf("NULL\n");
    }
    else
    {
        int output = 0;
        for (auto &i : res)
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

