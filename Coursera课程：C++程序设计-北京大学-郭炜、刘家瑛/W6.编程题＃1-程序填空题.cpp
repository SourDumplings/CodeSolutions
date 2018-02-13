/*
 @Date    : 2018-01-21 20:19:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/6w4/
 */

#include <iostream>
using namespace std;
class A {
    private:
        int nVal;
    public:
        void Fun()
        { cout << "A::Fun" << endl; }
        void Do()
        { cout << "A::Do" << endl; }
};
class B:public A {
    public:
        virtual void Do()
        { cout << "B::Do" << endl; }
};
class C:public B {
    public:
    void Do( )
    { cout << "C::Do" <<endl; }
    void Fun()
    { cout << "C::Fun" << endl; }
};
void Call(
    // 在此处补充你的代码
B &p
         )  {
    p.Fun();  p.Do();
}
int main()  {
    C c;    Call(c);
    return 0;
}
