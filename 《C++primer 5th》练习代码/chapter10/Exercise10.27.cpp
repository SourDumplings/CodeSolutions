/*
 @Date    : 2017-12-27 18:33:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p403
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
#include <iterator>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    vector<int> v{1, 1, 2, 3, 3, 5, 4, 5, 5, 5, 6, 7};
    sort(v.begin(), v.end());
    list<int> l;
    // unique_copy(v.begin(), v.end(), back_inserter(l));
    unique_copy(v.begin(), v.end(), inserter(l, l.begin()));
    for_each(l.begin(), l.end(), [] (int i) {cout << i << " ";});
    cout << endl;
    return 0;
}
