/*
 @Date    : 2018-01-04 21:07:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p548
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

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
    void read(istream &is) { int i; while (is >> i) data.push_back(i); }
    void print() { for_each(data.begin(), data.end(),
        [] (const int &i) mutable { cout << i << " "; }); }
private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "rvalue reference version" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "lvalue reference version" << endl;
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}

int main(int argc, char const *argv[])
{
    Foo f;
    f.read(cin);

    cout << "before sorting: ";
    f.print();
    cout << endl;

    f.sorted();
    cout << "after sorting: ";
    f.print();
    cout << endl;

    cin.clear();
    Foo f2;
    f2.read(cin);

    cout << "before sorting: ";
    f2.print();
    cout << endl;

    std::move(f2).sorted();
    cout << "after sorting: ";
    f2.print();
    cout << endl;


    return 0;
}
