/*
 @Date    : 2018-01-23 20:35:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p832
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class A
{
public:
    virtual ~A() = default;
};

class B: public A
{
public:
    virtual ~B() = default;
};

int main(int argc, char const *argv[])
{
    B *pb = new B;
    A &ra = *pb;
    cout << typeid(ra).name() << endl;
    return 0;
}
