/*
 @Date    : 2017-12-18 21:53:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p228
键入以下命令进行编译：
g++ -std=c++11 -c Exercise6.30.cpp
得到编译器报错输出结果：
Exercise6.30.cpp: In function 'bool str_subrange(const string&, const string&)':
Exercise6.30.cpp:33:13: error: return-statement with no value, in function returning 'bool' [-fpermissive]
             return;
             ^
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>

using namespace std;

bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
    {
        return str1 == str2;
    }
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
        {
            return;
        }
    }
}

