/*
 @Date    : 2018-01-04 20:20:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p544
得到编译错误信息：
main.cpp: In function 'int main(int, const char**)':
main.cpp:48:8: error: ambiguous overload for 'operator=' (operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>
::type {aka HasPtr}')
     h3 = std::move(h1);
        ^
main.cpp:48:8: note: candidates are:
In file included from main.cpp:38:0:
HasPtr.h:52:16: note: HasPtr& HasPtr::operator=(const HasPtr&)
 inline HasPtr& HasPtr:: operator=(const HasPtr &rhs)
                ^
HasPtr.h:35:9: note: HasPtr& HasPtr::operator=(HasPtr&&)
 HasPtr& HasPtr::operator=(HasPtr &&rhs)
         ^
HasPtr.h:27:13: note: HasPtr& HasPtr::operator=(HasPtr)
     HasPtr& operator=(HasPtr rhs) { swap(*this, rhs); return *this; }
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
#include "HasPtr.h"

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    HasPtr h1("one");
    HasPtr h2(std::move(h1));
    HasPtr h3;
    h3 = std::move(h1);
    return 0;
}
