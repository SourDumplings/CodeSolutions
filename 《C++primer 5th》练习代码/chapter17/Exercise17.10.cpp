/*
 @Date    : 2018-01-16 22:37:39
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p728
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> num{1, 2, 3, 5, 8, 13, 21};
    bitset<32> b1, b2;
    for (auto n : num)
        b1.set(n);
    b2 |= b1;
    cout << b2 << endl;
    return 0;
}
