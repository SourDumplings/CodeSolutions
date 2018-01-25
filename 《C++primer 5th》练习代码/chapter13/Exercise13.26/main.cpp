/*
 @Date    : 2017-12-31 15:55:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p513
原先的输出结果：
4
4
a about
a about
a an the about
欲使StrBlob具有“值”一样的行为
定义了复制构造函数和拷贝赋值操作符函数之后的输出结果：
4
3
a the
a the
a an the
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
#include "my_StrBlob.h"

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;

    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
    {
        cout << it.deref() << " ";
    }
    cout << endl;
    return 0;
}
