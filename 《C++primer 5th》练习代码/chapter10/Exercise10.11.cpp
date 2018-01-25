/*
 @Date    : 2017-12-25 21:24:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p387
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

using namespace std;

bool cmp_direct(const string &s1, const string &s2)
{
    bool result = false;
    if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2))
    {
        result = true;
    }
    return result;
}

bool cmp_size(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char const *argv[])
{
    vector<string> v{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    // sort(v.begin(), v.end(), cmp_direct);

    sort(v.begin(), v.end());
    stable_sort(v.begin(), v.end(), cmp_size);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (string s : v)
    {
        cout << s << endl;
    }
    return 0;
}
