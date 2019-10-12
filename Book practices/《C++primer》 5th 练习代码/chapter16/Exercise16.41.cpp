/*
 @Date    : 2018-01-12 22:10:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p686
 */

#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    auto a = sum(1, 1);
    cout << a << " " << sizeof(a) << endl;
    auto b = sum(1, 1.1);
    cout << b << " " << sizeof(b) << endl;
    auto c = sum(1, 1.1f);
    cout << c << " " << sizeof(c) << endl;
    return 0;
}
