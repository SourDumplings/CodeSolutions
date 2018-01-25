/*
 @Date    : 2018-01-02 15:41:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p504
输出结果：
local variable:
constructor X()

pass to nonreference parameter:
copy constructor X(const X&)
destructor ~X()

pass to reference parameter:

dynamic memory:
constructor X()

add to a container:
copy constructor X(const X&)

free dynamically allocated object:
destructor ~X()

indirectly initialize and assign:
copy constructor X(const X&)
copy-assignment constructor =(const X&)

end of the program:
destructor ~X()
destructor ~X()
destructor ~X()
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

struct X
{
    X() { cout << "constructor X()" << endl; }
    X(const X&) { cout << "copy constructor X(const X&)" << endl; }
    X& operator=(const X &rhs) { cout << "copy-assignment constructor =(const X&)" << endl; return *this; }
    ~X() { cout << "destructor ~X()" << endl; }
};

void f1(X x) {}
void f2(X &x) {}

int main(int argc, char const *argv[])
{
    cout << "local variable: " << endl;
    X x;
    cout << endl;

    cout << "pass to nonreference parameter: " << endl;
    f1(x);
    cout << endl;

    cout << "pass to reference parameter: " << endl;
    f2(x);
    cout << endl;

    cout << "dynamic memory: " << endl;
    X *px = new X;
    cout << endl;

     cout << "add to a container: " << endl;
     vector<X> vx;
     vx.push_back(x);
     cout << endl;

     cout << "free dynamically allocated object: " << endl;
     delete px;
     cout << endl;

     cout << "indirectly initialize and assign: " << endl;
     X y = x;
     y = x;
     cout << endl;

     cout << "end of the program: " << endl;
    return 0;
}
