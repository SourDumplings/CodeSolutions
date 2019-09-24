/*
 @Date    : 2018-01-11 11:26:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p658
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename I, typename T> I find(I b, I e, const T &v)
{
    while (b != e && *b != v)
        ++b;
    return b;
}

int main(int argc, char const *argv[])
{
    vector<int> vi{0, 2, 4, 6, 8, 10};
    list<string> ls{"Hello", "World", "!"};
    auto iter = find(vi.begin(), vi.end(), 6);
    if (iter == vi.end())
        cout << "cannot find it" << endl;
    else
        cout << "find " << *iter << " at position " << iter - vi.begin() << endl;
    auto iter1 = find(ls.begin(), ls.end(), "mom");
    if (iter1 == ls.end())
        cout << "cannot find mom" << endl;
    else
        cout << "find mom" << endl;
    return 0;
}
