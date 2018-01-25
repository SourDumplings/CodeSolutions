/*
 @Date    : 2018-01-04 19:48:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p544
 */

#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p): ps(new string(*p.ps)), i(p.i) {}
    HasPtr(HasPtr &&p) noexcept: ps(p.ps), i(p.i) { p.ps = nullptr; }
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(HasPtr&&);
    HasPtr& operator=(const string&);
    HasPtr& operator=(HasPtr rhs) { swap(*this, rhs); return *this; }
    string& operator*();
    ~HasPtr();
private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(HasPtr &&rhs)
{
    if (&rhs != this)
    {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}

HasPtr::~HasPtr()
{
    delete ps;
}

inline HasPtr& HasPtr:: operator=(const HasPtr &rhs)
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

inline HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

inline string& HasPtr::operator*()
{
    return *ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "swap " << *lhs.ps << "versus " << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    return;
}
