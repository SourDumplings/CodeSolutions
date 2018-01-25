/*
 @Date    : 2017-12-31 12:05:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p472
编译：g++ -std=c++11 -o Exercise12.16.exe Exercise12.16.cpp
得到错误信息：
Exercise12.16.cpp: In function 'int main(int, const char**)':
Exercise12.16.cpp:45:29: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp
, _Dp>&) [with _Tp = std::basic_string<char>; _Dp = std::default_delete<std::basic_string<char> >]'
     unique_ptr<string> p2(p1);
                             ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/memory:81:0,
                 from Exercise12.16.cpp:36:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/unique_ptr.h:356:7: note: declared here
       unique_ptr(const unique_ptr&) = delete;
       ^
Exercise12.16.cpp:47:8: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(
const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::basic_string<char>; _Dp = std::default_delete<std::basic_string<char>
 >]'
     p3 = p2;
        ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/memory:81:0,
                 from Exercise12.16.cpp:36:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/unique_ptr.h:357:19: note: declared here
       unique_ptr& operator=(const unique_ptr&) = delete;
                   ^
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
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    unique_ptr<string> p1(new string("jksdhjaksdk"));
    unique_ptr<string> p2(p1);
    unique_ptr<string> p3;
    p3 = p2;
    return 0;
}
