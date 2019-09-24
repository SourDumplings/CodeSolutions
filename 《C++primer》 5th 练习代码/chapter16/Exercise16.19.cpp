/*
 @Date    : 2018-01-12 10:45:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p672
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename C> void print(const C &c)
{
    for (typename C::size_type i = 0; i != c.size(); ++i)
        cout << c.at(i) << " ";
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    string s = "Hello";
    print(s);

    vector<int> vi{1, 2, 3, 4, 5};
    print(vi);
    return 0;
}
