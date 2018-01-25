/*
 @Date    : 2017-12-14 16:10:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p70
运行结果：
i
i
i
PKi
i
i
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <typeinfo>

using namespace std;

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    cout << typeid(i).name() << endl;
    cout << typeid(j).name() << endl;
    cout << typeid(k).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(j2).name() << endl;
    cout << typeid(k2).name() << endl;
    return 0;
}

