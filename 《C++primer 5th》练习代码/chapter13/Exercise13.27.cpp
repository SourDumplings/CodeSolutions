/*
 @Date    : 2018-01-02 21:51:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p516
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

class HasPtr
{
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    string& operator*();
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete use;
        delete ps;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*rhs.use)
    {
        delete use;
        delete ps;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, char const *argv[])
{
    HasPtr h("hi mom!");
    HasPtr h2 = h;
    h = "hi dad!";
    cout << "h:" << *h << endl;
    cout << "h2:" << *h2 << endl;
    return 0;
}
