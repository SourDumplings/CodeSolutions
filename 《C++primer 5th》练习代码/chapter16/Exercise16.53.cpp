/*
 @Date    : 2018-01-13 21:37:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p702
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> ostream& print(ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename...Args> ostream& print(ostream &os, const T &t, Args&...rest)
{
    os << t << " ";
    return print(os, rest...);
}

int main(int argc, char const *argv[])
{
    int i = 1;
    string s{"you"};
    double d = 3.14;
    print(cout, i, d, s);
    return 0;
}
