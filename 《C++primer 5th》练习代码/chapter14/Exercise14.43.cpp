/*
 @Date    : 2018-01-06 16:46:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p576
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    vector<int> v{6, 8, 24, 3, 5};
    int i;
    cin >> i;
    auto p = find_if(v.begin(), v.end(), bind(modulus<int>(), i, _1));
    if (p != v.end())
        cout << "no" << endl;
    else
        cout << "yes" << endl;

    return 0;
}
