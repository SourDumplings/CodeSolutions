/*
 @Date    : 2017-12-25 15:02:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p378
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
    vector<int> v{1, 3, 2, 3, 4, 4, 3, 2, 1, 5, 3, 2};
    cout << count(v.begin(), v.end(), 3) << endl;
    return 0;
}
