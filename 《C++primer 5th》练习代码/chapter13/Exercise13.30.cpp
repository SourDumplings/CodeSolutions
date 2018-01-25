/*
 @Date    : 2018-01-03 10:58:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p519
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
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    string& operator*();
    ~HasPtr();
private:
    string *ps;
    int i;
};

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

int main(int argc, char const *argv[])
{
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    swap(h2, h3);
    cout << "h:" << *h << endl;
    cout << "h2:" << *h2 << endl;
    cout << "h3:" << *h3 << endl;
    return 0;
}
