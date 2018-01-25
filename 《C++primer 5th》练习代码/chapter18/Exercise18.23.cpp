/*
 @Date    : 2018-01-22 11:04:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p808
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class A {};
class B : public A {};
class C : public B {};
class X {};
class Y {};
class Z : public X, public Y {};
class MI : public C, public Z {};
class D : public X, public C {};

int main(int argc, char const *argv[])
{
    D *pd = new D;

    X *px = pd;
    A *pa = pd;
    B *pb = pd;
    C *pc = pd;
    return 0;
}
