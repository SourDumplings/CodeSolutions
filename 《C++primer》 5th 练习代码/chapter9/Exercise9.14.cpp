/*
 @Date    : 2017-12-23 17:40:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
在此处添加文件说明
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    list<char *> l = {"Hello", "World", "me"};
    // char s[3][10];
    // auto it = l.cbegin();
    // for (unsigned i = 0; i < 3; ++i, ++it)
    // {
    //     strcpy(s[i], *it);
    // }
    vector<string> v;
    v.assign(l.cbegin(), l.cend());

    // for (auto &line : s)
    // {
    //     cout << line << " ";
    // }
    // cout << endl;
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
