/*
 @Date    : 2017-12-25 16:29:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p380
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

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 6};
    int sum = accumulate(v.cbegin(), v.cend(), 0);
    cout << sum << endl;
    return 0;
}
