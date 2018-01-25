/*
 @Date    : 2018-01-23 13:30:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p827
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class A { public: virtual ~A() {} };
class B : public A {};
class C : public B {};
class D : public B, public A {};

int main(int argc, char const *argv[])
{
    A *pa = new A;
    try
    {
        C &c = dynamic_cast<C&>(*pa);
    }
    catch (bad_cast &bc)
    {
        cout << "dynamic_cast failed" << endl;
    }
    return 0;
}
