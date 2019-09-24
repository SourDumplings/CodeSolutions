/*
 @Date    : 2018-01-13 21:23:26
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p701
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T, typename...Args>
void foo(const T &t, const Args&... rest)
{
    cout << sizeof...(Args) << " " << sizeof...(rest) << endl;
    return;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    double d = 3.14;
    string s{"I love you."};
    foo(i, s, 42, d);
    foo(s, 42, d);
    foo(42, d);
    foo(d);
    return 0;
}
