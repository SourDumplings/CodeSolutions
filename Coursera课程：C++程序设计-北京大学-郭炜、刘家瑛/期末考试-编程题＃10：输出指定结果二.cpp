/*
 @Date    : 2018-02-13 13:17:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
通过填空使得程序输出的结果符合下面的要求。
 */

#include <iostream>
#include <map>
using namespace std;
// 在此处补充你的代码
class A
{
public:
    A() { ++count; }
    A(int) { ++count; }
    A(const A&) { ++count; }
    static int count;
    virtual ~A() { cout << "A::destructor" << endl; --count; }
};

class B: public A
{
public:
    B(int): A() {}
    virtual ~B() override { cout << "B::destructor" << endl; }
};

int A::count = 0;
void func(B b) { }
int main()
{
        A a1(5),a2;
        cout << A::count << endl;
        B b1(4);
        cout << A::count << endl;
        func(b1);
        cout << A::count << endl;
        A * pa = new B(4);
        cout << A::count << endl;
        delete pa;
        cout << A::count << endl;
        return 0;
}
