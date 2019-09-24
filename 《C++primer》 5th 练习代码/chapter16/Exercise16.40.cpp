/*
 @Date    : 2018-01-12 22:13:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p686
 */

#include <iostream>
#include <vector>

using namespace std;

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3};
    cout << fcn3(v.begin(), v.end()) << endl;
    // fcn3(v.begin(), v.end()) = 5;
    // cout << fcn3(v.begin(), v.end()) << endl;
    return 0;
}
