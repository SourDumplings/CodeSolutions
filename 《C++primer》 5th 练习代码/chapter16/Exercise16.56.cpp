/*
 @Date    : 2018-01-14 10:53:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p704
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
ostream& print(ostream &os, const T &t)
{
    os << t << endl;
    return os;
}

template <typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&...rest)
{
    os << t << " ";
    print(os, rest...);
    return os;
}

template <typename T>
string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename... Args>
ostream& errorMsg(ostream &os, const Args&...rest)
{
    return print(os, debug_rep(rest)...);
}

int main(int argc, char const *argv[])
{
    int i = 10;
    string s{"abc"};
    char sc[] = "hello";
    double d = 3.14;
    errorMsg(cout, i, s, sc, d);
    return 0;
}
