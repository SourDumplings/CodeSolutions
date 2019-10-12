/*
 @Date    : 2018-01-23 20:16:52
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

class Base
{
public:
    virtual ~Base() = default;
};

class Derived: public Base
{
public:
    virtual ~Derived() = default;
};

class Sales_data {};

int main(int argc, char const *argv[])
{
    int arr[10];
    Derived d;
    Base *p = &d;

    string si = typeid(42).name();
    string sa = typeid(arr).name();
    string sS = typeid(Sales_data).name();
    string ss = typeid(string).name();
    string sp = typeid(p).name();
    string sb = typeid(*p).name();
    cout << si << " " << sa << " " << sS << " " <<
    ss << " " << sp << " " << sb << endl;
    return 0;
}
