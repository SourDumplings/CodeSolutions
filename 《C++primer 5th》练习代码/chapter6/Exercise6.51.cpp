/*
 @Date    : 2017-12-19 15:32:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p245
编译器报错：
Exercise6.51.cpp:29:15: error: call of overloaded 'f(double, int)' is ambiguous
     f(2.56, 42);
               ^
Exercise6.51.cpp:29:15: note: candidates are:
Exercise6.51.cpp:24:6: note: void f(int, int)
 void f(int, int);
      ^
Exercise6.51.cpp:25:6: note: void f(double, double)
 void f(double, double = 3.14);
      ^
注释掉f(2.56, 42);后得到结果：
f(double, double) called
f(int) called
f(int, int) called
f(double, double) called
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>

using namespace std;

void f(void);
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    // f(2.56, 42);
    f(2.56, static_cast<double>(42));
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}

void f(void)
{
    cout << "f() called" << endl;
    return;
}

void f(int, int)
{
    cout << "f(int, int) called" << endl;
    return;
}

void f(int)
{
    cout << "f(int) called" << endl;
    return;
}

void f(double, double)
{
    cout << "f(double, double) called" << endl;
    return;
}
