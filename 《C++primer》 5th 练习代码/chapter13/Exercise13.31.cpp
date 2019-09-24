/*
 @Date    : 2018-01-03 11:08:39
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p519
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
    friend void print(HasPtr&);
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p): ps(new string(*p.ps)), i(p.i) {}
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    bool operator<(const HasPtr&);
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

inline HasPtr& HasPtr::operator=(const string &rs)
{
    *ps = rs;
    return *this;
}

inline string& HasPtr::operator*()
{
    return *ps;
}

inline bool HasPtr::operator<(const HasPtr &rhs)
{
    return *ps < *rhs.ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "swap " << *lhs.ps << "versus " << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    return;
}

inline void print(HasPtr& h)
{
    cout << *h.ps << " ";
    return;
}

int main(int argc, char const *argv[])
{
    vector<HasPtr> v(3);
    v[0] = "abd";
    v[1] = "abc";
    v[2] = "a";
    cout << "before sorting: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;
    sort(v.begin(), v.end());
    cout << "after sorting: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;
    return 0;
}
