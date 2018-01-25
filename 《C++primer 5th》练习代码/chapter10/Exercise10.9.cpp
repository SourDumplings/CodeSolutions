/*
 @Date    : 2017-12-25 19:32:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p385
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
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> v{"I", "love", "love", "I", "you", "you", "you"};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto s : v)
    {
        cout << s << endl;
    }
    return 0;
}
