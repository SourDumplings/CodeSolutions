/*
 @Date    : 2017-12-24 12:14:57
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
    forward_list<int> fl{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = fl.before_begin();
    for (auto curr = fl.begin(); curr != fl.end();)
    {
        if (*curr & 1)
        {
            curr = fl.erase_after(pre);
        }
        else
        {
            pre = curr;
            ++curr;
        }
    }
    for (int i : fl)
    {
        cout << i << endl;
    }
    return 0;
}
