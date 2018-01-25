/*
 @Date    : 2017-12-24 17:16:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p356
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
    // list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // auto curr = l.begin();

    // while (curr != l.end())
    // {
    //     if (*curr & 1)
    //     {
    //         curr = l.insert(curr, *curr);
    //         ++curr;
    //         ++curr;
    //     }
    //     else
    //     {
    //         curr = l.erase(curr);
    //     }
    // }


    forward_list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = l.before_begin();
    for (auto curr = l.begin(); curr != l.end();)
    {
        if (*curr & 1)
        {
            curr = l.insert_after(curr, *curr);
            pre = curr;
            ++curr;
        }
        else
        {
            curr = l.erase_after(pre);
        }
    }

    for (auto curr = l.begin(); curr != l.end(); ++curr)
    {
        cout << *curr << " ";
    }
    cout << endl;


    return 0;
}
