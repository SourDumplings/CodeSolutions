/*
 @Date    : 2018-01-21 20:24:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/6w5/
 */

#include <iostream>
using namespace std;
class A {
// 在此处补充你的代码
public:
    virtual ~A() { cout << "destructor A" << endl; }
};
class B:public A {
    public:
        ~B() { cout << "destructor B" << endl; }
};
int main() {
    A * pa;
    pa = new B;
    delete pa;
    return 0;
}
