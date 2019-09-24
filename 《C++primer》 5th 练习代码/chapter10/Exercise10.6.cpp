/*
 @Date    : 2017-12-25 19:21:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p384
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
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
    vector<int> v{1, 2, 3, 4, 5};
    fill_n(v.begin(), v.size(), 0);
    for (int i : v)
    {
        cout << i << endl;
    }
    return 0;
}
