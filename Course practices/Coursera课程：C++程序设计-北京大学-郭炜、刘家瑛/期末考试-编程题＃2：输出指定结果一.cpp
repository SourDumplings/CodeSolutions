/*
 @Date    : 2018-02-12 21:10:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
填写代码，使输出结果为
2
2
8
10
 */

#include <iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n): num(n) {
    }
// 在此处补充你的代码

    Number(const Number &b): num(b.num) {}
    int& value() { return num; }
    Number& operator+(const Number &rhs) { num += rhs.num; return *this; }
};
int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    return 0;
}
