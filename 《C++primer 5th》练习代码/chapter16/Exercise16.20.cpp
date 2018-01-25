/*
 @Date    : 2018-01-12 10:49:21
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
    for (auto it = c.begin(); it != c.end(); ++it)
        cout << *it << " ";
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
