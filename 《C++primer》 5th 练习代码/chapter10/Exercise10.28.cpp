/*
 @Date    : 2017-12-27 18:40:14
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
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> v1, v2, v3;
    copy(v.begin(), v.end(), inserter(v1, v1.begin()));
    for_each(v1.begin(), v1.end(), [] (int i) {cout << i << " ";});
    cout << endl;

    copy(v.begin(), v.end(), inserter(v2, v2.begin()));
    for_each(v2.begin(), v2.end(), [] (int i) {cout << i << " ";});
    cout << endl;

    copy(v.begin(), v.end(), back_inserter(v1));
    for_each(v1.begin(), v1.end(), [] (int i) {cout << i << " ";});
    cout << endl;

    copy(v.begin(), v.end(), front_inserter(v2));
    for_each(v2.begin(), v2.end(), [] (int i) {cout << i << " ";});
    cout << endl;

    copy(v.begin(), v.end(), front_inserter(v3));
    for_each(v3.begin(), v3.end(), [] (int i) {cout << i << " ";});
    cout << endl;
    return 0;
}
