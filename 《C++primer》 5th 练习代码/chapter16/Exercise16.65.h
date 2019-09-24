/*
 @Date    : 2018-01-14 17:51:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p712
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T *p)
{
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

template<>
string debug_rep(char *p)
{
    return debug_rep(string(p));
}

template<>
string debug_rep(const char *p)
{
    return debug_rep(string(p));
}
