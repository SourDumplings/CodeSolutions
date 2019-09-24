/*
 @Date    : 2018-01-23 12:13:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p827
 */

#include <iostream>

using namespace std;

class A { public: virtual ~A() {} };
class B : public A {};
class C : public B {};
class D : public B, public A {};

int main(int argc, char const *argv[])
{
    // A *pa = new C;
    // if (B *pb = dynamic_cast<B*>(pa))
    //     cout << 1 << endl;
    B *pb = new B;
    if (C *pc = dynamic_cast<C*>(pb))
        cout << 2 << endl;
    // A *pa = new D;
    // B *pb = dynamic_cast<B*>(pa);
    return 0;
}

