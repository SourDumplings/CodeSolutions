/*
 @Date    : 2017-12-23 21:11:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
在此处添加文件说明
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> eq, oq;
    list<int> l{1, 2, 3, 4, 5, 6};
    for (auto i : l)
    {
        if (i % 2)
        {
            oq.push_back(i);
        }
        else
        {
            eq.push_back(i);
        }
    }
    for (auto i : oq)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : eq)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
